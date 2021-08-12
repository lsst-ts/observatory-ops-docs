Deploying the Upgrade
=====================

These are the activities that are performed when the time of deployment comes around.
You will need access to a number of resources (:ref:`Summit <Deployment-Activities-Summit-Resources>`, :ref:`NTS <Deployment-Activities-NTS-Resources>`) at the sites so be sure that you have the credentials to do so.
A number of scripts are available for easing the bare metal docker-compose deployment handling.
The scripts can be retrieved from this repo: https://github.com/lsst-ts/docker-compose-admin.
Use the scripts from the appropriate site directory.
If changes are necessary to these scripts from work described in the previous section, use the appropriate site Jira ticket.

.. note::

  The deployment is only concerned with CSCs and systems (:ref:`Summit <Deployment-Activities-Summit-Non-Production>`, :ref:`NTS <Deployment-Activities-NTS-Non-Production>`) in the production domain (domainId = 0).
  All other domains are left alone.

.. attention::

  As the person running the deployment, you have absolute control over the system to complete this process.
  No one should do anything without your express consent.

#. Log into the machines for bare metal deployments and Kubernetes access (:ref:`Summit <Deployment-Activities-Summit-BareMetal>`, :ref:`NTS <Deployment-Activities-NTS-BareMetal>`)
#. Use LOVE or Nublado to send all CSC systems to OFFLINE state.

    * **WARNING**: Not all CSCs report OFFLINE; these will instead report STANDBY as the last state seen.
      Check for heartbeats to be sure.
    * Preference is to use LOVE, but Nublado is a good fallback in case LOVE isn't working
    * An overall status view is available from LOVE (:ref:`Summit <Deployment-Activities-Summit-LOVE-Summary>`, :ref:`NTS <Deployment-Activities-NTS-LOVE-Summary>`)
        * **NOTE**: MTM1M3 does not show status on the LOVE board due to technical limitations.
          Check ``MT Summary State Monitor`` Chronograf dashboard to be sure.
    * You can also consult these dashboards on Chronograf. The names are the same across sites.
        * ``AT Summary State Monitor``
        * ``MT Summary State Monitor``
        * ``EAS Summary State Monitor``
        * ``Observatory Systems Summary State Monitor``
    * The Watcher and the ScriptQueues should come down last if running from LOVE

#. With all the systems OFFLINE, you can log out of your Nubaldo instance as we will clean them up soon.
#. While you are working on the cleanup, merge the ArgoCD branch onto master and push
#. Once all systems are in OFFLINE, still running CSCs/systems and OSPL daemons need to be cleaned up
    #. Get number of currently running daemons/CSCs still in OFFLINE from main OSPL daemon:
        * *docker exec ospl-daemon grep "federations" durability.log*
        * You must give the daemon some time (30 seconds to 2 minutes) before getting worried that the number isn't going down once you start shutting down daemons
        * You can check this after every shutdown or just periodically
    #. Cleanup CSCs and Daemons on DM and Camera machines (:ref:`Summit <Deployment-Activities-Summit-DM-Camera-Shutdown>`, :ref:`NTS <Deployment-Activities-NTS-DM-Camera-Shutdown>`)
        * One can work with the system principles to shutdown the services
    #. Shutdown LOVE and associated daemon (:ref:`Summit <Deployment-Activities-Summit-LOVE-Shutdown>`, :ref:`NTS <Deployment-Activities-NTS-LOVE-Shutdown>`)
        * This step will become unnecessary when it moves to Kubernetes
    #. Shutdown and Cleanup Bare Metal Deployments (:ref:`Summit <Deployment-Activities-Summit-TandS-BM-Shutdown>`, :ref:`NTS <Deployment-Activities-NTS-TandS-BM-Shutdown>`)
    #. Cleanup Kubernetes Deployment
        * This uses a script in this repo: https://github.com/lsst-ts/k8s-admin
        * Execute the following (:ref:`Summit <Deployment-Activities-Summit-Kubernetes>`, :ref:`NTS <Deployment-Activities-NTS-Kubernetes>`): *./cleanup_all -d*
            * The *-d* is important as that cleans up the OSPL daemons too
        * If the script fails, you can use ArgoCD to delete the **job/deployment/daemonset** associated with each application you wish to stop. Be sure to delete the job/deployment/daemonset box not the application itself. Note that auxtel and the other "app of apps" meta applications have no jobs; you have to deal with each application individually.
    #. Cleanup Nublado namespaces (:ref:`Summit <Deployment-Activities-Summit-Kubernetes>`, :ref:`NTS <Deployment-Activities-NTS-Kubernetes>`)
        * *kubectl delete ns -l argocd.argoproj.io/instance=nublado-users*
    #. Check to ensure all daemons have disconnected
        * If the reported number is not 0, you will need to investigate further to find the source of the rogue process.
    #. Shutdown and Cleanup Main Daemon (:ref:`Summit <Deployment-Activities-Summit-Main-Daemon-Shutdown>`, :ref:`NTS <Deployment-Activities-NTS-Main-Daemon-Shutdown>`)
#. With everything shutdown, the configurations need to be updated before deployment starts
    * Inform SQuaRE that they can merge the PR for the Nublado update and start the pre-puller
    * Rebase ArgoCD branch to single commit, create and merge PR (if this has not been done previously)
    * All other configuration repositories should have the necessary commits already on branches and pushed to GitHub
    * Update configuration repositories on bare metal machine deployments (:ref:`Summit <Deployment-Activities-Summit-Update-Configuration>`, :ref:`NTS <Deployment-Activities-NTS-Update-Configuration>`)
        * Unlike shutdown, only the T&S systems are handled here. DM and Camera are handled by the system principles
        * Also, only certain T&S systems are handled here, the rest need to be coordinated with system principles
#. Once all configuration in place, deployment of the new system can now begin
    * Be patient with container pulling (goes for everything containerized here)

    #. Startup Main OSPL daemon (:ref:`Summit <Deployment-Activities-Summit-Main-Daemon-Startup>`, :ref:`NTS <Deployment-Activities-NTS-Main-Daemon-Startup>`) and verify that it has started.
        * Verify that each daemon has actually started by running: *docker logs ospl-daemon* and checking for a line that says "daemon ready"
        * To monitor the number of daemons ("federations") as you bring up daemons and single-process CSCs, run the following: *docker exec ospl-daemon grep "federations" durability.log*
    #. Startup Minimal Kubernetes Services
        * This uses the ``sync_apps.py`` script found in https://github.com/lsst-ts/argocd-admin
        * The script is run in the same place that Kubernetes (*kubectl*) interactions are run.
        * Log into the argocd pod by doing the following:
            * *kubectl port-forward svc/argocd-server -n argocd 8888:443 &*
            * *argocd login localhost:8888*
            * Required username/password for the appropriate site
        * *python sync_apps.py \-\-no-sync=love*
        * csc-cluster-config, ospl-config and ospl-daemon apps will be synced automatically
        * Once the ospl-daemon app is synced, the script will pause
        * Check the logs on ArgoCD UI to see if daemons are ready
        * Type ``go`` and enter to move onto syncing the kafka-producers app
        * Script will again pause once the kafka-producers are synced
        * Check that all the logs say "Running" at the bottom. M1M3 now has an indicator saying: "Partial producers are all running"
        * Once all the kafka-producers are verified to be running, type ``go`` and enter to move onto syncing the obssys apps
        * Use the ArgoCD UI to verify that the containers are pulling and running
        * The script will pause again here. Do not proceed further with the script, but leave it alive.
    #. Startup LOVE (:ref:`Summit <Deployment-Activities-Summit-LOVE-Startup>`, :ref:`NTS <Deployment-Activities-NTS-LOVE-Startup>`)
    #. The above now represents a minimal system that other system principles can be allowed to start their daemons/CSCs
        * Use the site specific Slack channel (:ref:`Summit <Pre-Deployment-Activities-Summit-Slack-Announce>`, :ref:`NTS <Pre-Deployment-Activities-NTS-Slack-Announce>`) to inform the system principles
    #. Startup Rest of Kubernetes Services
        * Go back to where your running ``sync_apps.py`` script is and type ``go`` and enter to proceed with syncing the rest of the apps
        * The rest of the apps will be synced automatically so no further intervention is necessary.
        * **NOTE**: The mtrotator-sim is currently deployed on the summit. Stop the running job once the container pull completes.
    #. Startup Services on Bare Metal Deployments (:ref:`Summit <Deployment-Activities-Summit-TandS-BM-Startup>`, :ref:`NTS <Deployment-Activities-NTS-TandS-BM-Startup>`)
#. Once the deployment steps have been executed, the system should be monitored to see if all CSCs come up into STANDBY/OFFLINE. Daemons can also be monitored for connection using the methods listed above.
    * Use the site specific resources to help ascertain this condition
    * Report any issues directly to the system principles (DMs are OK) to get issue corrected
    * This step is completed when either all CSCs are in STANDBY/OFFLINE or CSCs with issues cannot be fixed in a reasonable (~30 minutes) amount of time
    * If leaving this step with CSCs in non-working order, make sure to report that on the site specific Slack channel
#. Certain sites require that some CSCs be put into ENABLED state (:ref:`Summit <Deployment-Activities-Summit-Enabled-CSCs>`, :ref:`NTS <Deployment-Activities-NTS-Enabled-CSCs>`)
#. If not carrying on with integration testing, folks can be told they can use Nublado again via the site specific Slack channel.

Site Specific Variations
========================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    summit/*
    ncsa-teststand/*

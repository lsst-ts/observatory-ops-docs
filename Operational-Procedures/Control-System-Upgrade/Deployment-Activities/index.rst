Deploying the Upgrade
=====================

These are the activities that are performed when the time of deployment comes around.
You will need access to a number of resources (:ref:`Summit <Deployment-Activities-Summit-Resources>`, :ref:`TTS <Deployment-Activities-TTS-Resources>`) at the sites so be sure that you have the credentials to do so.
A number of scripts are available for easing the bare metal docker-compose deployment handling.
The scripts can be retrieved from this repo: https://github.com/lsst-ts/docker-compose-admin.
Use the scripts from the appropriate site directory.
If changes are necessary to these scripts from work described in the previous section, use the appropriate site Jira ticket.

.. note::

  The deployment is only concerned with CSCs and systems (:ref:`Summit <Deployment-Activities-Summit-Non-Production>`, :ref:`TTS <Deployment-Activities-TTS-Non-Production>`) in the production domain (domainId = 0).
  All other domains are left alone.

.. attention::

  As the person running the deployment, you have absolute control over the system to complete this process.
  No one should do anything without your express consent.

#. Log into the machines for bare metal deployments and Kubernetes access (:ref:`Summit <Deployment-Activities-Summit-BareMetal>`, :ref:`TTS <Deployment-Activities-TTS-BareMetal>`)
#. Use LOVE or Nublado to send all CSC systems to OFFLINE state.

    * **WARNING**: Not all CSCs report OFFLINE; these will instead report STANDBY as the last state seen.
      Check for heartbeats to be sure. (:ref:`Summit <Deployment-Activities-Summit-Odd-State>`)
    * Preference is to use LOVE, but Nublado is a good fall back in case LOVE isn't working.
    * An overall status view is available from LOVE (:ref:`Summit <Deployment-Activities-Summit-LOVE-Summary>`, :ref:`TTS <Deployment-Activities-TTS-LOVE-Summary>`).
    * You can also consult these dashboards on Chronograf. The names are the same across sites.
        * ``AT Summary State Monitor``
        * ``MT Summary State Monitor``
        * ``EAS Summary State Monitor``
        * ``Observatory Systems Summary State Monitor``
    * The Watcher and the ScriptQueues should come down last if running from LOVE.

#. With all the systems OFFLINE, you can log out of your Nubaldo instance as we will clean them up soon.
#. Once all systems are in OFFLINE, still running CSCs/systems and OSPL daemons need to be cleaned up.
    #. Get number of currently running daemons/CSCs still in OFFLINE from main OSPL daemon: (:ref:`TTS <Deployment-Activities-TTS-Federation-Check>`)
        * *docker exec ospl-daemon grep "federations" durability.log*
        * You must give the daemon some time (30 seconds to 2 minutes) before getting worried that the number isn't going down once you start shutting down daemons.
        * You can check this after every shutdown or just periodically.
    #. Cleanup CSCs and Daemons on DM and Camera machines (:ref:`Summit <Deployment-Activities-Summit-DM-Camera-Shutdown>`, :ref:`TTS <Deployment-Activities-TTS-DM-Camera-Shutdown>`).
        * One can work with the system principles to shutdown the services.
    #. Shutdown LOVE and associated daemon (:ref:`Summit <Deployment-Activities-Summit-LOVE-Shutdown>`, :ref:`TTS <Deployment-Activities-TTS-LOVE-Shutdown>`).
        * This step will become unnecessary when it moves to Kubernetes.
    #. Shutdown and Cleanup Bare Metal Deployments (:ref:`Summit <Deployment-Activities-Summit-TandS-BM-Shutdown>`, :ref:`TTS <Deployment-Activities-TTS-TandS-BM-Shutdown>`).
    #. Cleanup Kubernetes Deployment.
        * Below uses scripts in this repo: https://github.com/lsst-ts/k8s-admin.
        * Execute the following (:ref:`Summit <Deployment-Activities-Summit-Kubernetes>`, :ref:`TTS <Deployment-Activities-TTS-Kubernetes>`): *./cleanup_all -d*
            * The *-d* is important as that cleans up the OSPL daemons too.
        * If the script fails, you can use Argo CD to delete the **job/deployment/daemonset** associated with each application you wish to stop. Be sure to delete the job/deployment/daemonset box not the application itself. Note that auxtel and the other "app of apps" meta applications have no jobs; you have to deal with each application individually.
        * Execute the following (:ref:`TTS <Deployment-Activities-TTS-Kubernetes>`): *./cleanup_love*
    #. Cleanup Nublado namespaces (:ref:`Summit <Deployment-Activities-Summit-Kubernetes>`, :ref:`TTS <Deployment-Activities-TTS-Kubernetes>`).
        * Below uses a script in this repo: https://github.com/lsst-ts/k8s-admin.
        * *./cleanup_nublado*
    #. Check to ensure all daemons have disconnected.
        * If the reported number is not 0, you will need to investigate further to find the source of the rogue process.
    #. Shutdown and Cleanup Main Daemon (:ref:`Summit <Deployment-Activities-Summit-Main-Daemon-Shutdown>`, :ref:`TTS <Deployment-Activities-TTS-Main-Daemon-Shutdown>`).
#. With everything shutdown, the configurations need to be updated before deployment starts.
    * Ensure SQuaRE has approved the ``cachemachine`` PR and then merge the PR.
    * Rebase Argo CD branch to single commit, create a PR and merge PR.
    * All other configuration repositories should have the necessary commits already on branches and pushed to GitHub.
    * Update configuration repositories on bare metal machine deployments (:ref:`Summit <Deployment-Activities-Summit-Update-Configuration>`, :ref:`TTS <Deployment-Activities-TTS-Update-Configuration>`).
        * Unlike shutdown, only the T&S systems are handled here. DM and Camera are handled by the system principles.
        * Also, only certain T&S systems are handled here, the rest need to be coordinated with system principles.
#. Once all configuration in place, deployment of the new system can now begin.
    * Be patient with container pulling (goes for everything containerized here).

    #. Update Nublado
        * From the site specific Argo CD UI, find the ``cachemachine`` app.
        * It should indicate ``OutOfSync`` (yellow) status, so click the ``Sync`` button to begin the process.
        * Once it syncs, a new pod will start from the ``cachemachine`` **deployment**.
        * Delete that running pod so a new one starts up.
        * The Nublado pull will be completed when the child processes from the new pod all complete and no downstream APIs are shown in the UI.
    #. Startup Main OSPL daemon (:ref:`Summit <Deployment-Activities-Summit-Main-Daemon-Startup>`, :ref:`TTS <Deployment-Activities-TTS-Main-Daemon-Startup>`) and verify that it has started.
        * Verify that each daemon has actually started by running: *docker logs ospl-daemon* and checking for a line that says "daemon ready".
        * To monitor the number of daemons ("federations") as you bring up daemons and single-process CSCs, run the following: *docker exec ospl-daemon grep "federations" durability.log* (:ref:`TTS <Deployment-Activities-TTS-Federation-Check>`)
    #. Startup Minimal Kubernetes Services (:ref:`TTS <Deployment-Activities-TTS-Minimal-K8S-System>`)
        * This uses the ``sync_apps.py`` script found in https://github.com/lsst-ts/argocd-admin.
        * The script is run in the same place that Kubernetes (*kubectl*) interactions are run.
        * Log into the argocd pod by doing the following:
            * *python argocd_login.py /path/to/auth_file*
            * The *auth_file* must contain the appropriate site username/password on separate lines.
        * *python sync_apps.py -p \-\-no-sync=love*
        * csc-cluster-config, ospl-config and ospl-daemon apps will be synced automatically.
        * Once the ospl-daemon app is synced, the script will pause.
        * Check the logs on Argo CD UI to see if daemons are ready.
        * Type ``go`` and enter to move onto syncing the kafka-producers app.
        * Script will again pause once the kafka-producers are synced.
        * Check that all the logs say "Running" at the bottom. M1M3 now has an indicator saying: "Partial producers are all running".
        * Once all the kafka-producers are verified to be running, stop here but leave the script alive.
    #. Startup Bare Metal LOVE (:ref:`Summit <Deployment-Activities-Summit-LOVE-Startup>`, :ref:`TTS <Deployment-Activities-TTS-LOVE-Startup>`).
    #. Continue Kubernetes Deployment
        * Go back to where your running ``sync_apps.py`` script is and type ``go`` and enter to move onto syncing the obssys apps.
        * Use the Argo CD UI to verify that the containers are pulling and running.
        * The script will pause again here. Do not proceed further with the script, but leave it alive.
    #. The above now represents a minimal system that other system principles can be allowed to start their daemons/CSCs.
        * Use the site specific Slack channel (:ref:`Summit <Pre-Deployment-Activities-Summit-Slack-Announce>`, :ref:`TTS <Pre-Deployment-Activities-TTS-Slack-Announce>`) to inform the system principles.
    #. Startup Rest of Kubernetes Services.
        * Go back to where your running ``sync_apps.py`` script is and type ``go`` and enter to proceed with syncing the rest of the apps.
        * The rest of the apps will be synced automatically so no further intervention is necessary.
    #. Startup Services on Bare Metal Deployments (:ref:`Summit <Deployment-Activities-Summit-TandS-BM-Startup>`, :ref:`TTS <Deployment-Activities-TTS-TandS-BM-Startup>`).
#. Once the deployment steps have been executed, the system should be monitored to see if all CSCs come up into STANDBY/OFFLINE. Daemons can also be monitored for connection using the methods listed above.
    * Use the site specific resources to help ascertain this condition.
    * Report any issues directly to the system principles (DMs are OK) to get issue corrected.
    * This step is completed when either all CSCs are in STANDBY/OFFLINE or CSCs with issues cannot be fixed in a reasonable (~30 minutes) amount of time.
    * If leaving this step with CSCs in non-working order, make sure to report that on the site specific Slack channel.
#. Certain sites require that some CSCs be put into ENABLED state (:ref:`Summit <Deployment-Activities-Summit-Enabled-CSCs>`, :ref:`TTS <Deployment-Activities-TTS-Enabled-CSCs>`).
#. If not carrying on with integration testing, folks can be told they can use Nublado again via the site specific Slack channel.

Site Specific Variations
========================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    summit/*
    tucson-teststand/*

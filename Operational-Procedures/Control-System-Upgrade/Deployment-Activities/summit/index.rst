Summit
======

This section contains site specific variations for the summit.

.. _Deployment-Activities-Summit-Resources:

Resources
---------

* LOVE: http://amor01.cp.lsst.org
* Argo CD: https://summit-lsp.lsst.codes/argo-cd
* Chronograf: https://chronograf-summit-efd.lsst.codes/
* Nublado: https://summit-lsp.lsst.codes/
* Rancher: https://rancher.cp.lsst.org (1)
* Slack: #summit-announce

(1) Need to get kubeconfig file from here.
File a `Jira ticket <https://jira.lsstcorp.org/projects/IHS>`_ with Chilean IT for access.
Once able to log into Rancher:

#. Select the yagan cluster.
#. Click the Kubeconfig File button in top-right.
#. Near bottom of dialog, click the download link.

.. _Deployment-Activities-Summit-Non-Production:

Non-Production Systems
----------------------

The non-production domain systems list is kept here: `Summit deployment <https://confluence.lsstcorp.org/display/LTS/Summit+deployment>`_.

.. _Deployment-Activities-Summit-BareMetal:

Bare Metal Machines
-------------------

* Main OSPL Daemon: azar1.cp.lsst.org
* T&S CSCs: azar2.cp.lsst.org
* LOVE: amor01.cp.lsst.org
* LOVE2: amor02.cp.lsst.org
* Kubernetes: Can be done from own machine, just need kubeconfig file and kubectl installed.
    * Systems run on the yagan cluster.
    * Can also use: https://k8slens.dev/.
* ATCamera (Tony Johnson): atsccs1.cp.lsst.org
* CCCamera(Tony Johnson): comcam-mcm.cp.lsst.org
* ATArchiver (Steve Pietrowicz): atarchiver.cp.lsst.org
* CCArchiver (Steve Pietrowicz): comcam-arctl01.cp.lsst.org
* M1M3 Dev (Petr Kubánek): m1m3-dev.cp.lsst.org
* M1M3 Test (Petr Kubánek): m1m3-test.cp.lsst.org
* M1M3 Support cRIO (Petr Kubánek): 139.229.178.182
* M1M3 VMS cRIO (Petr Kubánek): 139.229.178.183
* M2 VMS cRIO (Petr Kubánek): 139.229.178.193
* ATMCS/ATPneumatics cRIO (Tiago Ribeiro): 139.229.170.47
* AT PMD (Eric Coughlin): at-keener.cp.lsst.org
* M2 Control (Te-Wei Tsai): m2-control.cp.lsst.org

.. _Deployment-Activities-Summit-Odd-State:

Odd State Components
--------------------

ATMCS and ATPneumatics do not respond to being sent to OFFLINE and will remain in STANDBY with heartbeats still present.
ATPtg has some race condition where it looks to remain in STANDBY but the CSC is actually OFFLINE (no heartbeat is seen).

.. _Deployment-Activities-Summit-LOVE-Summary:

LOVE Summary View
-----------------

The overall system summary state view is called ``ASummary State View``.

.. _Deployment-Activities-Summit-DM-Camera-Shutdown:

Shutdown DM and Camera Services
-------------------------------

* Shutdown/Cleanup daemon on Archiver machines:
    * *docker stop ospl-daemon*
    * *docker rm ospl-daemon*
* Shutdown Camera OCS Bridges:
    * ATCamera: *sudo systemctl stop ats-ocs-bridge.service*
    * CCCamera: *sudo systemctl stop comcam-ocs-bridge.service*
* Shutdown Camera Daemons
    * *sudo systemctl stop opensplice.service*
    * Command is the same everywhere.

.. _Deployment-Activities-Summit-LOVE-Shutdown:

Shutdown LOVE
-------------

This needs to be done from amor01.

* Uses the ``docker-compose-admin`` scripts in ``summit/amor01`` directory.
    * *./shutdown_love*
    * *./shutdown_daemon*

If LOVE2 is operating, go to amor02.

* Uses the ``docker-compose-admin`` scripts in ``summit/amor02`` directory.
    * *./shutdown_love*
    * *./shutdown_daemon*

.. _Deployment-Activities-Summit-TandS-BM-Shutdown:

Shutdown T&S Bare Metal Services
--------------------------------

Handle azar2:

* Uses the ``docker-compose-admin`` scripts in ``summit/azar2`` directory.
    * *./shutdown_eas*
    * *./shutdown_daemon*

Handle AT systems (ATMCS and ATPneumatics):

* *ssh admin@139.229.170.47*
* *vim /usr/ts_ddsconfig/config/ospl-shmem.xml*
* Line 4: replace 0 with 2 in the <Id> tag.
* *reboot && exit*

Handle M1M3 cRIO:

* *ssh admin@139.229.178.182*
* */etc/init.d/ts-M1M3support stop*

Handle M1M3 VMS cRIO:

* *ssh admin@139.229.178.183*
* */etc/init.d/ts-VMS stop*

Handle M2 VMS cRIO:

* *ssh admin@139.229.178.193*
* */etc/init.d/ts-VMS stop*

Handle M1M3 Dev & Test:

* ssh to those machines.
* *ps wuax | grep splice*
* *sudo kill <PID>* on any processes turned up by the previous command.

AT PMD (at-keener):

* Uses ``docker-compose-ops``, so should be similar to azar2 (just doesn't have ``docker-compose-admin`` scripts).

M2 Control:

* ssh to that machine.
* *ps wuax | grep splice*
* *sudo kill <PID>* on any processes turned up by the previous command.

.. _Deployment-Activities-Summit-Kubernetes:

Interacting with Kubernetes
---------------------------

Commands can be executed from your own machine with *kubectl* and the proper kubeconfig file.

.. _Deployment-Activities-Summit-Main-Daemon-Shutdown:

Shutdown Main Daemon
--------------------

This needs to be done from azar1.

* Uses the ``docker-compose-admin`` scripts in ``summit/azar1`` directory.
    * *./shutdown_daemon*

.. _Deployment-Activities-Summit-Update-Configuration:

Update Configuration
--------------------

* Gather the branch for the configurations and version number for ``ts_ddsconfig``.
* Uses the ``docker-compose-admin`` scripts in ``summit`` directory.
* Directories to update:
    * ``/deploy-lsstts/docker-compose-ops`` (azar1, azar2, amor01, amor02)
    * ``/deploy-lsstts/ts_ddsconfig`` (azar1, azar2, amor01, amor02)
    * ``/deploy-lsstts/LOVE-integration-tools`` (amor01, amor02)
    * *sudo ./update_repo <repo path> <branch or version>*
* This will fail if the branch has local modifications. At that point you may as well just do the job manually. Here is one way to do that:
    * *cd /deploy-lsstts/<problem directory>*
    * *git status*
    * *sudo git reset --hard origin/<current ticket branch>*
    * Return to the ``docker-compose-admin`` scripts and run the *update_repo* command again.

.. _Deployment-Activities-Summit-Main-Daemon-Startup:

Startup Main Daemon
-------------------

This needs to be done from azar1.

* Uses the ``docker-compose-admin`` scripts in ``summit/azar1`` directory.
    * *./launch_daemon*

.. _Deployment-Activities-Summit-LOVE-Startup:

Startup LOVE
-------------

This needs to be done from amor01.

* Uses the ``docker-compose-admin`` scripts in ``summit/amor01`` directory.
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding.
    * *./launch_love*

If LOVE2 is operating, go to amor02.

* Uses the ``docker-compose-admin`` scripts in ``summit/amor02`` directory.
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding.
    * *./launch_love*

.. _Deployment-Activities-Summit-TandS-BM-Startup:

Startup T&S Bare Metal Services
-------------------------------

Handle azar2:

* Uses the ``docker-compose-admin`` scripts in ``summit/azar2`` directory.
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding.
    * *./launch_eas*

.. _Deployment-Activities-Summit-Enabled-CSCs:

Enabled CSCs
------------

The following CSCs are configured to go into ENABLED state automatically upon launching:

* Watcher
* ScriptQueue:1
* ScriptQueue:2

There are a few CSCs that must be put into ENABLED state before declaring an end to the deployment.
These are:

* WeatherStation:1

The WeatherStation:1 can be started by using the ``set_summary_state.py`` script once the ScriptQueues are ENABLED.
The systems require specific configuration settings for optimal operation.
They are:

* WeatherStation:1 - default

NCSA Test Stand
===============

This section contains site specific variations for the NCSA test stand.

.. _Deployment-Activities-NTS-Resources:

Resources
---------

* LOVE: ssh -L 8080:lsst-teststand-ts1.ncsa.illinois.edu:80 -J <username>@lsst-login01.ncsa.illinois.edu lsst-teststand-ts1.ncsa.illinois.edu
* ArgoCD: https://lsst-argocd-nts-efd.ncsa.illinois.edu/argo-cd
* Chronograf: https://lsst-chronograf-nts-efd.ncsa.illinois.edu/
* Nublado: https://lsst-nts-k8s.ncsa.illinois.edu/
* Kubeconfig: File a `Jira ticket <https://jira.lsstcorp.org/projects/IHS>`_ for NCSA IT for access and kubeconfig file
* Slack: #ncsa-integ-teststand

.. _Deployment-Activities-NTS-Non-Production:

Non-Production Systems
----------------------

The NCSA test stand operates all CSCs and systems on the production domain.

.. _Deployment-Activities-NTS-BareMetal:

Bare Metal Machines
-------------------

* Main OSPL Daemon: lsst-l1-cl-ocs.ncsa.illinois.edu
* LOVE: lsst-teststand-ts1.ncsa.illinois.edu
* T&S CSCs: lsst-teststand-ts2.ncsa.illinois.edu
* Kubernetes: lsst-login0X.ncsa.illinois.edu
    * Systems run on the NTS k8s cluster
* ATCamera (Tony Johnson): lsst-nts-ccs2.ncsa.illinois.edu
* CCCamera (Tony Johnson): lsst-nts-ccs1.ncsa.illinois.edu
* HeaderService (Felipe Menanteau): lsst-nts-ccheader.ncsa.illinois.edu
* Archiver (Steve Pietrowicz): lsst-l1-cl-arctl.ncsa.illinois.edu

.. _Deployment-Activities-NTS-LOVE-Summary:

LOVE Summary View
-----------------

The overall system summary state view is called ``Summary State``.

.. _Deployment-Activities-NTS-DM-Camera-Shutdown:

Shutdown DM and Camera Services
-------------------------------

* Shutdown/Cleanup daemon on Archiver machines:
    * *docker stop ospl-daemon*
    * *docker rm ospl-daemon*
* Shutdown Camera OCS Bridges:
    * ATCamera: *sudo systemctl stop ocs-bridge-atcamera.service*
    * CCCamera: *sudo systemctl stop ocs-bridge-comcam.service*
* Shutdown Camera Daemons
    * *sudo systemctl stop opensplice.service*
    * Command is the same everywhere
* Shutdown the HeaderService Daemon
    * *sudo su felipe*
    * *screen -ls*
    * Find the screen ID that has *daemon* in the name
    * *screen -r <daemon screen id>*
    * *Crtl+c* to stop the running daemon
    * Exit the screen session (*Ctrl+a d*)

.. _Deployment-Activities-NTS-LOVE-Shutdown:

Shutdown LOVE
-------------

This needs to be done from lsst-teststand-ts1

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-teststand-ts1`` directory
    * *./shutdown_love*
    * *./shutdown_daemon*

.. _Deployment-Activities-NTS-TandS-BM-Shutdown:

Shutdown T&S Bare Metal Services
--------------------------------

Handle lsst-teststand-ts2

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-teststand-ts2`` directory
    * *./shutdown_atmcs_atp*
    * *./shutdown_m1m3_m2*
    * *./shutdown_daemon*

.. _Deployment-Activities-NTS-Kubernetes:

Interacting with Kubernetes
---------------------------

Commands can be executed from the NCSA login machines (lsst-login0X.ncsa.illinois.edu) with *kubectl* and the proper kubeconfig file.

.. _Deployment-Activities-NTS-Main-Daemon-Shutdown:

Shutdown Main Daemon
--------------------

This needs to be done from lsst-l1-cl-ocs

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-l1-cl-ocs`` directory
    * *./shutdown_daemon*

.. _Deployment-Activities-NTS-Update-Configuration:

Update Configuration
--------------------

* Gather the branch for the configurations and version number for ``ts_ddsconfig``
* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand`` directory
* Directories to update:
    * ``/deploy-lsstts/docker-compose-ops`` (lsst-l1-cl-ocs, lsst-teststand-ts1, lsst-teststand-ts2)
    * ``/deploy-lsstts/ts_ddsconfig`` (lsst-l1-cl-ocs, lsst-teststand-ts1, lsst-teststand-ts2)
    * ``/deploy-lsstts/LOVE-integration-tools`` (lsst-teststand-ts1)
    * *./update_repo <repo path> <branch or version>*
* This will fail if the branch has local modifications. At that point you may as well just do the job manually. Here is one way to do that:
    * *cd /deploy-lsstts/<problem directory>*
    * *git status*
    * *sudo git reset --hard origin/<current ticket branch>*
    * Return to the ``docker-compose-admin`` scripts and run the *update_repo* command again

.. _Deployment-Activities-NTS-Main-Daemon-Startup:

Startup Main Daemon
-------------------

This needs to be done from lsst-l1-cl-ocs

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-l1-cl-ocs`` directory
    * *./launch_daemon*

.. _Deployment-Activities-NTS-LOVE-Startup:

Startup LOVE
------------

This needs to be done from lsst-teststand-ts1

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-teststand-ts1`` directory
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding
    * *./launch_love*

.. _Deployment-Activities-NTS-TandS-BM-Startup:

Startup T&S Bare Metal Services
-------------------------------

Handle lsst-teststand-ts2

* Uses the ``docker-compose-admin`` scripts in ``ncsa-teststand/lsst-teststand-ts2`` directory
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding
    * *./launch_atmcs_atp*
    * *./launch_m1m3_m2*

.. _Deployment-Activities-NTS-Enabled-CSCs:

Enabled CSCs
------------

If proceeding with integration testing, the CSCs will be brought to ENABLED state as part of that process.
You can be using all of the startup processes to recovery the NTS from the quarterly maintenance.
In this case, all of the CSCs must be returned to ENABLED state.
The ScriptQueues can be ENABLED using the ATQueue and MTQueue views in LOVE.
Click the cog wheel next to the Summary State display to chose Disable.
Click the cog wheel next to the Summary State display to chose Enable.
For the other components, leverage the following scripts.
Required configurations will be given for each script execution.

* ``set_summary_state.py``

  .. code:: bash

    data:
      -
        - Watcher
        - ENABLED
        - ncsa
* ``auxtel/enable_atcs.py``

  .. code:: bash

    athexapod: ncsa
    atdome: current
    ataos: current
* ``auxtel/enable_latiss.py``

  .. code:: bash

    atcamera: Normal
    atspectrograph: current
* ``maintel/enable_mtcs.py``

  .. code:: bash

    mtm1m3: Default
    mthexapod_1: default
    mthexapod_2: default
* ``maintel/enable_comcam.py``

  .. code:: bash

    cccamera: Normal
* ``set_summary_state.py``

  .. code:: bash

    data:
      -
        - DSM:1
        - ENABLED
      -
        - DSM:2
        - ENABLED
* ``set_summary_state.py``

  .. code:: bash

    data:
      -
        - Scheduler:1
        - ENABLED
      -
        - Scheduler:2
        - ENABLED
      -
        - OCPS
        - ENABLED
        - default

.. note::

  The Schedulers **MUST** be ENABLED after ATPtg and MTPtg have been ENABLED.
  Otherwise they will go into FAULT state.
  That is why this script execution is run last.

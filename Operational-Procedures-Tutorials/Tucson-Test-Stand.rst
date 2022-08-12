.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Write your name here*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Write your name here*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.

.. _Operational-Procedures-Tutorials-Tucson-Test-Stand:

.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########################
Tucson Test Stand (TTS)
###########################

This section contains site specific variations for the Tucson test stand.

.. _Deployment-Activities-TTS-Resources:

Resources
---------

* LOVE: http://love1.tu.lsst.org
* LOVE (k8s): http://love.tu.lsst.org
* Argo CD: https://tucson-teststand.lsst.codes/argo-cd
* Chronograf: https://tucson-teststand-efd.lsst.codes/chronograf
* Nublado: https://tucson-teststand.lsst.codes/
* Rancher: https://rancher.tu.lsst.org (1)
* Slack: #rubinobs-tucson-teststand

(1) Need to get kubeconfig file from here.
File a `Jira ticket <https://jira.lsstcorp.org/projects/IHS>`_ with Tucson IT for access.
Once able to log into Rancher:

#. Select the pillan cluster.
#. Click the Kubeconfig File button in top-right.
#. Near bottom of dialog, click the download link.

.. _Deployment-Activities-TTS-Non-Production:

Non-Production Systems
----------------------

The Tucson test stand operates all CSCs and systems on the production domain.

.. _Deployment-Activities-TTS-BareMetal:

Bare Metal Machines
-------------------

* LOVE: love1.tu.lsst.org
* T&S CSCs: tel-hw1.tu.lsst.org
* Kubernetes: Can be done from own machine, just need kubeconfig file and kubectl installed.
    * Systems run on the pillan cluster.
    * Can also use: https://k8slens.dev/.
* ATCamera (Tony Johnson): auxtel-mcm.tu.lsst.org
* CCCamera (Tony Johnson): comcam-mcm.tu.lsst.org
* ATArchiver (Steve Pietrowicz): auxtel-archiver.tu.lsst.org
* CCArchiver (Steve Pietrowicz): comcam-archiver.tu.lsst.org
* Calibration Systems (Patrick Ingraham): loonie.tu.lsst.org

.. _Deployment-Activities-TTS-LOVE-Summary:

LOVE Summary View
-----------------

The overall system summary state view is called ``Summary State``.

.. _Deployment-Activities-TTS-Federation-Check:

Checking the Number of Federations
----------------------------------

This uses a script in https://github.com/lsst-ts/k8s-admin.
Run *./feds-check* from a machine with *kubectl* and the proper kubeconfig file.

.. _Deployment-Activities-TTS-DM-Camera-Shutdown:

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

.. _Deployment-Activities-TTS-LOVE-Shutdown:

Shutdown LOVE
-------------

This needs to be done from love1.

* Uses the ``docker-compose-admin`` scripts in ``tucson-teststand/love1`` directory.
    * *./shutdown_love*
    * *./shutdown_daemon*

.. _Deployment-Activities-TTS-TandS-BM-Shutdown:

Shutdown T&S Bare Metal Services
--------------------------------

Handle tel-hw1:

* Uses the ``docker-compose-admin`` scripts in ``tucson-teststand/tel-hw1`` directory.
    * *./shutdown_atmcs_atp*
    * *./shutdown_m1m3*
    * *./shutdown_daemon*

Handle calibration systems:

Log into the machines listed in that section then stop and remove all running containers.

.. _Deployment-Activities-TTS-Kubernetes:

Interacting with Kubernetes
---------------------------

Commands can be executed from your own machine with *kubectl* and the proper kubeconfig file.

.. _Deployment-Activities-TTS-Main-Daemon-Shutdown:

Shutdown Main Daemon
--------------------

The main daemon on TTS runs on Kubernetes.
Shut it down by deleting the **deployment** under the ``ospl-main-daemon`` app on Argo CD.

.. _Deployment-Activities-TTS-Update-Configuration:

Update Configuration
--------------------

* Gather the branch for the configurations and version number for ``ts_ddsconfig``.
* Uses the ``docker-compose-admin`` scripts in ``tucson-teststand`` directory.
* Directories to update:
    * ``/deploy-lsstts/docker-compose-ops`` (love1, tel-hw1)
    * ``/deploy-lsstts/ts_ddsconfig`` (love1, tel-hw1)
    * ``/deploy-lsstts/LOVE-integration-tools`` (love1)
    * *sudo ./update_repo <repo path> <branch or version>*
* This will fail if the branch has local modifications. At that point you may as well just do the job manually. Here is one way to do that:
    * *cd /deploy-lsstts/<problem directory>*
    * *git status*
    * *sudo git reset --hard origin/<current ticket branch>*
    * Return to the ``docker-compose-admin`` scripts and run the *update_repo* command again.

.. _Deployment-Activities-TTS-Main-Daemon-Startup:

Startup Main Daemon
-------------------

The main daemon on TTS runs on Kubernetes and will be handled by the *sync_apps.py* script.
This will be detailed in the next section

.. _Deployment-Activities-TTS-Minimal-K8S-System:

Startup Minimal Kubernetes System
---------------------------------

This replaces most of step 6.3 in the main document.
Follow the first three bullet points in that step and then continue the process with the next steps.

* *python sync_apps.py -p*
* csc-cluster-config, ospl-config and ospl-main-daemon apps will be synced automatically.
* Once the ospl-main-daemon app is synced, the script will pause.
* Check the logs on Argo CD UI to see if daemon is ready.
* Type ``go`` and enter to move onto syncing the ospl-daemon app
* Once the ospl-daemon app is synced, the script will pause.
* Check the logs on Argo CD UI to see if daemons are ready.
* Type ``go`` and enter to move onto syncing the kafka-producers app.
* Script will again pause once the kafka-producers are synced.
* The kafka-producers use a startup probe, so once all of the pods show a green heart, type ``go`` and enter to move onto syncing the love app.
* Once the love app is synced, stop here and return to step 6.4 in the main document.
* Make sure you leave the script running.

.. _Deployment-Activities-TTS-LOVE-Startup:

Startup LOVE
------------

This needs to be done from love1.

* Uses the ``docker-compose-admin`` scripts in ``tucson-teststand/love1`` directory.
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding.
    * *./launch_love*

.. _Deployment-Activities-TTS-TandS-BM-Startup:

Startup T&S Bare Metal Services
-------------------------------

Handle tel-hw1

* Uses the ``docker-compose-admin`` scripts in ``tucson-teststand/tel-hw1`` directory.
    * *./launch_daemon*
    * Ensure daemon is ready before proceeding.
    * *./launch_atmcs_atp*
    * *./launch_m1m3*

.. _Deployment-Activities-TTS-Enabled-CSCs:

Enabled CSCs
------------

If proceeding with integration testing, the CSCs will be brought to ENABLED state as part of that process.
All of the startup processes maybe necessary for recovering the TTS from any maintenance.
In this case, all of the CSCs must be returned to ENABLED state.
The following components will automatically transition to ENABLED state when launched:

* Watcher
* ScriptQueue:1
* ScriptQueue:2
* DSM:1
* DSM:2

For the other components, leverage the following scripts.
Required configurations will be given for each script execution.

.. note::

    Both ATCamera and CCCamera must be in OFFLINE_AVAILABLE state before putting them into ENABLED state.

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
        - DIMM:1
        - ENABLED
        - current
      -
        - DIMM:2
        - ENABLED
        - current
      -
        - WeatherStation:1
        - ENABLED
        - default
* ``set_summary_state.py``

  .. code:: bash

    data:
      -
        - Scheduler:1
        - ENABLED
        - standstill
      -
        - Scheduler:2
        - ENABLED
        - standstill
      -
        - OCPS:1
        - ENABLED
        - LATISS
      -
        - OCPS:2
        - ENABLED
        - LSSTComCam

.. note::

  The Schedulers **MUST** be ENABLED **AFTER** ATPtg and MTPtg have been ENABLED.
  Otherwise they will go into FAULT state.
  That is why this script execution is run last.

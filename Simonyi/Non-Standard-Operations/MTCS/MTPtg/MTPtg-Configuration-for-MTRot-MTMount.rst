.. |author| replace:: *Paulina Venegas*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *David Sanmartim* *Jacqueline Seron*


.. _rancher: https://rancher.cp.lsst.org/
.. _Out of Hours Support: https://obs-ops.lsst.io/Safety/out-of-hours-support.html#safety-out-of-hours-support
.. _for AuxTel as well: https://obs-ops.lsst.io/AuxTel/Non-Standard-Operations/index.html
.. _Kubernetes: https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/122454286/Access+to+the+Kubernetes+Cluster
.. _Instructions for ArgoCD : https://obs-ops.lsst.io/Observatory-Control-System/Troubleshooting/CSCs-Troubleshooting/component-offline.html

.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount:

#############################################
MTPtg Configuration for MTRotator and MTMount
#############################################

.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Overview:
Overview
========

This document provides step-by-step instructions for reconfiguring the **MTPtg CSC** of the Simonyi Telescope when either the **MTRotator** and/or **MTMount** components are unavailable. 
These changes are typically needed during hardware failures, maintenance, or subsystem testing when continued tracking or telemetry is still desired.

In such non-standard operational conditions, it's possible to adjust the **MTPtg** configuration to prevent the system from entering a ``FAULT`` state, thereby allowing continued tracking using the remaining functional components.

**The procedures outlined include:**

* Transitioning the **MTPtg CSC** to ``STANDBY`` mode.
* Modifying configuration files within the **MTPtg pod** to reflect the current hardware availability.
* Restarting the **MTPtg CSC** to apply the new configuration.

**Important Information before start.**

.. warning:: 

    Only proceed if you are authorized to modify the **MTPtg** configuration of the Simonyi Telescope.
..

.. warning:: 

    Commissioning Scientists (ComSci) or Observing Specialist (OS) with the ArgoCD training and authorized on shift can change the version of **MTMount CSC** in ArgoCD to **mtmount-ccw-only**. 
    This configurations can deal with tracking without said component.
..


.. note:: 
    
    **Kubernetes authorization**
    
    To execute this procedure, you must have the necessary credentials installed to access the Kubernetes cluster. 
    Refer to the instructions for `Kubernetes`_.
    
..


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Error-Precondition:
Precondition
===============

1. **MTRotator** is not available, but you still want to track **without** the Rotator, using the rest of the components; or you want to **include** the Rotator in the tracking again. 
2. **MTMount** is not available (not starting up, for example), but you still want to use the Camara Cable Wrap (CCW) + Rotator **without** moving or commanding the mount, or you want to revert the change and **include** the mount.

3. The **MTMount CSC** should be configured in the proper CSC version to be operational (only with the CCW component).


    * This is done by the ComSci or the OS in ArgoCD (`Instructions for ArgoCD`_). 
    * The **MTMount** will need to be set to ``OFFLINE`` before switching the CSC version to **mtmount-ccw-only**.
    * To check the CSC version in use, you can open ArgoCD (credentials in 1Password) and search for *simoniyitel*. 
    * The figure shows this page, highlighting the **Synced** status indicating is in this state.


    .. figure:: ./_static/insimonyitel.png
      :width: 2500px
      :height: 250px
      :name: simonyitel

      Fig1. You search “simonyitel” and then click it.
    ..  

    .. figure:: ./_static/mtmount-ccw-only.png
      :width: 2500px
      :height: 250px
      :name: mtmount-ccw-only

      Fig2. You can find “mtmount-ccw-only” job when you scroll down.
    ..  


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Procedure-Steps:
Procedure Steps
===============
Steps
-----
1. Announce through the Slack channel *#summit-simonyi* that the component is not available, and you are about to change the configuration.

2. Issue the :file:`set_summary_state.py` script in LOVE to change the status of **MTPtg** to ``STANDBY`` with the following configuration

    .. code-block::
        :caption: set_summary_state.py

             data:
                 -
                   - MTPtg 
                   - STANDBY
..


3. Find the name of the *pod* where the **MTPtg** is running. 
   
    From your terminal, run the following command which list all the pods related to the simonyitel  :

    .. prompt:: bash
        
        kubectl --kubeconfig=${HOME}/.kube/yagan.yaml get pod -o=custom-columns=NAME:.metadata.name,STATUS:.status.phase,NODE:.spec.nodeName -n simonyitel

    ..

    If you get a :kbd:`command_not_found`, you first need to set up the access to Kubernetes. Follow the instructions for `Kubernetes`_ in step #4.

    .. figure:: ./_static/1.png
      :width: 480px
      :height: 300px
      :name: Your figure

      Fig3. In this particular case the name of the **MTPtg** *pod* is **mtptg-nss2j**, the name changed frequently, every time the CSC is restarted, *(mtptg-xxxxx)*.
    ..  

4. Connect to the **MTPtg** *pod mtptg-nss2j* within the *simonyitel*. The command bellow will open a terminal within the *pod* as *saluser*.

    .. prompt:: bash
    
      kubectl --kubeconfig=${HOME}/.kube/yagan.yaml exec --stdin --tty mtptg-nss2j -n simonyitel -- /bin/bash
    
    ..
   

5. Configuration directory: the configuration files are one level up.  

    .. prompt:: bash

      cd /home/saluser/repos/ts_pointing_common/install/data

    ..
    
    .. figure:: ./_static/3.png
       :width: 850px
       :height: 360px

       Fig4. The directory contains the configuration files :file:`MTPtg.info` and the pointing models :file:`mt.mod` files. 
   
    ..

    .. note:: 
    
        At startup, the pointing component loads by default the pointing model that's on the :file:`mt.mod` file and the :file:`MTPtg.info`.
    ..


6. Edit the :file:`MTPtg.info` file, use a text editor such as *vi*. 

    6.1. Edit the **disable_rotator** paramenter in the :file:`MTPtg.info` file.

    - set 1 : rotator will be **ignored** and will not be commanded by the **MTPtg** component (disabled). 
    - set 0 : rotator will be **included** (enabled)


    .. code-block:: 
        :caption: MTPtg.info / disable_rotator  - Disabled example

            disable_rotator: 1
    ..


    6.2. Edit The **disable_mount** parameter in the :file:`MTPtg.info` file. 

    - set 1 : mount will be **ignored** and will not be commanded by the **MTPtg** component (disabled). 
    - set 0 : mount will be **included** (enabled).

    .. code-block:: 
        :caption: MTPtg.info / disable_mount - Enabled example

            disable_mount: 0
    ..


7. **Exit** the *pod* by typing :command:`exit`.

8. Send the **MTPtg** to ``ENABLED`` using the script :file:`set_summary_state.py` and configuration below in the MTQueue.

    Note: **MTMount** must be ``ENABLED``, even if not tracking, so *CCW* can be still monitored.

    .. code-block::
        :caption: set_summary_state.py

             data:
                 -
                   - MTPtg 
                   - ENABLED
..


.. _MTRotator-or-MTMount-Configuration-Procedure-Post-Condition:

Post-Condition
==============

1. The tracking tests are able to run with a missing component, either **MTMount** or **MTRotator**, if the respective parameter was set to **1**.

2. The tracking tests includes the **MTMount** or **MTRotator**, if the respective parameter was set to **0**.  

3. Once you finish with the procedure, the parameters need to be restored to their original state.


.. _MTRotator-or-MTMount-Configuration-Procedure-Contingency:

Contingency
===========
* If the procedure is not successful, report the issue in #summit-simonyi, inform the Commissioning Scientist on duty, and/or activate the `Out of Hours Support`_.

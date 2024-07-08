.. |author| replace:: *D. Sanmartim*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *P. Venegas*


.. _Out of Hours Support: https://obs-ops.lsst.io/Safety/out-of-hours-support.html#safety-out-of-hours-support
.. _for AuxTel as well: https://obs-ops.lsst.io/AuxTel/Non-Standard-Operations/index.html

.. warning::
    DRAFT

    
.. _MTRotator-or-MTMount-Configuration:

##############################################################
MTRotator or MTMount Configuration Change (Ignore or Include) 
##############################################################

.. warning:: Important Information

- Only proceed if you are authorized to change the configuration of the pointing component ``MTPtg`` of the Simonyi Telescope.
   
- Additionally to this procedure, a change of MTMount CSC version needs to be done in ArgoCD by a commissioning scientist for 
the configuration change to be completely operational. *(See Warning in the procedure steps)*

..

.. note:: Kubernetes authorization

    To execute this procedure you must have installed in your computer the credentials to access the Kubernetes cluster. 

    Move to a more detailed instructions once written.
    
    Open a ticket directed to summit IT to access the Kubernetes cluster at the summit, named yagan, through the rancher at the Summit.
    https://rancher.cp.lsst.org/
    
    Once it is done, you can download your unique credentials and place the yagan.yaml file inside the ~/.kube directory in your local machine.

..

.. _MTRotator-or-MTMount-Configuration-Procedure-Overview:


Overview
========

When either MTRotator or MTMount components become unavailable for any reason and you still want to continue with testing and tracking, 
it's necessary to change the configuration of the MTPtg CSC to avoid comanding these non-available components and go into fault mode.


.. _MTRotator-or-MTMount-Configuration-Procedure-Error-Diagnosis:


Error Diagnosis
===============
 *a.*  MTRotator is not available but you want to still track without rotator, using the rest of the components; or you want to include 
MTRotator in the tracking again.

   or

 *b.*  MTMount/TMA is not available (not starting up for example), but you want to still track without moving or commanding the mount, 
only using CCW + rotator; or you want to revert the change and include MTMount again.


.. _MTRotator-or-MTMount-Configuration-Procedure-Procedure-Steps:


Procedure Steps
===============

.. warning::  Warning
    Announce through the usual Slack channel *#summit-simonyi* that the component is not available, and you are about to change the configuration.
    
    One of the commissioning scientists will be changing the version of MTMount CSC in ArgoCD that can deal with tracking without said component: 
    For that, they will/may request to send the MTMount to ``OFFLINE`` status and will change the ``MTMount`` CSC version to **mtmount-ccw-only**. 
    Follow their instructions.

..

Steps
-----

1. Issue the *set_summary_state.py* script in LOVE to send the ``MTPtg`` to ``STANDBY`` with the following configuration

.. code-block:: *set_summary_state.py*
    data:
        -
        - MTPtg 
        - STANDBY
..

2. **Find the name** of the pod where the ``MTPtg`` is running. 

    The following command will list all the pods related to the <namespace> maintel. 
    
    From your terminal, run:

    .. figure:: /_static/1.jpg
        :alt: Run *kubectl configuration*. In this particular case, the name of the **MTPtg** pod is **mtptg-djhpv**.

..

3. **Connect** to the ``MTPtg`` pod (**mtptg-djhjv** in this case) that is within the <namespace> maintel. 
This command will open a terminal within the pod.

.. code-block:: bash
    $ kubectl --kubeconfig=${HOME}/.kube/yagan.yaml exec --stdin --tty mtptg-djhpv -n maintel -- /bin/bash
..
    

.. figure:: /_static/2.jpg
    :alt: Run *kubectl configuration*. In this particular case, the name of the **MTPtg** pod is **mtptg-djhpv**.

..

4. The configuration files are one level up. **Move** to configuration directory */home/saluser/repos/ts_pointing_common/install/data*

.. code-block:: bash
    [saluser@podname] cd /home/saluser/repos/ts_pointing_common/install/data
..

.. figure:: /_static/3.jpg
    :alt: This directory contains the configuration files **MTPtg.info** (and **ATPtg.info** `for AuxTel as well`_) and the 
    pointing models **mt*.mod files** (**at*.mod** for AuxTel).
        
    At startup, the pointing component loads by default the pointing model that's on the **mt.mod** file and the **MTPtg.info** 
    (and equivalent to AuxTel)

..

5. **Edit** the **MTPtg.info** file with a text editor such as vi. 

5.1. ``MTRotator``: The disable_rotator line of the **MTPtg.info** file contains the parameter you need to change. 
It reflects whether the ``MTRotator`` is monitored in the tracking. 

The parameter set to 1, means that it's being ignored and will not be commanded by the ``MTPtg`` component. 
Edit with VI the **MTPtg.info** file, change this line to 0 or 1 depending on the ``MTRotator`` status.

            **disable_rotator: 1**  

    - **Set 0 → enabled** 
    - **Set 1 → disabled**
.. 


5.2. ``MTMount``: The line containing the disable_mount parameter in the **MTPtg.info** file is the one to edit. It shows whether the ``MTMount`` 
is monitored in the tracking.

            **disable_mount: 0**

    - **Set 0 → enabled** 
    - **Set 1 → disabled**


Above it's set to 0, which means that it's being included and commanded by the ``MTPtg`` component. 
Edit with VI the **MTPtg.info** file, change this line to 0 or 1 depending on the ``MTMount`` status.

6. **Exit** the pod by typing **exit**.

7. From LOVE, **send** the ``MTPtg`` back to ``ENABLED`` using the script *set_summary_state.py* and configuration below. ``MTMount`` 
must be **enabled**, even if not tracking, so ``CCW`` can be still monitored.

.. code-block:: *set_summary_state.py*
    data:
        - 
        - MTPtg
        - ENABLED
..

.. _MTRotator-or-MTMount-Configuration-Procedure-Post-Condition:

Post-Condition
==============
- The tracking tests are able to run with a missing component, either MTMount or MTRotator, if the respective parameter was set to 1.

or

- The tracking tests include the MTMount or MTRotator back if the parameter was set to 0.


.. _MTRotator-or-MTMount-Configuration-Procedure-Contingency:

Contingency
===========
If the procedure is not successful, report the issue in #summit-simonyi, inform the commissioning scientist on duty, and/or activate the 'Out of Hours Support'_.

.. |author| replace:: *David Sanmartim*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Paulina Venegas*


.. _rancher: https://rancher.cp.lsst.org/
.. _Out of Hours Support: https://obs-ops.lsst.io/Safety/out-of-hours-support.html#safety-out-of-hours-support
.. _for AuxTel as well: https://obs-ops.lsst.io/AuxTel/Non-Standard-Operations/index.html


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount:

#############################################
MTPtg Configuration for MTRotator and MTMount
#############################################


.. note:: Important Information before start.

    #. Only proceed if you are authorized to change the configuration of the CSC pointing component ``MTPtg`` of the Simonyi Telescope.
   
    #. A change of the ``MTMount`` CSC version needs to be done in *ArgoCD by a commissioning scientist*.

    #. Remember use VPN.

..

.. note:: Important Information before start.
    
    Kubernetes authorization

    1. To access the Kubernetes Cluster, you must have the necessary credentials installed on your computer.
  
            *Credentials*: Open a ticket directed to summit IT to access the Kubernetes Cluster, named **yagan**, through the rancher_. 

    2. Once it is done, you can download your unique credential and place the :file:`yagan.yaml` file inside the :file:`~/.kube` directory in your local machine.

..

.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Overview:
Overview
========

When either the ``MTRotator`` or ``MTMount`` components become unavailable during Simonyi operations, and you still want to continue testing and tracking,
it's necessary to change the configuration of the ``MTPtg`` CSC to avoid entering into ``FAULT`` mode commanding these unavailable components.


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Error-Diagnosis:
Error Diagnosis
===============

Cases
-----

1. ``MTRotator`` is not available, but you still want to track **without** the Rotator using the rest of the components; or you want to **include** 
the Rotator in the tracking again.

2. ``MTMount`` is not available (not starting up, for example), but you still want to use *CCW* + *Rotator*  **without** moving or commanding the mount, 
or you want to revert the change and **include** the mount.


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Procedure-Steps:
Procedure Steps
===============

.. warning:: 
    
    Announce through the Slack channel *#summit-simonyi* that the component is not available, and you are about to change the configuration.
    
    The Commissioning Scientists on shift will change the version of ``MTMount`` CSC in *ArgoCD*; this can deal with tracking without said component.

        The Commissioning Scientists  may request to send the ``MTMount`` to **OFFLINE**. this will change the ``MTMount`` CSC version to **mtmount-ccw-only**. 
..



Steps
-----

1. Issue the :file:`set_summary_state.py` script in LOVE to change the status of ``MTPtg`` to ``STANDBY`` with the following configuration

    .. code-block::
        :caption: set_summary_state.py

             data:
                 -
                   - MTPtg 
                   - STANDBY
..


2. Find the name of the **pod** where the ``MTPtg`` is running. 
   
    From your terminal, run the following command which list all the **pods** related to the *<namespace>* maintel:

    .. prompt:: bash

     kubectl --kubeconfig=${HOME}/.kube/yagan.yaml get pod -o=custom-columns=NAME:.metadata.name,STATUS:.status.phase,NODE:.spec.nodeName -n maintel

    ..

    .. figure:: ./_static/1.png
      :width: 950px
      :height: 165px
      :name: Your figure

      In this particular case the name of the ``MTPtg`` **pod** is **mtptg-djhpv**.
    ..  

3. Connect to the ``MTPtg`` **pod mtptg-djhjv** within the *<namespace>* maintel. 

    The command will open a terminal within the pod.

    .. prompt:: bash

     kubectl --kubeconfig=${HOME}/.kube/yagan.yaml exec --stdin --tty mtptg-djhpv -n maintel -- /bin/bash

    ..
   
    .. figure:: ./_static/2.png
        :width: 900px
        :height: 65px

    ..

4. **Move to configuration directory,** the configuration files are one level up. The directory contains the configuration files :file:`MTPtg.info` (:file:`ATPtg.info` for AuxTel) and the pointing models :file:`mt.mod` files (:file:`at.mod` for AuxTel). 

    At startup, the pointing component loads by default the pointing model :file:`mt.mod` file and the :file:`MTPtg.info` (equivalent for AuxTel).

    .. prompt:: bash

     [saluser@podname] cd /home/saluser/repos/ts_pointing_common/install/data

    ..
    
    .. figure:: ./_static/3.png
       :width: 900px
       :height: 420px
        
    ..

5. To edit the :file:`MTPtg.info` file use a text editor such as *vi*. 

    5.1. ``MTRotator``: The **disable_rotator** line of the :file:`MTPtg.info` file contains the parameter you need to change. It reflects whether the ``MTRotator`` is monitored in the tracking.
    
    * The parameter *set* is **1**, means that it's being ignored and will not be commanded by the ``MTPtg`` component.

    .. code-block::
        :caption: MTPtg.info: disable_rotator: 1

            - Set 0 → enabled
            - Set 1 → disabled
    ..


    5.2. ``MTMount``: The line containing the **disable_mount** parameter in the :file:`MTPtg.info` file is the one to edit. It shows whether the ``MTMount`` is monitored in the tracking.
   
    * The parameter *set* is *0*, which means that it's being included and commanded by the ``MTPtg`` component.
   
    .. code-block::
        :caption: MTPtg.info: disable_mount: 0

            - Set 0 → enabled
            - Set 1 → disabled
..


6. **Exit** the **pod** by typing :command:`exit`.

7. From LOVE, **send** the ``MTPtg`` back to ``ENABLED`` using the script :file:`set_summary_state.py` and configuration below. ``MTMount`` must be ``ENABLED``, even if not tracking, so ``CCW`` can be still monitored.

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

1. The tracking tests are able to run with a missing component, either ``MTMount`` or ``MTRotator``, if the respective parameter was set to **1**.

2. The tracking tests include the ``MTMount`` or ``MTRotator`` back if the parameter was set to **0**.


.. _MTRotator-or-MTMount-Configuration-Procedure-Contingency:

Contingency
===========
* If the procedure is not successful, report the issue in *#summit-simonyi*, inform the commissioning scientist on duty, and/or activate the xxxxxxOut of Hours Support_.

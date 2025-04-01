.. |author| replace:: *David Sanmartim*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Paulina Venegas*


.. _rancher: https://rancher.cp.lsst.org/
<<<<<<< HEAD
.. _Out of Hours Support: https://obs-ops.lsst.io/Safety/out-of-hours-support.html#safety-out-of-hours-support
.. _for AuxTel as well: https://obs-ops.lsst.io/AuxTel/Non-Standard-Operations/index.html
.. _Detailed instructions for Kubernetes: https://rubinobs.atlassian.net/wiki/spaces/~pvenegas/pages/122454286/Access+to+the+Kubernetes+Cluster
.. _Detailed instructions for Kubernetes in step #4: https://rubinobs.atlassian.net/wiki/spaces/~pvenegas/pages/122454286/Access+to+the+Kubernetes+Cluster
.. _ Instructions for ArgoCD : https://obs-ops.lsst.io/Observatory-Control-System/Troubleshooting/CSCs-Troubleshooting/component-offline.html
=======


>>>>>>> b726c6d (update index - troubleshooting)

.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount:

#############################################
MTPtg Configuration for MTRotator and MTMount
#############################################


.. note:: Important Information before start.

<<<<<<< HEAD
    - Only proceed if you are authorized to change the configuration of the pointing component **MTPtg** of the Simonyi Telescope.

..

.. note:: Important

    - A precondition to this procedure, is that the *MTMount CSC* should be configured in the proper *CSC version* to be operational (only with the CCW component). This is done by the commissioning scientist in *ArgoCD* (`Instructions for ArgoCD`_). They may/will request to send the MTMount to ``OFFLINE`` status before changing the *MTMount CSC version to mtmount-ccw-only*. Follow their instructions. To check the CSC version in use, you can open *ArgoCD* (credentials in 1Password) and search for ‘mtmount’, you will see 3 CSC versions for *MTMount*: **‘mtmount’**, **‘mtmount-ccw-only’**, and **‘mtmount-sim’**. The figure shows this page, highlighting the **Synced** status indicating is in this state, in this case **‘mtmount-ccw-only'**.

..

.. figure:: ./_static/3MTmount-ccw-only-ArgoCD.png
    :width: 600px
    :height: 400px
        
..


.. note:: Kubernetes authorization

    -  To execute this procedure you must have installed in your computer the credentials to access the Kubernetes cluster. 
  
     `Detailed instructions for Kubernetes`_.
    
..



=======
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

>>>>>>> b726c6d (update index - troubleshooting)
.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Overview:
Overview
========

<<<<<<< HEAD
When either the *MTRotator* or *MTMount* components become unavailable during Simonyi operations, and you still want to continue testing and tracking, it's necessary to change the configuration of the *MTPtg CSC* to avoid entering into ``FAULT`` mode.
=======
When either the ``MTRotator`` or ``MTMount`` components become unavailable during Simonyi operations, and you still want to continue testing and tracking,
it's necessary to change the configuration of the ``MTPtg`` CSC to avoid entering into ``FAULT`` mode commanding these unavailable components.
>>>>>>> b726c6d (update index - troubleshooting)


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Error-Diagnosis:
Error Diagnosis
===============

Cases
-----

<<<<<<< HEAD
1. **MTRotator** is not available, but you still want to track **without** the Rotator using the rest of the components; or you want to **include** the Rotator in the tracking again.

2. **MTMount** is not available (not starting up, for example), but you still want to use *CCW + Rotator*  **without** moving or commanding the mount, or you want to revert the change and **include** the mount.
=======
1. ``MTRotator`` is not available, but you still want to track **without** the Rotator using the rest of the components; or you want to **include** 
the Rotator in the tracking again.

2. ``MTMount`` is not available (not starting up, for example), but you still want to use *CCW* + *Rotator*  **without** moving or commanding the mount, 
or you want to revert the change and **include** the mount.
>>>>>>> b726c6d (update index - troubleshooting)


.. _MTMTPtg-Configuration-for-MTRotator-and-MTMount-Procedure-Procedure-Steps:
Procedure Steps
===============

.. warning:: 
    
    Announce through the Slack channel *#summit-simonyi* that the component is not available, and you are about to change the configuration.
    
<<<<<<< HEAD
    The Commissioning Scientists (ComSci) on shift will change the version of *MTMount CSC* in *ArgoCD* to **mtmount-ccw-only**. This configurations can deal with tracking without said component.

..


Steps
-----

1. Issue the :file:`set_summary_state.py` script in LOVE to change the status of *MTPtg* to ``STANDBY`` with the following configuration
=======
    The Commissioning Scientists on shift will change the version of ``MTMount`` CSC in *ArgoCD*; this can deal with tracking without said component.

        The Commissioning Scientists  may request to send the ``MTMount`` to **OFFLINE**. this will change the ``MTMount`` CSC version to **mtmount-ccw-only**. 
..



Steps
-----

1. Issue the :file:`set_summary_state.py` script in LOVE to change the status of ``MTPtg`` to ``STANDBY`` with the following configuration
>>>>>>> b726c6d (update index - troubleshooting)

    .. code-block::
        :caption: set_summary_state.py

<<<<<<< HEAD
        data:
            -
                - MTPtg 
                - STANDBY
..


2. Find the name of the **pod** where the *MTPtg* is running. 
   
    From your terminal, run the following command which list all the pods related to the maintel  :
=======
             data:
                 -
                   - MTPtg 
                   - STANDBY
..


2. Find the name of the **pod** where the ``MTPtg`` is running. 
   
    From your terminal, run the following command which list all the **pods** related to the *<namespace>* maintel:
>>>>>>> b726c6d (update index - troubleshooting)

    .. prompt:: bash

     kubectl --kubeconfig=${HOME}/.kube/yagan.yaml get pod -o=custom-columns=NAME:.metadata.name,STATUS:.status.phase,NODE:.spec.nodeName -n maintel

    ..

<<<<<<< HEAD
If you get a :kbd:`command not found`, you first need to set up docker. Follow the `Detailed instructions for Kubernetes in step #4`_.


    .. figure:: ./_static/1.png
      :width: 950px
      :height: 170px
      :name: Your figure

      In this particular case the name of the *MTPtg* **pod** is **mtptg-djhpv**, name that changed constantly *(by ~ mtptg-xxxxx)*.
    ..  

3. Connect to the *MTPtg* **pod mtptg-djhjv** within the maintel. The command will open a terminal within the pod.
=======
    .. figure:: ./_static/1.png
      :width: 950px
      :height: 165px
      :name: Your figure

      In this particular case the name of the ``MTPtg`` **pod** is **mtptg-djhpv**.
    ..  

3. Connect to the ``MTPtg`` **pod mtptg-djhjv** within the *<namespace>* maintel. 

    The command will open a terminal within the pod.
>>>>>>> b726c6d (update index - troubleshooting)

    .. prompt:: bash

     kubectl --kubeconfig=${HOME}/.kube/yagan.yaml exec --stdin --tty mtptg-djhpv -n maintel -- /bin/bash

    ..
   
    .. figure:: ./_static/2.png
        :width: 900px
        :height: 65px

    ..

<<<<<<< HEAD
4. Configuration directory: the configuration files are one level up. 
=======
4. **Move to configuration directory,** the configuration files are one level up. The directory contains the configuration files :file:`MTPtg.info` (:file:`ATPtg.info` for AuxTel) and the pointing models :file:`mt.mod` files (:file:`at.mod` for AuxTel). 

    At startup, the pointing component loads by default the pointing model :file:`mt.mod` file and the :file:`MTPtg.info` (equivalent for AuxTel).
>>>>>>> b726c6d (update index - troubleshooting)

    .. prompt:: bash

     [saluser@podname] cd /home/saluser/repos/ts_pointing_common/install/data

    ..
<<<<<<< HEAD

=======
    
>>>>>>> b726c6d (update index - troubleshooting)
    .. figure:: ./_static/3.png
       :width: 900px
       :height: 420px
        
    ..

<<<<<<< HEAD
The directory contains the configuration files :file:`MTPtg.info` (:file:`ATPtg.info` for AuxTel) and the pointing models :file:`mt.mod` files (:file:`at.mod` for AuxTel). 

    **At startup, the pointing component loads by default the pointing model that's on the :file:`mt.mod` file and the :file:`MTPtg.info`** (equivalent to AuxTel).



5. To edit the :file:`MTPtg.info` file, use a text editor such as *vi*. 

    The parameter set to **1**, means that it's being **ignored** and will not be commanded by the *MTPtg* component. 


    5.1. *MTRotator*: The **disable_rotator line** in the :file:`MTPtg.info` file contains the parameter you need to change. It reflects whether the ``MTRotator`` is monitored in the tracking.


    .. code-block:: disable_rotator line - Disable example
     :caption: MTPtg.info

        disable_rotator: 1

        - Set 0 → enabled
        - Set 1 → disabled
.. 


    5.2. *MTMount*: The **disable_mount line** in the :file:`MTPtg.info` file is the one to edit. It shows whether the *MTMount* is monitored in the tracking.

    .. code-block:: disable_mount line - Enable example
     :caption: MTPtg.info

        disable_mount: 0

        - Set 0 → enabled
        - Set 1 → disabled

..
   
    Above it's set to *0*, which means that it's being **included** and commanded by the *MTPtg* component. 


6. **Exit** the **pod** by typing exit.

7. From LOVE send the *MTPtg* back to ``ENABLED`` using the script :file:`set_summary_state.py` using the configuration below. 

    **MTMount must be in ``ENABLED`` status, even if not tracking, so The CCW can be still monitored**

    .. code-block:: set_summary_state.py
        data:
            -
                - MTPtg 
                - ENABLED

=======
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
>>>>>>> b726c6d (update index - troubleshooting)
..

.. _MTRotator-or-MTMount-Configuration-Procedure-Post-Condition:

<<<<<<< HEAD

Post-Condition
==============

1. The tracking tests are able to run with a missing component, either *MTMount* or *MTRotator*, if the respective parameter was set to **1**.

2. The tracking tests includes the *MTMount* or *MTRotator*, if the respective parameter was set to **0**.  

3. Once you finish with the procedure, the parameters need to be restored to their original state.
=======
Post-Condition
==============

1. The tracking tests are able to run with a missing component, either ``MTMount`` or ``MTRotator``, if the respective parameter was set to **1**.

2. The tracking tests include the ``MTMount`` or ``MTRotator`` back if the parameter was set to **0**.
>>>>>>> b726c6d (update index - troubleshooting)


.. _MTRotator-or-MTMount-Configuration-Procedure-Contingency:

Contingency
===========
<<<<<<< HEAD
* If the procedure is not successful, report the issue in *#summit-simonyi*, inform to the ComSci on duty, and/or activate the `Out of Hours Support`_.
=======
* If the procedure is not successful, report the issue in *#summit-simonyi*, inform the commissioning scientist on duty, and/or activate the xxxxxxOut of Hours Support_.
>>>>>>> b726c6d (update index - troubleshooting)

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| *Craig Lage*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *I. Sotuela, G. Aravena*
.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.

.. _AuxTel-Non-Standard-Operations-AuxTel-Recovery-after-Shutdown: 

.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##############################
AuxTel Recovery after Shutdown
##############################

.. :author: Craig Lage

.. _AuxTel-Recovery-after-Shutdown-Overview:

Overview
========

This document describes the procedures necessary to recover the AuxTel systems from a major event.
This may include a power shutdown, a major software upgrade, or a loss of network connectivity.

.. _AuxTel-Recovery-after-Shutdown-Precondition:

Precondition
=============

These procedures should be applied whenever the AuxTel systems are not operating normally.
Not all procedures will need to be followed in every case, and the user should use judgment and only apply the recovery procedures to the systems that are not operating normally.

.. note:: 

   Ping the machines before trying to recover the system involved. 
   This helps verify their network connectivity and confirms if they are responsive. 
   If the machines respond to the ping, it indicates they are powered on and connected, which can help in diagnosing the issue and determine if a reset or recovery is necessary.

.. caution::
   
   The preferred method to reset a cRIO is remotely, if not possible, make sure you press the reset button briefly (**less than 1 second**) to power cycle the cRIO. If you hold it for 5 seconds then it will be factory reset.

.. admonition:: Important
   
   - Every time you go to AuxTel building do not forget to follow the :ref:`Safety Entry to AuxTel <Safe-entry-to-AuxTel-Overview>` guidelines.
   - You need to use a pointed object to press the reset button and reset the cRIOs.
   - If you need to restart multiple systems that require activating the safety gate bypass, activate it at the beginning and deactivate it once the recovery process for all required systems is complete.

.. _AuxTel-Recovery-after-Shutdown-Post-Condition:

Post-Condition
==============

- After completing these procedures, the AuxTel systems should be operating normally. 
- The safety gate is **closed** and the bypass is **deactivated**.
- It is recommended to perform a full set of daytime checkouts after completing these procedures to confirm the recovery has been successful.


.. _AuxTel-Recovery-after-Shutdown-Procedure-Steps:

Procedure Steps
===============

The recovery procedures here are divided into several sections:

Main ATCamera electronics and sensor readout cabinet recovery
-------------------------------------------------------------

The main *ATCamera electronics and sensor readout cabinet* is on the first floor, next to the chiller, and is shown in Figure 1.  
Figure 2 shows the inside of this cabinet after opening the door.  
After a loss of power or other major work, the chiller should start up, but there are typically two things that need to be done, as shown by the yellow arrows in Figure 2:

#. The *Pfeiffer vacuum gauge* will stop reading and stop sending telemetry.  
    To reset it, press and hold the :guilabel:`Up arrow` key for 3 seconds.  
    The display should then start reading a vacuum pressure and resume sending telemetry.

#. The *CryoCon temperature controller* will stop controlling.  
    To resume control, press the :guilabel:`Control` button on the front panel. The blue light will come on. 
    Typically, when first pressed, there is short *Overtemp* excursion and the blue light goes off.  In this case press it again.  
    
    The goal is for the blue light to come on and stay on. It may take 2-3 tries for it to stay on.  
    
    .. Rewrite this when remote ccs-shell instructions are more available. 
    
    .. The Control button can also be activated remotely using CCS. 
    .. To open the CCS console, follow :ref:`steps 1 and 2 <Recovery-after-Shutdown-CCS>`.   
    .. From the CCS console run :command:`ccs>ats/CryoCon isInControl` and the :command:`ccs>ats/CryoCon setToControl` commands.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Electronics_cabinet.jpg
   :width: 300

   Figure 1: Location of *ATCamera main electronics cabinet*.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Electronics_cabinet_inside.jpeg
   :width: 300

   Figure 2: Inside *ATCamera main electronics cabinet*.

ATMCS/ATPneumatics recovery
---------------------------

Often the *ATMCS* and *ATPneumatics* CSCs will fail to recover after a loss of power or a software upgrade.  
In this case the **ATMCS/ATPneumatics cRIO** needs to be rebooted.  
It is located inside the :ref:`Main AT Control Cabinet <Cabinet-Content-Diagrams-AT-Control-Cabinet>` on the first floor, shown in Figures 3 and 4.  

Firstly, it is preferred to reboot this cRIO remotely by :command:`ssh` into *atmcs-crio.cp.lsst.org* using the credentials in the 1Password vault and sending the :command:`restart` command:

#. Open a Terminal.

#. *ssh admin@139.229.170.47*

   .. prompt:: bash

      ssh admin@139.229.170.47

    

#. Search for *ATMCS cRIO* in 1Password and copy credentials

#. Send *reboot && exit*

   .. prompt:: bash

      reboot && exit

    

#. After a minute it should be back.

If remote reboot is not possible, then you must manually reset the cRIO:

#. Locate the **ATMCS/ATPneumatics cRIO** and press the reset button briefly (**less than 1 second**).    

   .. list-table::
      :widths: 50 50
      :header-rows: 0

      * - .. figure:: /AuxTel/Non-Standard-Operations/_static/Main_cabinet.jpg
              :scale: 10 %

              Figure 3: *AT Control cabinet*.

        - .. figure:: /AuxTel/Non-Standard-Operations/_static/Main_cabinet_inside.jpg
              :scale: 15 %

              Figure 4: Inside *AT Control cabinet*.

#. The yellow light on the cRIO should come on.  

#. When the yellow light goes out, the reboot is completed.  The CSCs should then be recovered.

ATHexapod recovery
------------------

Sometimes the *ATHexapod* CSC does not recover from a major event.  
The **ATHexapod controller** is also located in the :ref:`Main AT Control Cabinet <Cabinet-Content-Diagrams-AT-Control-Cabinet>` shown in Figure 3. 

In the event of a failure of the ATHexapod CSC:

#. Power cycle the controller by switching off.

#. Wait for 3 minutes.

#. Switch back on.  

.. figure:: /AuxTel/Non-Standard-Operations/_static/ATHexapod_Controller.jpg
   :width: 300
   
   Figure 5: *ATHexapod controller* inside *AT control cabinet*.

.. note:: 
   
   You can also follow the procedures up to *Step 5* in :ref:`ATHexapod fails to enable with the rest of ATCS <ATHexapod-fails-to-enable-with-the-rest-of-ATCS-Procedure-Steps>` for more detailed guidance.


ATCalSys recovery
------------------

The *ATCalSys* generates white and monochromatic light for illuminating the dome screen for calibrations.  
The system is shown in Figure 6. 
There are some steps that must be followed after a power loss to recover it.

#. Ensure that the :ref:`Safety Gate Bypass <Safety-Gate-Procedures-Activate-Deactivate-bypass>` is **activated**. Then, :ref:`open the safety gate <Safety-Gate-Procedures-Gate-operation-Opening-the-gate>`.

#. Restart auxtel-monochromator01.cp.lsst.org (NUC computer). 

   - Locate the *auxtel-monochromator Windows computer* in the :ref:`Illumination System <Cabinet-Content-Diagrams-Illumination-System>` cabinet. After a power failure, this computer does not start automatically.

   .. admonition:: Important

      You need to use a screwdriver to turn the 2 screws to open its door.

   .. list-table::
      :widths: 50 50
      :header-rows: 0

      * - .. figure:: /AuxTel/Non-Standard-Operations/_static/ATCalSys.jpg
              :width: 450

              Figure 6: *ATCalSys*.

        - .. figure:: /AuxTel/Non-Standard-Operations/_static/ATCalSys_power_inside.jpg
              :width: 450

              Figure 7:  Inside the *ATCalSys* power cabinet.

   - Press the :guilabel:`power button` to turn it on. It is a small and round button on the left side of the *auxtel-monochromator Windows computer*.

   .. note:: 

      A configuration update will remove this step in the future, but for now, it is necessary.
    
#. Relaunch LabView

   - Once the computer is powered on, restart LabView by following the procedures in the `AuxTel Illumination System Handbook <https://tstn-032.lsst.io/>`__.

#. Often the *auxtel-ill-control.cp.lsst.org* fails to come up properly after a loss of power. In this case, it must be manually restarted. 
   
   - Locate the computer (top-center device in Figure 7), inside the :ref:`Illumination System <Cabinet-Content-Diagrams-Illumination-System>` cabinet.
   - Find the green and orange power connector at the back.
   - Unplug and replug it to power cycle the computer.
    
   .. It's possible that this can be done remotely with the PDU, but I don't know how to do this. 

#. :ref:`Close the safety gate <Safety-Gate-Procedures-Gate-operation-Closing-the-gate>` and **Deactivate** the :ref:`Safety Gate Bypass <Safety-Gate-Procedures-Activate-Deactivate-bypass>`.

After these steps, *ATCalSys* should be completely recovered. 
For more information about the illumination system please refer to `AuxTel Illumination System Handbook <https://tstn-032.lsst.io/>`__.

ATDome recovery
----------------

The AuxTel dome has experienced several problems in the past, most of which have been fixed with the new cRIO hardware and software for ATDome. 
However, after a shutdown or an unexpected outage, it is always necessary to reboot the components to restore proper operation.
More details on interfacing with the ATDome hardware can be found in the technote `SITCOMTN-094 <https://sitcomtn-094.lsst.io/>`__. 
The reset procedure is briefly outlined here:

#. Press the :ref:`safety gate bypass button <Safety-Gate-Introduction-Emergency-safety-mechanisms-Gate-override-AuxTel-safety-gate-bypass>` on the outside of the :ref:`main drive cabinet <Cabinet-Content-Diagrams-AT-Control-Cabinet>` to bypass the safety gate.
   This allows access to the second floor while ensuring the system does not trigger an :ref:`Emergency Stop <Daytime-Operations-Safety-Control-Safety-Systems-Emergency-Stop>`. Once bypassed, :ref:`open the safety gate <Safety-Gate-Procedures-Gate-operation-Opening-the-gate>`.

#. Reset the *Main Box cRIO* inside the :ref:`Dome Main Control Box <Cabinet-Content-Diagrams-Dome-Main-Control-Box>` on the first floor, located between the entrance door and the fan, as shown in Figure 8. 
   Press the reset button briefly (**less than one second**) to initiate the reboot, indicated by the yellow arrow. This step is necessary to restore control functionality after certain failures or power losses.

   .. figure:: /AuxTel/Non-Standard-Operations/_static/Main_Box_cRIO.jpeg
      :width: 400

      Figure 8: Dome Main Control Box.

#. Reset the *Dome Shutter cRIO* inside the :ref:`Dome Shutter Control Box <Cabinet-Content-Diagrams-Dome-Shutter-Control-Box>`, located on the second floor and which rotates with the dome. 
   Perform the same reset procedure as with the *Main Box cRIO*. The reset button is indicated by the yellow arrow.

   .. figure:: /AuxTel/Non-Standard-Operations/_static/Top_Box_cRIO.JPG
      :width: 400

      Figure 9: Dome Shutter Control Box.

   .. admonition:: Important
      
      Always reset the Main Box cRIO first, followed by the Dome Shutter cRIO. Resetting them in the wrong order may cause communication issues.


   .. note::

      The NOIRLab team is making an entirely new box since the current one is too small. 
      Once the work is completed, likely by the end of April 2025, the Dome Shutter Control Box will be different as it being shown in the image.


#. :ref:`Close and re-lock the safety gate <Safety-Gate-Procedures-Gate-operation-Closing-the-gate>`, ensuring it is securely in place. 
   Then, press the :ref:`Safety Gate Bypass button <Safety-Gate-Introduction-Emergency-safety-mechanisms-Gate-override-AuxTel-safety-gate-bypass>` again to **Deactivate** the bypass mode and restore normal safety protections.

.. note:: 

   The Auxiliary Telescope dome is controlled by a system developed by Astronomical Consultants and Equipment, Inc (`Interfacing with the Auxiliary Telescope dome hardware <https://sitcomtn-094.lsst.io/>`__). Low-level control is managed via a telnet interface, allowing operations such as dome rotation and slit opening. 
   Engineering User Interfaces (EUIs) provide status monitoring but offer limited control. 
   The dome’s movement is regulated by a Schneider VFD controller, which adjusts rotation speed and acceleration.

ATCamera recovery
------------------

Recovering the ATCamera is the most complex set of steps in this recovery procedure.  
This procedure assumes that the user is familiar with the CCS Camera Control System software. 
With the complexity of CCS, this document will not be able to cover all possible things that might go wrong. 
However, below are outlined some procedures that will deal with most cases.  
The technote `AuxTel PowerUp sequence <https://sitcomtn-026.lsst.io/>`__ has detailed information on how to power up the camera.

.. _Recovery-after-Shutdown-CCS:

Step 1 - Assess the status of the CCS subsystems
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The easiest way to do this is to open a CCS console:

#. Log in to *auxtel-hcu01*  
   
   .. prompt:: bash

      ssh -XY <your login>@auxtel-hcu01.cp.lsst.org

#. Open a CCS-console

   .. prompt:: bash
      
      ccs-console &
   
   If you have an M1 Mac, this command will result in a black window.  
   In that case, run this command: 
   
   .. prompt:: bash 
      
      ccs-console -Dsun.java2d.xrender=false -Dsun.java2d.pmoffscreen=false&

#. After the CCS-Console window opens, use the pulldown-menu to launch :guilabel:`CCS Tools > Monitoring > Whole Camera > CCS Health`.

#. This should give you a display like Figure 10.  

   All of the subsystems should be operational.  
   However, after a major event, it is likely that one or more of the subsystems are in Engineering Fault.
   Proceed with step 2 to clear the faults out of those failing subsystems. 

.. figure:: /AuxTel/Non-Standard-Operations/_static/CCS-Console.png
   :width: 600

   Figure 10: CCS Health display on CCS-Console

Step 2 - Bring the failing subsystems out of fault
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Bringing the CCS subsystems out of fault requires interfacing with the **CCS Shell**. 
Once you are in the **CCS Shell**, you can issue commands to the various subsystems.
Remember that “tab-complete” is your friend in CCS. 
If you are not sure what commands are available, try hitting tab to see what it shows you.

Some subsystems operate in different modes: a normal mode and an engineering mode. 
Some commands are only accessible in engineering mode. 
Additionally, a lock is placed on a subsystem when certain operations are performed, and it must be removed before the system will operate.
Here is an example of bringing one of the subsystems out of fault, in this case **ats**:

#. Starts the CCS shell from the bash prompt at *auxtel-hcu01.cp.lsst.org*:

   .. prompt:: bash
   
      ccs-shell &

#. Switch to engineering mode and clear alerts:

   .. code-block:: bash

      ccs> ats switchtoEngineeringMode -w
      ccs> ats clearAllAlerts -w
      ccs> ats switchToNormalMode -w


Using the clearAllAlerts command will usually allow you to clear most of the subsystem faults after a major event. 
However, there are some exceptions:

#. The *ats-mcm* (which stands for Master Control Module) can only be cleared this way once other systems are out of alert states. As such it should be cleared last.  
    To clear the alert on *ats-mcm*, run the following command in *ccs-shell*:

    .. code-block:: bash
      
      ccs> ats-mcm clearAllAlerts -w

   .. admonition:: Important

      The *ats-mcm* does not automatically clear its alert state, it always requires a command to do so. 
      Restarting the *ats-mcm* is not a recommended solution and **should not be attempted by the observing team**. 
      If this issue persists, report it in `#summit-auxtel <https://app.slack.com/client/T06D204F2/C01K4M6R4AH>`__ or call for an expert.
    

#. If the WREB board has not been powered up, then *ats-fp* will not be reporting.  
    This requires starting up the WREB board with the :file:`ats-init.py` script, followed by turning on the HV bias.   
    Detailed instructions for starting up the WREB and turning on the HV are available in the `powering up from a completely cold state section of the SITCOMTN-026 <https://sitcomtn-026.lsst.io/#powering-up-from-a-completely-cold-state>`__.  

#. Sometimes, *bonn-shutter* has a fault which can not be cleared with the instructions above.  
    When this happens, the only way that has been found to clear this is to physically power cycle the shutter controller.  
    Figure 11 shows the location of the bonn shutter controller.
    Power cycle it by unplugging the power cable, waiting a few seconds, and plugging it back in.  
    This usually clears the fault.  
    
    .. Again, this might be possible to do this remotely by logging into the PDU, but more details are needed. Include when available.

   .. figure:: /AuxTel/Non-Standard-Operations/_static/Shutter_reboot.jpg
      :width: 600

      Figure 11: Power cycling the *bonn-shutter* controller.

.. _Recovery-after-Shutdown-atcs-ocs-bridge:

Step 3 - Bringing ats-ocs-bridge to the proper state
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

One of the CCS modules is *ats-ocs-bridge*.  
This is the subsystem that interfaces between CCS and the Observatory Control System (i.e. the CSCs).  
In this case *ats-ocs-bridge* is interfacing with the ATCamera CSC.  
It is necessary to get *ats-ocs-bridge* into the proper state in order to be able to control ATCamera with LOVE and the ScriptQueue.  
Here are the necessary steps:

#. Get the state of the *atc-ocs-bridge* running the command from the *ccs-shell*:
   
   .. code-block:: bash

      ccs> ats-ocs-bridge getState

   This will return something like:
   
   .. code-block:: bash
      :caption: ccs> ats-ocs-bridge getState

      AlertState:NOMINAL CCSCommandState:IDLE CommandState:READY 
      ConfigurationState:CONFIGURED OfflineState:OFFLINE_PUBLISH_ONLY 
      OperationalState:ENGINEERING_OK PhaseState:OPERATIONAL 
      SummaryState:OFFLINE
   

#. The *SummaryState* is the same state of ATCamera you see with LOVE.  
    If the SummaryState is ``FAULT``, it cannot be brought out of fault with the normal LOVE commands.  
    It needs to be brought out of fault with the ccs-shell command 
    
    .. code-block:: bash

      ccs> ats-ocs-bridge clearFault -w

#. Assuming the *SummaryState* is ``OFFLINE``, then we look at the *OfflineState*.  
    If the OfflineState is ``OFFLINE_PUBLISH_ONLY``, we need to transition it to ``OFFLINE_AVAILABLE`` before we can use the usual state transition commands in LOVE and the script queue to bring it online.  
    This is done with the ccs-shell command 
   
    .. code-block:: bash

      ccs> ats-ocs-bridge setAvailable -w

#. Transition ATCamera to ``STANDBY``
    Once we have it in *SummaryState* ``OFFLINE`` and *OfflineState* ``OFFLINE_AVAILABLE``, the ATCamera can transition using the script queue and the :file:`set_summary_state.py` to bring the *SummaryState* to ``STANDBY``. 

#. Transition LATISS to ``ENABLED``
    Once the SummaryState is ``STANDBY``, you can run :file:`enable_latiss.py` in the script queue to bring up all of LATISS.  
    If this is successful, things should now be operating normally.


ATSpectrograph Recovery
------------------------

In the case the ATSpectrograph needs to be recovered, follow the procedure from :ref:`ATSpectrograph recovery <LATISS-Troubleshooting-ATspectrograph-Recovery>`.

.. _AuxTel-Recovery-after-Shutdown-Contingency:

Contingency
===========
If the procedure was not successful, report the issue on the `#summit-auxtel <https://app.slack.com/client/T06D204F2/C01K4M6R4AH>`__ channel and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.

This procedure was last modified |today|.
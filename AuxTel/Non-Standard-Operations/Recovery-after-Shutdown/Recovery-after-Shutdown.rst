.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| *Craig Lage*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *I. Sotuela*
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

This document describes to procedures necessary to recover the AuxTel systems from a major event.  
This might include a power shutdown, a major software upgrade, or a loss of network connectivity.  


.. _AuxTel-Recovery-after-Shutdown-Precondition:

Precondition
=============

These procedures should be applied any time the AuxTel systems are not operating normally.
Not all procedures will need to be followed in every case, and the user should use judgement and only apply the recovery procedures to the systems that are not operating normally.

.. _AuxTel-Recovery-after-Shutdown-Post-Condition:

Post-Condition
==============

After completing these procedures, the AuxTel systems should be operating normally.  
It is recommended to perform a full set of daytime checkouts after completing these procedures to confirm the recovery has been successful.



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
In this case the ATMCS/ATPneumatics cRIO needs to be rebooted.  
This is inside the main *AT control cabinet* on the first floor, shown in Figures 3 and 4.  

Press the reset button briefly (less than 1 second).  
The yellow light on the cRIO should come on.  
When the yellow light goes out, the reboot is completed.  The CSCs should then be recovered.  

It is also possible to reboot this cRIO remotely by :command:`ssh user@atmcs-crio.cp.lsst.org`
using the credentials in the 1Password vault (user and password), and sending the :command:`reboot` or :command:`sudo reboot` command.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Main_cabinet.jpg
   :width: 300
   
   Figure 3: *AT Control cabinet*.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Main_cabinet_inside.jpg
   :width: 300

   Figure 4: Inside *AT Control cabinet*.

ATHexapod recovery
------------------

Sometimes the *ATHexapod* CSC does not recover from a major event.  
The ATHexapod controller is also located in the main *AT control cabinet* shown in Figure 3.  

In the event of a failure of the ATHexapod CSC, power cycle the controller by turning it off, waiting approximately 1 minute, and turning it back on.  
The location of the power button is shown in Figure 5.

.. figure:: /AuxTel/Non-Standard-Operations/_static/ATHexapod_Controller.jpg
   :width: 300
   
   Figure 5: *ATHexapod controller* inside *AT control cabinet*.


ATCalSys recovery
------------------

The *ATCalSys* generates white and monochromatic light for illuminating the dome screen for calibrations.  
The system is shown in Figure 6. 
There are typically two things that need to be done after a loss of power to recover it.

#. Arrow #1 in Figure 7 shows the NUC computer that is *auxtel-monochromator01.cp.lsst.org*.  
    After a power failure, it does not start back up automatically.  
    There is a small round power button on the left side of the computer that needs to be pressed to power it up.  
    
    A configuration change that will make this unnecessary is under development, but for now it needs to be done.  
    
    Once the computer is powered up, the LabView instance needs to be relaunched.  
    The procedure for this is outlined in `AuxTel Illumination System Handbook <https://tstn-032.lsst.io/>`__.

#. Often the *auxtel-ill-control.cp.lsst.org* fails to come up properly after a loss of power.  
    In this case, it needs to be manually power cycled.  It is the machine shown by arrow #2 in Figure 7. 
    At the back of the computer, there is a green and orange power connector.  
    This needs to be unplugged and the re-plugged to power cycle the computer. 
    
    .. It's possible that this can be done remotely with the PDU, but I don't know how to do this. 

.. figure:: /AuxTel/Non-Standard-Operations/_static/ATCalSys.jpg
   :width: 400
   
   Figure 6: *ATCalSys*.

.. figure:: /AuxTel/Non-Standard-Operations/_static/ATCalSys_power_inside.jpeg
   :width: 400

   Figure 7:  Inside the *ATCalSys* power cabinet.


ATDome recovery
----------------

*ATDome* does not usually have a problem recovering.  
More detail on interfacing with the ATDome hardware is in the technote `SITCOMTN-094 <https://sitcomtn-094.lsst.io/>`__. 
The reset procedure is briefly outlined here:

#. Press the safety gate bypass button on the outside of the main drive cabinet to bypass the safety gate and then open the safety gate.
#. Reset the *Main Box cRIO* on the first floor as shown in Figure 8.
#. Reset the *Top Box cRIO* on the second floor as shown in Figure 9.
#. Re-lock the safety gate and press the button again to remove the bypass.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Main_Box_cRIO.png
   :width: 400

   Figure 8: *ATDome Main Box cRIO* is reset by pressing the button indicated by arrow 6.

.. figure:: /AuxTel/Non-Standard-Operations/_static/Top_Box_cRIO.png
   :width: 400

   Figure 9: *ATDome Top Box cRIO* is reset by pressing the button indicated by the yellow arrow.


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
      
      $ccs-console &
   
   If you have an M1 Mac, this command will result in a black window.  
   In that case, run this command: 
   
   .. prompt:: bash 
      
      $ccs-console -Dsun.java2d.xrender=false -Dsun.java2d.pmoffscreen=false&

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

Bringing the CCS subsystems out of fault requires interfacing with the *CCS Shell*.  
Once you are in the CCS Shell, you can issue commands to the various subsystems.  

Remember that "tab-complete" is your friend in CCS.  
If you aren't sure what commands are available, try hitting tab to see what it shows you.  

The CCS subsystems have levels of permission which limit what you can do.  
In the lowest level, only some commands will be visible.  At higher levels, you will have access to more commands.  
In addition, there is a normal mode, and an engineering more for each subsystem.  
Some commands are only accessible in engineering mode.  
When you access a higher level, a lock is placed on that subsystem which must be removed before the system will operate.

Here is an example of bringing one of the subsystems out of fault, in this case **ats**:

#. :command:`$ ccs-shell &`            # Starts the CCS shell from the bash prompt at *auxtel-hcu01.cp.lsst.org*
#. :command:`ccs> set level ats 10`    # Set the ats subsystem to the highest level
#. :command:`ccs> ats switchtoEngineeringMode`
#. :command:`ccs> ats clearAllAlerts`
#. :command:`ccs> ats switchToNormalMode`
#. :command:`ccs> unlock ats`           # This sets the level back to 0

For future commands, this guide won't go through all of the locking and unlocking steps, and it's assumed you have brought the subsystem to the necessary level to access the command.  
Using the :command:`clearAllAlerts` command will usually allow you to clear most of the subsystem faults after a major event.  
However, there are some exceptions:

#. The *ats-mcm* (which stands for Master Control Module) can not be cleared in this way.  
    However, after the other faults have been cleared, *ats-mcm* should come out of fault.  
    If it doesn't, try logging into *auxtel-mcm.cp.lsst.org* and running the command :command:`sudo systemctl restart ats-mcm`.  
    Of course, this requires sudo privileges.

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

#. Get the state of the *atc-ocs-bridge* running the command from the *ccs-shell* 
   
   :command:`ccs>ats-ocs-bridge getState`

   This will return something like:
   
    .. code-block:: text
      :caption: :command:`ccs>ats-ocs-bridge getState`
      
      AlertState:NOMINAL CCSCommandState:IDLE CommandState:READY 
      ConfigurationState:CONFIGURED OfflineState:OFFLINE_PUBLISH_ONLY 
      OperationalState:ENGINEERING_OK PhaseState:OPERATIONAL 
      SummaryState:OFFLINE           

#. The *SummaryState* is the same state of ATCamera you see with LOVE.  
    If the SummaryState is ``FAULT``, it cannot be brought out of fault with the normal LOVE commands.  
    It needs to be brought out of fault with the ccs-shell command 
    
    :command:`ccs>ats-ocs-bridge clearFault` 

#. Assuming the *SummaryState* is ``OFFLINE``, then we look at the *OfflineState*.  
    If the OfflineState is ``OFFLINE_PUBLISH_ONLY``, we need to transition it to ``OFFLINE_AVAILABLE`` before we can use the usual state transition commands in LOVE and the script queue to bring it online.  
    This is done with the ccs-shell command 
    
    :command:`ccs>ats-ocs-bridge setAvailable`

#. Transition ATCamera to ``STANDBY``
    Once we have it in *SummaryState* ``OFFLINE`` and *OfflineState* ``OFFLINE_AVAILABLE``, the ATCamera can transition using the script queue and the :file:`set_summary_state.py` to bring the *SummaryState* to ``STANDBY``. 

#. Transition LATISS to ``ENABLED``
    Once the SummaryState is ``STANDBY``, you can run :file:`enable_latiss.py` in the script queue to bring up all of LATISS.  
    If this is successful, things should now be operating normally.



.. _AuxTel-Recovery-after-Shutdown-Contingency:

Contingency
===========
If the procedure was not successful, report the issue on the *#summit-announce* channel and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.


This procedure was last modified |today|.

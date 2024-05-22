.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Paulina-Venegas-S.*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Karla-Aubel*, *Ioana-Soutela*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Mount-Fails-to-Move:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##########################
AuxTel Mount Fails to Move
##########################

.. _AuxTel-Mount-Fails-to-Move-Procedure-Overview:

Overview
========

This troubleshooting procedure is necessary when the AuxTel mount experiences a failure to move, specifically due to the **azimuth max velocity error exceeded**. 
Users will observe the telescope remaining stuck with ATMCS reporting the fault.

.. _AuxTel-Mount-Fails-to-Move-Procedure-Error-Diagnosis:

Error diagnosis
===============

When attempting to move the telescope via point_azel or Scheduler, the faults are the followings:

- The ATMCS get FAULT state ,  ATMCS provides specific error messages indicating faults in azimuth drives #1 and #2, with both fault bits activated.
- The ATPtgg et FAULT state

.. error::
    Fault event in ATMCS while in tracking enable state.  Azimuth max velocity error  exceeded.
    /ATMCS Real-Time Application.vi/MOUNTDEV.vi/Generic Device.lvclass:Run.vi:1530004/MOUNTDEV.lvclass:NormalDeviceLogic.vi/MOUNTDEV.lvclass:ProcessDeviceLogicStateTransitions.vi/MntcTrackEnabledState.lvclass:ProcessStateTransition.vi/mount_fault_state_procedure.vi
 
    Fault event in ATMCS while in tracking enable state.  Azimuth drive #2 fault bit is ON.  Azimuth drive #1 fault bit is ON.  Azimuth max velocity error  exceeded.
    /ATMCS Real-Time Application.vi/MOUNTDEV.vi/Generic Device.lvclass:Run.vi:1530004/MOUNTDEV.lvclass:NormalDeviceLogic.vi/MOUNTDEV.lvclass:ProcessDeviceLogicStateTransitions.vi/MntcTrackEnabledState.lvclass:ProcessStateTransition.vi/mount_fault_state_procedure.vi


.. _AuxTel-Mount-Fails-to-Move-Procedure-Procedure-Steps:


Procedure Steps
===============

.. todo::
   Make sure everything is in a safe or idle state before troubleshooting. 

To resume observations, nudge the telescope out of its position by slewing only in altitude to lower elevation. Then, nudge it incrementally in azimuth, starting with 1-2 degree increments to then increasing to 20-degree increments.

.. note::
    From LOVE.

.. _AuxTel-Mount-Fails-to-Move-Procedure-Critical-Step-1:

#. Stop the scheduler (if running) and clear any pending scripts from the queue by sending **auxtel/scheduler/stop.py**.

#. Cycle the **ATTCS:ATMCS** and **ATTCS:ATPtg**, if necessary, to CSCs to standby and back to enabled.

#. Slew the telescope in small increments using the **auxtel/point_azel.py** script.
   a. If the telescope is pointing at a higher elevation, move it lower.
   b. Start with azimuth and elevation coordinates close to the current position, e.g., Az: 57.64 deg move to Az= 58 deg.
   c. If the initial azimuth-only nudge fails, try nudging in the opposite azimuth direction.
   d. Gradually increase the amplitude of azimuth slews.

#. Example sequence of successful slews:
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **Steps**  | 1  | 2  | 3 | 4 | 5  | 6 | 7  | 8 | 9  | 10  | 11  | 12  |
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **AZ [deg]** | 57.64 | 58 | 60 | 58 | 56 | 54 | 40 | 20 | 1 | 80 | 120 | 150|
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **EL [deg]** | 45 | 45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  60 | 
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
#. Resume the Scheduler if desired.


**pending git commit -m "Cleaning script , minor change of organization"
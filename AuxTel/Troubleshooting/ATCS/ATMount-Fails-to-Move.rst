.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Y. AlSayyad*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *P. Venegas, I.Sotuela, K. Pena*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move:
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

This troubleshooting procedure is necessary when the AuxTel mount experiences a failure to move, 
specifically due to the ``azimuth max velocity error exceeded``. 
Users will observe the telescope remaining stuck with *ATMCS* reporting ``FAULT``.

.. _AuxTel-Mount-Fails-to-Move-Procedure-Error-Diagnosis:

Error diagnosis
===============

When attempting to move the telescope via :file:`point_azel` or Scheduler, the faults are the followings:

- The ATMCS get ``FAULT`` state , ATMCS provides specific error messages indicating ``FAULT``` in azimuth drives #1 and #2, with both ``FAULT`` bits activated.
- The ATPtg get ``FAULT`` state

.. code-block:: text
  :caption: Traceback Error

   Fault event in ATMCS while in tracking enable state.  
   Azimuth max velocity error  exceeded. ATMCS Real-Time Application.vi/MOUNTDEV.vi
   /Generic Device.lvclass:Run.vi:1530004/MOUNTDEV.lvclass:NormalDeviceLogic.vi/MOUNTDEV.
   lvclass:ProcessDeviceLogicStateTransitions.vi/MntcTrackEnabledState.lvclass:
   ProcessStateTransition.vi/mount_fault_state_procedure.vi


.. code-block:: text
  :caption: Traceback Error

   Fault event in ATMCS while in tracking enable state.  
   Azimuth drive #2 fault bit is ON. Azimuth drive #1 fault bit is ON.
   Azimuth max velocity error exceeded. ATMCS Real-Time Application.vi/
   MOUNTDEV.vi/Generic Device.lvclass:Run.vi:1530004/MOUNTDEV.lvclass:
   NormalDeviceLogic.vi/MOUNTDEV.lvclass:ProcessDeviceLogicStateTransitions.vi/
   MntcTrackEnabledState.lvclass:ProcessStateTransition.vi/mount_fault_state_procedure.vi

.. _AuxTel-Mount-Fails-to-Move-Procedure-Procedure-Steps:


Procedure Steps
===============

.. note::
   Make sure everything is in a safe or *idle* state before troubleshooting. 

To resume observations, nudge the telescope out of its position by slewing only in altitude to lower elevation. 
Then, nudge it incrementally in azimuth, starting with 1-2 degree increments to then increasing to 20-degree increments.

**From LOVE**

#. **Stop the Scheduler** and clear any pending scripts. From the queue, send the :file:`auxtel/scheduler/stop.py` script.

#. **Cycle the ATMCS and ATPtg**. If necessary, to CSCs to ``STANDBY`` and back to ``ENABLE``.

#. **Slew the telescope in small increments** using the :file:`auxtel/point_azel.py` script.

   a. If the telescope is pointing at a higher elevation, move it lower.

   b. Start with azimuth and elevation coordinates close to the current position, for instance, from Az= 57.64 deg move to Az=58.00 deg.

   c. If the initial azimuth-only nudge fails, try nudging in the opposite azimuth direction.

   d. Gradually increase the amplitude of azimuth slews.
     Example sequence of successful slews:

      +-------------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
      |  STEP       |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |  11   |  12   | 
      +=============+=======+=======+=======+=======+=======+=======+=======+=======+=======+=======+=======+=======+
      | **Azimuth** | 57.64 |   58  |   60  |   58  |   56  |   54  |   40  |   20  |   1   |   80  |  120  |  150  |
      +-------------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
      |**Elevation**|   45  |   45  |   45  |   45  |   45  |   45  |   45  |   45  |   45  |   45  |   45  |   60  |
      +-------------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+

#. **Resume Scheduler**, if desired.

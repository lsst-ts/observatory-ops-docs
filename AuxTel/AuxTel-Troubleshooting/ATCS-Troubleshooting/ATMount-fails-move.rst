.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

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

.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

This troubleshooting procedure is necessary when the AuxTel mount experiences a failure to move, specifically due to the **azimuth max velocity error exceeded**. 
Users will observe the telescope remaining stuck with ATMCS reporting the fault.

.. _AuxTel-Mount-Fails-to-Move-Procedure-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

When attempting to move the telescope via point_azel or Scheduler the faults are the followings:
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

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

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

   b. If Condition B, do the following action in :ref:`Condition B instructions <Title-of-Troubleshooting-Procedure-Condition-B-for-Step-4>`.

   .. _Title-of-Troubleshooting-Procedure-Final-Step:

#. Example sequence of successful slews:

+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **Steps**  | 1  | 2  | 3 | 4 | 5  | 6 | 7  | 8 | 9  | 10  | 11  | 12  |
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **AZ [deg]** | 57.64 | 58 | 60 | 58 | 56 | 54 | 40 | 20 | 1 | 80 | 120 | 150|
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| **EL [deg]** | 45 | 45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  45 |  60 | 
+------------+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+

#. Resume the Scheduler if desired.
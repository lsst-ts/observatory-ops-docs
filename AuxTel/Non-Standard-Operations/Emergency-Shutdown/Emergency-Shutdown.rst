.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Karla Peña Ramírez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Craig Lage, Eric Christensen, OS team*
.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Non-Standard-Operations-AuxTel-Emergency-Shutdown: 
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#########################
AuxTel Emergency Shutdown
#########################

.. _AuxTel-Emergency-Shutdown-Overview:

Overview
========
.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.
Unfavorable circumstances that indicate the need to close the dome if it is open are:
   - :ref:`Weather constraints <Observing-Constraints-AuxTel-Weather-Constraints>`
   - Sunrise approaching in the next two hours.
   - Power outage affecting the dome shutter mechanism.
 

.. _AuxTel-Emergency-Shutdown-Precondition:

Precondition
=============
.. This section should provide simple overview of preconditions before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

The dome shutter is open and an unforeseeable condition arises, forcing an emergency dome closure.

.. _AuxTel-Emergency-Shutdown-Post-Condition:

Post-Condition
==============
.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.
- The emergency situation has been clearly notified to the relevant personnel and management.
- Steps to eliminate or minimize the risk to the instruments and hardware are being implemented.
- Eventually, the dome shutter is closed and all equipment is safe.

.. _AuxTel-Emergency-Shutdown-Procedure-Steps:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

In the event of an emergency dome closure, the dome shutter won't be able to be operated from the standard CSC controls. 
The AuxTel dome would need to be closed manually. 
In case of sudden inclement weather, be very cautious and start closing early.

.. warning::
    If you are dealing with a dome shutter emergency shutdown. 
    Proceed calmly to keep the equipment safe. 
    Please use the standard safety measures when visiting the dome enclosure. **Safety of personnel always goes first.**

.. _AuxTel-Emergency-Shutdown-Shutter-Closure:

Shutter Closure
---------------
1. Communicate on the *#summit-announce* channel that the observing crew is going to attempt to close the AuxTel dome via the emergency procedure.

2. Go up to the AuxTel dome (second floor).  Locate the control box at the top of the stairs.  The top black button should close the shutter. Note that the safety gate at the bottom of the stairs needs to be closed and locked in order for this button to operate.

.. figure:: /AuxTel/Non-standard-Operations/_static/Box_at_Top_of_Stairs.jpg
  :name: AuxTel control box

3. If the above step fails, locate the AuxTel cRIO box. This box rotates with the AuxTel dome. Open it and identify the cRIO switches.

.. figure:: /AuxTel/Non-standard-Operations/_static/cRIO_box.jpg
  :name: AuxTel cRIO

.. figure:: /AuxTel/Non-standard-Operations/_static/Switches_in_cRIO_box.jpg
  :name: Switches inside AuxTel cRIO

With **EXTREME CAUTION** slide the switch labeled "CLOSE" (yellow arrow) progressively to the left. 
This is a low-level control switch and there are no limit switches or fail-safes. 
It is best to stop the shutter movement about 1 cm before it is fully closed to prevent you over drive the shutter until it bangs into the lower shutter or cause damage on the drive.

.. _AuxTel-Emergency-Shutdown-Shutter-Closure-Without-Power:

Shutter Closure without Power
-----------------------------

1. In the absence of electrical power, the shutter must be closed manually. On AuxTel first floor there is a crank that fits into a ring at the top of the dome. Rotating the ring manually with the crank assistance close the shutter. Note this is a long and physically demanding procedure and the hand crank just does not have enough torque to lift the weight of the shutter if it is all the way open. If you cannot safely insert the crank into the drive motor and operate the crank, then remove the crank and do not proceed.

.. figure:: /AuxTel/Non-standard-Operations/_static/Hand_Crank.jpg
  :name: AuxTel Hand Crank


.. figure:: /AuxTel/Non-standard-Operations/_static/Top_of_Dome.jpg
  :name: Top of Dome

<<<<<<< HEAD
.. _AuxTel-Emergency-Shutdown-Contingency:
=======
>>>>>>> 4f1460d (PR comments addressed on AuxTel Emergency Shutdown)

Contingency
===========
If the procedure was not successful, report the issue on the *#summit-announce* channel and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.


This procedure was last modified |today|.
.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Karla Peña Ramírez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Craig Lage, Eric Christensen, Kris Mortensen, OS team*
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
The AuxTel dome would need to be closed either through local override switches or---as a last resort---manually. 
In case of sudden inclement weather, be very cautious and start closing early.

.. warning::
    If you are dealing with a dome shutter emergency shutdown. 
    Proceed calmly to keep the equipment safe. 
    Please use the standard safety measures when visiting the dome enclosure. **Safety of personnel always comes first.**

.. _AuxTel-Emergency-Shutdown-Shutter-Closure:

Shutter Closure
---------------
1. Before attempting to close the dome shutter, slew the dome so that it faces west using the 
   :file:`auxtel/atdome/slew_dome.py` script with the following configuration.

   .. code-block:: python
      :caption: :file:`auxtel/atdome/slew_dome.py`

      az: 270

   .. note:: 
      
      If the dome cannot slew remotely, continue with the rest of the procedure. 
      Local control of the dome azimuth drives will be located in :ref:`Step 4 <AuxTel-Emergency-Shutdown-Shutter-Closure-Step4>`.

2. | Verify if the AuxTel dome shutter can close through CSC control. If unable to close, 
   | **send ATDome CSC to** ``Standby`` before continuing the rest of this procedure.

3. Communicate on the *#summit-announce* channel that the observing crew 
   is going to attempt to close the AuxTel dome via the emergency procedure.

.. _AuxTel-Emergency-Shutdown-Shutter-Closure-Step4:

4. Go up to the AuxTel dome (second floor).  Locate the control box at the top of the stairs.  
   The top black button should close the shutter. **Press and hold** the button to close the dome shutter.
   
   .. note::
      The safety gate at the bottom of the stairs needs to be closed and locked 
      in order for this button to operate.

   .. admonition:: Slewing ATDome Locally
      :class: hint

      If slewing the dome remotely was unsuccessful (see Step 1 of procedure), 
      the same control box can rotate the dome using the Clockwise (CW) and 
      Counter-Clockwise (CCW) buttons on the bottom row. 
      
      To rotate the dome, press and hold one of the buttons until that the 
      dome shutter faces West (az = 270 deg). If local control does not work, 
      prioritize closing the shutter.

   .. figure:: /AuxTel/Non-Standard-Operations/_static/Box_at_Top_of_Stairs.png

     AuxTel Level 2 Control Box

5. If the above step fails (i.e., no movement after pressing for more than 5 seconds), 
   locate the AuxTel cRIO box. This box rotates with the AuxTel dome and opens/closes the shutter. 
   Attempt to close the shutter by **pressing and holding** the ``CLOSE`` button on the outside of the box 
   (see yellow arrow).

   .. figure:: /AuxTel/Non-Standard-Operations/_static/cRIO_box.png
     
     AuxTel Dome Shutter Control Box

6. If the above step fails (i.e., no movement after pressing for more than 5 seconds), open the box and identify the cRIO switches.
   **Press and hold** the white ridges on the switch labeled ``CLOSE`` (see yellow arrow). 
   

   .. admonition:: **Execute this step with EXTREME CAUTION!** 
      :class: warning
    
      This is a low-level control switch for the dome. There are **no limit switches** and **no fail-safes**. 

      It is best to *stop the shutter movement a few centimeters* before it is fully closed. 
      This prevents over-driving of the shutter, which could bang into the lower shutter or cause damage on the drive.


   .. figure:: /AuxTel/Non-Standard-Operations/_static/Switches_in_cRIO_box.png

     AuxTel cRIO Low-Level Control Switch

7. If none of these steps were successful, the safest course of action is the leave the dome in its current
   state and **contact AuxTel personnel** using the *#summit-auxtel* Slack channel. 
   They will address the issue the following morning.

   .. admonition:: (Optional) Manually Closing Shutter
      :class: note

      If observers feel comfortable attempting to manually close the shutter by hand, 
      they can follow the steps in :ref:`AuxTel-Emergency-Shutdown-Shutter-Closure-Without-Power`.
  
.. _AuxTel-Emergency-Shutdown-Shutter-Closure-Without-Power:

Shutter Closure without Power
-----------------------------

In the absence of electrical power, the shutter must be closed manually. 

1.  On AuxTel first (or sometimes second) floor, there is a hand crank that fits into a ring 
    at the top of the dome.

    .. note::
      
      The crank handle has a removable rotating grip may be loose or detached.
      To properly use it, secure the handle using a short rigid tool (e.g., one of the nearby Allen keys).

    .. figure:: /AuxTel/Non-Standard-Operations/_static/Hand_Crank.jpg
      :height: 400px
     
      AuxTel Hand Crank
    
2.  Connect the tip of the crank to the ring at the top of the dome.

    .. figure:: /AuxTel/Non-Standard-Operations/_static/Top_of_Dome.png
      :height: 400px
      
      Manual Close Ring (Top of Dome)

3.  Rotate the ring manually with the crank assistance to close the shutter. 

.. note:: 
  
  This is a long and physically demanding procedure as the hand crank does not have enough 
  torque to lift the weight of the shutter if it is all the way open. 
  
  If you cannot safely insert the crank into the drive motor and operate the crank, 
  then remove the crank and do not proceed. Instead, **inform AuxTel personnel** 
  so they can assist the following morning.


.. _AuxTel-Emergency-Shutdown-Contingency:

Contingency
===========
If the procedure was not successful, report the issue on the *#summit-auxtel* channel and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.


This procedure was last modified |today|.
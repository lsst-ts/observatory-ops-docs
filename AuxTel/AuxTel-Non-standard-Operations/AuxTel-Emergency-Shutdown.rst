.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Karla Peña Ramírez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *List-of-contributors*
.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Templates-Title-of-Procedure: "AuxTel-AuxTel-Non-standard-Operations"
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
###################
AT Emergency Shutdown
###################
.. note::
    This is a procedure template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.
.. _Title-of-Procedure-Overview:
Overview
========
.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.
Unfavorable circumstances that indicate the need to close the dome if it is open, or leave the dome closed if it is:
   - Weather inclemencies:
  
      - Humidity rising above 60 %
      - Condensation on any surfaces outside of the building
      - Precipitation
      - Snow
      - Wind speed > 15 m/s
      - Dust in the air or clouds
  
   - Sunrise approaching in the next two hours
   - Power outage affecting the dome shutter mechanism
 
.. _Title-of-Procedure-Precondition:
Precondition
============
.. This section should provide simple overview of preconditions before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).
The dome shutter is open and an unforeseeable condition arises, forcing an emergency dome aperture closure.
.. _Title-of-Procedure-Post-Condition:
Post-Condition
==============
.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.
- The emergency situation has been clearly notified to the relevant personnel and management.
- Steps to eliminate or minimize the risk to the instruments and hardware are being implemented.
- Eventually, the dome shutter is closed and all equipment is safe.
.. _Title-of-Procedure-Procedure-Steps:
Procedure Steps
===============
.. todo::
   Please use the standard safety measures when visiting the dome enclosure. **Safety of personnel always goes first.**
.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

In the event of an emergency dome closure, the dome shutter won't be able to be operated from the standard CSC controls. The ATDome would need to be closed manually. In case of sudden inclement weather, be very cautious and start closing early.
.. warning::
    If you are dealing with a dome shutter emergency shutdown. Proceed calmly  to keep the equipment safe. 
.. _Title-of-Procedure-Critical-Step-1:
1. Go up to the AuxTel dome.  Locate the control box at the top of the stairs.  The top black button should close the shutter: FIGURE
2. If this fails, locate the cRIO box, which rotates with the AuxTel dome.  It looks like this: FIGURE Inside this box is a series of switches. FIGURE
Sliding the switch labeled "CLOSE" to the left  (yellow arrow) should close the shutter.  This must be done with EXTREME CAUTION.  This is a low-level control switch and there are no limit switches or fail-safes.  You can easily over drive the shutter until it bangs into the lower shutter.  You can also damage the drive.  If you do this, it is best to stop the shutter 1 cm or so before it is fully sfddfdfdffdclosed to prevent this type of damage.
3. The steps above should close the shutter if there is power.  As a last resort, for example if power has been lost, the shutter can be closed manually.  There is a crank on the first floor which fits into a ring at the top of the dome (see pictures below).  With these you can close the shutter manually.  Note that this is a tedious procedure that might take hours. FIGURE
   .. _Title-of-Procedure-Final-Step:
4. Complete the procedure's final step.

.. _Title-of-Procedure-Condition-A-for-Step-4:
Condition A for Step 4
----------------------
This is an example of a sub-section, used when Condition A applied. Complete the steps in this section:
#. Step 1 for Condition A.
#. Return to :ref:`Step 5 <Title-of-Procedure-Final-Step>` in the section above.
.. _Title-of-Procedure-Condition-B-for-Step-4:
Condition B for Step 4
----------------------
This is an example of a sub-section, used when Condition B applied. Complete the steps in this section:
#. Step 1 for Condition B.
#. Return to :ref:`Step 5 <Title-of-Procedure-Final-Step>` in the section above.
.. _Title-of-Procedure-Troubleshooting:
Troubleshooting
===============
.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.
.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.
     No troubleshooting information is applicable to this procedure.
- This is an example bullet (If the following error is given during :ref:`Step 5 <Title-of-Procedure-Final-Step>`, resolve it using a specified action.)

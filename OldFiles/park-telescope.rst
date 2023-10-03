.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Yijung Kang*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Alysha Shugart, Karla Aubel*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AT-Shutdown-Park-the-Telescope:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##################
Park the Telescope
##################

.. .. note::
.. This is a procedure template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.

.. _Park-the-Telescope-Overview:

Overview
========

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

.. This is a template for a procedure. It is performed by authorized and trained users.

Parking the telescope can be done by ``auxtel/shutdown.py``. However, if the ``shutdown`` script is not working, you can slew the telescope manually via ScriptQueue, notebook, or button in the AuxTel. See more details on the :ref:`Shutdown procedure <AT-Shutdown-Shutdown>` section.

.. _Park-the-Telescope-Prerequisites:

Prerequisites
=============

Before parking the telescope, any scheduler or script should be stopped properly. 
If the scheduler needs to stop, run ``auxtel/scheduler/stop.py`` on the ScriptQueue.  

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

.. _Park-the-Telescope-Post-Conditions:

Post-Condition
==============

The parking position for 

- **AuxTel dome: az=285.0 deg.** 

  : After parking the dome, dome following also needs to be disabled.

- **Auxiliary Telescope: El = 80 deg, Az = 0.0 deg, rot = 0.0 deg.** 
  
  : Tracking should be stopped.

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.


.. .. image:: ./_static/ATDome_park.png
    :name: Auxiliary Telescope and Dome at the parking position

.. _Park-the-Telescope-Steps:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

.. _Park-the-Telescope-Troubleshooting:

Troubleshooting
===============

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

     No troubleshooting information is applicable to this procedure.

.. _Park-the-Telescope-Contact-Personnel:

Contact Personnel
=================

This procedure was last modified |today|.

This procedure was written by |Author|. The following are contributors: |contributors|.

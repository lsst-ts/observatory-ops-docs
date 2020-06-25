.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.

.. This is the label that can be used as for cross referencing in the given area
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens
.. _Template-Folder-Title-of-Procedure:

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Name-of-Primary-Author*
.. |contributors| replace:: *List-of-contributors*

##################
Title of Procedure
##################

.. note::
    This a procedure template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.

Overview
^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This is a template for a procedure. It is performed by authorized and trained users.

Prerequisites
^^^^^^^^^^^^^

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel."
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

- This is an example bullet of a prerequisite (Telescope azimuth must be at 0 degrees.)

    - This is an example describing an exception (If the dome is closed, telescope elevation position is not important.)

- This is another example bullet of a prerequisite (Notification to specified SLACK channel.)

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees."

- This is an example bullet of a post-condition (Telescope azimuth is 0 degrees.)
- This is another example of a post-condition (This procedure leaves the telescope with the E-stop activated.)

Procedure Steps
^^^^^^^^^^^^^^^

.. todo::
   Include utilization of admonishments (caution, warning, etc.)

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisitcated methodologies may be appropriate, such as mutliple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

This paragraph describes some general guidance for this procedure. This paragraph is optional depending on its usefulness and the complexity of the procedure.

In the case of a very straightforward procedure, a simple numbered list could be used, like as follows:

#. This is Step 1 in a numbered list.

#. This is step 2.

#. Step 3 has two branches, but Step 4 is independent of Step 3.

    a. If Condition A, do the following action in :ref:`Condition A for Step 3`.

    a. If Condition B, do the following action in :ref:`Condition B for Step 3`.

.. _Step 4:

#. Complete the procedure's final step.


.. _Condition A for Step 3:

Condition A for Step 3
----------------------

This is an example of a sub-section, used when Condition A applied. Complete the steps in this section:

#. Step 1 for Condition A.
#. Return to :ref:`Step 4 <Step 4>` in the section above.

.. _Condition B for Step 3:

Condition B for Step 3
----------------------

This is an example of a sub-section, used when Condition B applied. Complete the steps in this section:

#. Step 1 for Condition B.
#. Return to :ref:`Step 4 <Step 4>` in the section above.

Troubleshooting
^^^^^^^^^^^^^^^

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.
     No troubleshooting informatin is required for this procedure.

- This is an example bullet (If the following error is given during Step 2, resolve it using a specified action.

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

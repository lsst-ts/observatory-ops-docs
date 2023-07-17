.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Name-of-Primary-Author*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *List-of-contributors*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Templates-Title-of-Troubleshooting-Procedure:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##################################
Title of Troubleshooting Procedure
##################################

.. note::
    This is a procedure template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.

.. _Title-of-Troubleshooting-Procedure-Overview:

Overview
^^^^^^^^

.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

This is a template for a troubleshooting procedure. It is performed by authorized and trained users.

.. _Title-of-Troubleshooting-Procedure-Error-Diagnosis:

Error diagnosis
^^^^^^^^^^^^^^^

.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

- This is an example bullet.

.. _Title-of-Troubleshooting-Procedure-Procedure-Steps:

Procedure Steps
^^^^^^^^^^^^^^^

.. todo::
   Make sure everything is in a safe or idle state before troubleshooting. Describe relevant safety steps if necessary.

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

This paragraph describes some general guidance for this procedure. This paragraph is optional depending on its usefulness and the complexity of the procedure.

In the case of a very straightforward procedure, a simple numbered list could be used, like as follows:

.. warning::
    For this example, this step is critical.

.. _Title-of-Troubleshooting-Procedure-Critical-Step-1:

#. This is Step 1 in a enumerated list. It happens to be very important.

#. This is Step 2.

#. This is step 3.

#. Step 4 has two branches, but Step 5 is independent of Step 4.

   a. If Condition A, do the following action in :ref:`Condition A Instructions <Title-of-Troubleshooting-Procedure-Condition-A-for-Step-4>`.

   b. If Condition B, do the following action in :ref:`Condition B instructions <Title-of-Troubleshooting-Procedure-Condition-B-for-Step-4>`.

   .. _Title-of-Troubleshooting-Procedure-Final-Step:

#. Complete the procedure's final step.


.. _Title-of-Troubleshooting-Procedure-Condition-A-for-Step-4:

Condition A for Step 4
----------------------

This is an example of a sub-section, used when Condition A applied. Complete the steps in this section:

#. Step 1 for Condition A.
#. Return to :ref:`Step 5 <Title-of-Troubleshooting-Procedure-Final-Step>` in the section above.

.. _Title-of-Troubleshooting-Procedure-Condition-B-for-Step-4:

Condition B for Step 4
----------------------

This is an example of a sub-section, used when Condition B applied. Complete the steps in this section:

#. Step 1 for Condition B.
#. Return to :ref:`Step 5 <Title-of-Troubleshooting-Procedure-Final-Step>` in the section above.

.. _Title-of-Troubleshooting-Procedure-Post-Condition:

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- This is an example bullet of a post-condition (Telescope azimuth is 0 degrees.)
- This is another example of a post-condition (This procedure leaves the telescope with the E-stop activated.)

.. _Title-of-Troubleshooting-Procedure-Contingency:

Contingency
^^^^^^^^^^^

If the procedure was not successful, report the issue in [relevant Slack channel] and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.

.. _Title-of-Troubleshooting-Procedure-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

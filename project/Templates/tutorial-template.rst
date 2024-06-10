.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

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
.. _Templates-Title-of-Tutorial:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#################
Tutorial Template
#################

.. note::
    This is a tutorial template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.

.. Important::

    This template is under heavy development and only in the very early stages of design.
    It should not be used nor consulted for a place of information at this time.

.. _Title-of-Tutorial-Overview:

Overview
========

.. This section should provide a brief, top-level description of the tutorial's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This is a template for a tutorial.

.. _Title-of-Tutorial-Precondition:

Precondition
=============

.. This section should provide simple overview of Precondition for using the tutorial.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section.

This section should list the Precondition (e.g. required conditions) to perform the tutorial. If multiple sentences/conditions are required this should be presented in bullet form.

- This is an example bullet (e.g. should have accounts on system XYZ)

    - This is a sub-bullet (e.g. can test by logging into VPN XYZ)

.. _Title-of-Tutorial-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after using the tutorial.

This section describes the state of the system after performing the tutorial. If multiple sentences/conditions are required this should be presented in bullet form.

- This tutorial leaves the telescope in tracking mode.

    - Add Extra-guidance when required/useful. (e.g. can stop tracking using the following command)

.. _Title-of-Tutorial-Tutorial-Steps:

Tutorial Steps
==============

.. This section should include the tutorial steps.
.. In the case of more complicated tutorials, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked tutorials to be performed in the specified order.
.. For highly complicated tutorials, consider breaking them into separate tutorials. Some options are a high-level tutorial with links, separating into smaller tutorials or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

This paragraph describes for the format of the Tutorial. This is optional as the usefulness depends upon the complexity of the procedure.

In the case of a very straightforward tutorial, a simple numbered list could be used, like as follows:

#. This is Step in a numbered list
#. This is step two.

Separate into Subsections
-------------------------

In the case of more complicated tutorials, more sophisticated methodologies may be appropriate, such as using multiple section headings, then numbered lists under each heading.

.. _Title-of-Tutorial-Troubleshooting:

Troubleshooting
===============

.. This section should include troubleshooting information.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

     No troubleshooting information is applicable to this tutorial.
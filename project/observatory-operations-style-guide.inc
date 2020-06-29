.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Project-Observatory-Operations-Style-Guide:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. This file does not contain a title so it can match formatting in another location (contributing.rst).
.. title:: Observatory Operations Style Guide
.. ##################################
.. Observatory Operations Style Guide
.. ##################################

.. This section should provide a brief, top-level description of the page.

.. important::
    The information provided below is based on the `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__. A style guide specific to the procedure's arm of the documentation will be provided at a later time.

The information below can help you create effective reStructuredText for the `Rubin Observatory Operations Documentation <https://obs-ops.lsst.io>`__.

.. _Observatory-Operations-Style-Guide-Style-and-Voice:

Style and Voice
---------------

This is user documentation, which is different from academic writing.
Here are some tips:

- Make sure that all of your writing is in the service of users.

- Write with the active voice and in the present tense as much as possible.

- Address the user directly (“you can…”).
  Never use “we” since that’s ambiguous.
  If “we” means “Rubin Observatory,” then name “Rubin Observatory.”
  If “we” means the user, then say “you.”
  Even in tutorials, don’t use “we” to refer to an imaginary writer assisting the user.

- Write simple, short sentences in short paragraphs.
  Chunk information with headers.

- Write confidently and precisely, yet also casually.

For further discussion about specific style issues, refer to the `Google Developer Documentation Style Guide <https://developers.google.com/style/>`_.

.. _Observatory-Operations-Style-Guide-File-Names:

File Names
----------

Always use hyphens to separate words in file names.
Do not use underscores or spaces.

.. _Observatory-Operations-Style-Guide-Templates:

Templates
---------

A template folder is located in the :ref:`project directory <Project-Information>`.
It contains template pages for the Observatory Operations Documentation area, including a directory index and a procedure template.
Review the README in the template folder for instructions, then update the contents accordingly.

.. _Observatory-Operations-Style-Guide-Titles-and-Headings:

Titles and Headings
-------------------

Title case for headings is recommended.

Try not to use more than two levels of heading hierarchy.
Using more than two levels of hierarchy might suggest an information architecture issue.

Also keep in mind DM’s `reStructuredText heading styles <https://developer.lsst.io/restructuredtext/style.html#sections>`__.

.. _Observatory-Operations-Style-Guide-Links:

Links
-----

Never use "here" as link text.
Instead, make the relevant noun or phrase the link.

.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Simonyi-Telescope-Operations:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##############################
Simonyi Telescope Operations
##############################

.. admonition:: Simonyi Important Announcements

    Place here all important Simonyi Telescope news and announcements. 
    If note text runs over a line, make sure the lines wrap and are indented to
    the same level as the note tag. If formatting is incorrect, part of the note
    might not render.
    
    Notes can have more than one paragraph. Successive paragraphs must
    indent to the same level as the rest of the note.

.. This section should provide a brief, top-level description of the page.

.. _Simonyi-Telescope-Operations-Components:

Introduction to the Simonyi Telescope
=====================================

.. toctree::
   :glob:
   :titlesonly:
   :caption: Components

   Components/MTCS/index.rst
   Components/*
   Components/Auxiliary-Components/index.rst

.. _Simonyi-Telescope-Weather-Constraints:

Weather Constraints
===================

Consult the :ref:`weather conditions and constraints <Observing-Constraints-Simonyi-Weather-Constraints>` to operate Simonyi before deciding to open. 

.. toctree::
   :glob:
   :titlesonly:
   :caption: Weather Constraints
   
   ../Observing-Constraints/Simonyi/index.rst


.. _Simonyi-Telescope-Operations-Standard-Operations:

Operations
===================

.. toctree::
   :glob:
   :titlesonly:
   :caption: Standard Operations

   Standard-Operations/index.rst

.. _Simonyi-Telescope-Operations-Non-standard-Operations:


.. Non-standard Operations
.. =======================

.. toctree::
    :glob:
    :maxdepth: 5 
    :titlesonly:
    :caption: Non-Standard Operations


    Non-Standard-Operations/index.rst

.. _Simonyi-Telescope-Operations-Troubleshooting:

.. Troubleshooting
.. ===============

Most common troubleshooting procedures with associated faults. 

.. toctree::
    :glob:
    :maxdepth: 5 
    :titlesonly:
    :caption: Troubleshooting


    Troubleshooting/index.rst



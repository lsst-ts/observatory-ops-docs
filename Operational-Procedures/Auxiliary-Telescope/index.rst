.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Auxiliary-Telescope-Procedures:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##############################
Auxiliary Telescope Procedures
##############################

.. This section should provide a brief, top-level description of the page.

.. note::
    This is a template file that is associated with a template directory structure. This note should be deleted when the section is properly populated

Procedures are divided into multiple categories based on the affected hardware and user's application.

.. What is the best way to arrange this? Arrange by systems, then by use-case? Or arrange by use-case, then by system?

.. _Auxiliary-Telescope-Procedures-Standard-Support-Operations:

Standard Support Operations
===========================

These procedures are part of observatory activities that do not include on-sky observations of astronomical targets; for example, opening the mirror cover.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    Support-Operations/*

    LATISS-Master-Calibrations-Procedure/*

    Enable-LATISS-Procedure/*

    Enable-OCPS-Auxiliary-Telescope-Procedure/*

    Prepare-ATCS-For-Flat-Fields-Procedure/*

..  Opening-Dome?

.. _Auxiliary-Telescope-Procedures-On-Sky-Operations:

On-sky Operations
=================

These procedures part of regular on-sky observations activities of astronomical targets, such as slewing the telescope and tracking the target.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    Full-Observatory/*

.. _Auxiliary-Telescope-Procedures-Maintenance-Operations:

Maintenance Operations
======================

Content for this section is under development.

.. _Auxiliary-Telescope-Procedures-Troubleshooting:

Troubleshooting
===============

.. toctree::
    :maxdepth: 1

    Troubleshooting/E-stop

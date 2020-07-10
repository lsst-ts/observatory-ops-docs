.. This is a template .rst file for a directory in the procedure's arm of the documentation. This template should be used for the directory's index.rst, and may be used to generate other pages within the directory. This comment may be deleted when the template folder is copied to the destination.

.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. image:: _static/Sunset_cropped_resampled_16x9.jpg
   :width: 250px
   :align: right

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Obs-Ops-Rubin-Observatory-Operations-Documentation:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##########################################
Rubin Observatory Operations Documentation
##########################################

.. This section should provide a brief, top-level description of the page.

.. Important::

    This documentation area is under heavy development and only in the very early stages of design.
    It should not be used nor consulted for a place of information at this time.

Observatory Operations consists of multiple levels of :ref:`interactions <Obs-Ops-Daytime-Nighttime-Interactions>` and :doc:`procedures </procedures/index>` occurring simultaneously in many places and timezones.
There are also :doc:`tutorials for the observatory </tutorials/index>`.
This section of documentation focuses on the resources needed for observers, commissioning personnel, and support staff to facilitate :doc:`night-time operations </procedures/operations/index>`.
This site also provides information for :doc:`safety reference </safety>`.

The scope of this area of documentation is to provide a centralized, version controlled space where resources are either located, or linked appropriately.
The content is provided as reference only.
All aspects of the project that go through strict change control (e.g. mirror procedures) should only be linked to these pages.

:doc:`Get started </interfaces/index>` or :doc:`learn how to contribute </project/index>`.

.. _Obs-Ops-Daytime-Nighttime-Interactions:

Daytime/Nighttime Interactions
==============================

This area contains information related to summit operations, specifically nighttime activities and the handoff to/from daytime personnel

- This also includes the mechanism to facilitate daytime work by the night crew (e.g. diagnose a re-occurring fault)
- Nightlog instructions


.. toctree::
    :maxdepth: 2
    :glob:
    :titlesonly:
    :hidden:

    interfaces/index
    procedures/index
    project/index
    auxiliary-telescope/index
    main-telescope/index
    tutorials/index


.. toctree::
    :glob:
    :hidden:

    *

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

Observatory Operations consists of multiple levels of interactions and procedures occurring simultaneously in many places and timezones.
This section of documentation focuses on the resources needed for observers, commissioning personnel, and support staff to facilitate night-time operations.

The scope of this area of documentation is to provide a centralized, version controlled space where resources are either located, or linked appropriately.
The content is provided as reference only.
All aspects of the project that go through strict change control (e.g. mirror procedures) should only be linked to these pages.

.. _Obs-Ops-Safety:

Safety
======

Content in this section relates to personnel safety and resources.
This includes:

- procedures on who (and how) to call when there is an issue
- location of keys, passwords etc
- what to do in case of vehicle failure, power-outage, fire etc.
- Procedures to enter telescope spaces during operations (e.g. AuxTel)
- Emergency meeting locations etc.

.. toctree::
   :glob:
   :titlesonly:
   :maxdepth: 2
   
   Safety/index


.. _Obs-Ops-Daytime-Operations:

Daytime Operations
======================

.. toctree::
    :glob: 
    :titlesonly:
    :maxdepth: 4

    Daytime-Operations/index


.. _Obs-Ops-Daytime-Nighttime-Interactions:

Daytime/Nighttime Interactions
==============================

This area contains information related to the summit operations and the handoff to/from daytime personnel

.. toctree::
   :maxdepth: 2
   :glob:
   :titlesonly:

   Daytime-Nighttime-Interactions/index


.. _Obs-Ops-NightTime-Operations:

Nighttime Operations
======================

.. toctree::
    :maxdepth: 4
    :glob:
    :titlesonly:

    Nighttime-Operations/index

.. _Obs-Ops-Troubleshooting:

Troubleshooting
======================

All related to troubleshooting is included in this section. 

.. toctree::
    :maxdepth: 4
    :glob:
    :titlesonly:
    
    Troubleshooting/index
 

.. _Obs-Ops-Project-Documentation-Information:

Project Documentation Information
=================================

Describes information regarding this documentation tree, including how to contribute.

.. toctree::
    :maxdepth: 2
    :glob:
    :titlesonly:

    project/index


.. _Obs-Ops-Observing-Interface-Setup:

Observing Interface Setup
==================================

Contains detailed instructions on how to set the required environment for operations and/or interaction with the system during testing and commissioning. 

.. toctree::
    :maxdepth: 2
    :glob:
    :titlesonly:

    Observing-Interface-Setup/index


.. _Obs-Ops-Operational-Procedures-Tutorials:

Operational Procedures - System testing, deployment and upgrade
==================================================================

Procedures for system testing, software build, deployment and upgrades at the summit and at TTS are compiled here (To eventually be displayed under https://obs-controls.lsst.io/)

.. toctree::
    :maxdepth: 2
    :glob:
    :titlesonly:

    Operational-Procedures-Tutorials/index
.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. Observatory-Control-System-Observatory-Control-System:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##############################
Observatory Control System
##############################
.. Place below all important observatory news and announcements. 
    If note text runs over a line, make sure the lines wrap and are indented to
    the same level as the note tag. If formatting is incorrect, part of the note
    might not render.
    
    Notes can have more than one paragraph. Successive paragraphs must
    indent to the same level as the rest of the note.

.. admonition:: Observatory-Wide Important Announcements
   
   This page is under construction. 

.. _Observatory-Control-System-Control-and-Monitoring: 

Control and Monitoring Software
===============================
.. toctree::
   :glob:
   :titlesonly:
   :caption: Control and Monitoring Software

   Control-and-Monitoring/index.rst

.. _Observatory-Control-System-EAS:

Environmental Awareness System - EAS
=======================================

.. toctree::
   :glob:
   :titlesonly:
   :caption: Environmental Awareness System - EAS


   EAS/index.rst

.. _Observatory-Control-System-Combined-Calibrations-Procedures:


Combined calibrations Procedures
================================

.. toctree::
   :glob:
   :maxdepth: 3
   :titlesonly:
   :caption: Calibration Procedures

   Calibrations/introduction-combined-calibrations-index.rst

.. _Observatory-Control-System-Non-standard-Operations:

Observatory Control System Non-standard Operations
==================================================

Manual interventions and unique protocols that apply to the observatory control system, such as summit devices shutdown procedures, are encapsulated 
here. 

.. toctree::
   :glob:
   :maxdepth: 2
   :titlesonly:
   :caption:  Non-standard Operations 
   
   Non-standard-Operations/index.rst



Troubleshooting
===========================================


.. toctree::
   :glob:
   :maxdepth: 2
   :titlesonly:
   :caption: Observatory Troubleshooting
   
   Troubleshooting/index.rst
.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Observatory-Troubleshooting-index:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. ###########################################
.. Observatory Control System Troubleshooting
.. ###########################################

###########################################
Known Faults
###########################################

.. This section should provide a brief, top-level description of the page.
.. list-table:: Known Faults
   :widths: 10 50 20 40  
   :header-rows: 1 

   * - CSC
     - Issue/Diagnosis
     - Happens mostly when
     - Troubleshooting procedure
   * - Row 1, column 1
     -
     - Row 1, column 3
     - Row 1, column 4
   * - Row 2, column 1
     - Row 2, column 2
     - Row 2, column 3
     - 

Per component
=============

.. toctree::
   :glob:
   :titlesonly:

   troubleshooting-the-scheduling-algorithm/troubleshooting-the-scheduling-algorithm-index.rst


.. toctree::
   :glob:
   :maxdepth: 3

   CSCs-Troubleshooting/index.rst


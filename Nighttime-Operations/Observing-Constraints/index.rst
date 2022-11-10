.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _NighttimeObserving-Constraints-Weather-Constraints:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.


#######################
Weather Constraints
#######################

.. This section should provide a brief, top-level description of the page.

This page defines the different types of operational constraints.

Operating conditions used to define the Rubin construction project are found in `LTS-54 <https://ls.st/lts-54>`__. 

As commissioning gets underway the operating conditions will be better constrained and different situations will apply to the Main telescope and Auxiliary Telescope.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

..    *

.. _Weather-Constraints-Unrestricted-Operating-Conditions:

Unrestricted Operating Conditions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Winds less than X km/h

.. _Weather-Constraints-Restricted-Observing-Conditions:

Restricted Observing Conditions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Winds greater than X km/h
Relative humidity greater than X%
Dust count?

.. _Weather-Constraints-Vent-Gate-Configurations:

Vent Gate Configurations
------------------------

Operations must be at elevations> Y degrees.

.. _Weather-Constraints-Moon-Avoidance:

Moon Avoidance
^^^^^^^^^^^^^^

Avoid the moon since it may damage the telescope.
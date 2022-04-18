.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Simulation-Environments:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#######################
Simulation Environments
#######################

.. This section should provide a brief, top-level description of the page.

The Vera C. Rubin Observatory uses two separate simulation environments.
The first environment, the Tucson Test Stand (TTS), is used to perform end-to-end integration testing of software, but can also be used to train new personnel, or to diagnose issues that may have occurred on the summit system.
The TTS is meant to be as identical as possible to the summit environment, and includes it's own Nublado instance, EFD, LFA, etc.
The second environment is the Base Test Stand, located in La Serena.
Although it is yet to be brought online, it will offer much of the same functionality as the TTS, but will include specialized hardware simulators for numerous components.

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :glob:

    */index


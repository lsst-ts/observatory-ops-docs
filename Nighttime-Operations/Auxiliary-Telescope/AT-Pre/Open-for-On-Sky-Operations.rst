.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Tiago Ribeiro*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Patrick Ingraham*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AT-Pre-Open-for-On-Sky-Operations:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

############################
Open for On-Sky Observations
############################

.. note::

    Content here is largely presented for the sake of example. This will require an update once more content is merged.

.. _Open-for-On-Sky-Operations-Overview:

Overview
^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This procedure takes the telescope from the nominal state of how it was (most likely) left at the end of the day, to getting the telescope fully open and ready to take observations. This includes things like enabling all components, opening the dome, mirror covers etc.

.. _Open-for-On-Sky-Operations-Prerequisites:

Prerequisites
^^^^^^^^^^^^^

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

- Assumes observatory is fully ready to operate, as would be the case if it was shutdown the night before using the shutdown procedure.

- Before taking the decision to open, review the weather conditions and :ref:`weather constraints <Nighttime-Operations-Weather-Constraints>` page.

.. _Open-for-On-Sky-Operations-Post-Condition:

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- Telescope will be left read to observe.

- It is recommended to try slewing and taking an image to ensure all functionality is operational. Because the telescope and dome is positioned optimally away from the sun, only a very small (~3 degree) slew in azimuth should be performed.

.. _Open-for-On-Sky-Operations-Procedure-Steps:

Procedure Steps
^^^^^^^^^^^^^^^

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

This paragraph describes some general guidance for this procedure. This paragraph is optional depending on its usefulness and the complexity of the procedure.

.. _Open-for-On-Sky-Operations-Open-Using-scriptQueue:

Open Using scriptQueue
----------------------

Running this procedure via the scriptQueue is not currently implemented.

.. _Open-for-On-Sky-Operations-Open-Using-Example-Notebook:

Open Using Example Notebook
---------------------------

At the end of the day, before observations starts, most telescope-related CSCs will be unconfigured and in ``STANDBY`` state. The first step in starting up the system is to enable all CSCs. Putting a CSC in the ``ENABLED`` state requires the transition from ``STANDBY`` to ``DISABLED`` and then from ``DISABLED`` to ``ENABLED``. When transitioning from ``STANDBY`` to ``DISABLED`` it is possible to provide a ``settingsToApply`` that selects a configuration for the CSC. Some CSCs won't need any settings while others will. It is possible to check what are the available settings by looking at the ``settingVersions`` event in the EFD, using Chronograf. Alternatively, it is also possible to let the high level control scripts to decide which configuration to use. In most cases, when performing regular operations, the auto-selection algorithm should be used.

To get started with it, make sure to open jupyter lab, navigate to the ``ts_notebooks`` folder nad create a  directory with your username in that repository (e.g. ``tribeiro`` or ``pingraham``). Then, navigate inside the newly created  directory and create sub-directories as you see fit to keep the notebooks organized. Once you are happy with the location you selected for the nights operation start a clean notebook and enter the following to import the basic libraries.

.. code-block:: python

    import asyncio

    from lsst.ts import salobj

    from lsst.ts.standardscripts.auxtel.atcs import ATTCS
    from lsst.ts.standardscripts.auxtel.latiss import LATISS

In the above, ``salobj`` is the high-level library that we use for basic
communication on component base. The following classes, ``ATCS`` and ``LATISS``
are developed using ``salobj`` to enable high-level operations combining multiple
components.

It is possible now to use those classes to operate with the components. To enable
them run;

.. code-block:: python

    domain = salobj.Domain()
    attcs = ATCS(domain)
    latiss = LATISS(domain)

    await asyncio.gather(atcs.start_task, latiss.start_task)

    await attcs.enable()

    await latiss.enable()

In case you want to enable the components with custom settings, it is possible to
pass them as a dictionary, e.g.;

.. code-block:: python

    await attcs.enable(settings={
                    'ataos': "current",
                    'atmcs': "",
                    'atptg': "",
                    'atpneumatics': "",
                    'athexapod': "current",
                    'atdome': "test.yaml",
                    'atdometrajectory': ""})


.. note::
    At this point one may want to setup for afternoon calibrations. This is outlined in procedure XYZ.

.. code-block:: python

    await attcs.startup()

It is safe to run this method with the telescope in most states. The task
will make sure to verify that all CSCs are in their proper state, will close the mirror
covers before opening the dome and then proceed to open the dome and so on.

.. _Open-for-On-Sky-Operations-Troubleshooting:

Troubleshooting
^^^^^^^^^^^^^^^

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

     No troubleshooting information is applicable to this procedure.

- Dome won't open due to cRIO communication error ``INSERT LINK``

.. _Open-for-On-Sky-Operations-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

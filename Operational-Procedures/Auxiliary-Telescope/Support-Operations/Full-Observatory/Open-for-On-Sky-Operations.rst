.. This is the label that can be used as for cross referencing in the given area
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hypens

.. _Full-Observatory-Open-for-On-Sky-Operations:

###########################
Open on On-Sky Observations
###########################

.. note::

    Content here is largely presented for the sake of example. This will require an update once more content is merged.


Overview
^^^^^^^^
This procedure takes the telescope from the nominal state of how it was (most likely) left at the end of the day, to getting the telescope fully open and ready to take observations. This includes things like enabling all components, opening the dome, mirror covers etc.

Open using scriptQueue
^^^^^^^^^^^^^^^^^^^^^^
TBR.

Open using example Notebook
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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


.. TODO ::

    - Link to example notebook


Troubleshooting for this Procedure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Address things here that are specific *only* to this procedure

    - Links to other applicable troubleshooting activities (hosted elsewhere)

        - Dome won't open due to cRIO communication error *INSERT LINK*
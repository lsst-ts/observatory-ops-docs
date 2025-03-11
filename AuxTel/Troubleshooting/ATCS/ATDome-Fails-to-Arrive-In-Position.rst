.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Erik Dennihy*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Gonzalo Aravena, Ioana Sotuela, Kris Mortensen*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _ATDome-Position-Failure:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##################################
ATDome Fails to Arrive in Position
##################################

.. _ATDome-Position-Failure-Overview:

Overview
========

When slewing to a new target the Dome stops tracking and fails to arrive to its final position, 
resulting in script failure (if the slew was triggered from a script) and the ATPtg CSC going into 
fault. The ATPtg can be recovered by performing a state cycle on LOVE, but the dome following must 
also be cycled independently to recover dome tracking. 

.. _ATDome-Position-Failure-Diagnosis:

Error diagnosis
===============

If the slew was initiated from a script, you may see an error traceback similar to the one below. 
This is triggered by the timeout that is expected when the ATDome never arrives to its final position.

.. dropdown:: ATDome Traceback: RuntimeError

    .. code-block:: python

        Traceback (most recent call last):
        File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/base_script.py", line 603, in do_run
            await self._run_task
        File "/net/obs-env/auto_base_packages/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_base_align.py", line 882, in run
            await self.arun(True)
        File "/net/obs-env/auto_base_packages/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_base_align.py", line 728, in arun
            await self._slew_to_target(checkpoint)
        File "/net/obs-env/auto_base_packages/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_base_align.py", line 642, in _slew_to_target
            await self.atcs.slew_object(
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 438, in slew_object
            return await self.slew_icrs(
                ^^^^^^^^^^^^^^^^^^^^^
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 655, in slew_icrs
            raise slew_exception
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 615, in slew_icrs
            await self.slew(
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 803, in slew
            await self._slew_to(
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1440, in _slew_to
            await self.process_as_completed(self.scheduled_coro)
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/remote_group.py", line 1176, in process_as_completed
            raise e
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/remote_group.py", line 1173, in process_as_completed
            ret_val = await res
                    ^^^^^^^^^
        File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/asyncio/tasks.py", line 605, in _wait_for_one
            return f.result()  # May raise f.exception().
                ^^^^^^^^^^
        File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1657, in wait_for_inposition
            raise RuntimeError(error_message)
        RuntimeError: Dome timed out getting in position.    

Another possible error is that you see ATDome is not moving while 
the other components have already arrived in position.

.. dropdown:: ATDome Traceback: TimeOutError

    .. code-block:: python

        Traceback (most recent call last):
        File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-5.1.0/lib/python3.10/site-packages/lsst/ts/salobj/base_script.py", line 603, in do_run
            await self._run_task
        File "/home/saluser/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_acquire_and_take_sequence.py", line 747, in run
            await self.arun(checkpoint=True)
        File "/home/saluser/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_acquire_and_take_sequence.py", line 731, in arun
            await self.latiss_acquire()
        File "/home/saluser/ts_externalscripts/python/lsst/ts/externalscripts/auxtel/latiss_acquire_and_take_sequence.py", line 484, in latiss_acquire
            tmp, data = await asyncio.gather(
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 659, in slew_icrs
            raise slew_exception
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 619, in slew_icrs
            await self.slew(
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 807, in slew
            await self._slew_to(
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1447, in _slew_to
            await self.process_as_completed(self.scheduled_coro)
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/remote_group.py", line 1173, in process_as_completed
            raise e
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/remote_group.py", line 1170, in process_as_completed
            ret_val = await res
        File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-5.1.0/lib/python3.10/asyncio/tasks.py", line 571, in _wait_for_one
            return f.result()  # May raise f.exception().
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1630, in wait_for_inposition
            status = await asyncio.gather(*tasks)
        File "/home/saluser/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1696, in wait_for_atdome_inposition
            await asyncio.wait_for(self.dome_az_in_position.wait(), timeout=timeout)
        File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-5.1.0/lib/python3.10/asyncio/tasks.py", line 458, in wait_for
            raise exceptions.TimeoutError() from exc
        asyncio.exceptions.TimeoutError

.. _ATDome-Position-Failure-Procedure-Steps:

Procedure Steps
===============

1. State cycle ATDome through ``STANDBY`` and back to ``ENABLE`` from the ASummaryState. 
   The transition must **be quick enough** so the dome shutter doesn´t start closing and the recovery 
   is faster; if it does close, the next step should deal with the shutter opening again.

   * If ATPtg faulted, transition it back to enabled from ASummaryState.

.. _ATDome-Position-LOVE-State-Cycle: 

.. mermaid::

    ---
    title: State Cycle Steps
    ---
    flowchart LR
        FA(FAULT) -->|"**standby**"| ST(STANDBY) -->|"**start**"| DI(DISABLED) -->|"**enable**"| EN(ENABLED)
            style FA fill:#DF5600,stroke-width:4px,stroke:#404141
            style ST fill:#EEE201,stroke-width:4px,stroke:#404141
            style DI fill:#758C98,stroke-width:4px,stroke:#404141
            style EN fill:#33A370,stroke-width:4px,stroke:#404141

.. note::

    One can alternatively state cycle ATDome using the ``set_summary_state.py``
    scripts found in the :ref:`Common AuxTel Scripts <Common-LOVE-SAL-Scripts-and-Configurations>` page.

2. After state cycling ATDome CSC, there are two options to choose depending on the state of the dome:
    
   a. If the dome remained **open**, run ``auxtel/atdome/enable_dome_following.py`` and move it to the 
      beginning of ATQueue. This is a faster recovery process, and is recommended given the current state of the dome.

   b. If the dome **closed**, run ``auxtel/prepare_for/onsky.py`` and move it to the beginning of the ATQueue. 
      This script will make sure the system is back and ready for observations, 
      with the mirror cover and dome shutter opened as well as the dome following enabled.

3. Keep ATQueue running to the next target. Confirm in LOVE that the dome is moving and following the mount.

Post-Condition
==============

- ATPtg is re-enabled.
- ATDome is tracking properly and arrives at its intended positions.
- AuxTel resumed running the night-time scheduler.

.. _ATDome-Position-Failure-Contingency:

Contingency
===========

.. _#summit-auxtel: https://rubin-obs.slack.com/archives/C07Q45NUK4P

If the procedure was not successful, report the issue in `#summit-auxtel`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
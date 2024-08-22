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
.. |contributors| replace:: *Ioana Sotuela, Gonzalo Aravenas*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Dome-Fails-to-Arrive-in-Position:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#######################################
AuxTel Dome Fails to Arrive in Position
#######################################


.. _AuxTel-Dome-Fails-to-Arrive-in-Position-Overview:

Overview
========

When slewing to a new target the Dome stops tracking and fails to arrive its final position, resulting in script failure (if the slew was triggered from a script) and the ATPtg CSC going into ``FAULT``. 
The ATPtg can be recovered by performing a state cycle on LOVE, but the Dome following must also be cycled independently to recover dome tracking. 


.. _AuxTel-Dome-Fails-to-Arrive-in-Position-Error-Diagnosis:

Error Diagnosis
===============

If the slew was initiated from a script, you may see an error traceback similar to the one below. This is triggered by the timeout that is excepted when the ATDome never arrives to its final position.

If the slew was not initiated from a script, you may instead see that the ATDome is not moving while the other components have already arrived in position.


.. code-block:: text
  :caption: ATDome Fails to Arrive in Position Error Message traceback


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


or

.. code-block:: text
  :caption: ATDome Fails to Arrive in Position Error Message traceback


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



.. _AuxTel-Dome-Fails-to-Arrive-in-Position-Procedure-Steps:

Procedure Steps
===============

Initially, ATDome tracking and positioning can be recovered directly from LOVE. 
If this fails, you can use a notebook to issue commands and recover the ATDome position. 
All necessary commands can be found in the daytime_checkout notebook.


A. **Procedure - Recovery from LOVE.**

   1. State cycle ATDome through ``STANDBY`` and back to ``ENABLE`` from the ASummaryState. 
      The transition must be quick enough so the dome shutter does not start closing and the recovery is faster; 
      if it does close, the next step should deal with the shutter opening again.  
      ``FAULT`` → ``STANDBY`` → ``START`` → ``DISABLE`` → ``ENABLE``.
   
      a. If ATPtg faulted, transition it back to ``ENABLE`` from ASummaryState LOVE view. 

   2. With the mirror cover and dome shutter opened, and the dome tracking enabled, first select auxtel/prepare_for/onsky from the script list. 
      Then, move it to the beginning of the ATQueue and execute the script.

   3. Keep ATQueue running to the next target. 
      Confirm from LOVE that the dome is moving and following the mount.



B. **Alternative procedure. Recovery from a notebook.**

.. note:: 
  This procedure may be deprecated due to changes in the operating system, as notebooks are no longer used to command the telescope.


1. If the LOVE recovery fails (Procedure A), from the ASummaryState, transition the ATPtg back to ``ENABLE`` state following the usual path: ``FAULT`` → ``STANDBY`` → ``START`` → ``DISABLED`` → ``ENABLED``

2. Using an instantiated atcs class from a notebook (e.g. the daytime_checkout notebook), ensure that dome following is disabled and perform a dome slew (using a value for az that is at least 15 degrees away from where you are currently pointing) before reactivating `dome_following` by running the following commands:


   .. prompt:: bash

     await atcs.disable_dome_following()
     dome_az = await atcs.rem.atdome.tel_position.next(flush=True,timeout=10)
     await atcs.slew_dome_to(az=dome_az.azimuthPosition+15)
     await atcs.slew_dome_to(az=dome_az.azimuthPosition-15)
     await atcs.enable_dome_following()



3. The dome following and positioning should now be recovered. 
   From the same notebook, perform a test slew choosing *az*, *el*, and *rot* values that are near your current position to ensure the dome tracks and arrives in the desired position.


   .. prompt:: bash

     current_position = atcs.rem.atptg.tel_mountPositions.get()
     start_az = current_position.azimuthCalculatedAngle[0]
     start_el = current_position.elevationCalculatedAngle[0]
     coord=atcs.radec_from_azel(az=start_az+10, el=start_el-10)
     await atcs.slew_icrs(coord.ra, coord.dec, rot=start_rot, stop_before_slew=False, rot_type=RotType.PhysicalSky)


**Additional Information/Details.**

The default timeout value for a slew triggered from a notebook is very long, so it may not be feasible to wait for it to timeout and you should instead interrupt the execution of the cell using the stop. 



.. _AuxTel-Dome-Fails-to-Arrive-in-Position-Error-Post-Condition:

Post-Condition
==============

- The ATDome is correctly tracking and positioned, following the telescope mount as expected.
  
- The ATPtg CSC is in the ENABLE state.
  
- The mirror cover and dome shutter are open, and dome tracking is enabled.


.. _AuxTel-Dome-Fails-to-Arrive-in-Position-Error-Contingency:

Contingency
===========

If these procedures wwere not successful, report the issue in `#summit-auxtel <https://lsstc.slack.com/archives/C01K4M6R4AH>`_ and/or check the :ref:`Out of hours support <Safety-out-of-hours-support>`.


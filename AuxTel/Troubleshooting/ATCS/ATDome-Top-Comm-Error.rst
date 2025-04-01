.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Ioana Sotuela, Kris Mortensen*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Jacqueline Seron, Erik Dennihy, Manuel Gomez*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Top-Comm-Error-Procedure:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##########################################
ATDome Lost Communication with the Top-End
##########################################

.. _Top-Comm-Error-Overview:

Overview
========

When running a script that commands the dome shutter (e.g., ``prepare_for/vent`` , ``prepare_for/onsky``  or ``auxtel/shutdown``), 
the script fails, showing a failure to communicate with the dome top-end where the shutter control resides. 

.. _Top-Comm-Error-Error-Diagnosis:

Error diagnosis
===============

When the command to the shutter is run within the script, an error is received in LOVE, showing a communication error:

.. code-block:: bash

    ack=<SalRetCode.CMD_FAILED: -302>

    result="Failed: Command SC returned 1 lines instead of 0; read: ' Top Comm Error\\r

Or the full traceback may be displayed as follows:

.. code-block:: python
    :linenos:

    2023/06/29 23:13:03 TAI
    Error in run
    Traceback (most recent call last):
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/base_script.py", line 603, in do_run
    await self._run_task
    File "/net/obs-env/auto_base_packages/ts_standardscripts/python/lsst/ts/standardscripts/auxtel/shutdown.py", line 62, in run
    await self.attcs.shutdown()
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 738, in shutdown
    raise e
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 732, in shutdown
    await self.close_dome()
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 946, in close_dome
    await self.rem.atdome.cmd_closeShutter.set_start(
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/topics/remote_command.py", line 416, in set_start
    return await self.start(timeout=timeout, wait_done=wait_done)
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/topics/remote_command.py", line 487, in start
    return await cmd_info.next_ackcmd(timeout=timeout)
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/topics/remote_command.py", line 191, in next_ackcmd
    raise base.AckError(msg="Command failed", ackcmd=ackcmd)
    lsst.ts.salobj.base.AckError: msg='Command failed', ackcmd=(ackcmd private_seqNum=71336703, ack=<SalRetCode.CMD_FAILED: -302>, error=1, 
    result="Failed: Command SC returned 1 lines instead of 0; read: ' Top Comm Error\\r n>'")


.. _Top-Comm-Error-Procedure-Steps:

Procedure Steps
===============


This is a hardware issue related to a loss in communication between the two cRIOs that are used to control the dome:

* The *Top Box cRIO*, which sits on the rotating part of the dome on the second floor. 
* The *Main Control Box*, which is on the first floor near the ventilation fan.

This issue can occur after an incorrect power sequence or a network communication loss.

To manually reset the dome cRIOs:

1. Check that the ATDome CSC is in the ``STANDBY`` state.
2. Access the Main and Top Box GUIs in any browser using the following link: **http://139.229.170.190/**. You must be within Rubin facilities (or have VPN access) to connect to the GUIs.
3. Head to AuxTel and reset the cRIOs manually using the `ATDome Recovery <https://obs-ops.lsst.io/AuxTel/Non-Standard-Operations/Recovery-after-Shutdown/Recovery-after-Shutdown.html#atdome-recovery>`_ 
   procedures on the :ref:`AuxTel Recovery after Shutdown <AuxTel-Non-Standard-Operations-AuxTel-Recovery-after-Shutdown>` page.

.. note::

    Make sure you have a small, pointed object (e.g., a paper clip or pen cap) to press the reset button on the cRIOs.


4. After the cRIOs are rebooted, confirm there is connectivity with the shutter and dome by verifying that the GUIs are operational. 
   If the GUIs do not come up on their own after 10 minutes, then a second reboot of the cRIOs is necessary.
5. Once the GUIs come back online, place the ATDome CSC back into the ``ENABLED`` state.

Post-Condition
==============

- Communication is back online and scripts that command the dome shutter will work without issue.

.. _Top-Comm-Error-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in `#summit-auxtel <https://rubin-obs.slack.com/archives/C07Q45NUK4P>`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
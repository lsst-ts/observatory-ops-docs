.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Ioana Sotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Jacqueline Seron, Erik Dennihy, Kris Mortensen*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Templates-Title-of-Troubleshooting-Procedure:
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

.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

When running a script that commands the dome shutter (e.g. ``prepare_for/vent`` , ``prepare_for/onsky``  or ``auxtel/shutdown``), 
the script fails showing a failure to communicate with the dome top-end where the shutter control resides. 

.. _Top-Comm-Error-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

When the command to the shutter is run within the script, an error is received in LOVE showing a communication error:

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

This is a hardware issue related to a lost communication with the top-end or rotating part of the dome. 
This can happen after a dome cabinets reboot, a power-off-on sequence or a power outage, that, not done 
in the proper order, can cause communication failures. Contact Mario Rivera or someone at the summit, to 
follow the dome cabinet power on procedure in the right order. If no one is available, you can attempt the 
procedure described in **Section 7.6** of the `Advanced Operations Procedures <https://tstn-004.lsst.io/#at-dome-communication-loss>`_ 
page.

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- Communication is back online and scripts that command the dome shutter will work without issue.

.. _Top-Comm-Error-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in `#summit-auxtel <https://rubin-obs.slack.com/archives/C07Q45NUK4P>`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
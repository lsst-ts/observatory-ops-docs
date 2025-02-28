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
.. |contributors| replace:: *Gonzalo Aravena*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Rotator-Out-Of-Range:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########################
AuxTel Rotator Out Of Range
###########################

.. _AuxTel-Rotator-Out-Of-Range-Overview:

Overview
========

:file:`latiss_acquire` (Spectroscopic survey) or :file:`track_target_and_take_image` (Imaging survey) 
script failed with the error message:

.. code-block:: text

    Rejected: Rotator out of range. Target in rotator limit (-170 to 170 degrees) but out of slew limit margin (1 degs).

and *ATPtg* might goes into ``FAULT``.

.. _AuxTel-Rotator-Out-Of-Range-Error-Diagnosis:

Error diagnosis
===============

During the imaging or spectroscopic surveys, :file:`latiss_acquire` (Spectroscopic survey) or :file:`track_target_and_take_image` (Imaging survey) 
causing *ATPtg* to fault. 
The full traceback error received is:

.. code-block:: text

    Error in run Traceback (most recent call last): 
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/base_script.py", line 603, in do_run await self._run_task 
    File "/net/obs-env/auto_base_packages/ts_standardscripts/python/lsst/ts/standardscripts/base_track_target_and_take_image.py", line 237, in run await self.track_target_and_setup_instrument() 
    File "/net/obs-env/auto_base_packages/ts_standardscripts/python/lsst/ts/standardscripts/auxtel/track_target_and_take_image.py", line 141,  in track_target_and_setup_instrument await self.atcs.slew_icrs( 
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 647, in slew_icrs raise ack_error 
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 615, in slew_icrs await self.slew( 
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 814, in slew raise ack_err 
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/base_tcs.py", line 803, in slew await self._slew_to( 
    File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1413, in _slew_to await slew_cmd.start(timeout=slew_timeout) 
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/topics/remote_command.py", line 487, in start return await cmd_info.next_ackcmd(timeout=timeout) 
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-6.0.0/lib/python3.10/site-packages/lsst/ts/salobj/topics/remote_command.py", line 191, in next_ackcmd raise base.AckError(msg="Command failed", ackcmd=ackcmd) 
    lsst.ts.salobj.base.AckError: msg='Command failed', ackcmd=(ackcmd private_seqNum=1630455441, ack=<SalRetCode.CMD_FAILED: -302>, error=6611,  
    result='Rejected : Rotator out of range. Target in rotator limit (-170 to 170 degrees) but out of slew limit margin (1 degs)') 



.. _AuxTel-Rotator-Out-Of-Range-Procedure-Steps:

Procedure Steps
===============

The interim solution requires recovering the *ATPtg* back to ``ENABLED`` in the case it went to ``FAULT``, and skipping to the next target in the ATQueue 
by pressing the :guilabel:`PLAY` button. 
If this script also fails with the same error, wait three minutes and try again.


#. Recover *ATPtg* from ``FAULT`` state: Transition the *ATPtg* *CSC* from LOVE ASummaryState through the states, ``FAULT`` → ``STANDBY`` → ``START`` → ``ENABLED``.
#. Add a :file:`auxtel/correct_pointing.py` script to the top of the queue to recover the pointing offsets from the beginning of the night. No configuration is needed, you can use the default configuration.  
#. Press :guilabel:`PLAY` button in the ATQueue: This will skip to the next target waiting in the queue.
#. If this "new" script fails as well, wait three minutes and repeat 1-2 again.
#. Log in relevant information about this failure in the ticket `OBS-52 <https://rubinobs.atlassian.net/browse/OBS-52>`__.


Alternative Procedure
=====================

In case the previous steps did not work, rotator continues failing and *ATPtg* never went to ``FAULT`` state, there is an alternative solution as follows. 

#. Track a new target placing the standard script :file:`auxtel/track_target.py` at the top of the queue. 
   Use the following configuration:
   
   .. code-block:: text
    :caption: track_target.py

    az: 90.0
    el: 60.0

#. Continue adding :file:`auxtel/correct_pointing.py` as in step 2 of previous procedure with the following configuration:

   .. code-block:: text
    :caption: correct_pointing.py

    az: 90.0
    el: 60.0
    mag_limit: 8.0

#. Press :guilabel:`PLAY` button in the ATQueue.

.. We might delete this point in the future because the OBS-52 is closed.
#. Log in relevant information about this failure in the ticket `OBS-52 <https://rubinobs.atlassian.net/browse/OBS-52>`__.


.. _AuxTel-Rotator-Out-Of-Range-Post-Condition:

Post-Condition
==============

- *ATPtg* is back to the ``ENABLED`` state.
- The rotator is within the acceptable range for operations.
- No further "Rotator out of range" errors occur after executing the procedure.


.. _AuxTel-Rotator-Out-Of-Range-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in `#summit-auxtel <https://app.slack.com/client/T06D204F2/C01K4M6R4AH>`__ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Erik Dennihy, Karla Aubel*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Karla Aubel*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Troubleshooting-ATCS-AT-M1-Cover-Fails-to-Open:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########################
AT M1 Cover Fails to Open
###########################

.. _AT-M1-Cover-Fails-to-Open:

Overview
========

This procedure explains the steps to follow when AuxTel M1 Cover fails to open during Daytime checkout or at the start of night. 

Error Diagnosis
===============

This indicates the M1 cover controller is in a bad state. 
This is possible following any daytime work which involves manually controlling the M1 Covers on AuxTel, such as the weekly C02 mirror cleaning.
 
:file:`auxtel/standard_scripts/atpneumatics_checkout.py` fails with:

Traceback:

..code-block::
caption: Traceback:    

Error in run
Traceback (most recent call last):
File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/base_script.py", line 603, in do_run
await self._run_task
File "/net/obs-env/auto_base_packages/ts_standardscripts/python/lsst/ts/standardscripts/auxtel/daytime_checkout/atpneumatics_checkout.py", line 200, in run
await self.atcs.open_m1_cover()
File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1074, in open_m1_cover
await self.rem.atpneumatics.cmd_openM1Cover.start(timeout=self.long_timeout)
File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/topics/remote_command.py", line 487, in start
return await cmd_info.next_ackcmd(timeout=timeout)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/topics/remote_command.py", line 191, in next_ackcmd
raise base.AckError(msg="Command failed", ackcmd=ackcmd)
lsst.ts.salobj.base.AckError: msg='Command failed', ackcmd=(ackcmd private_seqNum=1568846216, ack=<SalRetCode.CMD_FAILED: -302>, error=0, result='ERROR: Command OPENM1COVER rejected while M1 covers controller in StandbyState state.')

This indicates the M1 cover controller is in a bad state. This is possible following any daytime work which involves manually controlling the M1 Covers on AuxTel, such as the weekly C02 mirror cleaning.

Post-Condition
==============

This procedure leaves the telescope with the M1 cover open.

.. _ATSpectrograph-Failed-Due-To-The-Lost-Of-The-Grating-Stage-Position-And-Timed-Out:

Procedure Steps
===============


.. _https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2



Recovering the M1 Cover Controller state and clearing the fault must be done from the ATMCS EUI.

#. Step 1.

Ensure the ATCS CSCs are all set to STANDBY.
The easiest way to do this is to run the standby_atcs.py script from the ATQueue.
Do not proceed to the next step until the CSCs are set to STANDBY, otherwise you will need to reset both the CSC and EUI to regain communication. 

#. Step 2.

Log in to the ATMCS EUI using either Microsoft Remote Desktop or from the control computer on the first floor in the AuxTel dome.
Detailed instructions on how to install and setup the ATMCS EUI using Microsoft Remote Desktop can be found in this recovery procedure: 

:ref:`ATSpectrograph failed due to the lost of the grating stage position and timed out <ATSpectrograph-Failed-Due-To-The-Lost-Of-The-Grating-Stage-Position-And-Timed-Out>`

Procedure to reset M1 Cover state using the EUI is shown in video here: 

.. this is a link to a video:

.. _video-recovery:

.. _https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2


:ref:`https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2 <video-recovery>`

 


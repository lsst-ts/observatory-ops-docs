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
.. |contributors| replace:: *Karla Pena, I. Sotuela*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Troubleshooting-AuxTel-M1-Cover-Fails-To-Open:

.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#############################
AuxTel M1 Cover Fails to Open
#############################

.. _AuxTel-M1-Cover-Fails-To-Open-Overview:

Overview
========

This procedure explains the steps to follow when AuxTel M1 Cover fails to open during daytime checkout or at the start of night. 

.. _AuxTel-M1-Cover-Fails-To-Open-Error-Diagnosis:

Error Diagnosis
===============

This is possible following any daytime work which involves manually controlling the M1 Covers on AuxTel, such as the weekly C02 mirror cleaning.

:file:`auxtel/daytime_checkout/atpneumatics_checkout.py` fails with: 

.. code-block:: text
  :caption: Traceback error for SAL script :file:`atpneumatics_checkout.py`

    Error in run Traceback (most recent call last):
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/base_script.py",
    line 603, in do_run await self._run_taskFile "/net/obs-env/auto_base_packages/ts_standardscripts/python/lsst/ts/standardscripts/auxtel/daytime_checkout/atpneumatics_checkout.py",
    line 200, in run await self.atcs.open_m1_cover()File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", 
    line 1074, in open_m1_cover
    await self.rem.atpneumatics.cmd_openM1Cover.start(timeout=self.long_timeout)File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/topics/remote_command.py", line 487, in start
    return await cmd_info.next_ackcmd(timeout=timeout)
    File "/opt/lsst/software/stack/conda/envs/lsst-scipipe-7.0.1/lib/python3.11/site-packages/lsst/ts/salobj/topics/remote_command.py", line 191, in next_ackcmd
    raise base.AckError(msg="Command failed", ackcmd=ackcmd)
    lsst.ts.salobj.base.AckError: msg='Command failed', ackcmd=(ackcmd private_seqNum=1568846216, ack=<SalRetCode.CMD_FAILED: -302>, 
    error=0, result='ERROR: Command OPENM1COVER rejected while M1 covers controller in StandbyState state.')
    

Post-Condition
==============

This procedure leaves the telescope with the M1 cover open.

.. _AuxTel-M1-Cover-Fails-To-Open-Procedure:

Procedure Steps
===============

The recovery of the M1 cover control must be done from the *ATMCS EUI*.

#. **Ensure the ATCS CSCs are all set to STANDBY**

   The easiest way to do this is to run the :file:`standby_atcs.py` script from the *ATQueue*.
   Do not proceed to the next step until the CSCs are set to ``STANDBY``, otherwise you will need to reset both the CSC and EUI to regain communication. 

#. **Log in to the ATMCS EUI** either using a remote desktop or from the control computer on the first floor of the AuxTel dome. 

   More instruction can be found in the :ref:`access ATMCS EUI procedure <AuxTel-Non-Standard-Operations-AuxTel-EUI-Access>`. 

#. **Close the ATMCS EUI tab** 

#. **Engage E-stop in main AT Control Cabinet and ATDome Main Box** located on the first floor. 

#. **Release E-stop starting with the ATDome Main Box followed by the AT Control Cabinet**. 
   
   Refer to :ref:`release E-stop procedure <E-Stop-Procedure-How-Engage-Disengage-E-stop-System>` for more details. 

#. **Open LSST Auxiliary Telescope MCS & Pneumatics EUI aka ATMCS** in the web-browser. 
   
   Address is *http://139.229.170.47:8000/atmcs.html*
    
    .. figure:: /AuxTel/Non-standard-Operations/_static/EUI-ATMCS.png  
      
      ATMCS EUI

 
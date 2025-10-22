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
.. |contributors| replace:: *Kris Mortensen, Craig Lage, Michael Reuter*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AT-Fiber-Spectrograph-Fault:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#########################
ATFiberSpectrograph Fault
#########################

.. note::
    This is a procedure template file that is associated with a template directory structure. This note should be deleted when the section is properly populated.

.. _AT-Fiber-Spectrograph-Fault-Overview:

Overview
========

The AuxTel Calibration System FiberSpectrograph.3 goes to ``FAULT``, claims to have lost connection 
to USB and it can’t be recovered (cycled to ``ENABLED``) from LOVE. This may occur when running AuxTel 
daytime calibrations.

.. _AT-Fiber-Spectrograph-Fault-Error-Diagnosis:

Error diagnosis
===============

- When FiberSpectrograph.3 goes to ``FAULT``, the following error will display within the CSC:

.. code-block:: bash

    'Failed: Failed to connect to fiber spectrograph.'
    Fault! errorCode=1, errorReport="Failed to connect to 
    fiber spectrograph.: RuntimeError('No attached USB Avantes devices found.')"


.. _AT-Fiber-Spectrograph-Fault-Procedure-Steps:

Procedure Steps
===============

.. important::
    Try to restart the ATSpectrograph CSC 1-2 times before committing power cycles and reboots. 
    If restarting the CSC does not fix the issue, then continue with the following procedure.

1. First, you may consider checking the connections in the USB at both ends of the Avantes spectrometer 
   in case any of the cables is loose.

2. Power cycle the fiber spectrograph with the rocker switch. See Figure 2 in 
   `TSTN-032: AuxTel Illumination System Handbook <https://tstn-032.lsst.io/>`_

.. note::

    The power cycle of the Fiber Spectrograph could also be done via Outlet 7 of the 
    Auxtel Illumination System PDU http://auxtel-illpdu.cp.lsst.org/. 
    The password can be located in the 1Password AuxTel Vault. 

3. Power cycle auxtel-ill-control.cp.lsst.org computer via the green and orange power connector 
   (see Figure 7 in :ref:`AuxTel Recovery Page <AuxTel-Non-Standard-Operations-AuxTel-Recovery-after-Shutdown>`). 
   
.. note::
   
   It is also possible :command:`reboot` by remote ssh login into the auxtel-ill-control.cp.lsst.org using your IPA.

4. SSH into *auxtel-ill-control.cp.lsst.org* with your IPA, and issue the following commands:

.. code-block:: bash

    # Initial shutdown of spectrograph:
    >> sudo -iu dco

    # Make sure to wait for the previous command it gets through saying,
    # "The service 'durability' is now operational."
    # Then continue with launching the spectrograph:
    >> ./launch_AuxTel_Illumination_containers.sh

    # Once lauched, verify correct status with:
    >> docker ps -a


.. _AT-Fiber-Spectrograph-Fault-Post-Condition:

Post-Condition
==============

- Fiber spectrograph can be ``ENABLED`` again, and calibrations may continue.

.. _AT-Fiber-Spectrograph-Fault-Contingency:

Contingency
===========

.. _#summit-auxtel: https://rubin-obs.slack.com/archives/C07Q45NUK4P

If the procedure was not successful, report the issue in `#summit-auxtel`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
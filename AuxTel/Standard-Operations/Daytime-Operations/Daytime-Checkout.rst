.. |author| replace:: *E. Dennihy*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS team*

.. _AuxTel-DayTime-Operations-Daytime-Checkout:

.. Links 

.. _`summit's RubinTV`: https://summit-lsp.lsst.codes/rubintv/summit/auxtel 
.. _`USDF RubinTV`: https://usdf-rsp-dev.slac.stanford.edu/rubintv/summit-usdf/auxtel 
.. _`CCS`: http://ccs.lsst.org/RecentImages/auxtel.html
.. _`LATISS OODS Ingest Status`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/27

##################
Daytime Checkout 
##################


To ensure the Auxiliary Telescope is fully operational and ready for nighttime use, 
we have created a series of SAL Scripts that successively checkout each of the major components, 
culminating in a full test of the system involving slewing to a target, tracking, and taking a test image with LATISS. 
The goal of these scripts is to test the functionality of each component within the current software environment,
and alert the daytime staff to any operational issues before going on-sky. 
These tests are designed to be run using the script queue on LOVE during the daytime with an Observing Specialist 
or other personnel available to verify their results. 

The scripts are intended to be run in order, 
but offer some flexibility in what state to leave the Auxiliary Telescope 
(e.g. ready to take calibrations, ready to observe at night, or simply parked and shutdown). 
They can also be run individually if a single component is undergoing maintenance 
and requires a check of basic functionality. 

**None of the scripts require configuration.**

.. Important::

    The daytime checkout scripts involve Telescope, Dome, and Instrument component movement. 
    Before running, ensure that the area surrounding the telescope is and dome is clear for movement. 
    You MUST announce that you are running the checks on the #summit-announce channel before execution. 

The scripts can all be found under the standard scripts panel in the *LOVE ATQueue* view. 
The order of script execution is nominally:

* :file:`auxtel/enable_latiss.py` - Can be skipped if LATISS enabled 
* :file:`auxtel/enable_atcs.py` - Can be skipped if ATCS already enabled
* :file:`auxtel/daytime_checkout/latiss_checkout.py`
* :file:`auxtel/daytime_checkout/atpneumatics_checkout.py`
* :file:`auxtel/daytime_checkout/telescope_and_dome_checkout.py`
* :file:`auxtel/daytime_checkout/slew_and_take_image_checkout.py`

*auxtel/enable_latiss.py*
=========================

Bring *LATISS* to an enabled state to prepare for checkout. 

*auxtel/enable_atcs.py*
=======================

Bring the *ATCS* into an enabled state to prepare for checkout. 

*auxtel/daytime_checkout/latiss_checkout.py*
============================================

This script will take a bias and an engineering frame with *LATISS* 
and ensure that they are ingested by the *Observatory Operations Data Service (OODS)*.

Verify that the bias appears on the `summit's RubinTV`_. 
In case the image fails to appear, verify whether they have been ingested on *Chronograph* (`LATISS OODS Ingest Status`_) and/or `CCS`_,
and promptly communicate the issue in the channel *#summit-auxtel*. 

You can also check if images are arriving correctly at Rubin's SLAC facility using `USDF RubinTV`_.

*auxtel/daytime_checkout/atpneumatics_checkout.py*
==================================================

This script will first turn on the valves and check that the line pressure is sufficient for operations. 
Next, the telescope will be slewed to the park position, if it is not already there. 
Then, it will turn on/off the *ATAOS* corrections before lowering the mirror back down onto its hard points.
Finally, the mirror cover and vents are opened and closed. 

*auxtel/daytime_checkout/telescope_and_dome_checkout.py*
========================================================

This script starts by performing a slew of the telescope without dome movement. 
Then, sidereal tracking for the telescope is enabled and the system is left to track for a few minutes. 
Tracking is disabled and then the dome is commanded to move to a new position, without telescope movement. 
Finally, the telescope and dome are returned to a park position and left enabled.

*auxtel/daytime_checkout/slew_and_take_image_checkout.py*
=========================================================

This script will slew the telescope and dome to two different targets, 
track each target for 3 minutes and take a single verification image. 
The mirror covers remain closed during the duration of the script. 
At the end of the script, the telescope and dome are parked. 

Check that the verification image pop up in the monitor at `summit's RubinTV`_.



.. note::  
   Here you reach the end of Daytime checkouts. Next step depends on the available time before venting. Daily Calibrations, including FLATS,
   take a little over an hour to complete, and venting can only begin once the Sun’s elevation above the horizon is below **55 degrees**.  

   - **If daytime checkouts were completed early**, there is enough time to proceed with :ref:`LATISS Daily Calibrations <Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure>` 
     before venting. 
   - **If daytime checkouts were completed late in the afternoon**, you can skip calibrations and continue with :ref:`Prepare for vent <AuxTel-Daytime-Operations-Prepare-for-vent>`.

   This ensures the telescope is properly prepared for Nighttime Operations.  


This procedure was last modified on |today|.
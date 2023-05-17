.. |author| replace:: *E. Dennihy*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _AT-Daytime-Checkout-Daytime-Checkout:

############################
Daytime Checkout SAL Scripts
############################

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

None of the scripts require configuration. 

.. Important::

    The daytime checkout scripts involve Telescope, Dome, and Instrument component movement. 
    Before running, ensure that the area surrounding the telescope is and dome is clear for movement. 
    You MUST announce that you are running the checks on the #summit-announce slack channel before execution. 

The scripts can all be found under the Standard scripts panel in the LOVE ATQueue view. 
The order of script execution is nominally:

* auxtel/enable_latiss.py - Can be skipped if LATISS enabled 
* auxtel/daytime_checkout/latiss_checkout.py
* auxtel/enable_atcs - Can be skipped if ATCS already enabled
* auxtel/daytime_checkout/atpneumatics_checkout.py
* auxtel/daytime_checkout/telescope_and_dome_checkout.py
* auxtel/daytime_checkout/slew_and_take_image_checkout.py
* auxtel/prepare_for/flats - Can be substituted for other prepare_for scripts to leave AuxTel in different state

*auxtel/enable_latiss.py*
===============

Bring LATISS to an enabled state to prepare for checkout. 

*auxtel/daytime_checkout/latiss_checkout.py*
=================

This script will take a bias and engineering frame with LATISS and ensure that they are ingested by the OODS.

Check that the bias pops up in the monitor (https://roundtable.lsst.codes/rubintv/summit/auxtel/monitor_current)
If it fails, let Patrick or Merlin know.

You can check that it ingested at USDF with this link: ******* <b>Add when available<b>

*auxtel/enable_atcs.py*
=============

Bring the ATCS into an enabled state to prepare for checkout. 

*auxtel/daytime_checkout/atpneumatics_checkout.py*
=====================

This script will first turn on the valves and check that the line pressure is sufficient for operations. 
Next, The telescope will be slewed to the park position if it is not already there. 
Then, it will turn on/off the ATAOS corrections before lowering the mirror back down onto its hard points.
Finally the mirror cover and vents are opened and closed. 

*auxtel/daytime_checkout/telescope_and_dome_checkout.py*
=============================

This script starts by performing a slew of the telescope without dome movement. 
Then sidereal tracking for the telescope is enabled and the system is left to track for a few minutes. 
Tracking is disabled and then the dome is commanded to move to a new position, without telescope movement. 
Finally, the telescope and dome are returned to a park position and left enabled.

*auxtel/daytime_checkout/slew_and_take_image_checkout.py*
=============================

This script will slew the telescope and dome to two different targets, 
track each target for 3 minutes and take a single verification image. 
The mirror covers remain closed during the duration of the script. 
At the end of the script the telescope and dome are parked. 

Check that the verification images pop up in the monitor (https://roundtable.lsst.codes/rubintv/summit/auxtel/monitor_current)
If either fails, let Patrick or Merlin know.

*auxtel/daytime_checkout/prepare_for/flat.py*
===================
This is the default end-of-checkout script. 
It will leave the telescope in position to start taking afternoon calibrations. 
If you are not sure how you want to leave the telescope,
consider running this script as it will further exercise the system. 

Other options include: prepare_for/onsky, prepare_for/vent and shutdown_all

Quick Troubleshooting
=====================

Add some tips here on what to do if things don't work. 

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

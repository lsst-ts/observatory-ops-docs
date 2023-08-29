.. |author| replace:: *isotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _AT-On-sky-WEP:

####################################################################################
Beginning of the night: Center, absorb pointing offsets, mirror alignment and focus
####################################################################################

.. _Beginning_of_the_night-the-Telescope-Overview:

Overview
========

This procedure must be followed by the observers before the beginning of dark time, prior to starting science or engineering activities.

It will center a target, absorb the zero-point pointing offsets, align mirrors and focus the telescope. 

.. _Beginning_of_the_night-Prerequisites:

Prerequisites
=============
- The telescope is :ref:`open and ready for on-sky operations <AT-Pre-Open-for-On-Sky-Operations>`: 
  it has been vented (if applicable), mirror cover and dome shutter are open, AOS corrections are enabled. 

- The sky brightness is low enough that the WEP (wavefront estimate pipeline) can converge successfully. 
  This condition is normally achieved around 10-15 minutes before the end of nautical twilight or dark time. 

.. _Beginning_of_the_night-Post-Conditions:

Post-Condition
===============

- Telescope is aligned, focused and pointing offsets have been absorbed. 
  
  The system is ready to start :ref:`scheduler-driven observations <Nighttime-Scheduler-Scheduler-Operational-Procedures>` or engineering tasks. 

.. _Beginning_of_the_night-Procedure-Steps:

Procedure Steps
===============

#. Confirm sky background is dark enough. 

   As a general rule, a good time to start executing the following SAL scripts is 10-15 minutes before the end of nautical twilight. 

#. Command the telescope to measure and correct for any nightly pointing zero-point offsets using the SAL script ``auxtel/correct_pointing.py``.

   The steps the script performs in the background are:
        - Reset the pointing and hexapod x and y offsets.
        - Acquire target. How to select the source is summarized below. 
        - Take an image and find the offset between the brightest source in the field and the boresight.
        - Offset the telescope to place the source at the center of the detector. Take an image to confirm the target has been centered. 
        - The telescope will absorb the measured pointing offsets. 

   Nominally, the pointing offsets and mirror alignment are performed towards the east, ``az`` 90 deg, and at mid-elevations, ``el`` 60 deg. 

   From the LOVE ``ATQueue`` panel, under ``AVAILABLE SCRIPTS``, add the external script ``auxtel/correct_pointing.py``, by clicking on the blue icon. 

   Under ``CONFIG`` in the ``configuring Script:correct_pointing.py`` window, leave the window empty so the default configuration is loaded and click on ``Add``:

   .. figure:: ./_static/CorrectPointing_AuxTel.png
     :name: correctPointing

     LOVE launching the ``correct_pointing`` script with the defaults, to find a target around ``az`` 90 deg and ``el`` 60 deg, 
     magnitude limit ``mag_limit`` 6.0, magnitude range ``mag_range`` 4.0 and a search radius ``radius`` of 5 deg.  

   Visually inspect the recent images in RubinTV to confirm that the right target has been centered. 
   If it did, move to the next step. 
   If it didn't, repeat step #2. 

#. Launch a WEP sequence on the same target to use the wavefront estimation pipeline to measure wavefront error and perform mirror alignment and focus. 

   Load the script ``auxtel/latiss_wep_align.py``, available under ``External scripts`` in the ``ATQueue``. 
 
   In the ``Configuring Script: latiss_wep_align`` window, leave the ``CONFIG`` cell empty to perform the WEP over the same target the centering step was done and 
   which the telescope is still tracking.

   Click on ``Add`` and the script will be added to the end of the script queue.

   .. figure:: ./_static/WEP_AuxTel.png
       :name: latiss-wep

       Screenshot of LOVE launching the WEP. 


If these three steps were successful, the telescope is now centered, aligned and focus. 

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

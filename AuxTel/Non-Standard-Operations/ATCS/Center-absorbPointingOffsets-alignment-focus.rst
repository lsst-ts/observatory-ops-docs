.. |author| replace:: *isotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _AuxTel-Non-Standard-Operations-Center-Focus:

####################################################################################
Center, absorb pointing offsets, mirror alignment and focus
####################################################################################

.. _Center-Focus-Overview:

Overview
========

This procedure must be followed if the pointing or focus is lost for whatever reason. 

It will center a target, absorb the zero-point pointing offsets, align mirrors and focus the telescope. 

.. _Center-Focus-Precondition:

Precondition
=============
- The telescope is :ref:`open and ready for on-sky operations <AuxTel-Nighttime-Operations-Open-for-On-Sky-Operations>`: 
  it has been vented (if applicable), mirror cover and dome shutter are open, AOS corrections are enabled. 

- The sky brightness is low enough that the WEP (wavefront estimate pipeline) can converge successfully. 
  This condition is normally achieved around 10-15 minutes before the end of nautical twilight or dark time. 

.. _Center-Focus-Post-Conditions:

Post-Condition
===============

- Telescope is aligned, focused and pointing offsets have been absorbed. 
  
  The system is ready to continue :ref:`scheduler-driven observations <Scheduler-Scheduler-Operational-Procedures>` or engineering tasks. 

.. _Center-Focus-Procedure-Steps:

Procedure Steps
===============

#. Confirm sky background is dark enough. 

   Generally, the sky becomes dark enough for Wavefront-Estimation Error script (WEP) to converge approximately 10 minutes before the end of nautical twilight.

#. Pause the ATQueue and place at the top of the queue the scripts detailed in steps 3. and 4.  

#. Command the telescope to measure and correct for any nightly pointing zero-point offsets using the SAL script ``auxtel/correct_pointing.py``.

   The steps the script performs in the background are:
        - Reset the pointing and hexapod x and y offsets.
        - Acquire target. How to select the source is summarized below. 
        - Take an image and find the offset between the brightest source in the field and the boresight.
        - Offset the telescope to place the source at the center of the detector. Take an image to confirm the target has been centered. 
        - The telescope will absorb the measured pointing offsets. 

   Nominally, the pointing offsets and mirror alignment are performed towards the east, ``az`` 90 deg, and at mid-elevations, ``el`` 60 deg. 

   From the LOVE ``ATQueue`` panel, under AVAILABLE SCRIPTS, add the external script :file:`auxtel/correct_pointing.py`, by clicking on the blue icon. 

   Under ``CONFIG`` in the ``configuring Script:correct_pointing.py`` window, leave the window empty so the default configuration is loaded and click on :guilabel:`Add`:

   .. figure:: ./_static/CorrectPointing_AuxTel.png
     :name: correctPointing

     LOVE launching the :file:`auxtel/correct_pointing.py` script with the defaults, to find a target around ``az`` 90 deg and ``el`` 60 deg, 
     magnitude limit ``mag_limit`` 6.0, magnitude range ``mag_range`` 4.0 and a search radius ``radius`` of 5 deg.  

   Visually inspect the recent images in RubinTV to confirm that the right target has been centered. 
   If it did, move to the next step. 
   If it didn't, repeat step #3. 

#. Launch a WEP sequence on the same target to use the wavefront estimation pipeline to measure wavefront error and perform mirror alignment and focus. 

   Load the script :file:`auxtel/latiss_wep_align.py`, available under ``External scripts`` in the ``ATQueue``. 
 
   In the ``Configuring Script: latiss_wep_align`` window, leave the ``CONFIG`` cell empty to perform the WEP over the same target the centering step was done and 
   which the telescope is still tracking.

   Click on :guilabel:`Add` and the script will be added to the end of the script queue.

   .. figure:: ./_static/WEP_AuxTel.png
       :name: latiss-wep

       Screenshot of LOVE launching the WEP. 


If these steps were successful, the telescope is now centered, aligned and focus. 


This procedure was last modified on |today|.

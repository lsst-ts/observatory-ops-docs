.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *isotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: **

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AT-Pre-Prepare-for-vent:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

################
Prepare for vent
################

.. _Prepare-for-vent-Overview:

Overview
========

This procedure gets the AuxTel system ready for venting, positioning the telescope horizontally and the dome to face opposite the Sun to maximize the venting of the system. 

Venting accelerates thermal equalization, increasing the amount of free air currents. 
This way, the local thermal imbalances in the air inside the dome, that could deteriorate image quality, are minimized.  

In a typical observing night, observers must start venting in the afternoon following the execution of :ref:`daytime checkout <AT-Daytime-Checkout-Daytime-Checkout>` and 
:ref:`calibrations <LATISS-Combined-Calibrations-Procedure-LATISS-Combined-Calibrations-Generation-Procedure>`, when applicable.  

Once the Sun's elevation above horizon is below 25 degrees, please proceed to :ref:`prepare for on-sky operations <AT-Pre-Open-for-On-Sky-Operations>`. 
The Sun's coordinates at any given time, along with several other useful ephemeris, can be found at the :ref:`sky almanac <Sky-Almanac-Get-Sun-Coordinates>`.

.. _Prepare-for-vent-Prerequisites:

Prerequisites
=============

- Before taking the decision to open, review the weather conditions and :ref:`weather constraints <weather-constraints-deciding-to-open>` page.

- AuxTel is fully ready to operate and all components are enabled. 

- The :ref:`daytime checkout <AT-Daytime-Checkout-Daytime-Checkout>` has been executed successfully. 

- This procedure will take the system from the end point of the :ref:`daytime checkout <AT-Daytime-Checkout-Daytime-Checkout>`, 
  :ref:`calibration <LATISS-Combined-Calibrations-Procedure-LATISS-Combined-Calibrations-Generation-Procedure>` 
  state or any other initial state, to start venting. 

.. _Prepare-for-vent-Post-Condition:

Post-Condition
==============

- Telescope is venting. 

  The ``auxtel/prepare_for/vent.py`` script will run until the Sun's elevation is 5 degrees above the horizon, if there's no operator interaction prior to that. 
  
  Once the Sun's elevation is past below 25 degrees above horizon, please :ref:`prepare for on-sky operations <AT-Pre-Open-for-On-Sky-Operations>`. 

.. _Prepare-for-vent-Procedure-Steps:

Procedure Steps
===============
#. Review procedure :ref:`prerequisites <Prepare-for-vent-Prerequisites>` and confirm they have been executed. 

#. Announce in the #summit-announce and #summit-auxtel Slack channel that AuxTel is going to vent, and telescope and dome will move. 

#. Command the telescope and dome to prepare for venting. 

   Load the ``auxtel/prepare_for/vent.py`` script from the LOVE ``ATQueue`` panel, under ``AVAILABLE SCRIPTS`` by clicking on the blue icon. 

   .. note::
     The ``auxtel/prepare_for/vent.py`` will only run when the Sun's elevation is between 55 deg and 5 deg above horizon. 
     Otherwise, it will give you a warning and fail. 
     
   In the ``configuring script:vent`` screen that pops up, leave the ``CONFIG`` box empty. 

   .. figure:: ./_static/PrepareforVent_AuxTel.png
     :name: prepareforonsky_AuxTel
    
     Screenshot of LOVE launching ``auxtel/prepare_for/vent.py`` script. 

   The script performs the following steps:

       * Check that all components are enabled. 
       * Disable dome following. 
       * Home the dome. 
       * Disable AOS open loop corrections. 
       * Close M1 primary mirror cover. 
       * Close dome, if it was open. 
       * Enable AOS open loop correction.
       * Point telescope horizontally; az = 180, el = 30, rot = 0 deg. 
       * Disable AOS open loop corrections. 
       * Slew dome to face opposite the Sun; az = Sun's azimuth - 180 deg.

   .. note::
     The ``auxtel/prepare_for/vent.py`` script will keep running until the Sun's elevation is 5 degrees above the horizon, 
     repositioning the dome azimuth position every minute. 
     
   .. figure:: ./_static/PrepareforVent_AuxTel_running.png
     :name: script prepareforonsky_AuxTel running

     ``auxtel/prepare_for/vent.py`` script running until observer manually stops it or the Sun reaches 5 deg above horizon. 

#. Proceed to the AuxTel dome, and open the dome shutter manually two thirds of the way using the buttons at the top of the stairs. 
   The main shutter must not be opened too far such that direct sunlight contacts the telescope or any hardware on concrete inside the dome.     
   It is ok if small amounts of sunlight impacts the internal skin of the dome though. 

#. If the wind speed is below 8 m/s, manually open vent gate #3 using the remote controller and turn on the extraction fan power to max.  
   If wind speed is above or close to 8 m/s, keep vent gates closed and extraction fan off. 

   .. figure:: ./_static/PrepareforVent_AuxTel_VentGate3andFan.png
      :name: Dome Vent Gate 3 and Extraction Fan 

      AuxTel dome vent gate #3 and extraction fan with its controller located at the dome pier. 

#. Visually confirm in `LOVE displays <http://love01.cp.lsst.org/uif/view?id=68>`__ that the system is venting. 
        
        * Telescope is pointing to az = 180, el = 30 deg, rot = 0. 
        * M1 Mirror cover is closed. 
        * ATAOS corrections are disabled. 
        * Dome shutter is two thirds open and pointing opposite the Sun, towards the eastern horizon; az = Sun's azimuth - 180 deg. 
     
   .. figure:: ./_static/PrepareforVent_AuxTel_LOVEdisplayConfirmation.png
     :name: Confirmation of execution of ``auxtel/prepare_for/vent.py`` script LOVE 
     
     LOVE displaying AuxTel telescope and dome venting. 


.. _Prepare-for-vent-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.
.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
  - If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *isotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *None*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Nighttime-Operations-Open-for-On-Sky-Operations:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#############################
Prepare for On-Sky Operations
#############################

.. _Open-for-On-Sky-Operations-Overview:

Overview
========

This procedure gets the AuxTel system ready for on-sky operations, preparing the telescope and dome to be fully open. 

In a standard night, it will follow the execution of the :ref:`venting <AuxTel-Daytime-Operations-Prepare-for-vent>` procedure, 
but it works from any initial state of the system. 

If venting wasn't possible, observers must prepare for on-sky once the Sun is below an elevation of 25 degrees. 
The Sun's coordinates at any given time, along with several other useful ephemeris, can be found at the :ref:`sky almanac <Visualization-and-Monitoring-Tools-Sky-Almanac>`.

.. _Open-for-On-Sky-Operations-Precondition:

Precondition
=============

* Before making the decision to open, review the weather conditions and :ref:`weather constraints <auxtel-weather-constraints-deciding-to-open>` page.

* AuxTel is fully ready to operate and all components are enabled. 

* The :ref:`daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>` has been executed successfully. 

* This procedure will take the system from venting, the :ref:`calibration <AuxTel-Daytime-Operations-LATISS-Combined-Calibrations-Generation-Procedure>` 
  state or any other initial state to be prepared for on-sky observations. 

.. _Open-for-On-Sky-Operations-Post-Condition:

Post-Condition
==============

- Telescope is ready for on-sky operations. 
  
  Around 15 minutes before the end of the evening nautical twilight, proceed with the :ref:`beginning of the night procedure to center, align and focus the telescope. <AuxTel-Nighttime-Operations-WEP>`

.. _Open-for-On-Sky-Operations-Procedure-Steps:

Procedure Steps
===============
#. Review :ref:`preconditions <Open-for-On-Sky-Operations-Precondition>` and confirm they have been executed. 

#. Announce in the #summit-announce and #summit-auxtel Slack channel that AuxTel is preparing to go on-sky. 

#. Command the telescope and dome to prepare for on-sky observations. 

   Load the ``auxtel/prepare_for/onsky.py`` script from the LOVE ``ATQueue`` panel, under ``AVAILABLE SCRIPTS`` by clicking on the blue icon. 
   The script will be added to the script queue. 
   
   .. note::
     If the ``auxtel/prepare_for/vent.py`` script is still running, the queue will run ``auxtel/prepare_for/onsky.py`` once venting is done, around 20 minutes before sunset.  

   In the ``Configuring script:onsky`` screen that pops up, leave the ``CONFIG`` box empty. 
   Make sure there are no spaces in the ``CONFIG`` box, as it may prevent the proper configuration and loading of the script. 

   .. figure:: ./_static/PrepareforOnSky_AuxTel.png
     :name: prepareforonsky_AuxTel
    
     Screenshot of LOVE launching ``auxtel/prepare_for/onsky.py`` script. 

   The script includes the following steps:

       * Slew telescope to az = 90 and el = 80, where it is least likely to be hit by the Sun. 
       * If primary mirror cover is open, the script will now close it. 
         This will protect the mirror and avoid particles and dust falling on it when the dome shutter opens.
       * Move dome to oppose setting Sun to avoid direct sunlight inside the dome that might create thermal issues. 
       * Open dome main shutter.
       * Open primary mirror cover and vents. 
       * Activate AOS open loop corrections.
       * Enable dome following. 

#. If the wind speed is below 8 m/s, manually open vent gate #3 using the remote controller and turn on the extraction fan power to 20 % from the dome pier.  
   If wind speed is above or close to 8 m/s, keep vent gates closed and extraction fan off. 

#. Visually confirm in `LOVE displays <http://love01.cp.lsst.org/uif/view?id=68>`__:

        * Telescope is in position; az = 90, el = 80 deg, rot = 0. 
        * M1 Mirror cover is open. 
        * ATAOS corrections are enabled. 
        * Dome shutter is open and pointing towards the east; az = 90 deg. 
     

   .. figure:: ./_static/PrepareforOnSky_AuxTel_LOVEdisplayConfirmation.png
     :name: Confirmation of execution of ``auxtel/prepare_for/onsky.py`` script LOVE 
     
     LOVE displaying AuxTel telescope and dome prepared for on-sky observations. 


This procedure was last modified |today|.
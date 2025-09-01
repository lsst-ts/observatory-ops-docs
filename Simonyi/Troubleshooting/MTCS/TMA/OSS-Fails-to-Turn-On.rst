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
.. |contributors| replace:: *Karla Aubel, Karla Pena*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _TMA-OSS-Fails-to-Turn-On:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

########################
TMA OSS Fails to Turn On
########################

.. _TMA-OSS-Fails-to-Turn-On-Overview:

Overview
========

This procedure describes how to recover the OSS system when it fails to turn ON. 


.. _OSS-Fails-to-Turn-On-Error-Diagnosis:

Error diagnosis
===============


- Chiller(s) light in the EUI OSS screen is red. **OSS**, **observation** and **cooling** lights are red too. 
  On the alarm banner on the bottom, you can read **LOCAL: COOLING SYSTEM**. 


  .. figure:: ./_static/OSS_general_view.png
   :name: OSS general view 
   :width: 600

   OSS general view 

- The *Alarm History* screen shows

  .. figure:: ./_static/Alarm_History.png
    :name:  Alarm History
    :width: 600

    Alarm History 

in more detail:

  .. figure:: ./_static/alarm_his_1.png
    :name: alarm history A
    :width: 600

    Alarm History Detail

  .. figure:: ./_static/alarm_his_2.png
    :name: alarm history b 
    :width: 600

    Alarm History Detail 
 

.. _OSS-Fails-to-Turn-On-Procedure-Steps:

Procedure Steps
===============

.. todo::
   Make sure everything is in a safe or idle state before troubleshooting. Describe relevant safety steps if necessary.


#. Go to *Level 1 Machinery Room* and bring with you a Philips screwdriver. 
   The *Machinery Room* is the left door in the picture below.

     .. figure:: ./_static/level-1.png
      :name: level 1
      :width: 600

      Level 1

#. The screens in the front panel of one or both of the chiller cabinets display an alarm. 
   On the top, the red band says: **“STATUS: NOT ACKNOWLEDGED”** or **“STATUS: ALARM”**.


        .. figure:: ./_static/chiller_2.jpeg
            :name: chiller 2
            :width: 600

            Chiller #2


        .. figure:: ./_static/alarm_menu.jpeg  
            :name: alarm menu
            :width: 600

            Front panel of Chiller displaying alarms. 


   The large grey box on the cabinet's side (purple arrow) shows a blinking red light and an interlock in the screen.

     .. figure:: ./_static/grey_box_cabinets.jpeg
      :name: grey box cabinets
      :width: 600

      Grey Box on the cabinet's side

     .. figure:: ./_static/interlock_screens.jpeg
      :name: interlock screens
      :width: 600

      Interlock Screen

#. There are two reset buttons inside the chiller cabinet that need to be pressed. 
   From the side of the cabinet, use the screwdriver to remove two screws that are located on top. 
   This will allow you to remove the cover panel. Each cabinet has two panels. 

   Chiller #2 has the reset buttons within the furthermost panel (Image below), while in chiller #1 they are found under the panel closer to the front face of the chiller.

      .. figure:: ./_static/furthermost_panel.jpeg
       :name: remove panel
       :width: 600  

       Remove this panel

      .. figure:: ./_static/Hand.jpeg
       :name: Unscrew 
       :scale: 15 

       Unscrew 

      
#. Press each of the red reset buttons inside the cabinet for 3 seconds: Order does not matter.

     .. figure:: ./_static/reset_button_1.jpeg
         :name: buttons
         :width: 600

         Reset buttons inside chiller cabinet. 


#. Press the reset button on the large grey box on the side of the cabinet. 
   The red alarm light should stop blinking.

     .. figure:: ./_static/reset_button_2.jpeg
       :name: reset in the large grey box
       :scale: 15

       Reset alarm in the grey box. 

#. Acknowledge the alarms in the front panel by pressing the tick mark on the bottom of the screen. 
   After perhaps a minute or two, the front screen should show **"STATUS:OK"**.

     .. figure:: ./_static/acknowledge_alarm.jpeg
      :name: Alarm acknowledgment
      :scale: 15

      Alarm acknowledgment in the front panel. 

        

#. Repeat **steps 2-6** with the other chiller, if it shows an alarm.    

#. Back to the control room, reset the alarm in the TMA EUI *Safety System* screen. 
   Click on the red **OSS malfunction** and press the blue :guilabel:`RESET SELECTED` button.  
   The red color should disappear.

     .. figure:: ./_static/safety_system.png
      :name: TMA EUI
      :width: 600

      Reset **OSS malfunction** alarm in TMA EUI Safety System screen.  



Post-Condition
==============

- The OSS should be now ready to turn ON successfully.


Contingency
===========

Especially after a power glitch or a power cut, there can be additional steps required:

OSS temperature sensor
----------------------

While turning on the OSS through the TMA EUI, there may be rare occurrences where the process prolongs endlessly and never completes. This may be due to a faulty OSS pressure sensor on the TMA, and requires personal intervention for troubleshooting.

Go to level 8 and to the right of the main TMA cabinets you will find a temperature sensor attached to the TMA structure:

     .. figure:: ./_static/location_sensor_OSS.png
      :name: Location OSS temperature sensor
      :width: 600

      OSS temperature sensor location.

     .. figure:: ./_static/OSS_temperature_sensor.png
      :name: OSS temperature sensor
      :width: 600

      OSS temperature sensor.

You will need to touch with your bare fingers the sensor to warm it up. This is especially needed on cold winter nights.


Control cabinet OSS alarms
--------------------------

Some alarms on the OSS cannot be reset through the EUI (e.g., observation and cooling alarms in the OSS General View). Instead, they must be cleared through the control cabinet on the OSS, itself.

Go to level 1 and locate the Control Cabinet OSS (TMA-FA-OS-CBT-5002). You will require to locate its screen and acnowledge alarms. The process should be followed together with some member of the Electronics team.


     .. figure:: ./_static/Control_Cabinet_OSS.png
      :name: Control Cabinet OSS
      :width: 600

      Control_Cabinet_OSS.


     .. figure:: ./_static/Control_Cabinet_OSS_main_menu.png
      :name: Control Cabinet OSS main menu
      :width: 600

      Control Cabinet OSS main menu.


     .. figure:: ./_static/Control_Cabinet_OSS_alarm_acknowlegment.png
      :name: Control Cabinet OSS alarmacknowlegment
      :width: 600

      Control Cabinet OSS alarm acknowlegment (no active alarms in the picture).

If the procedure was not successful, report the issue in channel *#summit-simonyi* and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
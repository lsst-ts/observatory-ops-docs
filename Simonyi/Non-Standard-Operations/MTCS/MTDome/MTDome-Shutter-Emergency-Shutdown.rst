.. _Chronograf Rubin Weather Conditions: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/4?refresh=Paused&lower=now%28%29%20-%2015m
.. _Love Weather Monitor and Forecast: http://love01.cp.lsst.org/uif/view?id=104
.. _AccuWeather: https://www.accuweather.com/en/cl/seron/57851/satellite/57851
.. _Meteoblue: https://www.meteoblue.com/en/weather/week/loma-amarilla_chile_3899825


.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *OS team*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS team*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTDome-MTDome-Shutter-Emergency-Shutdown:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#################################
MTDome Shutter Emergency Shutdown
#################################

.. note::
    **We currently have a dome that the observing crew will be unable to close in the event of a complete power outage**. Until May 2024 we have only star trackers with mirrors that will focus the sun (and would be likely damaged/destroyed by the wrong angle relative to the sun). From early June, we will have a 8m class mirror system. Sunlight focusing on this surface would be catastrophic. **We will govern our decision to open the dome under very restrictive rules until we can assure that the risk is acceptably mitigated.**

            Rubin management is working on two fronts to mitigate the risk.
                * Update the telescope system to allow dome hand closure (longer term).
                *  Install a "pull cord" or similar that will cover the telescope with a tarp (short term).

.. _MTDome-Shutter-Emergency-Shutdown-Overview:

Overview
========

.. warning::
    **Power outage information**

    If you are dealing with a **dome shutter emergency shutdown**. Proceed calmly  to keep the equipment safe. 

    In the event of a power outage, the dome shutter won't be able to be operated from the standard CSC controls or from the 8th floor dome local cabinet buttons.

    The aperture shutter can only be closed in this case by a team of trained personnel: the night time observers are **not supposed to, or allowed to** shut it manually.

    In case of sudden inclement weather, be very cautious and start closing early.

    **Take this into account when monitoring the weather conditions.**


.. warning::
    **Weather constraint information**

    Before deciding to open the main dome shutter at night, weather conditions and predictions must be carefully monitored by the observers on shift.Carefully study `Chronograf Rubin Weather Conditions`_ and `Love Weather Monitor and Forecast`_ for weather conditions and `AccuWeather`_ and `Meteoblue`_ for weather predictions.
    When the winter plan is activated (April - August), AURA-O operations, COS, and NOIRLab Safety will send emails announcing chance of precipitation on the mountains. These communications will typically arrive from Fabrizzio Bruno (fabrizzio.bruno@noirlab.edu). Mountain services will update these forecasts by email as they develop.

    Implement the following guidance:

    If  probability of precipitation is higher than 5 %, or expected lowest temperature of the night minus dew point is less than 5 degrees, 
    or humidity is above 60 %: **DO NOT OPEN THE APERTURE SHUTTER.**


    * If weather conditions are near these limits at the time of dome handover, observers must remain closed and watch humidity trends until 12 degree twilight.

        * If the conditions remain near these limits until 30 minutes after 12 degree twilight, do not open the dome.
        * If the conditions are below these limits 30 minutes after twilight and do not show upward trends, observers may consider opening the dome (Data pending - ABS).
    * In case of doubt regarding the weather conditions, or there is chance of incoming unfavorable weather conditions during the night **DO NOT OPEN** the dome. Night observers **CAN NOT** close the dome shutter in a power full outage situation putting the equipment at risk.



Unfavorable circumstances that indicate the need to close the dome if it is open, or leave the dome closed if it is:

    * Sunrise approaching in the next two hours.
    * Power outage affecting the dome shutter mechanism.
    * Weather inclemencies:

        * Humidity rising above 60 %.
        * Condensation on any surfaces outside of the building.
        * Precipitation.
        * Snow.
        * Wind speed > 15 m/s.
        * Dust in the air or clouds.

Different situations are described below in **decreasing order** of emergency:

 * :ref:`No power, no internet, no phone.  <No-power-no-internet-no-phone>`
 * :ref:`No power in the observatory or in Simonyi Telescope.  <No-power-observatory-Simonyi-telescope>`
 * :ref:`No power on dome aperture shutter, but dome drives are powered on or dome shutter has problems closing, but everything else is fine.  <No-power-dome-aperture-shutter-problem>`
 * :ref:`Internet is down or Control system is down.  <Internet-down-Control-System-down>`
 * :ref:`Rubin is working fine, but you need to close at the end of the night or weather is worsening.  <End-of-night-weather-worsening>`


.. _MTDome-Shutter-Emergency-Shutdown-Precondition:

Precondition
============

.. This section should provide simple overview of preconditions before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

The dome shutter is open and an unforeseeable condition arises, forcing an emergency dome aperture closure.


.. _MTDome-Shutter-Emergency-Shutdown-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- The emergency situation has been clearly notified to the relevant personnel and management.
- Steps to eliminate or minimize the risk to the instruments and hardware are being implemented.
- Eventually, the dome shutter is closed and all equipment is safe.

.. _MTDome-Shutter-Emergency-Shutdowne-Procedure-Steps:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.


.. _No-power-no-internet-no-phone:

**No power, no internet, no phone - Can this even happen?**

In this very unlike situation where the commercial power is off, the generators haven't come up, and there's no communication with the outside world via landline, mobile phone data or calls, and one of the above unfavorable circumstance is approaching, drive to Hotel Pachón and check for power availability. There is a radio in the lobby linked to Rubin channels 3 and 5, and mountain channel 1. The hotel is managed by a different generator, so it is unlikely that ALL mountain facilities will remain without power. Utilize the radio to **activate the emergency contact list**, emphasizing the urgency and specifics of the situation. Management will evaluate the circumstances and determine the appropriate course of action.

.. _No-power-observatory-Simonyi-telescope:
**No power in the observatory or in Simonyi Telescope**

In the event of a commercial power outage and a failure of the backup generators, the observatory will be left without power. This will result in the inability to perform critical operations such as moving the telescope, closing the mirror covers, adjusting the dome azimuth, or closing the aperture shutter. Under these circumstances, the equipment will be at high risk.
In this case, gather all the information about telescope, camera status and dome positions, and activate the :ref:`Out of Hours support call list <Safety/out-of-hours-support.rst>` protocol.
Please use the standard safety measures when visiting the dome enclosure. **Safety of personnel always goes first.**

One of the two observers should go to the Simonyi dome enclosure with PPE, headlight and/or torch (flashlight), while the other observer starts **activating the emergency contact list** via phone or WhastApp, if available.


#. **Gather information:** The observer on the phone should start collecting information regarding the unfavorable circumstance.

        * In case of an impending sunrise, find the time and azimuth of the rising Sun in https://theskylive.com/sun-info. You must change your location on the top of the page under "Observing from" field and read the time and azimuth under the "RISE" output section.

       * For weather-related issues, describe in as much as you can the local conditions in detail.
            * Direction of the incoming cloud front.
            * Direction and wind speed.
            * Condensation status. .... etc, humidity and dew point temperature. 


#. Meanwhile, the other observer needs to go to the 8th floor to **confirm telescope and dome status** with their own eyes. Do not rely on EFD or LOVE readings. Bring your PPE and headlights and torches (flashlights).

        * Notice the **dome aperture position** (Markings in the concrete structure with N/NE/E/SE/S..and Azimuth value).
        * Notice the **position of the telescope**, both azimuth and elevation. Make a best guess if there are not numerical indicators available to you.
        * Confirm whether the **mirror covers** are open or closed. 
        * **Camera shutter status**. Can we see if camera shutter is open or closed from outside? Shine a light and see CCD?



#. To the emergency/management contact, **communicate the situation** emphasizing the urgency of the situation. Something like:

        *"We lost all power in the observatory and can't operate the dome shutter. Sunrise will be in 2.5 hours at 80 degrees azimuth. Dome is pointing to the southwest at around 210 degrees azimuth, telescope is pointing to the north at 5 deg azimuth and at 60 degrees elevation, mirror covers are open and ComCam shutter is closed. "*

        Another possibility

        *"We lost all power in the observatory and can't operate the dome shutter. Humidity is quickly rising and we have noticed that some condensation is starting to build up in the metallic part of the building outside. We need to close the dome shutter as soon as possible, please send the team up. Dome is pointing to the south towards 180 degrees azimuth, telescope is pointing to the north at 350 deg azimuth and at 15 degrees elevation, mirror covers are open and ComCam shutter is open."*


#. Mitigate potential damage if possible while awaiting for the arrival of team from La Serena (2 hours wait).

#. **Await further instructions:** Remain in communication with the management team and/or emergency contacts for updates and instructions.


.. _No-power-dome-aperture-shutter-problem:

**Dome aperture has no power, but dome azimuth drives do - or dome shutter has problems closing, but everything else is fine.**

The dome aperture shutter is not powered on, or it has issues closing, such as getting stuck, but the dome azimuth is still under control. The rest of the observatory is working nominally.

The purpose is to **activate the emergency contact list** so qualified personnel can come to the summit to close the dome aperture. Provide them as much information as possible. Follow the steps below to mitigate damage to the equipment.

#. One of the observers should start **activating the emergency contact list** via phone or WhatsApp, if available, while the other continues with step 2.

#. **Park the telescope and close mirror covers.**
    * Parking position to close the covers is zenith.
    * If the covers are not working, emergency parking position (with glass) is horizon.

#. Slew the dome azimuth to minimize exposure to the unexpected elements.
    * In case the Sun is rising in next three hours, find the time and azimuth of the Sun rise in https://theskylive.com/sun-info. Change your location on the top of the page under "Observing from" field and read the time and azimuth under "RISE" output section. Slew the dome opposite the morning sunrise, adding 180 degrees to the azimuth listed in the above mentioned page.

    * In case the weather is the culprit of the emergency, slew the dome away from the cause if possible at all.

        * Opposite the direction of the incoming cloud front.
        * Opposite the wind gusts.
        * **There is no current strategy in case rain/snow is at place.**

#. Send the rest of the component to ``STANDBY``.
#. **Communicate** the observatory's status and details of the circumstance to the emergency contacts by sharing the information gathered, along with any additional relevant information.
#. **Await** further instructions from the management team. Management will evaluate the circumstances and determine the next steps. 

.. _Internet-down-Control-System-down:

**Internet is down or Control System is down**

The Rubin network is down and it is time to close the dome shutter as the end of the night approaches OR an unfavorable circumstance show up.

The dome is in its own network, so even if Rubin network and/or control system is down, you will be able to close the aperture shutter via the local push button. Of course, the rotating dome must be powered and with the control system on. You will be able also to rotate the dome with a laptop via the push buttons in the ADBS local box (Level 7) if the cRIO is down.

If the fixed dome network is down, you can close only plugging the laptop or touch panel in the rotating part ethernet port. Currently you can connect “your” Laptop simulating the Rubin control room to the fixed MOXA switch EDR510 and sending “your” usual high level commands to rotate the dome and, in the near future, to operate the ApS.

#. **Close aperture shutters** from the dome aperture shutter cabinet following the Aperture Shutter Opening and Closing MTDome procedure.
#. If internet or control system is recovered, and the conditions clear, you may **reconsider opening** again following the standard procedures.

.. _End-of-night-weather-worsening:

**Rubin is working fine, but you need to close at the end of the night or weather is worsening.**

Follow the Aperture Shutter Opening and Closing MTDome standard procedure.


Contingency
===========
This procedure does not contemplate a contingency plan.


This procedure was last modified |today|.


.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).
.. |author| replace:: *Alysha Shugart*
.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Observing-Constraints-Simonyi-Weather-Constraints:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. _`Gemini South`: https://www.gemini.edu/observing/telescopes-and-sites/sites/cloud-cameras/gemini-south-all-sky-camera
.. _`Environment`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/4?refresh=Paused&lower=now%28%29%20-%2015m
.. _`MT Dome Weather Monitor`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/466?refresh=Paused&lower=now%28%29%20-%2015m 
.. _`LSSTCam Cryo Dashboard`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/572?refresh=Paused&lower=now%28%29%20-%2015m 
.. _`LSST DA Slack channel`: https://discovery-alliance.slack.com/archives/C08LEHT6V40 
.. _`M1M3 air temps`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/383?refresh=15s&lower=now%28%29%20-%2015m 
.. _`RubinTV All Sky`: https://summit-lsp.lsst.codes/rubintv/summit/allsky 

.. warning::
    DRAFT

############################
Simonyi Weather Constraints
############################

.. This section should provide a brief, top-level description of the page.

This page defines the different types of operational constraints due to weather.

Operating conditions used to define the Rubin construction project are found in `LTS-54 <https://ls.st/lts-54>`__. 

As commissioning gets underway, the operating conditions will be better constrained, and different situations will apply to the Main telescope and Auxiliary Telescope.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

..    *

.. _weather-constraints-deciding-to-open:

Deciding to open
================

Observers need to pay close attention to the weather and upcoming conditions on the summit using the data from the Weather Station and Weather Forecast CSCs. 
At the time of writing, the equipment most sensistive to changes in temperature or humidity are M1M3 and LSSTCam. 
While the EAS and M1M3TS are commissioned, it is best to vent the louvers first and get the inside dome temperature to closely match the outside temperature. 
Chronograph dashboards for `Environment`_ and `MT Dome Weather Monitor`_ identify important telemetries and given a broad overview of the dew point differece limits. 

.. warning::
    If the inside and outside dome temperatures are offset by more than 2 degrees, modify the venting procedure. 
    Consider opening the dome shutters in steps.
    Vent with the louvers for more time before opening the dome. 
    If humidity is more than 60%, or the air temperature is below 4 degrees C, use extra caution before deciding to open the dome, as the mirror and camera are more sensitive to borderline conditions than other equipment.

.. note::
    `MT Dome Weather Monitor`_ and the `LSSTCam Cryo Dashboard`_ offer fundamental guidelines to decide whether to open.  
    They have dew point difference and temperature guidelines hard-coded into the dashboards. 
    Once the MTDome is open, the M1M3 temperature gradients (M1M3 EUI), M1M3TS, Fan coil units, and the `LSSTCam Cryo Dashboard`_ must be monitored carefully. 

.. _weather-constraints-wind:

Wind
====

The image quality and AOS teams will produce studies showing the winds' impact on mount motion and image quality (IQ). 
The wind limits imposed here are to limit dust blowing around violently that can scratch the mirror. 

- Wind speeds up to 15 m/s: 
    Safe operations may continue.

- Wind speeds between 15 and 18 m/s:
    Observe out of the wind, close dome louvers.

- Wind speeds over 18 m/s:
    Close dome.
    Wind speeds must remain below 15 m/s for at least 15 minutes before opening again. 

.. _weather-constraints-humidity-and-dew-point:

Humidity and dew point
======================

LSSTCam and M1M3 are the most susceptible instruments to condensation, given the sensitivity to temerpature and the fragile refrigeration system that cools the camera. 

Until the M1M3 Thermal system and EAS are commissioned, a lot of human driven monitoring is necessary to ensure that the camera can remain cold and not condense, or that it does not apply too much power to counteract temperatures below 0.

Three critical dashboard to monitor are:
- `M1M3 air temps`_
    This dashboard helps to understand the temperature shock the mirror could feel if venting or opening is done too quickly.
    The mirror temps should be within 1 degree C of ambient.
    The mirror should not change temperature at a rate faster than 1.5 degrees per hour.
    If the Thermal system or EAS is not keeping the mirror temperature stable and near ambient, stop observing and call support for assistance. 

- `MT Dome Weather Monitor`_
    This dashboard has hard-coded closure limits based on the dew point difference. 
    In the different plots, a telemetry of the TMA is monitored and compared directly to the dew point in the dome.
    If any of these limits are reached, close the dome immediately. 

- `LSSTCam Cryo Dashboard`_
    This dashboard has hard-coded closure limits based on the camera cooling and cryo systems, and their sensitivity to temperature. 
    If any of the conditons in the dashboard are met, close the dome, and call Camera support for assistance. 

.. _weather-constraints-cloud-cover:

Cloud cover
===========

LSSTCam can tolerate some extinction, but it is not as robust as AuxTel. 
We are awaiting results of pipeline reduction studies to quantify exactly what level of extinction can be tolerated.
DREAM camera published cloud maps and specs every night to a `LSST DA Slack channel`. 
This will eventually be fed into our extinction criteria and this page updated. 

The biggest threat of cloud cover is lower-atmosphere condensation, or virga, which is rain and moisture that falls from a cloud, but evaporates before it hits ground level.
Virga appears like streaks of rain or whips on the bottom of different types of cumulus clouds. 
Winds can bring this moisture into the dome, or it can condense on the dome roof and fall through the slit. 

If clouds are present in the all-sky camera displayed on `RubinTV All Sky`_ - which is mounted next to Earthcam on Piñon - be mindful of further cloud accumulation and the direction they are coming from. 

Aggregate data by going outside and looking around the sky. 
During bright time, look along the glowing cloud edges for wisps or "cloud tails".
This is virga. 

.. note::
    Take the opportunity to go outside and compare the all sky cameras to real life. 
    Look east and verify that the clouds are not covering the mountain peaks. 
    If clouds are at this low elevation, these is a moisture risk.
    Take caution before opening the telescope, or consider closing the dome if it is open.

`Gemini South`_ also has an all-sky camera. 
Use it to further verify cloud coverage over the mountains to the east. 
This camera only exposes at night - each exposure is 30 seconds.

.. _weather-constraints-moon-avoidance:

Moon avoidance
==============

.. warning::
    Moonlight can trip the HVbias of the LSSTCam, and may cause damage to sensors. 
    It will cause fault loss and need intervention from the Camera team. 
    If the scheduler is choosing targets that point close to the direction of the moon, 
        STOP observing.
        Alert support staff or change the scheduler program.

If engineering tasks are being run that are not measuring sky brightness, choose targets out of the direction of the moon. 
Be mindful of scattered moonlight during heavy cloud cover. 

This procedure was last modified |today|.
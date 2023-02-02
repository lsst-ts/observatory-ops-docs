.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Nighttime-Operations-Weather-Constraints:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. _`Gemini weather station`: https://gemini.edu/sciops/telescopes-and-sites/weather/cerro-pachon/envmon/
.. _`Gemini cloud cameras`: https://www.gemini.edu/sciops/telescopes-and-sites/weather/cerro-pachon/cloud-cam/stills.html
.. _`site webcams`: https://noirlab.edu/science/observing-noirlab/weather-webcams
.. _`SOAR weather station`: https://noirlab.edu/science/observing-noirlab/weather-webcams/cerro-pachon/environmental-conditions


###################
Weather Constraints
###################

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
^^^^^^^^^^^^^^^^
Before opening the dome to take on-sky data or for cooling, observers must take care to inspect the weather conditions.
Humidity (especially the dew point difference), cloud cover, and wind speed are the three largest determining factors for safety of the telescope and equipment. 

Observers should inspect the forecast for the night, and review the weather trends on the Rubin weather station (currently unavailable) and the `Gemini weather station`_.
The weather data updates every 2 minutes. 
The wind speed data reported is the average over the previous 10 minutes. 

NOIRLab also hosts additional links to Cerro Pachón weather, including `site webcams`_, and the `SOAR weather station`_. 

Go outside and look for incoming cloud fronts, and inspect the buildings and cars for condensation if humidity is above 70%.
Be more cautious to open if there will not be someone in the control room to montior changing weather conditions, e.g. opening before going to dinner, or leaving the control room to complete another task.

.. warning::
    Vent gates:
        The vent gates on the first floor of the AuxTel dome are not rated for high winds. 
        The vent gates MUST be closed if the wind speed (gusts and sustained) is above 8 m/s.



.. note::
    Extraction fan use:
        The extraction fan on vent gate 3 can operate at 50-100% power for initial cooling. 
        During on-sky operations, the extraction fan must be run at 20-25% power.
        If winds are over 8 m/s, the extraction fan must be turned off and the vent gate must be closed.
        If humidity is rising quickly, or >= 65%, (to be revised) the extraction fan should be turned off to avoid drawing in more moisture through the dome. 

.. _weather-constraints-wind:

Wind
^^^^
The predominant wind direction at the summit is from the northwest or ~300 degrees.  
The majority of the time, the wind comes up from the coast and blows through the Elqui River valley, arriving to the summit. 
If the direction changes frequently, or has completely changed direction from 300 degrees, use caution as this likely indicates a frontal system and unstable atmospheric conditions.

Wind speeds less than 12 m/s (average):
    - This is safe operation range for AuxTel. 
        No restrictions in observing are needed. 
        
Wind speeds between 12 and 15 m/s (average):
    - If the observer has control to choose targets, observe out of the wind.
        Report that the scheduler configuration needs to be changed, or the observing program should be changed. 
        Avoid targets that are pointing direction into or 180 degree opposite of the dominant direction of the wind.

.. note::
    90 degree rule:
        Due to the curved dome, pointing at targets 180 degrees offset from the dominant wind direction creates a wind eddy under the lip of the dome, which can create wind shake on the upper truss of AuxTel. 
        To compensate for this, it is recommended to look for targets that have a 90-degree offset from the dominant wind direction. 

Wind speeds greater than 15 m/s (average):
    - Observers should consider closing once wind gusts (isolated data points) have become greater than 15 m/s. 
        Sustained winds (gusts averaged over 10 minutes) of more than 15 m/s should initiate telescope closure. 
        Before deciding to open again, ensure that sustained winds have dropped below the closure limits for more than 15 minutes. 
        The timer resets every time a wind data point is over 15 m/s.

.. warning::
    Dome drop-down shutter:
        The AuxTel dome shutter has a drop-down shutter that opens like a flap, causing it to extend further past the dome structure. 
        It is opened when observing targets below 25-30 degrees elevation. 
        The drop-down shutter is suceptible to wind gusts, and should be closed if gusts reach over 10 m/s.

.. _weather-constraints-humidity-and-dew-point:

Humidity and dew point
^^^^^^^^^^^^^^^^^^^^^^

Higher relative humidity is not an absolute determination of closure, but observers must pay close attention when humidity is over 70%, or if it begins to suddenly trend upward.

Humidity above 65%:
    - Turn off the extraction fan and close vent gates.

Humidity above 70%:
    - Observers must treat this range with extra caution. 
        Take time to go outside and inspect vehicles, buildings, and look for falling drops from the roof. 
        Be mindful of local humidity changes between AuxTel and the main telescope building.
        Because AuxTel is more exposed, there is more air mixing which creates a small buffer against condensation compared to the Rubin building.
        If the ambient temperature is cooler, especially during winter time, the condensation risk on metal surfaces is higher. 

The quantity that is more important than relative humidity is the **dew point temperature** and the **dew point difference**. 
The dew point temperature is the ambient air temperature at which relative humidity will reach 100% - the air is completely saturated with water vapor.
The dew point difference is the difference between the dew point temperature and the coldest structure in the telescope dome. 

Example:
    Dew point temperature = 8 degrees C.

    AuxTel M1 temperature = 11 degrees C.
    
    Glycol lines = 4 degrees C.
    
    **Dew point difference = 4 degrees C.**

In the example, the dew point difference is 4 degrees C, which is in safe operational range. 
For any object or strucutre that is above the dew point temperature, there is less condensation risk.
Water condenses on the coldest surface. 

Dew point difference is > 2.5 degrees C:
    - Normal operations may continue.

Dew point difference is between 2 degrees and 2.5 degrees C:
    - Observers must consider closing. 
        Go outside and check condensation on buildings and vehicles. 
        If wet, advise to close.

Dew point difference is 2 degrees C or less:
    - Close immediately. 

Observers must wait for the dew point temperature or humidity to recover from the closure limits for at least 15 minutes before opening again. 

.. note::
    If humidity has dropped during the night, before opening the dome slit, consider performing a quick dome drain procedure. 
    Rotate the closed dome several times in both directions, exercisicing large slews. 
    This can remove some of the water droplets that might have accumulated on the metal surface. 

.. _weather-constraints-cloud-cover:

Cloud cover
^^^^^^^^^^^

Until DIMM flux measurements are imported into Rubin TV or in the EFD, or the wavefront sensors of LSSTCam are available, determining safe or unsafe cloud coverage is a bit of an un-tested process.

AuxTel has continued observing happily in 2.5 magnitudes of extinction, given that most targets are typically <= 8 magnitudes.

The biggest threat of cloud cover is lower-atmosphere condensation, or virga, which is rain and moisture that falls from a cloud, but evaporates before it hits ground level.
Virga appears like streaks of rain or whisps on the bottom of different types of cumulus clouds. 
Winds can bring this moisture into the dome, or it can condense on the dome roof and fall through the slit. 

If clouds are present in the all-sky camera - which is mounted next to AuxTel on Calibartion Hill - be mindful of further cloud accumulation and the direction they are coming from. 

The `Gemini cloud cameras`_ are useful to evaluate how low the clouds are. 
Cloud camera images update every 30 seconds during the night. 
The Gemini cloud cameras begin exposing when the sun is ~6 degrees below horizon.
In the North East camera, verify that the clouds are not below the mountain peaks. 
If clouds are at this low elevation, and they are also overhead the telescope, these is a moisture risk.

.. note::
    The Gemini cloud cameras and the all-sky cameras do not always represent reality. 
    Due to the longer exposure times, stars can appear brighter in the images, so extinction is not as bad as it seems.
    If possible, take the opportunity to go outside and compare the cloud cameras to real life. 

.. _weather-constraints-moon-avoidance:

Moon avoidance
^^^^^^^^^^^^^^

If the scheduler is choosing targets that point directly into the direction of the moon, alert support staff or change the scheduler program.
If engineering tasks are being run that are not measuring sky brightness, choose targets out of the direction of the moon. 
Be mindful of scattered moonlight during heavy cloud cover. 
Data may be degraded. 
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
.. _Nighttime-Operations-Sky-Almanac:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########
Sky Almanac
###########

.. _Sky-Almanac-Overview:

Overview
========

The sky almanac is a useful tool to plan and monitor observations. It provides sunrise/setting times and the beginning/end of each twilight. 
It also informs of the position in the sky of Solar System objects along with plots of elevation vs time of selected targets. 

  * Located in the **ts_notebooks** GitHub repository, use the following notebook to access the sky almanac observing tool:
          `Sky Almanac <https://github.com/lsst-ts/ts_notebooks/blob/develop/procedures/observing_tools/Sky%20Almanac.ipynb>`__

  * An online interface with astronomical ephemeris data and daily elevation charts for your chosen targets. 
          `htpps://airmass.org/ <https://airmass.org/chart/obsid:gems/date:2023-04-25/sso:s3ASun>`__

.. _Sky-Almanac-Get-Sun-Coordinates:

Get Sun Coordinates
===================

Replace the time (in UTC) and run the following code in your notebook to obtain the Sun's azimuth and elevation at your requested time. 

.. code-block:: python

    from astropy import coordinates as coord
    from astropy.time import Time

    # Vera Rubin Coordinates from https://www.lsst.org/scientists/keynumbers
    rubin_obs = coord.EarthLocation(
        lat='-30:14:40.68', lon='-70:44:57.90', height=2647 * u.m)

    # Define time in UTC here
    time = Time("2023-04-25T17:00:00", format="isot", scale="utc")

    # Some calculations
    sun_coordinates = coord.get_sun(time)
    sun_coordinates.location = rubin_obs
    where_sun = "setting" if (sun_coordinates.altaz.az.value > 180) else "rising"

    # Print results
    print(f" The azimuth of the {where_sun} Sun at {time} is {sun_coordinates.altaz.az.value:.2f} deg \n"
          f" The elevation of the Sun at {time} is {sun_coordinates.altaz.alt.value:.2f} deg")

.. _Sky-Almanac-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.
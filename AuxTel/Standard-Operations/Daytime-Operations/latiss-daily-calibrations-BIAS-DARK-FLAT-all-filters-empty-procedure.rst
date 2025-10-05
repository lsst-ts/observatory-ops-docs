.. _`RubinTV`: https://summit-lsp.lsst.codes/rubintv/summit/auxtel 
.. _cp_verify: https://github.com/lsst/cp_verify
.. _butler: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/index.html
.. _collection: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/organizing.html
.. _BLOCK source code: https://github.com/lsst-ts/ts_config_ocs/blob/develop/Scheduler/observing_blocks_auxtel/block-295-latiss_daily_calibrations.json
.. _AuxTel (LATISS) Temperatures and Pressures dashboard: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/14


.. |author| replace:: *Karla Peña Ramírez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Erik Dennihy, Paulo Lago, Kristopher Mortensen*


.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure:

##################################################################
LATISS Daily Calibrations BIAS, DARK and FLAT: all filters + empty
##################################################################

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Overview:

Overview
========
This procedure will enable and turn on the ATWhiteLight that illuminates the dome flat screen. It will position the telescope and dome in the FLAT position, and will take BIAS, DARK, and FLATS calibrations images in all installed filters including the empty filter. Finally will turn off the white light and send the ATWhiteLight to ``STANDBY``. After the entire script completion, the telescope and dome will remain in ``ENABLED`` state and in the FLAT field position. The observer can decide whether to vent, proceed to on-sky or shutdown.

This page assumes the reader is familiar with the content explained in the Observatory section: :ref:`Introduction to the combined calibrations generation procedure <Introduction-Combined-Calibrations-Generation-index>` 

.. warning::
  This procedure involves telescope motion with AuxTel. Be sure to confirm the dome is clear of personnel (in situ or using the webcams) and announce that you are going to run the calibrations with telescope movement on the *#summit-announce* and *#summit-auxtel* channels before you run the following steps. The Daytime calibrations can be taken at any time or under any conditions when convenient, and they by default do not include the use of the Electrometer, Monochromator, or FiberSpectrograph CSCs, these can remain in ``STANDBY`` while running. 



.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Post-Conditions:
Post-Condition
==============
- Individual calibration images will be taken and verified using the `cp_verify`_ framework.
- If ``generate_calibrations`` is ``True``, a (daily) combined calibration image per detector will be certified in a `butler`_ ``CALIBRATION`` `collection`_.


.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure-Steps:
Procedure Steps
===============

#. Enable ATCS and LATISS using the standard scripts :file:`enable_atcs.py` and :file:`enable_latiss.py` with no configuration. 
#. Enable ``Scheduler:2`` with a valid scheduler configuration. Use the standard script :file:`auxtel/scheduler/enable.py` with the configuration specified in the AuxTel Scheduler-Driven Survey Test Case (BLOCK-T19). 
#. **Setup LATISS calibrations** BLOCK will setup ATCS and white light for calibrations. It enables and turns on the ATWhiteLight, enables OCPS:1 and commands AuxTel mount and dome to the FLAT position. Run the script :file:`add_block.py` to the ATQueue  with the following configuration:

    .. code-block:: text
      :caption: :file:`add_block.py`

      id: BLOCK-309

    The BLOCK with :file:`setup_latiss_calibrations` configuration will queue the scripts aimed to setup the system. It will start with the :file:`set_summary_state.py` script to enable ATWhiteLight CSC with the following configuration:

    .. code-block:: text
      :caption: :file:`set_summary_state.py`
    
      data:
        -
          - ATWhiteLight 
          - ENABLED 

    The :file:`set_summary_state.py` script will enable ``OCPS:1`` CSC.

    .. code-block:: text
      :caption: :file:`set_summary_state.py`
    
      data:
        -
          - OCPS:1
          - ENABLED

    The SAL script :file:`auxtel/calibrations/power_on_atcalsys.py` with no configuration inserted into the BLOCK :file:`setup_latiss_calibrations` structure will start the chiller, turn on the white light and open the shutter.  This script takes 15 minutes to complete, the time it takes to warm up the white light. On Chronograf using the query :file:`lsst.sal.ATWhiteLight.logevent_logMessage.message`, the lamp reports its retry loop status explicitly.

    .. code-block:: text
      :caption: :file:`auxtel/calibrations/power_on_atcalsys.py`

    The :file:`auxtel/prepare_for/flat.py` script (empty configuration) will position the telescope and dome in FLAT position. The telescope will point towards the dome flat screen (mount Az = 188.7 deg, mount El = 39.0 deg, dome Az= 2.59 deg). Confirm in the cameras "aux-cam01" or "aux-cam02" that the white light is on, and telescope is pointing to the dome flat screen.

    .. code-block:: text
      :caption: :file:`auxtel/prepare_for/flat.py`
  
    .. Note: We need to document and link here how to access the aux-cam01/02cameras.

#. The **LATISS daily calibrations** BLOCK will queue the scripts focused on the calibration image acquisition. Run the script :file:`add_block.py` to the ATQueue  with the following configuration:

    .. code-block:: text
      :caption: :file:`add_block.py`

      id: BLOCK-295


    Depending on which filters are currently installed in LATISS, the :file:`auxtel/make_latiss_calibrations.py` script may take different calibration sets. The calibration images displayed in `RubinTV`_ are post-ISR images and should have BIAS and DARK corrections applied. This means that BIAS and DARK images should display with maximum count rates of about 10 ADUs. In the case of FLAT images, counts must be below the :math:`\approx` 30000 ADUs. In the process of building the daily PTC (see below), the FLAT saturation is intended and achieved at around the 123000 ADUs (with an exposure time of about 25 seconds). In case daily FLATS are taken, they reach values of :math:`\approx` 68000 ADUs. If you see large deviations from these values, which could be related with a problem in the instrument signature removal in `RubinTV`_, then RAW count rates are being displayed, please report it. The calibration sets and their configurations can change depending on specific requirements (e.g. usage of filters BG40, OG550). Below it is listed the regular configuration sets.

    1. **: Set configuration for SDSSr_65mm.**

    .. code-block:: text
      :caption: :file:`auxtel/make_latiss_calibrations.py`

        n_flat: 20
        exp_times_flat: 6
        script_mode: BIAS_DARK_FLAT
        filter: SDSSr_65mm
        grating: empty_1

    2. **: Set configuration for SDSSg_65mm.**

    .. code-block:: text
      :caption: :file:`auxtel/make_latiss_calibrations.py`

        n_bias: 3
        n_dark: 3
        exp_times_dark: 6
        n_flat: 20
        exp_times_flat: 6
        script_mode: BIAS_DARK_FLAT
        filter: SDSSg_65mm
        grating: empty_1


    3. **: Set configuration for SDSSz_65mm.**

    .. code-block:: text
      :caption: :file:`auxtel/make_latiss_calibrations.py`

        n_bias: 3
        n_dark: 3
        exp_times_dark: 6
        n_flat: 20
        exp_times_flat: 3
        script_mode: BIAS_DARK_FLAT
        filter: SDSSz_65mm
        grating: empty_1


    4. **: Set configuration for SDSSy_65mm.**

    .. code-block:: text
      :caption: :file:`auxtel/make_latiss_calibrations.py`

        n_bias: 3
        n_dark: 3
        exp_times_dark: 6
        n_flat: 20
        exp_times_flat: 30
        script_mode: BIAS_DARK_FLAT
        filter: empty_1
        grating: SDSSy_65mm

    5. **: Set configuration for empty_1.**

    .. code-block:: text
      :caption: :file:`auxtel/make_latiss_calibrations.py`

        n_bias: 3
        n_dark: 3
        exp_times_dark: 1
        n_flat: 20
        exp_times_flat: 1
        script_mode: BIAS_DARK_FLAT
        filter: empty_1
        grating: empty_1

    6. **: Set sequence for the daily Photon Transfer Curve (PTC). Skip it if the previous sets were queued manually.**

    .. code-block:: text
      :caption: :file:`auxtel/take_image_latiss.py`

        image_type: FLAT
        filter: SDSSr_65mm
        grating: empty_1
        reason: daily_PTC
        exp_times:
                0.25,
                0.25,
                1.42,
                1.42,
                6.53,
                6.53,
                4.23,
                4.23,
                30.04,
                30.04,
                12.56,
                12.56,
                57.75,
                57.75,
                8.13,
                8.13,
                2.73,
                2.73,
                3.40,
                3.40,
                1.77,
                1.77,
                111.03,
                111.03,
                37.35,
                37.35,
                0.48,
                0.48,
                0.59,
                0.59,
                10.10,
                10.10,
                1.14,
                1.14,
                0.20,
                0.20,
                89.29,
                89.29,
                71.81,
                71.81,
                0.38,
                0.38,
                0.31,
                0.31,
                19.43,
                19.43,
                2.20,
                2.20,
                15.62,
                15.62,
                0.92,
                0.92,
                0.74,
                0.74,
                24.16,
                24.16,
                5.25,
                5.25,
                46.44,
                46.44

#. The **Shutdown LATISS calibrations** BLOCK will turn off the calibration lamp and leave it on standby state. Run the script :file:`add_block.py` to the ATQueue  with the following configuration:

    .. code-block:: text
      :caption: :file:`add_block.py`

      id: BLOCK-310


    The BLOCK with :file:`shutdown_latiss_calibrations` configuration finishes with the :file:`auxtel/calibrations/power_off_atcalsys.py` SAL script with no configuration. It will turn off the lamp, close the shutter and shutdown the chiller. At this stage, the script completion time is 15 minutes.

    .. code-block:: text
      :caption: :file:`auxtel/calibrations/power_off_atcalsys.py`

    Finally, the :file:`set_summary_state.py` script sends ATWhiteLight back to ``STANDBY``.

    .. code-block:: text
      :caption: :file:`set_summary_state.py`

        data:
          -
           - ATWhiteLight
           - STANDBY

Once the last script is done, check the camera to make sure the white light is off. At this point, ATCS and LATISS are in ``ENABLED`` state and the dome and telescope are in FLAT position.

.. note::
   The location of the `BLOCK source code`_ can be checked and if the filters or exposures times have changed, create a ticket for yourself and edit this document accordingly.


.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Contingency:

Contingency
===========
In cases such as telescope and dome movement not allowed or not cleared, or not enough time available for calibrations, skip this procedure.


This procedure was last modified |today|.
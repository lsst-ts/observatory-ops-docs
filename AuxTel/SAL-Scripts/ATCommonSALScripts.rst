.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Kristopher Mortensen*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Karla Peña, Ioana Sotuela Elorriaga, Kate Napier*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Common-LOVE-SAL-Scripts-and-Configurations:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#################################################
Common AuxTel Scripts & Configurations
#################################################

.. _table-information-section:

The following tables display the common SAL scripts used during operations with the Auxilary Telescope. 
These scripts are compatible with the LOVE ATQueue interface and include lower-level commands using ``run_command.py``. 
The tables contain the following information:

1. A simple description of the action/command that the script initiates to the appropriate CSCs.
2. The script name to search for in the ScriptQueue as well as a link to its GitHub documentation.
3. | Examples of common SAL script and/or ``run_command.py`` configurations. 
   | Scripts that require empty configurations are labeled as *"No configurations."*

.. _general-procedures:

General Procedures
==================

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Change summary state 
     - | ``set_summary_state.py``
       | `ts_standardscripts/set_summary_state.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/set_summary_state.py>`_ 
     -
       .. dropdown:: SAL Script

         To transition ATDome to ENABLED:

         .. code-block:: text
                
           data: 
             - 
               - ATDome
               - ENABLED
  
         Or to transition AuxTel’s scheduler to STANDBY:

         .. code-block:: text

           data: 
             - 
               - Scheduler:2
               - STANDBY

         Multiple states can be set using lists and summary states are case blind:

         .. code-block:: text

           data: 
             - [ATDome, enabled]
             - [Scheduler:2, STANDBY]

       .. dropdown:: run_command.py

         To transition ATDome to ENABLED:

         .. code-block:: text
                 
           component: ATDome
           cmd: enable

         Or to transition AuxTel’s scheduler to STANDBY:

         .. code-block:: text

           component: Scheduler:2
           cmd: standby
         
         **NOTE:** These commands are case sensitive.

   * - AT daytime checkouts
     - | **LATISS:**
       | ``auxtel/daytime_checkout/latiss_checkout.py``
       | `ts_standardscripts/daytime_checkout/latiss_checkout.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/daytime_checkout/latiss_checkout.py>`_ 
       |
       | **ATPneumatics:**
       | ``auxtel/daytime_checkout/atpneumatics_checkout.py``
       | `ts_standardscripts/daytime_checkout/atpneumatics_checkout.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/daytime_checkout/atpneumatics_checkout.py>`_ 
       |
       | **Telescope and Dome:**
       | ``auxtel/daytime_checkout/telescope_and_dome_checkout.py``
       | `ts_standardscripts/daytime_checkout/telescope_and_dome_checkout.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/daytime_checkout/telescope_and_dome_checkout.py>`_ 
       |
       | **Slew and Take Image:**
       | ``auxtel/daytime_checkout/slew_and_take_image_checkout.py``
       | `ts_standardscripts/daytime_checkout/slew_and_take_image_checkout.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/daytime_checkout/slew_and_take_image_checkout.py>`_ 
     - No configurations
   * - AT ``prepare_for`` sequences
     - | **Venting:**
       | ``auxtel/prepare_for/vent.py``
       | `ts_standardscripts/prepare_for/vent.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/prepare_for/vent.py>`_ 
       |
       | **Flats:**
       | ``auxtel/prepare_for/flat.py``
       | `ts_standardscripts/prepare_for/flat.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/prepare_for/flat.py>`_ 
       |
       | **On Sky:**
       | ``auxtel/prepare_for/onsky.py``
       | `ts_standardscripts/prepare_for/onsky.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/prepare_for/onsky.py>`_ 
       |
       | **CO2 Clean-Up:**
       | ``auxtel/prepare_for/co2_cleanup.py``
       | `ts_standardscripts/prepare_for/co2_cleanup.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/prepare_for/co2_cleanup.py>`_ 
     - No configurations  
   * - AT shutdown sequence
     - | ``auxtel/shutdown.py``
       | `ts_standardscripts/data/scripts/auxtel/shutdown.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/shutdown.py>`_
     - No configurations

.. _auxtel-scheduler:

AuxTel Scheduler
================

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - **Scheduler.2**
     - Enable/Resume/Stop scheduler
     - | **Enable:** 
       | ``auxtel/scheduler/enable.py``
       | `ts_standardscripts/scheduler/enable.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/scheduler/enable.py>`_
       |
       | **Resume:** 
       | ``auxtel/scheduler/resume.py``
       | `ts_standardscripts/scheduler/resume.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/scheduler/resume.py>`_
       |
       | **Stop:** 
       | ``auxtel/scheduler/stop.py``
       | `ts_standardscripts/scheduler/stop.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/scheduler/stop.py>`_
     -
       .. dropdown:: SAL Script

         The scripts ``resume.py`` and ``stop.py`` do not require configurations. However, ``enable.py`` may require various ``.yaml`` files for configuration.

         Daytime Calibrations (consistent):

         .. code-block:: text

           config: auxtel_fbs_image_photocal.yaml
                    
         Nightime Operations (varies):
             
         .. code-block:: text

           config: example_auxtel_survey.yaml

       .. dropdown:: run_command.py

         See :ref:`Change Summary State <general-procedures>` 
         for configuration on enabling the scheduler. The resume and stop states are ``cmd: resume`` and ``cmd: stop``, respectively.
         To load a configuration into the scheduler before enabling ATScheduler:

         .. code-block:: text
                 
           component: Scheduler:2
           cmd: load
           parameters:
             uri: example_config.yaml

   * -
     - Run block from scheduler
     - | ``auxtel/scheduler/add_block.py``
       | `ts_standardscripts/scheduler/add_block.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/scheduler/add_block.py>`_
     -
       .. dropdown:: SAL Script

         For the ATScheduler, to run a certain cofiguration (e.g., ``block_name``) use configuration:

         .. code-block:: text

           id: block_name

       .. dropdown:: run_command.py

         For the ATScheduler, to run the configuration ``block_name`` use configuration:
             
         .. code-block:: text
 
           component: Scheduler:2
           cmd: addBlock
           parameters:
             id: block_name

.. _auxtel-ATCS:

ATCS
====

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - 
     - Enable/Standby all ATCS CSCs
     - | **Enable:** 
       | ``auxtel/enable_atcs.py``
       | `ts_standardscripts/data/scripts/auxtel/enable_atcs.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/enable_atcs.py>`_
       |
       | **Standby:** 
       | ``auxtel/standby_atcs.py``
       | `ts_standardscripts/data/scripts/auxtel/standby_atcs.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/standby_atcs.py>`_
     - No configurations
   * - **ATMCS**
     - AT change Nasmyth to port 1
     - | ``run_command.py``
       | `ts-xml.lsst.io/ATMCS_setinstrumentport <https://ts-xml.lsst.io/sal_interfaces/ATMCS.html#setinstrumentport>`_
     - 
       .. dropdown:: run_command.py

         To change Nasmyth to port 1:
         
         .. code-block:: text
        
           component: ATMCS
           cmd: setInstrumentPort
           parameters:
             port: 1

   * - **ATPtg**
     - AT move mount to new azimuth or elevation
     - | ``auxtel/point_azel.py``
       | `ts_standardscripts/data/scripts/auxtel/point_azel.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/point_azel.py>`_
     -      
       .. dropdown:: SAL Script

         To move mount to a specific position az = 88 deg and el = 80 deg:

         .. code-block:: text

           az: 88
           el: 80

         To specify additional parameters like telescope rotation or slew timeout:

         .. code-block:: text

           rot_tel: 0
           slew_timeout: 240
           az: 88
           el: 80

       .. dropdown:: run_command.py

         To move the mount to a specific az/el position:

         .. code-block:: text
                 
           component: ATPtg
           cmd: azElTarget
           parameters:
             azDegs: 88
             elDegs: 80

   * - 
     - AT enable/disable tracking
     - | **Enable:**
       | ``auxtel/track_target.py``
       | `ts_standardscripts/atdome/track_target.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/track_target.py>`_
       |
       | **Disable:**
       | ``auxtel/stop_tracking.py``
       | `ts_standardscripts/atdome/stop_tracking.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/stop_tracking.py>`_
     -
       .. dropdown:: SAL Script

         To move mount to a specific ra/dec position and track that target:

         .. code-block:: text

             slew_icrs:
               ra: 5.465
               dec: -69.10

         To instead locate an object with az/el:

         .. code-block:: text
                
             track_azel:
               az: 132
               el: 45
                  
         Other options such as ``slew_planet`` and ``slew_ephem`` are available.

       .. dropdown:: run_command.py

         To move the mount to a specific az/el position:

         .. code-block:: text
                 
           component: ATPtg
           cmd: azElTarget
           parameters:
             azDegs: 132
             elDegs: 45

         Once we move, we can then start tracking:

         .. code-block:: text

           component: ATPtg
           cmd: startTracking

         To disable tracking, change command to ``cmd: stopTracking``.

   * - 
     - AT correct pointing
     - | ``auxtel/correct_pointing.py`` 
       | `ts_externalscripts/auxtel/correct_pointing.py <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/auxtel/correct_pointing.py>`_
     - 
       .. dropdown:: SAL Script

         To specify the az/el position as well as the filter:
  
         .. code-block:: text

          filter: SDSSr_65mm
          az: 270
          el: 80

   * - **ATDome**
     - AT open/close main dome shutter door
     - | **Open:**
       | ``auxtel/atdome/open_dome.py``
       | `ts_standardscripts/atdome/open_dome.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/open_dome.py>`_
       |
       | **Close:**
       | ``auxtel/atdome/close_dome.py``
       | `ts_standardscripts/atdome/close_dome.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/close_dome.py>`_
     -  
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

         To open dome main shutter door:

         .. code-block:: text

           component: ATDOME
           cmd: moveShutterMainDoor
           parameters:
             open: True

         To close the main sutter door, change parameter to ``open: False``.
 
   * - 
     - AT open/close dome dropout shutter
     - | **Open:**
       | ``auxtel/atdome/open_dropout_door.py``
       | `ts_standardscripts/atdome/open_dropout_door.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/open_dropout_door.py>`_
       |
       | **Close:**
       | ``auxtel/atdome/close_dropout_door.py``
       | `ts_standardscripts/atdome/close_dropout_door.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/close_dropout_door.py>`_
     -  
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

         To open the dropout door:

         .. code-block:: text

           component: ATDOME
           cmd: moveShutterDropoutDoor
           parameters:
             open: True

         To close the dropout door, change parameter to ``open: False``. 

   * - 
     - Home dome
     - | ``auxtel/atdome/home_dome.py``
       | `ts_standardscripts/atdome/home_dome.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/home_dome.py>`_
     -  
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

         To home the dome:

         .. code-block:: text

           component: ATDome
           cmd: homeAzimuth

   * - 
     - Slew dome
     - | ``auxtel/atdome/slew_dome.py``
       | `ts_standardscripts/atdome/slew_dome.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/slew_dome.py>`_
     -  
       .. dropdown:: SAL Script

         To move dome to a new azimuth:

         .. code-block:: text

           az: 180

       .. dropdown:: run_command.py

         To move dome to a new azimuth:

         .. code-block:: text

           component: ATDome
           cmd: moveAzimuth
           parameters:
             azimuth: 180

   * - **ATDomeTrajectory**
     - AT enable/disable dome following
     - | **Enable:**
       | ``auxtel/atdome/enable_dome_following.py``
       | `ts_standardscripts/atdome/enable_dome_following.py  <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/enable_dome_following.py>`_
       | **Disable:**
       | ``auxtel/atdome/disable_dome_following.py``
       | `ts_standardscripts/atdome/disable_dome_following.py  <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/atdome/disable_dome_following.py>`_
     -        
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

         To enable dome following:

         .. code-block:: text

           component: ATDomeTrajectory
           cmd: setFollowingMode
           parameters:
             enable: True
              
         To disable dome following, change parameter ``enable: False``.

   * - **ATAOS**
     - Enable/Disable ATAOS corrections
     - | **Enable:**
       | ``auxtel/enable_ataos_corrections.py``
       | `ts_standardscripts/data/scripts/auxtel/enable_ataos_corrections.py  <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/enable_ataos_corrections.py>`_
       |
       | **Disable:**
       | ``auxtel/disable_ataos_corrections.py``
       | `ts_standardscripts/data/scripts/auxtel/disable_ataos_corrections.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/disable_ataos_corrections.py>`_
       
       .. warning::
         Only run these scripts when the telescope is at high elevation :math:`(\geq 70^{\circ})`.

     -  
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

         To enable ATAOS:

         .. code-block:: text

           component: ATAOS
           cmd: enableCorrection
           parameters:
             hexapod: true
             m1: true
             atspectrograph: true
              
         To disable ATAOS, change the command to ``cmd: disableCorrection``.
   * - 
     - AT clear ATAOS offsets (x, y, z or all)
     - | ``auxtel/offset_ataos.py``
       | `ts_standardscripts/data/scripts/auxtel/offset_ataos.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/offset_ataos.py>`_
     -  
       .. dropdown:: SAL Script

         To reset all offsets:

         .. code-block:: text

           reset_offsets: "all"

         You can replace ``"all"`` by the individual axes you'd like to reset but they must be passed as an array of strings:

         .. code-block:: text

           reset_offsets: ["x","y"]

       .. dropdown:: run_command.py

         To reset a specific axis:

         .. code-block:: text

           component: ATAOS
           cmd: resetOffset
           parameters:
             axis: x

         To reset all of the axes, change parameter ``axis: all``.


   * - **ATPneumatics**
     - Open/Close M1 cover
     - | ``run_command.py``
       | `ts-xml.lsst.io/ATPneumatics_openm1cover  <https://ts-xml.lsst.io/sal_interfaces/ATPneumatics.html#openm1cover>`_
     - 
       .. dropdown:: run_command.py

         To open the M1 cover:

         .. code-block:: text

            component: ATPneumatics
            cmd: openM1Cover

         To close the cover:

         .. code-block:: text

           component: ATPneumatics
           cmd: closeM1Cover

.. _auxtel-LATISS:

LATISS
======

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - 
     - Enable/Standby all LATISS CSCs
     - | **Enable:** 
       | ``auxtel/enable_latiss.py``
       | `ts_standardscripts/data/scripts/auxtel/enable_latiss.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/enable_latiss.py>`_
       |
       | **Standby:** 
       | ``auxtel/standby_latiss.py``
       | `ts_standardscripts/data/scripts/auxtel/standby_latiss.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/standby_latiss.py>`_
     - No configurations
   * - **ATCamera**
     - Take image with camera
     - | ``auxtel/take_image_latiss.py``
       | `ts_standardscripts/data/scripts/auxtel/take_image_latiss.py  <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/take_image_latiss.py>`_
     -  
       .. dropdown:: SAL Script

         To specify the type of image (``BIAS``, ``DARK``, ``FLAT``, ``OBJECT``, etc.):

         .. code-block:: text

            image_type: BIAS

         To change the number of images and their exposure lengths:

         .. code-block:: text

            nimages: 5
            exp_times: 60
              
         To select a specific filter and/or grating for imaging (see `LATISS Status <https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/23?refresh=Paused&lower=now%28%29%20-%2015m>`_ on Chronograph):

         .. code-block:: text

            filter: FILTER_NAME_OR_ID
            grating: GRATING_NAME_OR_ID

       .. dropdown:: run_command.py

          To take a select number of images with specified exposure times:

          .. code-block:: text

            component: ATCamera
            cmd: takeImages
            parameters:
              numImages: 5
              expTime: 60

   * -
     - Generate Combined Calibrations
     - | ``auxtel/make_latiss_calibrations.py``
       | `ts_externalscripts/auxtel/make_latiss_calibrations.py <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/auxtel/make_latiss_calibrations.py>`_
     -  
       .. dropdown:: SAL Script

         The full list of configuration parameters are found under `AuxTel Daytime Operations <https://obs-ops.lsst.io/AuxTel/Standard-Operations/Daytime-Operations/latiss-combined-calibrations-procedure.html>`_.

       .. dropdown:: run_command.py

          To enable calibration:

          .. code-block:: text

              component: ATCamera
              cmd: enableCalibration

          To disable calibration:

          .. code-block:: text

              component: ATCamera
              cmd: disableCalibration

   * - **ATSpectrograph**
     - Optical alignment of AT with LATISS
     - | **WEP:**
       | ``auxtel/latiss_wep_align.py``
       | `ts_externalscripts/auxtel/latiss_wep_align.py <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/auxtel/latiss_wep_align.py>`_
       |
       | **CWFS:**
       | ``auxtel/latiss_cwfs_align.py``
       | `ts_externalscripts/auxtel/latiss_cwfs_align.py <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/auxtel/latiss_cwfs_align.py>`_
     - 
       .. dropdown:: SAL Script 
        
         The WEP script does not require a configuration schema for alignment.
         With the CWFS script, one can select an az/el position in the sky and limit the magnitude for source finding:

         .. code-block:: text

            find_target:
             az: 100.0
             el: 60.0
             mag_limit: 8

.. _calibration-systems:

Calibration Systems
===================

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - **ATWhiteLight**
     - Power on/off calibration lamp
     - | **Turn On:**
       | ``auxtel/calibrations/power_on_atcalsys.py``
       | `ts_standardscripts/calibrations/power_on_atcalsys.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/calibrations/power_on_atcalsys.py>`_
       |
       | **Turn Off:**
       | ``auxtel/calibration/power_off_atcalsys.py``
       | `ts_standardscripts/calibrations/power_off_atcalsys.py <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/data/scripts/auxtel/calibrations/power_off_atcalsys.py>`_
     - 
       .. dropdown:: SAL Script

         No configurations

       .. dropdown:: run_command.py

          To power on calibration lamp:

          .. code-block:: text
                 
            component: ATWhiteLight
            cmd: turnLampOn

          To power off calibration lamp:

          .. code-block:: text

            component: ATWhiteLight
            cmd: turnLampOff


.. _support-and-monitoring:

Support & Monitoring
====================

.. list-table::
   :width: 100
   :widths: auto
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - **ATBuilding** 
     - Change extraction fan control to CSC or Manual mode
     - | ``run_command.py``
       | `ts-xml.lsst.io/ATBuilding_setFanMode  <https://ts-xml.lsst.io/sal_interfaces/ATBuilding.html#setextractionfanmanualcontrolmode>`_
     - 
       .. dropdown:: run_command.py

          * To change extraction fan to **CSC control**:

          .. code-block:: text
                
            component: ATBuilding
            cmd: setExtractionFanManualControlMode
            parameters:
              enableManualControlMode: False

          * To change extraction fan to **Manual control**:

          .. code-block:: text
                
            component: ATBuilding
            cmd: setExtractionFanManualControlMode
            parameters:
              enableManualControlMode: True
   * - 
     - Open/Close Vent Gate #3
     - | ``run_command.py``
       | `ts-xml.lsst.io/ATBuilding_setVentGate  <https://ts-xml.lsst.io/sal_interfaces/ATBuilding.html#closeventgate>`_
     - 
       .. dropdown:: run_command.py

          * To **Open** vent gate #3:

          .. code-block:: text
                
            component: ATBuilding
            cmd: openVentGate
            parameters:
              gate: [2, -1, -1, -1]

          * To **Close** vent gate #3:

          .. code-block:: text
                
            component: ATBuilding
            cmd: closeVentGate
            parameters:
              gate: [2, -1, -1, -1]
   * - 
     - Turn On/Off the extraction fan
     - | ``run_command.py``
       | `ts-xml.lsst.io/ATBuilding_setvFanDriveFreq  <https://ts-xml.lsst.io/sal_interfaces/ATBuilding.html#setextractionfandrivefreq>`_
     - 
       .. dropdown:: run_command.py

          * To **Turn On** extraction fan at **20Hz**:

          .. code-block:: text
                
            component: ATBuilding
            cmd: setExtractionFanDriveFreq
            parameters:
              targetFrequency: 20

          * To **Turn Off** extraction fan at **0Hz**:

          .. code-block:: text
                
            component: ATBuilding
            cmd: setExtractionFanDriveFreq
            parameters:
              targetFrequency: 0




This procedure was last modified on |today|.


.. |author| replace:: *Kristopher Mortensen*
.. |contributors| replace:: *OS Team*

.. _Simonyi-SAL-Scripts-Configuration:

############################################
Simonyi SAL Scripts & Configurations
############################################

The following tables display the common SAL scripts used during operations with
the Simonyi Telescope. These scripts are compatible with the LOVE MTQueue
interface and include lower-level commands using ``run_command.py``.

Scripts are available in the
`ts_maintel_standardscripts <https://github.com/lsst-ts/ts_maintel_standardscripts/tree/develop/python/lsst/ts/maintel/standardscripts>`__
repository, with common and useful configurations.
Refer to `ts-xml <https://ts-xml.lsst.io>`__ to see the XML schema.

The tables contain the following information:

- A simple description of the action/command that the script initiates to the
  appropriate CSCs.
- The script name to search for in the ScriptQueue as well as a link to its
  GitHub documentation.
- Examples of common SAL script and/or ``run_command.py`` configurations.
  Scripts that require empty configurations are labeled as "No Configuration.."


.. _Simonyi-SAL-Scripts-MTM1M3:

MTM1M3
======

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/m1m3`

.. list-table::
   :widths: 40 30 30
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Raise/Lower M1M3
     - | :file:`/raise_m1m3.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/m1m3/raise_m1m3.py>`__]
       | :file:`/lower_m1m3.py`
     - No Configuration.
   * - Slew Flags
     - :file:`/enable_m1m3_slew_controller_flags.py`
     - Configuration for normal operations:

       .. code-block:: python
        :caption: enable_m1m3_slew_controller_flags.py

        slew_flags: [ACCELERATIONFORCES, BALANCEFORCES, VELOCITYFORCES, BOOSTERVALVES]
        enable: [True, True, True, True]

       To disable a specific slew flag, change the appropriate boolean to ``False``.

   * - Enable/Disable Force Balance System
     - | :file:`/enable_m1m3_balance_system.py`
       | :file:`/disable_m1m3_balance_system.py`
     - No Configuration.
   * - Check M1M3 Hardpoint Breakaway
     - :file:`/check_hardpoint.py`
       
       .. note::
        
        Default Configuration:
        
        .. code-block:: python
          
          hardpoints: all

     - To check specific hardpoints:

       .. code-block:: python
          :caption: check_hardpoint.py

          hardpoints: [1, 2, 4]

   * - M1M3 Bump Test Any/All Actuators
     - :file:`/check_actuators.py`

       .. note::
        
        Default Configuration:
        
        .. code-block:: python
          
          actuators: all
          ignore_actuators: []

     - Provide a list of the ``actuators`` to test:

       .. code-block:: python
          :caption: check_actuators.py

          actuators: [101, 102, 103, 104]

       Or check ``all`` actuators and ``ignore_actuators``:

       .. code-block:: python

          actuators: all
          ignore_actuators: [333, 412]

   * - Enter Engineering Mode
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTM1M3
        cmd: enterEngineering

   * - Exit Engineering Mode
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTM1M3
        cmd: exitEngineering


.. _Simonyi-SAL-Scripts-MTM2:

MTM2
====

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/m2`

.. list-table::
   :widths: 40 30 30
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable/Disable M2 Closed-Loop
     - | :file:`/enable_m2_closed_loop.py`
       | :file:`/disable_m2_closed_loop.py`
     - No Configuration.
   * - M2 Bump Test Any/All Actuators
     - :file:`/check_actuators.py`

       .. note::
        
        Default Configuration:
        
        .. code-block:: python
          
          actuators: all
          ignore_actuators: []
          period: 60
          force: 10

     - Write specific actuators in an array to bump test only those:

       .. code-block:: python
          :caption: check_actuators.py

          actuators: [121, 160]
          period: 5
          force: 10

       Or ignore certain actuators:

       .. code-block:: python

          ignore_actuators: [333, 412]


.. _Simonyi-SAL-Scripts-MTHexapods:

MTHexapods
==========

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/`

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable/Disable Compensation Mode
     - | :file:`enable_hexapod_compensation_mode.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_hexapod_compensation_mode.py>`__]
       | :file:`disable_hexapod_compensation_mode.py`
       
       .. note::
        
        Default Configuration applies to both hexapods:
        
        .. code-block:: python
        
          components: ["M2Hexapod", "CameraHexapod"]

     - For M2 Hexapod only:

       .. code-block:: python
          :caption: enable_hexapod_compensation_mode.py

          components:
            - M2Hexapod

       For Camera Hexapod only:

       .. code-block:: python

          components:
            - CameraHexapod

   * - Reset M2/Camera Hexapod Positions
     - ``run_command.py``
       
       .. note::
        
        For Camera Hexapod use ``component: MTHexapod:1``
        For M2 Hexapod use ``component: MTHexapod:2``

     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTHexapod:2
        cmd: move
        parameters:
            x: 0
            y: 0
            z: 0
            u: 0
            v: 0
            w: 0

       | **x, y, z** position in **microns** and **u, v, w** rotation in **degrees**.

   * - Offset M2/Camera Hexapods
     - | :file:`offset_camera_hexapod.py`
       | :file:`offset_m2_hexapod.py`
      
       .. note::
        
        | **Properties:** ``x``, ``y``, ``z``, ``u``, ``v``, and ``reset_axes``.
        | **x, y, z** position in **microns** and **u, v** rotation in **degrees**.

     - | Reset the positions before applying offsets in x, z and u axes:

       .. code-block:: python
          :caption: offset_camera_hexapod.py

          x: 1
          z: 3
          u: 0.23
          reset_axes: true

       | To reset offsets from all axes:

       .. code-block:: python

          reset_axes: "all"

       | Or to reset only certain axes:

       .. code-block:: python

          reset_axes: ["x", "z", "u"]

   * - Change Hexapod YAML Configuration
     - ``set_summary_state.py``
     - 
       .. code-block:: python
        :caption: set_summary_state.py

        data:
          -
            - MTHexapod:1
            - Standby
          -
            - MTHexapod:1
            - Enabled
            - laser_rotation_elevation_v18.yaml
          -
            - MTHexapod:2
            - Standby
          -
            - MTHexapod:2
            - Enabled
            - laser_rotation_elevation_v18.yaml


.. _Simonyi-SAL-Scripts-MTRotator:

MTRotator
=========

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/mtrotator`

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Move Rotator Angle
     - :file:`/move_rotator.py` (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtrotator/move_rotator.py>`__)
       
       .. note::

        ``angle`` range: [-89, +89] degrees.
     - To move the rotator to -45 deg:
  
       .. code-block:: python
        :caption: move_rotator.py

        angle: -45

   * - Stop Rotator
     - :file:`stop_rotator.py`
     - No Configuration.


.. _Simonyi-SAL-Scripts-MTMount:

MTMount
=======

| Path 1 (p1): :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/`
| Path 2 (p2): :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/mtmount`

.. list-table::
   :widths: 20 50 30
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Home TMA Axes
     - :file:`{p1}/home_both_axes.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/home_both_axes.py>`__]
       
       .. note::

        | Requires MTDome CSC in ``ENABLED`` or ``DISABLED``.
        |
        | Script enables **M1M3 force balance system** and M2Hex and Cam Hex **compensation mode**.
        | It also offers the option to move to another position and home again.

     - To home both axes at the position *Az = 1 deg* and *El = 46 deg*:

       .. code-block:: python
        :caption: home_both_axes.py

        final_home_position:
          az: 1
          el: 46

       The position (Az: 1, El: 46) was chosen to be run every time we home the axes, 
       to avoid offsets inconsistency when homing at different positions.

   * - Move TMA Point-to-Point
     - | :file:`{p1}/move_p2p.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/move_p2p.py>`__]
       
       .. note::
        
        Default Configuration:

        .. code-block:: python
        
          pause_for: 0
          move_timeout: 120.0
       
     - Select a single point in Az (deg), El (deg) or in RA (hrs), Dec (deg):

       .. code-block:: python
          :caption: move_p2p.py

          az: 70
          el: 70

       .. code-block:: python

          ra: 4.59867
          dec: 16.5092

       If slewing to more than one target, use an array and the ``pause_for`` function.

       .. code-block:: python

          az: [70, 90, 110]
          el: [70, 70, 70]
          pause_for: 30

       .. code-block:: python

          ra: [4.59867, 20.2, "12:20:56.5"]
          dec: [16.5092, 10.1, "-13:34:04.5"]
          pause_for: 15

       .. note::
        
        For (RA, Dec) arrays, sexagesimals may be added as strings.

   * - Point (Az, El)
     - :file:`{p1}/point_azel.py` [`code <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/base_point_azel.py>`__]
       
       .. note::
        
        Default Configuration:

        .. code-block:: python
        
          rot_tel: 0.0
          target_name: "AzEl"
          wait_dome: false
          slew_timeout: 240.0

     - To point the telescope at *Az = 80 deg* and *El = 80 deg*:

       .. code-block:: python
        :caption: point_azel.py

        az: 80
        el: 80

   * - Track Target
     - :file:`{p1}/track_target.py` [`code <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/base_track_target.py>`__]
       
       .. note::
        
        Default Configuration:
       
        .. code-block:: python
        
          offset: {x: 0, y: 0}
          differential_tracking: {dra: 0.0, ddec: 0.0}
          rot_type: "SkyAuto"
          rot_value: 0
          track_for: 0
          stop_when_done: false
          az_wrap_strategy: "OPTIMIZE"
          slew_timeout: 240

        * `rot_type Options <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_track_target.py#L230>`__
        * `az_wrap_strategy Options <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_track_target.py#L270>`__

       
       
     - | Slew and track ICRS RA, Dec coordinates.
       | RA in hours (0, 24), DEC in degrees (-90, +90):

       .. code-block:: python
          :caption: track_target.py

          slew_icrs:
            ra: 20.2
            dec: 10.1

       | RA, DEC in sexagesimals (as strings):

       .. code-block:: python

          slew_icrs:
            ra: "12:20:56.5"
            dec: "-13:34:04.5"

       | Slew to Az, El and start tracking:

       .. code-block:: python

          track_azel:
            az: 65
            el: 45

       | Slew and track a target name:

       .. code-block:: python

          target_name: HD150798

       | Find a target based on AzEl and magnitude limit:

       .. code-block:: python

          find_target:
            az: 65
            el: 25
            mag_limit: 8

   * - Stop Telescope Tracking
     - | :file:`{p1}/stop_tracking.py` [`code <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_stop_tracking.py>`__]
     - No Configuration.
   * - Open/Close Mirror Covers
     - | :file:`{p1}/open_mirror_covers.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/open_mirror_covers.py>`__]
       | :file:`{p1}/close_mirror_covers.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/close_mirror_covers.py>`__]

       .. note::
        
        * If El < 20°, script moves TMA to El 20°.
        * Closes (deploys) OR opens (retracts) the mirror covers.
        * Lock M1M3 mirror covers.
  
     - No Configuration.
   * - Change TMA Performance Settings
     - ``run_command.py``
     
       .. note:: 
        
        Remember to restore to default, as the settings are cumulative.

     - To set MTMount to 10% performance settings:

       .. code-block:: python
        :caption: run_command.py

        cmd: applySettingsSet
        component: MTMount
        parameters:
          restoreDefaults: true
          settings: 10percentperformance

   * - Restore TMA to Default Settings
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTMount
        cmd: restoreDefaultSettings

   * - Unpark Mount
     - :file:`{p2}/unpark_mount.py`
     - No Configuration.
   * - Park Mount
     - :file:`{p2}/park_mount.py`

       .. admonition:: DO NOT USE!
        :class: warning

        Currently in testing as of |today|.

     - No Configuration.


.. _Simonyi-SAL-Scripts-MTAOS:

MTAOS
=====

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/`

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Issue MTAOS Correction
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTAOS
        cmd: issueCorrection

   * - Reset MTAOS Correction
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTAOS
        cmd: resetCorrection

   * - Reset Applied Offsets to Degrees of Freedom (DOF)
     - ``run_command.py``
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTAOS
        cmd: resetOffsetDOF

   * - Enable/Disable AOS closed-loop
     - | :file:`enable_aos_closed_loop.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_aos_closed_loop.py>`__]
       | :file:`disable_aos_closed_loop.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/disable_aos_closed_loop.py>`__]
     - Default Configuration:
       
       .. code-block:: python
        :caption: enable_aos_closed_loop.py
        
        truncation_index: 12
        used_dofs: [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,30,31,32,33,34]
       
       Higher selectivity of DOFs, truncation, zernikes, etc. 
       can be done, with the approval of the AOS team:
       
       .. code-block:: python

        used_dofs: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        truncation_index: [2]
        zn_selected: [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20, 21, 22, 27, 28]

   * - Set Telescope DOFs
     - :file:`set_dof.py`
       
       .. note::
        
        To ignore specific components:

        .. code-block:: python
        
          ignore:
            - mtmount
            - mthexapod_1
            - mthexapod_2
            - mtrotator

     - Select DOFs from a **previous image**:

       .. code-block:: python
          :caption: set_dof.py

          day: 20250630
          seq: 457

       Apply **individual DOFs** (microns or arcsec):

       .. code-block:: python

          # Example: M1M3 bending mode 16
          M1M3_B16: 0.3

          # Example: M2 hexapod offset in x
          M2_dx: 5

       Apply **multiple DOFs** (50-dimensional vector):
       
       * [0-4]: M2 Rigid Body Motions
       * [5-9]: Camera Rigid Body Motions
       * [10-29]: M1M3 Bending Modes
       * [30-49]: M2 Bending Modes

       .. code-block:: python

          dofs: [0.0, 1.0, 2.0, 3.0, 4.0,
                 5.0, 6.0, 7.0, 8.0, 9.0,
                 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
                 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,
                 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,
                 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0]

   * - Apply DOFs to Telescope
     - :file:`apply_dof.py`
     - Same configurations as ``set_dof.py``.
   * - Run Closed-Loop System on AOS
     - :file:`close_loop_lsstcam.py`
     - Higher selectivity of script parameters can be done, with the approval of the AOS team.

       .. code-block:: python
        :caption: close_loop_lsstcam.py

        exposure_time: 15
        max_iter: 5
        mode: "FAM"
        program: "BLOCK-T249"
        note: "initial_focus_dzs_tilts_bending_modes"
        used_dofs: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 17, 18, 19, 20, 21, 22, 23, 28, 29, 30, 31, 32, 33, 34, 37, 38, 39, 40, 41, 42, 45, 46]
        apply_corrections: true
        use_ocps: true
        filter: "r_03"

   * - Offset M2/Camera Hexapods (PSF Focus)
     - | :file:`offset_m2_hexapod.py`
       | :file:`offset_camera_hexapod.py`
     - | If the first image shows a donut rather than a PSF, adjust by hand.
       | Change the camera hexapod z by **Dz = [(donut diameter in pixels) * 12]** microns.

       .. code-block:: python
          :caption: offset_camera_hexapod.py

          z: -Dz

       | If that makes things worse (bigger donuts):

       .. code-block:: python

          z: +2 x Dz

   * - Take Triplet Sequence with LSSTCam
     - :file:`take_aos_sequence_lsstcam.py`
       
       .. note::
        
        Default Configurations:

        .. code-block:: python
        
          filter: current_filter
          exposure_time: 30
          dz: 1500
          n_sequences: 1
          mode: TRIPLET
          program: AOSSEQUENCE

     - The following is an example AOS sequence used in testing:
       
       .. code-block:: python
        :caption: take_aos_sequence_lsstcam.py

        filter: z_20
        exposure_time: 10
        dz: 800
        mode: TRIPLET
        program: AOSSEQUENCE
        reason: "test"


.. _Simonyi-SAL-Scripts-MTDome:

MTDome
======

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/mtdome`

``subSystemId`` enumerations in `MTDome XML <https://ts-xml.lsst.io/sal_interfaces/MTDome.html#enumerations>`__:

- Azimuth Motion Control System (AMCS) = ``0x1``
- Aperture Shutter Control System (APSCS) = ``0x4``
- Louvers (LCS) = ``0x8``

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable/Disable Dome Following Mode
     - | :file:`/enable_dome_following.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/enable_dome_following.py>`__]
       | :file:`/disable_dome_following.py`
     - No Configuration.
   * - Offset Dome Azimuth
     - :file:`/offset_dome.py`
     - Units of ``az`` in degrees.

       .. code-block:: python
        :caption: offset_dome.py

        offset: 10

   * - Slew Dome in Azimuth
     - :file:`/slew_dome.py`
     - | Units of ``az`` in degrees. 
       | If needed, CSC components can be ignored with the ``ignore`` parameter.

       .. code-block:: python
        :caption: slew_dome.py

        az: 70
        ignore:
          - mtmount
          - mthexapod_1
          - mthexapod_2

   * - Park/Unpark Dome
     - | :file:`/park_dome.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/park_dome.py>`__]
       | :file:`/unpark_dome.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/unpark_dome.py>`__]
     - If needed, CSC components can be ignored with the ``ignore`` parameter. 
     
       .. code-block:: python
        :caption: park_dome.py

        ignore:
          - mtm1m3
          - mtm2
          - mtaos
          - mtdometrajectory
          - mthexapod_1
          - mthexapod_2

   * - Open/Close MTDome
     - | :file:`/open_dome.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/open_dome.py>`__]
       | :file:`/close_dome.py`
       
       .. note::
        
        Both scripts have the ``force`` property, useful to bypass errors
        or conditions (e.g., dome telemetry reports shutters in wrong state,
        mirror covers lost instead of closed).
       
        The dome can also open/close via a direct override using a ``run_command.py`` script,
        if the normal SAL Script fails to execute properly.

     - No Configuration., but you can ignore CSCs with the ``ignore`` parameter:

       .. code-block:: python
          :caption: open_dome.py

          force: false
          ignore:
            - mtm1m3
            - mtm2
            - mtaos
            - mtdometrajectory
            - mthexapod_1
            - mthexapod_2
            - mtmount
            - mtptg
            - mtrotator
      
       To open the dome with a ``run_command.py``:

       .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: openShutter

       To close the dome with a ``run_command.py``:

       .. code-block:: python

          component: MTDome
          cmd: closeShutter

   * - Open/Close Dome Louvers
     - ``run_command.py``
       
       .. note::
        
        | The array values are between 0.0 (**closed**) and 100.0 (fully **open**).
       
        | Louver Index (0-based):
        | [A1, A2, **B1**, B2, B3, C1, C2, C3, D1, D2, D3, 
         **E1**, **E2**, E3, F1, F2, F3, G1, G2, G3, **H1**, **H2**, 
         H3, I1, I2, I3, L1, L2, L3, **M1**, M2, M3, N1, N2]

     - If one wants to open the mechanical louvers **highlighted in bold** in the *Louver Index*:

       .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: setLouvers
          parameters:
            position: [0.0, 0.0, 100.0, 0.0, 0.0,
                       0.0, 0.0, 0.0, 0.0, 0.0,
                       0.0, 100.0, 100.0, 0.0, 0.0,
                       0.0, 0.0, 0.0, 0.0, 0.0,
                       100.0, 100.0, 0.0, 0.0, 0.0,
                       0.0, 0.0, 0.0, 0.0, 100.0,
                       0.0, 0.0, 0.0, 0.0]
    
       To close all louvers:

       .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: closeLouvers

       Alternatively, one can use the ``setLouvers`` command with value 0 in the
       louver indices to close specific louvers and leave others open.

   * - Stop Dome and Engage Brakes
     - ``run_command.py``
      
       .. note:: 
        
        Dome ``subSystemIds``:

        * Dome Azimuth: ``0x1``
        * Dome Shutter: ``0x4``
        * Louvers: ``0x8``
  
     - 
       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: stop
        parameters:
          engageBrakes: true
          subSystemIds: 0x1

   * - Recover from Dome Azimuth Fault
     - :file:`/recover_from_controller_fault.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/recover_from_controller_fault.py>`__]
       
       .. note::

        The script does the following:

        #. Clears the current dome controller fault.
        #. Turns on drives and moves the dome slightly to confirm fault is cleared.
        #. Re-enables dome following if able to move again.

     - No Configuration.
   * - Clear Dome Subsystem Fault
     - | ``run_command.py``
       
       .. note:: 
        
        Command will also reset dome/shutter drives (see below)
        internally when attempting to clear faults on those subsystems.
       
        Dome ``subSystemIds``:

        * Dome Azimuth: ``0x1``
        * Dome Shutter: ``0x4``
        * Louvers: ``0x8``

     - Most common subsystem fault is the Dome Azimuth Drives:

       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: exitFault
        parameters:
          subSystemIds: 0x1

   * - Reset Dome Azimuth Drives
     - ``run_command.py``
     - To reset all dome azimuth drives:

       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: resetDrivesAz
        parameters:
          reset: [1,1,1,1,1]

   * - Reset Dome Shutter Drives
     - ``run_command.py``
     - To reset all dome shutter drives:

       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: resetDrivesShutter
        parameters:
          reset: [1,1,1,1]

   * - Home Dome Azimuth
     - :file:`/home_dome.py`
       
       .. note::
        
        | Required: ``physical_az`` (azimuth position as read by markings inside the dome).
        | See `Homing MTDome Procedure <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/705003522>`__.

     - If the dome is parked, and its physical azimuth reads **310 deg**, instead of its true home position (328 deg):

       .. code-block:: python
        :caption: home_dome.py

        physical_az: 310
        ignore:
            - mtm1m3
            - mtm2
            - mtaos
            - mtdometrajectory
            - mthexapod_1
            - mthexapod_2
            - mtmount
            - mtptg
            - mtrotator

   * - Home Dome Shutter
     - ``run_command.py``
     - Remember to include the ``subSystemIds`` parameter:

       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: home
        parameters:
          subSystemIds: 0x4

   * - Set Dome Shutter to Degraded Mode
     - ``run_command.py``
       
       .. note::
        
        Dome operational modes:

        * ``1``: Normal Mode
        * ``2``: Degraded Mode (10% Performance)

     - Remember to include the ``subSystemIds`` parameter:

       .. code-block:: python
        :caption: run_command.py

        component: MTDome
        cmd: setOperationalMode
        parameters:
          operationalMode: 2
          subSystemIds: 0x4

   * - Rotate Dome at Constant Velocity
     - :file:`/crawl_az.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/crawl_az.py>`__]
       
       .. note::
        
        Includes ``position`` and ``velocity`` properties.
        
        * ``position`` is measures in **deg**.
        * ``velocity`` is measured in **deg/second**.
       
        Default Configuration:

        .. code-block:: python
        
          direction: ClockWise

     - If we want to move the dome counter-clockwise at a rate of 0.5 deg/second:

       .. code-block:: python
        :caption: crawl_az.py

        direction: CounterClockWise
        velocity: 0.5


.. _Simonyi-SAL-Scripts-LSSTCam:

LSSTCam
=======

Path: :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/`

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable LSSTCam
     - :file:`enable_lsstcam.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_lsstcam.py>`__]

       .. admonition:: DO NOT USE!
        :class: warning

        Not available as of |today|.

     - No Configuration.
   * - Standby LSSTCam
     - :file:`standby_lsstcam.py`
       
       .. admonition:: DO NOT USE!
        :class: warning

        Not available as of |today|.

     - No Configuration.
   * - Execute Focus Sweep
     - :file:`focus_sweep_lsstcam.py`

       .. note:: 
        
        Properties with Default Configurations:

        .. code-block:: python

          sim: false
          hexapod: Camera
          filter: null
          exp_time: 10
          axis: ["x", "y", "z", "u", "v"]
          focus_window:
          n_steps:
          focus_step_sequence:
          n_images_per_step: 1
          program: FOCUS_SWEEP
          reason: null
          ignore:
        
        Units for ``focus_window`` and ``focus_step_sequence`` are in **microns**.

     - | Required for defined focus window — use ``axis``, ``focus_window`` and ``n_steps``:

       .. code-block:: python
          :caption: focus_sweep_lsstcam.py

          axis: z
          focus_window: 300
          n_steps: 9
          program: "BLOCK-T92"
          hexapod: "Camera"
          reason: "focus_sweep_cam_dz"

       | Or required for chosen steps — use ``axis`` and ``focus_step_sequence``:

       .. code-block:: python

          axis: "y"
          focus_step_sequence: [200, 50, -50, 200]
          hexapod: "M2"
          reason: "Sweep in y"

   * - Change Filter
     - :file:`change_filter_lsstcam.py`

       .. warning::

        MTMount and MTRotator CSCs must be ``ENABLED`` for the script to run.
       
     - The ``filter`` parameter is required for this script. 
       To change to the ``z_20`` filter:

       .. code-block:: python
          :caption: change_filter_lsstcam.py

          filter: z_20

   * - Take Image
     - :file:`take_image_lsstcam.py`
       
       .. note::

        Typical Configurations Include:

        .. code-block:: python

          filter: # Current Filter.
          nimages: # (Optional) Number of images.
          exp_times: # Number of seconds (scalar or array).
          image_type: # One of ["BIAS", "DARK", "FLAT", 
                    #         "OBJECT", "ENGTEST", "ACQ", 
                    #         "SPOT", "CWFS", "FOCUS"].
          reason: # (Optional) Short reason for image(s).
          program: # (Optional) Test case used for the images.
          note: # (Optional) Additional notes to add.
        
        *Required Parameters:* ``exp_times`` and ``image_type``.

     - Take a single five-second bias image:

       .. code-block:: python
        
        :caption: take_image_lsstcam.py

        image_type: BIAS
        exp_times: 5

       Take two five-second flat images (with a reason):

       .. code-block:: python

        image_type: FLAT
        exp_times: 5
        nimages: 2
        reason: "flat_test"

       Take a single one-second acquisition image for a test case:

       .. code-block:: python

        image_type: ACQ
        exp_times: 1
        program: "BLOCK-TXXXX"

       Take a single 30-second engineering test image:

       .. code-block:: python

        image_type: ENGTEST
        exp_times: 30
        nimages: 1

   * - Track Target and Take Image
     - :file:`track_target_and_take_image_lsstcam.py`
     - | All of the following parameters are required:

       .. code-block:: python
          :caption: track_target_and_take_image_lsstcam.py

          ra: # ICRS right ascension (hour) in decimal hours or sexagesimal strings.
          dec: # ICRS declination (deg) in decimal hours or sexagesimal strings.
          rot_sky: # The position angle (deg) in the sky.
          name: # Target name.
          obs_time: # Time given for starting the slew
          num_exp: # Number of exposures.
          exp_times: # Array of exposure times in seconds.
          band_filter: # Filter used for observation.

   * - Take Stuttered Sequence
     - :file:`take_stuttered_lsstcam.py`
     - Configuration can be found in `take_stuttered_lsstcam.py source <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/take_stuttered_lsstcam.py>`__.
   * - Take AOS Triplet Sequence
     - :file:`maintel/take_aos_sequence_lsstcam.py`
       
       .. note::
        
        Default Configurations:

        .. code-block:: python
        
          filter: # Current filter.
          exposure_time: 30
          dz: 1500
          n_sequences: 1
          mode: TRIPLET
          program: AOSSEQUENCE

        Units for ``dz`` are in **microns**.

     - One can always add a ``reason`` to the triplet sequence.
     
       .. code-block:: python
        :caption: take_aos_sequence_lsstcam.py

        filter: z_20
        exposure_time: 10
        dz: 800
        mode: TRIPLET
        program: AOSSEQUENCE
        reason: "test"


.. _Simonyi-SAL-Scripts-LaserTracker:

LaserTracker
============

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Align the TMA to the Calibration Screen
     - :file:`laser_tracker/align.py` [`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/laser_tracker/align.py>`__]
       
       .. note::
        
        The LaserTracker alignment of the Calibration Screen is now done by
        using ``id: BLOCK-T495`` in the :ref:`scheduler/add_block.py <Simonyi-SAL-Scripts-Scheduler>` script.

        Default Configuration:

        .. code-block:: python
        
          max_iter: 10
          tolerance_linear: 0.0001 # in meters
          tolerance_angular: 0.00138 # in deg (~5 arcsec)
          target: "M2" 
          # Target Options (REQUIRED): 
          # "M2", "Camera", or "CALIBRATION_SCREEN"
        
     - To align to the calibration screen with a 0.01 deg angular tolerance:
       
       .. code-block:: python
        :caption: laser_tracker/align.py

        target: CALIBRATION_SCREEN
        tolerance_angular: 0.01
        reason: "Align TMA to Calibration Screen"
        program: "BLOCK-T495"

       
   * - Park the LaserTracker
     - ``run_command.py``

       .. note::
        
        The LaserTracker parking command is now done by
        using ``id: BLOCK-T495`` in the :ref:`scheduler/add_block.py <Simonyi-SAL-Scripts-Scheduler>` script.

     - To park the lasertracker at the p2 point on M1M3:

       .. code-block:: python
        :caption: run_command.py

        component: LaserTracker:1
        cmd: measurePoint
        parameters:
          collection: A
          pointgroup: M1M3
          target: p2



.. _Simonyi-SAL-Scripts-MTCalSys:

MTCalSys
========

.. list-table::
   :widths: 10 20 35 35
   :header-rows: 1

   * - CSC
     - Command
     - SAL Script
     - Script Configuration
   * - General
     - Open/close MTReflector
     - ``run_command.py``
     - To open MTReflector
       
       .. code-block:: python
        :caption: run_command.py

        component: MTReflector
        cmd: open

       To close the reflector, use ``cmd: close``.

   * -
     - Park the Calibration Projector
     - :file:`maintel/park_calibration_projector.py`
     - No Configuration.
   * -
     - Setup LEDProjector for White Light Flats
     - :file:`maintel/setup_whitelight_flats.py`
       
       .. note::
        
        Default Configuration:
       
        .. code-block:: python
        
          sequence_name: "whitelight_u_source"
          ignore: ['TunableLaser','LinearStage:104',
                   'CBP','Electrometer:101','Electrometer:102',
                   'FiberSpectrograph:101', 'FiberSpectrograph:102']

     - We can change the ``sequence_name`` and ``ignore`` unnecessary CSCs 
       based on the provided test cases on Zephyr Scale.

       .. code-block:: python
        :caption: setup_whitelight_flats.py

        sequence_name: 'laser_functional'
        ignore: ['LinearStage:104', 'CBP',
                 'Electrometer:102','Electrometer:101',
                 'FiberSpectrograph:101','FiberSpectrograph:102']

   * -
     - Take Specified Whitelight Flats
     - :file:`maintel/take_whitelight_flats_lsstcam.py` [`code <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/maintel/take_whitelight_flats_lsstcam.py>`__]
       
       .. note::
        
        | Default ``sequence_names: ["daily"]`` will run for all installed filters available (g, r, i, z, and u/y).
        | Metadata parameters available: ``note``, ``reason``, and ``program``.

     - The following is an example of a specific type Photon Transfer Curve (PTC) script used, 
       where the data is collected for the test case **BLOCK-T572**:

       .. code-block:: python
        :caption: take_whitelight_flats_lsstcam.py

        sequence_names: ['low_level_ptc']
        reason: "low_level_led_ptc"
        program: "BLOCK-T572"

   * - CBP
     - Move the CBP to (Az, El) Position
     - ``run_command.py``
       
       .. note::

        | The ``azimuth`` and ``elevation`` parameters require floating point numbers measured in *degrees*.
        |
        | **Limits:**
        | Az: [-45.0 to 45.0 deg]
        | El: [-69.0 to 45.0 deg]
        
     - If we want to move the CBP to *Az = -0.05 deg* and *El = -46.5 deg*:

       .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: move
          parameters:
            azimuth: -0.05
            elevation: -46.5

   * -
     - Change the CBP Mask
     - ``run_command.py``
       
       .. note::
        There are 5 masks to characterize the beam projection. 
        These are represented by strings of numbers: 
        
        * ``'1'``: LSSTCam 1 Pinhole per CCD Mask
        * ``'2'``: 1mm Pinhole Mask
        * ``'3'``: Empty Slot
        * ``'4'``: ComCam 1 Pinhole per CCD Mask
        * ``'5'``: 1 Pinhole per Amp Mask
        
        Selection of the mask type for a test case is determined typically by calibration team.

     - If we want to change the current CBP mask to *mask position 1*:

       .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: changeMask
          parameters:
            mask: '1'

   * -
     - Rotate the CBP Mask
     - ``run_command.py``

       .. note::
        
        Rotation is between 1 deg and 360 deg.

     - If we want to rotate the CBP mask to 96.5 deg:

       .. code-block:: python
        :caption: run_command.py

        component: CBP
        cmd: changeMaskRotation
        parameters:
          mask_rotation: 96.5

   * -
     - Set CBP Focus
     - ``run_command.py``

       .. note::

        Focus is measured in microns, and its range is [0, 13000] microns.

     - If we want to set the focus to *3800 microns*:

       .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: setFocus
          parameters:
            focus: 3800

   * -
     - Park CBP
     - ``run_command.py``

       .. note::

        The CBP moves to elevation -70 deg, and it locks its motors when parking.

     - 
       .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: park

   * - Tunable Laser
     - Set Tunable Laser Wavelength
     - ``run_command.py``

       .. note::

        Laser wavelengths are measured in nanometers (nm), and the range is between 
        350 - 1100nm during normal operations.

     - To change the laser wavelength to *750nm*:

       .. code-block:: python
          :caption: run_command.py

          component: TunableLaser
          cmd: changeWavelength
          parameters:
            wavelength: 750

   * -
     - Set Laser Output Configuration
     - ``run_command.py``
       
       .. note::
        
        Available optical configurations are located in the `XML documentation <https://ts-xml.lsst.io/sal_interfaces/TunableLaser.html#enumerations>`__.

     - To set the configuration to *F2 SCU*:

       .. code-block:: python
          :caption: run_command.py

          cmd: setOpticalConfiguration
          parameters:
            configuration: F2 SCU

   * -
     - Change Tunable Laser Mode
     - ``run_command.py``

       .. note::

        There are two available laser modes: *Burst Mode* (``setBurstMode``) 
        and *Continuous Mode* (``setContinuousMode``).

     - To set the tunable laser to *burst mode*:

       .. code-block:: python
          :caption: run_command.py

          component: TunableLaser
          cmd: setBurstMode

   * -
     - Start/Stop Tunable Laser Propagation
     - ``run_command.py``

       .. note::
        It is required to set the laser mode (burst/continous) *first* before 
        activating the laser propagation.

     - To start propagation:

       .. code-block:: python
        :caption: run_command.py

        component: TunableLaser
        cmd: startPropagateLaser

       To stop propagation, set ``cmd: stopPropagateLaser``.


.. _Simonyi-SAL-Scripts-Scheduler:

Scheduler
=========

.. list-table::
   :widths: 20 50 30
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable Simonyi Scheduler
     - :file:`maintel/scheduler/enable.py`
       
       .. note::
        
        Properties: ``config`` (string): Name of the configuration .yaml file.
        
        This loads the .yaml configuration file and can also be used to state-cycle the scheduler.

     - If we want to enable the standard configuration for the LSST survey:
     
       .. code-block:: python
        :caption: maintel/scheduler/enable.py

        config: fbs_config_lsst_survey.yaml

   * - Start Scheduler-Driven Observations
     - :file:`maintel/scheduler/resume.py`
     - No Configuration.
   * - Stop Scheduler-Driven Observations
     - :file:`maintel/scheduler/stop.py`
     - No Configuration.
   * - Start a Testing BLOCK
     - :file:`maintel/scheduler/add_block.py`
       
       .. note::
        
        Properties:
        
        * ``id`` (string): Name of the BLOCK to be run.
        * ``override``: List of parameters to be changed/updated in the BLOCK.
       
        Current available BLOCKs listed
        `here <https://rubinobs.atlassian.net/projects/BLOCK?selectedItem=com.atlassian.plugins.atlassian-connect-plugin:com.kanoah.test-manager__main-project-page#!/v2/testCases?projectId=10064>`__.

     - If we wanted to run the initial alignment for Simonyi (BLOCK-T539):

       .. code-block:: python
          :caption: maintel/scheduler/add_block.py

          id: BLOCK-T539


.. _Simonyi-SAL-Scripts-General:

General Scripts
===============

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Set Summary State to OFFLINE/ENABLED/DISABLED/STANDBY
     - | ``set_summary_state.py``
       |
       | Subsystems accepted: ``MTMount``, ``MTRotator``, ``MTHexapod:1`` (Cam),
       | ``MTHexapod:2`` (M2), ``MTM2``, ``MTPtg``, ``MTAOS``, ``MTDome``, ``MTM1M3``
       |
       | States accepted: ``STANDBY``, ``ENABLED``, ``DISABLED``, ``OFFLINE``
     - | .. code-block:: python
          :caption: set_summary_state.py

          data:
            - [MTMount, DISABLED]

       | or:

       .. code-block:: python

          data:
            -
              - MTAOS
              - STANDBY

   * - self.group.components naming convention
     - | The name of the CSC must match the name of the CSC in ``group.components``,
       | which is the name of the CSC in lowercase, replacing the ":" with "_"
       | for indexed components.
     - | e.g. ``ATMCS`` → ``atmcs``
       | ``MTHexapod:1`` → ``hexapod_1``
       |
       | To use an ``ignore`` property:

       .. code-block:: python

          ignore:
            - mtdometrajectory
            - hexapod_1
            - mtaos

   * - Checks and prepares key telescope systems
     - | :file:`ensure_on_sky_readiness.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/ensure_onsky_readiness.py>`__)
     - | Default Configuration:

       .. code-block:: python
          :caption: ensure_on_sky_readiness.py

          slew_flags = ["ACCELERATIONFORCES", "BALANCEFORCES",
            "VELOCITYFORCES", "BOOSTERVALVES"]
          enable_flags = [True, True, True, False]

   * - Enable EAS with different configuration
     - ``set_summary_state.py``
     - | .. code-block:: python
          :caption: set_summary_state.py

          data:
            - [EAS, STANDBY]
            - [EAS, ENABLED, "disable_m1m3ts.yaml"]


This procedure was last modified on |today|.



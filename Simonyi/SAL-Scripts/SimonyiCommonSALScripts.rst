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
  Scripts that require empty configurations are labeled as "No configuration."


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
     - No configuration
   * - Slew Flags
     - :file:`/enable_m1m3_slew_controller_flags.py`
     - Default Configuration:

       .. code-block:: python
        :caption: enable_m1m3_slew_controller_flags.py

        slew_flags: [ACCELERATIONFORCES, BALANCEFORCES, VELOCITYFORCES, BOOSTERVALVES]
        enable: [True, True, True, True]

       To disable a specific slew flag, change the appropriate boolean to ``False``.

   * - Enable/Disable Force Balance System
     - | :file:`/enable_m1m3_balance_system.py`
       | :file:`/disable_m1m3_balance_system.py`
     - No configuration
   * - Check M1M3 Hardpoint Breakaway
     - | :file:`/check_hardpoint.py`
       |
       | Default config:
       
       .. code-block:: python
        
        hardpoints: all

     - To check specific hardpoints:

       .. code-block:: python
          :caption: check_hardpoint.py

          hardpoints: [1, 2, 4]

   * - M1M3 Bump Test Any/All Actuators
     - | :file:`/check_actuators.py`
       |
       | Default config:

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
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable/disable M2 closed-loop
     - | :file:`/enable_m2_closed_loop.py`
       | :file:`/m2/disable_m2_closed_loop.py`
     - No configuration
   * - Perform a M2 bump test on either a selection of individual actuators or on all axial actuators
     - | :file:`/check_actuators.py`
       |
       | Default config:
       |
       | ``actuators: all``
       | ``ignore_actuators: []``
       | ``period: 60``
       | ``force: 10``
     - | Write specific actuators in an array to bump test only those:

       .. code-block:: python
          :caption: check_actuators.py

          actuators: [121, 160]
          period: 5
          force: 10

       | Or ignore certain actuators:

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
   * - Turning on compensation mode
     - | :file:`enable_hexapod_compensation_mode.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_hexapod_compensation_mode.py>`__)
       | :file:`disable_hexapod_compensation_mode.py`
       |
       | Default config applies to both hexapods:
       |
       | ``components: ["M2Hexapod", "CameraHexapod"]``
     - | For M2 Hexapod only:

       .. code-block:: python
          :caption: enable_hexapod_compensation_mode.py

          components:
            - M2Hexapod

       | For Camera Hexapod only:

       .. code-block:: python

          components:
            - CameraHexapod

   * - Resetting M2 Hexapod (MTHexapod:2) or Camera Hexapod (MTHexapod:1) to a zero position
     - | ``run_command.py``
       |
       | For Camera Hexapod use ``component: MTHexapod:1``
       | For M2 Hexapod use ``component: MTHexapod:2``
     - | .. code-block:: python
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

   * - Offset Camera Hexapod / Offset M2 Hexapod
     - | :file:`offset_camera_hexapod.py`
       | :file:`offset_m2_hexapod.py`
       |
       | Same schema for both SAL scripts.
       | Properties:
       |
       | ``x:``
       | ``y:``
       | ``z:``
       | ``u:``
       | ``v:``
       | ``reset_axes: false``
       |
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

   * - Enable Hexapods with new Configuration
     - ``set_summary_state.py``
     - | .. code-block:: python
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
   * - Move rotator to specific angle
     - | :file:`/move_rotator.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtrotator/move_rotator.py>`__)
       |
       | ``angle`` range [-89, +89]
     - | .. code-block:: python
          :caption: move_rotator.py

          angle: -45

   * - Stop rotator
     - :file:`stop_rotator.py`
     - No configuration


.. _Simonyi-SAL-Scripts-MTMount:

MTMount
=======

| Path 1 (p1): :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/`
| Path 2 (p2): :file:`ts_maintel_standardscripts/python/lsst/ts/maintel/standardscripts/mtmount`

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Home TMA axes
     - | :file:`{p1}/home_both_axes.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/home_both_axes.py>`__)
       |
       | Requires MTDome to be ``ENABLED`` or ``DISABLED``.
       | Enables **M1M3 force balance system** and M2Hex and Cam Hex **compensation mode**.
       | Offers the option to move to another position and home again.
     - | .. code-block:: python
          :caption: home_both_axes.py

          final_home_position:
            az: 1
            el: 46

       | The position (Az:1, El 46) was chosen to be run every time we home the axes,
       | to avoid offsets inconsistency when homing at different positions.

   * - Move TMA point to point
     - | :file:`{p1}/move_p2p.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/move_p2p.py>`__)
       |
       | Default config:
       | ``pause_for: 0``
       | ``move_timeout: 120.0``
       |
       | If slewing to more than one target, use an array and the ``pause_for`` function.
     - | Az [deg] / El [deg]:

       .. code-block:: python
          :caption: move_p2p.py

          az: 70
          el: 70

       | Example for arrays:

       .. code-block:: python

          az: [70, 90, 110]
          el: [70, 70, 70]

       | Or RA [hrs] / Dec [deg]:

       .. code-block:: python

          ra: 4.59867
          dec: 16.5092

       | Array (sexagesimal as strings):

       .. code-block:: python

          ra: [4.59867, 20.2, "12:20:56.5"]
          dec: [16.5092, 10.1, "-13:34:04.5"]

   * - Point AzEl
     - | :file:`{p1}/point_azel.py`
       | (`base code <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/base_point_azel.py>`__)
       |
       | Default config:
       | ``rot_tel: 0.0``
       | ``target_name: "AzEl"``
       | ``wait_dome: false``
       | ``slew_timeout: 240.0``
     - | .. code-block:: python
          :caption: point_azel.py

          az: 80
          el: 80

   * - Track a target
     - | :file:`{p1}/track_target.py`
       | (`base code <https://github.com/lsst-ts/ts_standardscripts/blob/develop/python/lsst/ts/standardscripts/base_track_target.py>`__)
       |
       | Default config:
       | ``offset: {x: 0, y: 0}``
       | ``differential_tracking: {dra: 0.0, ddec: 0.0}``
       | ``rot_type: "SkyAuto"``
       | ``rot_value: 0``
       | ``track_for: 0``
       | ``stop_when_done: false``
       | ``az_wrap_strategy: "OPTIMIZE"``
       | ``slew_timeout: 240``
       |
       | `rot_type options <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_track_target.py#L230>`__
       | `az_wrap_strategy options <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_track_target.py#L270>`__
     - | Slew and track ICRS RaDec coordinates.
       | RA in hours (0, 24), DEC in degrees (-90, +90):

       .. code-block:: python
          :caption: track_target.py

          slew_icrs:
            ra: 20.2
            dec: 10.1

       | RA, DEC in sexagesimal (as strings):

       .. code-block:: python

          slew_icrs:
            ra: "12:20:56.5"
            dec: "-13:34:04.5"

       | Slew to AzEl and start tracking:

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

   * - Stop telescope tracking
     - | :file:`{p1}/stop_tracking.py`
       | (`base code <https://github.com/lsst-ts/ts_standardscripts/blob/3e27256466ac0b4dc0c3b7fa66c88304225d301a/python/lsst/ts/standardscripts/base_stop_tracking.py>`__)
     - No configuration
   * - Mirror cover operations
     - | :file:`{p1}/close_mirror_covers.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/close_mirror_covers.py>`__)
       | :file:`{p1}/open_mirror_covers.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/open_mirror_covers.py>`__)
       |
       | If El < 20°, script moves TMA to El 20°.
       | Close (deploy) OR open (retract) the mirror covers.
       | Lock M1M3 mirror covers.
     - No configuration
   * - Change the performance setting for the TMA
     - | ``run_command.py``
       |
       | Remember to restore to default, as the settings are cumulative.
     - | .. code-block:: python
          :caption: run_command.py

          cmd: applySettingsSet
          component: MTMount
          parameters:
            restoreDefaults: true
            settings: 10percentperformance

   * - Restore to TMA default settings
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          cmd: restoreDefaultSettings
          component: MTMount

   * - Unpark mount
     - :file:`{p2}/unpark_mount.py`
     - No configuration
   * - Park mount
     - :file:`{p2}/park_mount.py`
     - In testing. DO NOT use (2026-6-16).


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
   * - Issue correction
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTAOS
          cmd: issueCorrection

   * - Reset correction
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTAOS
          cmd: resetCorrection

   * - Reset Offset DOF
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTAOS
          cmd: resetOffsetDOF

   * - Enable/Disable AOS closed-loop
     - | :file:`enable_aos_closed_loop.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_aos_closed_loop.py>`__)
       | :file:`disable_aos_closed_loop.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/disable_aos_closed_loop.py>`__)
     - | .. code-block:: python
          :caption: enable_aos_closed_loop.py

          used_dofs: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
          truncation_index: [2]
          zn_selected: [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20, 21, 22, 27, 28]

   * - Set the absolute state of the telescope DOFs
     - | :file:`set_dof.py`
       |
       | No default configuration.
       | To ignore a component:
       |
       | ``ignore:``
       | ``- mtmount``
       | ``- mthexapod_1``
       | ``- mthexapod_2``
       | ``- mtrotator``
     - | Uses a **previous image**:

       .. code-block:: python
          :caption: set_dof.py

          day: 20250630
          seq: 457

       | Apply **individual dofs** (microns or arcsec):

       .. code-block:: python

          # Example: M1M3 bending mode 16
          M1M3_B16: 0.3

          # Example: M2 hexapod offset in x
          M2_dx: 5

       | Apply **multiple dofs** (50-dimensional vector):
       | [0-4]: M2 Rigid Body Motions
       | [5-9]: Camera Rigid Body Motions
       | [10-29]: M1M3 Bending Modes
       | [30-49]: M2 Bending Modes

       .. code-block:: python

          dofs: [0.0, 1.0, 2.0, 3.0, 4.0,
          5.0, 6.0, 7.0, 8.0, 9.0,
          10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,
          20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,
          30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,
          40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0]

   * - Apply a DOF to the main telescope (bending mode or hexapod offset)
     - :file:`apply_dof.py`
     - Same configurations as ``set_dof.py``.
   * - Enable and run closed-loop system on the AOS for LSSTCam
     - :file:`close_loop_lsstcam.py`
     - | .. code-block:: python
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

   * - Adjust M2/Camera Hexapods to focus PSFs manually
     - | :file:`offset_m2_hexapod.py`
       | :file:`offset_camera_hexapod.py`
     - | If the first image shows a donut rather than a PSF, adjust by hand.
       | Change the camera hexapod z by Dz = [(donut diameter in pixels) * 12] microns.

       .. code-block:: python
          :caption: offset_camera_hexapod.py

          z: -Dz

       | If that makes things worse (bigger donuts):

       .. code-block:: python

          z: +2 x Dz

   * - Take Triplet Sequence with LSSTCam
     - | :file:`take_aos_sequence_lsstcam.py`
       |
       | Defaults:
       | ``filter:``
       | ``exposure_time: 30``
       | ``dz: 1500``
       | ``n_sequences: 1``
       | ``mode: TRIPLET``
       | ``program: AOSSEQUENCE``
     - | .. code-block:: python
          :caption: take_aos_sequence_lsstcam.py

          filter: z_03
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
   * - Enable/Disable dome following mode
     - | :file:`/enable_dome_following.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/enable_dome_following.py>`__)
       | :file:`/disable_dome_following.py`
     - No configuration
   * - Offset MTDome in Az
     - | :file:`/offset_dome.py`
       |
       | Units of ``az`` in degrees.
     - | .. code-block:: python
          :caption: offset_dome.py

          offset: 10

   * - Slew MTDome in Az
     - | :file:`/slew_dome.py`
       |
       | Units of ``az`` in degrees.
     - | .. code-block:: python
          :caption: slew_dome.py

          az: 70
          ignore:
            - mtmount
            - mthexapod_1
            - mthexapod_2

   * - Park / Unpark MTDome
     - | :file:`/park_dome.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/park_dome.py>`__)
       | :file:`/unpark_dome.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/unpark_dome.py>`__)
     - | .. code-block:: python
          :caption: park_dome.py

          ignore:
            - mtm1m3
            - mtm2
            - mtaos
            - mtdometrajectory
            - mthexapod_1
            - mthexapod_2

   * - Open/Close MTDome
     - | :file:`/open_dome.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/open_dome.py>`__)
       | :file:`/close_dome.py`
       |
       | Both scripts have the ``force`` property, useful to bypass errors
       | or conditions (e.g., dome telemetry reports shutters in wrong state,
       | mirror covers lost instead of closed).
     - | No configuration, but you can ignore certain CSCs:

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

   * - Open/Close MTDome (via run_command)
     - ``run_command.py``
     - | To open:

       .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: openShutter

       | To close:

       .. code-block:: python

          component: MTDome
          cmd: closeShutter

   * - Open Dome Louvers
     - | ``run_command.py``
       |
       | The array values are between 0.0 (**closed**) and 100.0 (fully **open**).
       |
       | Louver index (0-based):
       | [A1, A2, **B1**, B2, B3, C1, C2, C3, D1, D2, D3, **E1**, **E2**, E3,
       | F1, F2, F3, G1, G2, G3, **H1**, **H2**, H3, I1, I2, I3, L1, L2, L3,
       | **M1**, M2, M3, N1, N2]
       |
       | Bold = louvers available as of 2026-2-14.
     - | .. code-block:: python
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

   * - Close Dome Louvers
     - | ``run_command.py``
       |
       | Alternatively use the ``setLouvers`` command with value 0 in the
       | louver index you want to close.
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: closeLouvers

   * - Stop dome and engage brakes
     - | ``run_command.py``
       |
       | ``stop`` `command <https://ts-xml.lsst.io/sal_interfaces/MTDome.html#stop>`__
       | DomeAz: ``subSystemIds: 0x1``
       | Dome shutter: ``subSystemIds: 0x4``
       | Louvers: ``subSystemIds: 0x8``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: stop
          parameters:
            engageBrakes: true
            subSystemIds: 0x?

   * - Recover from Dome Az FAULT
     - | :file:`/recover_from_controller_fault.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/recover_from_controller_fault.py>`__)
       |
       | ``delta_move: 3.0``
       |
       | Clears a dome controller fault, moves the dome slightly to confirm
       | it works again, and re-enables dome following if successful.
     - No configuration required
   * - Exit Fault/Clear fault in subsystem
     - | ``run_command.py``
       |
       | DomeAz: ``subSystemIds: 0x1``
       | Dome shutter: ``subSystemIds: 0x4``
       | Louvers: ``subSystemIds: 0x8``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: exitFault
          parameters:
            subSystemIds: 0x?

   * - Reset dome drives
     - | ``run_command.py``
       |
       | (``exitFault`` will issue a ``resetDrivesAz`` internally; probably not needed)
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: resetDrivesAz
          parameters:
            reset: [1,1,1,1,1]

   * - Reset Dome shutter drives
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: resetDrivesShutter
          parameters:
            reset: [1,1,1,1]

   * - Home Dome Az
     - | :file:`/home_dome.py`
       |
       | Required: ``physical_az`` (azimuth position as read by markings).
       |
       | See `Homing MTDome procedure <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/705003522>`__.
     - | .. code-block:: python
          :caption: home_dome.py

          physical_az: <physical position as read by markings>
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

   * - Home Dome shutter
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: home
          parameters:
            subSystemIds: 0x4

   * - Set dome shutter to degraded mode
     - | ``run_command.py``
       |
       | Dome operational modes:
       | **1:** Normal mode
       | **2:** Degraded mode
     - | .. code-block:: python
          :caption: run_command.py

          component: MTDome
          cmd: setOperationalMode
          parameters:
            operationalMode: 2
            subSystemIds: 0x4

   * - Crawl - Move the azimuth axis at constant velocity
     - | :file:`/crawl_az.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/mtdome/crawl_az.py>`__)
       |
       | Includes ``position`` and ``velocity`` properties.
       | Speed in deg/second.
       |
       | Default config:
       | ``direction: ClockWise``
     - | .. code-block:: python
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
     - | :file:`enable_lsstcam.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/enable_lsstcam.py>`__)
     - Not available
   * - Put LSSTCam in STANDBY
     -
     - Not available
   * - Focus Sweep
     - | :file:`focus_sweep_lsstcam.py`
       |
       | Properties with default config:
       | ``sim: false``
       | ``hexapod: Camera``
       | ``filter: null``
       | ``exp_time: 10``
       | ``axis: ["x", "y", "z", "u", "v"]``
       | ``focus_window:``
       | ``n_steps:``
       | ``focus_step_sequence:``
       | ``n_images_per_step: 1``
       | ``program: FOCUS_SWEEP``
       | ``reason: null``
       | ``ignore:``
       |
       | Units are microns.
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
     - | :file:`change_filter_lsstcam.py`
       |
       | Required: ``filter``
     - | .. code-block:: python
          :caption: change_filter_lsstcam.py

          filter: <filter_name>

   * - Take Image
     - | :file:`take_image_lsstcam.py`
       |
       | ``filter:``
       | ``nimages: null``
       | ``exp_times: 0``
       | ``image_type: ["BIAS", "DARK", "FLAT", "OBJECT", "ENGTEST", "ACQ", "SPOT", "CWFS", "FOCUS"]``
       | ``reason:``
       | ``program:``
       | ``note:``
       |
       | Required: ``image_type``
     - | .. code-block:: python
          :caption: take_image_lsstcam.py

          image_type: BIAS

       .. code-block:: python

          image_type: FLAT
          exp_times: 5
          nimages: 2
          reason: "flat_test"

       .. code-block:: python

          image_type: ACQ
          exp_times: 1
          program: "BLOCK-TXXXX"

       .. code-block:: python

          image_type: ENGTEST
          exp_times: 30
          nimages: 1

   * - Track target and take image
     - :file:`track_target_and_take_image_lsstcam.py`
     - | All these are required:

       .. code-block:: python
          :caption: track_target_and_take_image_lsstcam.py

          ra:
          dec:
          rot_sky:
          name:
          obs_time:
          num_exp:
          exp_times:
          band_filter:

   * - Take Stuttered
     - :file:`take_stuttered_lsstcam.py`
     - | Configuration in
       | `take_stuttered_lsstcam.py source <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/take_stuttered_lsstcam.py>`__
   * - Take Triplets
     - | :file:`maintel/take_aos_sequence_lsstcam.py`
       |
       | ``filter:``
       | ``exposure_time: 30``
       | ``dz: 1500``
       | ``n_sequences: 1``
       | ``mode: TRIPLET``
       | ``program: AOSSEQUENCE``
     - | .. code-block:: python
          :caption: take_aos_sequence_lsstcam.py

          filter: z_03
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
   * - Align the TMA to the calibration screen
     - | :file:`laser_tracker/align.py`
       | (`code <https://github.com/lsst-ts/ts_maintel_standardscripts/blob/develop/python/lsst/ts/maintel/standardscripts/laser_tracker/align.py>`__)
       |
       | Default config:
       | ``max_iter: 10``
       | ``tolerance_linear: 0.0001`` (meters)
       | ``tolerance_angular: 0.00138`` (deg, ~5 arcsec)
       | ``target: M2`` (REQUIRED)
       |
       | ``target`` options: "M2", "Camera", "CALIBRATION_SCREEN"
     - | .. code-block:: python
          :caption: laser_tracker/align.py

          target: CALIBRATION_SCREEN
          tolerance_angular: 0.01
          reason: "Align TMA to Calibration Screen"
          program: "BLOCK-T495"

       .. note::

          The LaserTracker Measurement of the Calibration screen is done now
          using ``id: BLOCK-T495``.

   * - Park the lasertracker
     - ``run_command.py``
     - | .. code-block:: python
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
   * - MTReflector
     - Open/close MTReflector
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: MTReflector
          cmd: open

       | (or ``cmd: close``)

   * -
     - Park the calibration projector
     - :file:`maintel/park_calibration_projector.py`
     - No configuration
   * -
     - Setup LEDProjector for White light flats
     - | :file:`maintel/setup_whitelight_flats.py`
       |
       | Default config:
       | ``sequence_name: "whitelight_u_source"``
       | ``ignore: ['TunableLaser','LinearStage:104','FiberSpectrograph:101','FiberSpectrograph:102','CBP','Electrometer:102','Electrometer:101']``
     - | .. code-block:: python
          :caption: setup_whitelight_flats.py

          sequence_name: 'laser_functional'
          ignore: ['LinearStage:104','FiberSpectrograph:101','FiberSpectrograph:102','CBP','Electrometer:102','Electrometer:101']

   * -
     - Take whitelight flats for a given setup
     - | :file:`maintel/take_whitelight_flats_lsstcam.py`
       | (`code <https://github.com/lsst-ts/ts_externalscripts/blob/develop/python/lsst/ts/externalscripts/maintel/take_whitelight_flats_lsstcam.py>`__)
       |
       | Default will run for all installed filters:
       | ``sequence_names: ["daily"]``
       | Metadata: ``note``, ``reason``, ``program``
     - | .. code-block:: python
          :caption: take_whitelight_flats_lsstcam.py

          sequence_names: ['low_level_ptc']
          reason: "low_level_led_ptc"
          program: "BLOCK-T572"

   * - CBP
     - Move the CBP Az, El position
     - | ``run_command.py``
       |
       | ``azimuth`` and ``elevation`` are float in degrees.
       | Az: [-45.0 to 45.0 deg]
       | El: [-69.0 to 45.0 deg]
     - | .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: move
          parameters:
            azimuth: -0.05
            elevation: -46.5

   * -
     - Change the CBP mask
     - | ``run_command.py``
       |
       | There are 5 masks to characterize the beam projection.
     - | .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: changeMask
          parameters:
            mask: '1'

   * -
     - Rotate the CBP mask
     - | ``run_command.py``
       |
       | Rotation is between 1 and 360 deg.
     - | .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: changeMaskRotation
          parameters:
            mask_rotation: 96.5

   * -
     - Set CBP focus
     - | ``run_command.py``
       |
       | Focus in microns. Range is (0, 13000).
     - | .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: setFocus
          parameters:
            focus: 3800

   * -
     - Park CBP (moves to elevation -70, locks the motors)
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: CBP
          cmd: park

   * - Tunable Laser
     - Set tunable laser wavelength
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          component: TunableLaser
          cmd: changeWavelength
          parameters:
            wavelength: 750

   * -
     - Set laser output configuration
     - | ``run_command.py``
       |
       | Configurations available: (see XML documentation)
     - | .. code-block:: python
          :caption: run_command.py

          cmd: setOpticalConfiguration
          parameters:
            configuration: F2 SCU

   * -
     - Change tunable laser mode
     - | ``run_command.py``
       |
       | Available modes: ``setBurstMode`` and ``setContinuousMode``.
     - | .. code-block:: python
          :caption: run_command.py

          component: TunableLaser
          cmd: setBurstMode

   * -
     - Start/stop tunable laser propagation
     - | ``run_command.py``
       |
       | Start cmd: ``startPropagateLaser``
       | Stop cmd: ``stopPropagateLaser``
       |
       | Note: requires setting the mode first.
     - | .. code-block:: python
          :caption: run_command.py

          component: TunableLaser
          cmd: startPropagateLaser

   * -
     - Set laser output to F2 SCU
     - ``run_command.py``
     - | .. code-block:: python
          :caption: run_command.py

          cmd: setOpticalConfiguration
          parameters:
            configuration: F2 SCU


.. _Simonyi-SAL-Scripts-Scheduler:

Scheduler
=========

.. list-table::
   :widths: 20 40 40
   :header-rows: 1

   * - Command
     - SAL Script
     - Script Configuration
   * - Enable Scheduler:1
     - | :file:`maintel/scheduler/enable.py`
       |
       | Properties: ``config`` (string): Name of the configuration .yaml file.
       | This loads the .yaml configuration file and can also be used to
       | state-cycle the scheduler.
     - | .. code-block:: python
          :caption: maintel/scheduler/enable.py

          config: <config_file_name>.yaml

   * - Start scheduler-driven observations
     - :file:`maintel/scheduler/resume.py`
     - No configuration
   * - Stop scheduler-driven observations
     - :file:`maintel/scheduler/stop.py`
     - No configuration
   * - Start a testing BLOCK
     - | :file:`maintel/scheduler/add_block.py`
       |
       | Properties:
       | ``id`` (string): Name of the BLOCK to be run.
       | ``override``: List of parameters to be changed/updated in the BLOCK.
       |
       | Current available BLOCKs listed
       | `here <https://rubinobs.atlassian.net/projects/BLOCK?selectedItem=com.atlassian.plugins.atlassian-connect-plugin:com.kanoah.test-manager__main-project-page#!/v2/testCases?projectId=10064>`__.
     - | e.g. Measurement of Laser Tracker targets:

       .. code-block:: python
          :caption: maintel/scheduler/add_block.py

          id: BLOCK-T89


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
     - | Default config:

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



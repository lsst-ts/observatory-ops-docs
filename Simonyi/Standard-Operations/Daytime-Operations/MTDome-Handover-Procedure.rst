.. |author| replace:: *Kris Mortensen (AI-Assisted)*
.. |contributors| replace:: *none*

.. _Standard-Operations-MTDome-handover:

#############################
MTDome Handover Procedure
#############################

.. _Standard-Operations-MTDome-handover-Overview:

Overview
========

The MTDome Handover Procedure ensures the dome is ready for nighttime observations.
The majority of this procedure is carried out by the daytime engineering team, 
usually starts around 3:30pm CLT. 

The team starts with a walk around, which consists of 
carefully walking the dome floor and ensuring it is clear for movement. 
Then they check the dome controller by moving it to an azimuth of 328 deg, 
and then configure it for remote control. Finally, the observing team must 
perform a test to move the Dome Az, shutter and Louvers remotely via CSC. 
If that test succeeds, the handover is complete.

This document focuses on the actions performed by the **Observing Specialist (OS)** team
to test motion control via CSC. The complete dome handover procedure is described 
in the Rubin Technical Document (RTD-1131).

**Points of Contact:** Juan Fabrega, Luis Vergara, Hernán Herrera, and Eduardo Serrano.


.. admonition:: Reminder
   :class: note

   The ``subSystemIds`` for the Dome components are:

   * DomeAz: ``0x1``
   * Dome shutter: ``0x4``
   * Louvers: ``0x8``

.. _Standard-Operations-MTDome-handover-Precondition:

Precondition
============

* Laptops are configured and pre-loaded with necessary tools before arriving at Level 7.
* **M1M3 mirror cover is closed (deployed)** to protect the mirror during dome shutter tests.

  * **Exception:** If the TMA is parked at the horizon, the shutter may be opened slightly without the mirror cover deployed.

* The Electrical team has delivered the dome at 328 degrees.
* Capacitor banks are connected (if operating in full performance).
* Dome crane lights are off.
* Access to `main-brick01.cp.lsst.org <http://main-brick01.cp.lsst.org/>`_ (Windows 10 VM via `https://ls.st/main-brick01 <https://ls.st/main-brick01>`_) is verified for troubleshooting.

.. _Standard-Operations-MTDome-handover-Post-Condition:

Post-Condition
==============

* MTDome control is given to the observing team and can be controlled remotely via CSC.

.. _Standard-Operations-MTDome-handover-Procedure-Steps:

Procedure Steps
===============

.. _Standard-Operations-MTDome-handover-Preliminary-verifications:
1\. Preliminary Verifications
----------------------------

1. **Weather Assessment**
   
   If there was precipitation, high humidity, or low temperature the previous day, assess the dome for ice or snow to prevent falls onto the TMA:
   
   a. Park the TMA near zenith (>80°).
   b. Ensure authorized personnel inspect the panoramic platform via the hatches.
   c. If no ice or snow is present, proceed to open the dome shutter.
   
   .. warning::
      If no personnel are available to perform the inspection, the dome must remain closed. 
      If weather was bad but no snow/freezing occurred, follow the 
      `MTDome Post-Bad Weather Safety Inspection <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/966262786>`__ 
      procedure.

2. **Assert Dome Status**

   a. Confirm the dome is in the parking position (328 deg).
   b. Confirm the dome is in **remote mode** and at least 2 minutes have elapsed since the mode change.
   c. Confirm capacitor banks are connected (for Full Performance).
   d. Transition the **MTDome CSC** from ``STANDBY`` to ``DISABLED``.

   .. note::
      When switching to remote mode, listen for a click from the brakes engaging. In the `MTDome Azimuth Status Dashboard <https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/165?refresh=Paused&lower=now%28%29%20-%2015m>`_, the *Azimuth Motion State* should be ``STOPPED_BRAKED``.

   .. warning::
      Allow sufficient time for the MTDome CSC to stabilize after a state transition before issuing further commands.

3. **Verify Shutter Mode**

   Verify the Dome shutter is in **normal mode** using the `Simonyi Integrated Telemetry Dashboard <https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/423?refresh=Paused&lower=now%28%29%20-%206h>`_.

   To change the operational mode if necessary, use ``run_command.py``:

   .. code-block:: yaml

      component: MTDome
      cmd: setOperationalMode
      parameters:
        operationalMode: 1
        subSystemIds: 0x4

.. _Standard-Operations-MTDome-handover-Enable-MTDome-CSC:

2\. Enable MTDome CSC
-----------------------

1. Transition **MTDome CSC** from ``DISABLED`` to ``ENABLED``, and **wait 2-3 min**.
2. Clear any low-level faults, if present (refer to :ref:`Standard-Operations-MTDome-handover-Dome-Az-cRIO-reboot` ).

.. _Standard-Operations-MTDome-handover-Dome-Az-Checkout:

3\. Dome Az Checkout
----------------------

1. **Verify Position** 

   If telemetry does not match 328 degrees (`MTDome Azimuth Status Dashboard <https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/165?refresh=Paused&lower=now%28%29%20-%2015m>`__), 
   follow the `Homing the Dome <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/705003522>`__ 
   procedure.

2. | **Test Motion**
   | Move the Dome Az via CSC in both directions:

   a. Move to Az: 320 deg
   b. Wait until stopped and verify via the dashboard.
   c. Move to Az: 90 deg (position away from the Sun).

   | Use the following configuration with the ``maintel/mtdome/slew_dome.py`` script:

   .. code-block:: yaml

      az: 320
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

   .. caution::

      If this step doesn’t move refer to :ref:`Standard-Operations-MTDome-handover-Dome-Az-cRIO-reboot`.

3. **Engage Dome Azimuth Brakes** 

   Use :file:`run_command.py`:

   .. code-block:: yaml

      component: MTDome
      cmd: stop
      parameters:
        engageBrakes: True
        subSystemIds: 1

.. _Standard-Operations-MTDome-handover-Dome-Louvers-checkout:

4\. Dome Louvers checkout
---------------------------

1. Partially open the Louvers to 10% using :file:`run_command.py` 
   (Currently available: B1, E1, E2, H1, H2, M1).

   .. code-block:: yaml

      component: MTDome
      cmd: setLouvers
      parameters:
        position: [0.0, 0.0, 10.0, 0.0, 0.0,
                   0.0, 0.0, 0.0, 0.0, 0.0,
                   0.0, 10.0, 10.0, 0.0, 0.0,
                   0.0, 0.0, 0.0, 0.0, 0.0,
                   10.0, 10.0, 0.0, 0.0, 0.0,
                   0.0, 0.0, 0.0, 0.0, 10.0,
                   0.0, 0.0, 0.0, 0.0]

2. Close the Louvers using :file:`closeLouvers`.

   .. code-block:: yaml

      component: MTDome
      cmd: closeLouvers

.. _Standard-Operations-MTDome-handover-Dome-shutter-checkout:

5\. Dome shutter checkout
---------------------------

.. caution::

   If the dome shutter has faults refer to :ref:`Standard-Operations-MTDome-handover-Clear-Dome-shutter-fault`.

1. Ensure :ref:`Preconditions <Standard-Operations-MTDome-handover-Precondition>`
   are met (mirror covers closed, dome pointing South, etc.).
2. Using **MTQueue**, run the block ``BLOCK-T70``. This script performs:
   
   a. Open shutter.
   b. Wait 5 seconds.
   c. Stop shutter.
   d. Close shutter.

   Configuration for ``maintel/scheduler/add_block.py``:

   .. code-block:: yaml

      id: BLOCK-T70
      override:
        sleep_for: 5

.. warning::
   **Safety Critical**: Monitor the shutter and script execution closely. 
   If the block fails while the shutter is opening, the ``stop`` and ``closeShutter`` 
   commands will not execute. You must manually issue ``stop`` followed by 
   ``closeShutter`` immediately.

   .. dropdown:: ``run_command.py`` Configurations

      .. tab-set::

         .. tab-item:: stop

            .. code-block:: text

               component: MTDome
               cmd: stop
               parameters:
               subSystemIds: 0x4

         .. tab-item:: closeShutter

            .. code-block:: text

               component: MTDome
               cmd: closeShutter

.. _Standard-Operations-MTDome-handover-Turn-lights-off:

6\. Turn lights off
---------------------

1. Confirm the physical switch in the dome shutter drives cabinet (Level 8) is set to **OFF**.
2. Park the dome using :file:`park_dome.py`.
3. Disable MTDome using :file:`set_summary_state.py`.
4. Use the `dome trapped key <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/668893185>`__.
5. Manually turn off the lights from the Level 8 cabinet using the **Manual Override Lighting Control** switch..
6. Verify that scheduled lights (e.g., 18:30 or 19:30 CLT) turned off automatically.
7. Perform a final visual inspection to ensure all lights (including Level 3 and PFlow) are off before observing.

.. note::

   | **Important**
   | Coordinate with the day crew to have all the lights in lower levels also turned off when they finish their work around 17:15 CLT. Make sure someone is responsible for turning off the light.

.. _Standard-Operations-MTDome-handover-Troubleshooting:

Troubleshooting
===============

.. _Standard-Operations-MTDome-handover-Clear-Dome-Az-fault:

Clear Dome Az fault
-------------------

If a **FAULT** is reported in the *Azimuth Control Software Status*:

1. Send an ``exitFault`` command.
2. If ``exitFault`` fails due to an "incorrect state," issue a ``stop`` command to engage brakes.
3. If the ``stop`` command is refused with a "drive in fault" message, issue a ``resetDrivesAz`` command
   to reset the azimuth drives.
4. Retry the ``stop`` command, then the ``exitFault`` command.

.. dropdown:: ``run_command.py`` Configurations

   .. tab-set::

      .. tab-item:: exitFault

         .. code-block:: text

            component: MTDome
            cmd: exitFault
            parameters:
              subSystemIds: 0x1

      .. tab-item:: stop

         .. code-block:: text

            component: MTDome
            cmd: stop
            parameters:
              engageBrakes: true
              subSystemIds: 0x1

      .. tab-item:: resetDrivesAz

         .. code-block:: text

            component: MTDome
            cmd: resetDrivesAz
            parameters:
              reset: [true, true, true, true, true]

.. _Standard-Operations-MTDome-handover-Dome-Az-cRIO-reboot:

Dome Az cRIO reboot
-------------------

If we cannot clear faults and move the Dome Az. It is likely the cRIO must be rebooted, check the `detailed instructions <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39691463>`__, but in summary the steps are:

1. Set **MTDome CSC** to ``STANDBY``.
2. Open `ls.st/main-brick01 <https://ls.st/main-brick01>`__ to log into the `http://main-brick01.cp.lsst.org <http://main-brick01.cp.lsst.org>`__
3. Wait 2-3 mins, and then set **MTDome CSC** to ``ENABLED``.

* This will reset the zero position in the cRIO so after a reboot there is no need to home the dome . After a reboot, you may need to send an ``exitFault`` command (see step 2). If the azimuth control software is not in fault, the command will still be accepted.

Now, you should be able to move the dome via CSC. Sometimes you will have to state cycle the MTDome if the telemetry is lost.


.. warning::

   If the previous step did not work, the cRIO must be **rebooted manually**.

   * Consider asking electrical team to power cycle the drives at L7.
   * Alternatively, in an emergency situation, ask a Summit Support Scientist if they can follow the EIE procedure (08815-PRO314a). 
     After power cycling the drives, you should restart the procedure.

.. _Standard-Operations-MTDome-handover-Clear-Dome-Louver-faults:

Dome Shutter/Louvers Faults
---------------------------

*  If the dome shutter has faults, try an ``exitFault`` command. 
   If the faults persist, you may need to issue a ``resetDrivesShutter`` command.

   .. dropdown:: ``run_command.py`` Configurations

      .. tab-set::

         .. tab-item:: exitFault

            .. code-block:: text

               component: MTDome
               cmd: exitFault
               parameters:
               subSystemIds: 0x4

         .. tab-item:: resetDrivesShutter

            .. code-block:: text

               component: MTDome
               cmd: resetDrivesShutter
               parameters:
               reset: [true,true,true,true]

.. _Standard-Operations-MTDome-handover-Clear-Louvers-fault:

*  If the louvers have faults, try an ``exitFault`` command.

   .. code-block:: text

      component: MTDome
      cmd: exitFault
      parameters:
      subSystemIds: 0x8

Contingency
===========

If the procedure was not successful, report the issue in `#mtdome-worklog <https://rubin-obs.slack.com/archives/C07QFRT36QM>`__ on Slack, or contact one of the following dome experts for assistance:

* Wouter van Reeven (Primary Contact)
* Marina Pavlovic
* Brian Stalder
* Lorenzo Vio
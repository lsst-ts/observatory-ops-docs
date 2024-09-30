.. _AuxTel-AuxTel-Troubleshooting:

###################
AuxTel Known Faults
###################

A comprehensive list of common faults will be displayed here along their troubleshooting procedures. 

.. list-table:: Known Faults
   :widths: 10 50 20 40 
   :header-rows: 1 

   * - CSC
     - Issue/Diagnosis
     - Happens mostly when
     - Troubleshooting procedure
   * - ATCS
     - Scripts failed with a "Rejected: Rotator out of range" error and ATPtg might go into ``FAULT``. 
     - Observing at night
     - Cycle ATPtg and queue top :file:`correct_pointing.py`. See details in ...TBC.
   * - 
     - AT out of focus after a 'WEP' failure -> Clear ATAOS offsets + 'WEP'
     - Observing at night
     - Pause ATScriptQueue. Clear all ATAOS offsets for the x, y, and z axes. Run the standard scripts "offset_ataos" and "latiss_wep_align" to realign the mirror and focus the system. See details in...TBC
   * - 
     - AuxTel M1 Cover Fails to Open.
     - Daytime Checkout - Pneumatics / Calibrations / Prepare for on sky
     - Set all ATCS CSCs to STANDBY using :file:`standby_atcs.py`. Then, log in to the ATMCS EUI via Microsoft Remote Desktop or the control computer in the AuxTel dome. See details in :ref:`AuxTel M1 Cover Fails to Open <AuxTel-Troubleshooting-AuxTel-M1-Cover-Fails-To-Open>`. See also the explanation `video <https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2>`__.
   * - AT Mount
     - ATMount fails to move and times out
     - Observing at night
     - Stop the scheduler and clear the queue with :file:`auxtel/scheduler/stop.py`, cycle ATTCS:ATPtg CSC to standby and enabled, then confirm mount responsiveness by running :file:`auxtel/point_azel.py` and observing mount motion. See details in :ref:`AuxTel Mount Fails to Move and Times Out <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move-and-Times-Out>`. 
   * -      
     - ATMount fails to move and Azimuth Max Velocity error exceeded
     - Observing at night
     - Stop the scheduler with :file:`auxtel/scheduler/stop.py`, Cycle ATTCS:ATMCS and ATPtg (if needed) CSCs, then use :file:`auxtel/point_azel.py` to slew the telescope to a lower elevation and adjust azimuth in increasing increments. See details in :ref:`AuxTel Mount Fails to Move <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move>`.
   * -      
     - ATHexapod fails to enable - No connection to athexapod controller
     - Daytime Checkout -Enabling ATCS
     - Turn off the C-887 Hexapod Controller in the Main ATCS cabinet on the first level of the AuxTel dome, wait 3 minutes, then turn it back on. Transition ATHexapod CSC from ``STANDBY`` to ``ENABLE``. See details in :ref:`ATHexapod fails to enable with the rest of ATCS <ATHexapod-fails-to-enable-with-the-rest-of-ATCS>`.
   * - 
     - ATMCS fails to enable - e-stop is engaged
     - Daytime Checkout -Enabling ATCS
     - Check the ATMCS EUI for a red Emergency Stop indicator via the dome pier computer or remote connection to aux-brick01.cp.lsst.org. If engaged, release it using the provided procedure, confirm it’s released, and re-run :file:`auxtel/enable_atcs.py` from LOVE. See details in :ref:`AuxTel Mount Control System Fails to Enable / E-Stop is Engaged <ATCS-Troubleshooting-AuxTel-Mount-Control-System-Fails-to-Enable>`.
   * - AT Instrumentation
     - ATCamera Recovering from Fault State
     - When a parameter (temperature, voltage, current, etc.) exceeds its tolerance.
     - Identify the problematic CCS subsystem, review alerts and logs, and determine if the issue is transitory or requires expert diagnosis. Create an OBS ticket to track the problem. Clear alerts in the CCS subsystem and the Master Control Module (MCM). Clear the fault in the ocs-bridge and switch it to OFFLINE_AVAILABLE mode. See details in :ref:`AT camera recovery <LATISS-Troubleshooting-ATcamera-recovery>`.
   * - AT Calibration System
     - ATWhiteLight has thrown the error below saying the light failed to come on when it was on
     - During Calibrations
     - Try re-adding the calibration block, power_on_atcalsys should register that the white light lamp is on and calibrations can continue successfully. See details in ...TBC
   * - AT Dome
     - ATDome shutter fails to close.
     - While trying to move the telescope with point_azel.
     - Try the top black button on the control box at the dome’s top, if unsuccessful, then try the “CLOSE” switch on the cRIO box with caution. If all else fails, use the manual crank on the first floor, though it’s a slow process. See details in...TBC


Per component
=============

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    ATCS/index.rst


.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    LATISS/index.rst


.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    ATCalSys/index.rst


.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    General-Troubleshooting/index.rst
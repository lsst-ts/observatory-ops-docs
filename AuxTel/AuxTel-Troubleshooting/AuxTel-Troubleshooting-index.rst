.. _AuxTel-AuxTel-Troubleshooting:

######################
AuxTel Troubleshooting
######################

A comprehensive list of common faults will be displayed here along their troubleshooting procedures. 

.. list-table:: Known Faults
   :widths: 10 50 20 40 
   :header-rows: 1 

   * - CSC
     - Issue/Diagnosis
     - Happens mostly when
     - Troubleshooting procedure
   * - ATCS
     - Scripts failed with a "Rejected: Rotator out of range" error and ATPtg might go into FAULT. 
     - Observing at night
     - recover ATPtg and queue top correct_pointing.py
   * - 
     - AT out of focus after a 'WEP' failure -> Clear ATAOS offsets + 'WEP'
     - Observing at night
     - Pause ATScriptQueue. Clear all ATAOS offsets for the x, y, and z axes. Run the standard scripts "offset_ataos" and "latiss_wep_align" to realign the mirror and focus the system.
   * - 
     - AuxTel M1 Cover Fails to Open.
     - Daytime Checkout - Pneumatics / Calibrations / Prepare for on sky
     - Set all ATCS CSCs to STANDBY using standby_atcs.py. Then, log in to the ATMCS EUI via Microsoft Remote Desktop or the control computer in the AuxTel dome. Follow the instructions from video: https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2
   * - AT Mount
     - ATMount fails to move and times out 
     - Observing at night
     - Stop the scheduler and clear the queue with auxtel/scheduler/stop.py, cycle ATTCS:ATPtg CSC to standby and enabled, then confirm mount responsiveness by running auxtel/point_azel.py and observing mount motion.
   * - 
     - ATMount fails to move - and Azimuth Max Velocity error exceeded
     - Observing at night
     - Stop the scheduler with auxtel/scheduler/stop.py, Cycle ATTCS:ATMCS and A(TTCS:ATPtg if needed) CSCs, then use auxtel/point_azel.py to slew the telescope to a lower elevation and adjust azimuth in increasing increments.
   * - 
     - ATHexapod fails to enable - No connection to athexapod controller
     - Daytime Checkout -Enabling ATCS
     - Turn off the C-887 Hexapod Controller in the Main ATCS cabinet on the first level of the AuxTel dome, wait 3 minutes, then turn it back on. Transition ATHexapod CSC from STANDBY to ENABLE, and fill out the OBS-243 ticket with relevant details about the system state and prior maintenance.
   * - 
     - ATMCS fails to enable - e-stop is engaged
     - Daytime Checkout -Enabling ATCS
     - Check the ATMCS EUI for a red Emergency Stop indicator via the dome pier computer or remote connection to aux-brick01.cp.lsst.org. If engaged, release it using the provided procedure, confirm it's released, and re-run auxtel/enable_atcs.py from LOVE.
   * - AT Instrumentation
     - ATCamera Recovering from Fault State
     - When a parameter (temperature, voltage, current, etc.) exceeds its tolerance.
     - Identify the problematic CCS subsystem, review alerts and logs, and determine if the issue is transitory or requires expert diagnosis. Create an OBS ticket to track the problem. Clear alerts in the CCS subsystem and the Master Control Module (MCM). Clear the fault in the ocs-bridge and switch it to OFFLINE_AVAILABLE mode.
   * - AT Calibration System
     - ATWhiteLight has thrown the error below saying the light failed to come on when it was on 
     - During Calibrations
     - Try re-adding the calibration block, power_on_atcalsys should register that the white light lamp is on and calibrations can continue successfully.
   * - AT Dome
     - ATDome shutter fails to close.
     - While trying to move the telescope with point_azel.
     - Try the top black button on the control box at the dome's top, if unsuccessful, then try the "CLOSE" switch on the cRIO box with caution. If all else fails, use the manual crank on the first floor, though it's a slow process.
   


Per component
=============

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    ATCS-Troubleshooting/ATCS-Troubleshooting-index.rst


.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    LATISS-Troubleshooting/LATISS-Troubleshooting-index.rst 


.. toctree::
    :maxdepth: 3
    :titlesonly:
    :glob:

    ATCalSys-Troubleshooting/ATCalSys-Troubleshooting-index.rst


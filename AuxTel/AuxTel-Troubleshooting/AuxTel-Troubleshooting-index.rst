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
     - ATMount fails to move - and Azimuth Max Velocity error exceeded
     - Observing at night
     - Stop the scheduler. Cycle ATTCS:ATMCS (and ATTCS:ATPtg if needed) to standby and back to enabled. Use auxtel/point_azel.py to slew the telescope incrementally, adjusting azimuth and elevation as needed, and increase azimuth slews if the mount is stuck..
   * - 
     - Scripts failed with a "Rejected: Rotator out of range" error and ATPtg might go into FAULT. 
     - Observing at night
     - recover ATPtg and queue top correct_pointing.py
   * - 
     - AT out of focus after a 'WEP' failure -> Clear ATAOS offsets + 'WEP'
     - Observing at night
     - Pause ATScriptQueue. Clear all ATAOS offsets for the x, y, and z axes. Run the standard scripts "offset_ataos" and "latiss_wep_align" to realign the mirror and focus the system.
   * - AT Mount
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


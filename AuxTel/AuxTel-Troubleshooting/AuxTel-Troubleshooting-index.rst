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
     - Rejected : Rotator out of range and ATPtg went FAULT
     - Observing at night
     - recover ATPtg and queue top correct_pointing.py
   * - 
     - AT out of focus after a 'WEP' failure -> Clear ATAOS offsets + 'WEP'
     - Observing at night
     - Pause ATScriptQueue. Clear all ATAOS offsets for the x, y, and z axes. Run the standard scripts "offset_ataos" and "latiss_wep_align" to realign the mirror and focus the system.


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


.. _AuxTel-AuxTel-Troubleshooting:

###################
AuxTel Known Faults
###################

A comprehensive list of common faults will be displayed here along their troubleshooting procedures. 

.. list-table:: Known Faults
   :widths: 05 40 35 20 
   :header-rows: 1 

   * - CSC
     - Issue
     - Common in / Error traceback
     - Troubleshooting procedure
   * - ATCS
     - ATHexapod fails to enable - No connection to athexapod controller
     - `Daytime checkout`
  
       raise OSError(err, f'Connect call failed {address}')OSError: [Errno 113] Connect call failed ('139.229.170.48', 50000)
     - :ref:`ATHexapod fails to enable with the rest of ATCS <ATHexapod-fails-to-enable-with-the-rest-of-ATCS>`
   * - -
     - ATMCS fails to enable - e-stop is engaged
     - `Daytime checkout`

       Fault event in ATMCS while in enable state (port=. Nasmyth 1 drive fault bit is ON)
     - :ref:`AuxTel Mount Control System Fails to Enable / E-Stop is Engaged <ATCS-Troubleshooting-AuxTel-Mount-Control-System-Fails-to-Enable>`
   * - ATSpectrograph
     - ATSpectrograph failed after power down
     - `Daytime checkout`
     
       raise base.AckTimeoutError( lsst.ts.salobj.base.AckTimeoutError: msg='Timed out waiting for command acknowledgement',
       ackcmd=(ackcmd private_seqNum=1137560160, ack=<SalRetCode.CMD_NOACK: -301>, error=0, result='No command acknowledgement seen')
     - :ref:`ATSpectrograph failed - grating stage position and timed out <LATISS-Troubleshooting-ATspectrograph-failed>`
   * - ATWhiteLight
     - ATWhiteLight failed to turn on
     - `Calibrations`
     - TO DO
   * - ATCS - M1 Cover
     - AuxTel M1 Cover Fails to Open.
     - `Daytime checkout` `cCalibrations` `Prepare for on-sky`
  
       result='ERROR: Command OPENM1COVER rejected while M1 covers controller in StandbyState state.'
     - :ref:`AuxTel M1 Cover Fails to Open <AuxTel-Troubleshooting-AuxTel-M1-Cover-Fails-To-Open>`. Explanation `video <https://confluence.lsstcorp.org/download/attachments/210241325/M1%20cover%20reset%20using%20EUI.mp4?version=3&modificationDate=1700889964000&api=v2>`__
   * - Scheduler Driven Observations
     - Rotator out of range error and ATPtg might go into `FAULT` state. 
     - `on-sky`
  
       error=6611,  result='Rejected : Rotator out of range. Target in rotator limit (-170 to 170 degrees) but out of slew limit margin (1 degs)')
     - In review
   * - 
     - Lost pointing: Targets do not appear centered in the detector in the first acquisition
     - `on-sky`
  
       RuntimeError("Centroid finding algorithm was unsuccessful.")
     - :ref:`AuxTel Lost Pointing Accuracy <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-Lost-Pointing-Accuracy-Procedure>`
   * - 
     - AT out of focus after a 'WEP' failure
     - `on-sky`
  
     - :ref:`AuxTel Image out of focus <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-Image-out-of-focus-Procedure>`
   * - 
     - Correct Pointing fails
     - `on-sky`

       Rejected: elevation out-of-range.
     - :ref:`AuxTel Elevation Out of range <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-AuxTel-Elevation-out-of-range>`
   * - AT Mount
     - ATMount fails to move and times out
     - `on-sky`
  
       RuntimeError: Telescope timed out getting in position.
     - :ref:`AuxTel Mount Fails to Move and Times Out <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move-and-Times-Out>`
   * - -
     - ATMount fails to move and Azimuth Max Velocity error exceeded
     - `on-sky`
  
       Fault event in ATMCS while in tracking enable state.  Azimuth drive #2 fault bit is ON.  Azimuth drive #1 fault bit is ON.  Azimuth max velocity error  exceeded.
     - :ref:`AuxTel Mount Fails to Move <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move>`
   * - AT Dome
     - ATDome shutter fails to close
     - `Shutdown`
     - :ref:`AuxTel Emergency Shutdown <AuxTel-Non-Standard-Operations-AuxTel-Emergency-Shutdown>`
   * - AT Instrumentation
     - ATCamera Recovering from Fault State
     - `Daytime checkout` `Calibrations` `on-sky` 
     - :ref:`AT camera recovery <LATISS-Troubleshooting-ATcamera-recovery>`



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

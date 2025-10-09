.. _AuxTel-AuxTel-Troubleshooting:

###################
AuxTel Known Faults
###################

A comprehensive list of common faults will be displayed here along their troubleshooting procedures. 

.. list-table:: Known Faults
   :widths: 10 35 35 20 
   :header-rows: 1 

   * - OCS
     - Issue
     - Common in / Error traceback
     - Troubleshooting procedure
   * - ATCS/ATHexapod
     - ATHexapod fails to enable - No connection to athexapod controller
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`
  
        raise OSError(err, f'Connect call failed {address}')OSError: [Errno 113] Connect call failed ('139.229.170.48', 50000)
     - :ref:`ATHexapod fails to enable with the rest of ATCS <ATHexapod-fails-to-enable-with-the-rest-of-ATCS>`
   * - 
     - ATHexapod cannot issue AOS corrections - position out of limits
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`, :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`

        raise
        base.AckError(msg="Command failed", ackcmd=ackcmd) lsst.ts.salobj.base.AckError: msg='Command
        failed', ackcmd=(ackcmd private_seqNum=493863606, ack=<SalRetCode.CMD_FAILED: -302>, error=1,
        result="Failed: disableCorrection not allowed in Fault state: errorCode=8103,
        errorReport='Correction loop died.'")
     - :ref:`ATHexapod Position Out of Limits <ATHexapod-Fails-Out-of-Limits>`
   * - 
     - ATMCS fails to enable - e-stop is engaged
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`

        Fault event in ATMCS while in enable state (port=. Nasmyth 1 drive fault bit is ON)
     - :ref:`AuxTel Mount Control System Fails to Enable / E-Stop is Engaged <ATCS-Troubleshooting-AuxTel-Mount-Control-System-Fails-to-Enable>`
   * - LATISS/ATSpectrograph
     - ATSpectrograph failed after power down
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`
     
        raise base.AckTimeoutError( lsst.ts.salobj.base.AckTimeoutError: msg='Timed out waiting for command acknowledgement',
        ackcmd=(ackcmd private_seqNum=1137560160, ack=<SalRetCode.CMD_NOACK: -301>, error=0, result='No command acknowledgement seen')
     - :ref:`ATSpectrograph Recovery <LATISS-Troubleshooting-ATspectrograph-Recovery>`
   * - LATISS/ATCamera
     - ATCamera Recovering from Fault State
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`, :ref:`Calibrations <Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure>` , :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>` 
     - :ref:`AT camera recovery <LATISS-Troubleshooting-ATcamera-recovery>`
   * - ATCalSys/ATWhiteLight
     - ATWhiteLight failed to turn on
     - :ref:`Calibrations <Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure>` 
  
        RuntimeError: White Light Lamp failed to turn on after 900 s.
     - TO DO
   * - ATCS - M1 Cover
     - AuxTel M1 Cover Fails to Open.
     - :ref:`Daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>`, :ref:`Calibrations <Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-FLAT-all-filters-empty-Procedure>`, :ref:`Prepare for on-sky <AuxTel-Nighttime-Operations-Open-for-On-Sky-Operations>`
  
        result='ERROR: Command OPENM1COVER rejected while M1 covers controller in StandbyState state.'
     - :ref:`AuxTel M1 Cover Fails to Open <AuxTel-Troubleshooting-AuxTel-M1-Cover-Fails-To-Open>`.
   * - Scheduler Driven Observations
     - Rotator out of range error and ATPtg might go into `FAULT` state. 
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`
  
        error=6611,  result='Rejected : Rotator out of range. Target in rotator limit (-170 to 170 degrees) but out of slew limit margin (1 degs)')
     - :ref:`AuxTel Rotator Out Of Range <AuxTel-Rotator-Out-Of-Range>`  
   * - 
     - Lost pointing: Targets do not appear centered in the detector in the first acquisition
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`
  
        RuntimeError("Centroid finding algorithm was unsuccessful.")
     - :ref:`AuxTel Lost Pointing Accuracy <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-Lost-Pointing-Accuracy-Procedure>`
   * - 
     - AT out of focus after a 'WEP' failure
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`
  
     - :ref:`AuxTel Image out of focus <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-Image-out-of-focus-Procedure>`
   * - 
     - Correct Pointing fails
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`

        Rejected: elevation out-of-range.
     - :ref:`AuxTel Elevation Out of range <AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-AuxTel-Elevation-out-of-range>`
   * - ATCS/ATMCS
     - ATMount fails to move and times out
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`
  
        RuntimeError: Telescope timed out getting in position.
     - :ref:`AuxTel Mount Fails to Move and Times Out <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move-and-Times-Out>`
   * - 
     - ATMount fails to move and Azimuth Max Velocity error exceeded
     - :ref:`Nightime Operations <AuxTel-Nighttime-Operations-index>`
  
        Fault event in ATMCS while in tracking enable state.  Azimuth drive #2 fault bit is ON.  Azimuth drive #1 fault bit is ON.  Azimuth max velocity error  exceeded.
     - :ref:`AuxTel Mount Fails to Move <ATCS-Troubleshooting-AuxTel-Mount-Fails-to-Move>`
   * - ATCS/ATDome
     - ATDome shutter fails to close
     - :ref:`Shutdown <AuxTel-Nighttime-Operations-Shutdown>`
     - :ref:`AuxTel Emergency Shutdown <AuxTel-Non-Standard-Operations-AuxTel-Emergency-Shutdown>`




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

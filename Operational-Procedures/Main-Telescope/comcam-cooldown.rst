.. This is a template for procedures

.. This is the label that can be used as for cross referencing in the given area
.. _ComCam-cooldown:

.. Primary Author
.. add your name between the *'s below
.. |author| replace::  *Brian Stalder*
.. If making contribution, add your name between *'s below (first person will have to add the **'s.
.. Names should be separated by commas.
.. |contributors| replace:: *temporary replace statement*


##############################
ComCam Cooldown (CCS-specific)
##############################

.. note::
    This is a procedure document that is in a state of continuing development while ComCam is being integrated with the other observatory subsystems and not expected to be needed once in steady-state observations.  It is expected that these procedures will only be needed as reference by expert engineers and scientists.

Overview
^^^^^^^^

This procedure describes the starting up and cooling down of the ComCam cryostat.


Prerequisites
^^^^^^^^^^^^^

- Quadbox is connected to 3-phase power, all breakers are open and the PLC protection is active.
- All ComCam servers are booted and running the applicable CCS subsystems.


Post-Condition
^^^^^^^^^^^^^^

- This procedure leaves ComCam in a state where it is ready to take exposures via CCS or OCS.


Procedure Steps
^^^^^^^^^^^^^^^


Power Up Quadbox
-------------------------

(As Executed In Base datacenter)

#. 3-phase breaker closed in junction box
#. Quadbox breakers closed in quadbox (starting from 3-phase side)
#. PLC control reset (on white box)
#. start up ccs subsystems on lions

   a) comcam-quadbox on lion01
   b) comcam-rebpower on lion02

#. start ccs-console on any CCS machine

   a) open quadbox, vacuum, rebpower, fp GUI windows

#. start power for PDUs and corresponding masters (quadbox GUI)
#. Power up 120VAC transformers for external utilities

   a) Access via ssh to dimm laptop @ dimm@139.229.136.127
   b) telnet to PDUs, info as follows:

::

   PDU1 at 192.168.2.2 (apc:apc)
   1: unassigned1
   2: unassigned2
   3: Laptop
   4: unassigned4
   5: unassigned5
   6: KOOLANCE
   7: Fan1 (to PDUs)
   8: Fan2 (to REB PS)

   PDU15 at 192.168.1.2 (apc:apc)
   1: VQM
   2: LEDLamp
   3: QTHLamp
   4: FilterWheel
   5: Shutter
   6: unassigned6
   7: unassigned7
   8: VIBRATIONALARM


Power on KOOLANCE, Fan1, Fan2, VIBRATIONALARM


Pump Down
-------------------------

#. Turn on Roughing Pump (quadbox GUI, BFR switch)

#. Open VAT Valve after roughing pump (and turbo if already pumped down) has been on for ~10 minutes.  (Click the VAT Valve Open button on the vacuum GUI)

#. Turn on Turbo Pump if not already on (after pressure reaches ~1.0E-2 torr).  Click Cryo Turbo Pump on quadbox GUI to power on, then Click the Cryo Turbo Pump On button on vacuum GUI.


Cool Down
-------------------------

#. Make sure liquid cooling is running.

#. Power on cryotels (cryotel ctrl 0,1,2 on quadbox GUI).

#. Turn on Cryotel(s) (If AVC on pause between each and evaluate), from vacuum GUI.


Power on REBs
-------------------------

#. Turn on REB boards once COLD channels are below 0C.
   - Click REB PS on quadbox 48V Dirty GUI
   - Click the REB Main Power GUI buttons

.. note::
   Rebs may powerdown if the resistances go out of spec, then may need to manually power off/on from ccs-shell e.g. comcam-rebpower/R22/Reb0 powerRebOff, comcam-rebpower/R22/Reb0 powerRebOn


Power on CCDs
-------------------------

#. Start ccs-shell on any CCS machine
   
   a) > set target comcam-fp
   b) > set level 99

#. Add heater power, adjust until CCD cooldown rate is below 25C/hour.
   
   a) > comcam-fp/R22/Reb0 setHeaterPower 0 0.5
   b) > comcam-fp/R22/Reb2 setHeaterPower 0 0.5

#. Once CCDs are cooling (<0C), and REBs are cold (<-30C), check if CCDs are powered.
   
   a) > comcam-fp/R22/Reb0 getCCDsPowerState
   b) > comcam-fp/R22/Reb1 getCCDsPowerState
   c) > comcam-fp/R22/Reb2 getCCDsPowerState

#. Check for shorts.
   
   a) > comcam-fp/R22/Reb0 testCCDShorts
   b) > comcam-fp/R22/Reb1 testCCDShorts
   c) > comcam-fp/R22/Reb2 testCCDShorts

#. Turn on power to CCD (need to be at most -XC, for Reb0,Reb1, -90 for Reb2).
   
   a) > comcam-fp/R22/Reb0 powerCCDsOn
   b) > comcam-fp/R22/Reb1 powerCCDsOn
   c) > comcam-fp/R22/Reb2 powerCCDsOn

.. note::
   REBs may fail hardware checking and default CCD Type to None, which won't allow the CCDs to turn on.  Once at low enough temperature, they will pass checks.  Restart the fp subsystem will allow them to pass, and turn on.

Turn on CCD HV Biases
-------------------------

#. Check if Back Bias is already on
   
   a) > comcam-fp/R22/Reb0 isBackBiasOn
   b) > comcam-fp/R22/Reb1 isBackBiasOn
   c) > comcam-fp/R22/Reb2 isBackBiasOn

#. Enable Back Bias from Command Line
   
   a) > comcam-fp/R22/Reb0 setBackBias True
   b) > comcam-fp/R22/Reb1 setBackBias True
   c) > comcam-fp/R22/Reb2 setBackBias True

#. Set Back Bias DAC values on the power supply.
   
   a) > comcam-rebpower/R22/Reb0 change hvBias 500
   b) You can monitor the HV bias voltage and current on the Rebpower GUI.  Adjust DAC value until at ~50V.

#. Apply back bias to the CCDs.
   
   a) comcam-rebpower/R22/Reb0 hvBiasOn

.. note::
   Watch HV current, may momentarily spike to >200uA and come down to ~120uA in less than 10 seconds.  If it doesn’t come down to below 130uA, open switch, take some biases, then close switch again.


Similarly with Reb1, Reb2


Ion Pump
-------------------------

Can turn on ion pump once pressure is below 1E-6.  Usually takes a few tried (will "burp" and kick off as pressure releases).

#. Power on from 24V dirty PDU (quadbox GUI)

#. Activate pump (vacuum GUI)

Watch vacuum pressure, and ion pump current.



Troublshooting
^^^^^^^^^^^^^^^


Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

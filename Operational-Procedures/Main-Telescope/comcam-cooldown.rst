.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Brian Stalder*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Kevin Reil*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Main-Telescope-ComCam-Cooldown:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##############################
ComCam Cooldown (CCS-specific)
##############################

.. note::
    This is a procedure document that is in a state of continuing development while ComCam is being integrated with the other observatory subsystems and not expected to be needed once in steady-state observations. It is expected that these procedures will only be needed as reference by expert engineers and scientists.

.. _ComCam-Cooldown-Overview:

Overview
^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This procedure describes the starting up and cooling down of the ComCam cryostat.

.. _ComCam-Cooldown-Prerequisites:

Prerequisites
^^^^^^^^^^^^^

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

- Quadbox is connected to 3-phase power, all breakers are open and the PLC protection is active.
- All ComCam servers are booted and running the applicable CCS subsystems.

.. _ComCam-Cooldown-Post-Condition:

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- This procedure leaves ComCam in a state where it is ready to take exposures via CCS or OCS.

.. _ComCam-Cooldown-Procedure-Steps:

Procedure Steps
^^^^^^^^^^^^^^^

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

.. _ComCam-Cooldown-Power-Up-Quadbox:

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

.. _ComCam-Cooldown-Pump-Down:

Pump Down
-------------------------

#. Turn on Roughing Pump (quadbox GUI, BFR switch)

#. Open VAT Valve after roughing pump (and turbo if already pumped down) has been on for ~10 minutes.  (Click the VAT Valve Open button on the vacuum GUI)

#. Turn on Turbo Pump if not already on (after pressure reaches ~1.0E-2 torr).  Click Cryo Turbo Pump on quadbox GUI to power on, then Click the Cryo Turbo Pump On button on vacuum GUI.
   a) comcam-vacuum/turbo startTurboPump

.. _ComCam-Cooldown-Cool-Down:

Cool Down
-------------------------

#. Make sure liquid cooling is running.

#. Power on cryotels (cryotel ctrl 0,1,2 on quadbox GUI).

#. Turn on Cryotel(s) (If AVC on pause between each and evaluate), from vacuum GUI.

.. _ComCam-Cooldown-Power-On-REBs:

Power on REBs
-------------------------

#. Turn on REB boards once COLD channels are below 0C.
   - Click REB PS on quadbox 48V Dirty GUI
   - Click the REB Main Power GUI buttons

.. note::
   Rebs may powerdown if the resistances go out of spec, then may need to manually power off/on from ccs-shell e.g. comcam-rebpower/R22/Reb0 powerRebOff, comcam-rebpower/R22/Reb0 powerRebOn

.. _ComCam-Cooldown-Power-On-CCDs:

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

.. _ComCam-Cooldown-Turn-On-CCD-HV-Biases:

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

.. _ComCam-Cooldown-Ion-Pump:

Ion Pump
-------------------------

Can turn on ion pump once pressure is below 1E-6.  Usually takes a few tried (will "burp" and kick off as pressure releases).

#. Power on from 24V dirty PDU (quadbox GUI)

#. Activate pump (vacuum GUI)

Watch vacuum pressure, and ion pump current.

.. _ComCam-Steady-State:

Moving to ComCam Steady State
-------------------------------------
Once you are cold and well below 1E-6 you will want to

#. Close (power off) the VAT valve from the comcam-vacuum Control Panel or comcam-quadbox control Panel or
    a) comcam-quadbox (??)

#. Spin down the turbo pump by clicking Off on comcam-vacuum control Panel or
   a) comcam-vacuum/turbo stopTurboPump

#. Once RPM reaches zero on turbo pump you should power off to the scroll pump. Turn on Roughing Pump (quadbox GUI, BFR switch). Turbo pump power should stay on as the pump produces important telemetry even while not spinning.

.. _ComCam-Cooldown-Troublshooting:

Troublshooting
^^^^^^^^^^^^^^^

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

     No troubleshooting information is applicable to this procedure.

Content for section under development (if required).

.. _ComCam-Cooldown-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^
Kevin Reil - WhatsApp/Cell/Text 650-898-7345

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

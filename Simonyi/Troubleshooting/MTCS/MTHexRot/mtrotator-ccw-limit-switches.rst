.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Ioana Sotuela
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: Yijung Kang, Kshitija Kelkar, Carlos Morales, Kris Mortensen


.. _MTRotator-CCW-Limit-Switches-Troubleshooting:

#################################################
MTRotator CCW Limit Switches and Pull Cord Alarms
#################################################

.. _MTRotator-CCW-Limit-Switches-Overview:

Overview
========

MTRotator cannot be moved because the camera cable wrap (CCW) is under a limit switch error.
This typically occurs in situations where:

* The angle of the CCW and the MTRotator is different (TMA `Fault code 1012 <https://ts-tma.lsst.io/docs/tma_tma-faults/TMA%20Faults.html#ccw>`__).
* The CCW or MTRotator has hit the engineering limit or software limit (TMA `Fault codes 1002, 1003, 1010, 1011 <https://ts-tma.lsst.io/docs/tma_tma-faults/TMA%20Faults.html#ccw>`__).

**Software limits** on the CCW are conservatively set to ensure the CCW continues following the MTRotator within a certain range of angle.
The software limit switches (either + or −) are triggered when the offset exceeds the configured threshold.

The **positive or negative limit switches** (engineering limits) physically safeguard the CCW by preventing it from crossing the maximum positional offset from the MTRotator position.

.. _MTRotator-CCW-Limit-Switches-Error-Diagnosis:

Error Diagnosis
===============

* MTRotator is available, and MTMount can be enabled but CCW is in fault with **pull cord alarms (either + or −)** in the **SAFETY SYSTEM** in the TMA EUI. MTRotator and CCW position do not coincide. See :ref:`Case I <MTRotator-CCW-Limit-Switches-Case-I>`.
* MTRotator is available, and MTMount can be enabled but CCW is in fault with **limit switches (either + or −)** in the CCW **INTERLOCKS** in the TMA EUI. MTRotator and CCW position do not coincide. See :ref:`Case II <MTRotator-CCW-Limit-Switches-Case-II>`.
* MTRotator is available, and MTMount can be enabled but CCW is in fault with **software limit switches (either + or −)** in the CCW **INTERLOCKS** in the TMA EUI. MTRotator and CCW position do not coincide. See :ref:`Case III <MTRotator-CCW-Limit-Switches-Case-III>`.
* Limit switch interlock as well as the pull cord alarm is active. See :ref:`Case IV <MTRotator-CCW-Limit-Switches-Case-IV>`.
* All four limit switches (engineering + software) + and − activated together with pull cord alarms, which is very unlikely to happen under normal circumstances. See :ref:`Case V <MTRotator-CCW-Limit-Switches-Case-V>`.

.. _MTRotator-CCW-Limit-Switches-Preconditions:

Preconditions
=============

* MTMount is in ``DISABLED`` and the TMA EUI is in ``Engineering mode``.
* MTRotator is in ``DISABLED``.

.. warning::

   Safe speed to move the CCW through the EUI is << 5 deg/s.
   ALWAYS move the CCW as close as possible to the MTRotator.
   It is always recommended to DISABLE both software and engineering limit switches.

.. note::

   *Provisional note (April 2025):* Required to ``reset`` the MTM2Cam GIS at the end of this procedure.

.. _MTRotator-CCW-Limit-Switches-Procedure-Steps:

Procedure Steps
===============

.. _MTRotator-CCW-Limit-Switches-Case-I:

Case I: When Pull Cord (+ / −) Alarms Are Active
-------------------------------------------------

These switches are related to the TMA Safety System, and they check that the difference between the CCW and the rotator is not too high.
Although it is an independent safety system designed for the safety of the TMA operating personnel, it is sometimes used to safeguard valuable TMA hardware components — like in this case.

**Logic Flowchart:** Disable MTMount → **Override** alarms in the Safety System → Bring the CCW to the position of MTRotator → Clear alarms and **Release** the override of alarms in the Safety System → Ready to Enable MTRotator.

Even though this procedure is done entirely in the EUI, the command actually goes to the PILZ safety system and **NOT** to PXIs.

.. note::

   You can **ONLY JOG** the CCW under an alarm-override state.

#. Go to **HOME** → **MONITOR & CONTROL** → **SAFETY SYSTEM**.
   Select the row **Pull Cord +** or **Pull Cord −** (whichever is shown to be active) and click the softkey ``SET OVERRIDE``.
   This should change the color of the pull cord alarm from red to purple.
   You will have exactly 3 minutes to override the alarm before it activates again.

#. Move the CCW to the MTRotator position:

   #. Go to **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** and select the ``RESET ALARM`` blue softkey.
   #. Turn ``ON`` the CCW drives; the **STATUS** should show ``Enable`` in green.
   #. Jog the CCW to the current MTRotator angle using the ``+`` / ``-`` blue softkeys.
   #. Turn ``OFF`` the drives; the **STATUS** should show ``Idle``.

#. Go back to **HOME** → **MONITOR & CONTROL** → **SAFETY SYSTEM**.
   Select the row **Pull Cord +** or **Pull Cord −** and click the softkey ``RELEASE OVERRIDE``.
   This should turn the alarm back to red.

#. Click the softkey ``RESET SELECTED``.
   This should clear the pull cord alarm completely.

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-II:

Case II: When Limit Switches (+ / −) Are Active
------------------------------------------------

The maximum range of movement for the CCW is decided by the range of motion of the MTRotator.
Sometimes a difference between these two (e.g., unresponsive CCW) can cause this limit to be triggered either in the positive or negative direction.

**Logic Flowchart:** Disable MTMount → Disable software limits → Reset CCW interlocks → Bring the CCW to the position of MTRotator → Ready to Enable MTRotator.

**Fault check:** The **Interlocks** block in **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** should show an active interlock of either ``Positive Limit Switch Pressed`` or ``Negative Limit Switch Pressed``.

#. Go to **HOME** → **SETTINGS** → **CAMERA CABLE WRAP SETTINGS**.
   Depending on which limit switch interlock is activated, select the row that says **Positive Limit Switch Enable / Negative Limit Switch Enable** in the first column.
   Change the **Value** (third column) to ``FALSE`` and click the blue softkey ``WRITE``.
   This should show the change in yellow.

#. Select the row that says **Positive Software Limit Enable / Negative Software Limit Enable** in the first column.
   Change the **Value** (third column) to ``FALSE`` and click the blue softkey ``WRITE``.
   This should show the change in yellow.

#. Move the CCW to the MTRotator position:

   #. Go to **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** and select the ``RESET ALARM`` blue softkey.
   #. Turn ``ON`` the CCW drives; the **STATUS** should show ``Enable`` in green.
   #. Jog the CCW to the current MTRotator angle using the ``+`` / ``-`` blue softkeys OR by entering the angle in the field **Position deg** and appropriate small speed (<< 5 deg/s) in the field **Speed deg/s**.
   #. Turn ``OFF`` the drives; the **STATUS** should show ``Idle``.

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-III:

Case III: When Software Limit Switches (+ / −) Are Active
----------------------------------------------------------

**Logic Flowchart:** Disable MTMount → Disable software limits → Reset CCW interlocks → Bring the CCW to the position of MTRotator → Ready to Enable MTRotator.

**Fault check:** The **Interlocks** block in **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** should show an active interlock of either ``Positive Software Limit Switch Pressed`` or ``Negative Software Limit Switch Pressed``.

#. Go to **HOME** → **SETTINGS** → **CAMERA CABLE WRAP SETTINGS**.
   Depending on which limit switch interlock is activated, select the row that says **Positive Limit Switch Enable / Negative Limit Switch Enable** in the first column.
   Change the **Value** (third column) to ``FALSE`` and click the blue softkey ``WRITE``.
   This should show the change in yellow.

#. Select the row that says **Positive Software Limit Enable / Negative Software Limit Enable** in the first column.
   Change the **Value** (third column) to ``FALSE`` and click the blue softkey ``WRITE``.
   This should show the change in yellow.

#. Move the CCW to the MTRotator position:

   #. Go to **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** and select the ``RESET ALARM`` blue softkey.
   #. Turn ``ON`` the CCW drives; the **STATUS** should show ``Enable`` in green.
   #. Jog the CCW to the current MTRotator angle using the ``+`` / ``-`` blue softkeys OR by entering the angle in the field **Position deg** and appropriate small speed (<< 5 deg/s) in the field **Speed deg/s**.
   #. Turn ``OFF`` the drives; the **STATUS** should show ``Idle``.

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-IV:

Case IV: When Limit Switches (+ / −) as Well as Pull Cord Alarms Are Active
----------------------------------------------------------------------------

**Fault check:** The **Interlocks** block in **HOME** → **MONITOR & CONTROL** → **CAMERA CABLE WRAP** should show an active interlock of either of the following:

#. ``Positive Software Limit Switch Pressed`` or ``Negative Software Limit Switch Pressed``.
#. ``Positive Limit Switch Pressed`` or ``Negative Limit Switch Pressed``.

AND the safety matrix in **HOME** → **MONITOR & CONTROL** → **SAFETY SYSTEM** shows an active **Pull Cord +** or **Pull Cord −** alarm.

ALWAYS resolve the pull cord alarms first and then proceed to clear the limit switch interlock if still active.

#. Follow the procedure in :ref:`Case I <MTRotator-CCW-Limit-Switches-Case-I>` to resolve the pull cord alarms.
#. If the limit switch interlocks are still active, follow the procedure in :ref:`Case II <MTRotator-CCW-Limit-Switches-Case-II>` or :ref:`Case III <MTRotator-CCW-Limit-Switches-Case-III>` as appropriate.

.. _MTRotator-CCW-Limit-Switches-Case-V:

Case V: ALL Four Limit Switches (+ / −) AND Pull Cord Alarms Are Active
------------------------------------------------------------------------

This is an indication that there is an EtherCAT line issue that requires:

#. Physically connecting the Beckhoff master to the EtherCAT line to recover it (explained in `Reset EtherCAT in TMA Cabinets <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39696081>`__).
#. Followed by a PXI reset (in this case `TMA PXI <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39683156>`__).

However, this will often be accompanied by failures/faults in other TMA components controlled by that PXI.

.. note::

   Connecting the Beckhoff master is the most reliable EtherCAT recovery method, but it is not always required.
   For alternative recovery methods, refer to the
   `EtherCAT line management documentation <https://github.com/lsst-ts/ts_tma_tma-documentation_maintenance-documents_ethercat_manage-ethercat-line-status>`__
   and the
   `EtherCAT line diagnostic documentation <https://github.com/lsst-ts/ts_tma_tma-documentation_maintenance-documents_ethercat_ethercat-line-diagnostic>`__.

.. _MTRotator-CCW-Limit-Switches-Post-Condition:

Post-Condition
==============

* On the TMA EUI: CCW drives show **STATUS** either ``Idle`` or ``Enabled`` if the MTMount is enabled.

.. _MTRotator-CCW-Limit-Switches-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in `#summit_simonyi <https://lsstc.slack.com/archives/summit_simonyi>`__ and tag Julen Garcia / Alberto Izpizua / Tekniker remote support available at the time.
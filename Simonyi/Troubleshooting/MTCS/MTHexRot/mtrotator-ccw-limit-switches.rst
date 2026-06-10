.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Ioana Sotuela
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: Yijung Kang, Kshitija Kelkar, Carlos Morales, Kris Mortensen

.. Colors for added clarity in recovery procedures
.. raw:: html

    <style> .red {color:red; font-weight: bold} </style>
.. role:: red

.. raw:: html

    <style> .purple {color:purple; font-weight: bold} </style>
.. role:: purple


.. _MTRotator-CCW-Limit-Switches:

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

.. admonition:: Software Limits
   :class: info

   **Software limits** on the CCW are conservatively set to ensure the CCW continues following 
   the MTRotator within a certain range of angle. The software limit switches (either + or −) 
   are triggered when:  
   :math:`\boxed{\left|\theta_{CCW} - \theta_{Rot}\right| \geq 2.5\, \text{deg}}`


.. admonition:: Positive/Negative Limit Switches
   :class: info

   The **positive or negative limit switches** (engineering limits) physically safeguard the CCW 
   by preventing it from crossing the maximum positional offset from the MTRotator position.
   These switches are triggered when:  
   :math:`\boxed{\left|\theta_{CCW} - \theta_{Rot}\right| \geq 5\, \text{deg}}`

   
.. _MTRotator-CCW-Limit-Switches-Error-Diagnosis:

Error Diagnosis
===============

When this issue happens during operations, MTRotator is usually available and MTMount can still be enabled. 
However, the an error occurs directly with the CCW, reporting itself in fault due to the MTRotator and CCW positions not coinciding.
Common alarms for when the MTRotator and CCW are misaligned are:

1.  The :ref:`D-8 CCW Interlock <mtrot_recovery_2>` is triggered on the Global Interlock System (GIS) 
    display, located on level 2.

2.  The :ref:`TMA IS <mtrot_recovery_5>` is triggered on the GIS, and the
    :ref:`Watchdog <mtrot_recovery_4>` (WD) box in the Safety System of TMA EUI is red,

.. list-table:: 
   :header-rows: 0
   :widths: 50 50

   * - 
       .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_4.png
         :name: mtrot_recovery_4

         Active Watchdog (WD) alarm in the Safety System.

     - 
       .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_5.png
         :name: mtrot_recovery_5

         Active TMA IS alarm in the GIS.


There are five possible cases in which the CCW faults:

*  :ref:`Case I <MTRotator-CCW-Limit-Switches-Case-I>`: The *pull cord alarms* (+ and/or −) are active in the *SAFETY SYSTEM* of the TMA EUI.
*  :ref:`Case II <MTRotator-CCW-Limit-Switches-Case-II>`: The *limit switches* (+ and/or −) are activein the CCW *INTERLOCKS* of the TMA EUI.
*  :ref:`Case III <MTRotator-CCW-Limit-Switches-Case-III>`: The *software limit switches* (+ and/or −) are active in the *CCW INTERLOCKS* of the TMA EUI.
*  :ref:`Case IV <MTRotator-CCW-Limit-Switches-Case-IV>`: At least one *limit switch* **and** one *pull cord alarm* is active.
*  :ref:`Case V <MTRotator-CCW-Limit-Switches-Case-V>`: **All** *limit switches* (Cases II and III) **and** *pull cord alarms* (Case I) are active 
   (rare under normal circumstances).

.. list-table:: 
   :header-rows: 0
   :widths: 48 52

   * - 
       .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_1.png
         :name: mtrot_recovery_1

         Pull cord +/- alert highlighted by the red box in the *SAFETY SYSTEM*.

     -
       .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_10.png
        :name: mtrot_recovery_10

        Positive limit switch alert highlighted by the red box in the *CCW INTERLOCKS*.


.. _MTRotator-CCW-Limit-Switches-Preconditions:

Preconditions
=============

* MTMount is in ``DISABLED`` and the TMA EUI is in ``Engineering mode``.
* MTRotator is in ``DISABLED``.

.. note::

    There are two ways to recover this fault:

    1. **Moving the CCW to the Camera Rotator** 
       (see the :ref:`Procedure Steps <MTRotator-CCW-Limit-Switches-Procedure-Steps>` below).

    2. **Moving the Camera Rotator to the CCW** 
       (see the :ref:`MTRotator Manual Rotation Procedure <MTRotator-Manual-Rotation-Procedure>` for instructions).



.. _MTRotator-CCW-Limit-Switches-Procedure-Steps:

Procedure Steps
===============

.. warning::

   *  A safe speed to move the CCW through the EUI should be 
      :math:`\, \boxed{\ll \, 5 \, \text{deg/s}}`.
   *  ALWAYS move the CCW **as close as possible** to the MTRotator.
   *  It is always recommended to DISABLE both software and engineering limit switches.

.. _MTRotator-CCW-Limit-Switches-Case-I:

Case I: Pull Cord (+ / −) Alarms Are Active
-------------------------------------------

These switches are related to the TMA Safety System, and they check that the difference between the CCW and the rotator is not too high.
Although it is an independent safety system designed for the safety of the TMA operating personnel, it is sometimes used to safeguard valuable TMA hardware components — like in this case.

Even though this procedure is done entirely in the EUI, the command actually goes to the PILZ safety system and **NOT** to PXIs.

.. admonition:: Fault Check
   :class: info

   The safety matrix in :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`SAFETY SYSTEM` shows 
   an active ``Pull Cord +`` or ``Pull Cord −`` alarm.


#. If the *D-8 CCW* interlock is triggered, :ref:`bypass the detection <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` through the GIS panel.

#. In the TMA EUI, select :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`SAFETY SYSTEM`.

   a. Select the row ``Pull Cord +`` or ``Pull Cord −`` (whichever is shown to be active), and click the softkey :guilabel:`SET OVERRIDE`.
   
      * This should change the color of the pull cord alarm from :red:`red` to :purple:`purple`.
      * You will have exactly 3 minutes to override the alarm before it activates again.

#. Move the CCW to the MTRotator position:

   a. Go to :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` and select the :guilabel:`RESET ALARM` blue softkey.
   b. Turn :guilabel:`ON` the CCW drives; the ``status`` should show ``Enabled`` in green.
   c. Jog the CCW to the current MTRotator angle using the :guilabel:`+` / :guilabel:`-` blue softkeys.

      .. note::
         
         You can **ONLY JOG** the CCW under an alarm-override state.

   d. Turn :guilabel:`OFF` the drives; the ``status`` should show ``Idle``.

#. Go back to :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`SAFETY SYSTEM`.
   
   a. | Select the row ``Pull Cord +`` or ``Pull Cord −`` and click the softkey 
      | :guilabel:`RELEASE OVERRIDE`. This should turn the alarm from :purple:`purple` back to :red:`red`.

#. Click the softkey :guilabel:`RESET SELECTED`.
   This should clear the pull cord alarm completely.

#. Make sure to :ref:`clear the camera rotator interlocks <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepII>`, 
   and remember to :ref:`remove the bypass <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` on the *D-8 CCW* detection (if bypassed).

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-II:

Case II: Limit Switches (+ / −) Are Active
------------------------------------------------

The maximum range of movement for the CCW is decided by the range of motion of the MTRotator.
Sometimes a difference between these two (e.g., unresponsive CCW) can cause this limit to be triggered either in the 
``+ve`` or ``-ve`` direction.

.. admonition:: Fault Check
   :class: info

   The ``INTERLOCKS`` block in :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` 
   should show an active interlock of either ``Positive Limit Switch Pressed`` or ``Negative Limit Switch Pressed``.
   
   This fault will indicate where you need to edit the *Positive* or *Negative* settings in the procedure steps.

#. If the *D-8 CCW* interlock is triggered, :ref:`bypass the detection <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` through the GIS panel.

#. Go to :guilabel:`HOME` → :guilabel:`SETTINGS` → :guilabel:`CAMERA CABLE WRAP SETTINGS`.
   
   a. Depending on which limit switch interlock is activated, select the row that says ``Positive Limit Switch Enable`` / ``Negative Limit Switch Enable`` 
      in the first column.
   b. Change the ``Value`` (third column) to ``FALSE`` and click the blue softkey :guilabel:`WRITE`.
      This should show a change in yellow. 
   c. Select the row that says ``Positive Software Limit Enable`` / ``Negative Software Limit Enable`` in the first column.
   d. Change the ``Value`` (third column) to ``FALSE`` and click the blue softkey :guilabel:`WRITE`.
      This should show the change in yellow.

#. Move the CCW to the MTRotator position:

   a. Go to :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` and select the :guilabel:`RESET ALARM` blue softkey.
   b. Turn :guilabel:`ON` the CCW drives; the ``status`` should show ``Enabled`` in green.
   c. Jog the CCW to the current MTRotator angle using the :guilabel:`+` / :guilabel:`-` blue softkeys.
      
      * **OR** enter the *angle* in the ``position deg`` field with an *angular speed* 
        :math:`\, \left(\ll \, 5 \, \text{deg/s}\right)` in the ``speed deg/s`` field and select :guilabel:`MOVE`.
   
   d. Turn :guilabel:`OFF` the drives; the ``status`` should show ``Idle``.

#. Make sure to :ref:`clear the camera rotator interlocks <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepII>`, 
   and remember to :ref:`remove the bypass <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` on the *D-8 CCW* detection (if bypassed).

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-III:

Case III: Software Limit Switches (+ / −) Are Active
----------------------------------------------------------
The maximum range of movement for the CCW is decided by the range of motion of the MTRotator.
Sometimes a difference between these two (e.g., unresponsive CCW) can cause this limit to be triggered either in the 
``+ve`` or ``-ve`` direction.

.. admonition:: Fault Check
   :class: info

   The ``INTERLOCKS`` block in :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` 
   should show an active interlock of either ``Positive Software Limit Switch Pressed`` or ``Negative Software Limit Switch Pressed``.
   
   This fault will indicate where you need to edit the *Positive* or *Negative* settings in the procedure steps.

#. If the *D-8 CCW* interlock is triggered, :ref:`bypass the detection <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` through the GIS panel.

#. Go to :guilabel:`HOME` → :guilabel:`SETTINGS` → :guilabel:`CAMERA CABLE WRAP SETTINGS`.
   
   a. Depending on which limit switch interlock is activated, select the row that says ``Positive Limit Switch Enable`` / ``Negative Limit Switch Enable`` 
      in the first column.
   b. Change the ``Value`` (third column) to ``FALSE`` and click the blue softkey :guilabel:`WRITE`.
      This should show a change in yellow. 
   c. Select the row that says ``Positive Software Limit Enable`` / ``Negative Software Limit Enable`` in the first column.
   d. Change the ``Value`` (third column) to ``FALSE`` and click the blue softkey :guilabel:`WRITE`.
      This should show the change in yellow.

#. Move the CCW to the MTRotator position:

   a. Go to :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` and select the :guilabel:`RESET ALARM` blue softkey.
   b. Turn :guilabel:`ON` the CCW drives; the ``status`` should show ``Enabled`` in green.
   c. Jog the CCW to the current MTRotator angle using the :guilabel:`+` / :guilabel:`-` blue softkeys.
      
      * **OR** enter the *angle* in the ``position deg`` field with an *angular speed* 
        :math:`\, \left(\ll \, 5 \, \text{deg/s}\right)` in the ``speed deg/s`` field and select :guilabel:`MOVE`.
   
   d. Turn :guilabel:`OFF` the drives; the ``status`` should show ``Idle``.

#. Make sure to :ref:`clear the camera rotator interlocks <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepII>`, 
   and remember to :ref:`remove the bypass <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` on the *D-8 CCW* detection (if bypassed).

#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-IV:

Case IV: (Software) Limit Switch and Pull Cord Alarm is Active
--------------------------------------------------------------

.. admonition:: Fault Check
   :class: info

   This type of fault requires two conditions:

   1. The ``INTERLOCKS`` block in :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`CAMERA CABLE WRAP` 
      should show an active interlock of at least one of the following:
   
      a. A ``Positive Limit Switch Pressed`` or ``Negative Limit Switch Pressed`` interlock.
      b. A ``Positive Software Limit Switch Pressed`` or ``Negative Software Limit Switch Pressed`` interlock.
   
   2. The safety matrix in :guilabel:`HOME` → :guilabel:`MONITOR & CONTROL` → :guilabel:`SAFETY SYSTEM` shows an active ``Pull Cord +`` or ``Pull Cord −`` alarm.


**ALWAYS** *resolve the pull cord alarms* first and then proceed to *clear the limit switch interlocks*, if still active.

#. If the *D-8 CCW* interlock is triggered, :ref:`bypass the detection <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` through the GIS panel.
#. Follow steps 1-4 of the :ref:`Case I <MTRotator-CCW-Limit-Switches-Case-I>` procedure to resolve the pull cord alarms.
#. If the limit switch interlocks are still active, follow steps 1-2 in the :ref:`Case II <MTRotator-CCW-Limit-Switches-Case-II>` or :ref:`Case III <MTRotator-CCW-Limit-Switches-Case-III>` 
   procedure, as appropriate.
#. Make sure to :ref:`clear the camera rotator interlocks <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepII>`, 
   and remember to :ref:`remove the bypass <MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI>` on the *D-8 CCW* detection (if bypassed).
#. ``ENABLE`` MTRotator from the CSC, followed by MTMount.

.. _MTRotator-CCW-Limit-Switches-Case-V:

Case V: ALL Limit Switches AND Pull Cord Alarms Are Active
----------------------------------------------------------

If all pull alarms **and** limit switches are active, this is an indication that there is an *EtherCAT line issue*.
Recover the EtherCAT line will require:

#. Physically connecting the Beckhoff master to the EtherCAT line to recover it (explained in `Reset EtherCAT in TMA Cabinets <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39696081>`__).
#. Resetting the `TMA PXI <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39683156>`_.

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

If the procedure was not successful, report the issue in `#summit_simonyi <https://rubin-obs.slack.com/archives/C07Q45P0PAB>`__ and tag Julen Garcia / Alberto Izpizua / Tekniker remote support available at the time.

.. _MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset:

CCW/Rotator Global Interlock System (GIS) Operations
----------------------------------------------------

.. _MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepI:

Engage/Remove Bypass of the D-8 CCW GIS Interlock
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Select the :guilabel:`Det-Act` tab (bottom left of the screen), and press :guilabel:`Bypass` by the 
   ``D-8 Camera Cable Wrap Safety Device Actuated`` detection. 

   .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_2.png
      :name: mtrot_recovery_2
      :width: 500px 

      Detection D-8: Camera Cable Wrap Safety Device Actuated 

#. Once all other systems have recovered, select :guilabel:`Bypass` again to remove the D-8 bypass before normal operations.

.. _MTRotator-CCW-Limit-Switches-Contingency-GIS-Reset-StepII:

Reset Camera Rotator GIS Interlocks
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Select the :guilabel:`M2Cam` tab and then click :guilabel:`Overview` (default). 
#. Below the ``CAM. ROTATOR`` section, press and hold the :guilabel:`Reset` button. 
#. A **green "X"** mark should appear next the the ``Reset`` label. 
#. If it does not show, press and hold the :guilabel:`Reset` button, again.

   .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_3.png
      :name: mtrot_recovery_3
      :width: 500px

      M2Cam GIS Display
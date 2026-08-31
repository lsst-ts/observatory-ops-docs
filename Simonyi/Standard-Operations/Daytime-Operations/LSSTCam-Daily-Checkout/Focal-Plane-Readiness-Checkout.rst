.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. _Daytime-Operations-LSSTCam-Focal-Plane-Readiness-Checkout:

##############################
Focal Plane Readiness Checkout
##############################

.. _LSSTCam-Focal-Plane-Readiness-Overview:

Overview
========

This procedure confirms that the CCDs are powered and ready.
Complete it **before** you take the camera under Observatory Control System control.

You only read state in this procedure.
If a raft, a REB, or an HV circuit is not in the expected state,
record the identifier and contact the Camera Team.

.. warning::

    Do not power on a raft or a REB on your own,
    and do not change voltages from the :command:`ccs-console` GUI.

.. _LSSTCam-Focal-Plane-Readiness-Precondition:

Precondition
============

-  The :ref:`cooling and vacuum checkout <Daytime-Operations-LSSTCam-Cooling-and-Vacuum-Checkout>`
   is complete, and the cooling chain is stable.
-  You have access to the Big Plot or Chronograf.
-  You have a :command:`ccs-shell` session, and access to :command:`ccs-console`.

.. _LSSTCam-Focal-Plane-Readiness-Post-Condition:

Post-Condition
==============

-  REB total power is above 1000 W.
-  Every REB reports CCD power on, HV bias on, and a valid, online device state.
-  HV control is active.
-  Any raft or REB that is not ready is recorded and reported to the Camera Team.

.. _LSSTCam-Focal-Plane-Readiness-Procedure-Steps:

Procedure Steps
===============

.. _LSSTCam-Focal-Plane-Readiness-REB-Power:

REB Total Power
---------------

In the Big Plot or in Chronograf, check ``REB TOTAL POWER`` and ``Camera Reb Power``.

A fully operational system draws more than **1000 W**.
If the value is lower, report it before you continue.

.. _LSSTCam-Focal-Plane-Readiness-State:

Focal Plane State
-----------------

In :command:`ccs-shell`, read the focal plane state.

.. prompt:: text ccs>

    focal-plane getState

Every REB is expected to report the following.

.. code-block:: text

    CCDsPowerState:ON
    HVBiasState:ON
    RebDeviceState:ONLINE
    RebValidationState:VALID

The following values are also normally expected.

.. code-block:: text

    OperationalState:NORMAL
    PhaseState:OPERATIONAL

If a raft or a REB reports CCD power or HV off:

#. Record the ``Raft/Reb`` identifier.

#. Do not attempt to power it on yourself.

#. Contact the Camera Team.

.. _LSSTCam-Focal-Plane-Readiness-HV-Control:

HV Control
----------

#. Confirm that HV control is active.

   .. prompt:: text ccs>

       rebpower isHvControlActive

   The expected result is ``true``.
   If it returns ``false``, contact the Camera Team.

#. In :command:`ccs-console`, open
   :guilabel:`CCS Subsystems` → :guilabel:`rebpower` → :guilabel:`reb power control`,
   and verify the HV circuits.

   .. list-table:: Expected HV Values
      :widths: 40 60
      :header-rows: 1

      * - Quantity
        - Expected value
      * - All HV circuits
        - Above 0 V
      * - Median
        - About 50 V
      * - Minimum
        - About 30 V

   Some corner sensors and other channels can differ.

.. important::

    Read these values only.
    Do not modify voltages from the GUI.

.. _LSSTCam-Focal-Plane-Readiness-Troubleshooting:

Troubleshooting
===============

-  If REB total power is below 1000 W, or any REB reports CCD power or HV bias off,
   report it in *#cam-operator* before you continue the checkout.

-  If ``rebpower isHvControlActive`` returns ``false``, contact the Camera Team.
   Do not continue to OCS control until they confirm the state.

-  If multiple REBs lose power or HV, escalate as described in the
   :ref:`escalation criteria <LSSTCam-Monitoring-Escalation-Criteria>`.

This procedure was last modified on |today|.

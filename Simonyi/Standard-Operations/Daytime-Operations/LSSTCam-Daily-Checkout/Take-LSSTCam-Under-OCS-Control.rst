.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. _Daytime-Operations-LSSTCam-Take-Under-OCS-Control:

##############################
Take LSSTCam Under OCS Control
##############################

.. _Take-LSSTCam-Under-OCS-Control-Overview:

Overview
========

This procedure hands LSSTCam from the Camera Control System to the Observatory Control System
through the Master Control Module and the OCS bridge,
and leaves ``MTCamera`` in the ``ENABLED`` state.

Start with the :ref:`short procedure <Take-LSSTCam-Under-OCS-Control-Procedure-Steps>`.
If it does not work, follow
:ref:`when the short procedure fails <Take-LSSTCam-Under-OCS-Control-Short-Procedure-Fails>`.

.. warning::

    Clear only alerts that you recognize and that are already resolved.
    Use ``clearAllAlerts`` only when every raised alert is known
    and you have confirmed that the underlying conditions are corrected.
    If you have any doubt, clear alerts individually and contact the Camera Team.

.. _Take-LSSTCam-Under-OCS-Control-Precondition:

Precondition
============

-  The :ref:`cooling and vacuum checkout <Daytime-Operations-LSSTCam-Cooling-and-Vacuum-Checkout>`
   is complete.
-  The :ref:`focal plane readiness checkout <Daytime-Operations-LSSTCam-Focal-Plane-Readiness-Checkout>`
   is complete.
-  The :ref:`daily restart of the OCS bridge and Kafka <Daytime-Operations-LSSTCam-Restart-OCS-Bridge-and-Kafka>`
   is complete.
-  You have a :command:`ccs-shell` session.

.. _Take-LSSTCam-Under-OCS-Control-Post-Condition:

Post-Condition
==============

-  MCM reports ``OperationalState:NORMAL``.
-  :command:`ocs-bridge` reports ``OfflineState:OFFLINE_AVAILABLE``.
-  ``MTCamera`` is ``ENABLED``.

.. _Take-LSSTCam-Under-OCS-Control-Procedure-Steps:

Procedure Steps
===============

#. Open a :command:`ccs-shell`.

   .. prompt:: bash

       ssh -Y <IPA_USERNAME>@lsstcam-vw01.cp.lsst.org
       ccs-shell

#. At the ``ccs>`` prompt, start MCM in normal mode.

   .. prompt:: text ccs>

       mcm start Normal -w

#. Review the raised alerts.

   .. prompt:: text ccs>

       mcm getRaisedAlertSummary

#. Clear the alerts only when all of them are known and already resolved.

   .. prompt:: text ccs>

       mcm clearAllAlerts -w

#. Make the bridge available, and confirm its state.

   .. prompt:: text ccs>

       ocs-bridge setAvailable -w
       ocs-bridge getState

   The expected state is the following.

   .. code-block:: text

       AlertState:NOMINAL
       OfflineState:OFFLINE_AVAILABLE
       OperationalState:NORMAL
       SummaryState:OFFLINE

#. From the OCS ScriptQueue, or from the summary state controls,
   transition the camera to ``ENABLED``.

   .. code-block:: text
       :caption: :file:`set_summary_state.py`

       data:
           - [MTCamera, ENABLED]

The camera ends in ``ENABLED``.

.. _Take-LSSTCam-Under-OCS-Control-Short-Procedure-Fails:

When the Short Procedure Fails
==============================

.. _Take-LSSTCam-Under-OCS-Control-Locks:

Review Locks
------------

#. List the locked subsystems and their owners.

   .. prompt:: text ccs>

       showAllLocks

   The critical subsystems are ``focal-plane``, ``fcs``, and ``shutter1``.

#. If another person holds a lock, ask the owner to release it.
   Do not remove the lock yourself.

#. If MCM holds unexpected locks, place it into standby.

   .. prompt:: text ccs>

       mcm standby -w

.. _Take-LSSTCam-Under-OCS-Control-Hardware-Alerts:

Review Hardware Alerts
----------------------

#. Read the raised alerts for each critical subsystem.

   .. prompt:: text ccs>

       fcs getRaisedAlertSummary
       focal-plane getRaisedAlertSummary
       shutter1 getRaisedAlertSummary

#. Clear a known ``ALARM`` by its identifier.

   .. prompt:: text ccs>

       fcs clearAlerts <ALERT_ID> -w
       focal-plane clearAlerts <ALERT_ID> -w
       shutter1 clearAlerts <ALERT_ID> -w

   .. warning::

       When ``WARNING`` and ``ALARM`` alerts exist at the same time,
       do not use ``clearAllAlerts`` indiscriminately.
       Clear the known ``ALARM`` alerts individually.

#. Confirm the subsystem states.

   .. prompt:: text ccs>

       fcs getState
       focal-plane getState -t
       shutter1 getState

   Expect ``AlertState:NOMINAL``, or a known ``WARNING``,
   together with ``OperationalState:NORMAL``, a closed shutter, and a ready focal plane.

#. If the focal plane reports ``GuidingState:PAUSED``, contact the Camera Team.
   They issue the action that stops the guiders.

.. _Take-LSSTCam-Under-OCS-Control-Review-MCM:

Review MCM
----------

#. Read and clear the MCM alerts, then confirm its state.

   .. prompt:: text ccs>

       mcm getRaisedAlertSummary
       mcm clearAlerts <ALERT_ID> -w
       mcm getState

#. Confirm the following values.

   .. code-block:: text

       AlertState:NOMINAL
       OperationalState:NORMAL
       CommandState:READY
       TakeImageReadinessState:READY

.. _Take-LSSTCam-Under-OCS-Control-Recover-Bridge:

Recover the OCS Bridge
----------------------

#. Read the bridge state.

   .. prompt:: text ccs>

       ocs-bridge getState

#. If the bridge is in ``FAULT`` and the cause is already corrected,
   clear the fault and make it available again.

   .. prompt:: text ccs>

       ocs-bridge clearFault -w
       ocs-bridge setAvailable -w
       ocs-bridge getState

#. Enable ``MTCamera`` from the OCS.

.. _Take-LSSTCam-Under-OCS-Control-Troubleshooting:

Troubleshooting
===============

-  If ``MTCamera`` stays in ``FAULT`` after this procedure, escalate as described in the
   :ref:`escalation criteria <LSSTCam-Monitoring-Escalation-Criteria>`.

-  If an alert reappears immediately after you clear it,
   the underlying condition is not corrected.
   Stop, and contact the Camera Team.

This procedure was last modified on |today|.

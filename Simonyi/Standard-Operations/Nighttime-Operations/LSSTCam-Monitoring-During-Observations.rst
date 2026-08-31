.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. _Nighttime-Operations-LSSTCam-Monitoring-During-Observations:

######################################
LSSTCam Monitoring During Observations
######################################

.. _LSSTCam-Monitoring-Overview:

Overview
========

This page describes how to monitor LSSTCam through an observing night,
how to respond to an anomaly, and when to escalate immediately.

Active monitoring detects trends before the automatic protections act.
A protective stop can start a warm up whose recovery takes one to two weeks,
so the value of catching a trend early is high.

.. _LSSTCam-Monitoring-Precondition:

Precondition
============

-  The :ref:`LSSTCam daily checkout <Daytime-Operations-LSSTCam-Daily-Checkout>` is complete.
-  ``MTCamera`` is ``ENABLED``.
-  You can reach *#cam-operator*, *#cam-summit-ccs-alerts*, and *#summit-control-room*.

.. _LSSTCam-Monitoring-Post-Condition:

Post-Condition
==============

-  The camera is left in the state requested by the Observatory Operations Duty officer
   and the Camera Team.
-  Telemetry values, trends, alerts, and test results are recorded in the handover.

.. _LSSTCam-Monitoring-Normal-Work-Cycle:

Normal Work Cycle
=================

.. _LSSTCam-Monitoring-Start-of-Shift:

Start of Shift
--------------

#. Read the handover, and review active work.

#. Review the alerts and *#cam-operator*.

#. Run the :ref:`cooling and vacuum inspection <Daytime-Operations-LSSTCam-Cooling-and-Vacuum-Checkout>`.

#. Confirm :ref:`CCD power and HV <Daytime-Operations-LSSTCam-Focal-Plane-Readiness-Checkout>`.

#. :ref:`Restart the OCS bridge and Kafka <Daytime-Operations-LSSTCam-Restart-OCS-Bridge-and-Kafka>`
   when it applies.

#. :ref:`Take the camera under OCS control <Daytime-Operations-LSSTCam-Take-Under-OCS-Control>`.

#. Run the :ref:`checkout DARKs <LSSTCam-Functional-Tests-DARK-Acquisition>`.

#. Run the :ref:`Filter Exchange System test <LSSTCam-Functional-Tests-Filter-Exchange>`
   once the telescope state allows it.

#. Report that LSSTCam is ready, or record the outstanding problems.

.. _LSSTCam-Monitoring-During-Observations-Views:

During Observations
-------------------

Keep the following views available.

-  LOVE and the Watcher.
-  The Big Plot, or the Chronograf dashboard.
-  *#cam-summit-ccs-alerts*.
-  *#cam-operator*.
-  The Cluster Monitor.
-  RubinTV and the CCS Image Viewer, as needed.

Watch the following quantities in particular.

-  Glycol flow and temperatures.
-  The Cold Plate.
-  The Cryo Plate.
-  Cryo and HEX vacuum.
-  Dynalene to the Utility Trunk.
-  Compressor pressures.
-  REB power.
-  Missing detectors, and ingestion problems.
-  ``MTCamera`` faults, and OCS bridge timeouts.

.. _LSSTCam-Monitoring-Anomaly-Response:

Anomaly Response
================

Apply this sequence when something changes unexpectedly.

#. **Acknowledge.** Identify the alarm, its timestamp, the subsystem, and the severity.

#. **Correlate.** Review the Big Plot, Chronograf, and CCS Web Trending.

#. **Consult.** Review *#cam-operator* to rule out an intentional action.

#. **Communicate.** Notify the Camera Team, and the Observatory Operations Duty officer,
   according to the severity.

#. **Protect.** Stop new exposures if continuing can worsen the condition.

#. **Do not improvise.** Do not restart chillers or cryo compressors,
   and do not change setpoints, without instructions.

#. **Document.** Record the time, the telemetry, the actions taken, the people contacted,
   and the outcome.

.. _LSSTCam-Monitoring-Escalation-Criteria:

Immediate Escalation Criteria
=============================

Escalate as an emergency when any of the following appears.

-  ``CryoVac`` or ``HexVac`` above 1e-7 torr.
-  Glycol flow to the PCS below 1 gal/min.
-  A critical quantity falls to zero for more than one minute without explanation.
-  A rapid change in the PCS, Cold Plate, or Cryo Plate temperatures.
-  A large cryo pressure trend without a circuit being intentionally turned on or off.
-  An unexpected loss of Utility Trunk cooling.
-  Multiple REBs losing power or HV.
-  ``MTCamera`` in ``FAULT`` that does not recover through the authorized procedure.
-  Large red regions in the Cluster Monitor, or detectors missing from the images.

If the condition impairs data taken on sky, file a
:ref:`fault report <Daytime-Nighttime-Interactions-fault-reporting>`.
Outside working hours, use the
:ref:`out of hours support <Safety-out-of-hours-support>`.

.. _LSSTCam-Monitoring-Handover:

Handover
========

.. note::

    No formal shutdown or end of shift sequence is documented for LSSTCam.
    Under normal conditions, leave the camera in the state requested by
    the Observatory Operations Duty officer and the Camera Team.
    Do not improvise a power down sequence.

Record the following in the handover.

-  The cryo compressor that is intentionally off.
-  The relevant values and trends:

   -  Glycol flow.
   -  ``GlycChillerIn`` and ``GlycChillerOut``.
   -  The Cold Plate.
   -  The Cryo Plate.
   -  Cryo and HEX vacuum.
   -  Dynalene.
   -  Trim heater power.

-  Alerts that are active or were cleared, with the justification.
-  Whether :command:`ocs-bridge` and Kafka were restarted.
-  The result of the DARKs.
-  The result of the Filter Exchange System test.
-  Any problem with the DAQ, ingestion, RubinTV, or the guiders.
-  The final state of ``MTCamera``.
-  Pending interventions, and the people notified.

This procedure was last modified on |today|.

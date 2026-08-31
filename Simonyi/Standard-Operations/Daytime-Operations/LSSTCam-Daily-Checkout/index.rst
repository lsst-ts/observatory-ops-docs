.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. This is the label that can be used as for cross referencing this procedure.
.. _Daytime-Operations-LSSTCam-Daily-Checkout:

######################
LSSTCam Daily Checkout
######################

.. _LSSTCam-Daily-Checkout-Overview:

Overview
========

This checkout confirms that LSSTCam is cooled, powered, under Observatory Control System control,
and producing images before you hand the camera over for observations.
Run it near the beginning of every shift, daytime or nighttime.

The goal is not only to confirm that telemetry sits inside absolute limits.
It is to detect changes and new trends,
so compare every quantity against the previous shift or the previous day.
A value that looks acceptable on its own can still signal a developing problem
if it has moved since yesterday.

The checkout is split into the following procedures.
Run them in order.

.. toctree::
    :maxdepth: 2
    :titlesonly:

    Cooling-and-Vacuum-Checkout.rst
    Focal-Plane-Readiness-Checkout.rst
    Restart-OCS-Bridge-and-Kafka.rst
    Take-LSSTCam-Under-OCS-Control.rst
    LSSTCam-Functional-Tests.rst

Once the camera is ready, monitor it through the night as described in
:ref:`LSSTCam monitoring during observations <Nighttime-Operations-LSSTCam-Monitoring-During-Observations>`.

.. admonition:: Safety Principles
    :class: warning

    These rules apply to every part of the checkout.

    -  Do not clear an alert you do not recognize, that is not documented as benign,
       or whose cause you do not understand.
    -  Do not restart cooling hardware, such as chillers or cryo compressors.
    -  Do not change setpoints without authorization from the Camera Team.
    -  Do not power on a raft, a REB, or an HV circuit on your own.

.. _LSSTCam-Daily-Checkout-Precondition:

Precondition
============

You have access to the Summit VPN, and to the following interfaces.

-  Chronograf, and the *LSSTCam Utility and State Monitoring Dashboard*.
-  CCS Web Trending, and the Big Plot.
-  :command:`ccs-shell`.
-  :command:`ccs-console`.
-  The OCS ScriptQueue and LOVE.
-  The CCS Image Viewer.
-  Summit RubinTV, USDF RubinTV, and the Summit RubinTV Cluster Monitor.
-  SSH access to the camera machines.

You can reach the following channels.

-  *#cam-summit-ccs-alerts*
-  *#cam-operator*
-  *#summit-control-room*
-  The Camera Team member on shift.

.. _LSSTCam-Daily-Checkout-Post-Condition:

Post-Condition
==============

-  Cooling and vacuum telemetry is stable and explained.
-  All REBs report CCD power and HV bias on.
-  ``MTCamera`` is ``ENABLED`` and under OCS control.
-  Checkout DARKs are acquired, ingested, and visible in RubinTV.
-  The Filter Exchange System test is complete, when telescope state allowed it.
-  The camera state, and any outstanding problem, is reported and recorded in the handover.

.. _LSSTCam-Daily-Checkout-Summary-Checklist:

Summary Checklist
=================

Use this checklist to track the checkout.
Each item is described in the procedure pages linked above.

.. list-table:: Start of Shift
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - Handover and active work reviewed
     - :ref:`Cooling and vacuum checkout <LSSTCam-Cooling-and-Vacuum-Checkout-Review-State>`
   * - *#cam-summit-ccs-alerts* reviewed
     - :ref:`Cooling and vacuum checkout <LSSTCam-Cooling-and-Vacuum-Checkout-Review-State>`
   * - *#cam-operator* reviewed
     - :ref:`Cooling and vacuum checkout <LSSTCam-Cooling-and-Vacuum-Checkout-Review-State>`

.. list-table:: Cooling and Vacuum
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - Glycol supply and return temperatures stable
     - :ref:`PCS chiller and glycol supply <LSSTCam-Cooling-and-Vacuum-Checkout-Glycol>`
   * - Glycol flow above 2 gal/min
     - :ref:`PCS chiller and glycol supply <LSSTCam-Cooling-and-Vacuum-Checkout-Glycol>`
   * - Compressors that are on and off identified
     - :ref:`Cryo compressors <LSSTCam-Cooling-and-Vacuum-Checkout-Compressors>`
   * - Suction and discharge pressures stable
     - :ref:`Cryo compressors <LSSTCam-Cooling-and-Vacuum-Checkout-Compressors>`
   * - HEX temperatures stable
     - :ref:`HEX temperatures <LSSTCam-Cooling-and-Vacuum-Checkout-HEX>`
   * - Dynalene supply, return, and flow stable
     - :ref:`Dynalene and Utility Trunk <LSSTCam-Cooling-and-Vacuum-Checkout-Dynalene>`
   * - Cold Plate between -35 and -40 degrees C
     - :ref:`Cold Plate <LSSTCam-Cooling-and-Vacuum-Checkout-Cold-Plate>`
   * - Cryo Plate near -123.5 degrees C
     - :ref:`Cryo Plate <LSSTCam-Cooling-and-Vacuum-Checkout-Cryo-Plate>`
   * - Trim heater power compared against the previous day
     - :ref:`Cryo Plate <LSSTCam-Cooling-and-Vacuum-Checkout-Cryo-Plate>`
   * - ``CryoVac`` and ``HexVac`` below 1e-7 torr, with no trend
     - :ref:`Cryostat and HEX vacuum <LSSTCam-Cooling-and-Vacuum-Checkout-Vacuum>`

.. list-table:: Focal Plane
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - REB total power above 1000 W
     - :ref:`REB total power <LSSTCam-Focal-Plane-Readiness-REB-Power>`
   * - CCD power on for all REBs
     - :ref:`Focal plane state <LSSTCam-Focal-Plane-Readiness-State>`
   * - HV bias on for all REBs
     - :ref:`Focal plane state <LSSTCam-Focal-Plane-Readiness-State>`
   * - ``rebpower isHvControlActive`` returns ``true``
     - :ref:`HV control <LSSTCam-Focal-Plane-Readiness-HV-Control>`
   * - HV median near 50 V, minimum near 30 V
     - :ref:`HV control <LSSTCam-Focal-Plane-Readiness-HV-Control>`

.. list-table:: Daily Maintenance
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - ``MTCamera`` ``OFFLINE`` before the restart
     - :ref:`Restart preconditions <Restart-OCS-Bridge-and-Kafka-Precondition>`
   * - :command:`ocs-bridge` restarted and active
     - :ref:`Restart the services <Restart-OCS-Bridge-and-Kafka-Restart-Services>`
   * - Kafka restarted and active
     - :ref:`Restart the services <Restart-OCS-Bridge-and-Kafka-Restart-Services>`
   * - Telemetry confirmed in the EFD
     - :ref:`Confirm telemetry <Restart-OCS-Bridge-and-Kafka-Confirm-Telemetry>`

.. list-table:: OCS Control
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - MCM in ``OperationalState:NORMAL``
     - :ref:`Take control <Take-LSSTCam-Under-OCS-Control-Procedure-Steps>`
   * - Alerts known and resolved
     - :ref:`Take control <Take-LSSTCam-Under-OCS-Control-Procedure-Steps>`
   * - :command:`ocs-bridge` in ``OfflineState:OFFLINE_AVAILABLE``
     - :ref:`Take control <Take-LSSTCam-Under-OCS-Control-Procedure-Steps>`
   * - ``MTCamera`` ``ENABLED``
     - :ref:`Take control <Take-LSSTCam-Under-OCS-Control-Procedure-Steps>`

.. list-table:: Functional Tests
   :widths: 60 40
   :header-rows: 1

   * - Item
     - Reference
   * - Three 30 s DARKs complete
     - :ref:`DARK acquisition <LSSTCam-Functional-Tests-DARK-Acquisition>`
   * - All detectors and wavefront sensors present
     - :ref:`DARK acquisition <LSSTCam-Functional-Tests-DARK-Acquisition>`
   * - Summit and USDF RubinTV verified
     - :ref:`DARK acquisition <LSSTCam-Functional-Tests-DARK-Acquisition>`
   * - Cluster Monitor normal
     - :ref:`DARK acquisition <LSSTCam-Functional-Tests-DARK-Acquisition>`
   * - Guider stamps processed
     - :ref:`DARK acquisition <LSSTCam-Functional-Tests-DARK-Acquisition>`
   * - Filter Exchange System test complete, when applicable
     - :ref:`Filter Exchange System test <LSSTCam-Functional-Tests-Filter-Exchange>`
   * - Result communicated and handover updated
     - :ref:`Handover <LSSTCam-Monitoring-Handover>`

This procedure was last modified on |today|.

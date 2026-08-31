.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. _Daytime-Operations-LSSTCam-Functional-Tests:

########################
LSSTCam Functional Tests
########################

.. _LSSTCam-Functional-Tests-Overview:

Overview
========

These tests confirm that LSSTCam acquires images, that the data is ingested and displayed,
and that the Filter Exchange System operates.
Run them after the camera is under Observatory Control System control.

.. _LSSTCam-Functional-Tests-Precondition:

Precondition
============

-  ``MTCamera`` is ``ENABLED``, as described in
   :ref:`taking LSSTCam under OCS control <Daytime-Operations-LSSTCam-Take-Under-OCS-Control>`.
-  You have access to the CCS Image Viewer, Summit RubinTV, USDF RubinTV,
   and the Summit RubinTV Cluster Monitor.
-  For the Filter Exchange System test only:

   -  The telescope is handed over to observations.
   -  The required MTTCS systems are enabled.
   -  No intervention on the Filter Exchange System is active.

.. _LSSTCam-Functional-Tests-Post-Condition:

Post-Condition
==============

-  Three DARK images are acquired and ingested.
-  All detectors, including the wavefront sensors, appear in the CCS Image Viewer.
-  Sequence numbers appear in Summit RubinTV and in USDF RubinTV.
-  Guider stamps are processed.
-  A filter change completes without fault, when the test applies.

.. _LSSTCam-Functional-Tests-Procedure-Steps:

Procedure Steps
===============

.. _LSSTCam-Functional-Tests-DARK-Acquisition:

DARK Acquisition
----------------

#. Open the CCS Image Viewer, Summit RubinTV, USDF RubinTV,
   and the Summit RubinTV Cluster Monitor.

#. Confirm that the Cluster Monitor shows normal conditions.

#. Acquire the DARKs with the following configuration.

   .. code-block:: text
       :caption: DARK acquisition configuration

       exp_times: 30
       nimages: 3
       image_type: "DARK"
       reason: "LSSTCamCheckout"
       program: "BLOCK-T594"

#. While the images are taken, watch the Cluster Monitor.
   Some frames turning orange, together with a small amount of red, is normal.
   If large regions turn red, report it in *#summit-control-room*.

#. When the acquisition finishes, confirm that every detector appears in the CCS Image Viewer.
   White blocks can indicate missing detectors.
   Include the wavefront sensors in this review.

#. Confirm that the sequence numbers appear in Summit RubinTV,
   and in USDF RubinTV unless a known connection outage applies.

#. Confirm that the guider stamps are processed.

.. note::

    Confirm the ``program`` identifier with the Camera Team before you rely on this configuration.
    The guider stamp processing check depends on running under that BLOCK.

.. _LSSTCam-Functional-Tests-Filter-Exchange:

Filter Exchange System Test
---------------------------

Run this test only when the telescope is handed over to observations,
the required MTTCS systems are enabled,
and no intervention on the Filter Exchange System is active.

#. Run :file:`change_filter_lsstcam.py` with a filter that is not already in the optical path.

   .. code-block:: text
       :caption: :file:`change_filter_lsstcam.py`

       filter: <FILTER_NAME>

   The documented filters are the following.

   .. code-block:: text

       NONE, g_6, z_20, u_24, i_39, r_57, y_10

#. Listen to the exchange through the control room audio.
   The audio can lag by about 30 seconds.

#. Confirm that the change completes without fault.

.. warning::

    Do not change filters more often than once every two minutes.

.. note::

    Confirm the current filter names with the Camera Team.
    The set installed in the carousel can change.

.. _LSSTCam-Functional-Tests-Troubleshooting:

Troubleshooting
===============

-  If large regions of the Cluster Monitor turn red, or detectors are missing from the images,
   report it in *#summit-control-room* and escalate as described in the
   :ref:`escalation criteria <LSSTCam-Monitoring-Escalation-Criteria>`.

-  If images do not appear in Summit RubinTV, check whether they were ingested,
   then report the issue in *#cam-operator*.

-  If a filter change ends in fault, do not retry immediately.
   Report it to the Camera Team.

-  If the test impairs data taken on sky, file a
   :ref:`fault report <Daytime-Nighttime-Interactions-fault-reporting>`.

This procedure was last modified on |today|.

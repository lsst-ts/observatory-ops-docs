.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. _Daytime-Operations-LSSTCam-Restart-OCS-Bridge-and-Kafka:

############################
Restart OCS Bridge and Kafka
############################

.. _Restart-OCS-Bridge-and-Kafka-Overview:

Overview
========

This daily maintenance restarts the :command:`ocs-bridge` and Kafka services
to reduce the risk of an outage caused by excessive memory use.
Perform it before you take the camera under Observatory Control System control.

.. _Restart-OCS-Bridge-and-Kafka-Precondition:

Precondition
============

-  ``MTCamera`` is in ``SummaryState: OFFLINE``, that is, offline and publish only.
-  No image acquisition is active.
-  The Camera Team confirms that no intervention is in progress.
-  You have SSH access to *lsstcam-mcm.cp.lsst.org*.

.. _Restart-OCS-Bridge-and-Kafka-Post-Condition:

Post-Condition
==============

-  Both services report ``active (running)``, with a recent timestamp.
-  ``MTCamera`` has no persistent ``FAULT``.
-  Telemetry reaches the Engineering Facility Database.

.. _Restart-OCS-Bridge-and-Kafka-Procedure-Steps:

Procedure Steps
===============

.. _Restart-OCS-Bridge-and-Kafka-Connect:

Connect to the Camera Master Control Machine
--------------------------------------------

.. prompt:: bash

    ssh <IPA_USERNAME>@lsstcam-mcm.cp.lsst.org
    sudo -iu ccs

.. _Restart-OCS-Bridge-and-Kafka-Review-State:

Review Service State and Memory
-------------------------------

.. prompt:: bash

    sudo systemctl status ocs-bridge.service
    sudo systemctl status kafka-broker-service.service
    top -c

Press :kbd:`q` to leave the long views.

.. _Restart-OCS-Bridge-and-Kafka-Restart-Services:

Restart the Services
--------------------

#. Restart :command:`ocs-bridge`, and check its state.

   .. prompt:: bash

       sudo systemctl restart ocs-bridge.service
       sudo systemctl status ocs-bridge.service

#. In a :command:`ccs-shell`, confirm the bridge state.

   .. prompt:: text ccs>

       ocs-bridge getState

#. Restart Kafka, and check its state.

   .. prompt:: bash

       sudo systemctl restart kafka-broker-service.service
       sudo systemctl status kafka-broker-service.service

.. note::

    While :command:`ocs-bridge` restarts, ``MTCamera`` can enter ``FAULT`` briefly
    because it loses the heartbeat.
    The Kafka restart clears that condition automatically.
    CPU use near 800 percent immediately afterward can be normal.

    The restart order of the two services is not critical,
    but always follow the same sequence to make diagnosis easier.

.. _Restart-OCS-Bridge-and-Kafka-Confirm-Telemetry:

Confirm Telemetry and Close the Session
---------------------------------------

#. Confirm that both services report ``active (running)`` with a recent timestamp.

#. Confirm that ``MTCamera`` holds no persistent ``FAULT``.

#. Confirm that telemetry reaches the Engineering Facility Database.

   a. Open the Big Plot.

   b. Change :guilabel:`Source` to :guilabel:`EFD`.

   c. Confirm that the data is recent.

#. Leave the ``ccs`` user.

   .. prompt:: bash

       logout

.. _Restart-OCS-Bridge-and-Kafka-Troubleshooting:

Troubleshooting
===============

-  If either service does not return to ``active (running)``,
   stop the checkout and escalate to the Camera Team.

-  If ``MTCamera`` holds a ``FAULT`` after the Kafka restart, recover the bridge as described in
   :ref:`recovering the OCS bridge <Take-LSSTCam-Under-OCS-Control-Recover-Bridge>`.

This procedure was last modified on |today|.

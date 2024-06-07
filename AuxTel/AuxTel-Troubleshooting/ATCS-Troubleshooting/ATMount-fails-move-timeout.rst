.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Y.-AlSayyad*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *P.-Venegas*, *K.-Aubel*, *K.-Pena*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Mount-Fails-to-Move-and-Times-Out:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#########################################
AuxTel Mount Fails to Move and Times Out
#########################################

.. _AuxTel-Mount-Fails-to-Move-and-Times-Out-Procedure-Overview:

Overview
========

In this troubleshooting guide, we address an issue where the telescope times out while getting into position. 
All ATCS CSCs indicated no faults. However, the ATMCS Engineering User Interface System (EUI) showed several low air pressure faults. An air leak was discovered at the telescope base. 

.. _AuxTel-Mount-Fails-to-Move-and-Times-Out-Procedure-Error-Diagnosis:

Error diagnosis
===============

The queued **latiss_aquire_and_take_sequence.py** script report the following error:

.. code-block::

   File "/net/obs-env/auto_base_packages/ts_observatory_control/python/lsst/ts/observatory/control/auxtel/atcs.py", line 1658, in wait_for_inposition
    
    raise RuntimeError: Telescope timed out getting in position.
..

No ATCS CSCs is in fault, but the ATMCS EUI did indicate several low air pressure faults. An on-site check at the dome found the compressor running at pressure, but there was a noticeable air leak at a fitting at the telescope base.

However, since no CSCs were actually reporting faults, the leak might not be critical and the proximate cause in this case might actually being a lost DDS message between the ATMCS and ATPTG CSCs.


.. _AuxTel-Mount-Fails-to-Move-and-Times-Out-Procedure-Procedure-Steps:


Procedure Steps
===============

The recovery is detailed below.

**From LOVE**

#. Stop the Scheduler and clear any pending scripts. In the queue send the **auxtel/scheduler/stop.py** script and resume queue.

#. Cycle the **ATTCS:ATPtg** CSCs to standby and back to enabled.

#. Confirm mount is now responsive by queueing command **auxtel/point_azel.py**, specifying an azimuth and elevation some distance away from the current mount position, and observing mount motion.
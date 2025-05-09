.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *I. Sotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *K. Peña, P. Venegas*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Troubleshooting-MTCS-MTDome-Recover-and-clear-Faults:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.


.. _MTDome Status: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/165?refresh=10s&lower=now%28%29%20-%2015m

################################
MTDome Recover and clear Faults
################################

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Overview:

Overview
========
 
If issues arise with moving the MTDome directly, or if you observe that the *MTDomeTrajectory* following mode is ``ENABLED``, but the dome fails to follow the telescope, it is likely that the MTDome is having an internal subsystem fault and requires recovery.

Under specific circumstances, the dome may ignore move commands, such as when its position is identical to the previous *moveAz* command and the *velocity is 0.0 [deg/sec]*. 
To confirm this, inspect the MTDome logs in LOVE. 
The CSC would have received the duplicated move command, and a warning message will be displayed in the logs, indicating that it was ignored.

In other instances, the dome may reject move commands, when there is a subsystem ``FAULT``.

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Error-Diagnosis:

Error diagnosis
===============

- If a ``FAULT`` is indicated in the *Azimuth Control Software Status* (ACS status) window, the dome has an internal fault condition.
- Look at the Chronograf dashboard `MTDome Status`_ to verify the system status.

.. Note::
    
    The dome has several subsystems that continue to operate when a specific subsystem goes to ``FAULT``, the CSC itself won't go to ``FAULT``, unless it is an unrecoverable issue.
    A subsystem going to ``FAULT`` is recoverable.

..
.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Procedure-Steps:

Procedure Steps
===============
1. Disable the dome following mode in *MTDomeTrajectory*.

.. code-block:: text
  :caption: :file:`run_command.py`

    component: MTDomeTrajectory
    cmd: setFollowingMode
    parameters:
        enable: false
..

2. To clear the subsystem ``FAULT``, use the MTDome **exitFault** configuration command via the :file:`run_command.py` SAL script. 
In most cases, running the command once will clear the fault, but you may need to repeat the process a few times.

.. code-block:: text
  :caption: :file:`run_command.py`

    component: MTDome
    cmd: exitFault
..

3. After executing the command, verify its success by checking the ACS status in the `MTDome Status`_ dashboard. 

.. Note::  When the *exitFault* command is sent, the CSC executes the *resetDrivesAz* command before *exitFault* command.

  Command sent by **exitFault:**
    Configuration for *resetDrivesAz*
 
  .. code-block:: text  
    :caption: :file:`run_command.py`

      component: MTDome
      cmd: resetDrivesAz
      paramaters:
       reset: [1,1,1,1,1]
  

4. Now, at this point, you can try to move the dome again. 

- Confirm the dome moves by slewing to a nearby position; in the example below, 45 degrees azimuth. 
- Make sure that the dome moves before enabling the *MTDomeTrajectory* mode.

.. code-block:: text
  :caption: :file:`run_command.py`
    
    component: MTDome
    cmd: moveAz
    parameters:
        position: 45
..

5. Check the MTDome logs when trying to move it the first time after recovering it. 
If you see a warning message:

.. warning::
    Ignoring *moveAz* command for position=300.0 and velocity=0.0 because it is a duplicate command
..

The error means the CSC is ignoring the move command, regardless of whether the position mentioned in the message is the current position of the Dome.
In this case, try to move the dome to a different position.

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Post-Condition:

Post-Condition
==============

MTDome faults are clear and operations can continue.

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Contingency:

Contingency
===========

If the above procedure was not successful, report the issue in **#summit-simonyi** and **#rubinobs-mtdome**



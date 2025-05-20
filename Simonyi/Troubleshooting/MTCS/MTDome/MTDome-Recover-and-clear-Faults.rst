.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *I. Sotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *K. Peña, P. Venegas, Kris Mortensen*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults:
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
 
If issues arise with moving the MTDome directly, or if you observe that the ``MTDomeTrajectory`` following mode is ``ENABLED``, but the dome fails to follow the telescope, it is likely that the MTDome is having an internal subsystem fault and requires recovery.

Under specific circumstances, the dome may ignore move commands, such as when its position is identical to the previous ``moveAz`` command and the *velocity is 0.0 [deg/sec]*. 
To confirm this, inspect the MTDome logs in LOVE. 
The CSC would have received the duplicated move command, and a warning message will be displayed in the logs, indicating that it was ignored.

In other instances, the dome may reject move commands, when there is a subsystem ``FAULT``. The most common subsytems to fault are either the
*Azimuth Motion Control System (AMCS)* or the *Aperture Shutter Control System (APSCS)*

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Error-Diagnosis:

Error diagnosis
===============

- If a ``FAULT`` is indicated in the **Azimuth Control Software Status (ACS status)** window, the dome has an internal fault condition.
- Look at the Chronograf dashboard `MTDome Status`_ to verify the system status.
- Verify whether the fault is associate with the AMCS or the APSCS. 

.. Note::
    
    The dome has several subsystems that continue to operate when a specific subsystem goes to ``FAULT``, the CSC itself won't go to ``FAULT``, unless it is an unrecoverable issue.
    A subsystem going to ``FAULT`` is recoverable.

..
.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Procedure-Steps:

Procedure Steps
===============

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-AMCS:

Procedure A: Recover AMCS Fault
-------------------------------

1. Disable the ``MTDomeTrajectory`` following mode using the provided 
SAL Script or via a run command.

.. tab-set:: 

   .. tab-item:: SAL Script

      .. code-block:: python

         # Script Name:
         maintel/mtdome/disable_dome_following.py

         # No Configurations

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDomeTrajectory
         cmd: setFollowingMode
         parameters:
           enable: false
           
2. If there is a ``FAULT`` reported in the `MTDome Status`_ dashboard execute the :file:`run_command.py` script using 
the ``exitFault`` configuration. In most cases, running the command once will clear the fault, but you may need to repeat 
the process a few times.

.. tab-set:: 

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDome
         cmd: exitFault
         parameters:
           subSystemIds: 0x1

.. note:: 

  The ``exitFault`` command will **fail**, reporting it was sent to an incorrect state, if the 
  Azimuth brakes are **not engaged**. In this case, first issue a stop command to engage the brakes:


  .. tab-set:: 

   .. tab-item:: Run Command

      .. code-block:: python

        # Script Name:
         run_command.py

         # Configuration:
         component: MTDome
         cmd: stop
         parameters:
           engageBrakes: true
           subSystemIds: 0x1

  
  If the Az control system (on the cRIO) goes to ``FAULT``, then the brakes will automatically be engaged. 
  The ``exitFault`` should be accepted in this state.


3. After executing the command, verify its success by checking the ACS status in the 
`MTDome Status`_ dashboard. 

.. note::  
  
  The ``exitFault`` command will internally send a ``resetDrivesAz`` command and this **should** get 
  the cRIO and other dome parts into an operational mode. 

  Command sent by ``exitFault``:
  
  .. tab-set:: 

   .. tab-item:: Run Command

      .. code-block:: python

        # Script Name:
         run_command.py

         # Configuration:
         component: MTDome
         cmd: resetDrivesAz
         paramaters:
           reset: [true, true, true, true, true]    

4. Now, at this point, you can try to 
move the dome again. 

a. Confirm the dome moves by slewing to a nearby position; in the example below, 45 degrees azimuth. 

.. tab-set:: 

   .. tab-item:: SAL Script

      .. code-block:: python

         # Script Name:
         maintel/mtdome/slew_dome.py

         # Configuration:
         az: 45

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDome
         cmd: moveAz
         parameters:
           position: 45

b. Make sure that the dome moves before enabling the ``MTDomeTrajectory`` following mode.

.. tab-set:: 

   .. tab-item:: SAL Script

      .. code-block:: python

         # Script Name:
         maintel/mtdome/enable_dome_following.py

         # No Configurations

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDomeTrajectory
         cmd: setFollowingMode
         parameters:
           enable: true

5. Check the MTDome logs when trying to move it the first time after recovering it. 
If you see the following warning message:

.. warning::
    Ignore the ``moveAz`` command for *position = 300.0* and *velocity = 0.0* because it is a duplicate command.
..

The error means the CSC is ignoring the move command, regardless of whether the position mentioned in the message is the current position of the Dome.
In this case, try to move the dome to a different position.

.. important::

   If none of the previous commands worked for the dome, this likely means the cRIO needs to be rebooted.
   To reset the cRIO, follow the instructions on Step 5 of the `Dome Handover Procedure <https://rubinobs.atlassian.net/projects/BLOCK?selectedItem=com.atlassian.plugins.atlassian-connect-plugin:com.kanoah.test-manager__main-project-page#!/v2/testCase/BLOCK-T70/testScript>`_
   and then repeat the following procedure.

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-APSCS:

Procedure B: Recover APSCS Fault
--------------------------------
     
1. If there is a ``FAULT`` reported in the `MTDome Status`_ dashboard execute the :file:`run_command.py` script using 
the ``exitFault`` configuration. In most cases, running the command once will clear the fault, but you may need to repeat 
the process a few times.

.. tab-set:: 

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDome
         cmd: exitFault
         parameters:
           subSystemIds: 0x4

2. Attempt to close the dome using the provided SAL Script, or via a run command if the script fails.

.. tab-set:: 

   .. tab-item:: SAL Script

      .. code-block:: python

         # Script Name:
         maintel/mtdome/close_dome.py

         # No Configurations

   .. tab-item:: Run Command

      .. code-block:: python

         # Script Name:
         run_command.py

         # Configuration:
         component: MTDomeTrajectory
         cmd: closeShutter

.. note::

   If neither the SAL script nor the run command works, you will need to close the shutter manually. 
   Follow the instructions for opening/closing manually on the 
   `Aperture Shutter Opening and Closing MTDome <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39690072/Aperture+Shutter+Opening+and+Closing+MTDome>`_
   page.

.. important::

   If no options have worked for closing the dome shutter, this likely means the moving cRIO needs to be rebooted. 
   
   **DO NOT ATTEMPT THIS ON YOUR OWN!**

   Contact one of the following dome experts for assistance:

   - Wouter van Reeven (Primary Contact)
   - Marina Pavlovic
   - Brian Stalder
   - Lorenzo Vio

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Post-Condition:

Post-Condition
==============

``MTDome`` CSC will be ``ENABLED``, and no fault is reported in the `MTDome Status`_ dashboard.

.. _MTDome-Troubleshooting-MTDome-Recover-and-clear-Faults-Contingency:

Contingency
===========

If the above procedure was not successful, report the issue in **#summit-simonyi** and **#rubinobs-mtdome**



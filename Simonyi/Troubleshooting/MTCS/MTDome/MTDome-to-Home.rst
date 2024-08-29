.. |author| replace:: *Tiago Ribeiro*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Paulina Venegas*


.. _Troubleshooting-MTCS-MTDome-MTDome-re-Home:

##############
MTDome re-Home
##############

.. _MTDome-MTDome-re-Home-Overview:

Overview
========
The dome needs re-homing if the reference azimuth position is lost, and the encoders are not reading the real position of the dome azimuth (as seen in the camera).

.. note::
  This is a temporary situation which will be resolved once EIE updates the azimuth rotation control software. A bar code will be installed by EIE which will provide absolute positioning for the ``MTDome``.

  This process already has started but will take a few more months. 
  
  Once the upgrade is completed, this procedure can be deprecated.
..


.. _MTDome-MTDome-re-Home-Procedure-Error-Diagnosis:

Error Diagnosis
===============

* While the dome is not pointing where it should, the images might be vignetted by the dome. In more extreme cases, no images show at all, if the cameras are covered completely by the dome. 
* The azimuth position reported by the dome is not the same as the one seen in the camera.


.. _MTDome-MTDome-re-Home-Procedure-Procedure-Steps:

Procedure Steps
===============

1. Move the dome to the position 328 deg azimuth, it will shows up in the camera. This is the *zero position* or park position for the MTDome.
   
   * Note that the readings reported by the dome in LOVE or Chronograf will be showing a different number, so you need to calculate the value of the unaligned encoders would read at the park position of 328 deg and send the dome to that angle.


* For instance, you notice the dome is reporting 10 deg AZ, but the camera marks 25.2 deg (the encoder 15.2 deg behind). To send the dome to home 328 degrees, you need to command the dome to move to (328 - 15.2) = 312.8 degrees.

    .. code-block:: run_command.py
     component: MTDome
     cmd: moveAz
     parameters:
        position: 312.8
..

2. Once the dome is in the *zero position*, you need to stop the dome and engage the breaks.

    .. code-block:: run_command.py
      component: MTDome
      cmd: stop
      parameters:
         engageBrakes: true
         subSystemIds: 1
..


3. Set the dome *zero azimuth* position by running :file:`run_command.py` script with the following configuration:

    .. code-block:: run_command.py
      component: MTDome
      cmd: setZeroAz
..


.. _MTDome-MTDome-re-Home-Post-Condition:

Post-Condition
==============
* MTDome encoder is showing the right value and operations can continue.

.. _MTDome-MTDome-re-Home-Contingency:

Contingency
===========
* If the above procedure was not successful, report the issue in *#summit-simonyi* and *#rubinobs-mtdome channels*.


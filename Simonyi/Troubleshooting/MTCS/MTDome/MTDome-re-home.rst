.. |author| replace:: *Tiago Ribeiro*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Paulina Venegas*

.. _Unifi Camera: https://unifi.ui.com/
.. _Unifi Dashboard: https://unifi.ui.com/consoles/D021F9521E8800000000063CF3E6000000000686EFB60000000061C81AC6:201406364/protect/dashboard/all
.. _UniFi at Cam-04: https://unifi.ui.com/consoles/D021F9521E8800000000063CF3E6000000000686EFB60000000061C81AC6:201406364/protect/devices/65785e4b0192f403e40003fc
.. _LOVE dashboard: https://summit-lsp.lsst.codes/love/uif/view-editor?id=145
.. _Chronograf: 


.. _MTDome-MTDome-re-Home:

##############
MTDome re-Home
##############

.. _MTDome-MTDome-re-Home-Overview:

Overview
========
The MTDome needs re-homing if the reference azimuth position is lost, and the encoders are not reading the real position of the MTDome azimuth.

.. note::
  This is a temporary situation which will be resolved once EIE updates the *azimuth rotation control software*. The absolute encoders will only be installed by EIE when the dome is finished.

  This process already has started but will take a few more months. Once completed this procedure can be deprecated.
..

.. _MTDome-MTDome-re-Home-Procedure-Error-Diagnosis:

Error Diagnosis
===============

* If the MTDome is not positioned where it should be, the images from the lightpath LSSTCam/ComCam/Startracker may get vignetted by the MTDome. In extreme case, the images will show nothing if the camera's lightpath is covered by the MTDome. 
* The MTDome azimuth position reported is not the same as the one seen in the divice *UniFi at Cam-04* (use VPN to get into `Unifi Dashboard`_).


   .. image:: _static/mtdome_rehome_1.png
      :target: _static/mtdome_rehome_1.png
      :height: 270px 
      :width: 410px 


   .. image:: _static/mtdome_rehome_2.png
      :target: _static/mtdome_rehome_2.png
      :height: 350px 
      :width: 210px 


  - *Left: image UniFi at Cam-04 and Right: image LOVE/MTDome summary dashboard*




.. _MTDome-MTDome-re-Home-Procedure-Procedure-Steps:

Procedure Steps
===============

1. Move the MTDome to the azimuth of 328 deg, the position can be verified through the camera systems `UniFi at Cam-04`_ (via VPN). This is the **zero position or park position** for the MTDome.

2. Note that the readings reported by the MTDome in `LOVE dashboard`_ or *Chronograf*  will show different numbers, so you need to calculate the value that the unaligned encoders would read at the park position of 328 degrees and send the MTDome to that angle.

    * For example: you notice the MTDome dashboard is reporting 10 degree in azimuth, but the camera marks 25.2 degrees.
    * Due to the encoder is 15.2 degrees behind, to send the MTDome to home at 328 degrees, you need to command the dome to move to **(328 - 15.2) = 312.8 degrees**


    .. code-block::
        :caption: run_command.py

        component: MTDome
        cmd: moveAz
        parameters:
          position: 312.8
..

3. Once the MTDome is in the **zero position**, you need to stop the MTDome and engage the breaks.

    .. code-block:: 
        :caption: run_command.py

        component: MTDome
        cmd: stop
        parameters:
            engageBrakes: true
            subSystemIds: 1
..


4. Set the MTDome **zero azimuth** position by running :command:`run_command.py` script with the following configuration:

    .. code-block:: run_command.py
        :caption: run_command.py

        component: MTDome
        cmd: setZeroAz
..


* This :command:`setZeroAz` command reset the actual position of the azimuth telemetry to 328 deg.

  * Only if that does not work, try a reboot of the cRIO. This will reset the zero position in the cRIO, so after a reboot no :command:`setZeroAz command` is necessary.
  * After a reboot, always send an :command:`exitFault` command (i.e :command:`cmd: exitFault`). If the azimuth control software is not in fault, the command will still be accepted.


.. _MTDome-MTDome-re-Home-Post-Condition:


Post-Condition
==============
* The MTDome encoder is showing the right value in the Unifi camera, operations can continue.

.. _MTDome-MTDome-re-Home-Contingency:

Contingency
===========
* If the above procedure was not successful, report the issue in **#summit-simonyi, #simonyi-discussion** and **#mtdome-worklog** channels and please open an OBS Jira ticket if neccesary.

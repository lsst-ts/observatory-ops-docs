.. This is a template for MTRotator recovery when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Yijung Kang*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Ioana Sotuela, Holger Drass, Kshitija Kelkar, Kris Mortensen, Jacqueline Seron, Te-Wei Tsai*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTRotator-Clear-Interlocks:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. raw:: html

    <style> .red {color:red} </style>
.. role:: red
.. raw:: html

    <style> .green {color:green} </style>
.. role:: green

####################################
MTRotator Clear Safety Interlocks
####################################


.. _MTRotator-Clear-Interlocks-Overview:

Overview
========

This troubleshooting procedures serves as a guide to clear low-level interlocks when recovering the MTRotator CSC from a ``FAULT``.

The procedure may require access to the MTRotator GUI :guilabel:`run_rotgui` (check :ref:`access instructions <Simonyi-Components-Simonyi-EUI-Access>`).

.. _MTRotator-Clear-Interlocks-Error-Diagnosis:

Error Diagnosis
===============

*  MTRotator CSC goes into ``FAULT`` state, but it cannot recover or cycle through CSC states from LOVE.
  
*  When trying to re-enable the MTRotator CSC in *ASummary State View*, 
   the following message is reported in the ``ERROR CODE`` or ``MESSAGE LOG``:

   .. code-block:: text
    
    Lower level interlock is activated 


.. _MTRotator-Clear-Interlocks-Procedure-Steps:

Procedure Steps
===============

.. note::

    Most MTRotator low-level interlocks can be cleared through the GIS GUI panel on level 2.

    Before attempting to clear low-level interlocks, try and :ref:`clear the MTrotator GIS <MTRotator-Clear-Interlocks-Procedure-Step6>` first,
    and then attempt to re-enable the MTRotator CSC.

1.  **Transition MTRotator CSC to** ``STANDBY``.

    a.  This can be done via `ASummary State View <https://summit-lsp.lsst.codes/love/uif/view?id=51>`_
        or through the `ScriptQueue <https://summit-lsp.lsst.codes/love/uif/view?id=43>`_.

        .. code-block:: python
            :caption: set_summary_state.py

            data:
              - [MTRotator, STANDBY]

2.  **Access the MTRotator GUI.**

    a.  Enter the virtual machine that controls the rotator (*hexrot-vm01.cp.lsst.org*) with your IPA account credentials.

.. admonition:: Accessing the Rotator GUI
    :class: note

    **Remote Access:**
    The :ref:`How to Access MT M2/Rotator/Hexapods/Dome EUI <Simonyi-Components-Simonyi-EUI-Access>` 
    has a detailed procedure for accessing all the GUIs in the virtual machine.

    **Summit Access:**
    If you are logged into a linux machine at the summit, you can enter the virtual machine using an SSH command.

    * Open a terminal from the 'Activities' tab on top left, and type the following command::

        ssh -Y hexrot-vm01.cp.lsst.org
    
    
    c.  Once in the virtual machine, access the rotator using the :command:`run_rotgui` command:: 

        [(username)@hexrot-vm01 ~]$ run_rotgui


.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_8.png
    :name: mtrot_recovery_8

    MTRotator Python GUI


3.  **Change the Command Source from CSC to GUI mode.** 

    a. Once in the *Rotator Control GUI*, :guilabel:`Connect` to the low-level controller (top-left).
    b. In the ``Command`` section of the GUI, select :guilabel:`Switch command source`. 
    c. Under the ``Command Parameters`` go to ``Command Source`` and select :guilabel:`GUI`.    
    d. Execute the command by clicking :guilabel:`Send Command` at the bottom of the GUI.
      
.. _MTRotator-Clear-Interlocks-Procedure-Step4:

4.  **Clear Simulink/Interlock errors in MTRotator GUI.**

    a. In the ``Main`` tab, go to the ``Commands`` tab.
    b. Under ``Command``, select :guilabel:`State command`.
    c. Under ``Command Parameters``, go to ``State Trigger`` and select :guilabel:`ClearError`.
    d. Send the command by clicking on the :guilabel:`Send Command` button.

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_7.png

    Sending ClearError Command
            
.. admonition:: Telemetry Verification
    :class: hint
    
    Double-click the :guilabel:`Telemetry` tab at the bottom of the GUI (see image above). 

    * | If the Safety Interlock is activated, you can find a red light next to the 
      | :guilabel:`Safety Interlock fault` with the ``Application Status`` tab.
    * In case of a Simulink Error, there will be red light next to the :guilabel:`Simulink fault` on the same page.

    .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_6.png
        :name: mtrot_recovery_6

        Rotator Telemetry with Faults (GUI Command Source)

    * When both errors are cleared, the telemetry no longer have red fault lights:

    .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_9.png
        :name: mtrot_recovery_9

        Rotator Telemetry without Faults (CSC Command Source)

5.  **Change the Command Source from GUI to CSC mode and exit the GUI.** 

    a. In the ``Command`` section of the GUI, select :guilabel:`Switch command source`.
    b. Under the ``Command Parameters`` go to ``Command Source`` and select :guilabel:`CSC`.
    c. Execute the command by clicking :guilabel:`Send Command` at the bottom of the GUI.
    d.  Remember to :guilabel:`Disconnect` the low-level controller before you :guilabel:`Exit` the GUI.

.. _MTRotator-Clear-Interlocks-Procedure-Step6:

6.  **Reset MTRotator in GIS GUI on Level 2.**

    a.  | Select the :guilabel:`M2Cam` tab and then click :guilabel:`Overview` (default). Below the 
        | ``CAM. ROTATOR`` section, press and hold the :guilabel:`Reset` button. A **green "X"** mark 
        | should appear next the the ``Reset`` label. If it does not show, press and hold the 
        | :guilabel:`Reset` button, again.

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_3.png
    :name: mtrot_recovery_3  
  
.. admonition:: IMPORTANT: Interlock Due to CCW Limits
    :class: warning 

    If the interlocks activated due to the rotator being out of range with the CCW, 
    make sure to follow the steps on :ref:`MTRotator-CCW-Limit-Switches` 
    before clearing the interlocks on the GIS.

7.  **Transition MTRotator CSC back to** ``ENABLED``.
    
    .. code-block:: python
            :caption: set_summary_state.py

            data:
              - [MTRotator, ENABLED]


.. _MTRotator-Clear-Interlocks-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- MTRotator is operational and can be re-enabled from *LOVE* to safely continue operations. 
 

.. _MTRotator-Clear-Interlocks-Contingency:

Contingency
===========

If the above procedure was not successful, announce in the `#summit_simonyi <https://rubin-obs.slack.com/archives/C07Q45P0PAB>`_ channel.

.. _MTRotator-Clear-Interlocks-Contingency-PXIReboot:

MTRotator PXI Controller Reboot
-------------------------------

In case EUI/CSC control is not connecting, you may need to proceed with the control system 
restart procedure of the :ref:`MTRotator and MTHexapods PXI controller Reboot 
(Soft, Hard and Control System Restart) <MTRot-PXI-Controller-Reboot>`.

.. _MTRotator-Clear-Interlocks-Contingency-LockingPin:

MTRotator Locking Pin Engaged
-----------------------------

On rare occasions, the ``Safety Interlock fault`` may remain when attempting to 
:ref:`clear the low-level interlocks <MTRotator-Clear-Interlocks-Procedure-Step4>`.
If the safety interlock does not clear, it might be due to the rotator pin 
not being disengaged properly. Instructions on removing the rotator locking pin are 
located in the `MTRotator Unlock Locking Pin <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39692272/MTRotator+Unlock+Locking+Pin>`_ 
page on Confluence.




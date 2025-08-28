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
.. |contributors| replace:: *Ioana Sotuela, Holger Drass, Kshitija Kelkar, Kristopher Mortensen, Jacqueline Seron, Te-Wei Tsai*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTRotator-Recovery:
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

#########################
MTRotator Recovery
#########################


.. _MTRotator-Recovery-Overview:

Overview
========

.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

In the event of a fault occurrence within the MTRotator, following the proper recovery procedure is essential to maintaining operational safety. 
This document will outline the necessary step-by-step actions to return to normal MTRotator functioning.

.. _MTRotator-Recovery-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

* The difference between the MTRotator and the Camera Cable Wrap (CCW) is too large. Bulkhead limit switch activated; this is also called :guilabel:`Pull cord +` or :guilabel:`Pull cord -`. 

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_1.png
        :name: mtrot_recovery_1

        TMA EUI screenshot indicating the pull cord +/- alert highlighted by the red box

* :ref:`Safety Interlock <mtrot_recovery_6>` active in the MTRotator GUI 
* :ref:`Simulink fault <mtrot_recovery_6>` in the MTRotator GUI 
* CCW Interlock D-8 activated on the GIS (link here to the GIS interlock screenshot)
* MTRotator CSC goes into ``FAULT`` state, but it cannot recover or cycle through CSC states from LOVE.
* :ref:`Watchdog <mtrot_recovery_4>` (WD) box in safety system of TMA EUI is red and GIS :ref:`TMA IS <mtrot_recovery_5>` is triggered. 

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_4.png
    :width: 300  
    :name: mtrot_recovery_4

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_5.png
    :name: mtrot_recovery_5


.. note::

    There are two ways to recover this fault:

    1. **Moving the CCW to the Camera Rotator**.

       * Instructions can be found on the `CCW Recovery Confluence Page <https://rubinobs.atlassian.net/wiki/x/xqZdAg>`_.

    2. **Moving the Camera Rotator to the CCW** (see the :ref:`Procedure Steps <MTRotator-Recovery-Procedure-Steps>` below).

.. _MTRotator-Recovery-Procedure-Steps:

Procedure Steps
===============
.. warning::
    Only proceed after an accurate assessment of the MTRotator fault is done and details have been documented in a ticket.

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.


1.  **Transition MTRotator CSC to** ``STANDBY`` **status**.

2.  **Clear the error from TMA EUI first.**

3.  **Access the MTRotator EUI/GUI:**

    a.  Enter the virtual machine that controls the rotator (*hexrot-vm01.cp.lsst.org*) with your IPA account credentials.

.. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_8.png
    :name: mtrot_recovery_8

    MTRotator Python GUI

.. admonition:: Accessing the Rotator GUI
    :class: note

    **Remote Access:**
    The `How to Access MT M2/Rotator/Hexapods/Dome EUI <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/39685455/How+to+Access+MT+M2+Rotator+Hexapods+Dome+EUI>`_ 
    has a detailed procedure for accessing all the GUIs in the virtual machine.

    **Summit Access:**
    If you are logged into a linux machine at the summit, you can enter the virtual machine using an SSH command.

    * Open a terminal from the 'Activities' tab on top left, and type the following command::

        ssh -Y hexrot-vm01.cp.lsst.org
    
    
    c.  Once in the virtual machine, access the rotator using the :command:`run_rotgui` command:: 

        [(username)@hexrot-vm01 ~]$ run_rotgui

.. _MTRotator-Recovery-Procedure-Step4:

4.  **Change the Command Source from CSC to GUI mode:** 

    a. Once in the *Rotator Control GUI*, :guilabel:`Connect` to the low-level controller (top-left).

    b. In the ``Command`` section of the GUI, select :guilabel:`Switch command source`.
    
    c. Under the ``Command Parameters`` go to ``Command Source`` and select :guilabel:`GUI`.
    
    d. Execute the command by clicking :guilabel:`Send Command` at the bottom of the GUI.
      
    

5.  **Clear Simulink error in MTRotator GUI:**

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

.. _MTRotator-Recovery-Procedure-Step6:

6.  **Reset MTRotator in GIS GUI on Level 2:**

    a. Select the :guilabel:`Det-Act` tab (bottom left of the screen), and press :guilabel:`Bypass` by the D-8 (CCW Safety Device Actuated). 

    .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_2.png
         :name: mtrot_recovery_2  

    b.  | Select the :guilabel:`M2Cam` tab and then click :guilabel:`Overview` (default). Below the 
        | ``CAM. ROTATOR`` section, press and hold the :guilabel:`Reset` button. A **green "X"** mark 
        | should appear next the the ``Reset`` label. If it does not show, press and hold the 
        | :guilabel:`Reset` button, again.

    .. figure:: /Simonyi/Troubleshooting/_static/mtrot_recovery_3.png
         :name: mtrot_recovery_3  
  
    

7.  **Enable MTRotator in GUI and Move to CCW:**

    a. | Instructions for enabling and moving the rotator are found in **steps 3-5**
       | of the :ref:`MTRotator Motion Check <MTRot-Motion-Check>` procedure.
    b. When selecting an ending position for the rotator, make sure that the rotation distance between
       the rotator and the CCW are **within the software limits**: 
       
    .. math::
        
        \boxed{\left|\theta_{CCW} - \theta_{Rot}\right|  < 2.5^{\circ}}



8.  **Reset Alarms in TMA GUI:**

    a.  In the :guilabel:`Safety System` :ref:`menu <mtrot_recovery_1>`, reset the 
        :guilabel:`Pull Cord +` or :guilabel:`Pull Cord -` alarm.

    b.  Navigate to the :guilabel:`Camera Cable Wrap` tab, and select :guilabel:`Reset alarm`.

9.  **Release the Bypass to the CCW in GIS GUI on Level 2** 
    (Refer to :ref:`Step 6a <MTRotator-Recovery-Procedure-Step6>`).

10. **Change the Command Source from GUI to CSC mode** (reverse procedure of :ref:`Step 4 <MTRotator-Recovery-Procedure-Step4>`).

    * Remember to :guilabel:`Disconnect` the low-level controller before closing the GUI.

11.  **Transition MTMount and MTRotator Back to** ``ENABLED``.



Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- MTRotator is operational and can be re-enabled from :guilabel:`LOVE` to safely continue operations. 
 

.. _MTRotator-Recovery-Contingency:

Contingency
===========

If the above procedure was not successful, inform in the #summit-simonyi channel.

In case EUI/CSC control is not connecting, you could proceed with the control system 
restart procedure of the :ref:`MTRotator and MTHexapods PXI controller Reboot 
(Soft, Hard and Control System Restart) <MTRot-PXI-Controller-Reboot>`.

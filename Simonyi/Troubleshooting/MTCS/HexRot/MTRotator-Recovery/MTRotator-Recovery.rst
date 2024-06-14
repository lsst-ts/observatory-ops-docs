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
.. |contributors| replace:: *Ioana Sotuela, Holger Drass, Kshitija Kelkar*

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

- The difference between the MTRotator and the Camera Cable Wrap (CCW) is too large. Bulkhead limit 
switch activated; this is also called :guilabel:`Pull cord +` or :guilabel:`Pull cord -`. 

 .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_1.png
  :name: mtrot_recovery_1

  TMA EUI screenshot indicating the pull cord +/- alert highlighted by the red box
- :ref:`Safety Interlock <mtrot_recovery_5>` active in the MTRotator GUI 
- :ref:`Simulink fault <mtrot_recovery_5>` in the MTRotator GUI 
- CCW Interlock D-8 activated on the GIS (link here to the GIS interlock screenshot)
- MTRotator CSC goes into ``FAULT``, but can not be recovered/cycled through CSC from LOVE.


.. _MTRotator-Recovery-Procedure-Steps:

Procedure Steps
===============
.. warning::
    Only proceed after an accurate assessment of the MTRotator fault is done and details have been documented in a ticket.

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.




#.  **Transition MTRotator CSC to** ``STANDBY`` **status**


#.  **Access the MTRotator EUI/GUI:**


    a.  Enter *hexrot-vm02.cp.lsst.org* with your IPA account credentials.
    
    b.  Once in the virtual machine, choose your user profile and enter your IPA password.

    c.  open a terminal from the 'Activities' tab on top left and go to the following - 

    .. prompt:: bash

        cd /rubin/
        cd rotator/
        cd build
        ./runRotEui
#.  **Change from DDS Command Source to GUI mode:** 

    .. _step_3:

    Click the :guilabel:`Parameters` tab in the MTRotator EUI, select ``GUI`` under 
    :guilabel:`Command Source`, and press :guilabel:`Set Command Source`. In case the 
    GUI control is not possible consult the :ref:`Contingency section <MTRotator-Recovery-Contingency>` below for further guidance. 

    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_2.png
        :scale: 40%  
        :name: mtrot_recovery_2
    

#.  **Clear Simulink error in MTRotator GUI:** 

    .. _step_4a:

    a.  In the MTRotator EUI Main tab, select ``State Cmd`` under :guilabel:`Commands to Send`. 
    In :guilabel:`State Triggers`, select ``ClearError`` and click on the :guilabel:`Send Command` 
    button. The **Simulink Error** light should be cleared now.

    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_3.png
     :name: mtrot_recovery_3
     :scale: 40%

    b.  When the **Safety Interlock fault** is :red:`activated`

    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_4.png
     :name: mtrot_recovery_4

    c.  When the **Safety Interlock fault** is deactivated.

    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_5.png
     :name: mtrot_recovery_5

#.  **Reset MTRotator in GIS GUI at Level 2:** 

    .. _step_5a:

    a.  Press :guilabel:`Bypass` by the D-8 (CCW Safety Device Actuated).
    
    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_6.png
     :name: mtrot_recovery_6  
     :scale: 20%

    b.  Click :guilabel:`M2Cam` and then :guilabel:`Overview` (Default). Note that you should 
    see a :green:`x` mark on the square of :guilabel:`Reset`. If not, click the 
    :guilabel:`Reset` button again. 

    .. figure:: /MainTel/MainTel-Troubleshooting/_static/mtrot_recovery_7.png
     :name: mtrot_recovery_7  
     :scale: 20%

#.  **Back to MTRotator GUI, clearError command to reset Safety Interlock:**

    Following a similar process to :ref:`Step 4.a <_step_4a>`, the ``ClearError`` command will remove the 
    safety interlock.      
    
#. **Enable the MTRotator, then move it to zero degrees** 

    To enable, ``State Cmd`` 
    is selected, :guilabel:`StateTriggers` menu shows ``Enable`` under and then click 
    :guilabel:`Send Command` button. To move the MTRotator, go to the :guilabel:`Commands to Send` 
    section and in :guilabel:`Enabled Substate Triggers`, 
    choose ``Move``. Then, input ``0`` degrees in the :guilabel:`Position Cmd` field and 
    execute the movement by clicking on the :guilabel:`Send Command` button.


#.  **Reset alarms in TMA GUI:**

    a.  In the :guilabel:`Safety System` :ref:`menu <mtrot_recovery_1>`, reset the 
    :guilabel:`Pull Cord +` or :guilabel:`Pull Cord -` alarm.

    b.  Exit the :guilabel:`Safety System`and enter the :guilabel:`Camera Cable Wrap` tab. 
    Click on :guilabel:`Reset alarm`.

    c.  In the :guilabel:`Camera Cable Wrap` tab, press the :guilabel:`ON` button. 
    Everything should be shown as green now.

#.  **Release the bypass to the CCW in GIS GUI in Level 2** 
    (Refer to :ref:`Step 5.a <step_5a>`)

#.  **Revert Command Source from EUI to DDS** (opposite to the :ref:`Step 3 <step_3>`) 


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
(Soft, Hard and Control System Restart) <MTRotator and MTHexapods PXI controller Reboot (Soft, Hard and Control System Restart)>`

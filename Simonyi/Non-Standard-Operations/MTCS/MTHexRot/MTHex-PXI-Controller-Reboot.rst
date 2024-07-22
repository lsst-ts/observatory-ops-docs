.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Iona Sotuela, Carlos Morales
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: Kshitija Kelkar

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTHex-PXI-Controller-Reboot:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#######################################################################
MTHexapod PXI Controller Reboot (Soft, Hard and Control System Restart)
#######################################################################


.. _MTHex-PXI-Controller-Reboot-Overview:

Overview
========

.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

This document provides detailed instructions on how to perform a soft reboot, hard reboot, and restart the 
control system for the MTHexapod PXI controllers at the summit. These procedures are essential for 
troubleshooting faults encountered during routine operations but might also be necessary during maintenance 
and other non-standard observatory operations, such as scheduled power off. 



.. _MTHex-PXI-Controller-Reboot-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

When troubleshooting the EUI/CSC failed to connect to the control system, follow the sequential order of 
the procedures below to re-establish control. If a procedure proves unsuccessful, proceed to the next 
one:

- :ref:`Restart Control system <MTRot-PXI-Controller-Reboot-Restart-Control-System>`
- :ref:`Soft Reboot <MTRot-PXI-Controller-Reboot-Soft-Reboot>`
- :ref:`Hard Reboot or Power off <MTRot-PXI-Controller-Reboot-Hard-Reboot>`

.. _MTHex-PXI-Controller-Reboot-Prerequisites:

Prerequisites
=============

- Ensure you have access to LSST-WAP network.
- Obtain the necessary IP, account user, and password information from the *LSST 1Password MainTel Vault*.
- Familiarity with Linux commands and the use of general *Power Distribution Unit (PDU)* or *netbooter* for power cycling.


.. _MTHex-PXI-Controller-Reboot-Procedure:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.


.. _MTHex-PXI-Controller-Reboot-Restart-Control-System:

Restart Control System
----------------------

.. warning::
    As the primary troubleshooting step to regain control, perform the restart of the control system if 
    the CSC/EUI is entirely unresponsive and unable to establish a connection with the control system.

    #.  Before proceeding, make sure there are no active interlocks in the EUI and that no other EUI instance 
        is running. For the MTCamHexapod, check if :guilabel:`runCamHexEui` is running by following commands in the terminal -

        .. prompt:: 

            ps -aux | grep runCamHexEui

        If processes are already running, you may need to identify who is running them and ask permission 
        to end one (or both) so you can run your own EUI session. If another :guilabel:`runCamHexEui` is running -

        .. prompt:: 

            sudo kill -9 {pid}

        
        Replace :guilabel:`runCamHexEui` with :guilabel:`runM2HexEui` for the MTM2Hexapod
    
    
    #.  You can do the following to check the MTCamHexapod control system status in the terminal- 

        .. prompt::

            /etc/init.d/cameraHexapod status
        
        It will tell you whether the control system is running or not. To stop it, do -

         .. prompt::

            /etc/init.d/cameraHexapod stop

        To start it do -

         .. prompt::

            /etc/init.d/cameraHexapod start
       
        For MTM2Hexapod, replace in the command above ``cameraHexapod`` 
        with ``m2Hexapod``.


#.  **Establish an SSH connection to the MTHexapod PXI**: Using the credentials and hostnames found 
    in the *LSST 1Password MainTel Vault* create an ssh tunnel in the terminal. 
    
    For the MTCamHexapod, the command would look like-

    .. prompt::

        ssh admin@camhex-pxi-controller.cp.lsst.org

    For the MTM2Hexapod, the command would look like-

    .. prompt::

        ssh pbalucan@m2-hexapod-pxi.cp.lsst.org


#.  To **restart the control system** for the MTCamHexapod, run the command in the terminal- 

    .. prompt::

        /etc/init.d/cameraHexapod restart

    
#.  To **restart the control system** for the MTM2Hexapod, run the command in the terminal- 

    .. prompt::

        /etc/init.d/m2Hexapod restart

#.  **Allow 5-10 minutes for the system to initialize**: This period is necessary for the OS and control system 
    to set up the EtherCat and Copley drives before making a connection through the CSC/EUI.




.. _MTHex-PXI-Controller-Reboot-Soft-Reboot:

.. warning::

    Only proceed if EUI/CSC control is not connecting and 
    the :ref:`restart of the control system <MTRot-PXI-Controller-Reboot-Restart-Control-System>` procedure 
    proved unsuccesful to regain control.

Soft Reboot
-----------


#.  **Establish an SSH connection to the MTRotator PXI** using the credentials and hostnames found in 
    the *LSST 1Password MainTel Vault* (See :ref:`above <MTRot-PXI-Controller-Reboot-Restart-Control-System>`).

#.  **Execute the reboot command**: To initiate a soft reboot of the PXI, type in the terminal -

    .. prompt::

        sudo reboot now

#.  **Allow 5-10 minutes for the system to reboot**: This time is necessary for the OS and control system 
    to configure the EtherCat and Copley drives before attempting a connection through the CSC/EUI. 
    
    


.. _MTHex-PXI-Controller-Reboot-Hard-Reboot:

Hard Reboot
-----------

.. warning::

    **Only proceed with a hard reboot, if the EUI control connection remains unsucessful after 
    a** :ref:`soft reboot <MTRot-PXI-Controller-Reboot-Soft-Reboot>`.

    This method involves cutting power to the PXI and drives and should only be used as a last resort 
    due to the potential risks.

    If a power shutdown is scheduled, you can proceed until step 2 before the power on.


#.  **Login into Utilities cabinet *Power Distribution Unit* (*PDU*) or MTM2Hexapod *netbooter* **:
    Depending on the which subsytem you are rebooting, you need to follow either A or B
    
    A.  For MTCamHexapod, while in the LSST-WAP or summit VPN, 
        connect to https://tea-pdu01.cp.lsst.org/ using the credentials stored in the *Operators vault* 
        of *LSST 1Password* as *PDU Utilities Cabinet*. Click on :guilabel:`Outlets` on the left hand 
        side menu to open the outlets screen. The description of each outlet can be found here.

    .. figure:: /Simonyi/Non-Standard-Operations/_static/mtrot-controller-pxi-reboot-1.jpeg
   
    B.  For MTM2Hexapod the netbooter is required to power cycle the PXI and drives: Connect to the 
    M2 Hex Netbooter *m2-hexapod-netbooter.cp.lsst.org* using the credential stored in the *1Password MainTel 
    Vault* under *M2 Hexapod PXI/Drive NetBooter*.

#.  **Power Cycle PXI and drives**: To **power** :guilabel:`Off` the system, first power off the PXI, followed by 
    the drive. 
    
    A.  For MTCamHexapod, PXI is energized through outlet 8, while the drives correspond to outlet 4 in the *PDU*.

    B.  For M2Hexapod, power off PXI first , then the drive from the *M2 Hexapod PXI/Drive NetBooter*.

    .. note::

        **Scheduled Power Off**

        In case a scheduled power off is intended, do not continue with power on, and stop the 
        procedure here.


    When **powering** :guilabel:`On`, activate the drives first, and wait for at least 3 minutes before powering 
    on the PXI. This delay is **crucial** for the Ethercat application within the PXI to establish a 
    connection with the Copley drive.


#.   **Wait for an additional 5-10 minutes after powering on before using the CSC/EUI**: This allows time for the OS and control system to configure the necessary drives. 


#.  **Reset GIS interlocks** that were triggered during the power cycle.


.. _MTHex-PXI-Controller-Reboot-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

-   The PXI controller and its associated drives are correctly rebooted, allowing for successful connection 
    and operation through the CSC/EUI.

-   The EtherCat and Copley drives are properly set up and functional.

.. .. _Title-of-Troubleshooting-Procedure-Contingency:

.. Contingency
.. ===========

.. If the procedure was not successful, report the issue in [relevant Slack channel] and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
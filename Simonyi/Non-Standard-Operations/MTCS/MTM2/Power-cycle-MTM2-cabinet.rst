.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Jacqueline Seron*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Te-Wei Tsai*
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _M2-Non-standard-Procedures-Power-cycle-MTM2-cabinet:
.. include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. TO DO: check references work after merge 

#########################
Power Cycle MTM2 cabinet
#########################



.. _MTM2-Power-Cycle-Cabinet-Overview:

Overview
========

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This procedure is the final option for resolving an MTM2 issue during the night. 
It's utilized when the M2 GUI consistently displays alarms, and the MTM2 cannot transition to a *closed-loop* status following the steps outlined in the :ref:`M2 recovery <M2-Troubleshooting-M2-recovery>` procedure.

This document mirrors the `Power-Cycle section under M2 handling errors`_, 
albeit presented in the format of Observatory Operations Documentation.

.. _`Power-Cycle section under M2 handling errors`: https://ts-m2gui.lsst.io/error-handling/error-handling.html#power-cycle



.. _MTM2-Power-Cycle-Cabinet-Precondition:

Precondition
============

.. This section should provide simple overview of preconditions before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

.. note::
    Ensure you have access to 1Password and are a member of the **Operators vault**. If not, request access for the 1password Vault Operators via an `IT Jira ticket`_.

.. _`IT Jira ticket`: https://rubinobs.atlassian.net/jira/

- **Consult** with the hardware or system engineers to obtain approval before proceeding with this procedure.

- Ensure you are **connected to the control room network** as VPN cannot reach it.

- You should only do this procedure if:

  - Following :ref:`M2 recovery <M2-Troubleshooting-M2-recovery>` procedure **doesn't fix the issue**, this means re-starting the control system fails to clear alarms and you are unable to set MTM2 to *closed-loop*.

  - You **cannot ping or ssh the M2 controller** *m2-crio-controller01.cp.lsst.org* (on TMA) *m2-crio-controller02.cp.lsst.org* (on level 3).

  - You see **errors codes** 6051 and 6088, or 6051 and 6052, and in some cases error 6056.

- **Know the location of the MTM2 cabinet** according its installation, which is either in TMA or on level 3.

.. _MTM2-Power-Cycle-Cabinet-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- MTM2 GUI displays no alarms, and it can transition to a *closed-loop* status.


.. _MTM2-Power-Cycle-Cabinet-Procedure-Steps:

Procedure Steps
===============

Depending on the location of MTM2 the corresponding steps are:

.. _MTM2-Power-Cycle-Cabinet-If-MTM2-is-on-the-TMA:

If MTM2 is on the TMA
-----------------------
.. /MainTel/MainTel-Non-standard-Operations/MTCS-Non-standard-Procedures/M2-Non-standard-Procedures/_static/pdu-m2.png

#. Access *https://tea-pdu01.cp.lsst.org/*, the internet interface of the general power distribution (PDU).

     .. figure:: ../_static/pdu-m2.png
       :width: 700px

       General Power Distribution outlets 

#. Use the credentials for **PDU Utilities Cabinet** found in the 1Password **Operators Vault**.

#. Select :guilabel:`Outlets` in the left panel of the window.

#. Select and power :guilabel:`Off` M2 Cabinet.

#. Wait 30 seconds.

#. Turn the power :guilabel:`On` the M2 Cabinet.

.. _MTM2-Power-Cycle-Cabinet-If-MTM2-is-on-level-3:

If MTM2 is on level 3
----------------------

#. Go to level 3.

#. Locate the power inverter

#. Turn off the switch

#. Wait 30 seconds.

#. Turn the switch back on.

     .. figure:: ../_static/MTM2-power-inverter-switch.png
        :width: 700px

        MTM2 power inverter at level 3 

.. _MTM2-Power-Cycle-Cabinet-Final-steps:

Final steps:
----------------------

Connect the MTM2 control system to MTM2 CSC. Bare in mind that before requesting a connection you must wait for 5 minutes. 

.. _MTM2-Power-Cycle-Cabinet-Troubleshooting: 

Troubleshooting
===============

You can verify if the control system is running and waiting for the TCS/IP connection, by referring to the :ref:`Get information block <M2-recovery-log-info>` in the :ref:`M2 recovery <M2-Troubleshooting-M2-recovery>` page.

In the event that connecting fails try :ref:`re-starting the M2 EUI. <EUI-Access-Accessing-M2-Camera-Hexapods-and-Camera-Rotator-EUIs>` 


Note about TCP/IP connection:
------------------------------
If, even after performing a power-cycle, you're still unable to ping the controller, you must contact IT support.



.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace::  *Franco Colleoni, Jacqueline Seron*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *List-of-contributors*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _ATCS-Verify-AuxTel-Telescope-and-Dome-Drives-Interlocks:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

############################################
Verify Telescope and Dome Drives Interlocks
############################################



.. _AuxTel-Telescope-and-Dome-Drive-Interlocks-Overview:

Overview
========

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This procedure outlines the steps to verify if the AuxTel telescope 
and dome drives have a **triggered interlock** due to the gate being open, 
the gate being in error, an E-STOP action, or a general failure.


.. _AuxTel-Telescope-and-Dome-Drives-Interlocks-Precondition:

Precondition
============

- You are uncertain of the state of the telescope and dome drives.


.. _AuxTel-Telescope-and-Dome-Drives-Interlocks-Post-Condition:

Post-Condition
==============

- You’ve identified any triggered interlocks for the AuxTel telescope and dome drives.
- You can now take corrective actions to restore the system.


.. _AuxTel-Telescope-and-Dome-Drives-Interlocks-Procedure-Steps:

Procedure Steps
===============


* Check the **Pilz controller** inside the AuxTel Main Cabinet

* According to the **lights**, if they are:
    * *Off*, an interlock is triggered.
    * *Illuminated*, the system is functioning correctly.



.. figure:: ./_static/pilz-controller-status.png
      :width: 500px
      
      Pilz controller status at the AuxTel Main Cabinet




.. _AuxTel-Telescope-and-Dome-Drives-Interlocks-Troubleshooting:

Troubleshooting
===============

If an interlock has been triggered, follow one of the procedures below based on the cause:


* Gate open, gate in error: :ref:`Safety Gate procedures <Safety-Systems-Safety-Gate-Procedures>`.

* E-STOP activated: :ref:`E-stop procedure <AuxTel-Non-Standard-Procedures-E-Stop-Procedure>`.

* General failure: :ref:`Recovery after a Shutdown <AuxTel-Non-Standard-Operations-AuxTel-Recovery-after-Shutdown>`.

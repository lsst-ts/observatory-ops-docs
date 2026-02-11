.. _Simonyi-Components-EUI-Access-Index:

.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *OS Team*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Kris Mortensen*
.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Simonyi-Components-Simonyi-EUI-Access:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.


######################################
MT M2/Rotator/Hexapods/Dome EUI Access
######################################

.. _Simonyi-Components-EUI-Access-Overview:

Overview
========

.. This section should provide a brief, top-level description of the document's purpose and utilization. 

This document explain how to access the **M2**, **Camera Rotator**, **Camera / M2 Hexapod**, and **Dome EUI**.

Prerequisites
=============

To access the EUIs, the user must have the following credentials:

- Added to the hexrot and saluser IPA groups.
-  Access to the ``hexrot‑vm01.cp.lsst.org`` virtual machine.

To request access, please file a Jira ticket in the `IT Helpdesk Support page <https://rubinobs.atlassian.net/jira/>`_ project.

.. _MT-M2/Rotator/Hexapods/Dome-EUI-Access-Setup:

Setup to access the MT-M2/Rotator/Hexapods/Dome EUI
---------------------------------------------------

#. **Safety check** – Verify no one else is using the subsystem’s EUI. Be mindful that another session may be open, and mouse motions or commands will come from another user. Consult the relevant Slack channels:

   * M2 – ``#m2‑worklog``
   * Hexapods & Rotators – ``#hexrot‑worklog``
   * MT Dome – ``#mtdome‑worklog``

#. **Announce** your intention to issue commands in the appropriate channel.

#. **Clear browser cache** for ``ls.st`` to avoid loading stale links. If this is your first connection, use the URL that points to ``hexrot‑vm01.cp.lsst.org``. The link will get you to the ``vcenter.cp.lsst.org``. After typing your IPA credentials, you can log in to the virtual machine. From the control room linux machine use ``ssh -Y`` and run the command to access the EUIs.



.. _MT-M2/Rotator/Hexapods/Dome-EUI-Access-Connection:

Connecting to the MT-M2/Rotator/Hexapods/Dome-EUI
-------------------------------------------------

There are two different methods to access the EUIs for the M2, Camera Rotator, Camera/M2 Hexapods, or Dome EUIs:

1.  If you are on a Linux workstation at the summit, you can directly access the EUIs with :command:`ssh` commands.
2.  If you are using a non-Linux workstation (e.g., a personal laptop or the LSBF workstation), you will need to 
    access the EUIs using the virtual machine.

.. admonition:: Summit Access is Required!
   :class: important

   To access the EUIs you will need to be connected to the summit WiFi directly or using VPN access.

.. _MT-M2/Rotator/Hexapods/Dome-EUI-Access-Connection-ssh:

Linux Workstation Access (on Summit)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#.  Open a terminal on the Linux Workstation and log into ``hexrot‑vm01.cp.lsst.org`` using your IPA credentials.

    .. code:: shell

      ssh [IPAUsername]@hexrot-vm01.cp.lsst.org

      ### Follow instructions and enter your password. ###
   
#.  You will have successfully logged in once you see the command line display something similar to the following:
    ``(py313) -bash-5.1$``.

#.  Once logged in, proceed to **Step (2)** of the :ref:`MT-M2/Rotator/Hexapods/Dome-EUI-Access-Launch` procedure.


.. _MT-M2/Rotator/Hexapods/Dome-EUI-Access-Connection-VM:

Virtual Machine Access
~~~~~~~~~~~~~~~~~~~~~~

#. **Log in** to the virtual machine (**http://ls.st/hexrot-vm01**) using your IPA credentials.

    * If you can see a password input window for another person, click the button on the bottom-right.

    .. figure:: _static/login_MT_M2_Rotator_Hexapods_Dome_EUI.png    
    
    * Find your name and select your IPA login credentials on the list. Click “Not listed” if there is not your name on the list. And then enter your username without ``@lsst.org``

    .. figure:: _static/login_MT_M2_Rotator_Hexapods_Dome_EUI_not_listed.png  
    
    * Then enter your IPA password. 


#. Open a terminal. Click **Activities** → **Terminal** (icon in the centre of the bottom menu).
    
    .. figure:: _static/login_MT_M2_Rotator_Hexapods_Dome_EUI_Activities.png  
    
    .. figure:: _static/login_MT_M2_Rotator_Hexapods_Dome_EUI_terminal.png


.. _MT-M2/Rotator/Hexapods/Dome-EUI-Access-Launch:

Launching the EUI
-----------------

1. Run the appropriate EUI command. All GUIs reside under ``/rubin``:

   .. code-block:: bash

      # M2 GUI
      /rubin/mtm2/python

      # Rotator GUI
      /rubin/rotator/python

      # Hexapod GUI
      /rubin/hexapod/python

      # MT Dome GUI
      /rubin/dome/python

Once you have opened the appropriate EUI Python shell program, the command line should look similar to the following layout: ``(py311) [(username)@hexrot-vm01 ~]$.``


2. Use one of the following terminal commands to access the appropriate EUI:

   * **M2 EUI** – ``run_m2gui``
   * **Camera Rotator EUI** – ``run_rotgui``
   * **Camera Hexapod EUI** – ``run_hexgui 1``
   * **M2 Hexapod EUI** – ``run_hexgui 2``
   * **MT Dome EUI** – ``run_mtdomegui``


Command‑line help
~~~~~~~~~~~~~~~~~

.. code-block:: bash

   $ run_rotgui -h     # display help for Rotator GUI
   $ run_hexgui -h     # display help for Hexapod GUI


Simulation Mode
~~~~~~~~~~~~~~~

If you wish to practice without affecting the live system, launch any EUI with the ``-s`` flag.

.. code-block:: bash

   $ run_rotgui -s     # start Rotator EUI in simulation mode


Handling another user’s active session
-------------------------------------

If a process is already running, identify its owner and request permission before terminating it.

.. code-block:: bash

   # Check if M2 EUI is running
   $ ps -aux | grep run_m2gui

   # Check if Camera Rotator EUI is running
   $ ps -aux | grep run_rotgui

   # Check if Camera Hexapod EUI is running
   $ ps -aux | grep run_hexgui

   # Check if Dome EUI is running
   $ ps -aux | grep run_mtdomegui

   # To forcibly close a session (use with care!)
   $ sudo kill -9 <PID>

``<PID>`` is the process ID returned by the ``ps`` command. If an active session is running, running another will result in an EUI that will close in about 30 seconds or not connect.


Closing the EUI
---------------

After finishing, select **Exit** from the menu and close the session.  
Then click **Lock** (top‑right) to end your session.

   .. figure:: _static/closing_EUI_a.png  
   .. figure:: _static/closing_EUI_b.png  
   .. figure:: _static/closing_EUI_c.png   



This procedure was last modified on |today|.
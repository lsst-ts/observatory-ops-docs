#################
M1M3 EUI Access Tutorial
#################

.. |author| replace:: *Yijung Kang*
.. |contributors| replace:: *none*

.. _M1M3-EUI-Access-Tutorial:

Overview
========

This tutorial provides detailed steps to access the M1M3 EUI (Engineering User Interface). This is intended for operators and users who need to interact with the M1M3 system.

.. _M1M3-EUI-Access-Tutorial-Precondition:

Precondition
============

Before starting this tutorial, ensure the following conditions are met:

- You have an account on the M1M3 system.
    - The `observer` account is only accessible through the Linux machine in the Summit Control Room.
- You have terminal access with SSH capabilities.

.. _M1M3-EUI-Access-Tutorial-Post-Condition:

Post-Condition
==============

After completing this tutorial, the following conditions will be met:

- You will be connected to the `M1M3 GUI`
- The `M1M3TS GUI` and `VMS GUI` will be also accessible for you.

.. _M1M3-EUI-Access-Tutorial-Tutorial-Steps:

Tutorial Steps
==============

Follow these steps to access the M1M3 EUI:

#. Connect to the M1M3 machine using the observer account or your user account if necessary. Note that the observer account is only accessible through the Linux machine in the Summit Control Room (connected to three big monitors).

   .. important::
      Use the following SSH command to connect:
      
      .. code-block:: shell

         ssh -X observer@m1m3-dev.cp.lsst.org
         
         or
         
         ssh -X (username)@m1m3-dev.cp.lsst.org

#. Verify that OSPL is running by using the following command:

   .. code-block:: shell

      ospl status

   If OSPL is not running, start it with:

   .. code-block:: shell

      ospl start

#. Launch the GUIs or EUIs for M1M3 by typing the following commands in the terminal:

   - To launch the M1M3 GUI:
   
     .. code-block:: shell

        M1M3GUI

   - To launch the M1M3TS GUI:
   
     .. code-block:: shell

        M1M3TSGUI

   - To launch the VMS GUI:
   
     .. code-block:: shell

        VMSGUI

#################
TMA VNC Connection Tutorial
#################

.. |author| replace:: *David Sanmartim*
.. |contributors| replace:: *Caros Morales*

.. _TMA-VNC-Connection-Tutorial:

Overview
========

This tutorial provides detailed steps to connect to the TMA (Telescope Mount Assembly) using VNC (Virtual Network Computing). This is intended for operators who need to access the TMA EUI (Engineering User Interface) remotely.

.. _TMA-VNC-Connection-Tutorial-Precondition:

Precondition
============

Before starting this tutorial, ensure the following conditions are met:

- You have 1Password installed and configured with access to the required credentials.
- VNC Viewer is installed on your machine.
- You have terminal access with SSH capabilities.

.. _TMA-VNC-Connection-Tutorial-Post-Condition:

Post-Condition
==============

After completing this tutorial, the following conditions will be met:

- You will be connected to the TMA EUI via VNC.

.. _TMA-VNC-Connection-Tutorial-Tutorial-Steps:

Tutorial Steps
==============

Follow these steps to establish a VNC connection to the TMA:

#. Open **1Password** and navigate to **Operators > TMA-VNC** to retrieve the necessary credentials.

#. Open a **Terminal** and make an SSH connection to the server with the following command:

   .. code-block:: shell

      ssh -L 5901:localhost:5901 -N lsst@tma-controller01.cp.lsst.org

#. Open **VNC Viewer** and select **Control TMA**.

   .. figure:: _static/vnc-viewer.png
      :alt: VNC Viewer Control TMA
      :align: center

      VNC Viewer devices list

#. If the **VNC Server** is NOT in the list, create a new connection to `127.0.0.1:5901`.

   .. figure:: _static/vnc-settings.png
      :alt: VNC Viewer New Connection
      :align: center

      VNC Viewer New Connection

#. In the **Options** tab, you can select **view-only mode** if needed.

#. To open the TMA EUI, double-click the `tma_eui` application.

   .. figure:: _static/TMA-desktop.png
      :alt: TMA EUI Application
      :align: center

      TMA EUI Application

#. After opening the TMA EUI, you may see it like this:

   .. figure:: _static/TMA-EUI.png
      :alt: TMA EUI Interface
      :align: center

      TMA EUI Interface

.. _TMA-VNC-Connection-Tutorial-Troubleshooting:

Troubleshooting
===============

If you encounter any issues during the tutorial, consider the following troubleshooting steps:

- Ensure that your SSH command is correct and that you have the necessary permissions.
- Verify that the VNC Viewer application is correctly installed and configured.
- If the VNC connection fails, check your network connectivity and firewall settings.
- For issues with the TMA EUI, ensure that the `tma_eui` application is correctly installed and accessible.
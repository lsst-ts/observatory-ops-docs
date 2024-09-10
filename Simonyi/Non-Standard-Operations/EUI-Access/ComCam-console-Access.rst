#################
ComCam Console Access
#################

.. |author| replace:: *Yijung Kang*
.. |contributors| replace:: *none*

.. _ComCam-Console-Access:

Overview
========

This tutorial provides detailed steps to access the ComCam Console. This is intended for operators and users who need to interact with the ComCam.

.. _ComCam-Console-Access-Precondition:

Precondition
============

Before starting this tutorial, ensure the following conditions are met:

- You have an account on the ComCam system.
- You have terminal access with SSH capabilities.

.. _ComCam-Console-Access-Post-Condition:

Post-Condition
==============

After completing this tutorial, the following conditions will be met:

- You will be connected to the `ComCam Console`

.. _ComCam-Console-Access-Tutorial-Steps:

Tutorial Steps
==============

Follow these steps to access the ComCam Console:

#. Connect to ComCam machine using the observer account or your user account if necessary. 

   .. important::
      Use the following SSH command to connect:
      
      .. code-block:: shell

         ssh -XY observer@comcam-mcm.cp.lsst.org
         
         or
         
         ssh -XY (username)@comcam-mcm.cp.lsst.org

#. Open the ccs-console.

.. prompt:: bash

 ccs-console
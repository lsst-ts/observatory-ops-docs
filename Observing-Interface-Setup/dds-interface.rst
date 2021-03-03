#############
Debugging DDS
#############

Overview
^^^^^^^^
This topic describes procedures for debugging the status of the `DDS interface <https://ts-sal.lsst.io>`_ that powers the :doc:`CSCs <obs-controls:System-Architecture/CSC-Overview/index>` that run on the summit.

Checking the status of the Daemon
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
1. Check that the daemon is running:
   
   .. prompt:: bash

        ospl status
        Vortex OpenSplice System with domain name "ospl_sp_ddsi" has died

2. Start the daemon
   
   .. prompt:: bash
        
        ospl start


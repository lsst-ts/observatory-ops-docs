#############
Debugging DDS
#############

Overview
^^^^^^^^
This topic describes procedures for debugging the status of the `DDS interface <https://ts-sal.lsst.io>`_ that powers the :doc:`CSCs <obs-controls:System-Architecture/CSC-Overview/index>` that run on the summit.
There are 3 use-cases for DDS Daemons defined by their location and application.

#. Node specific daemons which are mostly used for production environments
#. Local daemons for local CSCs or services which are mostly used for non-production environments (i.e. development)
#. Nublado daemons which are mainly used as a way to manually ensure system stability for night time operations.

Prerequisites
^^^^^^^^^^^^^

* Inside of a node where the DDS Daemon is running

Responsibilities
^^^^^^^^^^^^^^^^
Software Engineer

Procedure
^^^^^^^^^

Checking the status of the Daemon
---------------------------------
In the case that a CSC has trouble starting due to DDS failures.
Check the status of the ospl daemon using the following procedure.

#. Setup the appropriate environment variables, as is shown in `Setup and Start DDS Daemon`_.

#. Check that the daemon is running:
   
   .. prompt:: bash

        ospl status
        Vortex OpenSplice System with domain name "ospl_sp_ddsi" has died

#. Start the daemon
   
   .. prompt:: bash
        
        ospl start


Verification
^^^^^^^^^^^^
* ospl daemon status is nominal when running ``ospl status``

Troubleshooting
^^^^^^^^^^^^^^^

In the case of a production node, the tmp directory which houses the daemon files can be wiped out.
In the case of a non-production node, bad conditions can cause the daemon to crash
In the case of a nublado node, these daemons can be forcibly shut down due to updates on the service end.


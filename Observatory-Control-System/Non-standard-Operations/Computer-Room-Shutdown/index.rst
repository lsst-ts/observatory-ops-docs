.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Computer-Room-Shutdown-Recovery:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###################################
Computer Room Shutdown and Recovery
###################################

The process of shutting down servers and network devices in the computer room will adhere to the following two scenarios:

* **Critical Situation with Extended ETA:**

If the computer room is in a critical state with no immediate solution or an estimated time for resolution that exceeds a reasonable wait time (typically a couple of hours), a decision will be made to power off all servers.

* **Critical Situation with Proximate ETA:**

In instances where the computer room is in a critical state but a solution is imminent, only a select group of servers, identified as "safe to power off," will undergo shutdown procedures. This procedure aims to balance the need for thermal management with the continuity of essential services during server shutdowns. 


Computer Shutdown Tiers
==========================

The following is the list of computers in each tier. 

Tier 1: Computers that can be powered off during an emergency in the computer room by IT/Devops, without the authorization or help from system owners. 

Tier 2: Computer that will be powered off in the computer room by IT/Devops, alerting the system owners but without taking down the control system

Tier 3: Computers that will be powered off in the computer room by IT/Devops, that will take down the control system but not the communications to the summit.

Tier 4: Complete power off of the computer room. 

Tier 1
------

The following is the list of safe to power-off servers. The computers can be powered off without noticing or alerting the system owner.

**IT**

*snapshot and shutdown VMs first*
- vsphere[2-3].cp.lsst.org - *hvaccp* and *dccp1* VMs migrate to vsphere01.cp.lsst.org  . Maintenance mode first then shut down from https://vcenter.cp.lsst.org/ui
- lukay[1-5].cp.lsst.org
- perfsonar01.cp.lsst.org

**Control**
- love01.cp.lsst.org -- development machine

**Comcam:**

- comcam-dc01
- comcam-daq-mgt
- comcam-archiver

**Lsstcam:**

- Any lsstcam machines part of diagnostic cluster.   lsstcam-dc01.cp.lsst.org  - 10

* Auxtel

auxtel-dc01.cp.lsst.org - can always be shut down first, it is only used for image visualization

*If we are not actively taking data e.g. during the daytime, during the weekend, or during a week when the AuxTel is NOT operating on sky:*

auxtel-archiver.cp.lsst.org - can always be shut down if we are not taking data, will lose ability to ingest data in Butler if taking data

auxtel-daq-mgt.cp.lsst.org - can always be shut down if we are not taking data, will lose connection/monitoring of the WREB a


Tier 2
------
The following is the list computers will be powered off alerting the system owners, but not taking down the control system

**Control System**

- azar[02-03].cp.lsst.org

Use foreman - remote job on machines(s)  with ipmtool chassis power off || shutdown -h now 

Tier 3
------
The following is the list computers will be powered off alerting the system owner, taking down the control system but not the communications to the summit

**IT**


- core[2 instances].cp.lsst.org (not dns of foreman hypervisor)
- elqui[01-18].cp.lsst.org
- ipsec switches
- leafs of each rack (except A1)
- ipmi of each rack (expect A1)
- all vms except hvac monitoring (hvaccp) and domain controller (dccp) 

**Control System**

- yagan[01-20].cp.lsst.org
- azar01.cp.lsst.org
- chonchon[01-03].cp.lsst.org
- nfs1.cp.lsst.org
- tma-controller01 (open tekniker and phase cabinet doors)
- hexrot-vm01 (shut off topend machines)
- m1m3-dev (already disconnected from hardware)
- comcam-mcm
- comcam-db01
- auxtel-mcm
- auxtel-db01
- fp01 (only if warmup cameras)
- daq mgt (only if warmup cameras)
- daq ATCA crates (only if warmup cameras)


Tier 4
------
The following is the list computers will be powered off that will take down the communications to the summit. 

**IT:**

- vsphere1.cp.lsst.org
- core[remaining].cp.lsst.org (includes foremand and dns)
- yepun[01-05].cp.lsst.org
- nvr01.cp.lsst.org
- network devices (spines, agg, leafs, wlc, cucm, etc) 
- dwdm 

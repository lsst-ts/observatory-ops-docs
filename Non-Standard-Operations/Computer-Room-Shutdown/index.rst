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


Safe to Power Off Servers
==========================

The purpose of this list is to identify servers that will be powered off by IT/Devops without the authorization or help from system owners. 

The following is the list of safe to power-off servers. 

* IT:

vsphere[2-3].cp.lsst.org - Previous movement of VMs to vsphere01.cp.lsst.org

lukay[1-5].cp.lsst.org

perfsonar01.cp.lsst.org

* Comcam:

comcam-dc01

comcam-daq-mgt

comcam-archiver

* Lsstcam:

Any lsstcam machines part of diagnostic cluster.

* Auxtel

auxtel-dc01.cp.lsst.org - can always be shut down first, it is only used for image visualization

*If we are not actively taking data e.g. during the daytime, during the weekend, or during a week when the AuxTel is NOT operating on sky:*

auxtel-archiver.cp.lsst.org - can always be shut down if we are not taking data, will lose ability to ingest data in Butler if taking data

auxtel-daq-mgt.cp.lsst.org - can always be shut down if we are not taking data, will lose connection/monitoring of the WREB a
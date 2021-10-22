.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Daytime-Nighttime-Interactions-daytime-and-nighttime-communication:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###################################
Daytime and Nighttime Communication
###################################

.. This section should provide a brief, top-level description of the page.

Daytime staff and observers scheduled for a night shift need to ensure that the telescope, instrument(s), and observatory tools are functioning as expected before the beginning of any night to minimize time loss due to unexpected faults. 

.. _daytime-and-nighttime-communication-Observers-Arrival:

Observers Arrival
=================

Observers scheduled for the night must arrange to arrive to the telescope control room before the daytime crew depart the summit for La Serena. It is recommended to arrive and begin the afternoon checkout at 16:00 local time so issues can be reported before the beginning of the night. 

These sections describe afternoon checkout and fault reporting:

  * :ref:`daytime-and-nighttime-communication-Afternoon-checkout`
  * :ref:`daytime-and-nighttime-communication-Reporting-a-fault`

Staff that work on the summit depart for La Serena at 16:30 Monday-Friday. Mario Rivera and Patrick Ingraham currently coordinate much of the work done for AuxTel. If Mario is not available, Ian Ordenes or Claudio Araya can report if daytime work such as mirror cleaning, filter changes, structural work or janitorial work is scheduled in order to confirm telescope motion is safe during the daytime.  

.. _daytime-and-nighttime-communication-Night-Logs:

Night Logs
==========

Details of work done during the day, such as software changes or mechanical work such as filter changes, mirror cleaning, and maintenance are published to the `Night Logs <https://confluence.lsstcorp.org/display/LSSTCOM/Night+Logs>`__ before the start of the night. Daytime staff publish the details before the end of day at the summit - 16:30 summit time.

More information about creating and writing night logs is found on the :ref:`Daytime-Nighttime-Interactions-nighttime-logging` page.

.. _daytime-and-nighttime-communication-Afternoon-Checkout:

Afternoon Checkout
==================

Afternoon checkouts are important procedures to ensure that the telescopes and instruments are functional before the beginning of the night. The full procedures for the different afternoon or recommended daily checkouts are described on these pages:

* AuxTel daily checkout
* LATISS calibrations
    * `LATISS master calibrations generation procedure <https://obs-ops.lsst.io/Operational-Procedures/Auxiliary-Telescope/LATISS-Master-Calibrations-Procedure/latiss-master-calibrations-procedure.html>`__
* Comcam calibrations
    * `Comcam master bias generation procedure <https://obs-ops.lsst.io/Operational-Procedures/Main-Telescope/ComCam-Master-Calibrations-Procedure/comcam-master-calibrations-procedure.html>`__
 
.. _daytime-and-nighttime-communication-Reporting-a-fault:

Reporting a fault
=================

The JIRA project called Observing Operations (OBS) for all night time or telescope faults is specifically to raise issues that impair data being taken on sky. In case there is a telescope or instrument issue found during the day or during the afternoon checkout, the daystaff or observer must file a `fault report <https://jira.lsstcorp.org/projects/OBS/issues/OBS-4?filter=allopenissues>`__ and flag it to recive priority attention before the night begins. Observers are also encouraged to communicate directly with summit staff or Tucson support to address an issue quickly, but must file a fault report describing the issue and the recovery procedure. 

.. _daytime-and-nighttime-communication-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by Alysha Shugart.

.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).


.. raw:: html

    <style> .red {color:red} </style>
.. role:: red


.. raw:: html

    <style> .gold {color:gold} </style>
.. role:: gold

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Karla Aubel
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: Kshitija Kelkar, *safety team*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTCS-Non-staandard-Procedures-LOTO-procedure:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.



######################
Simonyi LOTO Procedure
######################

.. _Simonyi-LOTO-procedure-Overview:

Overview
========

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This document describes how to prevent any telescope movement as a safety measure through **Lock-Out-Tag-Out** (**LOTO**) 
procedure. To perform this procedure, LOTO training must have been received. Observers during operations may be 
expected to LOTO the **Telescope Main Assembly** (**TMA**) due to unforeseen work done at night. The TMA LOTO is done directly 
in the **Oil Supply System** (**OSS**).



.. _Simonyi-LOTO-procedure-Precondition:

Precondition
============

.. This section should provide simple overview of preconditions before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

.. warning::

    To perform this procedure formal LOTO training must have been received; refer also to 
    the `TMA LOTO Procedure video. <https://drive.google.com/file/d/1rOvu1ITDCm0HNepfvoBWMzhGZkMPkKnH/view>`_ 

.. _Simonyi-LOTO-procedure-Procedure-Steps:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.


Applying LOTO on OSS
--------------------

.. note::

    **LOTO box**
    
    Keys and locks are inside the LOTO Box. You can find LOTO box (with a tag "Electronic team" on the box) on 
    Level 1 in the OSS room. If you cannot find or open that LOTO box, you can take a LOTO box from the meeting room 
    on Level 2.

    .. image:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-7.png
     :width: 30%
    .. image:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-8.jpeg
     :width: 30%
     
     




#.  **Announcement**: Before/right after applying LOTO on the OSS, announce "LOTO on the OSS" on  *#summit-announce* and/or *#summit-simonyi*.

#.  **Turning off the OSS**: Turn :guilabel:`OFF` the OSS in the EUI panel (indicated by the :gold:`circle` in the following Figure)

    .. figure:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-1.png
     :name: tma-loto-1
     
     Figure 1: The :guilabel:`OSS GENERAL VIEW` in the TMA EUI can be accessed by entering the :guilabel:`MONITOR & CONTROL` > :guilabel:`MAIN AXES` tab in the left vertical menu panel of the EUI. 

#.  **Wait until the OSS is off**:  the :guilabel:`status` turns `Idle` and :guilabel:`OSS` flag goes from green to gray. 
    It takes around 5-10 minutes to complete turning off the OSS. 

    .. figure:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-2.png
     :name: tma-loto-2
     
     Figure 2: The OSS :guilabel:`status` indicator (Zoom view of the top left sdection of the :guilabel:`OSS GENERAL VIEW` shown in Figure 1)     



#.  **Applying LOTO on the OSS Pump**: Go to the OSS room from Level 1 (first floor). Apply LOTOs on the OSS pump switches (highlighted by the :red:`box` in
    the following Figure). Close valves (Position "—-") and put locks on the holes to apply three LOTOs on the safety 
    switches of the OSS pumps.

    .. figure:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-3.png
     :name: tma-loto-3
     
     Figure 3: Location of the OSS Pump Switches on Level 1     
    .. image:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-4.png
     :width: 30%
    .. image:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-5.png
     :width: 30%
    .. image:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-6.png
     :width: 30%

    Figure 4: OSS Pump Valves in closed position and locked.  

Unlocking LOTO on OSS
---------------------

#.  Go to the the OSS room and remove the locks from the pump switches. Find the key for each lock from the LOTO box 
    and match the number on the key and the lock. 

#.  Put the LOTO locks with the keys back into the LOTO box.

#.  Open the switches (Position "|") on the pump (See the Figure 5 below).

    .. figure:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-9.png
     :name: tma-loto-9
     
     Figure 5

#.  Turn on the OSS from TMA EUI (**Optional**). 

#.  Announce the status of the OSS on  *#summit-announce* and/or *#summit-simonyi*.

.. note::

    **LOTO at night**

    During night-time operations, only **ONE** pump needs to be locked 
    to consider the TMA fully under LOTO. This helps to move the process faster by taking into consideration the 
    reduced on-summit personnel (~ 2 persons operation at night) and mitigating situations like when one cannot find the LOTO boxes, risk of losing 
    multiple locks + keys, leaving lights on longer etc.




.. _Simonyi-LOTO-procedure-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

#.  **After applying LOTO on OSS** 
    Telescope is unable to move. OSS is under LOTO shows :guilabel:`status` as `Idle` and the three pumps in :red:`red`, down to the left in the image.

    .. figure:: /Simonyi/Non-Standard-Operations/MTCS/TMA/_static/tma-loto-10.png
     :name: tma-loto-10  
     
     Figure 6: The :guilabel:`OSS GENERAL VIEW` when OSS is under LOTO

#.  **After unlocking LOTO on OSS** 

    -   OSS idle but not turned on (:red:`Need Figure`)

    -   OSS turned on after removing LOTO  (:red:`Need Figure`)

.. _Simonyi-LOTO-procedure-Contingency:

Contingency
===========

Announce the status of locking and unlocking the LOTO in *#summit-simonyi* and/or *#summit-announce* and/or activate 
the `Out of hours support <https://obs-ops.lsst.io/Safety/out-of-hours-support.html#safety-out-of-hours-support>`_.

This procedure was last modified |today|.

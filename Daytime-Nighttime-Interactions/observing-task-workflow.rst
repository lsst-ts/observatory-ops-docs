.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Erik Dennihy*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. _Daytime-Nighttime-Interactions-block-observing-workflow:

###############################
Observing Task Request Workflow
###############################

This page describes the overall workflow for how Observing Task requests can be submitted, executed, and completed. 
It is intended to be a reference for how the various JIRA workflows (SITCOM, BLOCK, SUMMIT) can all be used together to create an effective workflow for efficiently collecting and analyzing data collected at the Rubin Observatory.
Here we define an "observing task" as any test or task that requires data to be collected at the summit using any of the observing facilities outside of normal survey operations. 
This could include e.g. an engineering request or scientific dataset needed to verify a requirement or functionality. 
Observing tasks can be designed to take place during the daytime (e.g. calibrations or closed-dome movements) or during the night. 

How to submit a new Observing Task Request
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Proposers for new Observing Tasks should start by submitting a SITCOM ticket describing the motivation for the task, its constraints, and specific data required.
If the task is part of a larger campaign, it is appropriate to provide links to a Confluence page or other external reference describing the motivation. 

Strategic Planning Committee
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The newly proposed task should be brought to the Strategic Planning Committee for consideration. 
The Strategic Planning Committee is responsible for determining if the task merits execution and what priority it should be assigned for the upcoming observing test cycles. 
The Strategic Planning Committee is also responsbile for assigning the task to a member of the Science Comissioning team for execution. 

Role of the SITCOM JIRA ticket
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The SITCOM JIRA ticket should serve as both the task proposal and central location for all efforts related to the data collection and analysis. 
This could include:
    - a linked BLOCK ticket describing the observing task data collection
    - links to any additional pre-requisite or follow-up work such as a DM ticket to adjust parameters
    - links to task analysis results such as plots, parameters determined, notebooks, or technotes
The SITCOM JIRA ticket should be assigned to the task proposer or person responsible for confirming when the task has been completed. 

Role of the BLOCK JIRA ticket
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The BLOCK JIRA project contains the tickets which describe the actions or instructions needed to collect the requested data. 
These description of a BLOCK ticket should include one of the following: 
    - a set of scripts to be run via the script queue and their corresponding configurations
    - a notebook to be run from the summit (should be added to the ticket as an attachment)
    - a Scheduler-driven survey to be executed with the appropriate scheduler configuration
    - a BLOCK-ID to be executed as an observation block via the scheduler

In general, the BLOCK tickets are expected to be assigned to and followed-up by a member of the Commissioning Science team. 
They should include all of the necessary instructions to run the test through completion, including and pre-requisites or limiting conditions.
The BLOCK tickets themselves will then be included in the Plan of the Night to be executed by a member of the observing team. 
A single observing task defined by a SITCOM JIRA ticket may be broken up into many different BLOCKs to ease execution. 

Role of the SUMMIT JIRA ticket
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Some observing task requests (particularly those that include daytime data collection) require careful planning and coordination with summit activities. 
In these cases, a SUMMIT JIRA ticket should be made and linked to the SITCOM JIRA ticket so that the task can be added to the SUMMIT JIRA calendar. 

Why do we need multiple tickets to represent a single request?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The main reasons are the difference in timescales for between data collection and data analysis,  
and the need for clear, concise instructions for data collection on the summit. 
Data collection and data analysis can often (though should not always) proceed in parallel, benefitting from separate workflows. 
In addition, efficient execution of data collection on the summit requires modular scheduling of short tasks with concise instructions.  

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

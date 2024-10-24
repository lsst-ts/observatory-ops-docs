.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Communications-index:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.


##############################
Communications
##############################

.. This section should provide a brief, top-level description of the page.

.. 
    note::
        This is a template file that is associated with a template directory structure. This note should be deleted when the section is properly populated

This page provides descriptions of the different communications tools used by observers and daytime staff. 
Telescope handoff procedures, night logs, and fault reporting procedures are listed below. 

Slack Communications
====================

.. grid:: 2

    .. grid-item-card:: Slack Channel Usage 
        :link: slack-channel-usage
        :link-type: doc

        Contains the acceptable usage of the specific set of channels 
        that are focused on day and nighttime summit operations. 
    
    .. grid-item-card:: Uso de los canales de Slack (Version Español)
        :link: slack-channel-usage-spa
        :link-type: doc

        Detalla el uso previsto de los canales de comunicación específicos 
        para las operaciones diurnas y nocturnas en la montaña.
    

Daytime and nighttime communications
====================================

.. grid:: 2

    .. grid-item-card:: Daytime and Nighttime communication 
        :link: daytime-and-nighttime-communication
        :link-type: doc

        Summary of the communication processes between daytime and nighttime staff
        (Doc in process of update)
    

Fault reporting
===============

.. grid:: 2

    .. grid-item-card:: Fault Reporting
        :link: fault-reporting
        :link-type: doc

        How to file a fault report for any incident that happens during nighttime 
        operations in OBS Jira project.

    .. grid-item-card:: Fault Handling Workflow 
        :link: fault-handling-workflow
        :link-type: doc

        Description of OBS Jira project and how a created ticket 
        moves through OBS project workflow through to completion. 
    

Logging
=======
.. grid:: 2

    .. grid-item-card:: Nighttime Logging 
        :link: nighttime-logging
        :link-type: doc

        Section under construction. 
    

.. toctree::
   :glob:
   :titlesonly:
   :hidden:
   :maxdepth: 2
   
    *

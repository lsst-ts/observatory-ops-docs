.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Gonzalo Aravena*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Alysha Shugart*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Safe-entry-to-AuxTel:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

####################
Safe Entry to AuxTel
####################

.. _Safe-entry-to-AuxTel-Overview:

Overview
========

This document aims to provide the necessary guidelines and procedures for safely entering AuxTel. 
It covers aspects related to access during nighttime operations, ventilation, calibrations, and daytime access. 
Ensure you follow these instructions to guarantee your safety and the safety of the equipment.


Safety Equipment for All Entries
================================

Each entry to the telescope, regardless of the reason, must mandatorily use the following safety equipment:

- Helmet

- Reflective vest

- Safety shoes

.. figure:: ./_static/Notice.png
    :name: notice
    :scale: 25 %

    Safety Equipment

.. admonition:: Important
   
   If you do not have any of these safety items, please contact the safety staff at the summit. 

.. _Safe-entry-to-AuxTel-access-during-daytime:


Access During Daytime
=====================

1. **Communication Protocols**
   
   - Announce your visit to the telescope indicating the reasons briefly via the Slack channels `#summit-auxtel <https://lsstc.slack.com/archives/C01K4M6R4AH>`__ and `#summit-announce <https://app.slack.com/client/T06D204F2/C01P41NUR1R>`__.

   - Communicate by radio on channel 3 when entering the telescope during the day and night. This action is suggested.


2. **Conditional access**

   - Ensure that no images are being taken and no work is being done in the AuxTel dome that might be disrupted upon entering the telescope.


3. **Entry door key**

   - The key to access the main entrance door to the telescope will be hanging on the right side of the door just below the fire extinguisher sign. It is strictly requested that the keys must be always left in the same place when leaving the telescope.


   .. figure:: ./_static/keys.png
       :name: keys
       :scale: 25 %

       Key hook



   .. note:: 
       Exceptionally, the entrance door will currently be left unlocked.

  

.. _Safe-entry-to-AuxTel-access-during-ventilation:

Access During Ventilation
=========================

.. note:: 

   Review the weather conditions and :ref:`weather constraints <Observing-Constraints-AuxTel-Weather-Constraints>` before taking the decision to vent.


1. **Ventilation Notification**

   - Ventilation starts with a notification via Slack channels and/or radio channel 3.



2. **Safety Precautions**

   - Ensure the windows are fully open and the fan operates at 20%.

   - Take special care not to lean on the windows or manipulate the fan while it is running.

   - On the telescope's second floor, verify that the telescope is in a horizontal position and the dome is facing opposite the Sun to maximize the ventilation system.

.. figure:: ./_static/vent.png
    :name: Venting

    Air extraction fan.



.. _Safe-entry-to-AuxTel-access-during-calibrations:

Access During Calibrations
==========================

.. warning::

    Access is **NOT** permitted during calibrations unless there is an issue with the system that requires attention, and images can be interrupted or are not currently being taken. 
    Ensure there are no announcements in Slack, and confirm with summit staff (daytime shift workers or an Observing Specialist) that no images are in progress.



.. _Safe-entry-to-AuxTel-access-during-night-time-operations:

Access During Night time Operations
===================================

1. **Entry Permissions**

   - Only authorized personnel and the Observing Specialist team can enter without an external permit during operations.


2. **Lighting Restrictions**
   
   .. warning:: 

    During operations, it is prohibited to turn on building lights when entering the telescope.


   .. caution:: 
        
    The use of flashlights or headlamp is permitted but they should point towards the ground and should be minimized to avoid interfering with observations.


   .. tip:: 

    Red light flashlights can be a good choice and they interfere much less than regular white light.


.. _Safe-entry-to-AuxTel-behaviour-standards:

Behavior Standards
==================

Maintain proper behavior at all times, including:

- Being close to a radio (or always carrying one) and communicating your intentions to summit staff and on Slack.
  
- Following the :ref:`Safety Gate Procedure <Safety-Gate-Procedures-Overview>` and the :ref:`E-Stop procedure <AuxTel-Non-Standard-Procedures-E-Stop-Procedure>` as needed.
  
- Locking out movement when necessary following :ref:`LOTO procedure <Auxiliary-Telescope-AuxTel-LOTO-procedure>`.


.. _Safe-entry-to-AuxTel-Emergency-Procedures:

Emergency Procedures
====================

In case of any emergency, notify immediately via **radio channel 3 for Rubin staff, or channel 1 for after hours emergencies.**
For detailed instructions on specific types of emergencies, please refer to the :ref:`Emergency Response Guide <Safety-emergency-response-guide>`.
Remember to always keep the list of :ref:`Emergency Numbers <summit-contact-numbers-emergency-numbers>` handy for any urgent situations.


This procedure was last modified on |today|.

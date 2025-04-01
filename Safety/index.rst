.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Safety-Safety:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. _`English`: https://docs.google.com/presentation/d/1KMbyblTWzQjOn5Wm8BY_Ip62QuFoldGg/edit?usp=sharing&ouid=116721464699564151672&rtpof=true&sd=true
.. _`Spanish`: https://docs.google.com/presentation/d/14Q2C2-avt_DoPdipJ3c9qV4TFEoNjiaN/edit?usp=sharing&ouid=116721464699564151672&rtpof=true&sd=true


##############################################
Quick Safety Reference for Nighttime Personnel
##############################################


This page provides quick-reference procedures for the safety of personnel and equipment. 

This does not replace the required safety orientation for summit personnel.

For a full overview of emergency procedures, review the presentation in `English`_ (starting on slide 19) or in `Spanish`_, (starting on slide 19).

Emergency Response Guide
========================

.. grid:: 3     

   .. grid-item-card:: Medical Emergency
      :link: emergency-response-guide-medical-emergency
      :link-type: ref

   .. grid-item-card::  Inclement Weather
      :link: emergency-response-guide-inclement-weather
      :link-type: ref

   .. grid-item-card:: Earthquake
      :link: emergency-response-guide-earthquake
      :link-type: ref

.. grid:: 3

   .. grid-item-card:: Fire
      :link: emergency-response-guide-fire
      :link-type: ref


   .. grid-item-card:: Chemical Spill
      :link: emergency-response-guide-spill
      :link-type: ref

   .. grid-item-card:: Electric Shock
      :link: emergency-response-guide-electric-shock
      :link-type: ref


Summit Contact Numbers 
======================

These extensions can be dialed from any telephone in the Rubin Control room or on the Rubin summit. 

.. grid:: 4    

   .. grid-item-card:: Emergency Numbers
      :link: summit-contact-numbers-emergency-numbers
      :link-type: ref

   .. grid-item-card:: Summit Control Room 
      :link: summit-contact-numbers-control-room-numbers
      :link-type: ref

   .. grid-item-card:: Rubin Casino, SOAR & Gemini Control Rooms 
      :link: summit-contact-numbers-non-emergency-numbers
      :link-type: ref

   .. grid-item-card:: Calling Hotel Pachon
      :link: summit-contact-numbers-calling-hotel-pachon
      :link-type: ref


Out of Hours Support
====================

.. grid:: 3   

   .. grid-item-card:: Out of Hours Call List
      :link: out-of-hours-support
      :link-type: doc
      :padding: 4

   .. grid-item-card:: Resources for Help
      :link: out-of-hours-support-resources-for-help
      :link-type: ref

   .. grid-item-card:: Calling Instructions
      :link: out-of-hours-support-calling-instructions
      :link-type: ref


Safety Systems (GIS, LOTO, E-stop)
==================================

.. grid:: 2

   .. grid-item-card:: Control Safety Systems
      :link: Safety-Systems/Control-Safety-Systems
      :link-type: doc
      :padding: 4

      Description of GIS, LOTO and E-stop safety systems. 


   .. grid-item-card:: GIS
      :link: Safety-Systems/GIS
      :link-type: doc
      :padding: 4

      GIS introduction



Safety Gates
------------
.. grid:: 2

   .. grid-item-card:: Safety Gates
      :link: /Safety/Safety-Systems/Safety-Gate-Introduction
      :link-type: doc
      :padding: 4

      Safety Gates introduction

   .. grid-item-card:: Safety Gates Operations
      :link: /Safety/Safety-Systems/Safety-Gate-Procedures
      :link-type: doc
      :padding: 4

      How to open/close and activate/deactivate safety bypass. 

AuxTel
------
.. grid:: 2

   .. grid-item-card:: AuxTel LOTO
      :link: /AuxTel/Non-Standard-Operations/ATCS/AuxTel-LOTO-procedure
      :link-type: doc
      :padding: 4

      How to put AuxTel under LOTO. 

   .. grid-item-card:: AuxTel E-stop
      :link: /AuxTel/Non-Standard-Operations/ATCS/E-Stop-Procedure
      :link-type: doc
      :padding: 4

      Where to find E-stop switches and how to engage/disengage the E-stop system. 

Simonyi
-------
.. grid:: 2

   .. grid-item-card:: Simonyi OSS LOTO
      :link: /Simonyi/Non-Standard-Operations/MTCS/TMA/Simonyi-LOTO-procedure
      :link-type: doc
      :padding: 4

      How to put Simonyi under OSS LOTO. 

   .. grid-item-card:: Simonyi E-stop
      :link: Simonyi-E-Stop-Procedure
      :link-type: doc
      :padding: 4

      Under construction 

Enter Observatory Spaces
=========================

.. grid:: 1

   .. grid-item-card:: Safe entry to AuxTel
      :link: Enter-Observatory-Spaces/Enter-AuxTel-Telescope
      :link-type: doc
      :padding: 4

      Procedures to enter AuxTel during daytime, ventilation, calibration and night time operations. 



.. Here's is the left hand-side navigation. 

.. toctree::
    :maxdepth: 4
    :titlesonly:
    :hidden:

    emergency-response-guide.rst
    summit-contact-numbers.rst
    out-of-hours-support.rst
    Safety-Systems/index.rst
    Enter-Observatory-Spaces/index.rst





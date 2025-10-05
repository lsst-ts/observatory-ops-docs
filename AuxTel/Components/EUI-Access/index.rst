.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Kshitija Kelkar*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Kristopher Mortensen*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-Components-AuxTel-EUI-Access:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. role::  raw-html(raw)
    :format: html

####################
AuxTel EUI Access
####################

.. _AuxTel-EUI-Access-Overview:

Overview
========

.. This section should provide a brief, top-level description of the document's purpose and utilization. 

This document explains how to access all the components of *AuxTel EUI*-- for ATMCS, ATSPectrograph and ATDome-- through a remote desktop.

AuxTel EUI Access
========================
 
.. _Auxtel-EUI-Access-Setup:

Setup to access the AuxTel EUI remote desktop 
---------------------------------------------

#. Install and open **Microsoft Remote Desktop**.

#. Click :guilabel:`+` button on the top menu.

#. Select "Gateway" from drop-down menu.

#. Click the drop-down menu "Gateway" :raw-html:`&rarr;` "No gateway"

.. figure:: /AuxTel/Components/_static/AddAGateway.png
  :name: "Add a Gateway" pop-up window.
  :width: 500

  "Add a Gateway" pop-up window.

#. Put *aux-brick01.cp.lsst.org* on the "PC name" :raw-html:`&rarr;` "Save"

.. figure:: /AuxTel/Components/_static/Adding_AuxTel_EUI.png
  :name: "PC name" field.
  :width: 500

  "PC name" field.

.. note::
    You need to configure this setup only once. 

.. _Auxtel-EUI-Access-Connection:

Connecting to the EUI Remote desktop
------------------------------------

#. Login with Username/PW of **ATMCS/ATSpectrograph/ATDome EUI access** on 1Password **AuxTel** Vault.


#. The following tabs can now be accessible from the web-browser:

    * *LSST Auxiliary Telescope MCS & Pneumatics: http://139.229.170.47:8000/atmcs.html*
    
    .. figure:: /AuxTel/Components/_static/EUI-ATMCS.png

    * *ACE Spectrograph: http://139.229.170.44:8000/Spectrograph.html*  

    .. figure:: /AuxTel/Components/_static/EUI-ATSpec.png    

    * *Main Box Dome Control: http://139.229.170.190:8001/*   

    .. figure:: /AuxTel/Components/_static/EUI-ATDome.png    
    
    * *Top Box Dome Control: http://139.229.170.190:8000/*
    
    .. figure:: /AuxTel/Components/_static/EUI-Top-Control-Box.png

This procedure was last modified on |today|.
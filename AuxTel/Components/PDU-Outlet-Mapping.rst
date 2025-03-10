.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Manuel Gomez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Paulo Lago*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Templates-Informative-Document:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.
.. _AuxTel-Components-PDU-Outlet-Mapping:
##################
PDU Outlet Mapping
##################

.. _PDU Outlet Mapping-Overview:

Overview
========

This document provides an updated mapping of all the PDUs in the Auxiliary Telescope (AuxTel) as of September 3rd, 2024.

.. _PDU Outlet Mapping-Main-Information-Section:

1st Floor
=========
AT Control Cabinet
------------------

.. list-table:: AT Control Cabinet
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Main Power Supply
   * - 2
     - Powerbar + Hexapod
..
`Link to AT Control Cabinet PDU <http://aux-pdu-tcs.cp.lsst.org>`_

AT Camera Electronics and Sensor Readout Cabinet - Top PDU (1)
--------------------------------------------------------------
.. list-table:: AT Camera Electronics and Sensor Readout Cabinet - Top PDU (1)
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Empty
   * - 2
     - Network Switch
   * - 3
     - Cryocon Temperature Controller
   * - 4
     - HAMEG #2
   * - 5
     - Keithley Back Bias
   * - 6
     - Cabinet Light and Fan
   * - 7
     - Empty
   * - 8
     - USB Power
   * - 9
     - HAMEG #1
   * - 10
     - HAMEG #3
   * - 11
     - Empty
   * - 12
     - Empty
..
`Link to AT Camera Electronics and Sensor Readout Cabinet - Top PDU (1) <http://pdu1-aux.cp.lsst.org>`_

AT Camera Electronics and Sensor Readout Cabinet - Bottom PDU (2)
-----------------------------------------------------------------
.. list-table:: AT Camera Electronics and Sensor Readout Cabinet - Bottom PDU (2)
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Empty
   * - 2
     - Network Switch
   * - 3
     - ATS HCU Power Supply
   * - 4
     - Empty
   * - 5
     - Empty
   * - 6
     - Empty
   * - 7
     - Empty
   * - 8
     - To Telescope - Ion Pump
   * - 9
     - To Telescope
   * - 10
     - Empty
   * - 11
     - Empty
   * - 12
     - Pfeiffer Vacuum Gauge
..
`Link to AT Camera Electronics and Sensor Readout Cabinet - Bottom PDU (2) <http://pdu2-aux.cp.lsst.org>`_

Spectrograph Power Switch Cabinet
---------------------------------
.. list-table:: Spectrograph Power Switch Cabinet
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Empty
   * - 2
     - Power and cRIO
..
`Link to Spectrograph Power Switch Cabinet PDU <http://aux-pdu-spectrograph.cp.lsst.org>`_

Dome Main Control Box
---------------------
.. list-table:: Dome Main Control Box
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Power and cRIO
   * - 2
     - Empty
..
`Link to Dome Main Control Box PDU <http://aux-pdu-dome.cp.lsst.org>`_

2st Floor
=========

Illumination System
-------------------
.. list-table:: Illumination System
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - 24V Power Supply (which feeds the Illumination System Computer and Temperature Controller)
   * - 2
     - Fan
   * - 3
     - 12V Power Supply + Monochromator Windows Computer
   * - 4
     - 5V Power Supply
   * - 5
     - Electrometer
   * - 6
     - Fiber Spectrograph
   * - 7
     - KiloArc (White Light Source)
   * - 8
     - Chiller
..
`Link to Illumination System PDU <http://auxtel-illpdu.cp.lsst.org/>`_

LATISS PDU (in Nasmyth Rotator)
-------------------------------
.. list-table:: LATISS PDU (in Nasmyth Rotator)
   :header-rows: 1

   * - Outlet
     - Device
   * - 1
     - Ion Pump Power Supply
   * - 2
     - Bonn Shutter
..
`Link to LATISS PDU (in Nasmyth Rotator) <http://aux-pdu-latiss.cp.lsst.org/>`_
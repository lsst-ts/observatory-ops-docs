 .. This file is an example of what a top-level WBS page could look like

.. _Auxiliary_Telescope:

#######################
Auxiliary Telescope
#######################

The Auxiliary Telescope is a 1.2 meter telescope located on an hill adjacent to the Simonyi Survey Telescope.
The telescope is used in conjunction with a slitless spectrograph called LATISS (LSST Auxiliary Telescope Imager and Slitless Spectrograph) to measure changes in the atmospheric transmission function during LSST observations.
Transmission variations are primarily due to water and aerosol (dust, smoke etc) contents changing due to wind and pressure variations at multiple layers in the atmosphere.

A high-level description of the Auxiliary Telescope system is found in the `Auxiliary Telescope Concept of Operations <https://docushare.lsst.org/docushare/dsweb/Get/LSE-379>`__.

This page provides an index of the major components with links to applicable documentation.
Effort has been dedicated to provide guidance to finding the most pertinent documentation, however further content may be available in Docushare.

.. contents::
   :depth: 1
   :local:


Building and Site
=================

The building is two stories with the telescope located on the 2nd story.
A grating is used for the 2nd floor to promote airflow from the open dome shutter, through the building and out through 4 vent-gates located on the first floor.

Architectural
-------------

The building and site preparation was done by Besalco as part of the main summit facility contract.
Below are documents specifically related to the Auxiliary Telescope area.

The applicable architectural drawings for the building are as follows:

- Link to drawings

The applicable survey drawings for the mountain top may also be useful.

- Link to drawings

Electrical
----------

The Auxiliary Telescope summit is provided with the same 3-phase power with a generator backup as the main building(s).
However, inside the building, no 120V outlets are available.
A commercial UPS is used to provide backup power in case of an outage.

The building electrical drawings are:

- `Collection of Building Electrical Drawings <https://docushare.lsst.org/docushare/dsweb/View/Collection-6442>`__

Ancillary Equipment
-------------------
Located on Calibration hill is also the allsky camera(s), weather tower, the DIMM, and a modified container for storage.

Environmental Monitoring
^^^^^^^^^^^^^^^^^^^^^^^^

- `DIMM Tower <https://docushare.lsst.org/docushare/dsweb/View/Collection-5505>`__

- Weather Station links

Telescope Mount
===============

The telescope was previously installed on Kitt Peak as operated as the Calypso Telescope.
It was removed and underwent a large refurbishment effort by ACE Consultants.

A top-level `Technical Reference Manual <https://docushare.lsst.org/docushare/dsweb/Get/Document-30995>`__ describing the mechanical and electrical was delivered as part of this contract.

Mechanical
----------

All mechanical models for the telescope mount (and other AuxTel related equipment) are located in the PDM Vault

- The mechanical models were developed by ACE and delivered at FDR (In PDM vault:  4.8 Calib Sys/As designed/AUX TEL ACE 2018)

- Mirror Drawings (mechanical)

- `Critical ICDs <https://docushare.lsst.org/docushare/dsweb/View/Collection-6445>`__


Electrical
----------

- `AuxTel Mount Electrical Diagram <https://docushare.lsst.org/docushare/dsweb/Get/Document-26731>`__

Optical
-------

The contract with ACE included no optical modifications.

- Zemax Optical Prescription

Contractual
-----------

- `ACE contractual documents and review details <https://docushare.lsst.org/docushare/dsweb/View/Collection-4807>`__

Software
--------
The mount control software was written in LabVIEW by a team at CTIO.

- `Mount (Servo) Control Software Documentation <https://docushare.lsst.org/docushare/dsweb/View/Collection-9776>`__

- `ATMCS <https://ts-atmcs.lsst.io>`__ and `ATPneumatics <https://ts-atpneumatics.lsst.io>`__ CSC Documentation

Maintenance
-----------

- Mirror Installation Procedure(s)

- Motor and Encoder Procedures

Dome
====

The AuxTel uses a 30-foot diameter Ash Dome, which has had modifications to increase the weather durability by Benjamin Leyton.
The motors were also replaced with three-phase versions, combined with upgrading to use a ACE SmartDome system (running on a cRIO).

- `SmartDome Electrical and Software Manuals <https://docushare.lsst.org/docushare/dsweb/View/Collection-6331>`__

Mechanical
----------

No 3d CAD model came with the dome, however an approximate representation can be found in the PDM vault (4.8 Calib Sys/Calib Tel Dome)

Maintenance
-----------

- `Semi-Annual Dome Maintenance from Ash <https://docushare.lsst.org/docushare/dsweb/Get/Document-32543>`__


LATISS
======




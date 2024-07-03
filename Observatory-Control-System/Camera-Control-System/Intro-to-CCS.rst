.. This is a template for an informative/general use document.

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Name-of-Primary-Author*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *List-of-contributors*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Camera-Control-System-Introduction-to-CCS:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########################################
Camera Control System - Introduction to CCS
###########################################

This document gives an overview of the Camera Control System (CCS), particularly targeted to users on the summit in Chile, including Operations Specialists.
CCS is used by AuxTel, ComCam and LSSTCam.
In general this document applies to all 3 cameras, except where specifically noted.

.. Out of scope for this document
.. Developer specific information, try to keep things aimed at general users of CCS. Links to more expert material is OK
.. How to build/release new CCS software

.. _Introduction-to-CCS-Overview:

Who should read this document?
==============================

When a camera (be it AuxTel, ComCam or LSSTCam) is working normally it operates under control of the Observatory Control System (OCS) and knowledge of the CCS is not normally needed.
You will need to use CCS under the following circumstances.

* You are working to get the camera ready for normal operation.
* The camera has gone into a FAULT state, and you need to understand what caused the fault and rectify it.
  Although the introductory material here will be useful you may also want to see `Recovering-from-a-FAULT-Condition`_
* You want to monitor details of the camera operation, or understand its operation in more detail than displayed by LOVE.
* You want to perform an operation which requires using CCS directly, such as taking camera EO data with fp scripts.

Overview of CCS functionality
=============================

CCS is a distributed system....

How to login to CCS machines at the summit
==========================================

Logging in from the Summit Control Room
---------------------------------------

Logging in from the Base Control Room
-------------------------------------

Logging in from Remote Control Rooms
------------------------------------

SLAC
^^^^

Tucson
^^^^^^

Logging in from other locations
-------------------------------


What machines exist
-------------------

AuxTel
^^^^^^

ComCam
^^^^^^

LSSTCam
^^^^^^^

What are CCS subsystems?
------------------------

Which subsystems exist at the summit
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Interacting with CCS
====================

There are a number of tools which allow you to interact with CCS.

* ccs-console
   A graphical tool for interacting with CCS subsystems. This is the easiest tool to use, especially if you are logged in to one of the machines in the control room.

* ccs-shell
   A command line tool for interacting with CCS subsystems. Generally ccs-shell is the best tool to use when

   #. You are already familiar with the basic commands supported by CCS.
   #. You are accessing a machine remotely (for example using ssh) and the overhead of starting a ccs-console would be too large.
   #. You are following procedures outlined elsewhere in this document which call for issuing specific commands.

* ccs-script
   A tool which allows CCS to be controlled using simple python scripts. This tool is usually only used by experts for special purposes.

* ccs trending
   CCS trending allows you to view time histories of quantities monitored by CCS. There are actually several ways to access the CCS trending data.

   #. Using the CCSWebTrending web interface.
   #. Using the ccs-console.
   #. Using trender.py - a python interface to the ccs trending database.

* camera image visualization
   A tool for viewing camera images.

Each of these tools is described in more details below.

ccs-console
-----------
.. This is a placeholder, not very useful because most users will not have SLAC confluence accounts
.. We need to decide what to do about this.

See `The CCS Console User's Guide <https://confluence.slac.stanford.edu/x/tzYpC>`_.

ccs-shell
---------

ccs-script
----------

This is primarily a developers tool, and it probably beyond the scope of this document.

ccs trending
------------

camera image visualization
--------------------------

What are locks, and how to use them
-----------------------------------
What are the MCM and ocs-bridge
------------------------------
What states can they be in
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. This section should provide a brief, top-level description of the document's purpose and utilization.

.. _Introduction-to-CCS-Main-Information-Section:

Main Information Section
========================

.. todo::
   Include utilization of admonishments (caution, warning, etc.)

Present the information for this document.
Include links or further resources for additional follow-up.
Find additional examples of formatting on `this page <https://developer.lsst.io/v/DM-5063/docs/rst_styleguide.html>`__ or on the list of links of the `documentation style guide <https://obs-ops.lsst.io/project/contributing.html#contributing-doc-style-guide>`__.

.. warning::
    Keep this in mind when referring to this information.

.. _Introduction-to-CCS-Main-Information-Section-Subsection-One:

Subsection One
--------------

1. numbers

A. upper-case letters
   and it goes over many lines

   with two paragraphs and all!

a. lower-case letters

   3. with a sub-list starting at a different number
   4. make sure the numbers are in the correct sequence though!

I. upper-case roman numerals

i. lower-case roman numerals

(1) numbers again

1) and again

.. _Introduction-to-CCS-Main-Information-Section-Subsection-Two:

Subsection Two
--------------

This is an example of a subsection.

.. _Introduction-to-CCSmake clean-Main-Information-Section-Subsection-Two-Subsubsection:

Subsubsection
^^^^^^^^^^^^^

This is an example of a sub-subsection.

This procedure was last modified on |today|.
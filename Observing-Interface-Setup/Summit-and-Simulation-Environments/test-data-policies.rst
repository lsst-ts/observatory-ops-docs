.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Patrick Ingraham*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Observing-Interface-Test-data-policies:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##################
Test Data Policies
##################

Overview
^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

Each site will require data sets that must be located at each environment location (e.g. summit, TTS, BTS and USDF) that are used to run functionality tests.
The data must be managed to ensure disk space remains adequate, as well as organized to a particular test such that it can be easily maintained in the future.
Generally, there will be registers which relate tests to datasets, such that if tests are added/removed the data can be modified accordingly.
It is anticipated that these registers will eventually be of a computer readable format which directly feeds the data curation processing (e.g. a yaml file), but this has yet to be implemented.

This page explains the policies related to adding and/or removing test data sets.
In short, no permanent test data should be added or removed from the summit without first obtaining permission from one of the following people:

#. Michael Reuter
#. Tiago Ribeiro
#. Brian Stalder
#. Erik Dennihy


These people are tasked with ensuring the request is reasonable and the suggested execution and/or datasets are appropriate.
Any datasets/butler collections that have not been cleared by a member of this group and documented accordingly can be deleted at any time, although usually raw and derived data products will be kept for 30 days at the Summit.
Generally, disk space at the summit is the most precious, and will be subject to the most scrutiny. 
Data collections at USDF are very flexible and much more accommodating. 
The TTS and BTS have space limitations, but remain flexible in nature.


Test Data for Camera Playlists
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The camera playlists utilize raw fits files.
To date, these have been managed `primarily via confluence pages <https://confluence.lsstcorp.org/display/LSSTCOM/Site+Playlists>`_.
To date, only Michael Reuter has been the primary curator of these datasets.

Note that the new images created from running through the playlist are not protected and are subject to deletion when required (generally 30 days).


Test Data Curation in the Butler
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The process to add permanent test data to each environment is currently manual.

Brandon White (from FermiLab) is working on a mechanism that will use `Rucio <https://rucio.cern.ch/>`_ to manage the datasets that have been approved by the personnel above.
Until then, Steve Pietrowicz has offered to help add data following the same procedure that has been documented for :ref:`adding LATISS test collections <Tucson-Test_Stand-New-LATISS-data>`.

Current Collections
-------------------

The list of collections are to be hosted external to this documentation and will evolve with time.
Until that list (and mechanism) can be linked from here, a list of the current collections and datasets are on a `dedicated confluence page <https://confluence.lsstcorp.org/display/LSSTCOM/Site+Specific+Test+Data+Collections>`_. 

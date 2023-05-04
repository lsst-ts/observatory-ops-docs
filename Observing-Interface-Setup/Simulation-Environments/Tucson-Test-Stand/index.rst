.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
    - If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Tucson-Test_Stand:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#######################
Tucson Test Stand (TTS)
#######################


This exists to provide details on various aspects of the TTS.
It will continue to be expanded as functionality and usage increases. 

############################
Data Repositories and Policy
############################

The TTS has the repositories for generated data setup in exactly the same manner as the summit.
When a frame is successfully simulated, a new file is created and ingested to the butler.
Generated frames follow a standard simulation environment data policy where all data older than 30 days can be deleted without notice. 

Also contained in the same repository are special collections of on-sky data that are used for the unit testing of scripts and/or software.
This data does not follow the 30-day retention policy and remains until it is no longer needed.

Adding New Data to the LATISS Repositories
------------------------------------------

This subsection exists to guide a user to adding LATISS test data to the TTS and the summit.
These datasets are used in integration testing and verification of systems after upgrades and/or before observing.
Due to space constraints, we try to minimize the amount of data residing on the summit, and therefore two separate collections are kept:

- ``LATISS-test-data-tts``: This contents of this collection resides at the TTS and the USDF, but not at the summit.
- ``LATISS-test-data``: The contents of this collection reside on the summit, at TTS, and also at USDF.

When wanting to use data in these collections, they must be declared when instantiating the butler
An example of this is as follows, which applies for use on the TTS:

   .. code-block:: python
      
      datapath='/repo/LATISS'
      butler = dafButler.Butler(datapath, instrument='LATISS', collections=['LATISS/raw/all','LATISS-test-data, LATISS-test-data-tts'])


Assuming the data are at USDF, the raw data files are accessed from ``rubin-devl`` machines, but you need to access it via the login node ``s3dflogin.slac.stanford.edu``.
Rather than tunnel, copying the data to a temporary directory in your home space is often easier.
Data after 2022-07-13 are stored in s3 buckets and not in a directory.
Prior raw data are organized by date in ``/sdf/group/rubin/lsstdata/offline/instrument/LATISS/storage/``.

There are multiple variations on how one could perform the data transfer and ingestion.
The following steps describe a highly manual example of how one could perform the task. 

#. Starting from a terminal, ssh into ``s3dflogin.slac.stanford.edu`` using your SLAC unix credentials.
   Then ssh into ``rubin-devl``

The following steps copy the desired data from ``/sdf/group/rubin/lsstdata/offline/instrument/LATISS/storage/`` to a temporary directory in your home area (e.g. ``~/tmp_data/LATISS-test-data-tts/YYYY-MM-DD``)

#. In a new terminal session, ssh into ``auxtel-archiver.tu.lsst.org`` for the TTS (``auxtel-archiver.cp.lsst.org`` for the summit) using your Rubin SSO credentials then change directories to where the data will be stored

   .. code-block:: bash
      
      cd /data/lsstdata/TTS/auxtel/oods/gen3butler/raw/LATISS-test-data-tts # TTS
      cd /data/lsstdata/base/auxtel/oods/gen3butler/raw/LATISS-test-data/ # Summit

   Note that writing files to this directory requires the proper privileges.
   One can also use the saluser account.

#. Use secure-copy to bring the data from USDF to the TTS.

   .. code-block:: bash

      scp -r <USDF_username>@s3dflogin.slac.stanford.edu:~/tmp_data/LATISS-test-data-tts/YYYY-MM-DD/*.fits .
   
   This will copy the data from USDF into the directory ``/data/lsstdata/TTS/auxtel/oods/gen3butler/raw/YYYY-MM-DD``


The next series of steps performs the ingestion of the data to the butler repository.
It also shows how to verify it was ingested properly.

#. Pull a recent T&S development (base) container which contains the DM stack to have the ability to use butler utilities.
   The difference between this and the SQuaRe provided container is the use of the saluser uid/gid.

   .. code-block:: bash

      docker pull lsstts/base-sqre:develop

#. Run the container, passing the data directory into the container, then setup the lsst_distrib tools:

   .. code-block:: bash

      docker run -ti --volume /home/saluser/.lsst:/home/saluser/.lsst --volume /data:/data --volume /repo:/repo lsstts/base-sqre:develop
      source /opt/lsst/software/stack/loadLSST.bash
      setup lsst_distrib

#. Ingest the data to the TTS butler repository (``/repo/LATISS``); (note that warning messages such as, "Dark time less than exposure time. 
   Setting dark time to the exposure time," may appear and should be evaluated whether or not they are appropriate. )

   .. code-block:: bash

      butler ingest-raws -t direct /repo/LATISS /data/lsstdata/TTS/auxtel/oods/gen3butler/raw/LATISS-test-data-tts/2022*

   .. note::

      Ingestion issues can occur, specifically if there were updates to the headers (via the astrometadata translator) done at the USDF.
      At the moment, there is no easy work around, but Patrick can assist.

#. Associate the files to a the ``LATISS-test-data-tts`` collection.
   For a small number of files this can be done manually very rapidly.

   .. code-block:: bash

      butler associate /repo/LATISS LATISS-test-data-tts -d raw --where "exposure.day_obs=20220316 AND instrument='LATISS'"

#. Check that the files are now part of the collection.

   .. code-block:: bash

      butler query-datasets /repo/LATISS --collections LATISS-test-data-tts

#. Can query all collections to verify that the LATISS-test-data-tts collection is visible 

   .. code-block:: bash
      
      butler query-collections /repo/LATISS


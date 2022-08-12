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


.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    */index


############################
Data Repositories and Policy
############################

The TTS has the repositories for generated data setup in exactly the same manner as the summit.
When a frame is successfully simulated, a new file is created and ingested to the butler.
Generated frames follow a standard simulation environment data policy where all data older than 30 days can be deleted without notice. 

Also contained in the same repository are special collections of on-sky data that are used for the unit testing of scripts and/or software.
This data does not follow the 30-day retention policy and remains until it is no longer needed.

Adding New Data to the LATISS Repository
----------------------------------------

The butler test data collection for LATISS is named ``LATISS-test-data-tts``.

The raw data files are accessed from ``lsst-login.ncsa.illinois.edu`` and organized by date in ``/lsstdata/offline/instrument/LATISS/storage/``.

There are multiple variations on how one could perform the data transfer and ingestion.
The following steps describe a highly manual example of how one could perform the task.

#. Starting from a terminal, ssh into lsst-login.ncsa.illinois.edu using your NCSA Kerberos credentials.

The following steps copy the desired data from ``/lsstdata/offline/instrument/LATISS/storage/`` to a local scratch directory (e.g. ``/scratch/srp/LATISS-test-data-tts/YYYY-MM-DD``)

#. In a new tab, ssh into auxtel-archiver.tu.lsst.org using your Rubin SSO credentials then change directories to where the data will be stored

   .. code-block:: bash
      
      cd /data/lsstdata/TTS/auxtel/oods/gen3butler/raw/LATISS-test-data-tts

   Note that writing files to this directory requires the proper privileges.
   One can also use the saluser account.

#. Use secure-copy to bring the data from NCSA to the TTS.

   .. code-block:: bash

      scp -r <NCSA_username>@lsst-login.ncsa.illinois.edu:/scratch/<NCSA_username>/LATISS-test-data-tts/* .
   
   This will copy the data from NCSA into the directory ``/data/lsstdata/TTS/auxtel/oods/gen3butler/raw/YYYY-MM-DD``

The next series of steps performs the ingestion of the data to the butler repository.
It also shows how to verify it was ingested properly.

#. Pull a recent T&S development (base) container which contains the DM stack to have the ability to use butler utilities.
   The difference between this and the SQuaRe provided container is the use of the saluser uid/gid.

   .. code-block:: bash

      docker pull lsstts/base-sqre:develop

#. Run the container, passing the data directory into the container, then setup the lsst_distrib tools:

   .. code-block:: bash

      docker run -ti --volume /data:/data --volume /repo:/repo lsstts/base-sqre:develop
      source /opt/lsst/software/stack/loadLSST.bash
      setup lsst_distrib

#. Ingest the data to the TTS butler repository (``/repo/LATISS``); (note that warning messages such as, "Dark time less than exposure time. 
   Setting dark time to the exposure time," may appear and should be evaluated whether or not they are appropriate.)

   .. code-block:: bash

      butler ingest-raws -t symlink /repo/LATISS /data/lsstdata/TTS/auxtel/oods/gen3butler/raw/LATISS-test-data-tts/2022*

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
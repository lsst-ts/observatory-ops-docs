.. |author| replace:: *Andrés A. Plazas Malagón*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _Latiss-Master-Calibrations-Procedure:

###############################################
Latiss Master Calibrations Generation Procedure
###############################################

.. _Latiss-Master-Calibrations-Procedure-Overview:

Overview
========

This procedure describes how to execute the SAL Script to produce master calibrations for LATISS on the ScriptQueue from the LSST Operations and Visualization Enviroment (LOVE) at the Summit :ref:`operational environment <Observing-Interface-Operational-Environments>`. 

The script will have the option to: 

- command LSSTComCam to take a number of calibrations frames:
   - biases
   - darks
   - flats
- call the corresponding Rubin Science Pipelines calibration generation pipetask to produce biases, darks, flats, defects and Photon Transfer Curves (PTCs) via the OCS-Controlled Pipeline System (OCPS),
- verify the images taken using as reference the calibration generated in the previous step (see the package `cp_verify`_ and `DMTN-101`_), or using pre-existing calibrations (via the `generate_calibrations` boolean parameter in the configuration file), and
- certify the resulting calibration with a given range of validity dates.

For at least one type of test (as defined in `DMTN-101`_), if the majority of tests fail in the majority of detectors and the majority of exposures, then the script will terminate by raising a **RuntimeError** after calculating the verification statistics, and the calibration will not be certified. The configuration parameters **number_verification_tests_threshold_bias**, **number_verification_tests_threshold_dark**, and **number_verification_tests_threshold_flat** will be used to define thresholds to decide whether the calibration will pass verification and should be certified or not. Currently, verification is only implemented for ``BIAS``, ``DARK``, and ``FLAT`` calibration types. If the configuration parameters **do_defects** and **do_ptc** are set to ``True``, verification will be skipped for the ``DEFECTS`` and ``PTC`` calibrations and they will be automatically certified.

The script currently has the option (via the **script_mode** parameter in the configuration options) to:

- take only biases, 
- take biases and darks, and 
- take biases, darks, and flats. 
  
These options are constrained by the fact that one calibration depends on the existence of the previous one (i.e., to build a dark, a bias is necessary, and to build a flat, a dark and a bias are necessary).

If desired, defects can be constructed from darks and flats, and a PTC per detector per amplifier constructed from the flats. Note that the PTC assumes that a sequence of flat pairs has been taken, each pair taken at the same exposure time. In both cases, **script_mode** must be set to ``BIAS_DARK_FLAT``.

For more information about calibrations production (including verification and certification), please consult the `Constructing Calibrations documentation`_.

.. _cp_verify: https://github.com/lsst/cp_verify
.. _DMTN-101: https://dmtn-101.lsst.io/
.. _Constructing Calibrations documentation: https://lsst.ncsa.illinois.edu/~czw/pipelines_lsst_io/_build/html/modules/lsst.cp.pipe/constructing-calibrations.html 

.. _Latiss-Master-Calibrations-Procedure-Prerequisites:


Prerequisites
=============

- You should be logged into the LSST Operations and Visualization Enviroment (LOVE) at the Summit :ref:`operational environment <Observing-Interface-Operational-Environments>`.
- The script assumes (and checks) that the ``LATISS`` and ``OCPS`` components are all ``ENABLED``, and that the latter has been ``ENABLED`` with the configuration of ``LATISS``.

The instrument and the ``OCPS`` can be enabled with the following procedures: 
    - :ref:`Enable LATISS Procedure <Enable-LATISS-Procedure>`
    - :ref:`Enable OCPS Auxiliary Telescope Procedure <Enable-OCPS-Auxiliary-Telescope-Procedure>`

If you plan to take flat fields as well, make sure the Auxiliary Telescope is prepared to do so:
    - :ref:`Prepare ATCS For Flat Fields Procedure <Prepare-ATCS-For-Flat-Fields-Procedure>`

.. _Latiss-Master-Calibrations-Procedure-Post-Conditions:

Post-Condition
==============

- A (daily) master calibration image per detector will be certified in a `butler`_ ``CALIBRATION`` `collection`_.

.. _butler: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/index.html
.. _collection: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/organizing.html

.. _Latiss-Master-Calibrations-Procedure-Steps:

Procedure Steps
===============

Once you are logged into LOVE, click on the ``ATQueue`` panel, as circled on the left side of the figure below (for reference, ``MTQueue`` to launch ``LSSTComCam`` scripts is circled on the right):

.. figure:: ./_static/love-mtqueue-atqueue-panel.png
    :name: ATQueue-love

     Screenshot of LOVE interface with the "ATQueue" pannel.


Load the Script
---------------

After clicking on the ``ATQueue`` panel, search for the script ``auxtel/make_latiss_calibrations.py`` under ``AVAILABLE SCRIPTS`` on the left, as shown in the figure below:

.. figure:: ./_static/love-available-scripts.png
    :name: available-scripts-love

      Screenshot of LOVE interface with the "AVAILABEL SCRIPTS" list.
      
Load the script by clicking on the button in front of the name of the script that has a triangle.

Enter configuration parameters
------------------------------

After loading the script, a window that contains two sections, ``SCHEMA`` (top) and ``CONFIG`` (bottom), will appear. The former will show the available configuration options (and the default values of some of them) that should be entered in the latter. The configuration options are as follows:

- **script_mode**: Currently, the script can be run  in three modes, in which  it  will  produce only biases (``BIAS``), biases and darks (``BIAS_DARK``), or biases, darks,
  and flats (``BIAS_DARK_FLAT``). Default: ``BIAS_DARK_FLAT``
- `n_bias`: number of bias frames to be taken. Default: 1 
- `n_dark`: number of dark frames to be taken. Default: 1
- `exp_times_dark`: The exposure time of each dark image (sec). If a single value, then the same exposure time is used for each exposure. Default: 0
- `n_flat`: number of flat frames to be taken. Default: 1
- `exp_times_flat`: The exposure time of each flat image (sec). If a single value, then the same exposure time is used for each exposure. Default: 0
- `detectors`: Detector IDs, e.g., ``(0,1,2,3,4,5,6,7,8)`` for all LATISS CCDs. Default: "(0,1,2,3,4,5,6,7,8)"
- `do_verify`: Should the master calibrations be verified? (c.f., ``cp_verify``). Default:  True
- `generate_calibrations`: Should the master calibrations be generated from the images taken and use them as reference for image verification? If `False` and and `do_verify = True`, pre-existing calibrations will be used as reference for verification, and they should be provided in the input collections for the verification pipetasks. Default: False
- `config_options_bias`: Options to be passed to the command-line bias pipetask. They will overwrite the values in ``cpBias.yaml``. Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False -c isr:overscan.fitType='MEDIAN_PER_ROW'"
- `config_options_dark`: Options to be passed to the command-line dark pipetask. They will overwrite the values in ``cpDark.yaml``. Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False"
- `config_options_flat`: Options to be passed to the command-line flat pipetask. They will overwrite the values in ``cpFlat.yaml``. Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False -c cpFlatMeasure:doVignette=False "
- `do_defects`: Should defects be built using darks and flats?. `script_mode` must be ``BIAS_DARK_FLAT``.Default: False
- `config_options_defects`: Options to be passed to the command-line defects pipetask. They will overwrite the values in ``findDefects.yaml``. Default: "-c isr:doDefect=False "
- `do_ptc`: Should a Photon Transfer Curve be constructed from the flats taken? ``script_mode`` must be ``BIAS_DARK_FLAT``. Default: False
- `config_options_ptc`: Options to be passed to the command-line PTC pipetask. They will overwrite the values in ``measurePhotonTransferCurve.yaml``. Default: "-c ptcSolve:ptcFitType=EXPAPPROXIMATION -c isr:doCrosstalk=False "
- `input_collections_bias`: List of additional (the ``OCPS`` already adds ``LATISS/raw/all`` as a default) comma-separated input collections for the bias pipetask. The pipetask is called via the ``OCPS`` after enabling it with the ``LATISS`` configuration. Default: "LATISS/calib".
- `input_collections_verify_bias`: Additional comma-separated input collections to pass to the verify (bias) pipetask. Default: "LATISS/calib".
- `input_collections_dark`: Additional comma-separarted input collections to pass to the dark pipetask. Default: "LATISS/calib"
- `input_collections_verify_dark`: Additional comma-separated input collections to pass to the verify (dark) pipetask. Default: "LATISS/calib"
- `input_collections_flat`: Additional comma-separated input collections to pass to the flat pipetask. Default: "LATISS/calib"
- `input_collections_verify_flat`: Additional comma-separated input collections to pass to the verify (flat) pipetask. Default: "LATISS/calib"
- `input_collections_defects`: Additional comma-separated input collections to pass to the defects pipetask. Default: "LATISS/calib"
- `input_collections_ptc`: Additional comma-separated input collections to pass to the Photon Transfer Curve pipetask. Default: "LATISS/calib"
- `calib_collection`: ``CALIBRATION`` collection where the calibrations will be certified into, for example, ``LATISS/calib/u/plazas/YYYYMMMDD.test``. Default: "LATISS/calib/daily".
- `repo`: Butler repository. Default: ``/repo/LATISS``.
- `n_processes`: Number of processes that the pipetasks will use. Default: 8
- `certify_calib_begin_date`: The beginning date for the validity range of the certified calibration. For example, ``2021-07-15``. Default: "1950-01-01"
- `certify_calib_end_date`: The end date for the validity range of the certified calibration. For example, ``2021-07-16``. Default: "2050-01-01"
- `oods_timeout`: Timeout value, in seconds, for the Observatory Operations Data Service (``OODS``). Default: 120

An example set of configuration parameters is as follows:

.. code-block:: text

    n_bias: 6
    n_dark: 6
    exp_times_dark: [5, 5, 5, 10, 15, 20]
    n_flat: 14
    exp_times_flat: [0.1, 0.1, 0.35, 0.35, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0, 1.35, 1.35, 1.6, 1.6]
    detectors: (0,1,2,3,4,5,6,7,8)
    calib_collection: "LATISS/calib/u/plazas/daily.2021SEP13.test1"
    do_verify: True
    input_collections_verify_bias: "u/czw/DM-28920/calib.20210720,LATISS/calib"
    input_collections_verify_dark: "u/czw/DM-28920/calib.20210720,LATISS/calib"
    input_collections_verify_flat: "u/czw/DM-28920/calib.20210720,LATISS/calib"
    certify_calib_begin_date: "2021-07-15"
    certify_calib_end_date: "2021-07-17"
    script_mode: BIAS_DARK_FLAT
    do_defects: True
    do_ptc: True

Launch the script
-----------------

When the configuration options have been entered and the script is ready to be launched, click on the ``ADD`` button in the lower right of the screen (refer to image above).

Accessing the calibrations
--------------------------

The certified master calibrations will be available via the collection specified by the **calib_collection** parameter. They could be retrieved from a notebook for manipulation and visualization: 

.. code-block:: python
    
    import lsst.daf.butler as dB

    butler = dB.Butler("/repo/LATISS", collections=["LATISS/calib/daily.2021SEP13.test1"])
    detector = (0, 1, 2, 3, 4, 5, 6, 7, 8)
    exposure = [bias1ID, bias2ID] # e.g., [2021071500001, 2021071500002]
    
    # For detector "0":
    bias = butler.get('bias', detector=detector[0], exposure=exposure[0], instrument='LATISS')
    dark = butler.get('dark', detector=detector[0], exposure=exposure[0], instrument='LATISS')
    flat = butler.get('flat', detector=detector[0], exposure=exposure[0], instrument='LATISS')
    defects = butler.get('defects', detector=detector[0], exposure=exposure[0], instrument='LATISS')
    ptc = butler.get('ptc', detector=detector[0], exposure=exposure[0], instrument='LATISS')


In addition, the statistics produced by the verification step can be analized by looking into the ``examples`` folder in ``cp_verify``.

Troubleshooting
===============

    After checking the configuration options and the ``LOVE`` error messages, the file ``/scratch/uws/${jobId}/outs/ocps.log`` will contain additional technical information on which pipetask failed, if any. ``{jobId}`` is returned by the OCPS and can be retrieved from the ``LOVE`` output messages.


.. _Latiss-Master-Calibrations-Procedure-Conditions-Contact-Personnel:

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

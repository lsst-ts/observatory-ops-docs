.. |author| replace:: *Andrés A. Plazas Malagón*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _ComCam-Combined-Calibrations-Procedure-ComCam-Combined-Calibrations-Generation-Procedure:

#################################################
ComCam Combined Calibrations Generation Procedure
#################################################

.. warning::
    ComCam-only procedure - Deprecated

.. _ComCam-Combined-Calibrations-Procedure-Overview:

Overview
========

This page assumes the reader is familiar with the content explained in the Daytime Calibrations section:

- :ref:`Introduction to the combined calibrations generation procedure <Introduction-Combined-Calibrations-Generation-index>`

.. _ComCam-Combined-Calibrations-Procedure-Post-Conditions:

Post-Condition
==============

- Individual calibration images will be taken and verified using the `cp_verify`_ framework.
- If ``generate_calibrations`` is ``True``, a (daily) combined calibration image per detector will be certified in a `butler`_ ``CALIBRATION`` `collection`_.

.. _cp_verify: https://github.com/lsst/cp_verify
.. _butler: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/index.html
.. _collection: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/organizing.html

.. _ComCam-Combined-Calibrations-Procedure-Steps:

Procedure Steps
===============

Once you are logged into LOVE, click on the ``MTQueue`` panel, as circled on the right side of the figure below (for reference, ``ATQueue`` to lauch ``LATISS`` scripts is circled on the left):

.. figure:: ./_static/love-mtqueue-atqueue-panel.png
    :name: MTQueue-love

    Screenshot of LOVE interface with the "MTQueue" pannel.


Load the Script
---------------

After clicking on the ``MTQueue`` panel, search for the script ``maintel/make_comcam_calibrations.py`` under ``AVAILABLE SCRIPTS`` on the left, as shown in the figure below:

.. figure:: ./_static/love-available-scripts.png
    :name: comcam-available-scripts-love

    Screenshot of LOVE interface with the "AVAILABLE SCRIPTS" list.
      
Load the script by clicking on the button in front of the name of the script that has a triangle.

Enter configuration parameters
------------------------------

After loading the script, a window that contains two sections, ``SCHEMA`` (top) and ``CONFIG`` (bottom), will appear.
The former will show the available configuration options (and the default values of some of them) that should be entered in the latter.
The configuration options are as follows:

- ``script_mode``: Currently, the script can be run  in three modes, in which  it  will  produce only biases (``BIAS``), biases and darks (``BIAS_DARK``), or biases, darks, and flats (``BIAS_DARK_FLAT``).
  Default: ``BIAS_DARK_FLAT``.
- ``n_bias``: Number of biases to take.
  Default: ``20``.
- ``n_discard_bias``: Additional number of bias images to take and discard before starting the sequence.
  Default: ``1``.
- ``n_dark``: Number of darks to take.
  Default: ``20``.
- ``n_discard_dark``: Additional number of dark images to take and discard before starting the sequence.
  Default: ``1``.
- ``exp_times_dark``: The exposure time of each dark image (sec). If a single value, then the same exposure time is used for each exposure.
  Default: ``5``.
- ``n_flat``:  Number of flats to take. Default: ``20``.
- ``n_discard_flat``: Additional number of flat images to take and discard before starting the sequence.
  Default: ``1``.
- ``exp_times_flat``: The exposure time of each flat image (sec). If a single value, then the same exposure time is used for each exposure. If ``do_ptc`` is ``True``, the exposure times should form an adecuate secuence of flat pairs, each pair with the same exposure time. If ``do_gain_from_flat_pairs`` is ``True``, at least two flats with the same exposure time should be taken.
  Default: ``5``.
- ``detectors``: Detector IDs that will be pased to the pipeline tasks, given as an array of integers, e.g., ``[0,1,2,3]``. The default value is an empty array, which will translate in using all the detectors (9, for LSSTComCam).
  Default: ``[]``.
- ``do_verify``: Should the combined calibrations be verified? (c.f., ``cp_verify``).
  Default:  ``True``.
- ``generate_calibrations``: Should the combined calibrations be generated from the images taken and used as references for image verification? ("internal verification"). If ``False`` and and ``do_verify`` is ``True``, pre-existing calibrations will be used as reference for verification ("external verification"), and they should be provided in the input collections for the verification pipetasks.
  Default: ``False``.
- ``config_options_bias``: Options to be passed to the command-line bias pipetask. They will overwrite the values in ``cpBias.yaml``.
  Default: ``-c isr:doDefect=False``.
- ``config_options_dark``: Options to be passed to the command-line dark pipetask. They will overwrite the values in ``cpDark.yaml``.
  Default: ``-c isr:doDefect=False``.
- ``config_options_flat``: Options to be passed to the command-line flat pipetask. They will overwrite the values in ``cpFlat.yaml``.
  Default: ``-c isr:doDefect=False``.
- ``do_defects``: Should defects be built using darks and flats?. ``script_mode`` must be ``BIAS_DARK_FLAT``.
  Default: ``False``.
- ``config_options_defects``: Options to be passed to the command-line defects pipetask. They will overwrite the values in ``findDefects.yaml``.
  Default: ``-c isr:doDefect=False``.
- ``do_ptc``: Should a Photon Transfer Curve be constructed from the flats taken? ``script_mode`` must be ``BIAS_DARK_FLAT``.
  Default: ``False``.
- ``config_options_ptc``: Options to be passed to the command-line PTC pipetask. They will overwrite the values in ``cpPtc.yaml``.
  Default: ``-c isr:doCrosstalk=False``.
- ``do_gain_from_flat_pairs``: Should the gain be estimated from each pair of flats taken at the same exposure time?
  Runs the ``cpPtc.yaml#generateGainFromFlatPair`` pipeline.
  Since this pipeline is a subset of the PTC pipeline, you can use use the ``config_options_ptc`` parameter to pass options to the ``ISR`` (Instrument Signature Removal) and ``cpExtract`` tasks which form this pipeline. If ``True``, the script mode should be ``BIAS_DARK_FLAT``.
  Default: ``True``.
- ``input_collections_bias``: List of additional (the ``OCPS`` already adds ``LSSTComCam/raw/all`` as a default) comma-separated input collections for the bias pipetask. The pipetask is called via the ``OCPS`` after enabling it with the ``LSSTComCam`` configuration.
  Default: ``LSSTComCam/calib``.
- ``input_collections_verify_bias``: Additional comma-separated input collections to pass to the verify (bias) pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_dark``: Additional comma-separarted input collections to pass to the dark pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_verify_dark``: Additional comma-separated input collections to pass to the verify (dark) pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_flat``: Additional comma-separated input collections to pass to the flat pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_verify_flat``: Additional comma-separated input collections to pass to the verify (flat) pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_defects``: Additional comma-separated input collections to pass to the defects pipetask.
  Default: ``LSSTComCam/calib``.
- ``input_collections_ptc``: Additional comma-separated input collections to pass to the Photon Transfer Curve pipetask.
  Default: ``LSSTComCam/calib``.
- ``calib_collection``: ``CALIBRATION`` collection where the calibrations will be certified into, for example, ``LSSTComCam/calib/u/plazas/YYYYMMMDD.test`` or ``LSSTComCam/calib/daily``. Default: ``LSSTComCam/calib/daily``.
- ``repo``: Butler repository.
  Default: ``/repo/LSSTComCam``.
- ``n_processes``: Number of processes that the pipetasks will use.
  Default: ``8``.
- ``certify_calib_begin_date``: The beginning date for the validity range of the certified calibration, for example, ``2021-07-15``.
  Default: ``1950-01-01``.
- ``certify_calib_end_date``: The end date for the validity range of the certified calibration, for example, ``2021-07-16``.
  Default: ``2050-01-01``.
- ``oods_timeout``: Timeout value, in seconds, for the Observatory Operations Data Service (``OODS``).
  Default: ``120``.


Configuration examples
-----------------------

Daily Default
^^^^^^^^^^^^^

**Preferred daily script mode to be run**: if no configuration parameters are passed to LOVE and the default parameters are used, the script will take 21 biases, 21 darks of 5 seconds each one, and 21 flats of 5 seconds each one.
In each case, the first image will be discarded. New combined calibrations will not be generated, and verification of the images taken will be performed using the existing combined calibrations in the ``LSSTComCam/calib`` collection (i.e., th script will do ``external verification``).
In this case, no defects will be made.
Following DMTN-222, a gain estimate will be produced from each of the 10 flat pairs taken.
**Users should adjust parameters when needed, for example, the exposure times or the number of exposures taken**.

If the exposure times need to change, it can be done as follows:

.. code-block:: yaml
    
    exp_times_dark: 20
    exp_times_flats: 30

Changing the exposure times and the number of exposures
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If both the number of exposures and exposure times need to change, it can be done like this:

.. code-block:: yaml

    n_bias: 30
    n_dark: 5
    exp_times_dark: [5, 10, 15, 20, 25]
    n_flat: 10
    exp_times_flat: [5, 10, 15, 20, 25, 30, 35, 40, 45, 50]

Example of a configuration file for ``internal_verification``.
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note that the newly-generated combined calibrations
will be certified in the ``calib_collection`` collection, so this parameter must be specified, and new validity ranges should be provided (spanning one day for daily calibrations).
The name of the collection needs to be changed if the script needs to be run again (or the validity range), as it is not possible to certify the same type of calibration in the same collection with the same validity range:

.. code-block:: yaml

    generate_calibrations: True
    calibration_collection: LSSTComCam/calib/daily/calib.2022NOV04.1
    certify_calib_begin_date: "2022-11-04"
    certify_calib_begin_date: "2022-11-05"

Including a Photon Transfer Curve (PTC)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the following example, a new set of calibrations is generated, including a PTC (note that the exposure times need to be given by pairs and the total length must correspond to ``n_flat``) and defects.
If the individual images taken pass verification using as reference the newly generated combined bias, dark, and flat, the combined calibrations will be certified in the ``calib_collection`` collection with the validity range given by ``certify_calib_begin_date`` and ``certify_calib_end_date``.
There is the option to take flats with a particular filter (the appropiate names/ID should be replaced in ``${FILTER_NAME_OR_ID}`` below):

.. code-block:: yaml

    script_mode: BIAS_DARK_FLAT
    n_flat: 14
    exp_times_flat: [5, 5, 10, 10, 15, 15, 20, 20, 25, 25, 30, 30, 35, 35]
    filter: ${FILTER_NAME_OR_ID}
    generate_calibrations=True
    calib_collection: "LSSTComCam/calib/daily/calibs.2022NOV04.1"
    certify_calib_begin_date: "2022-11-04"
    certify_calib_end_date: "2022-11-05"
    do_defects: True
    do_ptc: True

Another example including PTC and defects generation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Another example set of configuration parameters is as follows:

.. code-block:: yaml

    n_bias: 6
    n_dark: 6
    exp_times_dark: [5, 5, 5, 10, 15, 20]
    n_flat: 14
    exp_times_flat: [0.1, 0.1, 0.35, 0.35, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0, 1.35, 1.35, 1.6, 1.6]
    calib_collection: "LSSTComCam/calib/u/plazas/daily.2021SEP13.test1"
    do_verify: True
    input_collections_verify_bias: "LSSTComCam/calib/u/plazas/2021SEP16.1,LSSTComCam/calib"
    input_collections_verify_dark: "LSSTComCam/calib/u/plazas/2021SEP16.1,LSSTComCam/calib"
    input_collections_verify_flat: "LSSTComCam/calib/u/plazas/2021SEP16.1,LSSTComCam/calib"
    certify_calib_begin_date: "2021-07-15"
    certify_calib_end_date: "2021-07-17"
    script_mode: BIAS_DARK_FLAT
    do_defects: True
    do_ptc: True

Notes:

- The ``detectors`` parameters was omitted, therefore, by default, all nine LSSTComCam detectors will be passed to the LSST Science Pipelines pipetasks.
  For testing purposes it might be convenient to process fewer detectors in the pipetasks, as the script will execute faster.
- The ``generate_calibrations`` parameters was omitted, and therefore combined calibrations will not be generated from the individual images taken (biases, darks, and flats since ``script_mode`` is ``BIAS_DARK_FLAT``), as its default value is ``False``.
  Pipetasks that require combined calibrations to run will search for them in their input collections.
  For example, since ``do_verify`` is ``True``, the bias, dark, and flat verification tasks will look for combined reference calibrations in their input collections, given by the ``input_collections_verify_bias``, ``input_collections_verify_dark``, and ``input_collections_verify_flat`` parameters.
  Since the collection ``LSSTComCam/calib/u/plazas/2021SEP16.1`` is located before the standard collection ``LSSTComCam/calib`` in these parameters, the verification tasks will look there first.
  On the other hand, since ``do_ptc`` is ``True`` and ``input_collections_ptc`` is omitted, the PTC task will look for combined calibrations (e.g., bias, dark) in the standard calibration collection ``LSSTComCam/calib``, which is the default for this parameter.
- Sometimes running the PTC can take a long time.
  In order to obtain a quick estimation for the gain (and monitor, for example, its stability with time), the parameter ``do_gain_from_flat_pairs`` can be set to ``True``.
  In that case, only one pair of flats is required, so the parameter ``exp_times_flat`` could be set to, e.g., ``[1.2, 1.2]``. However, the task will estimate a gain for every flat pair that has been taken (``LOVE`` will report the values per exposure pair per detector per amplifier).
  For example, if ``exp_times_flat`` is  ``[0.1, 0.1, 0.35, 0.35, 0.6, 0.6, 1, 1.5, 1.7, 2.1, 2.3]``, gains will be estimated from the first three flat pairs.
- See `DMTN-222`_ for a discussion on calibration generation, verification, acceptance, and certfication, including suggested naming conventions for parameters such as ``calib_collection``.

.. _DMTN-222: https://dmtn-222.lsst.io/

Launch the script
-----------------

When the configuration options have been entered and the script is ready to be launched, click on the ``ADD`` button in the lower right of the screen (refer to image above).

Accessing the calibrations
--------------------------

The certified combined calibrations will be available via the collection specified by the **calib_collection** parameter. They could be retrieved from a notebook for manipulation and visualization:

.. code-block:: python
    
    import lsst.daf.butler as dB

    butler = dB.Butler("/repo/LSSTComCam", collections=["LSSTComCam/calib/daily.2021SEP13.test1"])
    detectors = (0, 1, 2, 3, 4, 5, 6, 7, 8)
    exposure = [bias1ID, bias2ID] # e.g., [2021071500001, 2021071500002]
    
    # For detector "0":
    bias = butler.get('bias', detector=detectors[0], exposure=exposure[0], instrument='LSSTComCam')
    dark = butler.get('dark', detector=detectors[0], exposure=exposure[0], instrument='LSSTComCam')
    flat = butler.get('flat', detector=detectors[0], exposure=exposure[0], instrument='LSSTComCam')
    defects = butler.get('defects', detector=detectors[0], exposure=exposure[0], instrument='LSSTComCam')
    ptc = butler.get('ptc', detector=detectors[0], exposure=exposure[0], instrument='LSSTComCam')


If ``do_gain_from_flat_pair`` is ``True``, the estimated gains (as well as the measured empirical readout noise from the overscan during Instrument Signature Removal) can be found by requesting the ``cpPtcExtract`` data structure. In this case, the exposure ID should be one of the two flats used to estimate the gain:

.. code-block:: python

    cpCovs = butler.get('cpPtcExtract', detector=detector[0], exposure=flat1ID, instrument='LSSTComCam')
    gain_values = cpCov.gain
    noise_values = cpCov.noise

The gain estimated in this way (from single pairs of flats) is an approximation that is likely to be more accurate at lower fluxes.
This method has the advantage that it allows to obtain a quick estimate of the gain without having to take multiple flat pairs to construct a full PTC and to fit a model to it.

In addition, the statistics produced by the verification step can be analized by running the Jupyter notebooks in the ``examples`` folder in ``cp_verify``.
As it is shown in these notebooks, useful statistics and information about the results of the ``cp_verify`` tests can be retrieved from the butler via (using flat verification as an example):

.. code-block:: python

    runStats = butler.get('verifyFlatStats', instrument='LSSTComCam')
    runDetStats = butler.get('verifyFlatDetStats', instrument='LSSTComCam', detector=0, exposure=flatExposureID)


The images processed by ``cp_verify`` can also be retrieved for visual inspection:

.. code-block:: python
    
    import lsst.afw.display as afwDisplay
    afwDisplay.setDefaultBackend("matplotlib")

    imProc = butler.get('verifyFlatProc', detector=0, exposure=flatExposureID, instrument='LSSTComCam')
    calibArray = imProc.getImage().getArray()
    # Get simple stats
    q25, q50, q75 = np.percentile(calibArray.flatten(), [25, 50, 75]) 
    sigma = 0.74 * (q75 - q25)
    display = afwDisplay.Display(dims=(1000, 1000))
    display.scale('asinh', 'zscale')
    display.scale('linear', (q50 - 3.0 * sigma), (q50 + 3.0* sigma), "")
    display.mtv(imProc)

Troubleshooting
===============

    After checking the configuration options and the ``LOVE`` error messages, the file ``/scratch/uws/${jobId}/outs/ocps.log`` will contain additional technical information on which pipetask failed, if any.
    ``{jobId}`` is returned by the OCPS and can be retrieved from the ``LOVE`` output messages.


This procedure was last modified on |today|.

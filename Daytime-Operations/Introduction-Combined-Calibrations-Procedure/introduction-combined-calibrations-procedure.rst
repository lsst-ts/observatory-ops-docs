.. |author| replace:: *Andrés A. Plazas Malagón*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _Introduction-Combined-Calibrations-Generation-Procedure:

##########################################################
Introduction to Combined Calibrations Generation Procedure
##########################################################

.. _Introduction-Combined-Calibrations-Procedure-Overview:

Overview
========

This procedure describes how to execute the SAL Script to take individual calibration frames (biases, darks, and flats) and verify them via the `cp_verify`_ package for LATISS or LSSTComCam on the ScriptQueue from the LSST Operations and Visualization Enviroment (LOVE) at the Summit. 

The script will have the option to: 

- command the instrument to take a number of individual calibrations frames:
   - biases
   - darks
   - flats
- call the corresponding Rubin Science Pipelines calibration generation pipetask to produce combined biases, combined darks, combined flats, defects, and Photon Transfer Curves (PTCs) via the OCS-Controlled Pipeline System (OCPS),
- verify the images taken using as reference the calibration generated in the previous step via the ``generate_calibrations`` boolean parameter in the configuration file (this mode is referred to as "internal verification"; see the package `cp_verify`_, and the technical notes `DMTN-101`_ and `DMTN-222`_), or using pre-existing calibrations that are usually located in the ``LATISS/calib`` or `LSSTComCam/calib` standard calibration collections (this mode is referred to as "external verification"), and
- automatically certify the newly-generated combined calibration (if ``generate_calibrations`` is set to ``True``) with a given range of validity dates (usually one day).

The verification step is currently only implemented for biases, darks, and flats.
In order to run `cp_verify`_, the verification pipetask uses as input individual images and the combined image for a particular calibration type as a reference.
This reference combined image may already exist in the default calibration collection ``LATISS/calib`` or ``LSSTComCam/calib`` (a location that can be changed via the ``input_collections_verify_bias`` and similar parameters), or, the user can indicate the script to generate a new combined calibration from the individual images taken via the ``generate_calibrations`` parameter.
The former is known as ``external verification``, and the latter as ``internal verification``.
The two verification modes are designed to answer slightly different questions using the same tools; for ``external verification``, the question is "are the data taken with the camera consistent with what they were in the recent past?".
This covers stability ranges on the day/week/month time scales.
``Internal verification`` asks "are the data taken with the camera consistent with themselves?", covering stability ranges on the minute/hour level.
By default, the script will run in ``external verification`` mode.

For at least one type of test (as defined in the sections of `DMTN-101`_), if the majority of tests fail verification in the majority of detectors and the majority of exposures, then the script will terminate after calculating these verification statistics.
If ``generate_calibrations`` is ``True``, the calibration will not be certified into the ``calibration_collection`` collection.
The configuration parameters ``number_verification_tests_threshold_bias``, ``number_verification_tests_threshold_dark``, and ``number_verification_tests_threshold_flat`` will be used to define thresholds to decide whether the calibration will pass verification and should be certified or not.
Currently, verification is only implemented for ``BIAS``, ``DARK``, and ``FLAT`` calibration types.
If the configuration parameters ``do_defects`` and ``do_ptc`` are set to ``True``, verification will be skipped for the ``DEFECTS`` and ``PTC`` calibrations and they will be automatically certified.

The script currently has the option (via the ``script_mode`` parameter in the configuration options) to:

- work with  only biases (including talking the exposures and optionally generating and verifying a combined calibration), 
- work with biases and darks, and 
- work with biases, darks, and flats. 
  
These options are constrained by the fact that the generation or construction of one calibration depends on the existence of the previous one (i.e., to generate a combined dark, a combined bias is necessary, and to generate a flat, a combined dark and a combined bias are necessary).
If ``generate_calibrations`` is ``True``, calibrations will eventually end up in the collection specified by the ``calib_collection`` configuration parameter and, if certified, will have a validity span range from ``certify_calib_begin_date`` to ``certify_calib_end_date``.

Calibration generation from the images taken can also be skipped by setting ``generate_calibrations`` to ``False``.
This will speed up the execution time of the script, and subsequent tasks (for example, verification tasks or the PTC construction task) will look for necessary calibrations in their input collections (whose default is the standard calibrations collection: ``LATISS/calib`` or ``LSSTComCam/calib``).

If desired, defects can be constructed from darks and flats (if ``do_defects=True``), and a PTC per detector per amplifier constructed from the flats (if ``do_ptc=True``).
Note that the PTC assumes that a sequence of flat pairs has been taken, each pair taken at the same exposure time. In both cases, ``script_mode`` must be set to ``BIAS_DARK_FLAT``.

For more information about calibrations production (including verification and certification), please consult the `Constructing Calibrations documentation`_.

.. _cp_verify: https://github.com/lsst/cp_verify
.. _DMTN-101: https://dmtn-101.lsst.io/
.. _DMTN-222: https://dmtn-222.lsst.io/
.. _Constructing Calibrations documentation: https://pipelines.lsst.io/v/daily/modules/lsst.cp.pipe/constructing-calibrations.html

See also:

- :ref:`LATISS Combined Calibrations Procedure <LATISS-Combined-Calibrations-Procedure-LATISS-Combined-Calibrations-Generation-Procedure>`
- :ref:`ComCam Combined Calibrations Procedure <ComCam-Combined-Calibrations-Procedure-ComCam-Combined-Calibrations-Generation-Procedure>`

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

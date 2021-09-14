.. |author| replace:: *Andrés A. Plazas Malagón*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _ComCam-Master-Calibrations-Procedure:

###########################
ComCam Master Bias Generation Procedure
###########################

.. _ComCam-Master-Calibrations-Procedure-Overview:

Overview
========

This procedure describes how to call scripts to produce master calibrations for LSSTComCam from the LSST Operations and Visualization Enviroment (LOVE) at the Summit :ref:`operational environment <Observing-Interface-Operational-Environments>`. 

The script will have the option to: 

- command LSSTComCam to take a number of calibrations frames:
   - biases
   - darks 
   - flats
- call the corresponding Rubin Science Pipelines calibration generation pipetask to produce biases, darks, flats, defects and Photon Transfer Curves (PTCs) via the OCS-Controlled Pipeline System (OCPS),
- verify the resulting calibration (see the package `cp_verify`_ and `DMTN-101`_),
- certify the resulting calibration with a given range of validity dates.

The script currently has the option (the `script_mode` parameter in the configuration options) to 1) take only biases, 2) take biases and darks, 3) take biases, darks, and flats. These options are constrained by the fact that one calibration depends on the existence of the previous one (i.e., to build a dark, a bias is necessary, and to build a flat, a dark and a bias are necessary).

If desired, defects can be constructed from darks and flats (in which case  `script_mode` must be ``BIAS_DARK_FLAT``), and a PTC per detector per amplifier constructed form the flats. Note that the PTC assumes that a sequence of flat pairs has been taken, each pair taken at the same exposure time (in order to produce a PTC, `script_mode` must be ``BIAS_DARK_FLAT`` too).

For more information about calibrations production (including verification and certification), please consult the `Constructing Calibrations documentation`_.

.. _cp_verify: https://github.com/lsst/cp_verify
.. _DMTN-101: https://dmtn-101.lsst.io/
.. _Constructing Calibrations documentation: https://lsst.ncsa.illinois.edu/~czw/pipelines_lsst_io/_build/html/modules/lsst.cp.pipe/constructing-calibrations.html 

.. _ComCam-Master-Calibrations-Procedure-Prerequisites:


Prerequisites
=============

- You should be logged into the LSST Operations and Visualization Enviroment (LOVE) at the Summit :ref:`operational environment <Observing-Interface-Operational-Environments>`.
- The script assumes (and checks) that the ``LSSTComCam`` and ``OCPS`` components are all ``ENABLED``, and that the latter has been ``ENABLED`` with the configuration of ``LSSTComCam``. The instrument and the ``OCPS`` can be enabled, for example, from a notebook: 

.. code-block:: python

    import asyncio
    from lsst.ts import salobj
    from lsst.ts.observatory.control.maintel.comcam import ComCam

    do_enable_camera = True
    do_enable_ocps = True

    domain = salobj.Domain()
    comcam = ComCam(domain)
    ocps = salobj.Remote(domain, "OCPS")
    await asyncio.gather(comcam.start_task, ocps.start_task)

    if do_enable_camera:
       await comcam.enable()

    if do_enable_ocps:
        instrument="LSSTComCam"
        ack = await ocps.cmd_start.set_start(settingsToApply=instrument)
        if ack.ack != salobj.SalRetCode.CMD_COMPLETE:
            ack.print_vars()

        ack = await ocps.cmd_enable.set_start()
        if ack.ack != salobj.SalRetCode.CMD_COMPLETE:
            ack.print_vars()

.. _butler: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/index.html

.. _ComCam-Master-Calibrations-Procedure-Post-Conditions:

Post-Condition
==============

- A (daily) master calibration image per detector will be certified in a butler ``CALIBRATION`` `collection`_.

.. _collection: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/organizing.html

.. _ComCam-Master-Calibrations-Procedure-Steps:

Procedure Steps
===============

Once you are logged into LOVE, click on the ``MTQueue`` panel, as circled on the right side of the figure below (for completeness, ``ATQueue`` to lauch ``LATISS`` scripts is circled on the left):

.. figure:: ./_static/love-mtqueue-atqueue-panel.png
    :name: MTQueue-love

     Screenshot of LOVE interface with the "MTQueue" pannel.


Load the Script
---------------

After clicking on the ``MTQueue`` panel, search for the script ``maintel/make_comcam_calibrations.py`` under ``AVAILABLE SCRIPTS`` on the left, as shown in the figure below:

.. figure:: ./_static/love-available-scripts.png
    :name: available-scripts-love

      Screenshot of LOVE interface with the "AVAILABEL SCRIPTS" list.
      
Load the script by clicking on the button in front of the name of the script that has a triangle.

Enter configuration parameters
------------------------------

After loading the script, a window that contains two sections, ``SCHEMA`` (top) and ``CONFIG`` (bottom), will appear. The former will show the available configuration options (and the default values of some of them) that should be entered in the latter. The configuration options are as follows:

- ``script_mode``: Currently, the script can be run  in three modes, in which  it  will  produce only biases (``BIAS``), biases and darks (``BIAS_DARK``), or biases, darks,
  and flats (``BIAS_DARK_FLAT``).
  * Default: ``BIAS_DARK_FLAT``
- ``n_bias``: number of bias frames to be taken.
  * Default: 1 
- ``n_dark``: number of dark frames to be taken.
  * Default: 1
- ``exp_times_dark``: The exposure time of each dark image (sec). If a single value,
                       then the same exposure time is used for each exposure.
  * Default: 0
- ``n_flat``: number of flat frames to be taken.
  * Default: 1
- ``exp_times_flat``: The exposure time of each flat image (sec). If a single value,
                       then the same exposure time is used for each exposure.
  * Default: 0
- ``detectors``: Detector IDs, e.g., ``(0,1,2,3,4,5,6,7,8)`` for all LSSTComCam CCDs.
  *  Default: "(0,1,2,3,4,5,6,7,8)"
-  ``do_verify``: Should the master calibrations be verified? (c.f., ``cp_verify``)
  * Default:  True
- ``config_options_bias``: Options to be passed to the command-line bias pipetask. They will overwrite the values in cpBias.yaml.
  * Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False
                          -c isr:overscan.fitType='MEDIAN_PER_ROW'"
- ``config_options_dark``: Options to be passed to the command-line dark pipetask. They will overwrite
            the values in cpDark.yaml.
  * Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False"
- ``config_options_flat``: Options to be passed to the command-line flat pipetask. They will overwrite
            the values in cpFlat.yaml
   * Default: "-c isr:doDefect=False -c isr:doLinearize=False -c isr:doCrosstalk=False
                  -c cpFlatMeasure:doVignette=False "
- ``do_defects``: Should defects be built using darks and flats?. ``script_mode`` must be ``BIAS_DARK_FLAT``.
   * Default: False
- ``config_options_defects``: Options to be passed to the command-line defects pipetask. They will overwrite
            the values in findDefects.yaml.
   * Default: "-c isr:doDefect=False "
-  ``do_ptc``: Should a Photon Transfer Curve be constructed from the flats taken? ``script_mode`` must be ``BIAS_DARK_FLAT``.
    *  Default: False
- ``config_options_ptc``: Options to be passed to the command-line PTC pipetask. They will overwrite \
                    the values in measurePhotonTransferCurve.yaml. 
- ``input_collections_bias``: List of additional (the ``OCPS`` already adds ``LSSTComCam/raw/all`` as a default) comma-separated input collections for the bias pipetask. The pipetask is called via the ``OCPS`` after enabling it with the ``LSSTComCam`` configuration.
- ``calib_collection``: ``CALIBRATION`` collection where the calibrations will be certified into, for example, ``LSSTComCam/calib/u/plazas/YYYYMMMDD.test``.
- ``repo``: Butler repository. For example, ``/repo/LSSTComCam``.
- ``n_processes``: Number of processes that the pipetasks will use.
- ``certify_calib_begin_date``: The beginning date for the validity range of the certified calibration. For example, ``2021-07-15``.
- ``certify_calib_end_date``: The end date for the validity range of the certified calibration. For example, ``2021-07-16``.
- ``max_counter_archiver_check``: After the camera takes images, this is the maxmimum number of loops to wait for confirmation that the images taken are archived and available.
- ``oods_timeout``: Timeout value, in seconds, for the Observatory Operations Data Service (``OODS``).

An example set of configuration parameters is as follows:

.. code-block:: text

    n_bias: 6
    n_dark: 6
    exp_ttimes_dark: [5, 5, 5, 10, 15, 20]
    n_flat: 14
    exp_times_flat: [0.1, 0.1, 0.35, 0.35, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0, 1.35, 1.35, 1.6, 1.6]
    detectors: (0,1,2,3,4,5,6,7,8)
    calib_collection: LSSTComCam/calib/u/plazas/daily.2021SEP13.test1
    do_verify: True
    input_collections_verify_bias: LSSTComCam/calib/u/plazas/2021SEP01.4,LSSTComCam/calib
    input_collections_verify_dark: LSSTComCam/calib/u/plazas/2021SEP01.4,LSSTComCam/calib
    input_collections_verify_flat: LSSTComCam/calib/u/plazas/2021SEP01.4,LSSTComCam/calib
    certify_calib_begin_date: 2021-07-15
    certify_calib_end_date: 2021-07-16
    script_mode": BIAS_DARK_FLAT
    do_defects: True
    do_ptc: True
    repo: /repo/LSSTComCam

Launch the script
-----------------
When the configuration options have been entered and the script is ready to be launched, click on the ``ADD`` button in the lower right of the screen (refer to image above).

The certified master calibrations will be available in the ``calib_collection`` collection. They could be retrieved from a notebook for manipulation and visualization: 

.. code-block:: python
    
    import lsst.daf.butler as dB

    butler = dB.Butler("/repo/LSSTComCam", collections=["LSSTComCam/calib/daily.2021SEP13.test1"])
    detector = (0, 1, 2, 3, 4, 5, 6, 7, 8)
    exposure = [bias1ID, bias2ID] # e.g., [2021071500001, 2021071500002]
    
    # For detector "0":
    bias = butler.get('bias', detector=detector[0], exposure=exposure[0], instrument='LSSTComCam')
    dark = butler.get('dark', detector=detector[0], exposure=exposure[0], instrument='LSSTComCam')
    flat = butler.get('flat', detector=detector[0], exposure=exposure[0], instrument='LSSTComCam')
    defects = butler.get('defects', detector=detector[0], exposure=exposure[0], instrument='LSSTComCam')
    ptc = butler.get('ptc', detector=detector[0], exposure=exposure[0], instrument='LSSTComCam')


In addition, the statistics produced by the verification step can be analized by looking into the ``examples`` folder in ``cp-verify``.

Troubleshooting
===============

    After checking the configuration options and the ``LOVE`` error messages, the file ``/scratch/uws/${jobId}/outs/ocps.log`` will contain additional technical information on which pipetask failed, if any. ``{jobId}`` is returned by the OCPS and can be retrieved from the ``LOVE`` output messages.


.. _ComCam-Master-Calibrations-Procedure-Conditions-Contact-Personnel:

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

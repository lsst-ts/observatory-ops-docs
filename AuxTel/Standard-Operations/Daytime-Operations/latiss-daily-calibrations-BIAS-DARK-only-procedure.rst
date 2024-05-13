.. _`RubinTV`: https://summit-lsp.lsst.codes/rubintv/summit/auxtel 
.. _cp_verify: https://github.com/lsst/cp_verify
.. _butler: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/index.html
.. _collection: https://pipelines.lsst.io/v/daily/modules/lsst.daf.butler/organizing.html
.. _BLOCK source code: https://github.com/lsst-ts/ts_config_ocs/blob/develop/Scheduler/observing_blocks_auxtel/block-295-latiss_daily_calibrations.json
.. _AuxTel (LATISS) Temperatures and Pressures dashboard: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/14

.. |author| replace:: *Karla Peña Ramírez*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Erik Dennihy, OS team*

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-only-Procedure:
############################################
LATISS Daily Calibrations BIAS and DARK only
############################################

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-only-Overview:
Overview
========
This procedure will acquire BIAS and DARK calibration images. 
This page assumes the reader is familiar with the content explained in the Observatory section: :ref:`Introduction to the combined calibrations generation procedure.<Introduction-Combined-Calibrations-Generation-index>` 

.. warning::
  This procedure does not involves telescope motion with AuxTel. Announce that you are about to run the calibrations without telescope or dome movement on the *#summit-announce* and *#summit-auxtel* channels before you run the following steps.

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-only-Post-Conditions:
Post-Condition
==============
- Individual BIAS and DARK calibration images will be taken and verified using the `cp_verify`_ framework.
- If ``generate_calibrations`` is ``True``, a (daily) combined calibration image per detector will be certified in a `butler`_ ``CALIBRATION`` `collection`_.

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-only-Procedure-Steps:
Procedure Steps
===============

#. Calibration images should only be taken if the LATISS WREB temperature is under temperature control.
    
    Check the LATISS WREB temperatures under the `AuxTel (LATISS) Temperatures and Pressures dashboard`_ in Chronograf. WREB temperatures are visible in the lower middle panel labeled *WREB On Board*. 
        
    If the *mean_temp2* (top blue line) is between 26-29 degress C, the temperature is suitable for taking calibrations. 
        
    During the daytime, the fan on the WREB board may not be sufficient to cool the WREB down to these temperatures, so during warmer months you may have to wait until later in the day or early in the morning for it to reach the desired temperature. 
        
    If the temperature is too high, do not proceed to the next steps. 

#. Enable ATCS and LATISS using the standard scripts :file:`enable_atcs.py` and :file:`enable_latiss.py` with no configuration. 
#. Enable the OCPS:1 CSC which is used to run automatic verification pipelines on the data. The :file:`set_summary_state.py` script will enable the ``OCPS:1`` CSC.
            .. code-block:: text
              :caption: :file:`set_summary_state.py`
          
              data:
                -
                  - OCPS:1
                  - ENABLED
#. Enable the ``Scheduler:2`` scheduler using the standard script :file:`auxtel/scheduler/enable.py`. 
#. Run the script :file:`auxtel/make_latiss_calibrations.py` on the ATQueue  with the following configuration:
      .. code-block:: text
        :caption: :file:`auxtel/make_latiss_calibrations.py`
      
          script_mode: BIAS_DARK

#. The script takes the default number of BIAS (20) and DARK (22 with different exposure times  5, 15 and 30 seconds) calibration images. The process will take about 15 minutes to complete.

Once the script finishes, announce that the calibrations are complete on *#summit-announce* and *#summit-auxtel* channels. Use the :file:`standby_latiss.py` standard script to leave LATISS in ``STANDBY`` state.

.. _Daytime-Operations-LATISS-Daily-Calibrations-BIAS-DARK-only-Contingency:
Contingency
===========
In cases with not enough time available for calibrations, skip this procedure.

This procedure was last modified |today|.
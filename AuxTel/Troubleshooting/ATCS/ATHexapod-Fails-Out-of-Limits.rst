.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Kristopher Mortensen*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Ioana Sotuela, Kshitija Kelkar*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _ATHexapod-Fails-Out-of-Limits:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

################################
ATHexapod Position Out of Limits
################################


.. _ATHexapod-Fails-Out-of-Limits-Overview:

Overview
========

When running scripts that require ATAOS corrections (e.g., :file:`atpneumatics_checkout.py`, :file:`latiss_wep_align.py`, or :file:`enable_ataos_corrections.py`, 
ATHexapod may fail to apply corrections due to its position being outside of operational limits.

.. _ATHexapod-Fails-Out-of-Limits-Error-Diagnosis:

Error diagnosis
===============

1.  ATHexapod CSC goes into ``FAULT``, and produces the following error in its message log:

    .. code-block:: text
      :caption: ATHexapod CSC Error Message

      Position out of limits (7)
  

2.  Should the ATAOS CSC go into ``FAULT``, the following error will display in the 
    current SAL script execution log in ATQueue:

    .. code-block:: python
      :caption: ATAOS Script Failure Message

          File
      "/opt/lsst/software/stack/conda/envs/lsst-scipipe-9.0.0/lib/python3.11/site-
      packages/lsst/ts/salobj/topics/remote_command.py", line 191, in next_ackcmd
          raise
      base.AckError(msg="Command failed", ackcmd=ackcmd) lsst.ts.salobj.base.AckError: msg='Command
      failed', ackcmd=(ackcmd private_seqNum=493863606, ack=<SalRetCode.CMD_FAILED: -302>, error=1,
      result="Failed: disableCorrection not allowed in Fault state: errorCode=8103,
      errorReport='Correction loop died.'")

    And the ATAOS CSC produces the following error in its message log:

    .. code-block:: text
      :caption: ATAOS CSC Error Message

      Correction loop died.

.. _ATHexapod-Fails-Out-of-Limits-Procedure-Steps:

Procedure Steps
===============


.. _ATHexapod-Fails-Out-of-Limits-Procedure-Case-1:

Case 1: Only ATHexapod Faults
-----------------------------

1.  Reset the position of the ATHexapod loading a :file:`run_command.py` SAL script 
    into ATQueue with the following configuration::
      
      component: ATHexapod
      cmd: moveToPosition
      parameters:
        x: 0
        y: 0
        z: 0
        u: 0
        v: 0
        w: 0

2.  Load :file:`enable_ataos_corrections.py` to re-enable the ATAOS corrections.

    - Run this script only at **high elevations** :math:`(\geq 70^\circ)`.

3.  Verify ATHexapod is operating properly by running :file:`atpneumatics_checkout.py`.


.. _ATHexapod-Fails-Out-of-Limits-Procedure-Case-1:

Case 2: ATHexapod & ATAOS Fail
------------------------------

1.  Send ATAOS CSC to ``OFFLINE`` using the :file:`set_summary_state.py` script 
    with the following configuration::

        data:
          - [ATAOS, OFFLINE]

2.  Reset the ATAOS CSC on ArgoCD by following the instructions for `Restarting a CSC Component in ArgoCD <https://rubinobs.atlassian.net/wiki/spaces/OOD/pages/883752990/Restarting+a+CSC+Component+in+ArgoCD>`_.

    - Contact another scientist on Slack (`#summit-auxtel <https://rubin-obs.slack.com/archives/C07Q45NUK4P>`_) for assistance.

3.  Send ATAOS CSC back to ``ENABLED`` with another :file:`set_summary_state.py` 
    script::

      data:
        - [ATAOS, ENABLED]

4.  Load :file:`enable_ataos_corrections.py` to re-enable the ATAOS corrections.

    - Run this script only at **high elevations** :math:`(\geq 70^\circ)`.


5.  Verify ATHexapod is operating properly by running :file:`atpneumatics_checkout.py`.


.. _ATHexapod-Fails-Out-of-Limits-Post-Condition:

Post-Condition
==============

- The ATHexapod and ATAOS CSCs are successfully in the ``ENABLED`` state.
- ATAOS corrections are enabled without causing faults to the CSCs.
- The ATCS system is fully operational and ready to proceed with observations or further procedures.


.. _ATHexapod-Fails-Out-of-Limits-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in `#summit-auxtel <https://rubin-obs.slack.com/archives/C07Q45NUK4P>`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
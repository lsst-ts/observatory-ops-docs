.. |author| replace:: *Andrés A. Plazas Malagón*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *none*

.. _LATISS-Master-Bias-Procedure:

###########################
LATISS Master Bias Generation Procedure
###########################

.. _LATISS-Master-Bias-Procedure-Overview:

Overview
========

The procedure to call scripts to produce a master bias for LATISS from the LSST Operations and Visualization Enviroment (LOVE) at the Summit :ref:`operational environment <Observing-Interface-Operational-Environments>` is almost identical to the :ref:`same procedure in the case of LSSTComCam <ComCam-Master-Bias-Procedure>`

Please consult and follow that procedure, keeping in mind the following potential differences:

- The OCS-Controlled Pipeline System (OCPS) should have been ``ENABLED`` for ``LATISS``.
- When login into LOVE, click on the ``ATQueue`` panel instead of ``MTQueue``.
- After clicking on the ``ATQueue`` panel, search for the script ``auxtel/make_latiss_bias.py`` under ``AVAILABLE SCRIPTS`` on the left.
- The configuration parameters are the same, but their values may differ. For example, ``n_detector: "(0)"`` (since there is only one detector), the butler repository may take the form ``repo: /repo/LATISS``, the input collections for verification and certification, ``LATISS/calib``, and the calibration collection may have a different name (e.g., ``LATISS/calib/u/plazas/YYYMMDD.test``).

Troubleshooting
===============

No troubleshooting information is currently available.

.. _LATISS-Master-Bias-Procedure-Conditions-Contact-Personnel:

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

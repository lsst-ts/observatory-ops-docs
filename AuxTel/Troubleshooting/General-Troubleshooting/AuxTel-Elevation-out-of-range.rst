.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *I. Sotuela*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Carlos Morales, Erik Dennihy*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-AuxTel-Elevation-out-of-range:
.. Each section should include a label for cross-referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with a reST object such as a title or figure, you must include the link with an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

######################################
AuxTel Elevation Out of range
######################################

.. _AuxTel-Elevation-out-of-range-Overview:

Overview
========

.. In one or two sentences, explain when this AT correct_pointing failure procedure needs to be used. Describe the symptoms that the user sees to use this procedure.

This procedure should be used when the AuxTel :file:`auxtel/correct_pointing.py` script fails with the error 

.. code-block:: text

    Rejected: elevation out-of-range.

.. _AuxTel-Elevation-out-of-range-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide a simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

- The :file:`auxtel/correct_pointing.py` script fails with the following error traceback:

    .. code-block:: text
       
       lsst.ts.salobj.base.AckError: msg='Command failed', 
       ackcmd=(ackcmd private_seqNum=942292490, ack=<SalRetCode.CMD_FAILED: -302>, 
       error=6611, result='Rejected : elevation out of range')

- This occurs when the target search in the :file:`auxtel/correct_pointing.py` script is not successful in the specified location in the sky within the `mag_limit`, `mag_range`, and `radius`.

.. _AuxTel-Elevation-out-of-range-Procedure-Steps:

Procedure Steps
===============

.. _AuxTel-Elevation-out-of-range-Step-1:

To resolve this error while running the :file:`auxtel/correct_pointing.py` script, follow these steps:

#. Try **widening the target search**. 

   Run :file:`auxtel/correct_pointing.py` with a configuration that represents a larger search area. 
   The script defaults are:
   
        .. code-block:: text
            :caption: :file:`auxtel/correct_pointing.py` default configuration
            
            az: 90.0
            el: 60.0
            mag_limit: 6.0
            mag_range: 4.0
            radius: 5

    
   You can adjust the above parameters to:
    
      * Decrease the `mag_limit` to target brighter sources.
      * Increase the search magnitude range (`mag_range`).
      * Increase the search `radius` in degrees.
      * Or a combination of the above.

#. If the script works, the pointing correction will center the target in the detector. 
     If the problem persists, proceed to steps 2.a - 2.b:
     
     a. Find a target using the standard script :file:`auxtel/track_target.py` with the following configuration:

         .. code-block:: text
            :caption: :file:`auxtel/track_target.py`

            find_target:
               az: 90.0
               el: 60:0
               mag_limit: 8.0


     b. Run the external script :file:`auxtel/correct_pointing.py` on the same area of the sky using the configuration. 
        Modify `az` and `el` accordingly:

         .. code-block:: text
            :caption: :file:`run_command.py`

            az: 90.0
            el: 60.0

#. Fill out the script failure information in the ticket `OBS-186 <https://rubinobs.atlassian.net/browse/OBS-186>`_ for record-keeping.

#. Verify that the AuxTel is functioning correctly and the targets are centered in the detector.

.. _AuxTel-Elevation-out-of-range-Post-Condition:

Post-Condition
==============

- AuxTel is properly pointed, with targets centered in the detector.
- System is ready for further observations.

.. _AuxTel-Elevation-out-of-range-Procedure-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in the `#summit-auxtel <https://lsstc.slack.com/archives/C01K4M6R4AH>`__ channel.

If the pointing is still not accurate, open a ticket to keep a record of the loss of pointing accuracy.
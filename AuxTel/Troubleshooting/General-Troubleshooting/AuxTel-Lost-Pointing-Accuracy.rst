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
.. _AuxTel-AuxTel-Troubleshooting-General-Troubleshooting-AuxTel-Lost-Pointing-Accuracy-Procedure:
.. Each section should include a label for cross-referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with a reST object such as a title or figure, you must include the link with an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#############################
AuxTel Lost Pointing Accuracy
#############################

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Overview:

Overview
========

This procedure should be used when the AuxTel loses pointing accuracy, causing targets to not appear centered in the detector during the first acquisition.

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Error-Diagnosis:

Error diagnosis
===============

.. This section should provide a simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

- Targets are not centered in the detector, appearing at the edge of the field or not in the field at all.
- The issue might occur if the :file:`auxtel/correct_pointing.py` script has not centered the right star.
- This can arise when two or more similar magnitude stars are present in the field, potentially confusing the script.
- The issue should be mitigated by using the bright star catalog, but sometimes SIMBAD returns a field with two or more bright stars that may cause mispointing.
- See `OBS-88 <https://rubinobs.atlassian.net/browse/OBS-88>`_ for some off-centered images examples.

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Procedure-Steps:

Procedure Steps
===============

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Step-1:

Target is still visible in the detector
---------------------------------------

If the bright WEP or spectroscopic target is visible in the detector, follow these steps:

#. Pause the ATScriptQueue.

#. Add a :file:`auxtel/correct_pointing.py` script to the queue and move it to the top of the waiting scripts. 
   
   Leave the configuration empty (defaults are `az`: 90, `el`: 60) or you can choose an area (`az`, `el`) of the sky by introducing new values.  
   You can also launch a wider target search by modifying the `mag_limit`, `mag_range`, or the search `radius`.

    .. code-block:: text
        :caption: :file:`auxtel/correct_pointing.py`

        az: 180
        el: 35
        mag_limit: 6.0
        mag_range: 4.0
        radius: 5.0

#. Play the ATQueue and while the script is running, confirm in the incoming RubinTV images that the right target is being centered.

#. If the pointing is lost again, repeat steps 1-3 with a different configuration, different location of the sky, or widen the search to ensure the target is appropriate for the :file:`correct_pointing` script.


No bright target is visible in the detector
-------------------------------------------

If the pointing is completely lost and no bright star is seen in the image, follow these steps:

#. Pause ATScriptQueue.
#. Recycle ATPtg by sending it to ``STANDBY``, and then back to ``ENABLED``. 
   This will erase all absorbed zero-point pointing offsets from before.

#. Add a :file:`auxtel/correct_pointing.py` script to the queue and move it to the top of the waiting scripts. 
   
   Leave the configuration empty (defaults are `az`: 90, `el`: 60) or you can choose an area (`az`, `el`) of the sky by introducing new values.  
   You can also launch a wider target search by modifying the `mag_limit`, `mag_range`, or the search `radius`.

    .. code-block:: text
        :caption: :file:`auxtel/correct_pointing.py`

        az: 180
        el: 55
        mag_limit: 8.0
        mag_range: 4.0
        radius: 5.0

#. Play the ATQueue and while the script is running, confirm in the incoming RubinTV images that the right target is being centered.

#. If the pointing is lost again, repeat steps 1-3 with a different configuration, different location of the sky, or wider search to ensure the target is appropriate for the :file:`auxtel/correct_pointing.py` script.

#. Verify that the AuxTel is functioning correctly and the targets are centered in the detector.

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Post-Condition:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Please provide screenshots of the software status or relevant display windows to confirm.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- AuxTel is properly pointed, with targets centered in the detector.
- System is ready for further observations.

.. _AuxTel-Lost-Pointing-Accuracy-Procedure-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in the `#summit-auxtel <https://lsstc.slack.com/archives/C01K4M6R4AH>`__ channel.

If the pointing is still not accurate, open a ticket with high priority to reflect the loss of pointing accuracy.

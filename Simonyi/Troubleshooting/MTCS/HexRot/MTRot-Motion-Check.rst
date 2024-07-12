.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Yijung Kang
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: Kshitija Kelkar

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTRot-Motion-Check:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

######################
MTRotator Motion Check
######################


.. _MTRot-Motion-Check-Overview:

Overview
========

.. This section should provide a brief, top-level description of the document's purpose and utilization. 

This procedure checks the motion of the MTRotator under nominal movements, issued independently 
from the MTQue or the MTRotator EUI.

.. _MTRotator-motion-check-script:

Using the `move_rotator` SAL script
===================================

Use the following configuration to run :file:`maintel/mtrotator/move_rotator.py` using the follwoing configuration 

.. code-block:: SAL
    :caption: move_rotator.p

    angle = <+ or - angle you want to move in degrees>

If this procedure fails, follow the next one using the MTRotator EUI 

.. _MTRotator-motion-check-eui:

Using the MTRotator EUI
=======================

MTRotator EUI Access
--------------------

#.  Enter *hexrot-vm02.cp.lsst.org* with your IPA account credentials.
    
#.  Once in the virtual machine, choose your user profile and enter your IPA password.

#.  Open a terminal from the 'Activities' tab on top left and go to the following - 

    .. prompt:: bash

        cd /rubin/
        cd rotator/
        cd build
        ./runRotEui

Moving the MTRotator point to point (p2p) 
-----------------------------------------

#.  To enable, ``State Cmd`` 
    is selected, :guilabel:`StateTriggers` menu shows ``Enable`` under and then click 
    :guilabel:`Send Command` button. 
    
#.  To move the MTRotator, go to the :guilabel:`Commands to Send` 
    section and in :guilabel:`Enabled Substate Triggers`, 
    choose ``Move``. Then, input ``0`` degrees in the :guilabel:`Position Cmd` field and 
    execute the movement by clicking on the :guilabel:`Send Command` button.

#.  If the MTRotator does not follow this -

    a.  transition to ``Standby`` state followed by the ``Enabled`` state again to reset the internal 
        calculation of Simulink model. Then, do the p2p movement to origin again.

    b.  It might also be possible that some internal signals are not triggered in Simulink module. 
        You can try to do the p2p movement to another point such as 1 or 2 degree position first. If the 
        MTRotator moves then you could move it back to the origin.

.. warning::
    MTRotator position should always be at 0 degrees in the ``Standby`` state.  

This procedure was last modified on |today|.
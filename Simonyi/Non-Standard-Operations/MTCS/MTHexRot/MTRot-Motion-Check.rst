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
from the *LOVE/MTQueue* or the MTRotator EUI. 

.. warning::

    This check cannot be accomplished if MTRotator is in ``FAULT`` on the CSC and/or with interlocks 
    activated on the :guilabel:`GIS` or the MTRotator EUI. Please refer to `MTRotator Recovery 
    Procedure <https://obs-ops.lsst.io/Simonyi/Troubleshooting/MTCS/HexRot/MTRotator-Recovery/MTRotator-Recovery.html>`_
    to clear these warnings before proceeding.    


.. _MTRotator-motion-check-script:

Using the :file:`maintel/mtrotator/move_rotator.py` SAL script
==============================================================

Use the following configuration to run :file:`maintel/mtrotator/move_rotator.py` on the *LOVE/MTQueue* using the following configuration 

.. code-block:: text
    :caption: :file:`maintel/mtrotator/move_rotator.py`

    angle = < +/ - angle you want the MTRotator to move (in degrees) >

If this procedure fails, follow the next one using the MTRotator EUI. 

.. _MTRotator-motion-check-eui:

Using the MTRotator EUI
=======================

MTRotator EUI Access
--------------------

#.  Enter the virtual machine that controls the rotator *hexrot-vm02.cp.lsst.org* with your IPA account credentials.
    
#.  Once in the virtual machine, choose your user profile and enter your IPA password.

#.  Open a terminal from the 'Activities' tab on top left - 

    a. First check that there are no processes running on the EUI by typing

        .. prompt:: bash

            ps -aux | grep "runRotEui"

        
        If processes are already running, you may need to identify who is running them and ask permission 
        to end one (or both) so you can run your own EUI session. If another :guilabel:`runRotEui` is 
        running then type the following to kill the existing process

        .. prompt:: 

            sudo kill -9 {pid}


    b.  Enter the :guilabel:`runRotEui` by typing 
    
        .. prompt:: bash

            cd /rubin/rotator/build/
            ./runRotEui


Moving the MTRotator point to point (p2p) 
-----------------------------------------

#.  On the MTRotator Client, under the :guilabel:`Main tab`, ``State Cmd`` 
    is selected, :guilabel:`StateTriggers` menu shows ``Enable`` under and then click 
    :guilabel:`Send Command` button. This enables the MTRotator.
    
#.  To move the MTRotator, go to the :guilabel:`Commands to Send` 
    section and in :guilabel:`Enabled Substate Triggers`, 
    choose ``Move``. Then, input ``0`` degrees in the :guilabel:`Position Cmd` field and 
    execute the movement by clicking on the :guilabel:`Send Command` button.

#.  If the MTRotator does not follow:

    a.  Transition to ``Standby`` state followed by the ``Enabled`` state again to reset the internal 
        calculation of Simulink model. Then, do the p2p movement to origin again.

    b.  It might also be possible that some internal signals are not triggered in Simulink module. 
        You can try to do the p2p movement to another point such as 1 or 2 degree position first. If the 
        MTRotator moves then you could move it back to the origin.


.. note::
    
    If you want to p2p move the rotator after the soak test, consider the following steps:

    a.  Issue a :guilabel:`Stop` command to MTRotator and wait for 5 min. This should make sure the internal queue of *track* commands from the soak test has been processed 
        by Simulink model totally.

        .. figure:: /Simonyi/Non-Standard-Operations/_static/MTRot-motion-check-1.png
            :name: MTRot-motion-check-1
            :scale: 40%

    b.  Check the controller :guilabel:`State` is ``Enabled State`` and the :guilabel:`Actuator Enabled Sub-Sate` is ``Stationary``.

        .. figure:: /Simonyi/Non-Standard-Operations/_static/MTRot-motion-check-2.png
            :name: MTRot-motion-check-2
            :scale: 50%

 
.. warning::
    MTRotator position should always be at 0 degrees in the ``Standby`` state.  

This procedure was last modified on |today|.
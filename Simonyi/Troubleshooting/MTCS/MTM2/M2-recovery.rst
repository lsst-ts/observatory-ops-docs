.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Kevin Fanning*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Yiyung Kang, Jacqueline Seron, Karla Peña*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _MTM2-Troubleshooting-M2-recovery:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#########################
M2 Recovery
#########################

.. ..  TO DO: CHECK internal links are working, and see if page on LOVE commands has a counterpart in obs-ops

.. _M2-recovery-Overview:

Overview
^^^^^^^^
.. In one or two sentences, explain when this troubleshooting procedure needs to be used. Describe the symptoms that the user sees to use this procedure. 

This procedure should be done when MTM2 goes to ``FAULT`` and **exits** the *closed-loop* state.

This step-by-step guide is the integration of the `Recovery system at night`_ and 
`Restart control system`_ procedures

.. _`Recovery system at night`:  https://ts-m2gui.lsst.io/error-handling/recover-system-night.html

.. _`Restart control system`: https://ts-m2gui.lsst.io/error-handling/error-handling.html#lsst-ts-m2gui-error-restart-control-system



.. admonition:: Information

    **MTM2 possible states** or control modes are *Idle*, *TelemetryOnly (Disabled)*, *Open Loop*, *Closed Loop*. 
    Each state is indicated by an integer from 1 to 4.

    .. _M2-recovery-check-M2-state:

    You can check the MTM2 state in Chronograf dashboards `MTM2 dashboard`_ or  `LOVE view`_, once you are signed in.

    A GIS interlock prevents TMA movement if MTM2 is not in the *closed-loop* state. 
    
    .. figure:: _static/MTM2-recovery-M2-states-in-chronograf.png
        :width: 600

        MTM2 states in Chronograf

.. admonition:: Important

    MTM2 should always be in the *closed-loop* state (state 4) for the safety of the glass. 



.. _`M2 state`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/296?refresh=Paused&lower=now%28%29%20-%2015m 
 

.. _`MTM2 dashboard`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/34?refresh=Paused&lower=now%28%29%20-%2015m

.. _`Love view`: https://summit-lsp.lsst.codes/love/uif/view?id=99  

.. maybe what is in info block should be in a MTM2 introduction page. But until we have one it can be here.
.. In Force Balance = enable in LOVE M2 view or State = 4 in chronograph. 
.. https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/231?refresh=Paused&lower=now%28%29%20-%2015m link to chronograph


.. note::
    Any fault in MTM2 is worth ticketing, this is not a system that should reach a ``FAULT`` state easily.


.. _M2-recovery-Error-Diagnosis:

Error diagnosis
^^^^^^^^^^^^^^^
.. This section should provide simple overview of known or suspected causes for the error.
.. It is preferred to include them as a bulleted or enumerated list.
.. Post screenshots of the error state or relevant tracebacks.

MTM2 CSC goes to ``FAULT`` and exits the *closed-loop* control (:ref:`check M2 state <M2-recovery-check-M2-state>`).

     .. figure:: _static/MTM2-recovery-MTCS-M2-FAULT.png
        :width: 600
   
        MTM2 CSC in ``FAULT`` state

Follow these instructions to investigate the state of MTM2 and identify the cause in the Chronograf `MTM2 dashboard`_. 

Check the following items:

#. **Power Current**: 
     This will indicate when MTM2 exited the *closed-loop* state (as shown in the image below, the magenta line sharply drops at approximately 19:38).
     
     .. figure:: _static/MTM2-recovery-power-current.png
        :name: MTM2 Power current
        :width: 600
       
        MTM2 Power current

#. **TMA Elevation Position and Elevation Angle measured by M2**: 
     To ensure that they are at the same position after exiting the *closed-loop* state (note time displacement in plots).

     .. figure:: _static/MTM2-recovery-elevation-by-M2.png
        :width: 600

        MTM2 Elevation position

#. **Tangent Fault**: 
     It may indicate excessive forces were the cause of the fault.

     .. figure:: _static/MTM2-recovery-tangent-fault.png
        :width: 600

        MTM2 Tangent fault


#. **Log Message**:  
     It may display useful information about the cause.

     .. figure:: _static/MTM2-recovery-log.png
        :width: 100%

        MTM2 Log message


.. note::

    Log your observations on the cause and add comments to a Jira ticket (either existing or one you create). Include any unique activities occurring when the fault happened as MTM2 is not expected to fault.
 
.. _`OBS-416` : https://rubinobs.atlassian.net/browse/OBS-416


.. _M2-recovery-Procedure-Steps:

Procedure Steps
^^^^^^^^^^^^^^^

.. _`1password`: https://lsstit.1password.com/signin
.. _`Reset the M2 interlock signal`: https://ts-m2gui.lsst.io/error-handling/error-handling.html#lsst-ts-m2gui-error-reset-m2-interlock-signal



#. Restart control system.
    .. warning::
        This step must not be skipped. 
        Restarting the control system acts as a catch-all for resetting issues. Failing to do so may also cause issues with telemetry.

    #. **Connect** to the admin user on M2 cRIO controller via ssh using the username and password found in `1password`_ MainTel vault.
         .. note::

         There are 2 cRIO controllers in the summit. Depending on the location of M2, run the command:

         .. admonition:: If M2 is at the TMA:

            .. code-block:: shell

               ssh admin@m2-crio-controller01.cp.lsst.org

         .. admonition:: If M2 is on level 3:

            .. code-block:: shell

               ssh admin@m2-crio-controller02.cp.lsst.org


    #. **Stop the control system** and wait 3 minutes using the command:
         .. code-block:: shell

            /etc/init.d/nilvrt stop

    #. **Start the control system** and wait 3 minutes using the command: 
         .. code-block:: shell
            
            /etc/init.d/nilvrt start
        
         You may press enter to regain your shell prompt when you see the following "Welcome to LabVIEW Real-Time 18.0". It may take several minutes.

         .. figure:: _static/MTM2-recovery-restart-control-system.png
            :width: 600

            Restarting MTM2 control system

    .. _M2-recovery-Reset-the-M2-interlock-signal: 

#. `Reset the M2 interlock signal`_ in GIS main cabinet on level 2, even if the state is "OK".
     .. Important::

        Note that all status boxes for the M2 actuator will appear green. This indicates the status of the relay that enables power to the systems, not the status of M2 itself. Therefore, **after an interlock or power cycling**, it is necessary to press the :guilabel:`RESET` button.

#. Use python EUI to change MTM2 to *closed-loop* state:
     #. Open the **MTM2 EUI**. Follow instructions :ref:`to access the MTM2 EUI <Simonyi-Components-Simonyi-EUI-Access>`.

     #. Establish **local control** by pressing :guilabel:`connect`, then :guilabel:`local`. 
         Note that :guilabel:`local` may be greyed out after connecting, this is normal.

         .. figure:: _static/MTM2-recovery-GUI-open-connect.png
            :width: 600
            :align: center

            MTM2 GUI open and connect

     #. Pull up the **Overview widget** by double-clicking on :guilabel:`Overview` in the list at the bottom of the EUI.
         .. figure:: _static/MTM2-recovery-GUI-overview.png
            :width: 600
            :align: center

            MTM2 GUI Overview

         a. Check the **Enabled Faults Mask**. 
             It should **not be 0**. If it is, repeat `Reset the M2 interlock signal`_.
             
             .. note::
                
                It is ok if the ``isInterlockEngaged`` indicator is red.  

                .. the original said isInterlockEnabled

         b. Look at **Alarms/Warnings** widget to see active alarms (red) or warnings (yellow). 
             If active, reset them with :guilabel:`Reset All Items`. 
        
             *Make sure you have removed the fault condition*.

             .. figure:: _static/MTM2-recovery-GUI_alarms-warnings.png
                :width: 100%
                :align: center

                GUI Alarms and warnings widget

             If **Reset All Items** does not work, you maybe have to :ref:`power cycle M2 cabinet <M2-Non-standard-Procedures-Power-cycle-MTM2-cabinet>`. 
             *Only do this if there are no other options!*

     #. Switch to :guilabel:`Diagnostic` mode. Be patient; this may take some time.

     #. Switch to  :guilabel:`Enabled` mode. This may take up to 2 minutes. If this step fails, you may have to repeat `Reset the M2 interlock signal`_ instructions.

     #. :guilabel:`Enter closed-loop control`.

#. Return to **Standby mode** in the EUI to close the GUI by **pressing the following buttons**:
     a. :guilabel:`Enter open-loop control`.

     b. :guilabel:`Diagnostic` mode, this usually takes ~30s.

     c. :guilabel:`Standby` mode, this usually takes ~30s.

     d. :guilabel:`Remote` mode, to allow CSC control of M2.
     
     e. :guilabel:`Disconnect` EUI on the top tool bar, this usually takes ~30s.
    
     f. :guilabel:`Exit` on the top tool bar.

#. Change the status of MTM2 CSC from ``DISABLED`` to ``ENABLED``. 
     If the attempt fails, try again, but first set it to ``STANDBY``. Each transition is expected to take approximately 2 minutes. 
    

#. Check that M2 in under *closed-loop* control **4** in Chronograf M2 dashboard.
     If needed, set *closed-loop* control by running the script :file:`standardscripts/maintel/m2/enable_closed_loop.py`, without configuration. This can be done even if you are already under *closed-loop* control.


.. _`LOVE MT Useful lower-level command scripts + configurations`: https://confluence.lsstcorp.org/pages/viewpage.action?pageId=239409017


.. _M2-recovery-Condition-A-for-Step-4: 


Post-Condition
^^^^^^^^^^^^^^

- MTM2 is in ``ENABLED`` state. 
- MTM2 is in *closed-loop* state (4).

     .. figure:: _static/MTM2-recovery-MTCS-all-enabled.png
        :width: 600
   
        MTM2 CSC in ``ENABLED`` state


     .. figure:: _static/MTM2-recovery-M2-state-chronograf.png
        :width: 600

        MTM2 state in *closed-loop* (4) in Chronograf

.. note::

    There will be an indicator added in the MTM2 `LOVE view`_ (see that it is missing in the image below), check `LOVE-300`_.

    .. figure:: _static/MTM2-recovery-LOVE-M2.png
        :width: 600

        MTM2 display in LOVE

.. _`LOVE-300`: https://rubinobs.atlassian.net/jira/software/c/projects/LOVE/issues/LOVE-300

.. _M2-recovery-Contingency:

Contingency
^^^^^^^^^^^

If you are unable to find the fault, 
check the cRIO controller log that contains detailed report faults. 
These logs are found in the :command:`/u/log/` directory. 

* Use the command :command:`ls -lrt` to list logs, with the most recently modified logs displayed at the bottom. Logs are named according to their creation date and time.

* Grab error messages from the log with a command like :command:`grep -nr "error" name_of_log_here`

    .. figure:: _static/MTM2-recovery-log-cRIO.png
       :width: 100%

       Checking the cRIO log


.. _M2-recovery-log-info:

.. rubric:: Get information from log

.. code-block:: shell

    ls -lrt # list times in directory, in a list, sorted by time, in reverse order (newest on bottom)
    grep -nr "error" {logname} # List lines from file {logname} containing error
    cat {logname} # print the log file to terminal, sometimes these are short and in the event of a fault, interesting lines are at the bottom


If the procedure was not successful, report the issue in `#summit-simonyi`_ and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.

.. _`#summit-simonyi` : https://lsstc.slack.com/archives/C04HULH5HHD
.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Kris Mortensen*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Vent-Gate-Extraction-Fan-Operation:

######################################
Vent Gate and Extraction Fan Operation
######################################

.. _Vent-Gate-Extraction-Fan-Operation-Overview:

Overview
========

This procedure describes how to operate the AuxTel vent gate and extractor fan—both remotely via the ATBuilding CSC 
and, when needed, using local manual controls—to ventilate the AuxTel enclosure in preparation for and during on‑sky operations. 

By opening vent gate #3 and running the extraction fan within defined wind and humidity limits, 
observers can flush warm, stagnant, or moist air from the enclosure and promote a more stable internal environment, 
reducing dome seeing and thermal gradients that degrade image quality.

.. admonition:: Weather Constraints
    :class: warning

    Operation of the vent gate is dependent on the :ref:`AuxTel weather constraints <Observing-Constraints-AuxTel-Weather-Constraints>`. 
    In general, only operate the vent gate when:

    *  Wind speeds are :math:`< 10` m/s.
    *  Relative humidity is :math:`< 70\%`.

.. _Vent-Gate-Extraction-Fan-Operation-Precondition:

Precondition
============

-  Before taking the decision to open the vent gate, review the weather conditions and :ref:`weather constraints <Observing-Constraints-AuxTel-Weather-Constraints>` page.

-  AuxTel is fully ready to operate and all components are enabled. 

-  The :ref:`daytime checkout <AuxTel-DayTime-Operations-Daytime-Checkout>` has been executed successfully. 

-  Observers will begin :ref:`venting AuxTel <AuxTel-Daytime-Operations-Prepare-for-vent>` or  
   :ref:`on-sky preparations <AuxTel-Nighttime-Operations-Open-for-On-Sky-Operations>`.

.. _Vent-Gate-Extraction-Fan-Operation-Post-Condition:

Post-Condition
==============

- If venting AuxTel, vent gate is open and extraction fan is on. 
- If preparing on-sky operations, vent gate is closed and extraction fan is off.

.. _Vent-Gate-Extraction-Fan-Operation-Procedure-Steps:

Procedure Steps
===============

.. note::

    Monitor each step in the procedure using the 
    `ATBuilding Chronograf Dashboard <https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/462?refresh=Paused&lower=now%28%29%20-%2015m>`_.

.. _Vent-Gate-Extraction-Fan-Operation-CSC-Control:

Set CSC Control
---------------

1.  Verify that ATBuilding CSC is ``ENABLED``. If not, enable it using either LOVE's 
    `ASummaryState <https://summit-lsp.lsst.codes/love/uif/view?id=51>`_
    or with the :file:`set_summary_state.py` script in 
    `ATQueue <https://summit-lsp.lsst.codes/love/uif/view?id=41>`_.

    .. code-block:: python
        :caption: set_summary_state.py

        data:
            - [ATBuilding, ENABLED]

2.  Change control of ATBuilding from *Manual* to *CSC* using the :file:`run_command.py` script
    with the following configuration:

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: setExtractionFanManualControlMode
        parameters:
           enableManualControlMode: False
    
    Check on Chronograph that the ``Extraction Fan Control Mode`` is now set to ``CSC``.

.. _Vent-Gate-Extraction-Fan-Operation-Prepare-Venting:

Prepare for Venting
-------------------

1.  Open vent gate #3, and confirm on Chronograf that the vent gate state
    transitions from ``CLOSED`` to ``PARTIALLY_OPEN``.

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: openVentGate
        parameters:
           gate: [2, -1, -1, -1]

    .. note::

        The array consists of four elements, corresponding to the four vent gates. 
        To operate a specific gate, add its ID 
        (gate IDs are numbered from 0-3, counter-clockwise from the front entrance door). 
        If no gate operation is needed, use -1 as a placeholder.

2.  Turn on the extraction fan at vent gate #3, and set the target frequency to 20Hz.

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: setExtractionFanDriveFreq
        parameters:
           targetFrequency: 20


.. _Vent-Gate-Extraction-Fan-Operation-Stop-Venting:

Stop Venting
------------

1.  Turn of the extraction fan at vent gate #3 by setting the target frequency to 0Hz.

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: setExtractionFanDriveFreq
        parameters:
           targetFrequency: 0

2.  Close vent gate #3, and confirm on Chronograf that the vent gate state
    transitions from ``PARTIALLY_OPEN`` to ``CLOSED``.

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: closeVentGate
        parameters:
           gate: [2, -1, -1, -1]


.. _Vent-Gate-Extraction-Fan-Operation-Manual-Control:

Set Manual Control
------------------

1.  Change control of ATBuilding from *CSC* to *Manual* using the :file:`run_command.py` script
    with the following configuration:

    .. code-block:: python
        :caption: run_command.py

        component: ATBuilding
        cmd: setExtractionFanManualControlMode
        parameters:
           enableManualControlMode: False
    
    Check on Chronograph that the ``Extraction Fan Control Mode`` is now set to ``Manual``.

2.  Set the ATBuilding CSC to ``STANDBY`` using either LOVE's 
    `ASummaryState <https://summit-lsp.lsst.codes/love/uif/view?id=51>`_
    or with the :file:`set_summary_state.py` script in 
    `ATQueue <https://summit-lsp.lsst.codes/love/uif/view?id=41>`_ .

    .. code-block:: python
        :caption: set_summary_state.py

        data:
            - [ATBuilding, STANDBY]



.. _Vent-Gate-Extraction-Fan-Operation-Troubleshooting:

Troubleshooting
===============

     No troubleshooting information is applicable to this procedure.

- This is an example bullet (If the following error is given during :ref:`Step 5 <Title-of-Procedure-Final-Step>`, resolve it using a specified action.)
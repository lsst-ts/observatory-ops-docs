.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Carlos Morales*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *OS Team*

.. Links

.. _`LSSTCam Cryo Dashboard`: https://summit-lsp.lsst.codes/chronograf/sources/1/dashboards/572?refresh=Paused&lower=now%28%29%20-%2015m

.. _Daytime-Operations-LSSTCam-Cooling-and-Vacuum-Checkout:

###########################
Cooling and Vacuum Checkout
###########################

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Overview:

Overview 2
========

This procedure verifies that the LSSTCam cooling chain and cryostat vacuum are stable
before you take the camera under Observatory Control System control.
It covers the refrigeration plant, the heat exchangers, the Dynalene loop that cools the Utility Trunk,
the Cold Plate and Cryo Plate, and the cryostat and HEX vacuum.

Read every quantity against its recent history, not only against a limit.
A prolonged loss of refrigeration can degrade the vacuum,
which forces a full warm up, the connection of turbo pumps,
and a recovery that can take a week or more.
Active monitoring exists to catch a trend before the automatic protections act.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Precondition:

Precondition
============

-  You have access to Chronograf and to the *LSSTCam Utility and State Monitoring Dashboard*.
-  You have access to CCS Web Trending and the Big Plot.
-  You can read *#cam-operator* and *#cam-summit-ccs-alerts*.

.. note::

    The *LSSTCam Utility and State Monitoring Dashboard* is the preferred view for this procedure.
    The `LSSTCam Cryo Dashboard`_ carries hard coded closure limits for the camera cooling
    and cryo systems, and is the dashboard referenced by the
    :ref:`Simonyi weather constraints <Observing-Constraints-Simonyi-Weather-Constraints>`.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Post-Condition:

Post-Condition
==============

-  Every cooling and vacuum quantity is stable, or its change is explained.
-  Compressors that are intentionally off are identified.
-  Current vacuum values are recorded for comparison with the next shift.
-  Any deviation is reported to the Camera Team, and recorded in the handover.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Procedure-Steps:

Procedure Steps
===============

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Review-State:

Review General State and Communications
---------------------------------------

Complete this review before you run any command.

#. Read the handover from the previous shift.

#. Review *#cam-operator* for:

   -  Active Camera Team work.
   -  Compressors that are intentionally off.
   -  Recent changes to glycol, Dynalene, or the PCS.
   -  Systems locked by another user.

#. Review *#cam-summit-ccs-alerts*.

#. Confirm that no engineering intervention is active.

A CCS alert can indicate a condition that needs urgent action,
or a protective action that the system has already taken.
Correlate the alert with CCS and Chronograf telemetry,
and with what is reported in *#cam-operator*.

.. warning::

    If an alert is not known, is not documented as benign, or you do not understand its cause,
    do not continue by clearing it.
    Contact the Camera Team.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Cooling-System:

Verify the Cooling System
-------------------------

Open the Big Plot with an initial range of about **3 hours** and about **200 bins**.
Widen the range to 24 hours, or to several days, to inspect slow trends.

The Big Plot confirms short term stability.
Curves stay flat, or oscillate periodically in a way that is consistent with previous days.
Explain any significant deviation.

.. warning::

    Treat any quantity that changes rapidly, or that falls to zero for more than one minute
    without a known explanation, as an emergency.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Glycol:

PCS Chiller and Glycol Supply
-----------------------------

Check ``GlycChillerIn``, ``GlycChillerOut``, ``GlycInputFlow``,
and the internal ``chiller/Maq20/*`` telemetry.

.. list-table:: Glycol Supply Criteria
   :widths: 30 40 30
   :header-rows: 1

   * - Parameter
     - Expected condition
     - Action
   * - Glycol flow to the PCS
     - Above 2 gal/min, and stable
     - Normal
   * - Glycol flow between 1 and 2 gal/min
     - Low against the nominal checkout
     - Report and escalate
   * - Glycol flow below 1 gal/min
     - Emergency
     - Report immediately
   * - ``GlycChillerOut``
     - Below 35 degrees C
     - Escalate if it rises or changes without explanation
   * - Supply and return temperatures
     - Stable against the previous shift
     - Report rapid changes

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Compressors:

Cryo Compressors
----------------

Inspect the ``refrig/Cryo*/*`` subplots, together with ``SuctionPrs`` and ``DischrgPrs``,
and determine which compressors are running.

.. list-table:: Compressor State Indications
   :widths: 20 80
   :header-rows: 1

   * - State
     - Approximate indication
   * - On
     - High discharge pressure, around 300 psi
   * - Off
     - Discharge and suction similar, around 10 psi

One compressor is normally off on purpose, and which one it is can change.
Always confirm the current state in *#cam-operator*.
Do not assume that a compressor that is off is a failure
until you have checked the known operational state.

For each operational compressor:

#. Verify that ``DischrgPrs`` is stable.

#. Verify that ``SuctionPrs`` is stable.

#. Compare both against the previous shift.

#. Report any change, jump, or trend.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-HEX:

HEX Temperatures
----------------

In ``hex/Cryo*/*``, check the temperature of each operational circuit, ``HexRtrnTmp``,
and that the periodic behavior is consistent.

HEX temperatures stay stable for every active circuit.
A large change can correspond to a circuit being turned on or off.
If that explanation does not exist, report it as an emergency.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Dynalene:

Dynalene and Utility Trunk
--------------------------

Check ``CoolPipeSplyTemp``, ``CoolPipeRetnTemp``, ``CoolFlowRate``,
and the ``utilitytrunk/UT`` subplots.

The Dynalene loop removes heat from the warm Utility Trunk electronics.
Its temperatures normally oscillate,
so note the mean value for the day and record it in the handover,
then use it to detect later deviations.

-  A small, consistent oscillation is normal.
-  Report a sudden change in temperature or flow.
-  For an unexpected drop in fan speed, check *#cam-operator* first.
   If it was not an intentional action, report it as an emergency.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Cold-Plate:

Cold Plate
----------

Check ``thermal/Cold_Temp/*`` and ``AvgColdTemp``.
The Cold Plate is expected between **-35 and -40 degrees C**, and stable, with no rapid change.

The Cold Plate cools the readout electronics through the PCS.
A rising trend can indicate degradation or loss of PCS cooling.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Cryo-Plate:

Cryo Plate
----------

Check ``AvgCryoTemp``, the sensors distributed over the Cryo Plate, and the trim heater power.

.. list-table:: Cryo Plate Guideline Values
   :widths: 40 60
   :header-rows: 1

   * - Quantity
     - Guideline
   * - ``AvgCryoTemp``
     - Near -123.5 degrees C
   * - Individual Cryo Plate sensors
     - About -127 to -118 degrees C
   * - Behavior across circuits
     - Stable

For the cryo trim heaters:

-  Compare the power against the previous day.
-  Report variations larger than **10 W**.
-  Report a drop toward the **10 W** range, because it can indicate a loss of cooling capacity.

.. important::

    Do not interpret an isolated value without reviewing the recent history.
    Setpoints, the number of active circuits, and normal levels can all change.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Vacuum:

Cryostat and HEX Vacuum
-----------------------

Check ``CryoVac`` and ``HexVac``.

#. Record the current value, and compare it against the previous day.

#. Report **any** trend, even a small one.

#. Treat a value above **1e-7 torr** as an emergency.

#. A single burp or spike that returns immediately to the previous level can be ignored,
   but verify that it has genuinely recovered.

.. _LSSTCam-Cooling-and-Vacuum-Checkout-Troubleshooting:

Troubleshooting
===============

-  If a cooling or vacuum quantity is outside the values above, or shows an unexplained trend,
   report it to the Camera Team in *#cam-operator*, and follow the
   :ref:`escalation criteria <LSSTCam-Monitoring-Escalation-Criteria>`.

-  Do not restart chillers or cryo compressors, and do not change setpoints,
   without instructions from the Camera Team.

-  If the condition impairs data taken on sky, file a
   :ref:`fault report <Daytime-Nighttime-Interactions-fault-reporting>`.

This procedure was last modified on |today|.

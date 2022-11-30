.. |author| replace:: *Parker Fagrelius*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Patrick Ingraham*

.. _control-at-calib-illumination-system-AuxTel-Calibration-Illumination-System-Control-Procedure:

########################################################
AuxTel Calibration Illumination System Control Procedure
########################################################


Overview
========

.. note:: The AuxTel Calibration Illumination System is not yet installed. It should be ready to use by Dec. 9, 2022.

The AuxTel Calibration Illumination system is described in https://tstn-032.lsst.io. It is used to illuminate the white calibration screen mounted inside the AuxTel dome. The wavelength of the illumination can be changed to any wavelength between 300 and 1150 nm. Within the system, we can monitor the wavelength and relative brightness of the illumination during an exposure. 

There are no scripts written for this system yet. Everything will have to be completed in notebooks until there is agreement on how it will be used.

Here, I describe the parts of the system that can be controlled. Please see these notebooks for examples:

- https://github.com/lsst-tstn/tstn-032/blob/main/_static/AuxTelCalIll_FunctionalTest.ipynb
- 

Components
==========
Each of the components described below is controlled by one CSC. The XML is linked for reference

White Light Source
------------------
This is the big light bulb that produces the light. 

Check out the `XML <https://ts-xml.lsst.io/sal_interfaces/ATWhiteLight.html>`__ and `Tech Note 36 <https://tstn-036.lsst.io>`__ for information on the hardware that controls the White Light Source. 

.. note:: There is a 15 minutes warmup and cooldown time for the White Light Source. It should not be turned on and off quickly.

* **Chiller:** Before turning on the lamp, the chiller needs to be turned on. You can change the temperature. 

.. code-block:: py
   :name: chiller

   await WhiteLightSource.cmd_setChillerTemperature.set_start(temperature=20)
   await WhiteLightSource.cmd_startChiller.set_start()

* **Output Power:** Set the output power with the turnLampOn command. Power can be set from 800 to 1200 W.

.. code-block:: py
   :name: power

   await WhiteLightSource.cmd_turnLampOn.set_start(power=800)
   await WhiteLightSource.cmd_turnLampOff.set_start(force=True)

* **Shutter:** You must open the shutter when beginning. Close the shutter at the end of the calibration to keep out dust. The shutter does not move quickly

.. code-block:: py
   :name: shutter

   await WhiteLightSource.cmd_closeShutter.set_start()
   await WhiteLightSource.cmd_openShutter.set_start()

Monochromator
-------------
This changes the wavelength of the light.

Check out the `XML <https://ts-xml.lsst.io/sal_interfaces/ATMonochromator.html>`__ 

* **Grating:** There are two gratings, optimized for different wavelength ranges. Grating 0 should be used for 300 - 550nm. Grating 1 should be used for 550 - 1150 nm

.. code-block:: py
   :name: grating

   atmonochromator.cmd_selectGrating.set_start(gratingType=grating)

* **Wavelength:** Wavelength can be changed in 1nm steps from 300 to 1200 nm 

.. code-block:: py
   :name: wavelength

   atmonochromator.cmd_changeWavelength.set_start(wavelength=wave)

* **Slit Widths:** There is an entry and exit slit. Both can be moved from 0 - 5 mm (not including 5 mm).

.. code-block:: py
   :name: slits

   await atmonochromator.cmd_changeSlitWidth.set_start(slit=1, slitWidth=entry_width)
   await atmonochromator.cmd_changeSlitWidth.set_start(slit=2, slitWidth=exit_width)

Electrometer
------------
This is how the relative brightness of the beam can be tracked.

Check out the `XML <https://ts-xml.lsst.io/sal_interfaces/Electrometer.html>`__

* Use it in "Current mode" [1]
* Take a measurement like this:

.. code-block:: py
   :name: electrometer

   await electrometer.cmd_startScan.set_start(timeout=10)
   await asyncio.sleep(exp_time)
   await electrometer.cmd_stopScan.set_start(timeout=10)

* The way we get the data is being updated, but will be similar to the fiber spectrograph.

Fiber Spectrograph
------------------
This is how the wavelength of the output light is tracked

Check out the `XML <https://ts-xml.lsst.io/sal_interfaces/FiberSpectrograph.html>`__

* Data is saved in the lfa
* Sample data taking:

.. code-block:: py
   :name: fiber-spectrograph

   wait FiberSpectrograph.cmd_expose.set_start(duration=exp_time, numExposures=1)
   lfa = await FiberSpectrograph.evt_largeFileObjectAvailable.next(flush=False, timeout=10)
   filename=lfa.url.split('FiberSpectrograph')[-1]

Contact Personnel
=================

This procedure was last modified on |today|.

This procedure was written by |author|.
The following are contributors: |contributors|.

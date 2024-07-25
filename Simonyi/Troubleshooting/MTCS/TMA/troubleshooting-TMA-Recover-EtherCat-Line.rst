.. This is a template for troubleshooting when some part of the observatory enters an abnormal state. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Name-of-Primary-Author*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *List-of-contributors*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _TMA-Recover-EtherCat-Line:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

#########################
TMA Recover EtherCat Line
#########################

.. _TMA-Recover-EtherCat-Line:

Overview
========

This guide addresses the frequent issue of some systems on the TMA becoming non-responsive due to EtherCAT communication interface problems. 
It provides a detailed procedure for resetting the EtherCAT interface, focusing primarily on the main TMA cabinet. 
By following this guide, users can restore the responsiveness of critical systems, ensuring continuous operation even when specialized support is unavailable.

.. _Title-of-Troubleshooting-Procedure-Error-Diagnosis:

Error diagnosis
===============

Some set of systems on the TMA could be non-responsive in some ocasions. 
In these cases the ethercat communication interface must be reset to regain connection to these systems. 
This is often done by the day crew when needed, or by Tekniker/Phase support when on site. 
Observers knowing and following this procedure can help rescue nights when additional support is not available.

A non exhaustive list of systems that may not be responsive as a result of ethercat issues are:

- Az/El Drives
- Thermal Systems
- Limit Switches (will show as active when they are not)
- Inclinometer
- Power Supply
- More...

Typically it is sufficient to reset the ethercat in the TMA main cabinet. 
On rare occasions (once in current knowledge), ethercat in other cabinets may need to be reset. 
Different systems not responding may be indicative of which cabinet this procedure needs to be performed in.


Solution
========

.. admonition:: Important

    Ethercat can be reset for different systems in different TMA cabinets. 
    This guide covers the main TMA cabinet where it most commonly must be reset. 
    Similar steps may be used for other cabinets.

.. admonition:: Definition

    This guide uses the term RJ45, the formal name for the connector of an ethernet cable. 
    This is used to avoid incorrectly calling a connection "ethercat" or "ethernet" which both use RJ45 connectors.



#. **Lock out the TMA**: follow (TMA LOTO GUIDE PAGE) for this procedure
#. **Head up to the main TMA cabinet**: This can be found on level 8, on the TMA. If on the side of the TMA with the stairs up to the deploy able platforms, it is on the left on the other side of the corner.

   a. Next to the cabinet is the physical TMA Tekniker Support Computer (tma-pc01.cp.lsst.org).

#. **Connect to TMA Tekniker Support Computer**: details for this can be found in 1password.

   a. Typically the monitor is turned off to prevent stray light. You may need to turn it on. Remember to turn it off when you are done!

   b. Alternatively you may use your laptop and Microsoft Remote Desktop (available for Mac as well) to connect to this computer. More details on 1password.

#. **Identify dark green Ethernet cable connected to the support computer**: this cable plays a pivotal role in the reset of the procedure.

   a. The cable is a darker green from the other ethercat ethernet cables which are a pale green.

   b. This cable connects to a "Moxa" switch in the right section of the cabinet

   c. The cable goes through a hole in the floor of the cabinet and out to connect to the support PC.

   d. Remember its original slot in the switch, it will be returned here at the end of this procedure.

      .. figure:: ./_static/cable-1.png
          :name: Cable-1
          :scale: 20 %

          Dark green ethernet cable.


#. **Connect the support PC directly to the Phoenix Connect remote IO input**

   a. Identify the location of the Phoenix Connect system. It is in the center section of the cabinet, below the Bosch controller. It has Phoenix Connect branding and two RJ45 connectors on it.

   .. caution:: 

    Ensure that the existing RJ45 connection on the Phoenix Connect are tight by gently pushing them in.

   b. Disconnect the Support PC ethernet cable from the Moxa switch and move it to the middle section of the cabinet (an extra hand to hold it can be helpful)

   c. Replace the blue, upper RJ45 connection on the Phoenix Connect with the Support PC ethernet cable.

      .. figure:: ./_static/cable-2.png
          :name: Cable-2
          :scale: 20 %

          Phoenix Connect system.


#. **Reset Ethercat from the TMA Support PC**

   a. Open the PowerSupplyAndIOs project in TwinCAT software on the PC

   b. Click "restart TwinCAT System"


      .. figure:: ./_static/screen-1.png
          :name: Screen-1

          TwinCAT System


   c. Check that all is perfect

      .. figure:: ./_static/screen-2.png
          :name: Screen-2

          PowerSupplyAndIOs


   d. Trial license may need to be renewed during this step — see appendix

#. **Re-activate System in NI manager and TwinCAT**

   a. On the Phoenix Connect, replace the green support PC ethernet connection with the original blue RJ45 connection

   b. DO NOT return the green support PC ethernet to its original position yet!

      .. figure:: ./_static/cable-3.png
          :name: Cable-3
          :scale: 20%

          Green ethernet cable


   c. You may hear audible clicks in the cabinet

   d. Change 139.229.171.3 to active in NI Distributed System Manager software on Support PC

      .. figure:: ./_static/screen-3.png
          :name: Screen-3

          NI Distributed System Manager 


   e. Configure ethercat in TwinCAT software (blue box in upper left)

      .. figure:: ./_static/screen-4.png
          :name: Screen-4

          TwinCAT

#. **Disable and Re-enable Integrated Ethernet Network Interface Card in windows network settings**

   a. Open network settings in windows, can be accessed through the wifi symbol in the lower right corner

   b. Go to ethernet and click on "Cambiar Opciones del adaptador" to open up control panel version of the app

   c. Right click on the IntegratedEthernet adaptor

   d. Click Desactivar

   e. Right click again after a brief wait

   f. Click Activar

      .. figure:: ./_static/screen-5.png
          :name: Screen-5

          Windows network settings

#. **Return Support PC ethernet cable to its original position**

   .. figure:: ./_static/cable-1.png
          :name: Cable-1
          :scale: 20 %

          Returning ethernet cable.


#. **Ethercat should be reset and systems should be responsive now. If they are not, double check that the RJ45 connections to the Phoenix Connect are tight and try again.**


Appendix
========

#. Renew trial license on TwinCAT

   .. figure:: ./_static/screen-6.png
          :name: Screen-6

          TwinCAT

#. Pier 6 cabinet pictures

   a. Cabinet

      .. figure:: ./_static/cabinet-1.png
          :name: Cabinet-1
          :scale: 20 %

          Cabinet

   b. Level 6 Phoenix Connect

      .. figure:: ./_static/cabinet-2.png
          :name: Cabinet-2
          :scale: 20 %

          Level 6 Phoenix Cabinet

.. _Title-of-Troubleshooting-Procedure-Contingency:

Contingency
===========

If the procedure was not successful, report the issue in [relevant Slack channel] and/or activate the :ref:`Out of hours support <Safety-out-of-hours-support>`.
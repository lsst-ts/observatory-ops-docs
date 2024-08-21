.. This is a template for an informative/general use document. 

.. Review the README in this document's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: Kshitija Kelkar
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: 

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Templates-Informative-Document:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

################################################################
Power Distribution Unit (PDU) Outlet Mapping for MTCS components
################################################################


.. _PDU-Outlet-Mapping-Access:

Accessing the PDU 
=============

#.  While in the LSST-WAP or summit VPN, connect to `https://tea-pdu01.cp.lsst.org/ <https://tea-pdu01.cp.lsst.org>`_ 
    using the credentials stored in the Operators vault of 1Password as **PDU Utilities Cabinet**. 
    

#.  On the PDU page, click on :guilabel:`Outlets` on the left-hand side menu to open the outlets' screen.

    .. figure:: /Simonyi/Components/_static/pdu1.jpeg  
        :name: pdu1

        Figure 1: The list of :guilabel:`Outlets` on the *https://tea-pdu01.cp.lsst.org/*


.. _PDU-Outlet-Mapping-Description:

Description of the Outlets
==========================

To power cycle or turn any of them :guilabel:`On` or :guilabel:`Off`, use the top right buttons shown inside a 
red square in Figure 1

#.  **DIMM (Temp)**- This energizes the star tracker mounted on the top-end ring.

#.  **M2 Cell cabinet**- This outlet energizes the full MTM2 cabinet, including the controller and VMS

#.  **M2 Hexapod cabinet**- This outlet energizes the full MTM2 Hexapod cabinet and should be always on. 
    To cycle the power of the MTM2 Hexapod drives or PXI we need to use the MTM2 Hexapod Netbooter 
    *m2-hexapod-netbooter.cp.lsst.org*. Once the repackaging is done on MTM2 Hexapod, this Netbooter will be 
    removed as well.    

#.  **Camera Hex Cabinet**- This outlet energizes the MTCamHexapod drives.

#.  **Camera Rotator Cabinet**- This outlet energizes the MTRotator Cabinet drives.

#.  **PXI Camera Rotator**- This outlet only energizes the MTRotator PXI.

#.  **Free**- This will be used by the MTM2 Hexapod PXI in the future.

#.  **PXI Camera Hexapod**- This outlet only energizes the MTCamHexapod PXI

#.  **PS Labjack**- This energizes the Labjack that reads the accelerometers.

#.  **PS Temperature Scanners (3)**- This outlet energizes 3 temperature scanners located in the TEA. One for the 
    MTCameHexapod actuators and MTRotator motors temperature, one for the MTM2 Hexapod actuators temperature, and one 
    for the MTM2 Tangent Links temperatures.

#.  **PS Eth Switch1**- This is for the network switch and **should be always on**.

#.  **PS Eth Switch2**- This is for the network switch and **should be always on**.


.. warning::

    Never turn off outlets 11 and 12. These are only used by IT.


This procedure was last modified on |today|.
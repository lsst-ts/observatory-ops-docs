.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Alysha Shugart*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Giovanni Corvetto*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Safety-Systems-Control-Safety-Systems:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

######################
Control Safety Systems
######################

Presented here is an overview of the concepts LOTO (Lockout/Tagout), GIS (Global Interlock System), and E-STOP (Emergency Stop), and when each procedure or system is used. 
Specific procedures, like how to LOTO the Telescope Mount Assembly (TMA), or how to reset the GIS to resume operations of a specific component, are not described here. 
The final procedures for LOTO will be documented on the Observatory Operations pages and linked here. 

    - :ref:`AuxTel LOTO procedure <Auxiliary-Telescope-AuxTel-LOTO-procedure>`

Final procedures need approval by the Safety Team, or will require hands-on training. 

.. _Daytime-Operations-Safety-Control-Safety-Systems-LOTO:

LOTO
^^^^
LOTO stands for Lockout/Tagout. 
LOTO programs and procedures were instituted by the Occupational Safety and Health Administration (OSHA) of the United States. 
The OSHA standard 1910.147, the control of hazardous energy, mandates that all existing energy, or potential energy from a piece of equipment is ELIMINATED before it is serviced or accessed. 
LOTO procedures are designed so there is no accidental release of energy (such as powering up electrical panels or charging pressurized liquids) when someone is working on a machine.
Performing LOTO is also required if you are accessing an area where there is a collision risk, or you are in a confined space underneath or around the equipment.

**Lockout:** This method uses physical locks with unique keys to stop anyone from turning equipment back on. 
If you use LOTO, you must have your own unique lock and key issued to you by the Safety or SIT-Com team. 
Once you apply your lock to a piece of equipment, only you can take it off. 
You are responsible for knowing the procedure to put the equipment in a safe state, remove risks, and perform LOTO. 

**Tagout:** If you place a lock on a piece of equipment, you must also include a tag to indicate that the machine or piece of equipment is not usable and being serviced. 
These tags are available around the summit, or can be issued directly to you to write your contact information on. 

LOTO needs to occur anytime you put yourself or anyone else near any part of the dangerous zone of a piece of equipment. 
In the case that multiple people working in a dangerous area at one time, each person should perform LOTO on the equipment.
Some examples are:

    -	When accessing the observing platform on the TMA, EVEN IF the power supply is off.
    -	Going up to the Main Dome aperture platform to open the shutters.
    -	Doing any physical work on the AuxTel mount, such as adding accelerometers or installing sensors.

You are required to complete the `LOTO training <https://drive.google.com/file/d/1zKtvqbjtLcOuefIXvZ4KTSdCNThznWs9/view?usp=share_link>`_ before you are issued a lock and tag. 
This video is a overview of the OSHA guidelines for performing LOTO.
It does not include specific procedures for performing LOTO on any Rubin Observatory equipment. 
Once you have reviewed the video and available LOTO procedures, register your compliance with the Safety team and sign the log they maintain on the summit, affirming that you have completed the required training. 

.. _Daytime-Operations-Safety-Control-Safety-Systems-GIS:

GIS
^^^
The Global Interlock System (GIS) is a safety system that guarantees the Rubin Observatory's secure operation. 
GIS interacts with other systems of the Simonyi and Auxiliary Telescopes, such as the Pflow, M1M3, M2 Hexapod, etc. 
If any of the interlocks are triggered, such as fire detection, seismic activity, or a safety gate is open, such as the safety gate on the 6th floor underneath the TMA azimuth wrap, GIS receives these signals and creates a waterfall effect that blocks off any system coupled to the trigger. 
This is an example of the order of operations the GIS manages when an interlock is triggered:

1.	The TMA is rotating in azimuth.
2.	There is an earthquake or seismic activity detected by the Observatory’s earthquake monitoring system in the EAS (Environmental Awareness System).
3.	GIS receives these signals. 
4.	GIS sends an earthquake detection signal.
5.	The TMA is blocked from rotating, the CSCs go into error state, and the EUI displays a safety interlock.

GIS is a reactionary system, and is not fit for LOTO given that it does not completely remove an energy source from a system, it only temporarily blocks the energy source by software stop that has a physical release mechanism.
The stops are released by clearing the interlock, resetting the GIS control panel touchscreen, or in the case of the safety gate, closing the gate and pressing the GIS release button. 
The GIS can be reset by anyone by bypassing the interlock or resetting it on the 2nd floor. 

Specific procedures to reset interlocks, and what systems are affected, will be updated on these pages as they become official procedure. 

.. _Daytime-Operations-Safety-Control-Safety-Systems-Emergency-Stop:

Emergency Stop
^^^^^^^^^^^^^^

An E-STOP (Emergency Stop) is a system that is intended to avert harm to any person or machinery. 
It is intended for use in an EMERGENCY. It is not a safeguard, but is considered by OSHA a Complementary Protective Measure, which means that it is not inherently a safe design measure, but a last-available option in case of unforeseen circumstances or a misuse of equipment. 

E-STOPs around the Observatory are big, red buttons that need to be released in a certain way to unlock them. 
Only after releasing the E-STOP and resetting the electronic logic of the equipment can you continue to use it. 
For an example of an E-STOP procedure, see `AuxTel E-STOP release <https://obs-ops.lsst.io/AuxTel/AuxTel-Non-standard-Operations/ATCS-Non-standard-Procedures/E-Stop-Procedure.html>`_. 

These are meant to use ONLY IF a person or piece of equipment is in immediate danger of being damaged because of the machine’s continued use. 
It is a hard brake in the case of AuxTel or the TMA, and its use during a slew could exert forces on the drives that cause some damage. 
Recovering from an E-STOP during telescope motion is a multi-step process, and requires inspection of the equipment before complete recovery. 

**E-STOPs ARE NOT THE SAME AS LOTO.** 
Lockout requires that sources of hazardous energy are physically isolated, and the control system safety functions, such as GIS and E-STOPs, only meet part of the requirements, and not all of them. 
In the case of AuxTel, a person may be on the second floor working on the mount with an E-STOP pressed. 
Another person can release this E-STOP and recover the mount without the intervention of the person working. 
Because of this, the AuxTel E-STOP does not fulfill the requirements of the LOTO procedure. 

Read more about `E-STOP implementation <https://machinerysafety101.com/2009/03/06/emergency-stop-whats-so-confusing-about-that/>`_ and `E-STOPs in LOTO <https://machinerysafety101.com/2010/11/29/using-e-stops-in-lockout-procedures/>`_ procedures. 


This procedure was last modified |today|.

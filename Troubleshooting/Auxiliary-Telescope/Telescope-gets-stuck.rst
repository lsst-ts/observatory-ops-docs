######################
Telescope gets "stuck"
######################

On a few occasions there have been instances where the telescope appears stuck and does not move (although being enabled and responding to commands).
This has been rare, and was captured in Jira ticket OBS-53.
This page provides instructions on how people were able to get it unstuck.
They are provided for guidance, but should not be considered a strict recipe.

The following list was performed using the EUI (on auxtel-brick.cp.lsst.com), but it may also be possible to do via the CSC or a notebook.
In fact, it is recommended that the motion steps required are first attempted via a notebook before moving to the EUI.

This issue happened at AZ: -76 deg, EL: 45 deg. 
The solution was to command the azimuth a small number of degrees back or forward (exact order is unknown) and the movement reestablished.

#. Send the mount and pointing component to ``STANDBY``

#. Start and enable pneumatics system (open the Master Air Supply and Instrument Air Valve) even if the status is already marked as open. 

#. On the Mount Tab: Start, Enable and then move the elevation a small amount, then once moving, continue to desired location. 
   Then Stop, disable, and stand by.

#. Again, on the mount tab, Start, Enable and move this time the azimuth by 1-3 degrees (the direction may be important!) then once in motion send to the desired position.

#.  All axes should now be able to be moved simultaneously.

Note that several years ago we had a similar issue with the rotator.
It was never reproducible and was never seen again once the motor preload was decreased to resolve a different issue.
This may or may not be coincidence.


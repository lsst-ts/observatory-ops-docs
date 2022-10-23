.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Patrick Ingraham*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Tiago Ribeiro*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Observing-Interface-Production-Environment-Package-Management:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. _Production-Environment-Package-Management:

#########################################
Production Environment Package Management
#########################################

Introduction
^^^^^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This page explains how package management in controlled on production environments, specifically the summit.
Nominally, the CSC versions and supporting software packages deployed on the summit are managed by the `cycle build <https://ts-cycle-build.lsst.io/>`_.
However, during commissioning it will be required to deploy new versions for testing, and/or deploy on-the-fly hotfixes that won't yet have been included as part of the cycle build.
These fixes must be simultaneously available to the ScriptQueue CSC as well as the observer's notebook environments.
Most importantly, when testing new software on the summit, which may not be entirely stable, it is critical to have a mechanism to immediately roll back all packages to a designated stable version.
We call this the **base environment**.
Note that this version may include bug fixes and/or new functionalities that are not included in the previously released cycle build.


Shared packages
^^^^^^^^^^^^^^^
To ensure consistency between all observers and the ScriptQueue, packages are hosted on an NFS mounted disk.
The NFS mount is hosted on machine XYZ FIXME and mounted to all machines in ``/opt/obs_env``.
The directory is owned by ``obs_user`` and mounted as read-only.
In that directory includes packages such as: ``ts_observatory_control``,  ``ts_standardscripts``, ``ts_externalscripts``, ``summit_utils``, ``summit_extras``, ``ts_observing_utilities`` and any other packages which may get updated during an observing run.
Note that these are packages *used* by observers and/or CSCs, but are not the CSCs themselves.

The ``obs_user`` account
^^^^^^^^^^^^^^^^^^^^^^^^

The ``obs_user`` account is a special account which *does not have a login*.
Any commands issued by that user must be done via sudo, and that user must have the proper privileges to execute that command.
``obs_user`` is the owner of the summit environment packages that are used by observers and the scriptQueue.

The number of actual commands performed by ``obs_user`` is very limited and dependent upon the end-user.
There will be by a few sanctioned individuals who maintain the observing environment(s), they will have extensive sudo privileges such that they can manage the packages accordingly, however, they should really only need to perform a few commands.
Observers will also have access to the ``obs_user`` account, but *only* to execute a script that will roll back to the base environment.

All commands using the ``obs_user`` account must be executed as follows, to command itself is only an example:

.. code-block:: bash

   sudo -u obs_user git checkout main

The reason for using this method is because all sudo commands are logged, and therefore we have a history of who ran the command, which is stored in ``/var/log/secure`` for CentOS7 machines.
The fact that the ``obs_user``, does not have a login capability ensures that all commands executed under the ``obs_user`` identity are logged.

The command that observers use to roll back to the base environment is:

.. code-block:: bash

   sudo -u obs_user FIXME

Also, observers may need to overwrite their current Nublado instance and restore it to using only the base environment.
Note that this is a destructive action that takes time to revert.

.. code-block:: bash

   sudo -u obs_user FIXME

This command will move your current ``~/notebooks/.user_setups`` file to your home directory with a timestamp, then create a new file which points to the base environment.

Use of the deploy branch
^^^^^^^^^^^^^^^^^^^^^^^^

For all packages that are subject to potentially rapid changes during nighttime operations, a ``deploy`` branch is used to manage which commits are currently being used by the observing environment.

In a normal case, the deploy branch is updated merging a tagged commit from the main branch.
Middle-of-the-night hot-fixes will be deployed by directly pushing to the deploy branch.
The deploy branch is configured to automatically pull in changes and maintain the HEAD of the branch.
This means that as soon as a fix is pushed, the ScriptQueue gets it instantaneously, and users need only to restart their notebook kernels.

Under no circumstances should the deploy branch be merged back into main or develop.
Any hot-fixes that were made during the night should be incorporated by making a ticket, creating a branch from develop, and going through the standard development procedure.
Commits cannot be squashed or overwritten and must be kept to ensure traceability.

Question: Do we need CI on the deploy branch? FIXME

Question: Ideally, even hot-fixes should have a tag. Do we care? Is there a way to do this automatically?

Managing the base environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The base environment is defined by a list of tags, or commit hashes, representing the packages which are deemed to be stable.
Note that this list needs to be maintained daily, and can only be updated by the production environment maintainers.
The list itself is stored in ``/opt/obs_user/base_environment.yaml`` (FIXME-better way to do this? CSV file with package name and branch (or commit hash?)). 
The default for each package should be a tagged commit that has been merged to the deploy branch.
However, in certain cases it may be a specific commit of the deploy branch, specifically if bug-fixes have been applied that are not yet incorporated into the main branch.

Question: How do we update this when a new cycle build occurs? Just part of a procedure? FIXME


On-sky testing then rolling back a CSC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the event that a new CSC is rolled out for on-sky testing, but is not considered to be stable, this is to be performed by ... manually deploying a detached head inside the container? Then the container just has to be sent to offline and re-synced to pull the sanctioned version?


.. _Update-Notebook-Environment-in-Nublado-Prerequisites:

Prerequisites
^^^^^^^^^^^^^

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

- You must have write access to the deploy branch


.. _Update-Notebook-Environment-in-Nublado-Post-Conditions:

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

ScriptQueue and the Nublado instances will have access to the updated packages.
However, Nublado users *must restart their kernel* to grab the changes.

The ScriptQueue instantiates the script from disk each time it is launched, and therefore nothing needs to be performed to grab the new changes.

Updating the "base" environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If the changes should be included in base environment there are two options:

#. Updated the cycle build, create a new tag, and merge the main branch onto the deploy branch.
   Then change the base-environment definition file
   This is the best option, but 

.. _Update-Notebook-Environment-in-Nublado-Procedure-Steps:

Procedure Steps
^^^^^^^^^^^^^^^

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.


Troubleshooting
^^^^^^^^^^^^^^^

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

No troubleshooting information is applicable to this procedure.

.. _Update-Notebook-Environment-in-Nublado-Contact-Personnel:

Contact Personnel
^^^^^^^^^^^^^^^^^

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

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
.. _Observing-Interface-Observing-Environment-Package-Management:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. _Observing-Environment-Package-Management:

#########################################
Observing Environment Package Management
#########################################

Introduction
^^^^^^^^^^^^

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This page explains how package management is controlled on the Observing Environment, specifically the summit.
The Observing Environment is mainly composed of the ScriptQueue and user's Nublado instance, which are the primary high-level tools responsible for driving observatory operations.

Even though the Observing Environment is initially built and deployed alongside the rest of the Observatory Control System components (e.g. CSCs), it needs to follow a slightly different management approach to support on-the-fly updates.
These updates will primary consist of bug fixes and or workarounds to unforeseen circumstances.
Nominally, the CSC versions and supporting software packages deployed on the summit are managed by the `cycle build <https://ts-cycle-build.lsst.io/>`_
Nevertheless, the procedure to deploy hot-fixes for CSCs (e.g. create an alpha tag on the package, update the cycle build and redeploy), is not suitable for the Observing Environment, which requires a much larger set of packages and therefore, longer build times.
These patches to the Observing Environment needs to be rapidly rolled out to the summit and must be simultaneously available to the ScriptQueue CSC as well as the observer's notebook environments.
Most importantly, when testing new software on the summit, which may not be entirely stable, it is critical to have a mechanism to immediately roll back all packages to a designated stable version.
We call this suite of stable versions the **base observing environment**.


Shared packages
^^^^^^^^^^^^^^^
To ensure consistency between all observers and the ScriptQueue, packages are hosted on an NFS mounted disk.
The NFS mount is hosted on machine ``XYZ (FIXME)`` and mounted to all machines in ``/opt/obs_env``.
The directory is owned by ``obs_user`` and mounted as read-only.
In that directory includes packages such as: ``ts_observatory_control``,  ``ts_standardscripts``, ``ts_externalscripts``, ``summit_utils``, ``summit_extras``, ``ts_observing_utilities`` and any other packages which may get updated during an observing run.
Note that these are packages *used* by observers and/or CSCs, but are not the CSCs themselves.

The ``obs_user`` account
^^^^^^^^^^^^^^^^^^^^^^^^

The ``obs_user`` account is a special account which *does not have a login*.
Any commands issued by that user must be done via sudo, and that user must have the proper privileges to execute that command.
``obs_user`` is the owner of the summit environment packages that are used by observers and the scriptQueue.

The number of actual commands performed by ``obs_user`` is very limited and dependent upon the end-user.
There will be a few sanctioned individuals who maintain the observing environment(s), they will have extensive sudo privileges such that they can manage the packages accordingly, however, they should really only need to perform a few commands.
Observers will also have access to the ``obs_user`` account, but *only* to execute a script that will roll back to the base environment.

All commands using the ``obs_user`` account must be executed as follows, the command itself is only an example:

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

This command will move your current ``~/notebooks/.user_setups`` file to a new file with a timestamp (e.g. ``~/notebooks/.user_setups.<date>.bkp``, then create a new file which points to the base environment.


Managing the base environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The base environment is defined by a list of packages and associated tags, or commit hashes, representing the packages which are deemed to be stable (to the best of everyone's collective knowledge).
Note that the base environment needs to be maintained daily, and can only be updated by the production environment maintainers.
The list itself is stored in ``/opt/obs_user/base_env_repo/base_environment.yaml``  (TBR), 
The default for each package should be a tagged version that corresponds to the current cycle build.
However, in certain cases it may contain a specific commit or tag of a certain package that employs a bug fix that was identified the previous night but not yet incorporated into the main branch and pulled back into the cycle build.
Another possibility is that the main branch will have diverged from what is currently deployed and the changes will be brought into the base environment when a cycle upgrade is completed.

The base environment is a github repository managed by sanctioned individuals and led by the software architect.
It is their responsibility to ensure that the summit environment stays stable and that appropriate hot fixes make it into the package's repository.
The are also responsible for keeping the run environment (described below) identical to the base environment to the maximum extent possible.
The base environment repository also contains the scripts used to modify the environment that are executed by observers and/or maintainers.

.. Question: How do we update this when a new cycle build occurs? Just part of a procedure? FIXME


Modifying the run environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For all packages that are subject to potentially rapid changes during nighttime operations, a **run environment** is used to manage which commits are currently in use by the observing environment.
In standard operations, where the situation is stable, the run environment is identical to the base environment.
However, during commissioning and early operations, we are expecting the run environment to be more dynamic.

Like the base environment, the run environment is defined by a list of packages and associated tags, or commit hashes, stored in ``/opt/obs_user/run_environment.yaml``.
However, unlike the base environment configuration, this file *only* contains the packages that are to be overridden from the base environment; analogous to how CSC configurations are managed.

This file is *not* required to be managed by a GitHub repository, as it can be edited by a user, and therefore must be writeable by project personnel.

.. note::

   In the future, it is suspected that we'll write scripts to edit this file.
   Doing this ensures traceability regarding how the file was edited and by whom.

The script is executed using a sudo command such as:

.. code-block:: bash

   sudo -u obs_user bash setup_run_environment 

Not only does this script setup the environment, but it also writes a (read-only) log file to `/var/logs/obs_user/run_env_<datetime>.log` listing each package and tag used in the setup. This includes both overrides and the base environment packages.

Optionally, the script can setup the environment using a previously written log file.

.. code-block:: bash

   sudo -u obs_user bash setup_run_environment /var/logs/obs_user/run_env_<datetime>.log

Again, because all commands are run via sudo using the ``obs_user`` id, the retrospection capability is preserved.
Also, due to the NFS mounted environment, the ScriptQueue gets the changes instantaneously, and observers need only to restart their notebook kernels.

Using the run environment
^^^^^^^^^^^^^^^^^^^^^^^^^

- During the day, it is expected that developers and other personnel will modify the run environment to perform tests.
- It is quite possible that people will share the environment, especially if the scriptQueue is required.
  If running notebooks, then users should change their environment from within their local Nublado instance.
- At the beginning of the night, observers should run the script that sets up the base environment. 
  In the special case where a previous run environment needs to be loaded, this should be communicated to the observers by the run manager.

On-sky testing then rolling back a CSC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   This section is here temporarily.
   It is more a use-case on how we should handle CSCs that need to be tested and then rolled back, not about package management.

In the event that a new CSC is rolled out for on-sky testing, but is not considered to be stable, this is to be performed by ... manually deploying a detached head inside the container? Then the container just has to be sent to offline and re-synced to pull the sanctioned version?


.. _Update-Notebook-Environment-in-Nublado-Prerequisites:

Prerequisites
^^^^^^^^^^^^^

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).

- You must have sudo privileges to run the appropriate scripts.


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

#. Updated the cycle build, and create a new tag.
   Then change the base-environment definition file


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

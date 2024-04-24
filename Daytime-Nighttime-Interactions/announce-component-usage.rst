.. This is a template for operational procedures. Each procedure will have its own sub-directory. This comment may be deleted when the template is copied to the destination.

.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Patrick Ingraham*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Michael Reuter*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.

.. _Operational-Tutorials-Annouce-Component-Usage:

.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

##########################
Announcing Component Usage
##########################

.. Important::

    This procedure is still under development.

.. _Announcing-Component-Usage-Overview:

Overview
^^^^^^^^

This topic covers how to properly announce the usage of component(s) on the summit.

.. _Announcing-Component-Usage-Prerequisites:

Prerequisites
^^^^^^^^^^^^^


.. _Announcing-Component-Usage-Post-Condition:

Post-Condition
^^^^^^^^^^^^^^

.. This section should provide a simple overview of conditions or results after using the tutorial.

- Usage is properly noted and established to the appropriate authorities.

.. _Announcing-Component-Usage-Tutorial-Steps:

Tutorial Steps
^^^^^^^^^^^^^^^

.. This section should include the tutorial steps.
.. In the case of more complicated tutorials, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked tutorials to be performed in the specified order.
.. For highly complicated tutorials, consider breaking them into separate tutorials. Some options are a high-level tutorial with links, separating into smaller tutorials or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

* Announcements are to be made in the ``#summit-announce`` Slack channel
* People who participate in testing or infrastructure support/development must be actively monitoring that channel
* All announcements for all work that may affect the summit DDS network or its infrastructure are required

    * Includes Nublado updates, invasive networking changes etc.

* Announcement Guidelines/Procedure:

  The following rules are also bookmarked in the channel.
  
    * Make announcement when ready to begin work

        * Include estimate of how long the systems will be in use
        * Include name of other channel where conversation on the work will take place

    * List the CSC(s) you plan on using and a 1 or 2-sentence synopsis of what you are doing

        * You can refer to systems like AT, MT, ComCam etc. in lieu of listing all the CSCs to be used

    * Make announcement when ready to begin work

        * A 1 or 2 sentence summary of the tests performed is strongly encouraged


This procedure was last modified |today|.

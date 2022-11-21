.. Review the README in this procedure's directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this procedure's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Include a comment explaining why this is not required.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. Include one Primary Author and list of Contributors (comma separated) between the asterisks (*):
.. |author| replace:: *Tiago Ribeiro*
.. If there are no contributors, write "none" between the asterisks. Do not remove the substitution.
.. |contributors| replace:: *Michael Reuter, Patrick Ingraham*

.. This is the label that can be used as for cross referencing this procedure.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. _Observing-Interface-Operational-Environments:

########################
Operational Environments
########################

.. _Observing-Interface-Operational-Environments-Overview:

Overview
========

.. This section should provide a brief, top-level description of the procedure's purpose and utilization. Consider including the expected user and when the procedure will be performed.

This procedure is intended for users of the Rubin Observatory that are interested in interacting with the  Observatory Control System.
It contains basic information (with links and description) on how to connect to the observing interface tools at the summit and at the different test stands.

- Each operational environment is composed of a `nublado`_ instance, an EFD instance (with Chronograf and other visualization tools) and LOVE interface.
- Coordination on the use of each operational environment is managed through Slack channels.
- Most components are deployed as docker containers, orchestrated via ArgoCD and Kubernetes.
  A small subset of components are deployed with docker-compose and, in some cases, deployment is still done directly on bare metal nodes manually.

.. _nublado: https://nb.lsst.io


.. _Observing-Interface-Operational-Environments-Prerequisites:

Prerequisites
=============

.. This section should provide simple overview of prerequisites before executing the procedure; for example, state of equipment, telescope or seeing conditions or notifications prior to execution.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included at the beginning of the Procedure section below. For example: Do not include "Notify specified SLACK channel. Confirmation is not required." Instead, include this statement as the first step of the procedure, and include "Notification to specified SLACK channel." in the Prerequisites section.
.. If there is a different procedure that is critical before execution, carefully consider if it should be linked within this section or as part of the Procedure section below (or both).


- You must be logged on the LSST-WAP, into the NOAO or summit VPN.

.. _Observing-Interface-Operational-Environments-Post-Conditions:

Post-Condition
==============

.. This section should provide a simple overview of conditions or results after executing the procedure; for example, state of equipment or resulting data products.
.. It is preferred to include them as a bulleted or enumerated list.
.. Do not include actions in this section. Any action by the user should be included in the end of the Procedure section below. For example: Do not include "Verify the telescope azimuth is 0 degrees with the appropriate command." Instead, include this statement as the final step of the procedure, and include "Telescope is at 0 degrees." in the Post-condition section.

- Successfully access nublado and other observing interface tools.
- Ability to command components.

.. _Observing-Interface-Operational-Environments-Procedure-Steps:

Procedure Steps
===============

.. This section should include the procedure. There is no strict formatting or structure required for procedures. It is left to the authors to decide which format and structure is most relevant.
.. In the case of more complicated procedures, more sophisticated methodologies may be appropriate, such as multiple section headings or a list of linked procedures to be performed in the specified order.
.. For highly complicated procedures, consider breaking them into separate procedure. Some options are a high-level procedure with links, separating into smaller procedures or utilizing the reST ``include`` directive <https://docutils.sourceforge.io/docs/ref/rst/directives.html#include>.

In a browser open the links below under the heading corresponding to the operational environment you want to interact with.

For instance, open the nublado link in :ref:`TTS <Observing-Interface-Operational-Environments-TTS>` to interact with the observatory control system in that operational environment.

.. _Observing-Interface-Operational-Environments-BTS:

Base Facility Test Stand (BTS)
------------------------------

BTS is a simulation operational environment running at the base facility in La Serena.
The main difference between the :ref:`TTS <Observing-Interface-Operational-Environments-TTS>` and this operational environment is that some systems will run using hardware simulators.

Hardware simulators are, in general, higher fidelity than those of pure software available at :ref:`TTS <Observing-Interface-Operational-Environments-TTS>`.
For that, BTS will be used mostly for higher fidelity testing, development and debugging.
It will also be particularly useful for testing lower-level hardware interfaces.

- Nublado: https://base-lsp.lsst.codes/
- Chronograf: https://chronograf-base-efd.lsst.codes/
- LOVE: N/A
- ArgoCD: https://base-lsp.lsst.codes/argo-cd/
- Rancher: https://rancher.cp.lsst.org/
- Kubernetes Cluster: kueyen
- Slack: N/A
- Alarm Slack: N/A

.. _Observing-Interface-Operational-Environments-TTS:

Tucson Test Stand (TTS)
-----------------------

The TTS is currently being used as a staging platform to test new software versions and procedures prior to deployment at the summit.
Systems that control hardware at the :ref:`Summit <Observing-Interface-Operational-Environments-Summit>` run here in simulation mode.
Once a deployment is tested here, the platform is made available for general users for training, testing and developing of control algorithm and procedures.

- Nublado: https://tucson-teststand.lsst.codes/
- Chronograf: https://tucson-teststand-efd.lsst.codes/chronograf
- LOVE
   - bare metal: http://love1.tu.lsst.org
   - kubernetes: http://love.tu.lsst.org
- ArgoCD: https://tucson-teststand.lsst.codes/argo-cd
- Rancher: https://rancher.tu.lsst.org/
- Kubernetes Cluster: pillan
- Slack: rubinobs-tucson-teststand
- Alarm Slack: tucson-teststand-watcher

.. _Observing-Interface-Operational-Environments-Summit:

Summit
------

Summit is our main production operational environment.
Systems running here will be directly controlling hardware or communicating with components that control actual hardware.

  .. important::

      In the case of the Summit it is required to have personnel present at the site prior to any activity that involves moving hardware.
      These must be planned activities and require an accompanying `summit activity project <https://jira.lsstcorp.org/projects/SUMMIT>`__ Jira ticket organized by appropriate personnel.

- Nublado: https://summit-lsp.lsst.codes/
- Chronograf: https://chronograf-summit-efd.lsst.codes/
- LOVE: http://love01.cp.lsst.org/
- ArgoCD: https://summit-lsp.lsst.codes/argo-cd
- Rancher: https://rancher.cp.lsst.org/
- Kubernetes Cluster: yagan
- Slack: summit-announce
- Alarm Slack: summit-watcher

.. _Observing-Interface-Getting-Started-Troubleshooting:

Troubleshooting
===============

.. This section should include troubleshooting information. Information in this section should be strictly related to this procedure.

.. If there is no content for this section, remove the indentation on the following line instead of deleting this sub-section.

If you can not open the links to the operational environment you intend to work with, make sure you are connected to the LSST-WAP wifi network in one of the designed areas (Tucson, La Serena or Summit facilities) or that you are connected to the NOAO VPN.

If problems persist, you can ask for help in the designated Slack channels or in the com-square-support channel.

.. _Observing-Interface-Getting-Started-Personnel:

Contact Personnel
=================

This procedure was last modified |today|.

This procedure was written by |author|. The following are contributors: |contributors|.

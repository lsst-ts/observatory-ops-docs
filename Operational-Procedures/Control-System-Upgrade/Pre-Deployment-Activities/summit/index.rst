Summit
======

This section contains site specific variations for the summit.

.. _Pre-Deployment-Activities-Summit-Configuration-Repos-Info:

Configuration Repository Information
------------------------------------

Use the following options:

* ``docker-compose-ops``: ``summit``
* ``argocd-csc``: ``values-summit.yaml``
* ``LOVE-integration-tools``: ``deploy/summit``

.. _Pre-Deployment-Activities-Summit-Scheduling:

Scheduling Summit Upgrade
-------------------------

Please note that the summit work **MUST** be put on the Summit Jira calendar by filing a ticket on the `Summit Jira <https://jira.lsstcorp.org/projects/SUMMIT>`_ project.
By filling in the ``Start Date`` and ``End Date`` fields, the ticket will automatically appear on the calendar.
Set the ticket priority level to one.
Make sure Andy Clements is aware of the ticket.
The summit work **MUST** take place between 4 to 8 PM Chilean time on the given day to avoid bothering the day crew.

.. _Pre-Deployment-Activities-Summit-Slack-Announce:

Slack Channel for Announcements
-------------------------------

#summit-announce

.. _Pre-Deployment-Activities-Summit-RSP-Config:

RSP Configuration File
----------------------

``science-platform/values-summit.yaml``

Preparing for Deployment
========================

There are a few things that must be done before the deployment happens and while the builds of deployable artifacts are ongoing.

#. Create a Jira ticket for the cycle build configuration work.
   You will need a new ticket for each deployment site.
#. Prepare the configuration for the cycle build in the git repositories listed in :ref:`Control-System-Upgrade-Pre-Deployment-Activities-Repositories` using the Jira ticket above as the branch.
    #. Use the site specific file/directory: :ref:`Summit <Pre-Deployment-Activities-Summit-Configuration-Repos-Info>`, :ref:`NTS <Pre-Deployment-Activities-NTS-Configuration-Repos-Info>`.
    #. Update the cycle build tag.
    #. Update any changes to CSC configurations including launch command-line.
    #. Add new CSC/applications as necessary.
#. Work with build team during the build process to ensure schedule and resolve any encountered problems: :ref:`Summit <Pre-Deployment-Activities-Summit-Scheduling>`.
#. Create cycle build Confluence page (`Software Upgrades <https://confluence.lsstcorp.org/pages/viewpage.action?spaceKey=LSSTCOM&title=Software+Upgrades>`_) with versions of core packages and any operational changes.
    #. Announce page once all base artifacts are built.
#. Announce the deployment schedule on the slack channel: :ref:`Summit <Pre-Deployment-Activities-Summit-Slack-Announce>`, :ref:`NTS <Pre-Deployment-Activities-NTS-Slack-Announce>`.
    #. Use the ``release_announcement.py`` script from vanward_ to craft the announcement.
    #. If you want to work with the System Principles for DM and Camera machines, make sure to inform them you will require their help standing down services.
#. Coordinate with SQuaRE to make sure that a new nublado with the current XML/SAL will be available for the deployment day.
    #. Make a PR for the site specific science-platform configuration here: https://github.com/lsst-sqre/phalanx.
    #. Edit the appropriate configuration file: :ref:`Summit <Pre-Deployment-Activities-Summit-RSP-Config>`, :ref:`NTS <Pre-Deployment-Activities-NTS-RSP-Config>`.
    #. Notify SQuaRE when the PR is ready to merge.
    #. Syncing the ``cachemachine`` app will take place during the deployment.

.. _Control-System-Upgrade-Pre-Deployment-Activities-Repositories:

Deployment Configuration Repositories
=====================================

As noted above, following repositories contain the configuration as code.

* https://github.com/lsst-it/docker-compose-ops
* https://github.com/lsst-ts/argocd-csc
* https://github.com/lsst-ts/LOVE-integration-tools

Deployment Helper Repositories
==============================

The following repositories contain helper scripts that aid in the deployment process.
Specific uses for each repository are handled within the deployment documentation.

* https://github.com/lsst-ts/docker-compose-admin
* https://github.com/lsst-ts/k8s-admin
* https://github.com/lsst-ts/argocd-admin

Site Specific Variations
========================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    summit/*
    ncsa-teststand/*

.. _vanward: https://vanward.lsst.io

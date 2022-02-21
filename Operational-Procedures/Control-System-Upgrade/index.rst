######################
Control System Upgrade
######################

These pages will document the process for going about an upgrade of the control system software interface.
Since the control system is highly coupled to the interface specification (XML), the communication backplane (DDS) and the abstraction layer (SAL), this documentation focuses on upgrades to those dependencies.
The process for building the base artifacts and component containers is handled in other documentation: TSSW Build System :ref:`TSSW-Build-System-Introduction` and `Cycle Build <https://ts-cycle-build.lsst.io>`_.
The deployment part of the documentation will be written generically with sections highlighting the specific differences between the various sites.
It is best to read this documentation ahead of time as there are necessary credentials and code to setup before executing the outlined steps.

The control system upgrades are designated by a cycle concept similar to Data Management's fixed six month development period.
However, in the case of the control system, the cycle build happens roughly on a two month cadence, but the cadence can sometimes be irregular.
The irregularity is usually in longer periods between cycles, but on occasion can be shorter.
We identify an upgrade with a label: ``Cycle N`` where ``N`` is the next revision in the cycle process.

When referencing deployment sites, we use the following shorthand for the various test stands:

* NTS: NCSA test stand (retired as of 2022-02-11)
* TTS: Tucson test stand
* BTS: Base (La Serena) test stand

We refer to Cerro Pachon as the summit when talking about it as a deployment site.

.. _Control-System-Upgrade-Getting-Ready:

Getting the Dependencies Ready
==============================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    Getting-Ready/*

Pre-Deployment Activities
=========================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    Pre-Deployment-Activities/*

Deployment Activities
=====================

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    Deployment-Activities/*

.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Project-Contributing:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

####################################################
Contributing to Observatory Operations Documentation
####################################################

.. This section should provide a brief, top-level description of the page.

Below are instructions and guidelines on contributing to the `Rubin Observatory Operations Documentation <https://obs-ops.lsst.io>`__.
This documentation is built with `Sphinx <https://www.sphinx-doc.org/en/master/>`__ and published to `<https://obs-ops.lsst.io>`__.

This documentation is open source.
Rubin Observatory welcomes contributions that make this documentation more useful and accurate.

.. Keep in mind that everyone participating in this project is expected to follow the LSST DM `Team Culture and Conduct Standards <https://developer.lsst.io/team/code-of-conduct.html>`__.

.. _Contributing-Issue:

Raising an Issue
================

If you spot an issue with the documentation, the best thing to do is `raise a GitHub issue in the observatory-ops-docs repo <https://github.com/lsst-ts/observatory-ops-docs/issues/new>`__.
Include any relevant URLs with your issue description.

.. _Contributing-PR:

Creating a Pull Request
=======================

You can contribute directly to the `observatory-ops-docs <https://github.com/lsst-ts/observatory-ops-docs>`__ repo by creating a pull request.
If you’re intending to make a substantial change, it’s a good idea to create a GitHub issue first with your proposal.
Rubin Observatory can’t accept contributions that don’t fit with our strategy and roadmap.

These sections can help you create a successful pull request:

  * :ref:`Contributing-Building-the-Docs`
  * :ref:`Contributing-Doc-Style-Guide`

.. _Contributing-Building-the-Docs:

Building the Documentation Locally
==================================

These are the basic steps to clone and build the docs:

#. Clone the GitHub repository:

   .. code-block:: bash

      git clone https://github.com/lsst-ts/observatory-ops-docs
      cd nb_lsst_io

#. Create a Python virtual environment (with `venv <https://docs.python.org/3/tutorial/venv.html>`__, for example):

   .. code-block:: bash

      python3 -m venv .venv
      source .venv/bin/activate

   .. note::
      Activate this virtual environment in another shell by re-running the ``source`` command.

#. Install the Python dependencies:

   .. code-block:: bash

      python -m pip install --upgrade pip
      python -m pip install -r requirements.txt

#. You are now able to edit the cloned repository.
   The remaining items below are commands used to build and validate the documentation. These commands must be executed from the top-level directory.

#. Build the site:

   .. code-block:: bash

      make html

   .. note::
      Open ``_build/html/index.html`` in a browser to review it.

#. Validate the documentation build:

   .. code-block:: bash

      make linkcheck

   .. note::
      If some links are behind a login, you might need to ignore them.
      Look at the ``linkcheck_ignore`` variable in ``conf.py`` for examples of how to do this.

#. Completely clear the build:

   .. code-block:: bash

      make clean

.. _Contributing-Deployment:

Deployment
==========

Whenever you push to the GitHub repository, the site is built for the corresponding branch.
Find your build at https://obs-ops.lsst.io/v/. You can push to a branch you've created at any time.

The ``master`` branch is always published as https://obs-ops.lsst.io. Only authorize individuals can push to ``master``.
To incorporate your suggestions, create a :ref:`pull request <contributing-pr>`.

Approval Process
----------------

#. Verify the content with all authors and contributors.

#. Create a PR.

#. Request the following to review the PR:

   * Patrick Ingraham
   * Product Owner

#. Respond to the comments received during the review process.

#. After all reviewers approve, the submitter will squash commits and merge to master.

#. Notify Patrick Ingraham the PR was merged.

#. Notify the authorized individual to tag the release.

.. _Contributing-Doc-Style-Guide:

Documentation Style Guide
=========================

.. _Contributing-New-to-reST:

New to reStrcturedText and Sphinx
---------------------------------

Check out these resources and guides. Sources files are available to compare raw reST and HTML outputs.

  * `reStructuredText Introductory and Tutorial Material <https://docutils.sourceforge.io/rst.html>`__ and references therein.

  * `reStructuredText Primer <https://docutils.sourceforge.io/docs/user/rst/quickstart.html>`__

  * `reStructuredText Quick Reference <https://docutils.sourceforge.io/docs/user/rst/quickref.html>`__

  * `reStructuredText Primer from Sphinx <https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/basics.html>`_

  * `reStructuredText Style Guide for Rubin Observatory Data Management Developers <https://developer.lsst.io/restructuredtext/style.html>`__

.. _Contributing-Style-Guide:

Observatory Operations Style Guide
----------------------------------

.. include:: observatory-operations-style-guide.inc

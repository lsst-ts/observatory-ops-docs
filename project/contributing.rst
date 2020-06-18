####################################################
Contributing to Observatory Operations Documentation
####################################################

This documentation is open source.
Rubin Observatory welcomes contributions that make this documentation more useful and accurate.

.. todo::
   Provide agreed upon style guide.

.. Keep in mind that everyone participating in this project is expected to follow the LSST DM `Team Culture and Conduct Standards <https://developer.lsst.io/team/code-of-conduct.html>`__.

.. _contributing-issue:

Raising an issue
================

If you spot an issue with the documentation, the best thing to do is `raise a GitHub issue in the observatory-ops-docs repo <https://github.com/lsst-ts/observatory-ops-docs/issues/new>`__.
Include any relevant URLs with your issue description.

.. _contributing-pr:

Creating a pull request
=======================

You can contribute directly to the `observatory-ops-docs <https://github.com/lsst-ts/observatory-ops-docs>`__ repo by creating a pull request.
If you’re intending to make a substantial change, it’s a good idea to create a GitHub issue first with your proposal.
Rubin Observatory can’t accept contributions that don’t fit with our strategy and roadmap.

These sections can help you create a successful pull request:

  * :ref:`building-the-docs`
  * :ref:`doc-style-guide`

.. _building-the-docs:

Building the documentation locally
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

#. You are now able to edit the cloned repository. The remaining items below are commands used to build and validate the documentation.

#. Build the site:

   .. code-block:: bash

      make html

   .. note::
      Open ``_build/html/index.html`` in a browser to review it.

#. Validate the documetation build:

   .. code-block:: bash

      make linkcheck

   .. note::
      If some links are bheind a login, you might need to ignore them.
      Look at the ``linkcheck_ignore`` variable in ``conf.py`` for examples of how to do this.

#. Completely clear the build:

   .. code-block:: bash

      make clean

.. _deployment:

Deployment
==========

Whenever you push to the GitHub repository, the site is built for the corresponding branch.
Find your build at https://obs-ops.lsst.io/v. You can push to a branch you've created at any time.

The ``master`` branch is always published as https://obs-ops.lsst.io. Only authorize individuals can push to ``master``.
To incorperate your suggestions, create a :ref:`pull request <contributing-pr>`.

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

.. #. Notify the authorized individual to tag the release.

.. _doc-style-guide:

Documentation style guide
=========================

This documentation is written in reStructuredText and built with `Sphinx <https://www.sphix-doc.org/en/master>`__.
The `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__ can help you create effective reStructuredText.

New to reStrcturedText and Sphinx
---------------------------------

Check out these resources and guides. Sources files are available to compare raw reST and HTML outputs.

  * `reStructuredText Introductory and Tutorial Material <https://docutils.sourceforge.io/rst.html>`__ and references therein.

  * `reStructuredText Primer <https://docutils.sourceforge.io/docs/user/rst/quickstart.html>`__

  * `reStructuredText Quick Reference <https://docutils.sourceforge.io/docs/user/rst/quickref.html>`__

  * `reStructuredText Primer from Sphinx <https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/basics.html>`_

  * `reStructuredText Style Guide for Rubin Observatory Data Management Developers <https://developer.lsst.io/restructuredtext/style.html>`__

Style and voice
---------------

This is user documentation, which is different from academic writing.
Here are some tips:

- Make sure that all of your writing is in the service of users.

- Write with the active voice and in the present tense as much as possible.

- Address the user directly (“you can…”).
  Never use “we” since that’s ambiguous.
  If “we” means “LSST,” then name “LSST.”
  If “we” means the user, then say “you.”
  Even in tutorials, don’t use “we” to refer to an imaginary writer assisting the user.

- Write simply, with short sentences and short paragraphs.
  Chunk information with headers.

- Write confidently and precisely, yet also casually.
  Contractions are good.

For further discussion about specific style issues, refer to the `Google Developer Documentation Style Guide <https://developers.google.com/style/>`_.

File names
----------

Always use hyphens to separate words in file names.
Do not use underscores or spaces.

Templates
---------

A template folder is located in the :ref:`project directory <Project-Information>`.
It contains template pages for the Observatory Operations Documentation area, including a directory index and a procedure template.
Users wishing to create a new folder in this area should copy/paste the template folder, then update the contents accordingly.


Prose formatting in plain text
------------------------------

LSST DM's user documentation is written with soft wrapping, meaning that lines are as long as they need to be in the plain text file and the text editor is expected to handle wrapping.
Never hard wrap to an arbitrary line length.
Soft wrapping makes editing more approachable for more people (particularly those using the GitHub editor) and makes pull request line comments more useful.

More specifically, use `semantic line formatting <https://rhodesmill.org/brandon/2012/one-sentence-per-line/>`__.
Generally this means that each sentence should be its own line in the text file. This makes examining the differences between documentation versions easier while appearing as a single paragraph in the Sphinx rendered text.

Titles and headings
-------------------

Use sentence case for headings (don’t use title case).
Capitalize proper nouns as usual.

Try not to use more than two levels of heading hierarchy.
Using more than two levels of hierarchy might suggest an information architecture issue.

Also keep in mind DM’s `reStructuredText heading styles <https://developer.lsst.io/restructuredtext/style.html#sections>`__.

Links
-----

Never use "here" as link text.
Instead, make the relevant noun or phrase the link.

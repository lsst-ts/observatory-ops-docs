########################
Contributing to the docs
########################

This documentation is open source.
LSST welcomes contributions that make this documentation more useful and accurate.

Keep in mind that everyone participating in this project is expected to follow the LSST DM `Team Culture and Conduct Standards <https://developer.lsst.io/team/code-of-conduct.html>`__.

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
LSST can’t accept contributions that don’t fit with our strategy and roadmap.

These sections can help you create a successful pull request:

-  :ref:`building-the-docs`
-  :ref:`doc-style-guide`

.. _building-the-docs:

Building the docs locally
=========================

These are the basic steps to clone and build the docs:

.. code-block:: bash

   git clone https://github.com/lsst-ts/observatory-ops-docs
   cd nb_lsst_io

Next, create a Python virtual environment (with `venv <https://docs.python.org/3/tutorial/venv.html>`__, for example).

Once you’ve done that, install the Python dependencies:

.. code-block:: bash

   pip install -r requirements.txt

Finally, run these commands to build and validate the documentation:

.. code-block:: bash

   make html
   make linkcheck

To force a complete rebuild of the documentation, you can clean-up the existing build:

.. code-block:: bash

   make clean

.. _doc-style-guide:

Documentation style guide
=========================

This documentation is written in reStructuredText.
The `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__ can help you create effective reStructuredText.

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

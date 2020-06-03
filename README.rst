####################################
Observatory Operations Documentation
####################################

This is the source for the Rubin Observatory Operations Documentation.
This documentation is built with `Sphinx <https://www.sphinx-doc.org/en/master/>`__ and published to https://obs-ops.lsst.io.

GITHUB Structure
================

The following describes the various directories and their use in the GITHUB repository:

::

  Top-level of Repository
  |---Observing-Constraints         # Information about observing constraits
      |-index.rst                   # Source of page for Observing Constraints
  |---Observing-Interface-Setup     # Information about interface setup
      |-index.rst                   # Source of page for setting up the interface for observations
  |---Operational-Procedures        # Collection of operational procedures
      |---Auxiliary-Telescope       # Directory for Auxiliary Telescope Procedures
          |---Support-Operations    # Information about Support Operations
              |---Full-Observatory  # Information about Auxiliary Telescope that impacts the full observatory
                  |-Open-for-On-Sky-Operations.rst      # Information about ???
                  |-index.rst                           # Source of page for ???
              |---LATISS            # Directory for Auxiliary Telescope LATISS procedures
                  |-index.rst                           # Source of page for LATISS procedures
              |---Telescope         # Directory for Auxiliary Telescope observing procedures
                  |-index.rst                           # Source of page for Telescope procedures
                  |-park-telescope.rst                  # Procedure to park the Auxiliary Telescope
          |---Troubleshooting       # Information about troubleshooting Auxiliary Telescope elements
              |-E-stop.rst          # Information on emergency stopping of observations
      |---Main-Telescope            # Directory for Main Telescope Procedures
          |-README                  # Information on use and development for Main Telescope procedures
          |-index.rst               # Source of page for Main Telescope procedures
          |-comcam-cooldown.rst     # Procedure to prepare the operating environment and power-up the Commissioning Camera
      |---Tutorials                 # Directory of tutorials
          |-README.rst              # Information on development for tutorials
          |-index.rst               # Source of page for tutorials
          |-tutorial-template.rst   # Template for Main Telescope tutorials 
      |-index.rst                   # Source of page for operational procedures
  |---_static                       # Common directory for static objects
      |-README                      # Describes use of _static directory
  |---project                       # Directory for site information and template use
      |---Template-Folder               # Template directory to create new folders
          |-README.rst                  # README.rst file should describe use and development for a directory
          |-index.rst                   # Source of front-facing page for a directory on the site
          |-procedure-template.rst      # Template for source of a procedure
      |-contributing.rst                # Source describing contributing to the site
      |-index.rst                       # Source of page for Template-Folder directory
      |-license.rst                     # License information
  |-.gitignore                      # Configures GIT ignore functionality
  |-LICENSE                         # License information
  |-README.rst                      # Describes contributing to site
  |-Makefile                        # Configures building site in Sphinx
  |-conf.py                         # Configures building site in Sphinx
  |-requirements.txt                # Defines requirements and dependencies



Contributing
============

#. New to Sphinx and the reStructuredText format? Check out these resources and guides:

  * Reference Material from Docutils:

.. note:: 
       Links below will direct you to the HTML page. Docutils also provide the source file as a .txt, and you can retrieve the text file by changing `.html` to `.txt` in the URL. 
..

    - `reStructuredText Introductory and Tutorial Material <https://docutils.sourceforge.io/rst.html>`__
    and references therein, including:
       - `reStructuredText Primer <https://docutils.sourceforge.io/docs/user/rst/quickstart.html>`__
       - `reStructuredText Quick Reference <https://docutils.sourceforge.io/docs/user/rst/quickref.html>`__
  * `reStructuredText Primer from Sphinx <https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/basics.html>`__
   and the source file is linked on the right-hand sidebar. 
  * `reStructuredText Style Guide for Rubin Observatory Data Management Developers <https://developer.lsst.io/restructuredtext/style.html>`__

#. Create a virtual environment (if you haven't already):

   .. code-block:: bash

      python3 -m venv .venv
      source .venv/bin/activate

   **Tip:** activate this virtual environment in another shell by re-running the ``source`` command.

#. Install dependencies:

   .. code-block:: bash

      python -m pip install --upgrade pip
      python -m pip install -r requirements.txt

#. Build the site:

   .. code-block:: bash

      make html

   Open ``_build/html/index.html`` in a browser to review it.

#. To completely clear the build:

   .. code-block:: bash

      make clean

#. To check links:

   .. code-block:: bash

      make linkcheck

   If some links are behind a login, you might need to ignore them.
   Look at the ``linkcheck_ignore`` variable in ``conf.py`` for examples of how to do this.

Deployment
==========

Whenever you push a GitHub, the site is built for the corresponding branch.
Find your build at https://obs-ops.lsst.io/v. You can push to branch you've created at any time.

The ``master`` branch is always published as https://obs-ops.lsst.io. Only authorized individuals can push to ``master``.
To incorporate your suggestions, create a PR.

Approval Procedure
------------------

#. Contact Patrick.

#. Validate content.

#. Submit Push Request.

#. Code review process.

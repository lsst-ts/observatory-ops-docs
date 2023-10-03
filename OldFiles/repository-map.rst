.. This is the label that can be used as for cross referencing in the given area

.. _site-map:

###########################
GITHUB Repository Structure
###########################

.. Important::

    This is under heavy development and only in the very early stages of design.
    It should not be used nor consulted for a place of information at this time.

The following describes the various directories and their use in the GITHUB repository:

::

  Top-level of Repository
  |---Observing-Constraints         # Information about observing constraints
      |-index.rst                   # Source of page for Observing Constraints
  |---Observing-Interface-Setup     # Information about interface setup
      |-index.rst                   # Source of page for setting up the interface for observations
  |---Operational-Procedures        # Collection of operational procedures
      |---Auxiliary-Telescope       # Directory for Auxiliary Telescope Procedures
          |---Full-Observatory      # Information about Auxiliary Telescope that impacts the full observatory
              |-Open-for-On-Sky-Operations.rst      # Information about ???
              |-index.rst                           # Source of page for ???
          |---Support-Operations    # Information about Support Operations
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


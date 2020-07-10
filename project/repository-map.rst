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

    repository-repo
    ├── auxiliary-telescope # info related to auxiliary telescope
    │   ├── index.rst
    │   ├── README
    │   └── _static
    │       └── README
    ├── _build
    ├── conf.py
    ├── index.rst
    ├── interfaces # info related to interfaces/tools
    │   ├── index.rst
    │   ├── interface-setup
    │   │   ├── index.rst
    │   │   ├── nublado-notebook-environment-update.rst
    │   │   ├── README
    │   │   └── _static
    │   │       ├── nublado-interface.png
    │   │       └── README
    │   └── nublado.rst
    ├── LICENSE
    ├── main-telescope # Info related to the Main Telescope
    │   ├── index.rst
    │   ├── README
    │   └── _static
    │       └── README
    ├── Makefile
    ├── observing-constraints.rst
    ├── procedures # Procedures directory
    │   ├── commissioning # type of procedure, in this case commissioning
    │   │   ├── comcam-cooldown.rst
    │   │   └── index.rst
    │   ├── emergency
    │   │   ├── E-stop.rst
    │   │   └── index.rst
    │   ├── index.rst
    │   ├── operations
    │   │   ├── index.rst
    │   │   └── Open-for-On-Sky-Operations.rst
    │   ├── README
    │   └── _static
    │       └── README
    ├── project # For site related information
    │   ├── contributing.rst
    │   ├── implementation.rst
    │   ├── index.rst
    │   ├── license.rst
    │   ├── observatory-operations-style-guide.rst
    │   ├── repository-map.rst
    │   └── Templates
    │       ├── index.rst
    │       ├── index-template.rst
    │       ├── procedure-template.rst
    │       ├── Template-Folder
    │       │   ├── index.rst
    │       │   ├── README
    │       │   └── _static
    │       │       └── README
    │       └── tutorial-template.rst
    ├── README
    ├── requirements.txt
    ├── safety.rst # a general topic which does not have information yet, to split into more detailed topics
    ├── _static
    │   ├── README
    │   ├── Sunset_cropped_resampled_16x9.jpg
    │   └── Sunset_cropped_resampled.jpg
    └── tutorials # for tutorials
        ├── index.rst
        ├── README
        └── _static
            └── README


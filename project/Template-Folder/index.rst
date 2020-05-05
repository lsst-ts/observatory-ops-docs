.. This is a template top-level index file for a directory in the procedure's arm of the documentation. Each procedure will have its own sub-directory. This comment will be deleted when the template folder is copied to the destination.

.. This is the label that can be used as for cross referencing in the given area
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hypens
.. _Template-Folder-Template-Index-Section-Title:

############################
Template Index Section Title
############################

.. note::
    This is a template file that is associated with a template directory structure. This note will be deleted when
    the section is properly populated

This is the top-level description of what this section is about and what it includes. Below is a table of contents which is used to show the levels below this level. If there are no levels beneath this one, make sure the 2nd line is commented out.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :glob:

    *

..  Any Figures should be stored in the same directory as this file.
    To add images, add the image file (png, svg or jpeg preferred) to the same directory as this .rst file.
    The reST syntax for adding the image is:
    .. figure:: /filename.ext
        :name: fig-label
        :target: http://target.link/url
        Caption text.

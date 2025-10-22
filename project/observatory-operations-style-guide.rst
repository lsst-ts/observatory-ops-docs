.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Project-Observatory-Operations-Style-Guide:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

.. This file does not contain a title so it can match formatting in another location (contributing.rst).

##################################
Observatory Operations Style Guide
##################################

.. This section should provide a brief, top-level description of the page.

.. important::
    The information provided below is based on the `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__. A style guide specific to the procedure's arm of the documentation will be provided at a later time.

The information below can help you create effective reStructuredText for the `Rubin Observatory Operations Documentation <https://obs-ops.lsst.io>`__.

.. _Observatory-Operations-Style-Guide-Tone-and-Content:

Tone and Content
----------------

This is user documentation, which differs from academic writing.

- Make sure that all of your writing is in the service of users. 
- Keep it friendly and conversational, and write confidently and precisely. 
- Write simple, short sentences in short paragraphs.
- Do not use please and thank you. 
- Avoid "simply" ,"It's that simple", "It's easy", or "quickly" in a procedure. 

.. _Observatory-Operations-Style-Guide-Language-and-Grammar:

Language and Grammar
--------------------

- Write in second person and use *you* instead of *we*. 
- Use Present tense. Avoid the use of *would* and other conditional forms. 
- Write in the active voice to make instructions clear and direct. 

  .. admonition:: Active Voice
    
    The subject of the sentence is the person or thing performing the action
    
    Recommended: *Send the command to the server. The server will respond in 1 min*
    
    *Not* recommended: *The server is commanded and a response is received*

- Follow standard American spelling and punctuation rules as defined by Merriam-Webster. 

.. _Observatory-Operations-Style-Guide-Formatting-and-Organization:

Formatting, Punctuation, and Organization
-----------------------------------------

- Organize your document using sections and subsections.
- Avoid parentheses; use commas or dashes instead when adding information.
- Use numbered lists to present steps that must be completed in order.
- Use bulleted lists for general lists that do not follow a sequence.

.. _Observatory-Operations-Style-Guide-Titles-and-Headings:

Section Headings and Document Titles
------------------------------------

- Create descriptive headings and titles to facilitate navigation.
- Limit heading hierarchy to no more than two levels if possible.
- Use *Title Case* for headings and titles.
  
  .. admonition:: Title Case for Headings and Document Titles

    Capitalize the first and last words, as well as all other main words.

    Keep minor words, such as articles, coordinating conjunctions, and prepositions, in lowercase.

    Examples: *Science Fiction Classics: Exploring the Timeless Stories of Distant Galaxies* or *The Mystery of the Missing Shining Diamond*

.. _Observatory-Operations-Style-Guide-File-Names-and-Directories:

Filenames and Directory Names
-----------------------------
- Use hyphens to separate words in directory and file names.
- Do not use underscores or spaces, as hyphens improve search engine optimization.
- Apply *Start Case* for directory names
  
  .. admonition:: Start Case for Files and Directories

    Capitalize the first letter of each and every word.

    Separate words with hyphens.

    Examples: *AuxTel-Weather-Constraints* or *LSSTCam-Troubleshooting*

.. _Observatory-Operations-Style-Guide-Links:

Links
-----

-  Do not use use "here" as link text. Instead, make the relevant noun or phrase the link.
  
   .. admonition:: Links
    
    *Not* recommended: See `here <www.obs-ops.lsst.io>`__
    
    Recommended: See more in the `Auxiliary Telescope LOTO procedure <www.obs-ops.lsst.io>`__.

.. _Observatory-Operations-Style-Guide-Templates:

Templates
---------

A template folder is located in the :ref:`template directory <Templates-Template-Folder-Index>`.
It contains template pages for the Observatory Operations Documentation area, 
including procedure, informative and troubleshooting templates.
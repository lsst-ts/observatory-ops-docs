.. Review the README in this directory on instructions to contribute.
.. Static objects, such as figures, should be stored in the _static directory. Review the _static/README in this file's directory on instructions to contribute.
.. Do not remove the comments that describe each section. They are included to provide guidance to contributors.
.. Do not remove other content provided in the templates, such as a section. Instead, comment out the content and include comments to explain the situation. For example:
	- If a section within the template is not needed, comment out the section title and label reference. Do not delete the expected section title, reference or related comments provided from the template.
    - If a file cannot include a title (surrounded by ampersands (#)), comment out the title from the template and include a comment explaining why this is implemented (in addition to applying the ``title`` directive).

.. This is the label that can be used as for cross referencing this file.
.. Recommended format is "Directory Name"-"Title Name"  -- Spaces should be replaced by hyphens.
.. _Project-Observatory-Operations-rst-reference-guide:
.. Each section should includes a label for cross referencing to a given area.
.. Recommended format for all labels is "Title Name"-"Section Name" -- Spaces should be replaced by hyphens.
.. To reference a label that isn't associated with an reST object such as a title or figure, you must include the link an explicit title using the syntax :ref:`link text <label-name>`.
.. An error will alert you of identical labels during the build process.

###########################
reST Style Reference Guide
###########################

A quick reference for reST formatting for the procedural documentation 
included in `Rubin Observatory Operations Documentation <https://obs-ops.lsst.io>`__.

The information provided below is based on the `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__. 

ReStructuredText is an *extensible* markup language used by `LSST`_.

.. _LSST: http://lsst.org


.. _Observatory-Operations-reST-Style-Reference-Guide-In-line-Text-Styling:

In-line Text Styling
====================

Italics
-------
*Italics* can be used to lend emphasis to specific ideas, concepts and new terms, 
e.g. *scheduling algorithm*, *seeing*, *ATCS cRIO user*,
highlighting their importance within the text. 

Use also *italics* to declare *hostnames*, e.g. *aux-brick01.cp.lsst.org*. 

.. list-table:: Italics
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

         *text in italics*

         *aux-brick01.cp.lsst.org*

     - *text in italics*

       *aux-brick01.cp.lsst.org*

Bold 
----
**bold** formatting serves to provide a stronger emphasis on specific ideas or key steps within procedures. 
However, use sparingly to maintain its impact and avoid overwhelming the readers.  

.. list-table:: Bold
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

         1. **Connect to the dimm machine** using ssh. 
         User and password are stored under DIMM remote 
         login in the 1Password Operators Vault.

     - 1. **Connect to the dimm machine** using ssh. 
          User and password are stored under *DIMM remote login* in the 1Password Operators Vault.


Monospaced
----------
Utilize double back quotes to generate a monospaced style, 
appropriate for referencing variables, configuration parameters, and summary states. 

.. list-table:: Monospaced
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

         Transition the CSC to ``STANDBY``. 
         Set the *configuration* ``config`` to ``None``.
         Send the CSC back to ``ENABLED``

     - Transition the CSC to ``STANDBY``. 
       Set the *configuration* ``config`` to ``None``.
       Send the CSC back to ``ENABLED``


.. _Observatory-Operations-reST-Style-Reference-Guide-Filenames:

Filenames and paths
--------------------

Apply this formatting style consistently to represent file and directory names, 
paths, and SAL scripts throughout the documentation. 
When referring to SAL scripts, ensure that the full path is included.

.. list-table:: Filenames and paths
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

        :file:`auxtel/standard_scripts/prepare_for/vent.py`

     - :file:`auxtel/standard_scripts/prepare_for/vent.py`


.. _Observatory-Operations-reST-Style-Reference-Guide-Shell-Commands:

Shell Commands 
---------------

In-line shell commands that are generally compact can be expressed as: 

.. list-table:: Shell Commands
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

        :command:`ls -la`

     - :command:`ls -la`

.. _Observatory-Operations-reST-Style-Reference-Guide-KeyBoard-Shortcuts:

Keyboard Shortcuts 
------------------
When referring to key combinations for specific actions, 
employ the format below to represent the keys, 
such as using the '+' symbol to denote simultaneous key presses. 

.. list-table:: Keyboard shortcuts
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

        :kbd:`Control+q+A`

     - :kbd:`Control+q+A`


.. _Observatory-Operations-reST-Style-Reference-Guide-Interface-Labels:

Buttons or text labels in interactive programs 
----------------------------------------------
When indicating user interaction with buttons, 
text labels or tabs (e.g. in LOVE, EUIs), use the formatting shown below. 

.. list-table:: Buttons in interactive programs
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

        :guilabel:`Main Axes` 

        :guilabel:`Power Supply`
        
        :guilabel:`Change to Configuration`

     - :guilabel:`Main Axes` 

       :guilabel:`Power Supply`
        
       :guilabel:`Change to Configuration`



.. _Observatory-Operations-reST-Style-Reference-Guide-Inline-math:

Math
-------------
The ``:math:`` *directive* can be used in-line or in a separate paragraph. 

.. list-table:: Math formulae
   :widths: 40 40
   :header-rows: 1

   * - reST
     - renders as
   * - ::

        :math:`\mu = -2.5 \log_{10}(\mathrm{DN}) + m_0`

     - :math:`\mu = -2.5 \log_{10}(\mathrm{DN}) + m_0`



.. _Observatory-Operations-reST-Style-Reference-Guide-Headings:

Headings
========

Start each section with a heading. Use heading 1 for the page title, heading 2 for the page's main sections, and headings 3, 4
and 5 for the respectively subsections. 

Use *title case* for headings and tiles: 
First and last words are always capitalized, as well as all other main words. 
“Minor words” like articles, coordinating conjunctions and prepositions are lower-case. 


::

  ######################
  Page Title - Heading 1
  ######################

  Heading 2
  =========

  Heading 3
  ---------

  Heading 4
  ^^^^^^^^^

  Heading 5
  """""""""

.. _Observatory-Operations-reST-Style-Reference-Guide-Tables-of-Contents:

Table of contents
==================
With the *directive* ``toctree::`` you can organize your content into a coherent hierarchy, 
mirroring the structure and functionality of a tree data structure.

Improving the flow and readability, the table of content also facilitates seamless navigation 
as it creates an intuitive sidebar menu to the left, and inserts in-page navigation links.  

::
    
    .. toctree::
        :titlesonly:

       ../Safety/emergency-response-guide
       ../Safety/out-of-hours-support
       license
       ../AuxTel/AuxTel-Non-standard-Operations/AuxTel-Non-Standard-Operations-index.rst


.. _Observatory-Operations-reST-Style-Reference-Guide-Code:

Code
=====

To markup content or *code blocks* that readers can easily copy and paste for use elsewhere, utilize the *directives* below. 
These directives will appear as separate paragraphs enclosed within a box, 
making them suitable for longer lines or extensive chunks of code,
or to draw focus on crucial information.


.. _Observatory-Operations-reST-Style-Reference-Guide-Bash:

Bash prompts and commands
-------------------------
::
  
  .. prompt:: bash

   mkdir -p hello/world
   cd hello/world

renders as:

.. prompt:: bash

   mkdir -p hello/world
   cd hello/world


.. _Observatory-Operations-reST-Style-Reference-Guide-Text:

SAL scripts configuration - Text
--------------------------------
This formatting should be used when detailing the configuration required for a SAL script. 
Use the parameter ``:caption:`` with the name of the SAL script to display it above the block of configuration. 

The ``code-block::text`` *directive* can be used to preserve the formatting and spacing of text.
This feature is particularly useful when displaying content that relies on precise spacing, layout or format, 
such as code snippets, structured data, or formatted text excerpts.

::
  
  .. code-block:: text
    :caption: run_command.py

    component: MTDome
    cmd: stop
    parameters:
        engageBrakes: true
        subSystemIds: 1   

renders in HTML as:

.. code-block:: text
   :caption: run_command.py

    component: MTDome
    cmd: stop
    parameters:
        engageBrakes: true
        subSystemIds: 1   


.. _Observatory-Operations-reST-Style-Reference-Guide-Code-Blocks:

Code blocks 
----------- 

Use the ``code_block:: python`` or ``code_block:: JSON`` *directive* to adequately display python or JSON code, respectively.  
You may also add the parameter ``:caption::`` to this *directive* to include a title above the code. 

Python
^^^^^^

::
  
  .. code-block:: python

    large_file_object = await remote.evt_largeFileObjectAvailable.aget(timeout=5)

    print(large_file_object.url)

will be displayed as, in python language:

.. code-block:: python

    large_file_object = await remote.evt_largeFileObjectAvailable.aget(timeout=5)

    print(large_file_object.url)


JSON
^^^^

::
  
  .. code-block:: JSON
    
    {
            "name": "auxtel/take_image_latiss.py",
            "standard": true,
            "parameters": {
                "image_type": "FLAT",
                "filter": "SDSSr_65mm",
                "grating": "empty_1",
                "reason": "daily_sflat",
                "exp_times": [
                    0.5,
                    0.5,
                    12.8,
                    12.8,
                ]
            }
        }


is displayed in HTML like:

.. code-block:: JSON

    {
            "name": "auxtel/take_image_latiss.py",
            "standard": true,
            "parameters": {
                "image_type": "FLAT",
                "filter": "SDSSr_65mm",
                "grating": "empty_1",
                "reason": "daily_sflat",
                "exp_times": [
                    0.5,
                    0.5,
                    12.8,
                    12.8
                ]
            }
        }

.. _Observatory-Operations-reST-Style-Reference-Guide-Images:

Images and other media
======================

Images must be stored in the :file:`./_static/` directory within your working directory, in PNG or GIF formats. 
Use the ``..figure::`` *directive* and always include a descriptive caption for each figure. 

::

  .. figure:: ./_static/Snow_Rubin.png
    :name: Your figure

    This is the caption for this snowy image of Rubin Observatory.  


will show:

.. figure:: ./_static/Snow_Rubin.png
    :name: Your figure

    This is the caption for this snowy image of Rubin Observatory.  

.. _Observatory-Operations-reST-Style-Reference-Guide-Links:

Links
==================

.. _Observatory-Operations-reST-Style-Reference-Guide-External-Links:

External Links
---------------
There are two methods to link to external references. 
Both are equally valid. 

In-line External Link
^^^^^^^^^^^^^^^^^^^^^

The most direct and compact using the syntax **`anchor text <URL>`__**. The disadvantage is that 
the anchor text can not be later referenced and it's a little harder to read. 

::
  
  You can check first on 
  `LSST DM reStructuredText style guide
  <https://developer.lsst.io/restructuredtext/style.html>`__.

is rendered in HTML as:

You should first check on `LSST DM reStructuredText style guide <https://developer.lsst.io/restructuredtext/style.html>`__.

Using a Link Reference
^^^^^^^^^^^^^^^^^^^^^^

The advantage is readability and reusability. 

:: 

  When writing for this repository, it's a good idea to refer 
  to `LSST DM reStructuredText style guide`_. 
  You might even enjoy the literature found 
  in the `LSST DM reStructuredText style guide`_.

  .. _LSST DM reStructuredText style guide: https://developer.lsst.io/restructuredtext/style.htm


which would render as:

When writing for this repository, it's a good idea to refer to `LSST DM reStructuredText style guide`_. 
You might even enjoy the literature found in the same `LSST DM reStructuredText style guide`_.

.. _LSST DM reStructuredText style guide: https://developer.lsst.io/restructuredtext/style.html

.. _Observatory-Operations-reST-Style-Reference-Guide-Internal-Links:

Internal Links to Labels
-------------------------
You can also send your reader to another section, in the current page or to a section in another page in this repository. 
These internal links reference the labels that are placed before each section, image, table or code block. 

To create a label, start with an underscore and separate individual words with hyphens. 
Prefix the label with *..* to inform the reST parser that the following text is to be treated as a label.  
To complete the label reference, ensure that the label text is followed by a colon (:). 
In practice, the syntax for creating a label will look like this 

*.. _label-name:*

This section, for instance, 
is preceded by 

*.. _Observatory-Operations-reST-Style-Reference-Guide-Internal-Links:*

With the ``:ref:`` *directive* you can create the link to any *label* using 

::
  
  :ref:`[link_text] <label-name>` in general. For instance, 
  to create an internal link to this section  
  you should write
  :ref:`internal link section <Observatory-Operations-reST-Style-Reference-Guide-Internal-Links>`.


rendered in HTML as:

**:ref:`[link_text] <label-name>`** in general. For instance, 
to create an internal link to this section  
you should write
:ref:`internal link section <Observatory-Operations-reST-Style-Reference-Guide-Internal-Links>`.


.. _Observatory-Operations-reST-Style-Reference-Guide-Tables:

Tables
==================
The ``.. list-table::`` *directive* facilitates the creation of tables in your docs. 
Asterisks indicate each row, and hyphens denote each column (* and - must be aligned, respectively). 

::

  .. list-table:: Title
   :widths: 25 25 25
   :header-rows: 1

   * - Heading: row 1, column 1
     - Heading: row 1, column 2
     - Heading: row 1, column 3
   * - Row 2, column 1
     - (Even if the content is empty must be accounted for)
     - Row 2, column 3
   * - Row 3, column 1
     - Row 3, column 2
     - Row 3, column 3

.. list-table:: Title
   :widths: 25 25 25
   :header-rows: 1

   * - Heading: row 1, column 1
     - Heading: row 1, column 2
     - Heading: row 1, column 3
   * - Row 2, column 1
     - (Even if the content is empty each cell must be accounted for)
     - Row 2, column 3
   * - Row 3, column 1
     - Row 3, column 2
     - Row 3, column 3

.. _Observatory-Operations-reST-Style-Reference-Guide-Notes:

Notes
======

Use these to make specific information stand out from the surrounding text, either to convey critical content or to draw attention 
to certain aspects of the document. Use admonitions sparingly. There is *some* evidence that readers skip them.


:: 

  .. warning:: 

    Critical information

  .. caution:

    Proceed carefully. 

  .. note::

    A note looks like this. 

  .. tip::

    Maybe useful. 

  .. admonition:: Personalized Title

    This is how an admonition looks like. Do you like it?


.. warning:: 

  Critical information

.. caution::

  Proceed carefully. 

.. note::

  A note looks like this. 

.. tip::
  
  Maybe useful. 

.. admonition:: Personalized Title

  This is how an admonition looks like. Do you like it?

.. _Observatory-Operations-reST-Style-Reference-Guide-Lists:

Lists
=====

.. _Observatory-Operations-reST-Style-Reference-Guide-Ordered-Lists:

Ordered Lists
-------------

Use hash symbols for numbered lists:

::

  #. Step 1
  
  #. Step 2
  
     #. Step 2.1

     #. Step 2.2

     #. Step 2.3

  #. Step 3

     #. Step 3.1

  #. Step 4


#. Step 1
  
#. Step 2
  
   #. Step 2.1

   #. Step 2.2

   #. Step 2.3

#. Step 3

   #. Step 3.1

#. Step 4

.. _Observatory-Operations-reST-Style-Reference-Guide-Unordered-Lists:

Unordered Lists
---------------

Use asterisks for bulleted lists:

::

  * one
  
  * two
  
  * three
  
  * four

* one
  
* two
  
* three
  
* four

.. _Observatory-Operations-reST-Style-Reference-Guide-Diagrams:

Diagrams 
========
Uses `Mermaid <https://documenteer.lsst.io/guides/diagrams.html>`__ *directive* to generate engaging and visually appealing conceptual diagrams by using plain text. 

::
  
  .. mermaid::

   flowchart LR
     Checkout(Daytime Checkout)
     Checkout --> C(Calibrations)
     C --> V(Venting)
     V --> S(On-Sky)
     Checkout --> V
     Checkout --> S
    

.. mermaid::

   flowchart LR
     Checkout(Daytime Checkout)
     Checkout --> C(Calibrations)
     C --> V(Venting)
     V --> S(On-Sky)
     Checkout --> V
     Checkout --> S


.. _Observatory-Operations-reST-Style-Reference-Guide-Sidebar:

Sidebar
=======
You can add a sidebar with important information or a table of contents for instance, like the one here:

:: 

  ..  sidebar:: 

    Here's a little table of contents for this page. Congratulations for making it to the end:
    * :ref:`Text Styling <Observatory-Operations-reST-Style-Reference-Guide-In-line-Text-Styling>`
    * :ref:`Code <Observatory-Operations-reST-Style-Reference-Guide-Code>`
    * :ref:`Images <Observatory-Operations-reST-Style-Reference-Guide-Images>`
    * :ref:`Links <Observatory-Operations-reST-Style-Reference-Guide-Links>`
    * :ref:`Tables <Observatory-Operations-reST-Style-Reference-Guide-Tables>`
    * :ref:`Notes <Observatory-Operations-reST-Style-Reference-Guide-Notes>`
    * :ref:`Lists <Observatory-Operations-reST-Style-Reference-Guide-Lists>`
    * :ref:`Diagrams <Observatory-Operations-reST-Style-Reference-Guide-Diagrams>`
    * :ref:`Sidebar <Observatory-Operations-reST-Style-Reference-Guide-Sidebar>`


..  sidebar:: 

    Here's a little table of contents for this page. Congratulations for making it to the end:
    * :ref:`Text Styling <Observatory-Operations-reST-Style-Reference-Guide-In-line-Text-Styling>`
    * :ref:`Code <Observatory-Operations-reST-Style-Reference-Guide-Code>`
    * :ref:`Images <Observatory-Operations-reST-Style-Reference-Guide-Images>`
    * :ref:`Links <Observatory-Operations-reST-Style-Reference-Guide-Links>`
    * :ref:`Tables <Observatory-Operations-reST-Style-Reference-Guide-Tables>`
    * :ref:`Notes <Observatory-Operations-reST-Style-Reference-Guide-Notes>`
    * :ref:`Lists <Observatory-Operations-reST-Style-Reference-Guide-Lists>`
    * :ref:`Diagrams <Observatory-Operations-reST-Style-Reference-Guide-Diagrams>`
    * :ref:`Sidebar <Observatory-Operations-reST-Style-Reference-Guide-Sidebar>`
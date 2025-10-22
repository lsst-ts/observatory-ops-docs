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

If you spot an issue with the documentation, the best thing to do is `raise a GitHub issue in the observatory-ops-docs repositiry (repo) <https://github.com/lsst-ts/observatory-ops-docs/issues/new>`__.
Include any relevant URLs with your issue description.

.. _Contributing-Add-Update:

Adding/Updating Documentation
=============================

| You can contribute directly to the `observatory-ops-docs <https://github.com/lsst-ts/observatory-ops-docs>`__ repository by working with a 
| *Jira & Git(Hub) Workflow*. If you’re intending to make a substantial change, it’s a good idea to create a GitHub issue first with your proposal. Rubin Observatory can’t accept contributions that don’t fit with our strategy and roadmap.

These sections can help you to successfully contribute to the documentation:

* :ref:`Contributing-Building-the-Docs`
* :ref:`Contributing-Deployment`
* :ref:`Contributing-Doc-Style-Guide`

For a refresher, refer to the :ref:`Git Commands for Documentation <observatory-operations-git-commands>`.

.. _Contributing-Building-the-Docs:

Building the Documentation Locally
==================================

These are the basic steps to clone and build documents for the first time on your local computer. 
Keep in mind that some steps are not required if you have already started working on documentation 
prior to accessing this page.

.. note::   
   For the code blocks found in the **Notes & Configurations** column:

   * Executable code is denoted by the :kbd:`>>` symbol.
   * Comments are marked with the :kbd:`#` symbol.
   * Everything else is represented as outputs that should be displayed in the wrap/terminal.

.. _Contributing-Preconditions:

Preconditions
--------------

Make sure that your computer is set up with the correct software before attempting to work on any documentation.
The following steps provide a guideline for how to prepare your local computer to access observatory-ops-docs.

.. list-table::
   :header-rows: 1
   :stub-columns: 1
   :widths: 5 40 55

   * - 
     - Steps
     - Notes & Configurations
   * - 1.
     - **Install** `Visual Studio Code (VSCode) <https://code.visualstudio.com/>`_. 
     - 
        It is our **recommended text editor** to work with reStructuredText (RST) language and Sphinx.
        Some useful extensions for Visual Studio Code when writing documents for Rubin in reStructuredText are:

        * `reStructuredText <https://marketplace.visualstudio.com/items?itemName=lextudio.restructuredtext>`_
        * `reStructuredText Syntax highlighting <https://marketplace.visualstudio.com/items?itemName=trond-snekvik.simple-rst>`_
   * - 2.
     - **Clone** GitHub repository into a local directory.
     - In your terminal:

       .. code-block:: bash

         >> git clone https://github.com/lsst-ts/observatory-ops-docs.git 

   * - 3.
     - **Open** the repository locally in VSCode.
     - | To open the repository, select: 
       | :guilabel:`File` :math:`\Rightarrow` :guilabel:`Open Folder` :math:`\Rightarrow` :guilabel:`observatory-ops-docs`
   * - 4.
     - **Install project dependencies** in a Python virtual environment.
     - In your terminal:

       .. code-block:: bash

         # Create virtual environment
         >> python3 -m venv .venv
         >> source .venv/bin/activate

         # Add project dependencies
         >> pip install --upgrade pip  
         >> pip install -r requirements.txt

   * - 5.
     -  **Install** `SourceTree <https://www.sourcetreeapp.com/>`_.
     - | This program helps **visualize** the repository tree **interact** with local and remote branches. To open the repository, select: 
       | :guilabel:`File` :math:`\Rightarrow` :guilabel:`Open...` :math:`\Rightarrow` :guilabel:`observatory-ops-docs`


.. _Jira-and-Git-Workflow:

Jira & Git(Hub) Workflow
------------------------

Once you have completed the :ref:`Contributing-Preconditions`, you are ready to start building your own documents. These steps provide 
an overall workflow for writing documentation in your local repository and moving it into your remote GitHub repository. 
This workflow should help either start a new Jira ticket or to continue with a previous ticket.

.. list-table::
   :header-rows: 1
   :stub-columns: 1
   :widths: 5 40 55

   * - 
     - Steps
     - Notes & Configurations
   * - 1.
     - **Create** a `Jira Ticket <https://rubinobs.atlassian.net/jira/your-work>`_.
     - 
       .. admonition:: Jira Ticket Layout
         :class: hint

         | **Project:** SITCOM Work Management
         | **Issue Type:** Story
         | **Component:** SIT-Com Organizational Support
         | **Labels:** documentation
         | **Assignee:** The person that's going to write it (you or someone else).
         | **Reviewer:** Subsystem specialist/manager or one of the other members from the OS team.
         | **Start and End Date:** Estimate time interval.
         * Add links to pages if applicable.
   * - 2.
     - Remember the ticket number and **update your progress** on the ticket.
     - 
       * The new Jira Ticket will have a unique 4-number identifier (e.g., **SITCOM-1811**).
       * | Once you start working, move ticket from: 
         | :guilabel:`To-Do` :math:`\Rightarrow` :guilabel:`In Progress`
   * - 3.
     - **Set up** the necessary tools for editing documentation.
     - 
       * Open VSCode and access the cloned repository to have a visual to its structure and edit the files.
       * Open SourceTree and access the cloned repo to have a visual of the branch structure.
       * Open a terminal on your laptop and enter the folder of the cloned repository:

       In your terminal:

       .. code-block:: bash

        # Navigate to the folder:
        >> cd /path/to/observatory-ops-docs

        # Check that you are in correct folder:
        >> pwd
           /path/to/observatory-ops-docs
   * - 4.
     - **Initialize** your local directory and **check your connection** to the obs-ops-docs repository.
     - In your terminal:

       .. code-block:: bash

          # Initialize:
          >> git init

          # Check remote is correct:
          >> git remote -v
              origin  git@github.com:lsst-ts/observatory-ops-docs (fetch)
              origin  git@github.com:lsst-ts/observatory-ops-docs (push)

          # If in different repository, switch using:
          >> git remote set-url origin git@github.com:lsst-ts/observatory-ops-docs

       .. note::

        This step is important for *switching between multiple repositories*. 
        If you are working with **documentation only** then **skip this step**.
   * - 5.
     - **Enter** your python virtual environment.
     - In your terminal:

       .. code-block:: bash

         >> source .venv/bin/activate
   * - 6.
     - **Update** local repository and **create a new branch** for the Jira ticket.
     - In your terminal:

       .. code-block:: bash

         # Update main branch
         >> git checkout main
         >> git fetch --all
         >> git pull

         # Create ticket branch (e.g., SITCOM-1811)
         >> git branch tickets/SITCOM-1811

         # Move to ticket branch:
         >> git checkout tickets/SITCOM-1811

       .. note::
         If you are continuing previous work:

         * Check that you are on the correct branch with ``git branch``.
         * If on the wrong branch, move to the branch of interest using ``git checkout``.
         * Make sure to update the ``main`` branch each time before working in your ticket branch.
   * - 7.
     - **Start editing** RST files in obs-ops-docs using VSCode. 
     - Additonal aid for working with RST files:

       .. admonition:: reStructuredText Review
          :class: info

          See the :ref:`Contributing-Doc-Style-Guide` to find resources on working with RST files and Sphinx 
          in the `Rubin Documentation style <https://obs-ops.lsst.io/project/observatory-operations-reST-reference.html>`_.
   * - 8.
     - **Verify the html page** loads properly using the terminal commands.
     - In your terminal:

       .. code-block:: bash

         # Build HTML Webpage:
         >> make html

         # Check Weblinks:
         >> make linkcheck

         # Visualize Changes Locally:
         >> open _build/html/index.html
   * - 9.
     - **Add links to the ignore list** in documenteer file (optional).
     - | Running a linkcheck may cause errors for links that are VPN-dependent or unavailable outside the summit.
         Therefore they must be ignored for proper deployment.
      
       | In VSCode: 

       .. code-block:: bash

        # Navigate to documenteer.toml and locate the linkcheck ignore list:
        [sphinx.linkcheck]
        ignore = [
            'http://love01.cp.lsst.org/*',
            'http://localhost:\d+/*',
             ...   ] 

        # Add new links to the end of the list:
        [sphinx.linkcheck]
        ignore = [
            'http://love01.cp.lsst.org/*',
            'http://localhost:\d+/*',
             ... ,   
             'https://chronograf-base-efd.lsst.codes/', ] 

       .. note::

        Please only *add new links* and **avoid modifying** existing ones, as the check applies to the entire repository.
   * - 10.
     - **Check changes** on git and **commit** the changes.
     - In your terminal:

       .. code-block:: bash

         # Display files that need to be staged:
         >> git status

         # Stage files:
         >> git add -A

         # Commit files with message included:
         >> git commit -m "INSERT MESSAGE HERE!"   

       .. admonition:: Important
         :class: warning

         When writing commits, make sure that they are **short** yet **descriptive**.
   * - 11.
     - **Push the commits** from the local repository to the remote repository.
     - In your terminal:

       .. code-block:: bash

          # Pushing for the first time:
          >> git push --set-upstream origin tickets/SITCOM-1811

          # Successive pushes are simply:
          >> git push
   * - 12.
     - **Check remote webpage** after deployment to see if the RST files loaded properly.
     -
       * Remote webpage: https://obs-ops.lsst.io/v/
       * Select your Jira ticket to view webpage.

.. _Contributing-Deployment:

Deployment
==========

Whenever you push to the GitHub repository, the site is built for the corresponding branch. 
You can push to a branch you've created at any time.

However, the ``main`` branch is always published as https://obs-ops.lsst.io. Only authorized individuals can merge directly to ``main`` (may be delegated).
To incorporate your suggestions, you will need permission from others before you can merge your work.

.. _Contributing-PR: 

Pull Requests & Review Process
------------------------------

Once your document is ready for review, a **pull request** must be created and sent to reviewers. 
This allows peer-reviewed verification of any potential updates to documentation in the https://obs-ops.lsst.io webpage. 
Reviewers can approve/disapprove mergers as well as provide corrections to your documents before deployment.
The following steps will guide you through creating and managing a pull request on `GitHub <https://github.com/lsst-ts/observatory-ops-docs>`_.

.. list-table::
  :header-rows: 1
  :stub-columns: 1
  :widths: 5 40 55

  * - 
    - Steps
    - Notes & Configurations
  * - 1.
    - | **Navigate to obs-ops GitHub** main page, and in the :guilabel:`branch` menu, choose the branch with your commits (e.g., 
      | :guilabel:`tickets/SITCOM-1811`).
    - 
     .. image:: _static/Obs-Ops-GitHub-Main.png
      :width: 100%
  * - 2.
    - **Create a new pull request** for the associated branch.
    - 
     | After recent changes, a yellow banner will appear (see below) where you can click 
     | :guilabel:`Compare & pull request`:

     .. image:: _static/pull-request-compare-pull-request.png
      :width: 125%

     | If there is no banner, you can create a new pull request on Github by selecting 
     | :guilabel:`Pull requests` :math:`\Rightarrow` :guilabel:`New pull request`:

     .. image:: _static/create-pull-request.png
      :width: 125%
  * - 3.
    - Use the :guilabel:`base` branch dropdown menu to **select the main branch** you'd like to merge your changes into, then use the 
      :guilabel:`compare` branch drop-down menu to **select the ticket branch** where you made your changes.
    - 
     .. image:: _static/Compare-changes.png
      :width: 100%

     | :guilabel:`base` :math:`\Rightarrow` :guilabel:`main`
     | :guilabel:`compare` :math:`\Rightarrow` :guilabel:`tickets/SITCOM-1811`

  * - 4.
    - **Add a title and description** for your pull request and **include reviewers**.
    - 
       * **Title** should be the Jira ticket number: *"Tickets/SITCOM-1811''*.
       * **Description** should *summarize all of the commits* that have been pushed onto the ticket branch.
       * | To **add reviewers**, click on the 
         | :guilabel:`Reviewers` tab to the right side of the pull request page, and 
          enter the GitHub usernames of the appropriate reviewers. These reviewers should also be added to both 
          the **Jira ticket** (as *reviewers*) and the **RST document** 
         | (as *contributors*).
  * - 5.
    - Click :guilabel:`Create Pull Request` to **begin review process**.
    - 
     * | Move your Jira ticket from: 
       | :guilabel:`In Progress` :math:`\Rightarrow` :guilabel:`In Review`.
  * - 6.
    - | Once comments are given, **fix corrections** using the 
      | :ref:`Jira-and-Git-Workflow` steps. When the reviewers approve of the Pull Request, **proceed** to the :ref:`Contributing-Merge-PR` steps.
    - 
     * | Move your Jira ticket from: 
       | :guilabel:`In Review` :math:`\Rightarrow` :guilabel:`Reviewed`.

     .. note:: 
       After you have opened your pull request, **you can continue making changes to files** by adding new commits 
       to your head branch regardless if reviewer comments were sent.

.. _Contributing-Merge-PR:

Merging a Pull Request 
--------------------

Once the pull request is approved, the document is ready to combine with the main page. 
Now all that is left is to make sure our branch is up-to-date, squash all of the commits 
that were created into a single commit, and merge our branch into the main project.

.. list-table::
  :header-rows: 1
  :stub-columns: 1
  :widths: 5 40 55

  * - 
    - Steps
    - Notes & Configurations
  * - 1.
    - Once reviewers approve of the pull request, and all comments were addressed, 
      **rebase your branch** to allow a smoother merging process.
    - In your terminal:

      .. code-block:: bash

        # Update main branch:
        >> git checkout main
        >> git fetch --all
        >> git pull

        # Rebase main branch so that
        # ticket branch is leading:
        >> git checkout tickets/SITCOM-1811
        >> git rebase origin/main

        # FORCE push the changes into your
        # remote repository:
        >> git push --force-with-lease

      .. warning::

        | **DO NOT REBASE USING GITHUB!** 
        | Updating on GitHub will likely cause issues between your local and remote repositories.
  * - 3.
    - Once the rebase is successful, **squash your commits** into a single commit to reduce clutter in the log of the obs-ops workflow.
    - There are two options to use when squashing commits:
      
      1. Visually using **Sourcetree**:
      
      .. vimeo:: 1063614564
        :width: 100%

      |
      
      2. **Git Terminal Commands** while in ticket branch:

      .. vimeo:: 1063607809
        :width: 100%

      a. | Verify which commits you should squash using 
         | :command:`git log` to display them.
      b. Once the commits are squashed, force push them again: :command:`git push --force-with-lease`.
  * - 4.
    - **Merge your ticket** branch into the main branch.
    - In your terminal:

      .. code-block:: bash

        # Update local repository 
        # with the latest changes.
        >> git pull origin main

        # Switch to the base branch 
        # of the pull request.
        >> git checkout main

        # Merge the head branch into the 
        # base branch safely and preserve history.
        >> git merge tickets/SITCOM-1811 --no-ff

        # Push the changes.
        >> git push -u origin main

      * Move Jira ticket from: :guilabel:`Reviewed` :math:`\Rightarrow` :guilabel:`Done`

      .. note::
        You can merge directly in GitHub as well using the 
        :guilabel:`Merge pull request` button at the bottom of your pull request page.
  * - 5.
    - Once merge was successful, **update** your local repository and **prune any branches** that have already merged in remote.
    - In your terminal:

      .. code-block:: bash

        # To update and prune:
        >> git fetch --all -p
        >> git pull

        # (Optional) to prune a local branch:
        >> git branch -d tickets/SITCOM-1811

.. _Contributing-Doc-Style-Guide:

Documentation Style Guide
=========================

.. _Contributing-New-to-reST:

New to reStructuredText and Sphinx
-----------------------------------

Check out these resources and guides. Sources files are available to compare raw reST and HTML outputs.

  * `reStructuredText Introductory and Tutorial Material <https://docutils.sourceforge.io/rst.html>`__ and references therein.

  * `reStructuredText Primer <https://docutils.sourceforge.io/docs/user/rst/quickstart.html>`__

  * `reStructuredText Quick Reference <https://docutils.sourceforge.io/docs/user/rst/quickref.html>`__

  * `reStructuredText Primer from Sphinx <https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/basics.html>`_

  * `reStructuredText Style Guide for Rubin Observatory Data Management Developers <https://developer.lsst.io/restructuredtext/style.html>`__

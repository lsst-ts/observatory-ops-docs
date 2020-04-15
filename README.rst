####################################
Observatory Operations Documentation
####################################

This is the source for the Rubin Observatory Operations Documentation.
This documentation is built with `Sphinx <https://www.sphinx-doc.org/en/master/>`__ and published to https://obs-ops.lsst.io.

Contributing
============

1. Create a virtual environment (if you haven't already):

   .. code-block:: bash

      python3 -m venv .venv
      source .venv/bin/activate

   **Tip:** activate this virtual environment in another shell by re-running the ``source`` command.

2. Install dependencies:

   .. code-block:: bash

      python -m pip install --upgrade pip
      python -m pip install -r requirements.txt

3. Build the site:

   .. code-block:: bash

      make html

   Open ``_build/html/index.html`` in a browser to review it.

4. To completely clear the build:

   .. code-block:: bash

      make clean

5. To check links:

   .. code-block:: bash

      make linkcheck

   If some links are behind a login, you might need to ignore them.
   Look at the ``linkcheck_ignore`` variable in ``conf.py`` for examples of how to do this.

New to Sphinx and the reStructuredText format?
Check out our `ReStructuredText Style Guide <https://developer.lsst.io/restructuredtext/style.html>`__.

Deployment
==========

Whenever you push a GitHub, the site is built for the corresponding branch.
Find your build at https://obs-ops.lsst.io/v.

The ``master`` branch is always published as https://obs-ops.lsst.io.

clxx website
============

This is website project for clxx project. It's based on jekyll_ blog-aware
templating engine.

Tips for developers
-------------------

Install bundler first (if you don't have one):

.. code:: bash

    apt-get install bundler

Install all gems necessary to run jekyll_

.. code:: bash

    bundle install --path vendor/bundle

Sometimes you may need to install nodejs, e.g

.. code:: bash

    sudo apt-get install nodejs

Start jekyll_ server

.. code:: bash

    bundle exec jekyll serve --watch --baseurl ''

Open your browser and go to your website: ``http://localhost:4000/``

    

.. _jekyll: http://jekyllrb.com/

.. Micropython HTTP Parser documentation master file, created by
   sphinx-quickstart on Thu Jul 16 17:42:52 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Micropython HTTP Parser's documentation!
===================================================
This project provides a lean and mean module for micropython to handle http
sessions and parse messages in a fast and low-resource-consumption way.

.. note:: 
   
   this module doesn't provide IO routines. you can use built-in
   utils for IO. in addition SSL/TLS is not implemented in this module.

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   GetStarted.rst
   HTTP.rst
   Session.rst
   LowLevel.rst
   SSL.rst

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

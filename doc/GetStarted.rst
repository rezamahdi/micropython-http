Getting Started
===============
First, remember that this module doesn't do network IO by itself. I sugguest you
to use `micropython usyncio <https://docs.micropython.org/en/latest/library/
uasyncio.html>`_ for IO. this has a modern design, uses low ram and is extreamly
fast.

As I am a fan of async/non-blocking IO, I will make examples in this way.
you can use examples in `example` directory for socket blocking based examples.

.. note::
   using uasyncio needs to be familiar with async/non-blocking IO. if you are
   not, use `socket` module.

Building the module
-------------------
this module is written in C, so you must compile it first. Follow this steps to build it:

1. Clone micropython source from github
  clone micropython source using following command:

  ``git clone --depth=1 https://github.com/micropython/micropython.git``

2. clone module's source code
   
   ``git clone --depth=1 https://github.com/rezamahdi/micropython-http_parser.git``

3. cd to modules source dir
   now you must have two dirs: ``micropython`` and ``micropython-http_parser``
   so do:

   ``cd micropython-http_parser``

4. Issue this command to compile and build module (watch ``ARCH``)

   ``make MPY_DIR=../micropython ARCH=x86``

Now, you must have a .mpy file in build directory. this is the module binary ready to use :-)

.. warning::
   in this way, you get a module for **x86** architectur. change ``ARCH``
   argument for your board in last command.
   in addition, you must have proper compiler toolchain.

Uploading module to board
-------------------------

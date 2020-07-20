Components of module
====================
Here, you can find components and classes reside in this module. almost all part
of the module is written in C, but some portion is written in python (the
router) to use micropython ready-to-use modules like ``ure``.

the total soul of components are inspired by `macaron <https://go-macaron.com/
>`_ that is a high performance library for Go.
but as almost all users of micropython are running on bare metal, low resource
devices, I ommit some parts (maybe this increases performance; Small Is Pretty).

Session
-------
Session is object represents a HTTP session.

.. doxygenstruct:: session
   :members:

functions:
^^^^^^^^^^
.. doxygenfunction:: session_init

.. doxygenfunction:: session_free

Session Manager
---------------
We have a limited amount of ram. some variation of boards, like ESP32, have a
good CPU power to handle requests like a real server (Not as a public heavy
load server of corse). so managing sessions in embeded systems is very
important. for doing this, I implemented a simple supervisor-like manager. this
manager has a bipbuffer, that is a ring buffer. this buffer has a limited amount
of space. whenever the server recieves a new connection, it calls the manager
to:

 1. Check it for address filtering, creating SSL/TLS contexts and so on.
 2. Create the Session according to settings.
 3. Emplace it on the buffer.
 4. Create any resource necessary for handling.

the prototypes and structs of C implementation is here.

.. doxygenstruct:: session_manager
   :members:

.. doxygenfunction:: session_manager_init

.. doxygenfunction:: session_manager_free


Low-Level function and objects
==============================
this module uses `picohttpparser <https://github.com/h2o/picohttpparser>`_ under
the hood to parse HTTP messages. any message-feeding to underlaying functions
are automated in the module. but, in any way you may need use fundamental
functions. just import ``http.ll``. this sub-module adds functions and objects
like picohttpparser's ones in the same name.

.. class:: header

   this class is a simple pair of bytes holding a singel HTTP header

.. function:: parse_request(buffer)

   parses a request

   :param bytes buffer: The recieved buffer to be parsed
   :retrn: a HTTP request


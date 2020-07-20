# tope-level make file for micropython http_parser
# copyright (c) reza mahdi
# Licensed under the terms of Apache v2.0

MPY_DIR   ?=

ARCH      ?=
MOD        = http

SRC        = picohttpparser.c http.c bipbuffer.c request.c \
	     utils.c

include $(MPY_DIR)/py/dynruntime.mk

docs: doc/Makefile
	cd doc
	doxygen Doxyfile
	make SPHINXOPTS="-Dbreathe_projects.micropython_http=doxygen/xml" html


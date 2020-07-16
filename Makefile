# tope-level make file for micropython http_parser
# copyright (c) reza mahdi
# Licensed under the terms of Apache v2.0

MPY_DIR   ?=

ARCH      ?=
MOD        = http

SRC        = http_parser.c http.c

include $(MPY_DIR)/py/dynruntime.mk

docs: doc/Makefile
	cd doc; make html


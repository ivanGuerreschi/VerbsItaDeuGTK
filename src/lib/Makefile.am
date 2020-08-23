# Makefile.am
# Copyright (C) 2020 Ivan Guerreschi
#
# This file is part of verbsitadeugtk.
#
# Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
# Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e
#
# verbsitadeugtk is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#  
# verbsitadeugtk is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with verbsitadeugtk.  If not, see <http://www.gnu.org/licenses/>.

AM_CFLAGS = -I $(top_srcdir)/src/lib -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
          -Wjump-misses-init -Wlogical-op 

noinst_LIBRARIES = libverbs.a
noinst_HEADERS = verbs.h

libverbs_a_SOURCES = \
		     $(libverbs_a_HEADERS) \
		     verbs.c

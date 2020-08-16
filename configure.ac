#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# configure.ac
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

AC_PREREQ([2.69])
AC_INIT([verbsitadeugtk], [0.1], [ivanguerreschi86@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE()

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_CPP
AC_PROG_RANLIB

# Use the C language and compiler for the following checks
AC_LANG([C])

# Checks for libraries.
PKG_CHECK_MODULES([GTK], [
    glib-2.0
    gtk+-3.0
])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h stdbool.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/lib/Makefile])
AC_OUTPUT

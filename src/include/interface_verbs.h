/* interface_verbs.h
   Copyright (C) 2020 Ivan Guerreschi

This file is part of verbsitadeugtk.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

verbsitadeugtk is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

verbsitadeugtk is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with verbsitadeugtk.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef INTERFACE_VERBS_H
#define INTERFACE_VERBS_H

#include <gtk/gtk.h>
#include "include/widgets_struct.h"

void rdm_verb_ita (GtkWidget *button, EntryWidgets *entrys);
void rdm_verb_deu (GtkWidget *button, EntryWidgets *entrys);
void tra_verb_deu (GtkWidget *button, EntryWidgets *entrys);

#endif /* INTERFACE_VERBS_H  */

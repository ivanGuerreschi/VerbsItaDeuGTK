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

void on_btn_random_verb_ita_clicked (GtkWidget *button, EntryWidgets *entrys);
void on_btn_random_verb_deu_clicked (GtkWidget *button, EntryWidgets *entrys);
void on_btn_translate_verb_deu_clicked (GtkWidget *button, EntryWidgets *entrys);
void on_btn_translate_verb_ita_clicked (GtkWidget *button, EntryWidgets *entrys);
void on_btn_exist_verb_clicked (GtkWidget *button, EntryWidgets *entrys);
void on_btn_all_vebs_clicked (GtkWidget *button, gpointer window);

#endif /* INTERFACE_VERBS_H  */

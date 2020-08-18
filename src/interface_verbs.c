/* interface_verbs.c
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

#include <stdbool.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "verbs.h"
#include "include/interface_verbs.h"

void
rdm_verb_ita (GtkWidget *widget,
	      gpointer   entry)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  gtk_entry_set_text (GTK_ENTRY (entry), random_verb_ita (verbs, row));

  close_file (&file_verbs);
  close_file (&file_row);

  free (verbs);
}

void
rdm_verb_deu (GtkWidget *widget,
	      gpointer   entry)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  gtk_entry_set_text (GTK_ENTRY (entry), random_verb_deu (verbs, row));

  close_file (&file_verbs);
  close_file (&file_row);

  free (verbs);
}

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
#include <string.h>
#include "verbs.h"
#include "include/interface_verbs.h"
#include "include/widgets_struct.h"

void
on_btn_random_verb_ita_clicked (GtkWidget *button,
                                EntryWidgets *entrys)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_ita), random_verb_ita (verbs, row));

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

void
on_btn_random_verb_deu_clicked (GtkWidget *button,
                                EntryWidgets *entrys)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_deu), random_verb_deu (verbs, row));

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

void
on_btn_translate_verb_deu_clicked (GtkWidget *button,
                                   EntryWidgets *entrys)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  const gchar *verb_deu;
  const gchar *verb_ita;
  const gchar *translate_OK = "Translate OK";
  const gchar *translate_not_OK = "Translate not OK";


  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  verb_ita = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_ita));
  verb_deu = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_deu));

  if (translate_verb_deu (verbs, verb_ita, verb_deu, row))
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_deu), translate_OK);
  else
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_deu), translate_not_OK);

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

void
on_btn_translate_verb_ita_clicked (GtkWidget *button,
                                   EntryWidgets *entrys)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  const gchar *verb_deu;
  const gchar *verb_ita;
  const gchar *translate_OK = "Translate OK";
  const gchar *translate_not_OK = "Translate not OK";


  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  verb_deu = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_deu));
  verb_ita = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_ita));

  if (translate_verb_ita (verbs, verb_ita, verb_deu, row))
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_ita), translate_OK);
  else
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_ita), translate_not_OK);

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

void
on_btn_exist_verb_clicked (GtkWidget *button,
                           EntryWidgets *entrys)
{
  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  const gchar *verb_deu;
  const gchar *verb_ita;
  const gchar *verb_exist = "Verb exist";
  const gchar *verb_not_exist = "Verb not exist";


  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  verb_deu = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_deu));
  verb_ita = gtk_entry_get_text (GTK_ENTRY (entrys->entry_verb_ita));

  if ((strlen (verb_deu)) > 0 )
    if (exist_verb_deu (verbs, verb_deu, row))
      gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_deu), verb_exist);
    else
      gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_deu), verb_not_exist);
  else if (exist_verb_ita (verbs, verb_ita, row))
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_ita), verb_exist);
  else
    gtk_entry_set_text (GTK_ENTRY (entrys->entry_verb_ita), verb_not_exist);

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

void on_btn_all_vebs_clicked (GtkWidget *button,
                              gpointer window)
{

  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.dat");
  open_file (&file_verbs, "verbs.dat");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  char dialog_verbs[50];
  int pos = 0;

  for (int i = 0; i < row; i++)
    pos += snprintf (&dialog_verbs[pos], 50, "%s-%s\n", verbs[i].ita, verbs[i].deu);

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new (GTK_WINDOW (window),
                                   GTK_DIALOG_DESTROY_WITH_PARENT,
                                   GTK_MESSAGE_INFO,
                                   GTK_BUTTONS_OK,
                                   "%s", dialog_verbs);

  gtk_window_set_title (GTK_WINDOW (dialog), "All verbs");
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
}

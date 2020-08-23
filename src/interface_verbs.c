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
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

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
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

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
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

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
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

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
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

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
                              gpointer data)
{
  GtkWidget *window;
  GtkWidget *text_view;
  GtkWidget *scrolled_window;
  GtkTextBuffer *buffer;

  FILE *file_verbs, *file_row = NULL;
  open_file (&file_row, "verbs.txt");
  open_file (&file_verbs, "verbs.txt");

  int row = count_row_file (file_row);
  verb_t *verbs = all_verbs (file_verbs, row);

  gchar *text_view_verbs = g_malloc (row * (50 * sizeof (gchar)));
  int pos = 0;

  for (int i = 0; i < row; i++)
    pos += g_snprintf (&text_view_verbs[pos], 50, "%s-%s\n", verbs[i].ita, verbs[i].deu);

  if (!g_utf8_validate (text_view_verbs, -1, NULL))
    {
      g_printerr ("%s\n %s", "Invalid UTF-8 filename", text_view_verbs);
      return;
    }

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "All Verbs");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  text_view = gtk_text_view_new ();

  buffer = gtk_text_buffer_new (NULL);
  gtk_text_view_set_buffer (GTK_TEXT_VIEW (text_view), buffer);
  gtk_text_buffer_set_text (buffer, text_view_verbs, -1);

  scrolled_window = gtk_scrolled_window_new (NULL, NULL);

  gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 5);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                                  GTK_POLICY_AUTOMATIC,
                                  GTK_POLICY_AUTOMATIC);

  gtk_container_add (GTK_CONTAINER (scrolled_window), text_view);
  gtk_container_add (GTK_CONTAINER (window), scrolled_window);

  gtk_widget_show_all (window);

  close_file (&file_verbs);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (verbs[i].ita);
      free (verbs[i].deu);
    }

  free (verbs);
  g_free (text_view_verbs);
}

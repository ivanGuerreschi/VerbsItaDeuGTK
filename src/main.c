/* main.c
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
#include <gtk/gtk.h>
#include "verbs.h"
#include "include/interface_verbs.h"
#include "include/widgets_struct.h"

static void
on_activate (GtkApplication *app)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *label_verb_ita;
  GtkWidget *label_verb_deu;
  GtkWidget *button_rdm_verb_ita;
  GtkWidget *button_rdm_verb_deu;
  GtkWidget *button_translate_verb_ita;
  GtkWidget *button_translate_verb_deu;
  GtkWidget *button_all_verbs;
  GtkWidget *button_exist_verb;
  EntryWidgets *entrys = g_slice_new (EntryWidgets);

  const gchar *title = "Verbs Ita Deu";

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), title);
  gtk_container_set_border_width (GTK_CONTAINER (window), 5);

  grid = gtk_grid_new ();
  gtk_grid_set_column_spacing (GTK_GRID (grid), 5);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 5);

  gtk_container_add (GTK_CONTAINER (window), grid);

  label_verb_ita = gtk_label_new ("Verb Ita");
  gtk_grid_attach (GTK_GRID (grid), label_verb_ita, 0, 0, 1, 1);

  entrys->entry_verb_ita = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_verb_ita, 1, 0, 1, 1);

  label_verb_deu = gtk_label_new ("Verb Deu");
  gtk_grid_attach (GTK_GRID (grid), label_verb_deu, 0, 1, 1, 1);

  entrys->entry_verb_deu = gtk_entry_new ();
  gtk_grid_attach (GTK_GRID (grid), entrys->entry_verb_deu, 1, 1, 1, 1);

  button_rdm_verb_ita = gtk_button_new_with_label ("Rdm verb Ita");
  gtk_grid_attach (GTK_GRID (grid), button_rdm_verb_ita, 0, 2, 1, 1);
  g_signal_connect (button_rdm_verb_ita, "clicked", G_CALLBACK (on_btn_random_verb_ita_clicked), entrys);

  button_translate_verb_ita = gtk_button_new_with_label ("Translate verb Ita");
  gtk_grid_attach (GTK_GRID (grid), button_translate_verb_ita, 1, 2, 1, 1);
  g_signal_connect (button_translate_verb_ita, "clicked", G_CALLBACK (on_btn_translate_verb_ita_clicked), entrys);

  button_rdm_verb_deu = gtk_button_new_with_label ("Rdm verb Deu");
  gtk_grid_attach (GTK_GRID (grid), button_rdm_verb_deu, 0, 3, 1, 1);
  g_signal_connect (button_rdm_verb_deu, "clicked", G_CALLBACK (on_btn_random_verb_deu_clicked), entrys);

  button_translate_verb_deu = gtk_button_new_with_label ("Translate verb Deu");
  gtk_grid_attach (GTK_GRID (grid), button_translate_verb_deu, 1, 3, 1, 1);
  g_signal_connect (button_translate_verb_deu, "clicked", G_CALLBACK (on_btn_translate_verb_deu_clicked), entrys);

  button_all_verbs = gtk_button_new_with_label ("All Verbs");
  gtk_grid_attach (GTK_GRID (grid), button_all_verbs, 0, 4, 1, 1);
    g_signal_connect (button_all_verbs, "clicked", G_CALLBACK (on_btn_all_vebs_clicked), NULL);


  button_exist_verb = gtk_button_new_with_label ("Exist Verb");
  gtk_grid_attach (GTK_GRID (grid), button_exist_verb, 1, 4, 1, 1);
  g_signal_connect (button_exist_verb, "clicked", G_CALLBACK (on_btn_exist_verb_clicked), entrys);

  gtk_widget_show_all (window);
}

int
main (int  argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("it.ivanGuerreschi.verbsitadeugtk",
                             G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

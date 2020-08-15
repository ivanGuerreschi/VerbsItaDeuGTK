/* verbs.h
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

#ifndef LIBVERBS_FILE_H
#define LIBVERBS_FILE_H

typedef struct
{
  char *ita;
  char *deu;
} verb_t;

void open_file (FILE **, const char *name_file);
void close_file (FILE **);
verb_t *all_verbs (FILE *, int);
int count_row_file (FILE *);
bool exist_verb_deu (verb_t *verbs, const char *verb, int);
bool exist_verb_ita (verb_t *verbs, const char *verb, int);
bool translate_verb_deu (verb_t *verbs, const char *verb_ita,
                         const char *verb_deu, int);
char *random_verb_ita (verb_t *verbs, int);
char *random_verb_deu (verb_t *verbs, int);

#endif /* LIBVERBS_FILE_H */


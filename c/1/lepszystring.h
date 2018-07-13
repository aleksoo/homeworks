#ifndef LEPSZYSTRING_H
#define LEPSZYSTRING_H

#include <stdlib.h>

typedef struct string{
    char* buffer;
    int size;
}lepszystring;

enum error_code { STR_OK, STR_MEMORY_ERROR };

enum error_code new_string(struct string*); /* tworzenie pustego obiektu */
enum error_code new_string_from_characters(struct string *, char *); /* na podstawie przekazanego lancucha */
enum error_code append_string(struct string*, char*); /* doklejanie */
enum error_code trim_string(struct string*, int); /* wycinanie podlancucha */
/*int lenght_of_string(struct string*);*/ /* dlugosc lancucha */
int find_character_in_string(struct string*, char); /* znajdowanie znaku w lancuchu */
enum error_code compare_strings(struct string*, struct string*); /* porownanie lancuchow */
enum error_code free_string(struct string*); /* wycinanie */

#endif
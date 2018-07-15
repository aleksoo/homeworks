#ifndef LEPSZYSTRING_H
#define LEPSZYSTRING_H

#include <stdlib.h>

typedef struct string{
    char* buffer;
    int size;
}lepszystring;

enum error_code { STR_OK, STR_MEMORY_ERROR };

/* TODO:
trim_string - w obecnym dzialaniu odcina od konca, 
moze zrobic tak, ze podaje sie dwie pozycje i miedzy nimi zostawia lancuch?
valgrind 

compare strings - porownac od konca, bo moze byc tak, ze ten dluzszy string jest pusty na koncu

free_string - usuwanie stringa
*/

enum error_code new_string(struct string*); /* tworzenie pustego obiektu */
enum error_code new_string_from_characters(struct string *, char *); /* na podstawie przekazanego lancucha */
enum error_code append_string(struct string*, char*); /* doklejanie */
enum error_code trim_string(struct string*, int); /* wycinanie podlancucha */
/*enum error_code trim_substring(struct string*, int, int); */ /* wycinanie lancucha od do */
int lenght_of_string(const struct string*); /* dlugosc lancucha */
int find_character_in_string(const struct string*, char); /* znajdowanie znaku w lancuchu */
int compare_strings(const struct string*, const struct string*); /* porownanie lancuchow */
enum error_code free_string(struct string*); /* wycinanie */

#endif
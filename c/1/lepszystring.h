#ifndef LEPSZYSTRING_H
#define LEPSZYSTRING_H

typedef struct string{
    char* buffer;
    int size;
}lepszystring;

enum error_code { STR_OK, STR_MEMORY_ERROR };

/* TODO:


*/

enum error_code new_string(struct string*); /* tworzenie pustego obiektu */
enum error_code new_string_from_characters(struct string *, char *); /* na podstawie przekazanego lancucha */
enum error_code append_string(struct string*, const struct string*); /* doklejanie */
enum error_code trim_string(struct string*, int); /* wycinanie podlancucha */
enum error_code trim_substring(struct string*, const char*, int);  /* wycinanie lancucha od do */
lepszystring return_substring(const struct string*, int, int);
int lenght_of_string(const char*); /* dlugosc lancucha */
int find_character_in_string(const struct string*, int); /* znajdowanie znaku w lancuchu */
int compare_strings(const struct string*, const struct string*); /* porownanie lancuchow */
enum error_code optimize_string(struct string *); /*przycina string do ilosci znakow*/
enum error_code free_string(struct string*); /* wycinanie */

#endif
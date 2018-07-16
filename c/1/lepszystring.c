#include "lepszystring.h"
#include <stdlib.h>
#include <stdio.h>

enum error_code new_string(struct string* str){
    str->buffer = NULL;
    str->size = 0;
    return STR_OK;
}

enum error_code new_string_from_characters(struct string *str, char* characters){
        int i;
        int lenght = lenght_of_string(characters);

        str->size = lenght;
        
        str->buffer = malloc(sizeof(char) * (str->size));
        for(i=0; i < str->size ; ++i){
            str->buffer[i] = characters[i];
        }
        return STR_OK;
}

enum error_code append_string(struct string* str, const struct string *str2){
    if(str->buffer){
        int i;
        int lenght = lenght_of_string(str2->buffer);
        char *new_buffer;

        new_buffer = realloc(str->buffer, sizeof(char) * (str->size + lenght));

        if(new_buffer){
            str->buffer = new_buffer;
            for(i=0; i<lenght; ++i){
                str->buffer[str->size+i] = str2->buffer[i];
            }
            str->size+=lenght;
        } else return STR_MEMORY_ERROR;
        return STR_OK;
    } else return STR_MEMORY_ERROR;
}

enum error_code trim_string(struct string *str, int end){
    str->size = end;
    return STR_OK;
}

enum error_code trim_substring(struct string *newString, const char* start, int end){
    int i;

    newString->buffer = malloc(sizeof(char)*(end+1));
    if(newString->buffer){
        newString->size = end;
        for(i=0; i<end; ++i){
            newString->buffer[i]=start[i];
        }
        return STR_OK;
    }else return STR_MEMORY_ERROR;
}

lepszystring return_substring(const struct string *str, int start, int end){
    lepszystring substring;
    trim_substring(&substring, &(str->buffer[start]), end);
    return substring;
}

enum error_code optimize_string(struct string *str){
    int lenght = lenght_of_string(str->buffer);
    str->size=lenght;
    return STR_OK;
}

int lenght_of_string(const char *str){
    int lenght=0;
    while(str[++lenght] != '\0');
    return lenght;
}

int find_character_in_string(const struct string *str, int character){ /* */
    int i;
    for(i=0; i < str->size; ++i){
        if(str->buffer[i]==character) return i;
    }
    return -1;
}

int compare_strings(const struct string *str1, const struct string *str2){
    int i;
    if(str1->size != str2->size) return 0;
    else{
        for(i=0; i<str1->size; ++i){
            if(str1->buffer[i] != str2->buffer[i]) return 0;
        }
    }
    return 1;
}

enum error_code free_string(struct string* str){
    if(str->buffer){
        free(str->buffer);
        str->buffer = NULL;
        return STR_OK;
    }
    else return STR_MEMORY_ERROR;
}
#include "lepszystring.h"

enum error_code new_string(struct string* str){
    str->buffer = 0;
    str->size = 0;
    return STR_OK;
}

enum error_code new_string_from_characters(struct string *str, char* characters){
    if(str->buffer){
        int i;
        int lenght = 0;
        while(characters[lenght]!='\0') ++lenght;

        str->size = lenght;
        
        str->buffer = malloc(sizeof(char) * (str->size + 5));
        for(i=0; i < str->size ; ++i){
            str->buffer[i] = characters[i];
        }
        return STR_OK;
    }
    else return STR_MEMORY_ERROR;
}

/*enum error_code append_string(struct string* str, char*){

}*/

enum error_code trim_string(struct string *str, int place){
    int i;
    for(i=str->size; i > place; --i){
        str->buffer[i]=0;
        /*free(str->buffer[i]);*/
    }
    str->size=str->size - place;
    return STR_OK;
}
/*
int lenght_of_string(struct string *str){
    int lenght=0;
    while(str->buffer[++lenght] != "\0");
    return lenght;
}*/

int find_character_in_string(struct string *str, char character){
    int i;
    for(i=0; i < str->size; ++i){
        if(str->buffer[i]==character) return i;
    }
    return -1;
}

enum error_code compare_strings(struct string *str1, struct string *str2){
    if(str1->buffer || str2->buffer){

        return STR_OK;
    }    
    else return STR_MEMORY_ERROR;
}

enum error_code free_string(struct string* str){
    if(str->buffer){
        int i;
        for(i=0; i < str->size; ++i) str->buffer[i]=0;
        free(str->buffer);
    return STR_OK;
    }
    else return STR_MEMORY_ERROR;
}
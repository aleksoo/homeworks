#include "lepszystring.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    lepszystring s1;
    lepszystring s2;
    lepszystring s3; 
    lepszystring s4;
    char search = 'd';

    new_string_from_characters(&s1, "abc");
    printf("s1 string: %s\n", s1.buffer);

    new_string(&s2);
    append_string(&s2, s1.buffer);
    printf("New string s2: %s\n", s2.buffer);

    new_string_from_characters(&s3, "def");
    append_string(&s2, s3.buffer);
    printf("New string (s2 + s1): %s %d\n", s2.buffer, s2.size);

    printf("Lenght of string s1: %d\n", lenght_of_string(&s1));
    printf("Lenght of string s2: %d\n", lenght_of_string(&s2));
    printf("Lenght of string s3: %d\n", lenght_of_string(&s3));

    trim_string(&s2, 3);
    printf("New string after trimming: %s %d\n", s2.buffer, s2.size);

    
    printf("Place of character %c in string s2: %d\n", search, find_character_in_string(&s2, search));

    new_string_from_characters(&s4, "def");
    printf("Lenght of s1 and s4: %d %d\n", s1.size, s4.size);
    printf("Comparing s1 and s2: %d\n", compare_strings(&s1, &s4));
    

    free_string(&s1);
    free_string(&s2);
    free_string(&s3);
    free_string(&s4);
    return 0;
}
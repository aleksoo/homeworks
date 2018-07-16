#include "lepszystring.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    lepszystring s1;
    lepszystring s2;
    lepszystring s3; 
    lepszystring s4;/*
    lepszystring s5;*/

    new_string_from_characters(&s1, "abc");
    printf("s1 string: %s %d\n\n", s1.buffer, s1.size);

    new_string_from_characters(&s2, "def");
    append_string(&s1, &s2);
    printf("s1 string: %s %d\n\n", s1.buffer, s1.size);
    
    new_string(&s3);
    s3 = return_substring(&s1, 2, 4);
    printf("s3 string: %s %d\n\n", s3.buffer, s3.size);

    new_string_from_characters(&s4, "cdef");
    printf("Comparing s3 and s4: %d\n", compare_strings(&s3, &s4));

    printf("Searching for 'd' in s4 string: %d\n", find_character_in_string(&s4, 'd'));
    printf("Number of characters in s4: %d\n", lenght_of_string(s4.buffer));
    
    free_string(&s1);
    free_string(&s2);
    free_string(&s3);
    free_string(&s4);/*
    free_string(&s5);*/
    return 0;
}
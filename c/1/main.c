#include "lepszystring.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    lepszystring s;
    new_string(&s);
    new_string_from_characters(&s, "abc");
    printf("%c\n", &s->buffer);
    return 0;
}
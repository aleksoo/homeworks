#include <iostream>
#include "killer3.h"
#include <stdio.h>

int main(){
    freopen("plik.txt","w", stderr);
    Tron killer;
    killer.loadData();
    killer.makeMove();
    return 0;
}
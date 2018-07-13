#include <iostream>
#include "myBot.h"


#include <stdio.h>

int main()
{
    freopen("plik.txt","r", stdin);
    MyBot bot('1', '2');
    bot.loadData();
    bot.returnDirection();
}
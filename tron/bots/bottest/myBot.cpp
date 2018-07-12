#include "myBot.h"
#include <iostream>
#include <sstream>
 
MyBot::MyBot(char player1, char player2)
{
    gr1 = player1;
    gr2 = player2;
}
 
void MyBot::getDimensions()
{
    std::cin >> colsNumber >> rowsNumber;

    std::cerr << colsNumber << ' ' << rowsNumber << std::endl;
}
 
void MyBot::getMap()
{
    std::string item;
 
    while(getline(std::cin, item))
    {
        myMap.push_back(item);
    }
}
 
void MyBot::getPosition()
{
    for(int i = 0; i < rowsNumber; ++i)
    {
        for(int j = 0; j < colsNumber; ++j)
        {
            if(myMap[i][j] == gr1)
            {
                rowPosition = i;
                colPosition = j;
            }
        }
    }
}
 
void MyBot::returnDirection()
{
   
}
 
void MyBot::loadData()
{
    getDimensions();
    getMap();
    getPosition();
}
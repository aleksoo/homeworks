#ifndef MYBOT_H
#define MYBOT_H
 
#include <vector>
#include <string>
 
class MyBot
{
public:
    void loadData();
    void returnDirection();
    MyBot(char, char);
   
private:
    std::vector<std::string> myMap;
    int rowPosition, colPosition;
    int rowsNumber, colsNumber;
    char gr1;
    char gr2;
 
    void getDimensions();
    void getMap();
    void getPosition();
};
 
#endif
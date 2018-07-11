#ifndef KILLER_H
#define KILLER_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Tron{
    public:

    void move_x(void); //prototyp ruchu
    void get_info(void); // czytanie pozycji i mapy, niekoniecznie void, cos moge tam przekazac, ale to potem w trakcie rozwijania
    void show_info(void); // wyswietlanie do debugowania

    private:
    
    std::vector<int> dim; // rozmiar
    std::vector<int> pos1; // pozycja, 0 to x pion, 1 to y poziom
    std::vector<int> pos2; // pozycja, 0 to x, 1 to y
    std::vector<int> dir; //sprawdza pozycje, 0 to gora i leci w strone wskazowek, wartosc to odleglosc

    std::vector<std::string> map; // tutaj bede wpisywal informacje o arenie
        
    void load_map(); // wczytuje mape
    void load_pos(void); // wczytuje pozycje jednego i drugiego gracza
    void load_dim(); // zaladuj wymiary
    //void check_wall(void); //sprawdza jak w danym polu sa ustawione sciany
    int check_lenght(int); // TODO jaka odleglosc w x kierunku
    void check_dir(void); // TODO sprawdza jak w ktora strone moze sie ruszyc 
    void map_state(void); // wyswietlanie stanu mapy
    

    // jakies heurystyki na koniec

};

#endif
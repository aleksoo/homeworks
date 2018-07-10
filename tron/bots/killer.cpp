/*
-napisac klase, ktora bedzie czytac zawartosci txt, czyli wziac rozmiar x i y, najlepiej w konstruktorze
-rozmiar x i y wykorzystac do stworzenia vectora (czy czegos, sprawdizc najlepsze rozw) o tych rozmiarach
-przeczytac pierwsza linie, druga to juz mapka, zwrocic uwage na punkt startowy przy czytaniu (jakis if)

*/

#include <killer.h>


void Tron::load_map(void){

}

void Tron::load_pos(std::vector<int> &pos){
    std::getline(std::cin, pos[0], ' ');
    std::getline(std::cin, pos[1], ' ');
}

void Tron::check_wall(std::vector<int> &pos){

}

void Tron::map_state(std::vector<std::vector<char>> &map){
    for(int i=0; i< map.size(); i++)
    {
        for(int j=0; j< map[i].size(); i++)
        {
            std::cout << map[i][j] << std::endl;
        }
    }
}
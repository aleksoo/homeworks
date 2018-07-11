/*
-napisac klase, ktora bedzie czytac zawartosci txt, czyli wziac rozmiar x i y, najlepiej w konstruktorze
-rozmiar x i y wykorzystac do stworzenia vectora (czy czegos, sprawdizc najlepsze rozw) o tych rozmiarach
-przeczytac pierwsza linie, druga to juz mapka, zwrocic uwage na punkt startowy przy czytaniu (jakis if)

*/

#include "killer.h"

void Tron::load_dim(){
    std::string dim_string;
    getline(std::cin, dim_string, ' ');
    dim.push_back(std::stoi(dim_string));
    getline(std::cin, dim_string);
    dim.push_back(std::stoi(dim_string));
}

void Tron::load_map(){
    std::string map_string;
    while(getline(std::cin, map_string)){
        map.push_back(map_string);
    }
}

void Tron::load_pos(void){

    for(int i = 0; i < dim[1]; i++) {
        for(int j = 0; j < dim[0]; j++)
            if(map[i][j]=='1') {
                pos1[0]=j;  // pion
                pos1[1]=i;  // poziom             
            } else if(map[i][j]=='2'){
                pos2[0]=j;  // pion
                pos2[1]=i;  // poziom
            }
    }
    
    
}

/*
void Tron::check_wall(void){
    // sprawdzenie poziomu

}*/

int Tron::check_lenght(int x){
    
    switch(x){
        case 0: {// sprawdzanie do gory
            int lenght0 = pos1[0];
            while(map[ pos1[lenght0] ][ pos1[1]] != '#'){
                --lenght0;
            }
            return std::abs(lenght0-pos1[0]);
            break;
        }
        case 1: {// sprawdzenie w prawo
            int lenght1 = pos1[1];
            while(map[ pos1[0] ][ pos1[lenght1]] != '#'){
                --lenght1;
            }
            return std::abs(lenght1-pos1[1]);
            break;
        }
        case 2: {// sprawdzenie w dol
            int lenght2 = pos1[0];
            while(map[ pos1[lenght2] ][ pos1[1] ] != '#'){
                ++lenght2;
            }
            return std::abs(lenght2-pos1[0]);
            break;
        }
        case 3: {//sprawdzenie w lewo
            int lenght3 = pos1[1];
            while(map[ pos1[0] ][ pos1[lenght3]] != '#'){
                ++lenght3;
            }
            return std::abs(lenght3-pos1[1]);
            break;
        }
    }
}
 
void Tron::check_dir(void){
    //dir.resize(3);
    // UZUPELNIC dir[x][TUTAJ] funkcja check_lenght
    // sprawdza gorne pole
    if(map [pos1[0]-1] [pos1[1]] != '#') dir[0] = 1;//check_lenght(0);
    else dir[0] = 0;
    // sprawdza dolne pole
    if(map [pos1[0]+1] [pos1[1]] != '#') dir[2] = 1;//check_lenght(2);
    else dir[3] = 0;
    // sprawdza lewo pole
    if(map [pos1[0]] [pos1[1]-1] != '#') dir[3] = 1;//check_lenght(3);
    else dir[2] = 0;
    // sprawdza prawo pole
    if(map [pos1[0]] [pos1[1]+1] != '#') dir[1] = 1;//check_lenght(4); 
    else dir[1] = 0;
}

void Tron::map_state(){
    for(int i=0; i< map.size(); i++)
    {
        for(int j=0; j< map[i].size(); i++)
        {
            std::cout << map[i][j] << std::endl;
        }
    }
}

void Tron::get_info(void){
    
    load_dim();    
    load_map();
    move_x();
    //map_state();
    load_pos();
    check_dir();
    
    
}

void Tron::move_x(void){
    //std::cout << *std::max_element(dir.begin(), dir.end());    
    std::cout << 2;
}

void Tron::show_info(void){
    //std::cerr << "Dimensions: " << std::endl << dim[0] << ' ' << dim[1] << std::endl;
}
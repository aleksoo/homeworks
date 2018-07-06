/*
fork
pipe
dup2
close
execvp

*/


#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

struct program_data {
    std::string name;
    std::vector<std::string> args;
} program_data1, program_data2;

int main(int argc, char *argv[]){
    std::string input_string;
    std::string input_string_2;
    
    std::getline(std::cin, input_string); 

    // Tworze streama, ktory bedzie mi podawal stringa bezposrednio do getline
    std::istringstream second_string(input_string);

    // Getline w while iteruje sie poki nie dojdzie do konca lub dojdzie do znaku "|"
    std::getline(second_string, program_data1.name, ' '); // Wrzucam nazwe programu
    while( (std::getline(second_string, input_string_2, ' ')) && (input_string_2 != "|") )
        program_data1.args.push_back(input_string_2);
    
    std::getline(second_string, program_data2.name, ' ');
    while( std::getline(second_string, input_string_2, ' '))
        program_data2.args.push_back(input_string_2);


    /*
    // Wyswietlanie zawartosci dwoch vectorow
    std::cout << program_data1.name << std::endl;
    for(int i = 0; i < program_data1.args.size(); i++ ) {
        std::cout << program_data1.args[i] << std::endl;
    }

    std::cout << program_data2.name << std::endl;
    for(int i = 0; i < program_data2.args.size(); i++ ) {
        std::cout << program_data2.args[i] << std::endl;
    }  
    */

    // TODO: zeby odpalal sie wybrany program przez argument

    pid_t pid=fork();

    if(pid==0){
        // Jestem w dziecku
        std::cout << "I'm in child process" << std::endl;

        //const char arg1[program_data1.size()];
        //memcpy(arg1, program_data1.data(), program_data1.size());
        std::vector<char*> arg1;
        
        for(auto const& a : program_data1.args) {
            arg1.emplace_back(const_cast<char*>(a.c_str()));
        }
        program_data1.args.push_back(nullptr);

        execvp(program_data1.name.c_str(), arg1.data());
        
        exit(0); // TODO: nie moze wychodzic za kazdym razem z 0, bo to tak jakby za kazdym razem bylo dobrze wykonane, a tego nie wiadomo     
    } 
    else if(pid>0){
        // Jestem w rodzicu
        std::cout << "Child PID = " << pid << std::endl;
        
        std::vector<char*> arg2;

        for(auto const& a : program_data2.args){
            arg2.emplace_back(const_cast<char*>(a.c_str()));
        }
        program_data2.args.push_back(nullptr);
        
        execvp(program_data2.name.c_str(), arg2.data());

        wait(&pid);
        
        std::cout << "Child PID = " << pid << std::endl; // dlaczego tutaj zwraca mi zero? czy jest to skonczony proces?
    } 
    else if(pid<0) {
        exit(EXIT_FAILURE);
        std::cout << "Error, pid=-1" << std::endl;
    }

    return 0;
}
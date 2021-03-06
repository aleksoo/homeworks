/*

*/

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

struct program_data
{
    std::string name;
    std::vector<std::string> args;
};

void show_contents(program_data vector); // Wyswietla zawartosc struktury program_data

int main(int argc, char *argv[])
{
    program_data program_data1, program_data2;

    std::vector<program_data> data_vector; // wektor struktur

    std::string input_string;

    std::getline(std::cin, input_string);

    // Tworze streama, ktory bedzie mi podawal stringa bezposrednio do getline
    std::istringstream second_string(input_string);

    // Getline w while iteruje sie poki nie dojdzie do konca lub dojdzie do znaku "|"

    // TODO: Na poczatku mam przeiterowac do pierwszego znaku |, pozniej to co mi wrzuci do niego zinterpretowac odpowiednio
    // , cos w stylu wczytuje pierwszy wyraz do pola name, reszte do vectora i tak dalej i tak dalej
    // chyba jakims forem to zrobic, moze whilem, na pewno musze pomyslec o iteratorze zeby powpisywac do data_vector odpowiednio
    std::getline(second_string, program_data1.name, ' '); // Wrzucam nazwe programu
    while ((std::getline(second_string, data_vector, ' ')) && (input_string_2 != "|"))
        program_data1.args.push_back(input_string_2);


    int pipe1[2];
    pipe(pipe1);

    if (pipe(pipe1) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        // Proces potomny
        close(pipe1[0]);
        dup2(pipe1[1], 1);

        std::cout << "I'm in child process" << std::endl;

        std::vector<char *> arg1;
        arg1.emplace_back(const_cast<char *>(program_data1.name.c_str()));
        for (auto const &a : program_data1.args)
        {
            arg1.emplace_back(const_cast<char *>(a.c_str()));
        }
        arg1.push_back(nullptr);

        execvp(program_data1.name.c_str(), arg1.data());

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        // Proces parent
        std::cout << "Child PID = " << pid << std::endl;
        
        close(pipe1[1]);
        dup2(pipe1[0], 0);
        
        std::vector<char *> arg2;
        arg2.emplace_back(const_cast<char *>(program_data2.name.c_str()));
        for (auto const &a : program_data2.args)
        {
            arg2.emplace_back(const_cast<char *>(a.c_str()));
        }
        arg2.push_back(nullptr);

        execvp(program_data2.name.c_str(), arg2.data());
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        exit(EXIT_FAILURE);
        std::cout << "Error, pid=-1" << std::endl;
    }
    close(pipe1[0]);
    close(pipe1[1]);
    wait(&pid);
    wait(&pid);

    return 0;
}

void show_contents(program_data vector){
    std::cout << vector.name << std::endl;
    for(int i = 0; i < vector.args.size(); i++ ) {
        std::cout << vector.args[i] << std::endl;
    }
}
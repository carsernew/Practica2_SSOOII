
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include <chrono>
#include <ctime>
#include <shared_mutex>
#include <fstream>

/*******************************************************************************************
 * 
 * PROJECT          :       Practica 2 SSOO2                 
 * 
 * PROGRAM NAME     :       main.cpp
 * 
 * AUTHOR           :       Carlos Fernandez-Aparicio Margoton
 * 
 * DATE CREATE      :       04/04/23
 * 
 * PURPOSE          :       Lectura y division de las tareas por los hilos 
 * 
********************************************************************************************/
void readFile(std::string);

int main(int argc, char const *argv[])
{
    std::string file_name(argv[1]);
    readFile(file_name);
    return 0;
}



void readFile(std::string file_name){

    std::string root="books/";
    root+=file_name;
    std::ifstream file(root);
    
    if (!file){
        std::cerr << " No se encontro el archivo "<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    
    while (std::getline(file, line)) { 
        std::cout << line << std::endl; 
    }
    

    file.close(); // cerrar el archivo
    exit(EXIT_SUCCESS);

}


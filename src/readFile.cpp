
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
void readFile();

int main(int argc, char const *argv[])
{
    readFile();
    return 0;
}



void readFile(){
    std::string root="books/";
    std::string file_name="prueba.txt";
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


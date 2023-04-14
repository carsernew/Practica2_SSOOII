
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

#include "wordfinder.cpp"

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


std::mutex semaforo;
int redFile(std::string file_name,int);
void threadCreadtion(int);

std::vector<std::thread> v_threads;

std::vector<wordfinder> v_searchers;

int main(int argc, char const *argv[])
{
    std::string file_name(argv[1]);
    const char* search_word(argv[2]);
    int n_threads(std::stoi(argv[3]));
    char* word = const_cast<char*>(search_word);
    

    if (argc != 3) 
    {
        std::cout << "No has puesto lo necesario para realizar la busqueda" <<std::endl;
        exit(EXIT_FAILURE);
    }

    threadCreation(n_threads,file_name,word);

   
    readFile(file_name,n_threads);

    std::cout<< "[THREAD MAIN] Child threads have finished. Printing results.\n" <<std::endl;

    return 0;
}

void threadCreation(int n_threads,std::string file_name,char *word)
{
    int n_lines = readFile(file_name,n_threads);
    if(n_lines < n_threads){
        std::cout<< "Linas insuficientes para la cantidad de hilos" <<std::endl;
        exit(EXIT_FAILURE);
    }

    int lines_per_thread = n_lines / n_threads;

    for (int i=0; i<n_threads; i++)
    {
        int begin = i*lines_per_thread;
        int end = (begin + lines_per_thread) - 1;
        v_searchers.push_back(wordfinder(i, begin, end));

    }
    for (int i=0; i<n_threads; i++)
        v_threads.push_back(std::thread(std::ref(v_searchers[i]), file_name, word));
}


int readFile(std::string file_name, int n_threads)
{
    std::string root = "books/";
    root += file_name;
    std::ifstream file(root);
    int count;

    if (!file)
    {
        std::cerr << " No se encontro el archivo " << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;

    while (std::getline(file, line))
    {
        count++;
    }
    std::cout << "El numero de lineas es " << count <<std::endl;


    file.close(); // cerrar el archivo

    return count;
    
}

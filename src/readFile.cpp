
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


std::mutex semaforo;
void readFile(std::string,int);
void threadCreadtion(int);

int main(int argc, char const *argv[])
{
    std::string file_name(argv[1]);
    //std::string search_word(argv[2]);
    int n_threads = 4;

    //threadCreation(n_threads);
    readFile(file_name,n_threads);
    return 0;
}

void threadCreation(int n_threads,int i)
{
    std::unique_lock<std::mutex> myLock(semaforo);
    std::vector<std::thread> threads(n_threads);
    threads[i];  
    threads[i].join();  
    std::cerr << i << std::endl;
    myLock.unlock();

}

void threadCalculating(int n_threads,int lines)
{
    int linesthread;
    int residue;
    if(n_threads>0){
        linesthread=lines/n_threads;
        residue=lines%n_threads;

        std::cout << linesthread <<std::endl;
        std::cout << residue <<std::endl;
        for (int i = 0; i < n_threads; i++)
        {
            
            threadCreation(n_threads,i);
            
        }
        



    }else{
        std::cerr << " No existen ningun hilo " << std::endl;
        exit(EXIT_FAILURE);
    }
    

}

void readFile(std::string file_name, int n_threads)
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

    threadCalculating(n_threads,count);

    file.close(); // cerrar el archivo
    exit(EXIT_SUCCESS);
}

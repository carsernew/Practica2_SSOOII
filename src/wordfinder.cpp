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
#include <stdlib.h>
#include <cstring>
#include <iostream>

/*******************************************************************************************
 *
 * PROJECT          :       Practica 2 SSOO2
 *
 * PROGRAM NAME     :       wondfinder.cpp
 *
 * AUTHOR           :       Carlos Fernandez-Aparicio Margoton
 *
 * DATE CREATE      :       04/04/23
 *
 * PURPOSE          :       Busca las palabras que necesitamos
 *
 ********************************************************************************************/

class wordfinder{

      private:

        int id_thread;
        int begin_line;
        int end_line;

        void wordFinder(std::string file, char *word){
            std::ifstream ifile;
            std::string line;
            char trunk[256];
            size_t pos;
            char *token;
            int n_lines = 0;
            std::vector<char*> v_line;

            ifile.open(file);
            if (!ifile)
            {
                std::cout<< "[HILO " << id_thread+1 << "]  Ha tenido un problema. " <<std::endl;
                return;
            }

            while (!ifile.eof())
            {
                v_line.clear();
                getline(ifile, line);
                if (n_lines >= this->begin_line && n_lines <= this->end_line)
                {
                    strcpy(trunk, line.c_str());
                    token = strtok(trunk, " .,");

                    while (token != NULL)
                    {
                        v_line.push_back(token);
                        token = strtok(NULL, " .,");
                    }

                    
                }
                n_lines++;
            }
        }

        

};
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
#include "results.cpp"

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
        std::vector<InfoResult> v_results;

        void wordFinder(char *word,std::string file){
            std::ifstream ifile;
            std::string line;
            char trunk[256];
            char *token;
            int n_lines = 0;
            size_t pos;
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
                    fillResults(word, n_lines, v_line);
                    
                }
                n_lines++;
            }
        }
        void fillResults(char *word, int n_lines, std::vector<char *> &v_line)
        {
            std::string word_before, word_after;
            for (int i = 0; i < v_line.size(); i++)
            {
                word_before = "";
                word_after = "";
                if (strcmp(v_line[i], word) == 0)
                {
                    if (i != 0) word_before = std::string(v_line[i-1]);

                    if (i != v_line.size() - 1 ) word_after = std::string(v_line[i+1]);

                    v_results.push_back(InfoResult(word_before,word_after,std::string(word),n_lines));
                }
            }
        }

    public:

        wordfinder(int thread_id, int begin_line, int end_line)
        {
            this->id_thread = id_thread;
            this->begin_line = begin_line;
            this->end_line = end_line;
        }

        void teachResults()
        {
            for (int i = 0; i < v_results.size(); i++)
            {
                std::cout<< "[HILO " << id_thread+1 << " inicio: " << begin_line << " - final: " << end_line << "]" << " :: " << v_results.at(i).toString()<<std::endl;
            
            }
            
        }
        
        void operator ()(std::string file, char *word){
            wordFinder(word,file);
        }

        

};
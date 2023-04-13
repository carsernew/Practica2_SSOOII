
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
#include <string>

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
 * PURPOSE          :       Se mostraran los datos que se han conseguido en el programa
 *
 ********************************************************************************************/


class InfoResult
{
public:
    InfoResult(std::string bef_Word, std::string af_Word, std::string word, int lineNumber)
        : bef_Word{bef_Word}, af_Word{af_Word}, word{word}, lineNumber{lineNumber} {}

    std::string toString() const
    {
        return "line " + std::to_string(lineNumber) + " :: ... " + bef_Word + " " + word + (af_Word[0] == ',' ? "" : " ") + af_Word + " ...";
    }

private:
    std::string bef_Word;
    std::string af_Word;
    std::string word;
    int lineNumber;
};

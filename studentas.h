#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Studentas
{
    std::string var;
    std::string pav;
    std::vector<int> paz;
    int egz;
    float gal_vid;
    float gal_med;
};

// Funkcijų prototipai
double median(std::vector<int> paz);
Studentas Stud_iv();
Studentas Stud_rand();
Studentas Stud_file(std::ifstream &fin);

#endif

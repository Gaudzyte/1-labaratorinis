//#ifndef UTILS_H
//#define UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "studentas.h"
using std::sort;
using std::string;
using std::vector;

void issaugotiRezultatus(const std::vector<Studentas>& vargsiukai,
                         const std::vector<Studentas>& kietiakiai);

void rusiuoti(vector<Studentas>& grupe, int pasirinkimas);
int extractNumber(const string& pav);
//#endif

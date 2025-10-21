#define UTILS_H
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "studentas.h"
using std::sort;
using std::string;
using std::vector;
using std::left;
using std::ofstream;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;


void rusiuoti(vector<Studentas>& grupe, int pasirinkimas);
int extractNumber(const string& pav);

template <typename T>
void issaugotiRezultatus(const T &vargsiukai,
                         const T &kietiakiai)
{
     if (vargsiukai.size() != 0)
     {
          ofstream out1("vargsiukai.txt");
          out1 << left << setw(20) << "Pavarde"
               << setw(15) << "Vardas"
               << setw(20) << "Galutinis (Vid.)"
               << setw(20) << "Galutinis (Med.)" << endl;
          out1 << string(80, '-') << endl;

          for (auto &s : vargsiukai)
          {
               out1 << left << setw(20) << s.pav
                    << setw(15) << s.var
                    << fixed << setprecision(2)
                    << setw(20) << s.gal_vid
                    << setw(20) << s.gal_med << endl;
          }
          out1.close();
     }

     ofstream out2("kietiakiai.txt");
     out2 << left << setw(20) << "Pavarde"
          << setw(15) << "Vardas"
          << setw(20) << "Galutinis (Vid.)"
          << setw(20) << "Galutinis (Med.)" << endl;
     out2 << string(80, '-') << endl;

     for ( const auto &s : kietiakiai)
     {
          out2 << left << setw(20) << s.pav
               << setw(15) << s.var
               << fixed << setprecision(2)
               << setw(20) << s.gal_vid
               << setw(20) << s.gal_med << endl;
     }
     out2.close();
}

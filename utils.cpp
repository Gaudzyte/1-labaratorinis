#include "utils.h"

using namespace std;

void issaugotiRezultatus(const vector<Studentas> &vargsiukai,
                         const vector<Studentas> &kietiakiai)
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

     for (auto &s : kietiakiai)
     {
          out2 << left << setw(20) << s.pav
               << setw(15) << s.var
               << fixed << setprecision(2)
               << setw(20) << s.gal_vid
               << setw(20) << s.gal_med << endl;
     }
     out2.close();
}

int extractNumber(const string &pav)
{
     string digits;
     for (char c : pav)
     {
          if (isdigit(c))
               digits += c;
     }
     if (digits.empty())
          return 0;
     return stoi(digits);
}

void rusiuoti(vector<Studentas> &grupe, int pasirinkimas)
{
     sort(grupe.begin(), grupe.end(), [pasirinkimas](const Studentas &a, const Studentas &b)
          {
            if (pasirinkimas == 1) {
               return a.var < b.var;
            } else if (pasirinkimas == 2) {
               return a.pav < b.pav;
            } else if (pasirinkimas == 3) {
               return a.gal_vid < b.gal_vid;
            }
            else return false; });
}

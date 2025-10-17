#include "utils.h"

using namespace std;

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

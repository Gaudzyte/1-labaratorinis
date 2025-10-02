#include "utils.h"
#include <fstream>
#include <iomanip>

using namespace std;

void issaugotiRezultatus(const vector<Studentas>& vargsiukai,
                         const vector<Studentas>& kietiakiai)
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

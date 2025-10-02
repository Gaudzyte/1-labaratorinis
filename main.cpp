#include "studentas.h"
#include "utils.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <random>
#include <fstream>
#include <cctype>
#include <chrono>

using namespace std;
using std::cin;
using std::cout;
using std::end;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;
using namespace std::chrono;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

int extractNumber(const string& pav) {
    string digits;
    for (char c : pav) {
        if (isdigit(c)) digits += c;
    }
    if (digits.empty()) return 0;
    return stoi(digits);
}

void rusiuoti(vector<Studentas>& grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        // pagal vardą
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.var < b.var;
        });
    } 
    else if (pasirinkimas == 2) {
        // pagal pavardės numerį
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            int na = extractNumber(a.pav);
            int nb = extractNumber(b.pav);
            if (na == nb) return a.pav < b.pav;
            return na < nb;
        });
    } 
    else if (pasirinkimas == 3) {
        // pagal galutinį pažymį (vidurkį)
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.gal_vid < b.gal_vid;
        });
    }
}

int main()
{
    vector <Studentas> Grupe;

    int pasirinkimas;
    cout << "Pasirinkite veiksma:" << endl;
    cout << "1 - Ivesti pazymius ranka" << endl;
    cout << "2 - Generuoti atsitiktinius pazymius ir egzamina" << endl;
    cout << "3 - Nuskaityti studentus is failo" << endl;
    cout << "Pasirinkimas: ";
    cin >> pasirinkimas;

    while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3)
    {
        cout << "Neteisingas pasirinkimas! Bandykite dar karta: ";
        cin >> pasirinkimas;
    }

    if (pasirinkimas == 1)
    {
        int m;
        cout << "Kiek studentu grupeje? ";
        cin >> m;
        for (int z = 0; z < m; z++)
        {
            Grupe.push_back(Stud_iv());
        }
    }
    else if (pasirinkimas == 2)
    {
        int m;
        cout << "Kiek studentu grupeje? ";
        cin >> m;

        auto start = high_resolution_clock::now();

        for (int z = 0; z < m; z++)
        {
            Grupe.push_back(Stud_rand());
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Failu kurimas uztruko: " << duration.count() << " ms" << endl;
    }
    else if (pasirinkimas == 3)
    {
        string failoPav;
        cout << "Iveskite failo pavadinima: ";
        cin >> failoPav;

        ifstream fin(failoPav);
        if (!fin)
        {
            cout << "Nepavyko atidaryti failo " << failoPav << endl;
            return 1;
        }

        string headerLine;
        getline(fin, headerLine);

        auto start = high_resolution_clock::now();

        while (fin.peek() != EOF)
        {
            Grupe.push_back(Stud_file(fin));
        }

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Failu nuskaitymas uztruko: " << duration.count() << " ms" << endl;

        cout << "Duomenys nuskaityti is failo " << failoPav << "." << endl;
    }

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    for (auto &s : Grupe)
    {
        if (s.gal_vid < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakiai.push_back(s);
    }

    int rusiavimas;
    cout << "Pagal ka norite rusiuoti?" << endl;
    cout << "1 - Pagal varda" << endl;
    cout << "2 - Pagal pavarde (su numeriais)" << endl;
    cout << "3 - Pagal galutini pazymi (vid.)" << endl;
    cout << "Pasirinkimas: ";
    cin >> rusiavimas;

    rusiuoti(vargsiukai, rusiavimas);
    rusiuoti(kietiakiai, rusiavimas);

    issaugotiRezultatus(vargsiukai, kietiakiai);

    cout << "Sugeneruoti du failai: vargsiukai.txt ir kietiakiai.txt" << endl;
}

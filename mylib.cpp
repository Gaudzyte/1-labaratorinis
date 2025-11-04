#include "mylib.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>    
#include <sstream>     
#include <string>       
#include <fstream>
using namespace std;

vector<Studentas> NuskaitytiVector(const string &failas)
{
    ifstream fin(failas);
    if (!fin)
    {
        cerr << "Nepavyko atidaryti failo: " << failas << endl;
        return {};
    }

    string header;
    getline(fin, header); // praleidžiam stulpelių eilutę

    vector<Studentas> studentai;
    studentai.reserve(100000);

    Studentas s;
    while (fin >> s.var >> s.pav)
    {
        s.paz.clear();
        int x;
        for (int i = 0; i < 4; ++i)
        {
            if (!(fin >> x))
                break;
            s.paz.push_back(x);
        }
        fin >> s.egz;

        double suma = 0;
        for (int paz : s.paz)
            suma += paz;
        double vid = suma / s.paz.size();
        s.gal_vid = vid * 0.4 + s.egz * 0.6;

        studentai.push_back(s);
    }

    return studentai;
}

void Paskirstymas_vector_1_strategija(const vector<Studentas> &Grupe, const int irasu_sk, const string& failo_vardas)
{
    Timer t;
    vector<Studentas> Vargsai, Kietiakai;
    for (auto &stud : Grupe)
    {
        if (stud.gal_vid < 5)
            Vargsai.push_back(stud);
        else
            Kietiakai.push_back(stud);
    }
    cout << irasu_sk << " irasu vektoriaus padalijimo 1 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Kietiakai, 1, failo_vardas);
    Spausdinimas(Vargsai, 1, failo_vardas);
}

void Paskirstymas_vector_2_strategija(vector<Studentas> Grupe, const int irasu_sk, const string& failo_vardas)
{
    Timer t;
    vector<Studentas> Vargsai;
    size_t newSize = 0;
    for (size_t i = 0; i < Grupe.size(); i++)
    {
        if (Grupe[i].gal_vid < 5)
            Vargsai.push_back(Grupe[i]);
        else
            Grupe[newSize++] = std::move(Grupe[i]);
    }
    Grupe.erase(Grupe.begin() + newSize, Grupe.end());
    cout << irasu_sk << " irasu vektoriaus padalijimo 2 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 2, failo_vardas);
    Spausdinimas(Vargsai, 2, failo_vardas);
}

void Paskirstymas_vector_3_strategija(vector<Studentas>& Grupe, const int irasu_sk, const string& failo_vardas) {
    Timer t;
    vector<Studentas> Vargsai;
    Vargsai.reserve(Grupe.size());

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),
                        [](const Studentas& stud) {
                            return stud.gal_vid >= 5;
                        });

    auto new_end = std::remove_if(Grupe.begin(), Grupe.end(),
                                  [](const Studentas& stud) {
                                      return stud.gal_vid < 5;
                                  });
    Grupe.erase(new_end, Grupe.end());

    cout << irasu_sk << " irasu vektoriaus padalijimo 3 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 3, failo_vardas);
    Spausdinimas(Vargsai, 3, failo_vardas);
}

void Paskirstymas_list_1_strategija(const list<Studentas> &Grupe, const int irasu_sk, const string& failo_vardas)
{
    Timer t;
    list<Studentas> Vargsai, Kietiakai;
    for (auto &stud : Grupe)
    {
        if (stud.gal_vid < 5)
            Vargsai.push_back(stud);
        else
            Kietiakai.push_back(stud);
    }
    cout << irasu_sk << " irasu saraso padalijimo 1 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Kietiakai, 1, failo_vardas);
    Spausdinimas(Vargsai, 1, failo_vardas);
}

void Paskirstymas_list_2_strategija(list<Studentas> Grupe, const int irasu_sk, const string& failo_vardas)
{
    Timer t;
    list<Studentas> Vargsai;
    for (auto it = Grupe.begin(); it != Grupe.end();)
    {
        if (it->gal_vid < 5)
        {
            Vargsai.push_back(*it);
            it = Grupe.erase(it);
        }
        else
        {
            ++it;
        }
    }
    cout << irasu_sk << " irasu saraso padalijimo 2 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 2, failo_vardas);
    Spausdinimas(Vargsai, 2, failo_vardas);
}

void Paskirstymas_list_3_strategija(list<Studentas>& Grupe, const int irasu_sk, const string& failo_vardas) {
    Timer t;
    list<Studentas> Vargsai;

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),
                        [](const Studentas& stud) {
                            return stud.gal_vid >= 5;
                        });

    Grupe.remove_if([](const Studentas& stud) {
        return stud.gal_vid < 5;
    });

    cout << irasu_sk << " irasu saraso padalijimo 3 strategijos laikas: "
         << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 3, failo_vardas);
    Spausdinimas(Vargsai, 3, failo_vardas);
}

void TestavimasIsFailo(const string &failas, int irasu_sk)
{
    cout << "\n"
         << failas << "\n";

    Timer t;
    auto Grupe_vector = NuskaitytiVector(failas);
    double readTime = t.elapsed();
    list<Studentas> Grupe_list(Grupe_vector.begin(), Grupe_vector.end());

    cout << "Failo nuskaitymas uztruko: " << readTime << " s\n";

    Paskirstymas_vector_1_strategija(Grupe_vector, irasu_sk, failas);
    Paskirstymas_vector_2_strategija(Grupe_vector, irasu_sk, failas);
    Paskirstymas_vector_3_strategija(Grupe_vector, irasu_sk, failas);
    Paskirstymas_list_1_strategija(Grupe_list, irasu_sk, failas);
    Paskirstymas_list_2_strategija(Grupe_list, irasu_sk, failas);
    Paskirstymas_list_3_strategija(Grupe_list, irasu_sk, failas);
}

template <typename T>
void Spausdinimas(const T &Spausd_gr, const int& strat, const std::string& failo_vardas) {
    if (Spausd_gr.empty()) return;

    std::stringstream ss;
    ss << std::setw(15) << std::left << "Vardas"
       << std::setw(20) << std::left << "Pavarde"
       << std::setw(17) << std::left << "Galutinis (Vid.)" << std::endl;
    ss << std::string(52, '-') << std::endl;

    for (const auto &Past : Spausd_gr) {
        ss << std::setw(15) << std::left << Past.var
           << std::setw(20) << std::left << Past.pav
           << std::setw(17) << std::left << std::fixed
           << std::setprecision(2) << Past.gal_vid << std::endl;
    }

    auto it = Spausd_gr.begin();
    std::string tipas = (it->gal_vid >= 5) ? "_kietiakai" : "_vargsiukai";
    std::string failoPav = failo_vardas.substr(0, failo_vardas.find_last_of('.')) +
                           tipas + std::to_string(strat) + ".txt";

    std::ofstream out(failoPav);
    out << ss.str();
    out.close();
}

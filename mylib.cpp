#include "mylib.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <chrono>
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

void Paskirstymas_vector_1_strategija(const vector<Studentas> &Grupe, const int irasu_sk)
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
}

void Paskirstymas_vector_2_strategija(vector<Studentas> Grupe, const int irasu_sk)
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
}

void Paskirstymas_vector_3_strategija(vector<Studentas>& Grupe, const int irasu_sk) {
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
}

void Paskirstymas_list_1_strategija(const list<Studentas> &Grupe, const int irasu_sk)
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
}

void Paskirstymas_list_2_strategija(list<Studentas> Grupe, const int irasu_sk)
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
}

void Paskirstymas_list_3_strategija(list<Studentas>& Grupe, const int irasu_sk) {
    Timer t;
    list<Studentas> Vargsai;

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),
                        [](const Studentas& stud) {
                            return stud.gal_vid < 5;
                        });

    auto border = std::stable_partition(Grupe.begin(), Grupe.end(),
                                        [](const Studentas& stud) {
                                            return stud.gal_vid >= 5;
                                        });
    Grupe.erase(border, Grupe.end());

    cout << irasu_sk << " irasu saraso padalijimo 3 strategijos laikas: "
         << t.elapsed() << " s\n";
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

    Paskirstymas_vector_1_strategija(Grupe_vector, irasu_sk);
    Paskirstymas_vector_2_strategija(Grupe_vector, irasu_sk);
    Paskirstymas_vector_3_strategija(Grupe_vector, irasu_sk);
    Paskirstymas_list_1_strategija(Grupe_list, irasu_sk);
    Paskirstymas_list_2_strategija(Grupe_list, irasu_sk);
    Paskirstymas_list_3_strategija(Grupe_list, irasu_sk);
}

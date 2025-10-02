#include "studentas.h"
#include <algorithm>
#include <limits>
#include <random>

using namespace std;

double median(vector<int> paz)
{
    sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0)
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    else
        return paz[n / 2];
}

Studentas Stud_iv()
{
    Studentas Pirmas;
    cout << "Iveskite studento duomenis." << endl;
    cout << "Vardas: ";
    cin >> Pirmas.var;
    cout << "Pavarde: ";
    cin >> Pirmas.pav;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Iveskite pazymius (Norint baigti - ENTER du kartus):" << endl;
    string eilute;
    int suma = 0;
    int tusti = 0;

    while (true)
    {
        getline(cin, eilute);

        if (eilute.empty())
        {
            tusti++;
            if (tusti == 1)
                break;
            continue;
        }
        else
            tusti = 0;

        int laik_paz = stoi(eilute);
        Pirmas.paz.push_back(laik_paz);
        suma += laik_paz;
    }

    cout << "Iveskite egzamino pazymi: ";
    cin >> Pirmas.egz;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!Pirmas.paz.empty())
    {
        double vid = double(suma) / double(Pirmas.paz.size());
        double med = median(Pirmas.paz);
        Pirmas.gal_vid = vid * 0.4 + 0.6 * Pirmas.egz;
        Pirmas.gal_med = med * 0.4 + 0.6 * Pirmas.egz;
    }
    else
    {
        Pirmas.gal_vid = 0.6 * Pirmas.egz;
        Pirmas.gal_med = 0.6 * Pirmas.egz;
    }

    return Pirmas;
}

Studentas Stud_rand()
{
    Studentas S;
    cout << "Iveskite studento duomenis." << endl;
    cout << "Vardas: ";
    cin >> S.var;
    cout << "Pavarde: ";
    cin >> S.pav;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> paz_dist(1, 10);
    uniform_int_distribution<> egz_dist(1, 10);
    uniform_int_distribution<> kiek_dist(1, 7);

    int suma = 0;
    int kiek = kiek_dist(gen);

    for (int i = 0; i < kiek; i++)
    {
        int paz = paz_dist(gen);
        S.paz.push_back(paz);
        suma += paz;
    }

    S.egz = egz_dist(gen);
    double vid = double(suma) / double(S.paz.size());
    double med = median(S.paz);
    S.gal_vid = vid * 0.4 + 0.6 * S.egz;
    S.gal_med = med * 0.4 + 0.6 * S.egz;

    return S;
}

Studentas Stud_file(ifstream &fin)
{
    Studentas S;
    S.paz.clear();
    if (!(fin >> S.var >> S.pav))
        return S;

    vector<int> laikini;
    int x;
    while (fin.peek() != '\n' && fin >> x)
        laikini.push_back(x);

    if (!laikini.empty())
    {
        S.egz = laikini.back();
        laikini.pop_back();
        S.paz = laikini;

        int suma = 0;
        for (auto p : S.paz)
            suma += p;
        double vid = double(suma) / S.paz.size();
        double med = median(S.paz);
        S.gal_vid = vid * 0.4 + 0.6 * S.egz;
        S.gal_med = med * 0.4 + 0.6 * S.egz;
    }
    else
    {
        S.egz = 0;
        S.gal_vid = 0.6 * S.egz;
        S.gal_med = 0.6 * S.egz;
    }

    return S;
}

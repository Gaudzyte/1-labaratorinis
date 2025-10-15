#include "studentas.h"
#include "utils.h"
#include "libraries.h"
#include <list>

int main()
{
    using namespace std::chrono;

    int konteineris;
    cout << "Pasirinkite konteineri:\n";
    cout << "1 - std::vector\n";
    cout << "2 - std::list\n";
    cout << "Pasirinkimas: ";
    cin >> konteineris;

    double readSec = 0.0, sortSec = 0.0, splitSec = 0.0, vargsiukaiSec = 0.0, kietiakiaiSec = 0.0;
    size_t nIrasu = 0;

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

    steady_clock::time_point programStart;

    if (konteineris == 1)
    {
        vector<Studentas> Grupe;

        if (pasirinkimas == 1)
        {
            int m;
            cout << "Kiek studentu grupeje? ";
            cin >> m;
            for (int z = 0; z < m; z++)
            {
                Studentas s = Stud_iv();
                Grupe.push_back(s);
                cout << "Studento " << s.var << " " << s.pav
                     << " adresas konteineryje: " << &Grupe.back() << endl;
            }
        }
        else if (pasirinkimas == 2)
        {
            int m;
            cout << "Kiek studentu grupeje? ";
            cin >> m;
            auto start = steady_clock::now();
            for (int z = 0; z < m; z++)
                Grupe.push_back(Stud_rand());
            auto end = steady_clock::now();
            readSec = duration_cast<duration<double>>(end - start).count();
            nIrasu = Grupe.size();
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
            auto start = steady_clock::now();
            while (true)
            {
                Studentas s = Stud_file(fin);
                if (!fin)
                    break;
                Grupe.push_back(s);
            }
            auto end = steady_clock::now();
            readSec = duration_cast<duration<double>>(end - start).count();
            nIrasu = Grupe.size();
            fin.close();
        }

        int rusiavimas;
        cout << "Pagal ka norite rusiuoti?" << endl;
        cout << "1 - Pagal varda" << endl;
        cout << "2 - Pagal pavarde" << endl;
        cout << "3 - Pagal galutini pazymi (vid.)" << endl;
        cout << "Pasirinkimas: ";
        cin >> rusiavimas;

        programStart = steady_clock::now();

        auto startSort = steady_clock::now();
        rusiuoti(Grupe, rusiavimas);
        auto endSort = steady_clock::now();
        sortSec = duration_cast<duration<double>>(endSort - startSort).count();

        auto startSplit = steady_clock::now();
        vector<Studentas> vargsiukai, kietiakiai;
        for (auto &s : Grupe)
        {
            if (s.gal_vid < 5.0)
                vargsiukai.push_back(s);
            else
                kietiakiai.push_back(s);
        }
        Grupe.clear();
        auto endSplit = steady_clock::now();
        splitSec = duration_cast<duration<double>>(endSplit - startSplit).count();

        auto startVargs = steady_clock::now();
        issaugotiRezultatus(vargsiukai, {});
        auto endVargs = steady_clock::now();
        vargsiukaiSec = duration_cast<duration<double>>(endVargs - startVargs).count();

        auto startKiet = steady_clock::now();
        issaugotiRezultatus({}, kietiakiai);
        auto endKiet = steady_clock::now();
        kietiakiaiSec = duration_cast<duration<double>>(endKiet - startKiet).count();
    }

    else if (konteineris == 2)
    {
        list<Studentas> Grupe;
        if (pasirinkimas == 1)
        {
            int m;
            cout << "Kiek studentu grupeje? ";
            cin >> m;
            for (int z = 0; z < m; z++)
                Grupe.push_back(Stud_iv());
        }
        else if (pasirinkimas == 2)
        {
            int m;
            cout << "Kiek studentu grupeje? ";
            cin >> m;
            auto start = steady_clock::now();
            for (int z = 0; z < m; z++)
                Grupe.push_back(Stud_rand());
            auto end = steady_clock::now();
            readSec = duration_cast<duration<double>>(end - start).count();
            nIrasu = Grupe.size();
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
            auto start = steady_clock::now();
            while (true)
            {
                Studentas s = Stud_file(fin);
                if (!fin) break;
                Grupe.push_back(s);
            }
            auto end = steady_clock::now();
            readSec = duration_cast<duration<double>>(end - start).count();
            nIrasu = Grupe.size();
            fin.close();
        }

        int rusiavimas;
        cout << "Pagal ka norite rusiuoti?" << endl;
        cout << "1 - Pagal varda" << endl;
        cout << "2 - Pagal pavarde" << endl;
        cout << "3 - Pagal galutini pazymi (vid.)" << endl;
        cout << "Pasirinkimas: ";
        cin >> rusiavimas;

        programStart = steady_clock::now();

        auto startSort = steady_clock::now();
        Grupe.sort([rusiavimas](const Studentas &a, const Studentas &b)
        {
            if (rusiavimas == 1) return a.var < b.var;
            if (rusiavimas == 2) return a.pav < b.pav;
            if (rusiavimas == 3) return a.gal_vid < b.gal_vid;
            return false;
        });
        auto endSort = steady_clock::now();
        sortSec = duration_cast<duration<double>>(endSort - startSort).count();

        auto startSplit = steady_clock::now();
        list<Studentas> vargsiukai, kietiakiai;
        for (auto &s : Grupe)
        {
            if (s.gal_vid < 5.0)
                vargsiukai.push_back(s);
            else
                kietiakiai.push_back(s);
        }
        Grupe.clear();
        auto endSplit = steady_clock::now();
        splitSec = duration_cast<duration<double>>(endSplit - startSplit).count();

        auto startVargs = steady_clock::now();
        issaugotiRezultatus(vector<Studentas>(vargsiukai.begin(), vargsiukai.end()), {});
        auto endVargs = steady_clock::now();
        vargsiukaiSec = duration_cast<duration<double>>(endVargs - startVargs).count();

        auto startKiet = steady_clock::now();
        issaugotiRezultatus({}, vector<Studentas>(kietiakiai.begin(), kietiakiai.end()));
        auto endKiet = steady_clock::now();
        kietiakiaiSec = duration_cast<duration<double>>(endKiet - startKiet).count();
    }

    auto programEnd = steady_clock::now();
    double totalSec = duration_cast<duration<double>>(programEnd - programStart).count();

    cout << fixed << setprecision(6);
    cout << "Failas uzdarytas\nFailo is " << nIrasu
         << " irasu nuskaitymo laikas: " << readSec << "\n"
         << nIrasu << " irasu rusiavimas didejimo tvarka laikas, su sort funkcija: " << sortSec << "\n"
         << nIrasu << " irasu dalijimo i dvi grupes laikas: " << splitSec << "\n"
         << nIrasu << " irasu vargsiuku irasymo i faila laikas: " << vargsiukaiSec << "\n"
         << nIrasu << " irasu keteku irasymo i faila laikas: " << kietiakiaiSec << "\n"
         << nIrasu << " irasu testo laikas: " << totalSec << endl;

    return 0;
}

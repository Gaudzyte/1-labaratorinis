#include "studentas.h"
#include "utils.h"
#include "libraries.h"

int main()
{
    auto programStart = high_resolution_clock::now();

    vector <Studentas> Grupe;

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

        auto start = high_resolution_clock::now();

        while (true)
        {
            Studentas s = Stud_file(fin);
            if (!fin) break;
            Grupe.push_back(s);
        }


        auto end = high_resolution_clock::now();
        readSec = duration_cast<duration<double>>(end - start).count();
        nIrasu = Grupe.size();
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

    auto startSort = high_resolution_clock::now();
    rusiuoti(Grupe, rusiavimas);
    auto endSort = high_resolution_clock::now();
    sortSec = duration_cast<duration<double>>(endSort - startSort).count();

    auto startSplit = high_resolution_clock::now();
    vector<Studentas> vargsiukai, kietiakiai;
    for (auto &s : Grupe) {
        if (s.gal_vid < 5.0) vargsiukai.push_back(s);
        else kietiakiai.push_back(s);
    }
    //cout << "varg: " << vargsiukai.size() << " ; kiet: " << kietiakiai.size();
    Grupe.clear();
    auto endSplit = high_resolution_clock::now();
    splitSec = duration_cast<duration<double>>(endSplit - startSplit).count();

    auto startVargs = high_resolution_clock::now();
    issaugotiRezultatus(vargsiukai, {}); 
    auto endVargs = high_resolution_clock::now();
    vargsiukaiSec = duration_cast<duration<double>>(endVargs - startVargs).count();

    auto startKiet = high_resolution_clock::now();
    issaugotiRezultatus({}, kietiakiai); 
    auto endKiet = high_resolution_clock::now();
    kietiakiaiSec = duration_cast<duration<double>>(endKiet - startKiet).count();

    auto programEnd = high_resolution_clock::now();
    double totalSec = duration_cast<duration<double>>(programEnd - programStart).count();

    cout << "Failas uzdarytas\nFailo is " << nIrasu 
         << " irasu nuskaitymo laikas: " << readSec << "\n"
         << nIrasu << " irasu rusiavimas didejimo tvarka laikas, su sort funkcija: " << sortSec << "\n"
         << nIrasu << " irasu dalijimo i dvi grupes laikas: " << splitSec << "\n"
         << nIrasu << " irasu vargsiuku irasymo i faila laikas: " << vargsiukaiSec << "\n"
         << nIrasu << " irasu keteku irasymo i faila laikas: " << kietiakiaiSec << "\n"
         << nIrasu << " irasu testo laikas: " << totalSec << endl;

    return 0;
}

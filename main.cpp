#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;
using std::cout;
using std::cin;
using std::end;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

struct Studentas
{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    float gal_vid;
    float gal_med; 
};

double median(vector<int> paz) {
    sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) 
        return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    else 
        return paz[n/2];
}

Studentas Stud_iv(){
    Studentas Pirmas;
    cout << "Iveskite studento duomenis." << endl;
    cout << "Vardas: "; 
    cin >> Pirmas.var; 
    cout << "Pavarde: "; 
    cin >> Pirmas.pav;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // išvalom buferį

    cout << "Iveskite pazymius (Norint baigti - spauskite du kartus ENTER):" << endl;
    string eilute;
    int suma = 0;
    int tusti = 0;

    while (true) {
        getline(cin, eilute);

        if (eilute.empty()) {
            tusti++;
            if (tusti == 1) break; // du ENTER paeiliui = pabaiga
            continue;
        } else {
            tusti = 0; // buvo įvestas skaičius
        }
        int laik_paz = stoi(eilute); // darom prielaidą, kad visada skaičius
        Pirmas.paz.push_back(laik_paz);
        suma += laik_paz;
    }

    cout << "Iveskite egzamino pazymi: "; 
    cin >> Pirmas.egz;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!Pirmas.paz.empty()) {
        double vid = double(suma) / double(Pirmas.paz.size());
        double med = median(Pirmas.paz);

        Pirmas.gal_vid = vid * 0.4 + 0.6 * Pirmas.egz;
        Pirmas.gal_med = med * 0.4 + 0.6 * Pirmas.egz;
    } else {
        Pirmas.gal_vid = 0.6 * Pirmas.egz;
        Pirmas.gal_med = 0.6 * Pirmas.egz;
    }

    return Pirmas;
}

int main()
{
    vector<Studentas>Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;
    Studentas past;
    for(auto z=0; z<m; z++){
        Grupe.push_back(Stud_iv());
    }
    //past = Stud_iv();

    cout << endl;
    cout << left << setw(15) << "Pavarde" 
         << setw(15) << "Vardas" 
          << setw(20) << "Galutinis (Vid.)"
         << setw(20) << "Galutinis (Med.)" << endl;
    cout << string(70, '-') << endl;
    
    
    for(auto &past : Grupe) {
        cout << left << setw(15) << past.pav
             << setw(15) << past.var
             << fixed << setprecision(2) 
             << setw(20) << past.gal_vid
             << setw(20) << past.gal_med << endl;
    }
}

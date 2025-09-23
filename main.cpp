#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

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
    int n, laik_paz, suma = 0;
    Studentas Pirmas;
    cout<<"Iveskite studento duomenis."<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var; 
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<": "; cin>>n; 
    for(int a=0; a<n; a++)
        {
        cout<<"Iveskite "<<a+1<<" pazymi: "; cin>>laik_paz;
        Pirmas.paz.push_back(laik_paz);
        suma += laik_paz; //sum+=Pirmas.paz[a];
        }
    cout<<"Iveskite egzamino pazymi:"; cin>>Pirmas.egz;

    double vid = double(suma) / double(n);
    double med = median(Pirmas.paz);

    Pirmas.gal_vid = vid * 0.4 + 0.6 * Pirmas.egz;
    Pirmas.gal_med = med * 0.4 + 0.6 * Pirmas.egz;
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

// Example program
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
    float gal;
    };

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
    Pirmas.gal = double(suma)/double(n) * 0.4 + 0.6 * Pirmas.egz;  
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
         << setw(15) << "Galutinis (vid.)" << endl;
    cout << string(45, '-') << endl;
    
    
    for(auto &past : Grupe) {
        cout << left << setw(15) << past.pav
             << setw(15) << past.var
             << fixed << setprecision(2) << setw(15) << past.gal << endl;
    }
}


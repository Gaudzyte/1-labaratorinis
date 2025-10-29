# Objektinis programavimas 

## **v0.1**
Programa leidžia pasirinkti:
1. "Įvesti pažymius ranka"
   - Įvedamas studentų skaičius grupėje, jų vardai, pavardės ir pažymiai.
   
2. "Generuoti atsitiktinius pažymius ir egzaminą" 
   - Programa automatiškai sugeneruoja nurodytą kiekį studentų su pažymiais ir egzamino rezultatais.
  
3. "Nuskaityti studentus iš failo"
   - Programa nuskaito duomenis iš failų
     
Programa studentų vardus ir pavardes bei jų galutinį vidurkį/medianą atspausdina ekrane.

## **v0.2**
Sukurta programa kur yra generuojami studentų duomenys.
#### Studentai automatiškai suskirstomi į dvi grupes: ####
- **vargšiukai** – galutinis pažymys < 5.0;
- **kietiakai** – galutinis pažymys ≥ 5.0.

#### Galima pasirinkti rūšiavimo kriterijų: ####
- pagal vardą;
- pagal pavardę;
- pagal galutinį pažymį (vidurkį).

#### Galiausiai programa matuoja ir išveda šių etapų vykdymo trukmę: ####
- įrašų nuskaitymo laiką,
- rūšiavimo laiką,
- dalijimo į dvi grupes laiką,
- rezultatų įrašymo laiką,
- bendrą viso testo laiką.

## **v0.3**

#### Paleidus kodą leidžiama pasirinkti konteinerį: ####
- **std::vector**
-  **std::list** 

Pridėta galimybė matyti vector ir list adresą kompiuterio atmintyje, kai duomenys apie studentus yra įrašomi ranka.

Atlikta programos spartos analizė

<img width="1066" height="622" alt="image" src="https://github.com/user-attachments/assets/8ccfbfa4-bffc-4d70-8765-031e53283a63" />

Galime matyti jog duomenų nuskaitymo laikas yra labai panašus tarp vector ir list. Duomenų rūšiavimą list atlieka žymiai greičiau negu vector. Duomenų dalijimą į dvi grupes šįkart vector atlieka sparčiau. Nors paprastai duomenų įrašymą greičiau atlieka vector, šiuo atveju, esant 10 milijonų duomenų, list veikė greičiau – net 19 sekundžių skirtumu.

#### Testavimo sistemos parametrai: ####
  - CPU - **AMD Ryzen 5 7520U with Radeon Graphics**
  - 2.80GHz
  - RAM - **16GB**
  - SSD - **477GB**

    ## **v1.0**


<img width="821" height="252" alt="image" src="https://github.com/user-attachments/assets/5f94ef9e-b3fe-417f-b720-fe56bafbd4bd" />


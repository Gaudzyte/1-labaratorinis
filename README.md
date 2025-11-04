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
Atliktos trys strategijos optimizuojant studentų rūšiavimą į dvi kategorijas:
- 1 strategija: yra identiška, kaip veikdavo anksčiau.
- 2 strategija: yra sukuriamas tik vienas papildomas konteineris - "Vargšiukai". Tie studentai, kurie neatitinka kriterijaus (vidurkis mažesnis už 5) yra ištrinami iš pagrindinio konteinerio.
- 3 strategija: pritaikyti algoritmai (std::remove_if, std::remove_copy_if, std::stable_partition), jog būtų paspartintas skaidymas.

Rezultatai sekundėmis:

<img width="821" height="252" alt="image" src="https://github.com/user-attachments/assets/5f94ef9e-b3fe-417f-b720-fe56bafbd4bd" />

**Išvados:**

3 strategija vector konteineryeje greičiausiai atliko spartos analizę. Tačiau ir 1000 įrašų turinčio failo duomenys buvo greitai apdoroti, naudojant antrąją strategiją tiek su vector, tiek su list konteineriais.


**Naudojimosi ir įdiegimo instrukcija:**

1. Atsisiųskite failus main.cpp, mylib.cpp, laikas.h, mylib.h, studentas.h, Generuojami file, CMakeLists.txt ir **runme.bat**
2. Patikrinkite ar kompiuteryje turite įdiegtus C++ kompiliatorių ir projekto generavimo įrankius cmake. Jei jų neturite - įdiekite.
3. Kompiuteryje sukurkite naują aplanką, kuriame vykdysite kodo paleidimą ir įkelkite CMakeLists.txt ir **runme.bat**
4. Šiame aplankale taip pat sukurkite aplanką "src" ir "include".
5. Į "src" aplankalą sukelkite atsisiųstus .cpp failus ir sugeneruotus studentų failus (studentai.1000.txt, studentai.10000.txt ir t.t.), o į "include" .h failus.
6. Paspauskite ant **runme.bat** ir programa pradės veikti.
7. Galiausiai matysite programos veikimo spartą skirtingoms strategijoms.

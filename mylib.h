#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "studentas.h"
#include "timer.h"

std::vector<Studentas> NuskaitytiVector(const std::string& failas);

// Strategijos
void Paskirstymas_vector_1_strategija(const std::vector<Studentas>& Grupe, const int irasu_sk);
void Paskirstymas_vector_2_strategija(std::vector<Studentas> Grupe, const int irasu_sk);
void Paskirstymas_list_1_strategija(const std::list<Studentas>& Grupe, const int irasu_sk);
void Paskirstymas_list_2_strategija(std::list<Studentas> Grupe, const int irasu_sk);

// Testavimas
void TestavimasIsFailo(const std::string& failas, int irasu_sk);

#endif

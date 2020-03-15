#ifndef ANTRASTES_LIST_H_INCLUDED
#define ANTRASTES_LIST_H_INCLUDED

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <list>
#include <numeric>
#include <fstream>
#include <cctype>
#include <random>
#include <chrono>

#define daugiausia 50

struct student;
class Rand_int;

void ArSkaiciusTinkamas (int& skaicius, int pradzia, int pabaiga);
double rasti_mediana_list (std::list <int> listas);
double vidurkis_list (std::list<int> listas, int n);
bool compareAlphabet(student a, student b);
void failugeneravimas (int a, int b);
void failugeneravimas1000 (int a);
void failugeneravimas10000 (int a);
void failugeneravimas100000 (int a);
void failugeneravimas1000000 (int a);
void failugeneravimas10000000 (int a);
void skaitymas_is_failo_listas (std::list<student> &studentas, std::string kas);
void pirmine_apklausa (std::string &kas, std::string &ar_generuoti, std::string &duomenu_ivedimas, int &koki_faila_generuoti, int &kiek_nd);
void F_duomenu_ivedimas_listas(std::string kas, std::list<student> &studentas);
void spausdinimas_listas(std::list<student> a, std::string b);
void koks_konteineris (char& simbolis, char pirmas, char antras, char trecias);
void listas();


#endif
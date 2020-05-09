#ifndef ANTRASTES_VEKTORIUS_H_INCLUDED
#define ANTRASTES_VEKTORIUS_H_INCLUDED


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>
#include <cctype>
#include <random>
#include <chrono>

#define daugiausia 50

class student1;
class Rand_int;


void ArSkaiciusTinkamas (int& skaicius, int pradzia, int pabaiga);
double rastimediana (std::vector<int> vekt);
bool compareAlphabet(const student1 a, const student1 b);
bool rikiuojam_pagal_balaD(const student1 a, const student1  b);
void spausdinimas(std::vector<student1> a, char b);
void spausdinimas(std::vector<student1> kiet, std::vector<student1> vargs, char b);
void failugeneravimas (int a, int b);
void skaitymas_is_failo (int egz, char kas, double ndvid, double ndsum, std::vector<student1> &studentas);
void pirmine_apklausa (char &kas, char &ar_generuoti, char &duomenu_ivedimas,
 int &koki_faila_generuoti, int &kiek_nd, int &strategija);
void paskirstymas (std::vector<student1> &a);
void paskirstymas2 (std::vector<student1> &a, std::vector<student1> &kiet);
void paskirstymas1 (std::vector<student1> &a, std::vector<student1> &vargs, std::vector<student1> &kiet);
void F_duomenu_ivedimas(double ndsum, int egz, double ndvid, char kas, std::vector<student1> &studentas);
void koks_konteineris (char& simbolis, char pirmas, char antras, char trecias);
void vektorius ();

#endif // ANTRASTES_VEKTORIUS_H_INCLUDED
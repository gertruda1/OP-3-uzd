#ifndef ANTRASTES_DEQUE_H_INCLUDED
#define ANTRASTES_DEQUE_H_INCLUDED


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include <cctype>
#include <random>
#include <chrono>

#define daugiausia 50


struct student;
class Rand_int;

void ArSkaiciusTinkamas (int& skaicius, int pradzia, int pabaiga);
double rastimediana_deque (std::deque<int> vekt);
bool compareAlphabet(student a, student b);
void spausdinimas_deque(std::deque<student> a, std::string b);
void spausdinimas_deque(std::deque<student> kiet, std::deque<student> vargs, std::string b);
void failugeneravimas (int a, int b);
void failugeneravimas1000 (int a);
void failugeneravimas10000 (int a);
void failugeneravimas100000 (int a);
void failugeneravimas1000000 (int a);
void failugeneravimas10000000 (int a);
void skaitymas_is_failo_deque (int egz, std::string kas, double ndvid, double ndsum, std::deque<student> &studentas);
void pirmine_apklausa (std::string &kas, std::string &ar_generuoti, std::string &duomenu_ivedimas, 
int &koki_faila_generuoti, int &kiek_nd, int &strategija);
void paskirstymas_deque (std::deque<student> &a);
bool rikiuojam_pagal_balaD(student a, student  b);
void paskirstymas1_deque (std::deque<student> &a, std::deque<student> &vargs, std::deque<student> &kiet);
void paskirstymas2_deque (std::deque<student> &a, std::deque<student> &kiet);
void F_duomenu_ivedimas_deque(double ndsum, int egz, double ndvid, std::string kas, std::deque<student> &studentas);
void koks_konteineris (char& simbolis, char pirmas, char antras, char trecias);
void deque ();

#endif // ANTRASTES_DEQU_H_INCLUDED
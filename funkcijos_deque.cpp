#include "antrastes_deque.h"
#include "antrastes2.h"

bool compareAlphabet_deque(const student a, const student b)
{
    return a.vardas < b.vardas;
}

bool rikiuojam_pagal_balaD_deque(const student a, const student  b)
{
    return a.galutinis < b.galutinis;
}


double rastimediana_deque (std::deque<int> vekt)
{
    typedef std::vector<int>::size_type vec_sz;
    vec_sz size = vekt.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(vekt.begin(), vekt.end());
    vec_sz mid = size / 2;
    return (double)(size % 2 == 0 ? ((double)(vekt[mid]) + (double)(vekt[mid-1])) / 2 : (double)(vekt[mid]));
}


void skaitymas_is_failo_deque (int egz, char kas, double ndvid, double ndsum, std::deque<student> &studentas)
{
    int nd_kiekis_faile = 0;
    std::ifstream duom ("kursiokai.txt");

        try
        {
            std::string exception = "Skaitymo failas neegzistuoja";
            if(duom) std::cout << "skaitymo failas egzistuoja" << std::endl;
            else throw(exception);
        }
        catch(std::string isimtis)
        {
            std::cout << isimtis << std::endl;
            return;
        }

        if (duom.good())
        {
            std::string str;
            std::getline(duom, str);
            std::istringstream s (str);
            std::string str1;
            while (s >> str1)
            {
                nd_kiekis_faile++;
            }
        }
        nd_kiekis_faile -= 3;
        int i = 0;

        std::deque<int> nd_rez;
        student tmp;
        int nd;
        while(!duom.eof())
        {
            duom >> tmp.vardas >> tmp.pavarde;
            for (int j = 0; j < nd_kiekis_faile; j++)
            {
                duom >> nd;
                nd_rez.push_back(nd);
            }
            duom >> egz;
            if(kas == 'v')
            {
                ndsum = accumulate(nd_rez.begin(), nd_rez.end(), 0);
                ndvid = ndsum / (nd_rez.size());
                tmp.galutinis = 0.4 *ndvid + 0.6 * egz;
            }
            if(kas == 'm')
            {
               tmp.galutinis = 0.4 * rastimediana_deque(nd_rez) + 0.6 * egz;
            }
            nd_rez.clear();
            studentas.push_back(tmp);
        }
    
    std::sort(studentas.begin(), studentas.end() -1, compareAlphabet_deque);
    studentas.pop_back();
    duom.close();
}


void paskirstymas_deque (std::deque<student> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].galutinis < 5) a[i].grupe = "vargsiukai";
        else a[i].grupe = "kietiakai";
    }
}

void paskirstymas1_deque (std::deque<student> &a, std::deque<student> &vargs, std::deque<student> &kiet)
{
    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (i->galutinis < 5) vargs.push_back(*i);
        else kiet.push_back(*i);
    }
    a.clear();
}


void paskirstymas2_deque (std::deque<student> &a, std::deque<student> &kiet)
{
    std::sort(a.begin(), a.end(), rikiuojam_pagal_balaD_deque);
    
    int ne = 0;
        while (a[ne].galutinis < 5.0 && ne != a.size())
            ne ++;

    std::copy(a.begin() + ne, a.end(), std::back_inserter(kiet));

    a.resize(ne);
    a.shrink_to_fit();
}


void F_duomenu_ivedimas_deque (double ndsum, int egz, double ndvid, char kas, std::deque<student> &studentas)
{
        int m;
        std::cout << "Iveskite, kiek is viso yra studentu " << std::endl;
        std::cin >> m;
        while(m <= 0 || !std::cin)
        {
            if(std::cin.fail() || m <=0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"Ivestas netinkamas dydis, iveskite teigiama skaiciu: ";
                std::cin>>m; 
            }
        }
        int kaip;
        std::cout << "Namu darbu resultatai random (1) ar nerandom (2)? " << std::endl;
        std::cin >> kaip;
        ArSkaiciusTinkamas(kaip, 1,2);

        student stud;
        for (int i = 0; i < m; i++)
        {
            std::cout << "Iveskite "<< i + 1 << " studento varda ir pavarde " << std::endl;
            std::cin >> stud.vardas >> stud.pavarde;


            std::deque<int> vektorius;
                int nd;
                int kiek = 0;

            if (kaip == 2)

            {
                std::cout << "Iveskite namu darbu rezultatus (desimtbaleje sistemoje)" << std::endl;

                int tmp = 1;
                for(int j = 0; j < tmp; j++)
                {
                    std::cin >> nd;
                    ArSkaiciusTinkamas(nd, 0, 10);
                    if (nd == 0)
                        tmp = 0;
                        else
                        {
                        vektorius.push_back(nd);
                        }
                        ndsum = accumulate(vektorius.begin(), vektorius.end(), 0);
                        tmp++;
                        kiek++;
                }

                std::cout << "Iveskite " << i+1 << " studento egzamino rezultata (desimtbaleje sistemoje)" << std::endl;
                std::cin >> egz;
                while (std::cin.fail() || egz < 1 || egz > 10)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"Ivestas netinkamas dydis" <<std::endl;
                    std::cout << "Pasirinkite skaiciu is intervalo nuo " << 1 << " iki " << 10 << ": ";
                    std::cin >> egz;
                }
                
            }

            if(kaip == 1)
            {
                Rand_int rnd(1, 10);
                int galas=0; int kiekis;
                ndsum = 0;
                std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiekis;
                ArSkaiciusTinkamas (kiekis, 1, daugiausia);
                std::cout << "Namu darbu balai: " ;
                    do
                    {
                        vektorius.push_back(rnd());
                        std::cout  << vektorius[kiek]<<" " ;
                        /// apskaiciuojama sugeneruoto vektoriaus elementu suma
                        ndsum = accumulate(vektorius.begin(), vektorius.end(), 0);
                        kiekis--;
                        kiek++;
                    } while (galas != kiekis);
                egz = (1 + rand() % 10);
                std::cout << "Egzamino balas: " << egz << std::endl;
            }
            std::cout << std::endl;

            ndvid = ndsum / (kiek - 1);
            if (kas == 'v')
            {
                stud.galutinis = 0.4 * ndvid + 0.6 * egz;
            }
            else stud.galutinis = 0.4 * rastimediana_deque(vektorius) + 0.6 * egz;
            studentas.push_back(stud);
        }
}

void spausdinimas_deque(std::deque<student> a, char b)
{

    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.)" << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe == "vargsiukai")
            rez1 << std::setw(20) << std::left << a[i].pavarde << std::setw(20) 
            << a[i].vardas << std::setw(20) << std::fixed << std::setprecision(2) << a[i].galutinis << std::endl;
    }
    rez1.close();
    
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "(Med.)" << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe == "kietiakai")
            rez2 << std::setw(20) << std::left << a[i].pavarde << std::setw(20) << a[i].vardas 
            << std::setw(20) << std::fixed << std::setprecision(2) << a[i].galutinis << std::endl;
    }
    rez2.close();
}

void spausdinimas_deque(std::deque<student> kiet, std::deque<student> vargs, char b)
{
    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.)" << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;

    for (int i = 0; i < vargs.size(); i++)
    {
        rez1 << std::setw(20) << std::left << vargs[i].pavarde << std::setw(20) << vargs[i].vardas 
        << std::setw(20) << std::fixed << std::setprecision(2) << vargs[i].galutinis << std::endl;
    }
    rez1.close();
        
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "Galutinis (Med.)" << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < kiet.size(); i++)
    {
            rez2 << std::setw(20) << std::left << kiet[i].pavarde << std::setw(20) << kiet[i].vardas 
            << std::setw(20) << std::fixed << std::setprecision(2) << kiet[i].galutinis << std::endl;
    }
    rez2.close();
}


void deque()
{
    double ndvid, ndsum = 0;
    char kas, ar_generuoti, duomenu_ivedimas;
    int koki_faila_generuoti, egz, kiek_nd, strategija;
    std::deque<student> studentas;
    pirmine_apklausa(kas, ar_generuoti, duomenu_ivedimas, koki_faila_generuoti, kiek_nd, strategija);
    
    if(ar_generuoti == 't')
    {
        auto start = std::chrono::high_resolution_clock::now();
        failugeneravimas(koki_faila_generuoti, kiek_nd);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << koki_faila_generuoti << " Irasu failo generavimo laikas: " << diff.count() << std::endl;
    }
    if(ar_generuoti == 't' || duomenu_ivedimas == 'n')
    {
        auto start = std::chrono::high_resolution_clock::now();
        skaitymas_is_failo_deque(egz, kas, ndvid, ndsum, studentas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "failo nuskaitymo laikas: " << diff.count() << std::endl;

        if (strategija == 3)
        {
            start = std::chrono::high_resolution_clock::now();
            paskirstymas_deque(studentas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas_deque(studentas, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
        else if (strategija == 1)
        {
            std::deque<student> vargsiukai, kietiakai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas1_deque(studentas, vargsiukai, kietiakai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas_deque(kietiakai, vargsiukai, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
        else
        {
            std::deque<student> kietuoliai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas2_deque(studentas, kietuoliai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            std::sort(kietuoliai.begin(), kietuoliai.end(), compareAlphabet_deque);
            std::sort(studentas.begin(), studentas.end(), compareAlphabet_deque);
            start = std::chrono::high_resolution_clock::now();
            spausdinimas_deque(kietuoliai, studentas, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
    }


    ///////////////Duomenu ivedimas/////////////////////
    if(duomenu_ivedimas == 'i')
    {
        F_duomenu_ivedimas_deque(ndsum, egz, ndvid, kas, studentas);

        if (strategija == 3)
        {
            paskirstymas_deque (studentas);
            spausdinimas_deque(studentas, kas);
        }
        
        else if(strategija == 1)
        {
            std::deque<student> vargsiukai, kietiakai;
            paskirstymas1_deque(studentas, vargsiukai, kietiakai);
            spausdinimas_deque(kietiakai, vargsiukai, kas);
        }
        else
        {
            std::deque<student> kietiakai;
            paskirstymas2_deque(studentas, kietiakai);
            std::sort(kietiakai.begin(), kietiakai.end(), compareAlphabet_deque);
            std::sort(studentas.begin(), studentas.end(), compareAlphabet_deque);
            spausdinimas_deque(kietiakai, studentas, kas);
        }
        
    }
}
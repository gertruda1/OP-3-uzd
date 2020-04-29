#include "antrastes_vektorius.h"
#include "antrastes2.h"

void ArSkaiciusTinkamas (int& skaicius, int pradzia, int pabaiga)
{
    while (std::cin.fail() || skaicius < pradzia || skaicius > pabaiga)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ivestas netinkamas dydis" <<std::endl;
        std::cout << "Pasirinkite skaiciu is intervalo nuo " << pradzia << " iki " << pabaiga << ": ";
        std::cin >> skaicius;
    }
}

double rastimediana (std::vector<int> vekt)
{
    typedef std::vector<int>::size_type vec_sz;
    vec_sz size = vekt.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(vekt.begin(), vekt.end());
    vec_sz mid = size / 2;
    return (double)(size % 2 == 0 ? ((double)(vekt[mid]) + (double)(vekt[mid-1])) / 2 : (double)(vekt[mid]));
}

bool compareAlphabet(const student1 a, const student1 b)
{
    return a.vardas() < b.vardas();
}

bool rikiuojam_pagal_balaD(const student1 a, const student1  b)
{
    return a.galutinis() < b.galutinis();
}

void failugeneravimas (int a, int b)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << std::setw(20) << std::left << "VARDAS" << std::setw(21) <<  "PAVARDE";
    for (int i = 1; i <= b; i++)
    {
        generavimas << "ND" << std::setw(8) << std::left << i;
    }
    generavimas << "Egz." << std::endl;
    
    for (int i = 1; i <= a; i++)
    {
        generavimas << "Vardas" << std::setw(14) << std::left << i <<  "Pavarde" << std::setw(14) << std::left << i;
        for (int j = 0; j < b + 1; j++) generavimas << std::setw(10) << std::left << rnd();
        generavimas << std::endl;
    }
    generavimas.close();
}


void skaitymas_is_failo (int egz, std::string kas, double ndvid, double ndsum, std::vector<student1> &studentas)
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

        std::vector<int> nd_rez;
        student1 tmp;
        std::string vard, pavard;
        int nd;
        while(!duom.eof())
        {
            duom >> vard >> pavard;
            tmp.setVardas(vard);
            tmp.setPavarde(pavard);
            for (int j = 0; j < nd_kiekis_faile; j++)
            {
                duom >> nd;
                nd_rez.push_back(nd);
            }
            duom >> egz;
            if(kas == "vidurkis")
            {
                ndsum = accumulate(nd_rez.begin(), nd_rez.end(), 0);
                ndvid = ndsum / (nd_rez.size());
                tmp.galBalas(ndvid, egz);
            }
            if(kas == "mediana")
            {
               tmp.galBalas(nd_rez, rastimediana, egz);
            }
            nd_rez.clear();
            studentas.push_back(tmp);
        }
    
    std::sort(studentas.begin(), studentas.end() -1, compareAlphabet);
    studentas.pop_back();
    duom.close();
}

void pirmine_apklausa (std::string &kas, std::string &ar_generuoti, std::string &duomenu_ivedimas, 
int &koki_faila_generuoti, int &kiek_nd, int &strategija)
{
    std::cout << "Vidurkis ar mediana? (vidurkis / mediana)" << std::endl;
    std::cin >> kas;
    while(!std::cin || kas!="vidurkis" && kas!="mediana" )
    {
        std::cout<<"Ivestas netinkamas dydis, pasirinkite vidurkis ar mediana: ";
        std::cin>>kas;

        if(kas=="vidurkis" && kas=="mediana" )
        {
            break;
        }
    }

    std::cout << "Kokia studentu dalijimo i dvi kategorijas strategija? Panaudojant du naujus konteinerius (1), Panaudojant viena nauja konteineri (2), Nenaudojant nauju konteineriu (3)" << std::endl;
    std::cin >> strategija;
    ArSkaiciusTinkamas(strategija, 1, 3);

    std::cout << "Generuoti duomenu failus ar negeneruoti? (generuoti / negeneruoti)" << std::endl;
    std::cin >> ar_generuoti;
    while(!std::cin || ar_generuoti!="negeneruoti" && ar_generuoti!="generuoti" )
    {
        std::cout<<"Ivestas netinkamas dydis, pasirinkite generuoti ar negeneruoti: ";
        std::cin>>ar_generuoti;

        if(ar_generuoti == "generuoti" && ar_generuoti == "negeneruoti" )
        {
            break;
        }
    }

    if(ar_generuoti == "generuoti")
    {
        std::cout << "Kiek studente bus viename faile? (1000 / 10000 / 100000 / 1000000 / 10000000)" << std::endl;
        std::cin >> koki_faila_generuoti;
        while (std::cin.fail() || koki_faila_generuoti != 1000 && koki_faila_generuoti != 10000 &&
        koki_faila_generuoti != 100000 && koki_faila_generuoti != 1000000 && koki_faila_generuoti != 10000000)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Ivestas netinkamas dydis" <<std::endl;
            std::cout << "Pasirinkite viena is skaiciu 1000, 10000, 100000, 1000000, 10000000: ";
            std::cin >> koki_faila_generuoti;
        }

        std::cout << "Kiek bus namu darbu rezultatu? (1 - 50)" << std::endl;
        std::cin >> kiek_nd;
        ArSkaiciusTinkamas(kiek_nd, 1, daugiausia);

    }

    if (ar_generuoti == "negeneruoti")
    {
        std::cout << "Duomenis nuskaityti ar ivesti?  (nuskaityti / ivesti)" << std::endl;
        std::cin >> duomenu_ivedimas;
        while(!std::cin || duomenu_ivedimas!="nuskaityti" && duomenu_ivedimas!="ivesti" )
        {
            std::cout<<"Ivestas netinkamas dydis, pasirinkite nuskaityti ar ivesti: ";
            std::cin>>duomenu_ivedimas;

            if(duomenu_ivedimas == "nuskaityti" && duomenu_ivedimas == "ivesti")
            {
                break;
            }
        }
    }
}



void paskirstymas (std::vector<student1> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].galutinis() < 5) a[i].setGrupe("vargsiukai");
        else a[i].setGrupe("kietiakai");
    }
}

void paskirstymas1 (std::vector<student1> &a, std::vector<student1> &vargs, std::vector<student1> &kiet)
{
    int n = std::count_if (a.begin(), a.end(), [](student1 x) 
    { 
        return x.galutinis() < 5; 
          
    } ); 
    vargs.resize(n);  
    kiet.resize(a.size() - n); 
    partition_copy(a.begin(), a.end(), vargs.begin(),  
                                     kiet.begin(), [](student1 x) 
    { 
        return x.galutinis() < 5; 
    }); 
    a.clear();

    
}

void paskirstymas2 (std::vector<student1> &a, std::vector<student1> &kiet)
{
    std::sort(a.begin(), a.end(), rikiuojam_pagal_balaD);
    
    int n = 0;
        while (a[n].galutinis() < 5.0 && n != a.size())
            n++;

    std::copy(a.begin() + n, a.end(), std::back_inserter(kiet));

    a.resize(n);
    a.shrink_to_fit();
}

void F_duomenu_ivedimas(double ndsum, int egz, double ndvid, std::string kas, std::vector<student1> &studentas)
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
        std::string kaip;
        std::cout << "Namu darbu resultatai random ar ne (Ivesti 'random' / 'nerandom')? " << std::endl;
        std::cin >> kaip;
        while(!std::cin || kaip!="random" && kaip!="nerandom" )
        {
            std::cout<<"Ivestas netinkamas dydis, pasirinkite random ar nerandom: ";
            std::cin>>kaip;

            if(kaip=="random" && kaip=="nerandom" )
            {
                break;
            }
        }

        student1 stud;
        std::string vard, pavard;
        for (int i = 0; i < m; i++)
        {
            std::cout << "Iveskite "<< i + 1 << " studento varda ir pavarde " << std::endl;
            std::cin >> vard >> pavard;
            stud.setVardas(vard);
            stud.setPavarde(pavard);


            std::vector<int> vektorius;
                int nd;
                int kiek = 0;

            if (kaip == "nerandom")

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

            if(kaip == "random")
            {
                Rand_int rnd(1, 10);
                int galas=0; int kiekis;
                ndsum = 0;
                std::cout << "Generuojamu pazymiu kiekis: (1 - 50)"; std::cin >> kiekis;
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
            if (kas == "vidurkis")
            {
                stud.galBalas(ndvid, egz);
            }
            else stud.galBalas(vektorius, rastimediana, egz);
            studentas.push_back(stud);
        }
}

void spausdinimas(std::vector<student1> a, std::string b)
{

    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == "vidurkis") rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.) " << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe() == "vargsiukai")
            rez1 << std::setw(20) << std::left << a[i].pavarde() << std::setw(20) << a[i].vardas()  << std::fixed  <<
            std::setprecision(2) << a[i].galutinis() << std::endl;
    }
    rez1.close();
        
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == "vidurkis") rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "Galutinis (Med.)" << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe() == "kietiakai")
            rez2 << std::setw(20) << std::left << a[i].pavarde() << std::setw(20) << a[i].vardas() << std::fixed <<
             std::setprecision(2) << a[i].galutinis() << std::endl;
    }
    rez2.close();
}
void spausdinimas(std::vector<student1> kiet, std::vector<student1> vargs, std::string b)
{
    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == "vidurkis") rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.)" << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;

    for (int i = 0; i < vargs.size(); i++)
    {
        rez1 << std::setw(20) << std::left << vargs[i].pavarde() << std::setw(20) << vargs[i].vardas() 
        << std::setw(20) << std::fixed << std::setprecision(2) << vargs[i].galutinis() << std::endl;
    }
    rez1.close();
        
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == "vidurkis") rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "Galutinis (Med.)" << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < kiet.size(); i++)
    {
            rez2 << std::setw(20) << std::left << kiet[i].pavarde() << std::setw(20) << kiet[i].vardas() 
            << std::setw(20) << std::fixed << std::setprecision(2) << kiet[i].galutinis() << std::endl;
    }
    rez2.close();
}


void koks_konteineris (char& simbolis, char pirmas, char antras, char trecias)
{
    while (!(simbolis == pirmas || simbolis == antras || simbolis == trecias))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Ivestas netinkamas dydis" <<std::endl;
        std::cout << "Pasirinkite viena is variantu arba " << pirmas << " arba " << antras  << " arba " << trecias << ": ";
        std::cin >> simbolis;
    }
}

void vektorius()
{
    double ndvid, ndsum = 0;
    std::string kas;
    std::string ar_generuoti;
    std::string duomenu_ivedimas;
    int koki_faila_generuoti, egz, kiek_nd, strategija;
    std::vector<student1> studentas;
    pirmine_apklausa(kas, ar_generuoti, duomenu_ivedimas, koki_faila_generuoti, kiek_nd, strategija);
    
    if(ar_generuoti == "generuoti")
    {
        auto start = std::chrono::high_resolution_clock::now();
        failugeneravimas(koki_faila_generuoti, kiek_nd);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "failogeneravimo laikas: " << diff.count() << std::endl;
    }
    if(ar_generuoti == "generuoti" || duomenu_ivedimas == "nuskaityti")
    {
        auto start = std::chrono::high_resolution_clock::now();
        skaitymas_is_failo(egz, kas, ndvid, ndsum, studentas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "failo nuskaitymo laikas: " << diff.count() << std::endl;

        if (strategija == 3)
        {
            start = std::chrono::high_resolution_clock::now();
            paskirstymas(studentas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas(studentas, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
        else if (strategija == 1)
        {
            std::vector<student1> vargsiukai, kietiakai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas1(studentas, vargsiukai, kietiakai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas(kietiakai, vargsiukai, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
        else
        {
            std::vector<student1> kietiakai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas2(studentas, kietiakai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            std::sort(kietiakai.begin(), kietiakai.end(), compareAlphabet);
            std::sort(studentas.begin(), studentas.end(), compareAlphabet);
            start = std::chrono::high_resolution_clock::now();
            spausdinimas(kietiakai, studentas, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
    }


    ///////////////Duomenu ivedimas/////////////////////
    if(duomenu_ivedimas == "ivesti")
    {
        F_duomenu_ivedimas(ndsum, egz, ndvid, kas, studentas);
        if(strategija == 3)
        {
            paskirstymas (studentas);
            spausdinimas(studentas, kas);
        }
        else if (strategija == 1)
        {
            std::vector<student1> vargsiukai, kietiakai;
            paskirstymas1(studentas, vargsiukai, kietiakai);
            spausdinimas(kietiakai, vargsiukai, kas);
        }
        else
        {
            std::vector<student1> kietiakai;
            std::sort(kietiakai.begin(), kietiakai.end(), compareAlphabet);
            std::sort(studentas.begin(), studentas.end(), compareAlphabet);
            paskirstymas2(studentas, kietiakai);
            spausdinimas(kietiakai, studentas, kas);
        }
        
    }
}
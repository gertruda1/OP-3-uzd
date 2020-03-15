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

bool compareAlphabet(student a, student b)
{
    return a.vardas < b.vardas;
}

void failugeneravimas1000 (int a)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << "vardas \t\t\t pavarde \t\t";
    for (int i = 1; i <= a; i++)
    {
        generavimas << "ND" << i << "\t\t";
    }
    generavimas << "Egz." << std::endl;
    for (int i = 1; i <= 1000; i++)
    {
        generavimas << "Vardas" << i << " \t\t Pavarde" << i << " \t\t";
        for (int j = 0; j < a + 1; j++) generavimas << rnd() << "\t\t";
        generavimas << std::endl;
    }
    generavimas.close();
}

void failugeneravimas10000 (int a)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << "vardas \t\t\t pavarde \t\t";
    for (int i = 1; i <= a; i++)
    {
        generavimas << "ND" << i << "\t\t";
    }
    generavimas << "Egz." << std::endl;
    for (int i = 1; i <= 10000; i++)
    {
        generavimas << "Vardas" << i << " \t\t Pavarde" << i << " \t\t";
        for (int j = 0; j < a + 1; j++) generavimas << rnd() << "\t\t";
        generavimas << std::endl;
    }
    generavimas.close();
}
void failugeneravimas100000 (int a)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << "vardas \t\t\t pavarde \t\t";
    for (int i = 1; i <= a; i++)
    {
        generavimas << "ND" << i << "\t\t";
    }
    generavimas << "Egz." << std::endl;
    for (int i = 1; i <= 100000; i++)
    {
        generavimas << "Vardas" << i << " \t\t Pavarde" << i << " \t\t";
        for (int j = 0; j < a + 1; j++) generavimas << rnd() << "\t\t";
        generavimas << std::endl;
    }
    generavimas.close();
}

void failugeneravimas1000000 (int a)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << "vardas \t\t\t pavarde \t\t";
    for (int i = 1; i <= a; i++)
    {
        generavimas << "ND" << i << "\t\t";
    }
    generavimas << "Egz." << std::endl;
    for (int i = 1; i <= 1000000; i++)
    {
        generavimas << "Vardas" << i << " \t\t Pavarde" << i << " \t\t";
        for (int j = 0; j < a + 1; j++) generavimas << rnd() << "\t\t";
        generavimas << std::endl;
    }
    generavimas.close();
}

void failugeneravimas10000000 (int a)
{
    Rand_int rnd(1, 10);
    std::ofstream generavimas ("kursiokai.txt");
    generavimas << "vardas \t\t\t pavarde \t\t";
    for (int i = 1; i <= a; i++)
    {
        generavimas << "ND" << i << "\t\t";
    }
    generavimas << "Egz." << std::endl;
    for (int i = 1; i <= 10000000; i++)
    {
        generavimas << "Vardas" << i << " \t\t Pavarde" << i << " \t\t";
        for (int j = 0; j < a + 1; j++) generavimas << rnd() << "\t\t";
        generavimas << std::endl;
    }
    generavimas.close();
}

void skaitymas_is_failo (int egz, std::string kas, double ndvid, double ndsum, std::vector<student> &studentas)
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
            if(kas == "vidurkis")
            {
                ndsum = accumulate(nd_rez.begin(), nd_rez.end(), 0);
                ndvid = ndsum / (nd_rez.size());
                tmp.galutinis = 0.4 *ndvid + 0.6 * egz;
            }
            if(kas == "mediana")
            {
               tmp.galutinis = 0.4 * rastimediana(nd_rez) + 0.6 * egz;
            }
            nd_rez.clear();
            studentas.push_back(tmp);
        }
    
    std::sort(studentas.begin(), studentas.end() -1, compareAlphabet);
    studentas.pop_back();
    duom.close();
}

void pirmine_apklausa (std::string &kas, std::string &ar_generuoti, std::string &duomenu_ivedimas, int &koki_faila_generuoti, int &kiek_nd)
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

void failugeneravimas (int a, int b)
{
    if (a == 1000) failugeneravimas1000(b);
    if (a == 10000) failugeneravimas10000(b);
    if (a == 100000) failugeneravimas100000(b);
    if (a == 1000000) failugeneravimas1000000(b);
    if (a == 10000000) failugeneravimas10000000(b);
}

void paskirstymas (std::vector<student> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].galutinis < 5) a[i].grupe = "vargsiukai";
        else a[i].grupe = "kietiakai";
    }
}

void F_duomenu_ivedimas(double ndsum, int egz, double ndvid, std::string kas, std::vector<student> &studentas)
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

        student stud;
        for (int i = 0; i < m; i++)
        {
            std::cout << "Iveskite "<< i + 1 << " studento varda ir pavarde " << std::endl;
            std::cin >> stud.vardas >> stud.pavarde;


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
                stud.galutinis = 0.4 * ndvid + 0.6 * egz;
            }
            else stud.galutinis = 0.4 * rastimediana(vektorius) + 0.6 * egz;
            studentas.push_back(stud);
        }
}

void spausdinimas(std::vector<student> a, std::string b)
{

    std::ofstream rez1 ("vargsiukai.txt");
    if (b == "vidurkis") rez1 << "Pavarde \t Vardas \t\t Galutinis (Vid.)" << std::endl;
    else rez1 << "Pavarde \t Vardas \t\t Galutinis (Med.) " << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe == "vargsiukai")
            rez1 << a[i].pavarde << " \t " << a[i].vardas << " \t\t " << std::fixed << std::setprecision(2) <<
            a[i].galutinis << std::endl;
    }
    rez1.close();
    
    std::ofstream rez2 ("kietiakai.txt");
    if (b == "vidurkis") rez2 << "Pavarde \t Vardas \t\t Galutinis (Vid.)" << std::endl;
    else rez2 << "Pavarde \t Vardas \t\t Galutinis (Med.) " << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].grupe == "kietiakai")
            rez2 << a[i].pavarde << " \t " << a[i].vardas << " \t\t " << std::fixed << std::setprecision(2) <<
            a[i].galutinis << std::endl;
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
    int koki_faila_generuoti, egz, kiek_nd;
    std::vector<student> studentas;
    pirmine_apklausa(kas, ar_generuoti, duomenu_ivedimas, koki_faila_generuoti, kiek_nd);
    
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


    ///////////////Duomenu ivedimas/////////////////////
    if(duomenu_ivedimas == "ivesti")
    {
        F_duomenu_ivedimas(ndsum, egz, ndvid, kas, studentas);
        paskirstymas (studentas);
        spausdinimas(studentas, kas);
    }
}
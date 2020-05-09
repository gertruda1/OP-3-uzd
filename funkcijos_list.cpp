#include "antrastes_list.h"
#include "antrastes2.h"


bool compareAlphabet_list(const student a, const student b)
{
    return a.vardas < b.vardas;
}


double rasti_mediana_list (std::list <int> listas)
{    
    double m;
    listas.sort();                     
    int n = listas.size();
    auto it1 = listas.begin();         
    auto it2 = it1;
    std::advance(it1, n / 2 - 1);  
    std::advance(it2, n / 2);       

    n % 2 == 0 ? (m = 1.00 * (*it1 + *it2) / 2) : m = *it2; // Calculate median
    return m;
}

double vidurkis_list (std::list<int> listas, int n) 
{
    double sum = 0;
    auto it = listas.begin();
    for (auto it = listas.begin(); it != listas.end(); it ++)
        sum += *(it);
    return (sum / n);
}



void skaitymas_is_failo_listas (std::list<student> &studentas, char kas)
{
    int nd_kiekis_faile = 0; 
    std::ifstream duom ("kursiokai.txt");

    try
    {
        std::string Exception = "SKAITYMO FAILAS NEEGZISTUOJA";
        if (duom) std::cout << "skaitymo failas egzistuoja " << std::endl;
        else if(!duom) throw (Exception);
    }

    catch (std::string isimtis)
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
        while (s >> str1)  nd_kiekis_faile++;
    }

    nd_kiekis_faile -= 3;
    student tmp;
    std::list<int> nd_rez;
    int nd;
    while(duom >> tmp.vardas)
    {
        duom >> tmp.pavarde;           
        for (int j = 0; j < nd_kiekis_faile; j++)
        {
            if (duom.fail())
            {
                duom.clear(); duom.ignore();
            }
            duom >> nd; nd_rez.push_back(nd);
        }
    int egz;
    duom >> egz;
    double ndvid;
    if(kas == 'v')
    {
        ndvid = vidurkis_list (nd_rez, nd_rez.size());
        tmp.galutinis = 0.4 * ndvid + 0.6 * egz;
    }
    if(kas == 'm')
    {
        tmp.galutinis = 0.4 * rasti_mediana_list(nd_rez) + 0.6 * egz;
    }
    nd_rez.clear();
    studentas.push_back(tmp);
    }
    studentas.sort(compareAlphabet_list);
    duom.close();
}

void paskirstymas_listas (std::list<student> &a)
{
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        if (itr->galutinis < 5.0) itr->grupe = "vargsiukai";
        else itr->grupe = "kietiakai";
    }
}

void paskirstymas1_listas (std::list<student> &a, std::list<student> &vargs, std::list<student> &kiet)
{
    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (i->galutinis < 5.0)
        {
            vargs.push_back(*i);
        } 
        else kiet.push_back(*i);
    }
    a.clear();
}

void paskirstymas2_listas (std::list<student> &a, std::list<student> &vargs)
{
    for (auto i = a.begin(); i != a.end(); i++) 
    {
        if (i->galutinis < 5)
        {
            vargs.push_back(*i);
        }
    }


     auto itr = a.begin(); 
 while (  itr != a.end() )
 {
    if (itr->galutinis < 5)
    {
        a.erase(itr++);
    }

    else
    {
        ++itr;
    }
  }
}


void F_duomenu_ivedimas_listas(char kas, std::list<student> &studentas)
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
        std::cout << "Namu darbu resultatai random(1) ar nerandom (2)? " << std::endl;
        std::cin >> kaip;
        ArSkaiciusTinkamas(kaip, 1,2);

        student stud;
        int egz;
        for (int i = 0; i < m; i++)
        {
            std::cout << "Iveskite "<< i + 1 << " studento varda ir pavarde " << std::endl;
            std::cin >> stud.vardas >> stud.pavarde;


            std::list<int> listas;
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
                        listas.push_back(nd);
                        }
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
                double ndvid = vidurkis_list(listas, listas.size());
            }

            if(kaip == 1)
            {
                Rand_int rnd(1, 10);
                int galas=0; int kiekis;
                std::cout << "Generuojamu pazymiu kiekis: "; std::cin >> kiekis;
                ArSkaiciusTinkamas (kiekis, 1, daugiausia);
                std::cout << "Namu darbu balai: " ;
                    do
                    {
                        int z = rnd();
                        listas.push_back(z);
                        std::cout << z <<" " ;
                        kiekis--;
                        kiek++;
                    } while (galas != kiekis);
                egz = rnd();
                std::cout << "Egzamino balas: " << egz << std::endl;
            }
            std::cout << std::endl;

            double ndvid = vidurkis_list(listas, listas.size());

            if (kas == 'v')
            {
                stud.galutinis = 0.4 * ndvid + 0.6 * egz;
            }
            else stud.galutinis = 0.4 * rasti_mediana_list(listas) + 0.6 * egz;
            studentas.push_back(stud);
        }
        studentas.sort(compareAlphabet_list);
}

void spausdinimas_listas(std::list<student> a, char b)
{

    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.) " << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        if (itr->grupe == "vargsiukai")
            rez1 << std::setw(20) << std::left << itr->pavarde << std::setw(20) << itr->vardas 
            << std::setw(20) << std::fixed << std::setprecision(2) << itr->galutinis << std::endl;
    }
    rez1.close();
    
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "Galutinis (Med.) " << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        if (itr->grupe == "kietiakai")
            rez2 << std::setw(20) << std::left << itr->pavarde << std::setw(20) << itr->vardas 
            << std::setw(20) << std::fixed << std::setprecision(2) << itr->galutinis << std::endl;
    }
    rez2.close();
}

void spausdinimas_listas (std::list<student> kiet, std::list<student> vargs, char b)
{
    std::ofstream rez1 ("vargsiukai.txt");
    rez1 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20);
    if (b == 'v') rez1 << "Galutinis (Vid.)" << std::endl;
    else rez1 << "Galutinis (Med.)" << std::endl;
    rez1 << "-----------------------------------------------------------" << std::endl;
    for (auto itr = vargs.begin(); itr != vargs.end(); itr++)
    {
        rez1 << std::setw(20) << std::left << itr->pavarde << std::setw(20) << itr->vardas 
        << std::setw(20) << std::fixed << std::setprecision(2) << itr->galutinis << std::endl;
    }
    rez1.close();
    
    std::ofstream rez2 ("kietiakai.txt");
    rez2 << std::setw(20) << std::left << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20); 
    if (b == 'v') rez2 << "Galutinis (Vid.)" << std::endl;
    else rez2 << "Galutinis (Med.)" << std::endl;
    rez2 << "-----------------------------------------------------------" << std::endl;
    for (auto itr = kiet.begin(); itr != kiet.end(); itr++)
    {
        rez2 << std::setw(20) << std::left << itr->pavarde << std::setw(20) << itr->vardas 
        << std::setw(20) << std::fixed << std::setprecision(2) <<
        itr->galutinis << std::endl;
    }
    rez2.close();
}

void listas()
{
    char kas, ar_generuoti, duomenu_ivedimas;
    int koki_faila_generuoti, kiek_nd, strategija;
    std::list<student> studentas;
    pirmine_apklausa(kas, ar_generuoti, duomenu_ivedimas, koki_faila_generuoti, kiek_nd, strategija);
    
    if(ar_generuoti == 't')
    {
        auto start = std::chrono::high_resolution_clock::now();
        failugeneravimas(koki_faila_generuoti, kiek_nd);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "failo generavimo laikas: " << diff.count() << std::endl;
    }
    if (ar_generuoti == 't' || duomenu_ivedimas == 'n')
    {
        auto start = std::chrono::high_resolution_clock::now();
        skaitymas_is_failo_listas(studentas, kas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        std::cout << "failo nuskaitymo laikas: " << diff.count() << std::endl;

        if (strategija == 3)
        {
            start = std::chrono::high_resolution_clock::now();
            paskirstymas_listas(studentas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas_listas(studentas, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }

        else if (strategija == 1)
        {
            std::list<student> vargsiukai, kietiakai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas1_listas(studentas, vargsiukai, kietiakai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas_listas(kietiakai, vargsiukai, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }

        else
        {
            std::list<student> vargsiukai;
            start = std::chrono::high_resolution_clock::now();
            paskirstymas2_listas(studentas, vargsiukai);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "dalijimo i dvi grupes laikas: " << diff.count() << std::endl;

            start = std::chrono::high_resolution_clock::now();
            spausdinimas_listas(studentas, vargsiukai, kas);
            end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            std::cout << "spausdinimo laikas: " << diff.count() << std::endl;
        }
    }

    ///////////////Duomenu ivedimas/////////////////////
    if(duomenu_ivedimas == 'i')
    {
        F_duomenu_ivedimas_listas(kas, studentas);
        if (strategija == 3)
        {
            paskirstymas_listas (studentas);
            spausdinimas_listas(studentas, kas);
        }
        else if (strategija == 1)
        {
            std::list<student> vargsiukai, kietiakai;
            paskirstymas1_listas(studentas, vargsiukai, kietiakai);
            spausdinimas_listas(kietiakai, vargsiukai, kas);
        }
        else
        {
            std::list<student> vargsiukai;
            paskirstymas2_listas(studentas, vargsiukai);
            spausdinimas_listas(studentas, vargsiukai, kas);
        }
    }
}
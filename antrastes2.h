#ifndef ANTRASTES2_H_INCLUDED
#define ANTRASTES2_H_INCLUDED

class student1
{
    private:
        std::string vardas_, pavarde_;
        double galutinis_;
        std::string grupe_;
    public:
        student1() : vardas_("Vardenis"), pavarde_("Pavardenis"), galutinis_(10.0), grupe_("kietiakai") { 
            std::cout << "klase sukurta" <<std::endl;}
        std::string vardas() const { return vardas_; std::cout << "labas" << std::endl; } // get'eriai
        std::string pavarde() const { return pavarde_; } // get'eriai
        double galutinis() const { return galutinis_; } // get'eriai
        std::string grupe() const { return grupe_; } // get'eriai
        void galBalas(double ndvid, int egz) { galutinis_ = 0.4 *ndvid + 0.6 * egz; } // set'eriai
        void galBalas(std::vector<int> nd_rez, double (*f)(std::vector<int>), int egz) {
            galutinis_ = 0.4 * (*f)(nd_rez) + 0.6 * egz; } // set'eriai
        void setVardas (std::string vard) { vardas_ = vard; } // set'eriai
        void setPavarde (std::string pavard) { pavarde_ = pavard; } // set'eriai
        void setGrupe (std::string a) { grupe_ = a; } // set'eriai
        ~student1() {};
};

struct student
{
    std::string vardas, pavarde;
    double galutinis;
    std::string grupe;
};

class Rand_int
{
    public:
        Rand_int(int low, int high): mt{rd()}, dist{low, high} {}
        int operator()() {return dist(mt);}
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};

#endif // ANTRASTES2_H_INCLUDED
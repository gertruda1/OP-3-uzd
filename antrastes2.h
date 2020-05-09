#ifndef ANTRASTES2_H_INCLUDED
#define ANTRASTES2_H_INCLUDED

class zmogus
{  
    protected:
        std::string vardas_, pavarde_;
        inline zmogus(): vardas_("Vardenis"), pavarde_("Pavardenis") {}
};

class student1 : protected zmogus
{
    private:
        double galutinis_;
        std::string grupe_;
    public:
        inline student1() : zmogus{}, galutinis_(10.0), grupe_("kietiakai") {}
        student1(const student1& a)
        {
            galutinis_ = a.galutinis_;
            grupe_ = a.grupe_;
            vardas_ = a.vardas_;
            pavarde_ = a.pavarde_;
        }
        student1& operator = (const student1 &a){ 
            if(&a == this) return *this;
            vardas_ = a.vardas_;
            pavarde_ = a.pavarde_;
            galutinis_ = a.galutinis_;
            return *this;
             }

        virtual inline std::string vardas() const { return vardas_;} // get'eriai
        virtual inline std::string pavarde() const { return pavarde_; } // get'eriai
        virtual void setVardas (std::string vard) { vardas_ = vard; } // set'eriai
        virtual void setPavarde (std::string pavard) { pavarde_ = pavard; } // set'eriai

        inline double galutinis() const { return galutinis_; } // get'eriai
        inline std::string grupe() const { return grupe_; } // get'eriai
        void galBalas(double ndvid, int egz) { galutinis_ = 0.4 *ndvid + 0.6 * egz; } // set'eriai
        void galBalas(std::vector<int> nd_rez, double (*f)(std::vector<int>), int egz) {
            galutinis_ = 0.4 * (*f)(nd_rez) + 0.6 * egz; } // set'eriai
        void setGrupe (std::string a) { grupe_ = a; } // set'eriai

        inline friend bool operator==(const student1& a, const student1& b) { return a.vardas_ == b.vardas_ && a.pavarde_ == b.pavarde_ &&
		a.galutinis_ == b.galutinis_ && a.grupe_ == b.grupe_; }
        inline friend bool operator!=(const student1& a, const student1& b) { return !(a == b); }
        inline friend bool operator>(const student1& a, const student1& b) { return a.galutinis_ > b.galutinis_; }
        inline friend bool operator<(const student1& a, const student1& b) { return a.galutinis_ < b.galutinis_; }
        inline friend bool operator>=(const student1& a, const student1& b) { return a.galutinis_ >= b.galutinis_; }
        inline friend bool operator<=(const student1& a, const student1& b) { return a.galutinis_ <= b.galutinis_; }

        inline ~student1() {};
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
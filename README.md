# Objektinio-programavimo-2-uzduotis

Programa, nuskaitanti duomenis apie studentus ir apskaičiuojanti jų mokslo rezultatus

## Įdiegimo instrukcija

Norint paleisti programą, reikia:
1) Atsisiųsti bet kurį iš programos kodų ([releases](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases)).
2) Įsidiegti g++ kompiliatorių ([GCC](https://gcc.gnu.org/)).
3) Naudojant komandinę eilutę paleisti programą naudojant Makefile
    * make
    * test

## Programos naudojimas ir veikimas

Vartotojo veiksmų seka:

1) Vartotojas pasirenka, kuriame konteineryje bus saugomi duomenys (vector, list, deque).
2) Vartotojas pasirenka, pagal ką bus skaučiuojams studneto galutinis balas (pagal namų darbų vidurkį ar medianą).
3) Vartotojas pasirenka, pagal kokią strategiją bus studentai skirstomi į 2 grupes (panaudojant 1 - 1 strategija -, 2  - 2 strategija - ar 0 - 3 strategija -, naujų konteinerių).
4) Vartotojas pasirenka, ar generuoti naują failą su studentų duomenimis, ar ne.

Jei taip:

  5) Vartotojas pasirenka, kelių studentų duomenys tame faile bus (1000, 10000, 100000, 1000000, 10000000).
  6) Toliau vartotojas pasirenka, kiek vienas studentas turės namų darbų rezultatų (nuo 1 iki 50).
  7) Pasirinkdamas, kad failus programa sugeneruotų pati, vartotojas automatiškai sutinka, kad visi šie duomenys toliau bus nuskaityti ir  iš jų bus išvestas rezultatas.

Jei ne:

  5) Vartotojas pasirenka, ar duomenis nori pats įvesti, ar kad programa nuskaitytų nuo jau esančio failo.

  Jei programa nuskaito failą, tai ji išveda rezultatus. Jei pasirenkama įvesti rankiniu būdų visus studentų duomenis, toliau eina tokia vartotojo veiksmų seka:

  6) Vartotojas įveda, kiek iš viso bus studentų.
  7) Vartotojas pasirenka, ar namų darbų bei egzamino rezultatus nori suvesti pats, ar kad programa tuos rezultatus sugeneruotų random.

 Jei random:

 8) Vartotojas suveda kiekvieno studento vardą ir pavardę.
 9) Vartotojas pasirenka, kiek bus generuojama namų darbų rezultatų (nuo 1 iki 50).
 10) Vartotojas gauna rezultatus

 Jei pažymiai bus ne random:

 8) Vartotojas suveda kiekvieno studento vardą.
 9) Vartotojas suveda kiekvieno studento namų darbų pažymius (Jei jis jau suvedė visus pažymius, turi įvesti 0)
 10) Vartotojas įveda studento egzamino balą
 11) Vartotojas gauna rezultatą.


 Po visos šios veiksmų sekos atspausdinami 2 .txt failai pagal galutinio balo rezultatą. Jei galutinis balas < 5, studento duomenys (vardas, pavardė) ir rezultatai išvedami į ("vargsiukai.txt") failą, o jei rezultatai >= 5, tai studento duomenys bei rezultatai išvedami į ("kietuoliai.txt") failą.

 Galutinio rezultato formulės:

    Galutinis rezultatas = (namų darbų vidurkis) * 0.4 + (egzamino balas) * 0.6;
    Galutinis rezultatas = (namų darbų mediana) * 0.4 + (egzamino balas) * 0.6;

## Programos veikimo spartos analizė (v0.5 versija)

Įrangos parametrai:

| CPU  | RAM | SSD |
| ----- | ------|------ |
| Intel Core i5 8th Gen 1,6 GHz | 8GB  | 256 GB |

Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 3.

 | Duomenų kiekis | Duomenų failo generavimas | Duomenų failo skaitymas | Studentų rūšiavimas | Duomenų spausdinimas |
 |----------------|---------------------------|-------------------------|---------------------|----------------------|
 | 1000 | 0.040117 | 0.019702 | 0 | 0.010025 |
 | 10000 | 0.049145 | 0.229971 | 0 | 0.060223 |
 | 100000 | 0.390096 | 2.88993 | 0.020137 | 0.589707 |
 | 1000000 | 3.80589 | 37.9099 | 0.135065 | 6.92016 |
 | 10000000 | 42.7737 | 534.582 | 1.17489 | 64.5651 |

 Išmatuotas laikas pateikiamas sekundėmis. Kiekviename faile yra sugeneruoti 2 namų darbų rezultatai.

Laikai naudojant STL konteinerį vector:

![image](https://user-images.githubusercontent.com/57493215/76709642-10a77d00-6709-11ea-93a8-4e2add77194e.png)


Laikai naudojant STL konteinerį list:

![image](https://user-images.githubusercontent.com/57493215/76709661-35035980-6709-11ea-85a5-6a2abb6861ff.png)


Laikai naudojant STL konteinerį deque:

![image](https://user-images.githubusercontent.com/57493215/76709672-48162980-6709-11ea-8ba6-2be6c1b95f90.png)


## Programos veikimo spartos analizė (v1.0)

**1 Strategija**

Konteinerio skirstymas į du naujus to paties tipo konteinerius: "kietiakai" ir "vargsiukai".

**2 Strategija**

Konteinerio skirstymas panaudojant tik vieną naują konteinerį: "kietiakai". Tokiu būdu, jei studento galutinis balas yra >=5.0, jo duomenys bus įkelti į naująjį "kietiakų" konteinerį ir ištrinti iš bendro "studentas" konteinerio.

**3 Strategija**

Konteinerio skirstymas nenaudojant jokių naujų konteinerių. Struktūra "student" turi string tipo kintamąjį "grupe". Skirstant studentus į dvi grupes, kintamojo "grupe" reikšmė yra prilyginama arba "vargsiukai", arba "kietiakai".


Išmatuotas laikas pateikiamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.
Duomenų rūšiavimo laikų ir naudojamų STL konteinerių palyginimas:

| Studentų duomenų kiekis | std::vector pirmoji strategija | std::vector 2-oji strategija| std::vector 3-oji strategija | std::list 1-oji strategija | std::list 2-oji strategija | std::list 3-oji strategija | std::deque 1-oji strategija | std::deque 2-oji strategija | std::deque 3 strategija |
 |----------------|---------------------------|-------------------------|---------------------|----------------------|-------------|---------------|---------------|-------------|----------------|
 | 1000 | 0.034085 | 0.004352 | 0.001042 | 0.002702 | 0.001141 | 0.001053 | 0.03109 | 0.002372 | 0.001054 |
 | 10000 | 0.334191 | 0.031132 | 0.004649 | 0.020042 | 0.009305 | 0.006008 | 0.374688 | 0.015991 | 0.007048 |
 | 100000 | 3.27643 | 0.226233 | 0.029783 | 0.150196 | 0.080037 | 0.042508 | 3.45871 | 0.112762 | 0.058947 |
 | 1000000 | 14.7801 | 0.840429 | 0.107936 | 0.515022 | 0.263296 | 0.148627 | 14.7349 | 0.382019 | 0.197004 |
 | 10000000 | 20.639035 | 2.15946 | 0.195848 | 5.25209 | 2.74862 | 1.53284 | 176.301 | 3.87196 | 1.94484 |

**Išvados**

Pati greičiausia ir efektyviausia strategija naudojant STL konteinerius (std::vector, std::list, std::deque) yra trečioji - nepanaudojant nei vieno naujo konteinerio, o įrašant informaciją apie grupę į pačią studento struktūrą. Std::list konteineris iš naudojamų konteinerių laiko prasme išsiskiria kaip efektyviausias.

Duomenų rūšiavimo laikų naudojant/nenaudojant papildomų algoritmų ir naudojant std::vector konteinerį palyginimas:

 | Studentų duomenų kiekis | std::vector 1-oji strategija be papildomų algoritmų | std::vector 1-oji strategija su papildomais algoritmais | std::vector 2-oji strategija be papildomų algoritmų | std::vector 2-oji strategija su papildomais algoritmais | std::vector 3-oji strategija be papildomų algoritmų | std::vector 3-oji strategija su papildomais algoritmais |
 |-----------------|------------------|---------------------|--------------|----------|---------------|--------------|
 | 1000 | 0.034085 | 0.007934 | 0.004352 | 0.000999 | 0.001042 | 0 |
 | 10000 | 0.334191 | 0.092788 | 0.031132 | 0.006964 | 0.004649 | 0.001036 |
 | 100000 | 3.27643 | 1.15254 | 0.226233 | 0.06283 | 0.029783 | 0.010969 |
 | 1000000 | 14.7801 | 14.3593 | 0.840429 | 0.686164 | 0.107936 | 0.125697 |
 | 10000000 | 27.639035 | 27.493502 | 2.15946 | 2.0389038 | 0.195848 | 0.1423084 |

 **Išvados**

 Naudojami algoritmai:
  * std::copy
  * std::partition

 Jų panaudojimas spartina studentų rūšiavimą į dvi grupes pagal galutinį balą.

 ## Releases

 [**v0.1**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v.0.1)

 [**v0.2**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v0.2)

 [**v0.3**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v0.3)

 [**v0.4**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v0.4)

 [**v0.5**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v0.5)

 [**v1.0**](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis/releases/tag/v1.0)

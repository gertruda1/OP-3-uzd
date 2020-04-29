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

# Ankstesnė užduotis

[Objektinio-programavimo-2-uzduotis](https://github.com/gertruda1/Objektinio-programavimo-2-uzduotis)

 
# Programos veikimo spartos analizė

laikas yra matuojamas sekundėmis. Namų darbų kiekis sugeneruotuose failuose - 5.

**Programos laikų palyginimas pagal naudojamą duomenų tipą**

 | Studentų įrašų kiekis | Struct | Class |
 | ---------------------- | ------- | ------ |
 | 100000 | 4.593612 | 4.025496 | 
 | 1000000 | 52.90607 | 45.069293 | 
 | 10000000 | 609.13654 | 539.845385 |

**Programos laikų palyginimas naudojant class pagal kompiliavimo flag'us**

 | Studentų įrašų kiekis | Class be flag'ų | -O1 | -O2 | -O3 |
 | ---------------------- | ------- | ------ | ---- | ------ |
 | 100000 | 4.025496 | 2.168157 | 2.082117 | 2.079964 |
 | 1000000 | 45.069293 | 21.572886 | 22.29229 | 21.178044 |
 | 10000000 | 539.845385 | 240.395703 | 234.346243 | 215.633292 |

 ## Releases

 [**v1.1**](https://github.com/gertruda1/OP-3-uzd/releases/tag/v1.1)
 
 Šioje programos versijoje buvo sukurta nauja klasė "student1", kuri panaudojama vietoj struktūros "student", kai programoje yra naudojami vektoriai. Klasėje yra naudojamas konstruktorius, destruktorius, set'eriai ir get'eriai.

[**v1.2**](https://github.com/gertruda1/OP-3-uzd/releases/tag/v1.2)

Šioje programos versijoje realizuoti Rule of three ir nauji operatoriai klasėje "student1".

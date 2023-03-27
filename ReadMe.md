**Algoritmų ir duomenų struktūros 2-as lab. darbas.** 

Programa sprendžia daiktų suskirstymo į 2 grupes uždavinį (`Partition problem`).

**Užduotis**
Duota N daiktų, kurių svoriai s1, s2, ... sN. Programa turi suskirstyti daiktus į 2 grupes taip, kad grupių svoriai būtų, kiek įmanoma, vienodesni. Vartotojas nurodo failą, iš kurio programa įveda daiktų svorius.

**Kaip sukompiliuoti programa?**
Tam, kad sukompiliuotum projektą reikia paleisti `Go.bat` failą ir tada programos rezultatas atsiras `partitionTest.txt` faile.

**Failai**
`test.c`    -- pagrindinis programos failas.

`MakeFile`  -- transliavimo make failas.

`Go.bat`    -- komandų failas main sutransliavimui ir įvykdymui.

`input.txt` -- failas su testavimo duomenimis.
Testavimui į `input.txt` įrašyti skaičių rinkinį tokiu formatu:
Pvz.: 4 5 6 7 8

`partitionTest.txt` -- failas, kuriame išsaugomas programos rezultatas. 

`functions.c`-- failas su funkcijomis

`function.h`-- header failas

**Kiti, testavimui skirti, skaičių rinkiniai:**
2 10 3 8 5 7 9 5 3 2 |
771 121 281 854 885 734 486 1003 83 62 |
484 114 205 288 506 503 201 127 410 |
19 17 13 9 6

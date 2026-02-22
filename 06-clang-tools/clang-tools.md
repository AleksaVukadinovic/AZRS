**Clang** sa propatnim alatima je jedan od najbitnijih delova LLVM projekta. Clang je kompajler za jezike kao sto su C, C++, Objective C... Da budemo preciznije clang je frontend koji kao ulaz uzima kod napisan u prethodno navedenim jezicima i prevodi ga u medjureprezentaciju (tj. LLVM IR) i to predstavlja kao ulaz u sredisnji deo na kojem se vrse optimizacije nezavisne od jezika i arhitekture. Na kraju backend vrsi optimizacije vezane za konkretnu arhitekturu i prevodi kod na masinski jezik.

U odnosu na gcc, implementira je u C++ koriscnjem modernijih tehnologija. Bolje predstavlja informacije u slucaju greske ili upozorenja, uglavnom daje vise upozorenja u odnosu na gcc. 

Koristi se isto kao i gcc:
```bash
clang [options] input.c # za C
clang++ [options] input.cpp # za C++
```

**ClangTidy** je deo Clang/LLVM projekta koji nam automatski refaktorise C++ kod. Ova grupa alata se naziva **linteri**. Linteri su alati koji proveravaju i pronalaze stilske i programske greske. Potreba za ovakvim alatom nastaje usled standarda C++11 koji je dodao mnogo novih funkcionalnosti (auto, override, lambda, ...), kako se mnogi kodovi nisu prilagodili novim standardima (a i dosta programera ih ne koristi), ideja je da `clang-tidy` donekle olaksa resavanje ovog problema tj. refaktorisanje koda tako da koristi novije funkcionalnosti.

Možemo da primenimo clang-tidy i da vidimo potencijalna mesta za refaktorisanje. Ako želimo da alat primeni direktno popravke na kod možemo da napravimo new.cpp i da dodamo opciju --fix. Postoji lista provera koje možemo da uključimo preko opcije --checks=[PATTERN1],[PATTERN2],...,[PATTERNK]. Ako želimo da uključimo sve opcije, onda koristimo --checks=*. Želimo da modernizujemo kod pa koristimo --checks=modernize-*. Izlaz preusmeravamo u log.txt:
* cp old.cpp new.cpp
* clang-tidy new.cpp --checks="modernize-*" --fix -- --std=c++17 > log.txt

**ClangFormat** je alat zaduzen za formatiranje koda. On nam nudi vise razlicitih stilova formatiranja. Za postavljanje stila koristimo `--style = [STYLE]` (npr STYLE moze biti LLVM, Google, Chromium, Mozilla, WebKit, Microsoft, GNU, ...)


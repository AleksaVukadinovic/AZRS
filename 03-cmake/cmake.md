CMake (Cross-Platform Make)
`CMake` je generator build sistema. On ne kompajlira direktno, već generiše `Makefile` ili projektne fajlove za druge alate.

### Osnovni Workflow
1. **Konfiguracija**: `cmake -S . -B build` (analiza sistema i pronalaženje kompajlera).
2. **Izgradnja**: `cmake --build build` (ili pozivanje `make` unutar build direktorijuma).

### Ključne Komande u CMakeLists.txt
* `cmake_minimum_required(VERSION x.x)`: Osigurava kompatibilnost sa verzijom alata.
* `project(Ime VERSION 1.0)`: Definiše metapodatke projekta i generiše promenljive poput `PROJECT_NAME`.
* `add_executable(ime_izvrsnog fajlovi.cpp)`: Definiše binarni fajl koji se dobija kompilacijom.
* `add_library(ime TIP fajlovi.cpp)`: Kreira biblioteku (TIP može biti `STATIC` ili `SHARED`).
* `target_link_libraries(cilj PRIVACY biblioteka)`: Povezuje izvršni fajl sa bibliotekom.
* `add_subdirectory(direktorijum)`: Omogućava modularnost projekta pozivanjem CMakeLists.txt fajlova iz poddirektorijuma.

### Upravljanje Bibliotekama i Vidljivost
CMake koristi sistem propagacije svojstava kroz ključne reči:
* **STATIC**: Kod se kopira u izvršni fajl (veći binarni fajl, lakša distribucija).
* **SHARED**: Kod se referencira u vreme izvršavanja (manji binarni fajlovi, zahteva prisustvo .so/.dll fajla).
* **PRIVATE**: Zavisnosti/zaglavlja koristi samo ta biblioteka.
* **INTERFACE**: Zavisnosti/zaglavlja koriste samo oni koji linkuju tu biblioteku.
* **PUBLIC**: Zavisnosti/zaglavlja koriste i biblioteka i njeni korisnici.

### Testiranje i Analiza (CTest & Coverage)
Build sistem se koristi i za automatizaciju provere kvaliteta.
* **CTest**: Omogućava se sa `enable_testing()`. Testovi se definišu putem `add_test(NAME ime COMMAND izvrsni)`.
* **Code Coverage (Pokrivenost)**: Metrika koja meri procenat izvršenih linija ili grana koda tokom testova.
  * Zahteva specifične zastavice kompajlera (npr. `--coverage` za GCC).
  * Alati poput `LCOV` generišu vizuelne izveštaje iz podataka dobijenih izvršavanjem testova.


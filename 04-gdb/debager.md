Debager

**Bug** je greska ili propust u programu ili sistemu zbog koje taj program ili sistem daju pogresan rezultat, neocekivan rezultat, losije performanse ili u najgorem slucaju dovodi do pada sistema ili gubitka podataka. **Debagovanje** je proces pronalazenja i otklanjanj bagova u programu ili sistemu.

Tehnike debagovanja:
- Posmatranje i analiza koda
- Menjanje koda i ponovno pokretanje
- Dodavanje privremenog koda koji sluzi samo za debagovanje
- …

**Debager** je program (alat) koji se koristi za debagovanje drugog programa. Alati za debagovanje obicno nude i neke funkcionalnost koje ne moraju u potpunosti da budu vezane za samo debagovanje. Neki poznati debageri su:
- **GDB (the GNU Project Debugger)**
- **LLDB (LLVM Debugger)**
- Microsoft Visual Studio Debugger
- **Valgrind**

Debageri su vrlo mocni alati, ali to ne znaci da treba uvek da ih koristimo. Ako pretpostavimo da je greska jednostavna, onda mozemo da probamo da popravimo tako sto koristimo neku prethodnu navedenu tehniku. Ako se ispostavi da greska nije trivijalna, onda mozemo da ukljucimo nek debager. Jedan od najcescih uzroka teskih bagova je rastoj`nje od izvora greske do mesta gde bag ispoljava. U ovakvim situacijama je veoma bitno primeniti prave metode debagovanja, kao i prave alate.

**GDB (the GNU Project debugger)** je debager koji ima podršku za sledeće jezike: Ada, Assembly, C, C++, D, Fortran, Go, Objective-C, OpenCL, Modula-2, Pascal, Rust. GDB je dominantan na Unix sistemima, ali se u praksi za neke druge os koriste drugi debageri zbog bolje podrske.

Ako zelimo da koristimo `gdb` na izvrsnoj datoteci, potrebno je da prilikom kompilacije dodamo `-g` flag kojim naglasavamo kompajleru da sacuva tabelu simbola. Bitno je napomenuti da `-g` flagom odbacujemo neke kompajlerske optimizacije, zato cesto imamo `release` i `debug` verziju programa.
  
- `g++ -g <naziv_executable> <naziv_programa>` - komapjlirajne sa -g flagom
- `gdb ./<naziv_exe>` - otvara gdb interfejs 
- `run [args]` , `r [args]`- pokrece program, opciono sa argumentima komandne linije
- `quit`, `q`, `Ctrl + D` - prekida debagovanje i program
- `break [args]` , `b [args]`- postvlja breakpoint (tacka gde program pauzira izvrsavanje). Ima vise nacina da se koristi break:
  - `break func_name` - zaustavlja se na odredjenoj funkciji
  - `break line_num` - zaustavlja se na odredjenoj liniji
  - `break +offset`, `break -offset` - relativna lokacija
- `next`, `n` - izvrsava trenutnu liniju i prelazi na sledecu
- `list`, `l` - prikazuje deo koda oko linije na kojoj se trenutno nalazimo
- `print [expression]`, `p` - ispisuje sadrzaj neke promenljive
- `display [expression]` - umesto da stalno pisemo `next` pa `print promenljiva` mozemo samo da kazemo `display promenljiva` tj. svaki put kad se zaustavimo na nekoj liniji ispisace vrednost te promenljive
- `step` - izvrsaca sledecu liniju koda i ako postoji poziv funkcije ulazi u nju (za razliku od `next` koji preskace funkcije)
- `backtrace`, `where` - prikazuje ceo call stack sve do trenutne tacke
- `down` - ide jedan okvir nanize u call stacku
- `up` - ide jedan okvir navise u call stacku
- `kill` - prekida izvrsavanje progama u debageru
- `continue` - nastavlja izvrsavanje do sledeceg preakpointa
- `finish` - izvrsava trenutnu funkciju da kraja i vraca se u pozivacjucu
- `watch [var_name]` - breakpoint kada se promeni vrednost promenljive
- `info [args]` - prikazuje info o necemu zavisnosti od argumenata
  - `info breakpoints`
  - `info locals`
  - `info args`
  - `info registers`
- `whatis [var]` - vraca tip promenljive
- `delete [breakpoint/watchpoint]` 
- `disable [breakpoint/watchpoint]` 
- `enable [breakpoint/watchpoint]`
- `clear` - brise sve breakpointove



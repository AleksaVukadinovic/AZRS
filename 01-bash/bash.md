BASH

**BASH (Bourne-Again Shell)** je mocna i veoma korisna komadna linija i skriptni jezik koji se cesto koristi na Unix sistemima. Sluzi kao interfejs za komunikaciju coveka i racunara putem tekstualnih komadni. Jako je fleksibilan i efikasan tkd je idealan za pisanje skripti.

Sve bash komande prate istu strukturu. **Opcije (flagovi)** pocinju sa \-\- ili -, ako nas zanima vise o nekoj komandi kazemo samo komanda \-\- help ili `man komanda` za prikaz doukemtnacije:
```bash
command --options [arguments]
```

Komande:
- `*` - pronalai nula ili vise znakova (*.yaml nalazi sve yaml fajlove)
- `?` - nalazi tacno jedan znak (file?.txt nalazi file1.txt, file2.txt, …)
- `cat` - ispsiuje sadrzaj datoteke (`cat *.yaml` ili `cat test.txt`)
- `echo` - ispis (`echo “Hello world!`)
- `$$` - PID trenutnog procesa (`echo "PID trenutnog procesa: $$"`)
- `$!` - PID Poslednjeg pozadinskog procesa
- `$?` - Status izlaza poslednjeg procesa
- `$_` - Poslednji argumenti komandne linije
- `!!` - Prethodna komanda
- `cd` - Promena direktorijuma
- `.` - trenutni direktorijum
- `..` - prethodni direktorijum
- `ls` - lista datoteka i direktorijuma
- `pwd` - trenutni direktorijum (puna putanja)
- `touch` - kreiranje prazne datoteke
- `mkdir` - kreiranje direktorijuma
- `rm` - brisanje datoteke
- `rmdir` - brisanje direktorjuma
- `mv` - kopiranje (i preimenovanje) datoteka i direktorijuma
- `cp` - kopiranje datoteka/direktorijuma
- `grep` - pretraga teksta pomocu regexa, obavezno koristiti `-E` flag (`grep -E "regex_pattern" datoteka`)
- `sed` - uredjivanje teksta (`sed -E 's/regex_pattern/zamena/' datoteka`)
- `awk` - procesiranje teksta u tabelarnom formatu
- **Redirekcija** (`>`, `>>`, `<`) omogućava usmeravanje ulazno/izlaznih tokova podataka između komandi i datoteka.
- **Cevi** (`|`) omogućavaju da se izlaz jedne komande koristi kao ulaz za drugu, čime se stvara niz komandi za složeniju obradu podataka.
- `=` - za definisanje promenljivih (`ime="John" prezime = “Doe”`)
- `unset` - brise promenljive (`unset prezime`)
- `export` - deklarisanje globalne promenljive (`export GLOBALNA_PROMENLJIVA="Vrednost"`)
- `$HOME` - putanja do maticnog direkotrijuma korisnika
- `$USER` - korisnicko ime
- `$GROUP` - korisnicka grupa
- `$PATH` - putanja izvrsnih fajlova
- `$PWD` - trenutni radni dirktorijum
- `$SHELL` - putanja do trenutnog shell-a
- `$RANDOM` - nasumican broj
- `$HOSTNAME` - ime racunara
- `read` - citanje unosa (`read ime_korisnika`)
- `source` - skripta se izvrsava u treutnom procesu umesto u novom (koristi se kod venv)
- `wget` - preuzima fajl sa interneta
- `zip` - zippuje fajl
- `unzip` - unzippuje fajl
- `exit`, `break`, `continue` - ono sto se i ocekuje

Dodavanjem `set -e` na pocetak skripte, osiguravamo se da ce se nas program zavrsiti kada dodje do greske.
### IF-THEN-ELSE
```bash
if [uslov]; then
	komanda1
	komanda2
	...
else
	komanda67
fi
```
### PETLJE
```bash
for var in lista; do
	komanda1
	komanda2
done

while [uslov]; do
	komanda
done
```
### Matematika i uslovi u bash-u 
* `-eq` - Jednako (za brojeve)
* `-ne` - Različito (za brojeve)
* `-lt` - Manje od (za brojeve)
* `-le` - Manje ili jednako (za brojeve)
* `-gt` - Veće od (za brojeve)
* `-ge` - Veće ili jednako (za brojeve)
* `=` - Jednako (za stringove)
* `!=` - Različito (za stringove)

### Primeri
```bash
if [ $broj -gt 10 ]; then
    echo "Broj je veći od 10."
fi

if [ "$string1" = "$string2" ]; then
    echo "Stringovi su jednaki."
fi

# Za matematiku koristimo ((izraz))
rezultat=$((broj1 + broj2))
echo "Rezultat je: $rezultat"

if test -e "fajl.txt"; then
    echo "Fajl postoji."
fi

# Definisanje funkcije sa parametrima
function pozdrav {
    echo "Dobrodošli, $1!"
}

# Poziv funkcije sa argumentom
pozdrav "Korisnik"
```



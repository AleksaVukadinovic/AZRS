Docker je open-source projekat koji nam omogucava **isporuku (delivery)** aplikacija unutar **kontejnera (container)** tako sto nam daje dodatni nivo apstrakcije i automatizacije preko **OS-level virtualization** za Linux.

Ideja je da zapakujemo kod i sve zavisnosti u jednu standardizovanu jedinicu koja se naziva **kontejner (container)**. To nam omogucava da brzo i pouzdano instaliramo aplikaciju na vise okruzenja.

**Docker slika kontejnera (container image)** je samostalan paket softvera koji sadrzi:
- kod
- okruzenje
- sistemske alate
- biblioteke
- opcije

Slike kontejnera postaju kontejneri tokom izvrsavanja. U slucaju **Docker slika**, slike postaju kontejneri i kada se pokrenu preko **Docker engine**-a.

Slike definisemo preko **Dockerfile** datoteke koja se sastoji iz niza instrukcija. Opsti flow ide `Dockerfile` -> `Docker Image` -> `Docker Container`.

Virtuelne mašine i kontejneri daju slične benefite i sličnu izolaciju, ali funkcionišu drugačije:
- **Virtuelni masine**:
  - Apstrakcija na fizickom nivou. Vise servera umesto jednog servera na istoj masini
  - **Hipervizor (hypervisor)** omogucava da se vise VM pokrece na jednoj masini.
  - Svaka VM ima svoju kopiju operativnog sistema, aplikacija, datoteka (sve nezavisno). Zbog toga zauzimaju vise memorije - mere se u GB.
  - Sporo se pokrecu
- **Kontejneri**:
  - Apstrakcija na aplikacionom sloju koja spaja kod i zavisnosti u jedno
  - Vise kontejnera mogu da budu na jednom operativnom sistemu i da dele isto jezgro (kernel)
  - Obicno su znatno manji od virtuelnih masina - mere se u MB
  - Brzo se pokrecu

Virtuelne masine su bolje resenje kada aplikacije zahtevaju svre resurse i funkcionalnosti operativnog sistema ili kada nam je potrebno da imamo vise razlicitih operativnih sistema na raspolaganju. Kontejneri su bolje resenje kada zelimo da maksimizujemo broj pokrenutih aplikacija na minimalnom broju servera.

Docker ima mnogo prednosti:
- Pojednostavljeno konfigurisanje
- Izvoz razvojnog koda u produkcioni
- **Multi-tenant** aplikacije: Vise klijenata koristi istu aplikaciju. Kao da je aplikacija proizvod koji se prodaje vise puta.
- Prouktivnost na strani developera.
- **Konsolidacija servera**: jeftinije je imati vise kontejner servera nego vm servera.
- Docker nudi alate za debagovanje
- Brz izvoz (pokretanje traje par milisekundi)

Osnovne komande:
```dockerfile
FROM gcc:latest

COPY . /usr/src/hello-world

WORKDIR /usr/src/hello-world

RUN g++ -o hello-world main.cpp

CMD ["./hello-world"]
```

Za sve Docker komande postoje man strane:
* `FROM gcc:latest` - Dohvati već postojeću sliku za gcc kao osnovni sloj 
* `COPY . /usr/src/hello-world` - Kopiraj trenutni direktorijum . u Docker sliku na putanji /usr/src/hello-world.
* `WORKDIR /usr/src/hello-world` - Postavi putanju /usr/src/hello-world kao putanju za radni direktorijum.
* `RUN g++ -o hello-world main.cpp` - Izvrši komandu (u ovom slučaju kompiliraj c++ kod).
* `CMD ["./hello-world"]` - Podrazumevana opcija (komanda) za kontejner. Ovo npr. može da bude pokretanje servera.

Kad smo napisali Dockerfile treba da ga buildujemo komandom `docker build [PATH]`, opcijom `-t` dodajemo ime image-u. Npr. `docker build -t hello-world`. Zatim je potrebno pokrenuti ga sa `docker run —name helloworld hello-world:latest`

- `docker image ls` - izlistava sve docker image-a
- `docker ps` - izlistava sve aktivne kontejnere
- `docker ps -a` - izlistava sve kontejnere

Ako pokusamo da pokrenemo neki image koji nemamo lokalno, ali postoji na internet, onda se implicitno poziva komanda `docker-pull` koja ga instalira.

Ako zelimo da obrisemo neki image, koristimo komandu `docker image rm [naziv]` ili skraceno `docker rmi`, potencijalno treba dodati opciju `-f` za forisiranje brisanja ako neki kontejner korisit ovaj image.
- `docker rmi hello-world:latest`
- `docker rmi robotmurlock/helloworld:1.0 -f`

Nakon brisanja, ako je nasa slika backupovana na Docker Hub-u mozemo da je dohvatimo sa `docker pull`.



Git

**Github** je platforma za hostovanje koda koji koristi **git** kao sistem za kontrolu verzija. **Sistem za verzionisanje (VCS - Version Control System)** je sistem koji je zaduzen za cuvanje i kontrolisanje programskih kodova, dokumenata itd. Pored githuba postoje i Gitlab, AWS CodeCommit, Bitbucket, …

Situacije u kojima je sistem za kontrolu verzija koristan:
* Ako smo napravili promene u kodu i onda nakon nekog vremena smo shvatili da je ta promena greška;
* Ako izgubimo lokalne podatke, onda možemo preuzeti podatke poslednje verzije;
* Ako želimo da uporedimo kod sad i pre;
* Ako želimo da dokažemo da je određena promena izazvala greške;
* Ako želimo da analiziramo istoriju koda;
* Ako želimo da delimo kod sa drugim ljudima;
* Ako želimo da dodamo novu "eksperimentalnu" funkcionalnost, ali da ne menjamo trenutni kod.

Postoje dve filozofije kod sistema za kontrolu verzija **DVCS (Distributed Version Control System)**: Distribuirani sistem za kontrolu verzija, predstavnik je **git**. Pored ovih koji su danas najzatuljeniji postoje i **CVCS (Centralized Version Control System)**: Centralizovani sistem za kontrolu verzija. Primer: **SVN**.
- Centralizovani sistem za kontrolu verzija podrazumeva arhitekturu server i klijenta. Repozitorijum se nalazi na centralnom serveru i postoji samo jedan repozitorijum. Kada želimo da postavimo novu verziju koda ili da dohvatimo novu verziju koda moramo da komunicira sa centralnim serverom (neophodan je mrežni pristup). Često se pristup repozitorijumu omogućava preko VPN (Virtual Private Network)-a.
- Distribuirani sistem nije toliko drugačiji od centralizovanog sistema. Razlika je u tome što što pored "centralnog servera" (ne mora da samo jedan), svaki developer ima lokalni repozitorijum (kao lokalni server). Verzije koda mogu da se ažuriraju na lokalnom repozitorijumu (nije neophodan mrežni pristup), a kasnije da se te izmene postave na glavni repozitorijum (neophodan mrežni pristup).

Git cuva tri verzije direktorijuma (promene se beleze unutar `.git/index` fajla):
- **Working directory** - to je ono gde mi radimo
- **Staging directory** - promene koje se prate ali nisu jos commitovane
- **Repository** - komitovane promene

Komande
- `git init` - pravi git repo na lokali
- `git clone` - preuzima git repo sa remote-a
- `git add [fajlovi]` - dodaje fajlove za pracenje
- `git commit` - komituje fajlove
- `git status` - stanje 3 verzije direktorijuma (kaze nam sta je commitovano, sta nije i sl.)
- `git reset <hash>` - vraca stanje projekta na prthodni commit, sve promene nakon toga idu u working direcotry
- `git log` - istorija komitova
- `git log --pretty=oneline` - lepsi ispis
- `git log —graph` - sranje prikaz grafa
- Definisanje aliasa: `git config --global alias.hist "log --pretty=format:'%h %ad | %s%d [%an]' --graph --date=short"`, sada je `git hist` komanda
- `git checkout` - checkoutuje granu
- `git checkout HEAD` - checkoutuje poslednju promenu
- `git checkout HEAD~n` - checkoutuje n promena pre poslednje
- `git tag naziv_tag` - postavlja tag na trenutni commit
- `git revert` - pravi suprtoan commit datom hashu
- `git reflog` - detaljan istorija 
- `git commit --amend -m "Dodat je README.md"` - menja poruku poslednjeg commita (moze da promeni i sam commit)
- `git branch` - izlistava lokalne grane
- `git branch -a` - ispisuje i lokalne i remote grane
- `git branch -r` - ispisuje samo remote grane
- `git branch ime_grane` - pravi granu (bez checkouta)
- `git checkout -b ime_grane` - pravi granu (sa checkoutom)
- `git branch -d ime_grane` - brise granu (samo ako je spojena)
- `git branch -D ime_grane` - brise granu
- `git merge grana2` - u trenutnu granu spaja granu2
- `git config` - razlicita podesavanja 
- `git rebase grana2` - pozicionira rep nase grane na head grane2
- `git rebase -i HEAD~n` - pokrece interaktivni rebase
  - `pick` -> `squash` (sluzi da se spoljsti vise commitova u jedan)
- `git cherry-pick [commits]` - bira niz comitova i kopira ih na trenutnu granu
- `git fetch` - updatuje lokalno stanje informacijama sa remote-a
- `git push` - gura promene na remote

U `.gitignore` stavljamo fajlove i foldere koje zelimo da git ignorise. Treba pisati dobre commitove itd. 
**Gitflow** je model koji kaze, imamo main granu, imamo development granu, pored toga imamo feature, bugfix, release, hotfix grane… (nebitno)



**Callgrind** je alat za profajliranje koji cuva istoriju poziva funkcija u programu kao graf poziva. Informacije koje nam pruza za dati program su:
- broj izvrsenih instrukcija
- odnosi izvrsenih instrukcija sa odgovarajucim linijama koda
- `caller/callee` odnos izmedju funkcija sa frekvencijama
- informacije o kesiranju (promasaji, pogodjaji, ...)
- . . .

Ideja profajlera je da identifikuju koji delovi koda (npr. funkcije) najvise uticu na performanse programa (vreme, memorija, ...). Ako se 60% izvrsavanja programa svede na jednu funkciju, onda je to dobro mesto za optimizaciju.

**KCachegrind** je pomocni alat za vizuelizaciju podataka dobijenih iz callgrind analize.

**Valgrind** je framework za alate za dinamicku analizu programa. Koristi se kao pomoc u otklanjanju bagova sa memorijom i nitima. Dakle, Valgrind je profajler i debager, jer predstavlja alat za debagovanje i koristi se pretezno za C/C++.

Nad kompajliranim fajlom, pokrecemo sa komandom:

```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=log.txt \
         ./a.out
```

Ovo ce da generise fajl `log.txt` koji ce da sadrzi informacije o curenjima memorije.

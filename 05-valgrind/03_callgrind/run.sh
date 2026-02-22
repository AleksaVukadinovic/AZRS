gcc -g -o main.out main.c
valgrind --tool=callgrind --callgrind-out-file=callgrind.out ./main.out
kcachegrind callgrind.out

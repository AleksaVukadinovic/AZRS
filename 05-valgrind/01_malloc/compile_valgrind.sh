#!/bin/bash

set -e

gcc $1
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=log.txt \
         ./a.out
cat log.txt

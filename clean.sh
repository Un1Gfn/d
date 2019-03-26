#!/bin/bash 

find ./ -type f -a \( -name '*.out' -o -name '*.o' -o -name '*.gch' -o -name 'vgcore.?????' \) -exec rm -v {} \;

rm -rf html/
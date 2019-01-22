#!/bin/bash 

find ./ -type f -a \( -name '*.out' -o -name '*.o' -o -name '*.gch' \) -exec rm -v {} \;
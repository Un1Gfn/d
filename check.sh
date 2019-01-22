#!/bin/bash
g++ -fsyntax-only -fdiagnostics-color=always -std=c++11 -Wall $@ |& less -SR -M +%
#!/bin/bash
g++ -fdiagnostics-color=always -std=c++11 -Wall $@ |& less -SR -M +%

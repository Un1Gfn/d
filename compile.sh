#!/bin/bash

OUT=$( g++ \
	-g \
	-fsyntax-only \
	-fdiagnostics-color=always \
	-std=c++11 \
	-Wall $@ \
	2>&1 )

if [ -n "$OUT" ];then
  less <<<"$OUT" -R -M +%
	exit 1
fi

# ccache g++ -fsyntax-only -fdiagnostics-color=always -std=c++11 -Wall $@ |& less -R -M +%
g++ -g -fdiagnostics-color=always -std=c++11 -Wall $@
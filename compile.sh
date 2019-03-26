#!/bin/bash

OUT=$( g++ \
	-g \
	-fsyntax-only \
	-fdiagnostics-color=always \
	-std=c++11 \
	-Wall $@ \
	2>&1 )

PASS="$?"

if [ -n "$OUT" ];then
  less <<<"$OUT" -R -M +%
	if [ "$PASS" -ne 0 ];then
		echo "x"
		exit 1
	fi
fi

# ccache g++ -fsyntax-only -fdiagnostics-color=always -std=c++11 -Wall $@ |& less -R -M +%
g++ -g -fdiagnostics-color=always -std=c++11 -Wall $@
ls a.out
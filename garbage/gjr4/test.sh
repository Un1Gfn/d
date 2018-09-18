#!/bin/bash
# use xdotool to test
# "apt install xdotool" (ubuntu 16.04)
# which xdotool
# if [ "$?" -ne 0 ];then
# 	echo 'please "apt install xdotool" before using this test.'
# 	exit 1
# fi
# echo "Please be ready (mouse focus on the running a.out) before key press is simulated"
sleep 3
xdotool $1 --delay 100ms
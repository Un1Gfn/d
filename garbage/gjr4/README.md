# Experiment 4 - contiguous and linked list

## Important
* This program is vulnerable to illegal input. Please don not give it anything weird.
* The `make test0` requires xdotool package, please `sudo apt install xdotool`. It's actually a simple yet powerful "按键精灵" for linux, and is extremely interesting. Have fun ...
* Whether "linked" or "contiguous" is decided by macros. the `-D <macro-name>` in **Makefile** controls it.

Command|Operation
-|-
q|quit
p|print list
i|insert
r|remove

## Contiguous

###### Normal

```
$ make clean ; make contiguous ; make test0 ; make clean 
rm -f ./*.out
g++ -std=c++11 -Wall -D CONTIGUOUS main.cpp -o a.out
nohup ./test.sh ./normal.xdo.txt >/dev/null 2>/dev/null </dev/null &
./a.out
Input command: i
Insert before position:0
What to insert:C
Done
Input command: p
C 
Input command: 
Input command: i
Insert before position:1
What to insert:R
Done
Input command: p
C R 
Input command: 
Input command: i
Insert before position:1
What to insert:T
Done
Input command: p
C T R 
Input command: 
Input command: i
Insert before position:1
What to insert:U
Done
Input command: p
C U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:P
Done
Input command: p
C P U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:M
Done
Input command: p
C M P U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:O
Done
Input command: p
C O M P U T R 
Input command: 
Input command: i
Insert before position:6
What to insert:E
Done
Input command: p
C O M P U T E R 
Input command: 
Input command: r
Position:0
'' is removed
Input command: p
O M P U T E R 
Input command: 
Input command: r
Position:4
'' is removed
Input command: p
O M P U E R 
Input command: 
Input command: r
Position:2
'' is removed
Input command: p
O M U E R 
Input command: 
Input command: r
Position:3
'' is removed
Input command: p
O M U R 
Input command: q
rm -f ./*.out
darren@darren-HP-Pavilion-Notebook:~/Desktop/Link to algorithm/algorithm_experiment4$ 

```

###### Invalid

```
$ make clean ; make contiguous ; make test1 ; make clean 
rm -f ./*.out
g++ -std=c++11 -Wall -D CONTIGUOUS main.cpp -o a.out
nohup ./test.sh ./invalid.xdo.txt >/dev/null 2>/dev/null </dev/null &
./a.out
Input command: i
Insert before position:-1
What to insert:C
Fail
Input command: p
empty
Input command: i
Insert before position:1
What to insert:C
Fail
Input command: p
empty
Input command: i
Insert before position:0
What to insert:C
Done
Input command: p
C 
Input command: r
Position:1
Fail
Input command: p
C 
Input command: r
Position:-1
Fail
Input command: p
C 
Input command: r
Position:0
'' is removed
Input command: p
empty
Input command: q
rm -f ./*.out
darren@darren-HP-Pavilion-Notebook:~/Desktop/Link to algorithm/algorithm_experiment4$ 

```

## Linked

###### Normal

```
$ make clean ; make linked ; make test0 ; make clean
rm -f ./*.out
g++ -std=c++11 -Wall -D LINKED main.cpp -o a.out
nohup ./test.sh ./normal.xdo.txt >/dev/null 2>/dev/null </dev/null &
./a.out
Input command: i
Insert before position:0
What to insert:C
Done
Input command: p
C 
Input command: 
Input command: i
Insert before position:1
What to insert:R
Done
Input command: p
C R 
Input command: 
Input command: i
Insert before position:1
What to insert:T
Done
Input command: p
C T R 
Input command: 
Input command: i
Insert before position:1
What to insert:U
Done
Input command: p
C U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:P
Done
Input command: p
C P U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:M
Done
Input command: p
C M P U T R 
Input command: 
Input command: i
Insert before position:1
What to insert:O
Done
Input command: p
C O M P U T R 
Input command: 
Input command: i
Insert before position:6
What to insert:E
Done
Input command: p
C O M P U T E R 
Input command: 
Input command: r
Position:0
'C' is removed
Input command: p
O M P U T E R 
Input command: 
Input command: r
Position:4
'T' is removed
Input command: p
O M P U E R 
Input command: 
Input command: r
Position:2
'P' is removed
Input command: p
O M U E R 
Input command: 
Input command: r
Position:3
'E' is removed
Input command: p
O M U R 
Input command: q
rm -f ./*.out

```

###### Invalid

```
$ make clean ; make linked ; make test1 ; make clean
rm -f ./*.out
g++ -std=c++11 -Wall -D LINKED main.cpp -o a.out
nohup ./test.sh ./invalid.xdo.txt >/dev/null 2>/dev/null </dev/null &
./a.out
Input command: i
Insert before position:-1
What to insert:C
Fail
Input command: p
empty
Input command: i
Insert before position:1
What to insert:C
Fail
Input command: p
empty
Input command: i
Insert before position:0
What to insert:C
Done
Input command: p
C 
Input command: r
Position:1
Fail
Input command: p
C 
Input command: r
Position:-1
Fail
Input command: p
C 
Input command: r
Position:0
'C' is removed
Input command: p
empty
Input command: q
rm -f ./*.out

```
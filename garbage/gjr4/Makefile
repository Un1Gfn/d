# Makefile



default:
	@echo "Please make a choice."

contiguous:
	g++ -std=c++11 -Wall -D CONTIGUOUS main.cpp -o a.out

linked:
	g++ -std=c++11 -Wall -D LINKED main.cpp -o a.out

clean:
	rm -f ./*.out

test0:
	nohup ./test.sh ./normal.xdo.txt >/dev/null 2>/dev/null </dev/null &
	./a.out

test1:
	nohup ./test.sh ./invalid.xdo.txt >/dev/null 2>/dev/null </dev/null &
	./a.out
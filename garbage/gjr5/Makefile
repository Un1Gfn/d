default: a.out

a.out: main.cpp
	g++ -std=c++11 -Wall -g ./main.cpp -o ./a.out

test: a.out
	echo `shuf -i 2-8` | ./a.out

static_test: a.out
	echo "3 6 5 8 4 2 7" | ./a.out

run: a.out
	./a.out

clean:
	rm -f *.svg *.out

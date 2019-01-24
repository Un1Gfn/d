#include <iostream>
#include <random>
#define LINKED
// #define DEBUG
#include "Sortable_list.h"

int main(){
	uniform_int_distribution<int> u(0,12345);
	default_random_engine e(time(0));

	// Sortable_list<int> l;
	// Sortable_list<int> l{11};
	// Sortable_list<int> l{11,22};
	// Sortable_list<int> l{22,11};
	// Sortable_list<int> l{11,22,33};
	// Sortable_list<int> l{22,11,33};
	// Sortable_list<int> l{33,11,22};
	// Sortable_list<int> l{11,33,22};
	// Sortable_list<int> l{22,33,11};
	// Sortable_list<int> l{33,22,11};

	for(int len=0;len<=100;++len){
		Sortable_list<int> l;
		for(int i=1;i<=len;++i){
			const int x=u(e);
			l.insert(l.size(),x);
		}
		l.print();
		l.insertion_sort();
		l.print();
	}

	return 0;
}
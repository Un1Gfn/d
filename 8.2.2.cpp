#include <iostream>
#include <random>
#define CONTIGUOUS
#define DEBUG
#include "Sortable_list.h"

int main(){
	uniform_int_distribution<int> u(0,100);
	default_random_engine e(time(0));

	// initializer_list<int> il={
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e),
	// 	u(e)
	// };
	// Sortable_list<int> l(il);

	Sortable_list<int> l;
	for(int i=0;i!=17;++i){
		const int x=u(e);
		l.insert(l.size(),x);
	}

	l.print();
	l.insertion_sort();
	l.print();
	
	return 0;
}
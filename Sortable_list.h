#pragma once

#include "List.h"

template <class Record>
class Sortable_list:public List<Record>{
public:
	// Sortable_list(std::initializer_list<Record> il):List(il);
	using List<Record>::List;
	void insertion_sort();
	void selection_sort();
// private:
};

template <class Record>
void Sortable_list<Record>::insertion_sort(){
	if(this->count<=1)
		return;
	cout << this->count<<endl;
	for(int first_unsorted=1;first_unsorted!=this->count;++first_unsorted){
		Record current=this->entry[first_unsorted];
		int position=first_unsorted;
		while( position>=1 && this->entry[position-1]>current ){
			this->entry[position]=this->entry[position-1];
			--position;
		}
		this->entry[position]=current;
	}
}

// template < class Record >
// void Sortable_list<Record>::insertion_sort()
// {
// 	int first_unsorted;
// 	int position;
// 	Record current;
// 	for (first_unsorted = 1; first_unsorted < count; first_unsorted ++ )
// 		if (this->entry[first_unsorted] < this->entry[first_unsorted - 1]) {
// 			position = first_unsorted;
// 			current = this->entry[first_unsorted];
// 			do {
// 				this->entry[position] = this->entry[position - 1];
// 				position --;
// 			} while (position > 0 && this->entry[position - 1] > current);
// 			this->entry[position] = current;
// 	}
// }

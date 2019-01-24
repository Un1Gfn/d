#pragma once
#include "List.h"
#define forward(A) A=A->next

template <class Record>
class Sortable_list:public List<Record>{
public:
	// Sortable_list(std::initializer_list<Record> il):List(il);
	using List<Record>::List;
	using List<Record>::print;
	void insertion_sort();
	void selection_sort();
private:
	using List<Record>::count;
#ifdef CONTIGUOUS
	using List<Record>::entry;
#endif
#ifdef LINKED
	using List<Record>::head;
#endif
};

template <class Record>
void Sortable_list<Record>::insertion_sort(){
#ifdef CONTIGUOUS
	// Page 322
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
	if(count<=1)
		return;
	cout << count<<endl;
	for(int first_unsorted=1;first_unsorted!=count;++first_unsorted){
		Record current=entry[first_unsorted];
		int position=first_unsorted;
		while( position>=1 && entry[position-1]>current ){
			entry[position]=entry[position-1];
			--position;
		}
		entry[position]=current;
	}
#endif

#ifdef LINKED
	if(count<=1)
		return;
	Node<Record> *last_sorted=head;
	Node<Record> *first_unsorted=head->next;
	do{
		if(first_unsorted->entry < head->entry){ 
			last_sorted->next=first_unsorted->next;
			first_unsorted->next=head;
			head=first_unsorted;
			first_unsorted=last_sorted->next;
		}else{
			Node<Record> *trailing=head, *current=trailing->next;
			// Travse sorted part
			while(current!=first_unsorted && current->entry < first_unsorted->entry){
				current=current->next;
				trailing=trailing->next;
			}
			if(current==first_unsorted){
				last_sorted = first_unsorted;
				first_unsorted = first_unsorted->next;
			}else{
				last_sorted->next = first_unsorted->next;
				trailing->next = first_unsorted;
				first_unsorted->next = current;
				first_unsorted=last_sorted->next;
			}
		}
	}while(first_unsorted!=nullptr); // Traverse unsorted part

#endif
}
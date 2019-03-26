#pragma once
#include "List.h"

#ifdef STATISTICS
unsigned long long compares=0;
unsigned long long moves=0;
#define COMPARE ++compares
#define MOVE ++moves
#define INIT compares=0;moves=0
#define SUM cout<<compares<<" "<<moves<<endl;
#else
#define COMPARE 0 // Satisfy comma operator
#define MOVE
#define INIT
#define SUM
#endif

template <class Record>
class Sortable_list:public List<Record>{
public:
	// Sortable_list(std::initializer_list<Record> il):List(il);
	using List<Record>::List;
	using List<Record>::print;
	void insertion_sort();
private:
	using List<Record>::count;

#ifdef CONTIGUOUS
public:
	void selection_sort();
private:
	int max_key(int,int);
	void swap(int,int);
	using List<Record>::entry;
#endif

#ifdef LINKED
public:
	void merge_sort();
private:
	using List<Record>::head;
#endif

};

#ifdef CONTIGUOUS
template <class Record>
void Sortable_list<Record>::insertion_sort(){
	INIT;
	if(count<=1)
		return;
	for(int first_unsorted=1;first_unsorted!=count;++first_unsorted){
		if( COMPARE,entry[first_unsorted-1]>entry[first_unsorted] ){
			Record current=entry[first_unsorted];
			MOVE;
			entry[first_unsorted]=entry[first_unsorted-1]; // First shift
			MOVE;
			int position=first_unsorted-1;
			while( position>=1 && (COMPARE,entry[position-1]>current) ){
				entry[position]=entry[position-1]; // 2nd+ shift
				MOVE;
				--position;
			}
			entry[position]=current;
			MOVE;
		}
	}
}
#endif

#ifdef LINKED
template <class Record>
void Sortable_list<Record>::insertion_sort(){
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
}
#endif

#ifdef CONTIGUOUS
template <class Record>
void Sortable_list<Record>::selection_sort(){
	INIT;
	for(int position=count-1;position>0;--position){
		int max=max_key(0,position);
		swap(max,position);
	}
}
template <class Record>
int Sortable_list<Record>::max_key(int low,int high){
	int largest=low;
	for(int i=low+1;i<=high;++i){
		COMPARE;
		if(entry[i]>entry[largest])
			largest=i;
	}
	return largest;
}
template <class Record>
void Sortable_list<Record>::swap(int low,int high){
	MOVE;
	Record tmp=entry[low];
	MOVE;
	entry[low]=entry[high];
	MOVE;
	entry[high]=tmp;
}
#endif

#ifdef LINKED
template <class Record>
Node<Record> *divide_from(Node<Record> *sub_list)
{
	Node<Record> *x2=sub_list;
	Node<Record> *x1=sub_list;
	Node<Record> *bak=nullptr;
	while(x2&&x2->next){
		bak=x1;
		x1=x1->next;
		x2=x2->next->next;
	}
	// Odd amount of elements
	if(x2){
		bak=x1->next;
		x1->next=nullptr;
		return bak;
	}
	// Even amount of elements or no element
	if(bak)
		bak->next=nullptr;
	return x1;
}
template <class Record>
/// @return Head of the combined list
Node<Record> *merge(Node<Record> *first,Node<Record> *second){
	Node<Record> *combined=nullptr;
	Node<Record> **last_sorted=&combined; // points to the last node of sorted list
	while(true){
		#define F {\
			*last_sorted=first;\
			last_sorted=&((*last_sorted)->next);\
			first=first->next;\
		}
		#define S {\
			*last_sorted=second;\
			last_sorted=&((*last_sorted)->next);\
			second=second->next;\
		}
		if(first){
			if(second)
				if(first->entry<=second->entry)
					F
				else
					S
			else
				F
		}else if(second){
			S
		}else{
			break;
		}
	}
	return combined;
}
template <class Record>
void recursive_merge_sort(Node<Record> **sub_list){
	if(*sub_list && (*sub_list)->next){
		Node<Record> *second_half = divide_from(*sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(&second_half);
		*sub_list = merge(*sub_list, second_half);
	}
}
template <class Record>
void Sortable_list<Record>::merge_sort(){
	recursive_merge_sort(&head);
}

#endif
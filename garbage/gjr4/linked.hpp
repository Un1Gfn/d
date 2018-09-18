// linked.hpp
#ifndef L
#define L
#include"main.hpp"
template<typename Node_entry>
struct Node {
	Node_entry entry;
	Node *next;
	Node( ):next(nullptr),entry(0){}
	Node(Node_entry item, Node *add_on = NULL):
		entry(item),next(add_on){}
};

template < class List_entry >
class List {
public:
	// methods of the List ADT
	~List( ){clear();}
	List( ):count(0),head(nullptr){}
	int size( ) const{return count;}
	// impossible on most occasions
	// bool full( ) const{return}
	bool empty( ) const{return count==0;}
	void clear( ){
		Node<List_entry>* a=head;
		Node<List_entry>* b=nullptr;
		while(a!=nullptr){
			b=a->next;
			delete a;
			a=b;
		}
		head=nullptr;
		count=0;
	}
	void print()const{
		Node<List_entry>* a=head;
		if(empty())
			cout<<"empty";
		else{
			while(a!=nullptr){
				cout<<a->entry<<" ";
				a=a->next;
			}
		}
		cout<<endl;
	}
	Error_code remove(int position, List_entry &x){
		// "list is empty" -> "(position<0||position>-1)"
		if(position<0||position>count-1)
			return Error_code:: range_error;
		Node<List_entry>** a=&head;
		// jump <position> times
		for(int i=0;i!=position;++i)
			a=&((*a)->next);
		x=(*a)->entry;
		Node<List_entry>* b=(*a)->next;
		delete *a;
		*a=b;
		--count;
		return Error_code::success;
	}
	Error_code insert(int position, const List_entry &x){
		if (position < 0 || position > count)
			return Error_code:: range_error;
		Node<List_entry>** a=&head;
		// jump <position> times
		for(int i=0;i!=position;++i)
			a=&((*a)->next);
		Node<List_entry>* new_node = new Node< List_entry >(x, *a);
		if (new_node == NULL)
			return Error_code:: overflow;
		*a=new_node;
		++count;
		return Error_code:: success;
	}
protected:
// data members for a contiguous list implementation
	int count;
	Node< List_entry > *head;
};
#endif

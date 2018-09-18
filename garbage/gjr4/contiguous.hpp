// contiguous.hpp
#ifndef C
#define C
#include"main.hpp"
const int max_list=100;
template < class List_entry >
class List {
public:
// methods of the List ADT
	List( ):count(0){clear();}
	int size( ) const{return count;}
	bool full( ) const{return count>=max_list-1;}
	bool empty( ) const{return count==0;}
	void clear( ){
		for(List_entry& r:entry)
			r=0;
	}
	void print()const{
		if(empty())
			cout<<"empty";
		else{
			for(int i=0;i!=count;++i)
				cout<<entry[i]<<" ";
		}
		cout<<endl;
	}
	Error_code remove(int position, List_entry &x){
		if(empty())
			return Error_code::underflow;
		if(position<0||position>count-1)
			return Error_code::range_error;
		entry[position]=0;
		for(int i=position;i!=count-1;++i)
			entry[i]=entry[i+1];
		--count;
		return Error_code::success;
	}
	Error_code insert(int position, const List_entry &x){
		if (full( ))
			return Error_code::overflow;
		if (position < 0 || position > count)
			return Error_code::range_error;
		for (int i = count - 1; i >= position; i-- ){
			entry[i + 1] = entry[i];
		}
		entry[position] = x;
		count ++ ;
		// cout<<count<<endl;
		return Error_code::success;
	}

protected:
	// data members for a contiguous list implementation
	int count;
	List_entry entry[max_list];
};
#endif

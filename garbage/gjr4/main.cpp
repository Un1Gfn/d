// main.cpp
#include<iostream>
using namespace std;
#ifdef CONTIGUOUS
	#include"contiguous.hpp"
#else
	#ifdef LINKED
		#include"linked.hpp"
	#else
		#error"No header specified"
	#endif
#endif
namespace darren{
	char getchar(const char* str){
		cout<<str;
		char ret='\0';
		cin>>ret;
		cin.get();
		return ret;
	}
	size_t getnum(const char* str){
		cout<<str;
		size_t ret=0;
		cin>>ret;
		cin.get();
		return ret;
	}
}
int main(){
	List<char> li;
	while(1){
		string op;
		cout<<"Input command: ";
		getline(cin,op);
		if(!cin||op=="q")
			break;
		else if(op=="p"){ // print
			li.print();
		}
		else if(op=="i"){ // insert
			size_t pos=darren::getnum("Insert before position:");
			char to_insert=darren::getchar("What to insert:");
			if(li.insert(pos,to_insert)!=Error_code::success)
				cout<<"Fail"<<endl;
			else
				cout<<"Done"<<endl;
		}
		else if(op=="r"){ // remove
			size_t pos=darren::getnum("Position:");
			char removed='\0';
			if(li.remove(pos,removed)!=Error_code::success)
				cout<<"Fail"<<endl;
			else
				cout<<"\'"<<removed<<"\' is removed"<<endl;
		}
		else if(op.empty()){
			continue;
		}
		else{
			cout<<"Invalid command"<<endl;
		}
	}
	return 0;
}
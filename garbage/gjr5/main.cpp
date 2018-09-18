#include<iostream>
#include<climits>
#include<map>
#include"node.hpp"
#include"tree.hpp"
using namespace std;
// type
typedef long long int_t;
// global var
Binary_tree<int_t> bt;
// utility
void print(int_t& e)
{
	cout<<" "<<e;
}
void show(const char* title)
{
	cout<<title<<":"<<endl;
	cout<<"  Preorder :";
	bt.preorder(print);
	cout<<endl;
	cout<<"  Postorder:";
	bt.postorder(print);
	cout<<endl;
	cout<<"  Inorder  :";
	bt.inorder(print);
	cout<<endl;
	cout<<endl;
}
void logout(){
	cout<<"Bye."<<endl;
	cout<<endl;
}
// main
int main(){
	cout<<"Please input signed integers between ["<<LLONG_MIN<<", "<<LLONG_MAX<<"]: "<<endl;
	cout<<"Each number a line, end with EOF."<<endl;
	cout<<"Don't give me letters and/or other garbages. Please BE SMART."<<endl;
	int_t tmp=0;
#define PS1 "Number> "
	cout<<PS1;
	while(cin>>tmp){
		bt.insert(tmp);
		cout<<PS1;
	}
	cout<<endl;
	cout<<endl;
	show("Original");
	bt.flip();
	show("Flipped");
	logout();
	return 0;
}
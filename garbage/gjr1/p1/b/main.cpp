// magic square generator
#include <iostream>
#include <iomanip>
#define GETq \
	if(!square)\
		throw runtime_error("Square resource is released");\
	auto q=(int(*)[square_size])square;\

using namespace std;
// global var
int square_size=0;
void* square=nullptr;
int curr_r=0,curr_c=0;
// func
// void print_square(){
// 	GETq;
// 	cout<<"---"<<endl;
// 	cout<<"  ";
// 	for(int i=0;i!=square_size;++i)
// 		cout<<"\033[32m"<<i<<" \033[0m";
// 	cout<<endl;
// 	for(int r=0;r<square_size;++r)
// 	{
// 		cout<<"\033[32m"<<r<<"\033[0m"<<" ";
// 		for(int c=0;c<square_size;++c)
// 			cout<<q[r][c]<<" ";
// 		cout<<endl;
// 	}
// 	cout<<"---"<<endl;
// }
// void print_square1(){
// 	GETq;
// 	cout<<"     ---"<<endl;
// 	cout<<"       ";
// 	for(int i=0;i!=square_size;++i)
// 		cout<<"\033[32m"<<i<<" \033[0m";
// 	cout<<endl;
// 	for(int r=0;r<square_size;++r)
// 	{
// 		cout<<"     \033[32m"<<r<<"\033[0m"<<" ";
// 		for(int c=0;c<square_size;++c)
// 			cout<<q[r][c]<<" ";
// 		cout<<endl;
// 	}
// 	cout<<"     ---"<<endl;
// }
void print_square(){
	GETq;

	const int width=to_string(square_size*square_size).size()+1;
	cout<<"---"<<endl;
	for(int r=0;r<square_size;++r)
	{
		for(int c=0;c<square_size;++c)
			cout<<setw(width)<<q[r][c];
		cout<<endl;
	}
	cout<<"---"<<endl;
}
void fix_forward(){
	if(curr_r<0)
		curr_r=square_size-1;
	if(curr_c>=square_size)
		curr_c=0;
}
void fix_drop(){
	if(curr_r>=square_size)
		curr_r=0;
}
void next(){
	GETq;
	// backup
	const int tmp_r=curr_r;
	const int tmp_c=curr_c;
	// forward
	--curr_r;
	++curr_c;
	// cout<<"--++:"<<curr_r<<" "<<curr_c<<endl;
	fix_forward();
	// cout<<" fix:"<<curr_r<<" "<<curr_c<<endl;
	//  occupied
	// cout<<" after1:"<<curr_r<<" "<<curr_c<<endl;
	// cout<<q[curr_r][curr_c]<<endl;
	// print_square1();
	if(q[curr_r][curr_c]!=0)
	{
		// recover
		curr_r=tmp_r;
		curr_c=tmp_c;
		// fix_drop
		++curr_r;
		// fix_drop();
		if(q[curr_r][curr_c]!=0)
			throw runtime_error("I'm stuck underneath");
	}
	// cout<<" after2:"<<curr_r<<" "<<curr_c<<endl;
}
void put(int num){
	GETq;
	q[curr_r][curr_c]=num;
}
int main()
{
	cout<<"Input square size (odd number>=3): ";
	cin>>square_size;
	if(square_size<3||square_size%2!=1)
	{
		cout<<"Invalid number, must be 3,5,7..."<<endl;
		return 1;
	}
	int square_resource[square_size][square_size]={};
	square=square_resource;
	curr_r=0;
	curr_c=square_size/2;
	put(1);
	// print_square();
	for(int i=2;i<=square_size*square_size;++i){
		// cout<<"before:"<<curr_r<<" "<<curr_c<<endl;
		next();
		// cout<<" after3:"<<curr_r<<" "<<curr_c<<endl;
		put(i);
		// print_square();
	}
	print_square();
	return 0;
}
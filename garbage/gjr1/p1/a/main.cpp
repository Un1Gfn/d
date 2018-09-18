// read a square array of integers and determines whether or not it is a magic square
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
const string example=string()+
"===Example===\n"+
" Input: square size=2, other numbers={3,6,8,0}\n"+
" square:\n"+
"------\n"+
" 3 6\n"+
" 8 0\n"+
"------\n"+
"===EndExmp===";
int square_size=0;
void* square=nullptr;
int sum_row(int row){
	if(!(row>=0&&row<square_size))
		throw runtime_error("Illegal row");
	if(!square)
		throw runtime_error("Square resource is released");
	int ret=0;
	auto q=(int(*)[square_size])square;
	for(int c=0;c<square_size;++c)
		ret+=q[row][c];
	return ret;
}
int sum_col(int col){
	if(!(col>=0&&col<square_size))
		throw runtime_error("Illegal col");
	if(!square)
		throw runtime_error("Square resource is released");
	int ret=0;
	auto q=(int(*)[square_size])square;
	for(int r=0;r<square_size;++r)
		ret+=q[r][col];
	return ret;
}
int sum_r_slash_diagonal(){
	if(!square)
		throw runtime_error("Square resource is released");
	auto q=(int(*)[square_size])square;
	int ret=0;
	for(int i=0;i!=square_size;++i)
		ret+=q[i][i];
	return ret;
}
int sum_slash_diagonal(){
	if(!square)
		throw runtime_error("Square resource is released");
	auto q=(int(*)[square_size])square;
	int ret=0;
	for(int i=0;i!=square_size;++i)
		ret+=q[square_size-i-1][i];
	return ret;
}
void print_square(){
	if(!square)
		throw runtime_error("Square resource is released");
	auto q=(int(*)[square_size])square;
	cout<<"---"<<endl;
	for(int r=0;r<square_size;++r)
	{
		for(int c=0;c<square_size;++c)
			cout<<q[r][c]<<" ";
		cout<<endl;
	}
	cout<<"---"<<endl;
}
int main()
{
	cout<<"Input square size, or '0' for the example: ";
	cin>>square_size;
	if(square_size<0)
	{
		cout<<"Invalid number, must be 0 or more"<<endl;
		return 1;
	}
	if(square_size==0){
		cout<<example<<endl;
		return 0;
	}
	int square_resource[square_size][square_size]={};
	square=square_resource;
	cout<<"Input "<<square_size*square_size<<" numbers in a single line or "<<square_size<<" lines to fill the square: "<<endl;
	for(int r=0;r<square_size;++r)
		for(int c=0;c<square_size;++c)
			cin>>square_resource[r][c];
	const int standard=sum_row(0);
	cout<<"Sum of the first row (row 0) is "<<standard<<endl;
	cout<<"Verifying other rows ..."<<endl;
	for(int r=1;r!=square_size;++r)
	{
		if(sum_row(r)!=standard)
		{
			cout<<"Failed"<<endl;
			return 2;
		}
	}
	cout<<"Verifying cols ..."<<endl;
	for(int c=0;c!=square_size;++c)
	{
		if(sum_col(c)!=standard)
		{
			cout<<"Failed"<<endl;
			return 3;
		}
	}
	cout<<"Verifying diagonals ..."<<endl;
	if(sum_r_slash_diagonal()!=standard || sum_slash_diagonal()!=standard)
	{
		cout<<"Failed"<<endl;
		return 4;
	}
	cout<<"Passed"<<endl;
	square=nullptr;
	return 0;
}
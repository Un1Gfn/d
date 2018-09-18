// main.cpp
#include <iostream>
#include <cstdio>
#include "Date.h"
using namespace std;
int main(){
	Date t1,t2;
	cout<<"Input year, month and date of two dates (6 integers seperated with spaces): ";
	cin>>t1.y>>t1.m>>t1.d;
	cin>>t2.y>>t2.m>>t2.d;
	if(!legal(t1)||!legal(t2))
	{
		cout<<"Illegal date"<<endl;
		return 1;
	}
	if(t2<t1)
		std::swap(t1,t2);
	cout<<"There are "<<diffDate(t1,t2)<<" days in ["<<toString(t1)<<", "<<toString(t2)<<")"<<endl;
	return 0;
}
// main.cpp
// 2017-09-06 Wednesday
#include <iostream>
#include <cstdio>
#include "Date.h"
using namespace std;
string week[7]={
	"Monday",   //0
	"Tuesday",
	"Wednesday",//2
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"    //6
};
#define TODAY 2
const Date t0(2017,9,6);
int main(){
	Date t;
	cout<<"Input year, month and date(3 integers seperated with spaces): ";
	cin>>t.y>>t.m>>t.d;
	if(!legal(t))
	{
		cout<<"Illegal date"<<endl;
		return 1;
	}
	if(t0<t)
		cout<<toString(t)<<" is "<<week[(diffDate(t0,t)%7+TODAY)%7]<<endl;
	else
		cout<<toString(t)<<" is "<<week[((-diffDate(t,t0)%7+TODAY)%7+7)%7]<<endl;
	return 0;
}
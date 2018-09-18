// main.cpp
// 2017-09-06 Wednesday
#include "Date.h"
using namespace std;
string week[7]={
	"Monday",   //0
	"Tuesday",
	"Wednesday",//2
	"Thursday",
	"Friday",   //4
	"Saturday",
	"Sunday"    //6
};
#define TODAY 2
const Date t0(2017,9,6);
int dayOfWeek(const Date& t){
	if(!legal(t))
		throw runtime_error("Illegal date");
	if(t0<t)
		return (diffDate(t0,t)%7+TODAY)%7;
	// cout<<toString(t)<<" is "<<week[((-diffDate(t,t0)%7+TODAY)%7+7)%7]<<endl;
	throw runtime_error("History");
}
int main(){
	int counter[7]={};
	// count from 2018 through 2417
	for(int y=2018;y!=2418;++y)
		for(int m=1;m<=12;++m)
		{
			Date tmp(y,m,13);
			++counter[dayOfWeek(tmp)];
		}
	int total=0;
	for(int i=0;i!=7;++i)
	{
		cout<<setw(10)<<week[i]<<setw(4)<<counter[i]<<endl;
		total+=counter[i];
	}
	cout<<total<<endl;
	return 0;
}
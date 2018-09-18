// Date.cpp
#include "Date.h"
using namespace std;
int cal[2][13]=
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool lunar(const int y){
	if(y%400==0)
		return true;
	if(y%100==0)
		return false;
	if(y%4==0)
		return true;
	return false;
}
bool lunar(const Date& t){
	return lunar(t.y);
}
int dayInYear(const int year){
	return lunar(year)?366:365;
}
int diffDate(Date t1,Date t2){
	if(t2<t1)
		std::swap(t1,t2);
	int ret=0;
	for(int i=t1.y;i!=t2.y;++i)
		ret+=dayInYear(i);
	ret-=offset(t1);
	ret+=offset(t2);
	// +1 ? -1 ?
	return ret;
}
int offset(const Date& t){
	int ret=0;
	for(int i=1;i<t.m;++i)
		ret+=cal[lunar(t)?1:0][i];
	ret+=t.d;
	return ret;
}
bool operator<(const Date& t1,const Date& t2){
	return tuple<int,int,int>(t1.y,t1.m,t1.d)<tuple<int,int,int>(t2.y,t2.m,t2.d);
}
bool legal(const Date& t){
	if(t.y<1 || t.m<1 || t.m>12 || t.d<1 || t.d>cal[lunar(t)?1:0][t.m])
		return false;
	return true;
}
string toString(const Date& t){
	char ret[20]={};
	sprintf(ret,"%04d-%02d-%02d",t.y,t.m,t.d);
	return string(ret);
}
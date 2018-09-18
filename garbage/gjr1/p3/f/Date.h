// Date.h
#ifndef DATE_H
#define DATE_H
#include <algorithm>
#include <tuple>
#include <string>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <iomanip>
struct Date{
	Date():y(0),m(0),d(0){}
	Date(int num1,int num2,int num3):y(num1),m(num2),d(num3){}
	int y;
	int m;
	int d;
};
bool legal(const Date& t);
bool operator<(const Date& t1,const Date& t2);
int dayInYear(const int year);
int offset(const Date& t);
int diffDate(Date t1,Date t2);
bool lunar(const int y);
bool lunar(const Date& t);
std::string toString(const Date& t);
#endif
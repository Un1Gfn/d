#include <cstring>
#include <iostream>
#include <list>
#include <algorithm>
#include "08_String.h"

String::String():entries(nullptr),length(0){}

String::~String(){
  delete[]entries;
}

String::String(const char *in_string)
{
  length = strlen(in_string);
  entries = new char[length + 1];
  strcpy(entries, in_string);
}

String::String (/*List*/list<char> &in_list)
{
  length = in_list.size();
  entries = new char[length + 1];
  // for (int i = 0; i < length; i++ ) in_list.retrieve(i, entries[i]);
  char *p=entries;
  for_each(in_list.begin(),in_list.end(),[&p](char ch){*(p++)=ch;});
  entries[length] = '\0' ;
}

void String::operator=(const String &copy){
  length=0;
  delete[]entries;
  entries=nullptr;
  entries=new char[copy.length+1];
  strcpy(entries,copy.entries);
}

const char *String::c_str() const
{
  return (const char *)entries;
}


bool operator == (const String &first, const String &second)
{
  return strcmp(first.c_str(), second.c_str()) ==0;
}

bool operator>(const String &first, const String &second){
  return strcmp(first.c_str(), second.c_str()) >0;
}

bool operator<(const String &first, const String &second){
  return strcmp(first.c_str(), second.c_str()) <0;
}

bool operator>=(const String &first, const String &second){
  return strcmp(first.c_str(), second.c_str()) >=0;
}

bool operator<=(const String &first, const String &second){
  return strcmp(first.c_str(), second.c_str()) <=0;
}

bool operator!=(const String &first, const String &second){
  return strcmp(first.c_str(), second.c_str()) !=0;
}

void strcat(String &add_to, const String &add_on)
{
  const char *cfirst = add_to.c_str();
  const char *csecond = add_on.c_str();
  char *copy = new char[strlen(cfirst) + strlen(csecond) + 1];
  strcpy(copy, cfirst);
  strcat(copy, csecond);
  add_to = copy;
  delete [ ]copy;
}

String read_in(istream &input)
{
  // List<char> temp;
  list<char> temp;
  int size = 0;
  char c;
  while ((c = input.peek()) != EOF && (c = input.get()) != '\n' ){
    // temp.insert(size++ , c);
    temp.insert(temp.end(), c);
    ++size;
  }
  String answer(temp);
  return answer;
}

void write(String &s)
/* Post: The String parameter s is written to cout.*/
{
  cout << s.c_str() << endl;
}

void strcpy(String &copy, const String &original){
  // char *tmp = new char[strlen(original.c_str()) + 1];
  // strcpy(tmp, original);
  // copy=tmp;
  // delete [ ]tmp;
  copy=original;
}

void strncpy(String &copy, const String &original, int n){
  char *tmp = new char[strlen(original.c_str()) + 1];
  strncpy(tmp,original.c_str(),n);
  copy=tmp;
  delete[]tmp;
}

int strstr(const String &text, const String &target){

}

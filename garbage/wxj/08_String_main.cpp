#include <iostream>
#include <list>
#include "08_String.h"

// Valgrind?

int main()
{
  // String s;
  // write(s);

  // String s("123sdfsd");
  // write(s);
  // printf("%s\n",s.c_str());
  
  // list<char> l{'a','g','+','f'};
  // String s("123sdfsd");
  // write(s);

  // String s1("asdf");
  // String s2("asde");
  // printf("(%c) s1==s2\n",s1==s2?'O':'X');
  // printf("(%c) s1> s2\n",s1> s2?'O':'X');
  // printf("(%c) s1< s2\n",s1< s2?'O':'X');
  // printf("(%c) s1>=s2\n",s1>=s2?'O':'X');
  // printf("(%c) s1<=s2\n",s1<=s2?'O':'X');
  // printf("(%c) s1!=s2\n",s1!=s2?'O':'X');

  // String s1("asdf");
  // String s2("asde");
  // strcat(s1,s2);
  // write(s1);

  // String s=read_in(cin);
  // write(s);

  // String s1("asdf");
  // String s2("asde");
  // strcpy(s1,s2);
  // write(s1);

  String s1("asdf");
  String s2("xyzwt");
  strncpy(s1,s2,3);
  write(s1);

  return 0;
}
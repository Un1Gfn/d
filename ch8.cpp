#include <iostream>
#include <random>

// #define LINKED
#define CONTIGUOUS
// #define STATISTICS // How many comparasions/moves?
#include "Sortable_list.h"

// #define SORT l.insertion_sort();
// #define SORT l.selection_sort();
// #define SORT l.merge_sort();
#define SORT l.quick_sort();

// void stat(){}

// Fixed length
// void test_random(int len,int num_case){
//   uniform_int_distribution<int> u(0,99);
//   default_random_engine e(time(0));
//   for(int i=0;i!=num_case;++i){
//     Sortable_list<int> l;
//     for(int j=0;j!=len;++j)
//       l.insert(j,u(e));
//     l.print();
//     // INIT;
//     SORT
//     l.print();
//     // SUM;
//     cout<<endl;
//   }
// }

// Random length
void test_random(int lenL,int lenU,int num_case){
  uniform_int_distribution<int> lenD(lenL,lenU);
  uniform_int_distribution<int> eleD(0,99);
  default_random_engine e(time(0));
  for(int i=0;i!=num_case;++i){
    Sortable_list<int> l;
    int len=lenD(e);
    for(int j=0;j!=len;++j)
      l.insert(j,eleD(e));
    l.print();
    // INIT;
    SORT
    l.print();
    // SUM;
    cout<<endl;
  }
}

void test_static(){
  for(initializer_list<int> il:initializer_list<initializer_list<int>>{
    {}
    ,
    {11}
    ,
    {11,22}
    ,
    {22,11}
    ,
    {11,22,33}
    ,
    {22,11,33}
    ,
    {33,11,22}
    ,
    {11,33,22}
    ,
    {22,33,11}
    ,
    {33,22,11}
  }){
    Sortable_list<int> l(il);
    l.print();
    // INIT;
    SORT
    // SUM;
    cout<<endl;
  }
}

int main(){
  // test_static();
  test_random(10,20,7);
  // stat();
  return 0;
}
#include <cstdio>
#include <algorithm>
#include "10_BinarySearch.h"

void print(const Ordered_list& ol){
  for_each(
    ol.begin(),
    ol.end(),
    [](const Record& r){printf("%d ",r.the_key());
  });
  printf("\n");
}

int main(){

  printf("\n");
  Ordered_list l;
  l.insert(5);
  l.insert(4);
  l.insert(3);
  l.insert(2);
  l.insert(1);
  l.insert(10);
  l.insert(9);
  l.insert(8);
  l.insert(7);
  l.insert(6);
  int sum=0;

  for(int i=1;i!=11;++i){
    int p=0;
    comparisons=0;
    binary_search_1(l,Key(i),p);
    printf("%d ",comparisons);
    sum+=comparisons;
  }
  printf("- %lf\n",(double)sum/10);

  sum=0;
  for(int i=1;i!=11;++i){
    int p=0;
    comparisons=0;
    binary_search_2(l,Key(i),p);
    printf("%d ",comparisons);
    sum+=comparisons;
  }
  printf("- %lf\n",(double)sum/10);

  // print(l);
  // for(int i=1;i!=11;++i){
  //   int p=0;
  //   if(binary_search_1(l,Key(i),p)==success)
  //     printf("%d\n",p);
  //   else
  //     printf("Not found\n");
  // }

  printf("\n");
  return 0;
}
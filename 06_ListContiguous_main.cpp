#include <stdio.h>
#include "06_ListContiguous.h"

void visit(char& ch){
  // printf("x");
  printf("%c ",ch);
}

int main(){

  List<char> l;

  // visit(l.entry[0]);
  // printf("%d",l.insert(0,'a'));
  // visit(l.entry[0]);
  printf("\n");
  l.insert(0,'a');
  l.insert(0,'s');
  l.insert(0,'d');
  l.insert(3,'x');
  l.insert(3,'x');
  l.insert(0,'d');
  l.insert(6,'y');
  l.insert(6,'y');
  // printf("%d\n",l.count);
  l.traverse(visit);

  // printf("\n");
  // l.serve();
  // l.print();

  // printf("\n");
  // ch=0;
  // l.retrieve(ch);
  // printf("%c\n",ch);
  // printf("%d\n",l.size());

  // printf("\n");
  // ch=0;
  // l.serve_and_retrieve(ch);
  // printf("%c\n",ch);
  // printf("%d\n",l.size());

  printf("\n");
  return 0;

}
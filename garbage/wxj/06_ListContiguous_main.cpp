#include <stdio.h>
#include "06_ListContiguous.h"

void visit(char& ch){
  // printf("x");
  printf("%c ",ch);
}

int main(){
  List<char> l;

  // printf("\n");
  // l.insert(0,'a');
  // l.insert(0,'s');
  // l.insert(0,'d');
  // printf("%d\n",l.insert(5,'x'));
  // printf("%d\n",l.insert(4,'x'));
  // printf("%d\n",l.insert(3,'x'));
  // l.traverse(visit);

  // printf("\n");
  // l.insert(0,'a');
  // l.insert(0,'s');
  // l.insert(0,'d');
  // char ch=0;
  // printf("%d\n",l.retrieve(-1,ch));
  // printf("%d\n",l.retrieve(3,ch));
  // printf("%d\n",l.retrieve(4,ch));
  // printf("%d\n",l.retrieve(0,ch));printf("%c\n",ch);
  // printf("%d\n",l.retrieve(1,ch));printf("%c\n",ch);
  // printf("%d\n",l.retrieve(2,ch));printf("%c\n",ch);

  // printf("\n");
  // l.insert(0,'a');
  // l.insert(0,'s');
  // l.insert(0,'d');
  // char ch=0;
  // printf("%d\n",l.remove(-1,ch));
  // printf("%d\n",l.remove(3,ch));
  // printf("%d\n",l.remove(4,ch));
  // printf("%d\n",l.remove(0,ch));l.traverse(visit);printf(" -> %c\n",ch);
  // printf("%d\n",l.remove(0,ch));l.traverse(visit);printf(" -> %c\n",ch);
  // printf("%d\n",l.remove(0,ch));l.traverse(visit);printf(" -> %c\n",ch);

  printf("\n");
  l.insert(0,'a');
  l.insert(0,'s');
  l.insert(0,'d');
  char ch=0;
  printf("%d\n",l.remove(-1,ch));
  printf("%d\n",l.remove(3,ch));
  printf("%d\n",l.remove(4,ch));
  printf("%d\n",l.remove(2,ch));l.traverse(visit);printf(" -> %c\n",ch);
  printf("%d\n",l.remove(1,ch));l.traverse(visit);printf(" -> %c\n",ch);
  printf("%d\n",l.remove(0,ch));l.traverse(visit);printf(" -> %c\n",ch);

  printf("\n");
  return 0;

}
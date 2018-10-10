#include <stdio.h>
#include "05_LQ.h"

int main(){

  Super_queue q;
  Queue_entry ch=0;

  // printf("\n");
  // q.print();
  // printf("%s\n",q.empty()?"Empty":"Not empty");

  printf("\n");
  q.append('a');
  q.append('s');
  q.append('d');
  q.print();

  printf("\n");
  q.serve();
  q.print();

  printf("\n");
  ch=0;
  q.retrieve(ch);
  printf("%c\n",ch);
  printf("%d\n",q.size());

  printf("\n");
  ch=0;
  q.serve_and_retrieve(ch);
  printf("%c\n",ch);
  printf("%d\n",q.size());

  printf("\n");
  return 0;

}
#include "03_C_Stack.h"
#include <stdio.h>

int main()
{
  // Prepare
  int n=0;
  double item=0;
  printf(" Type in an integer n followed by n decimal numbers.\n");
  printf(" The numbers will be printed in reverse order.\n"); 
  scanf("%d",&n);
  // Initialization
  Stackinit();
  // Read
  for (int i = 0; i < n; i++ ) {
    scanf("%lf",&item);
    push(&item);
  }
  printf("\n\n");
  // Write
  while (!empty()) {
    Stack_entry tmp=0;
    top(&tmp);
    // cout << tmp << " ";
    printf("%lf ",tmp);
    pop();
  }
  printf("\n");
  return 0;
}

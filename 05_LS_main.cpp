#include <stdio.h>
#include "05_LS.h"

void print_stack(const Stack& s){
  // Stack tmpS(s);
  Stack tmpS;
  tmpS=s;
  printf("TOP ");
  while(!tmpS.empty()){
    Stack_entry tmpE=0;
    tmpS.top(tmpE);
    printf("%c ",tmpE);
    tmpS.pop();
  }
  printf("BOTTOM\n");
}

int main(){
  Stack s;
  printf("%s\n",s.empty()?"Empty":"Not empty");
  while(1){
    char ch[3]={};
    // if(scanf("%s",ch)!=1)
    //   break;
    scanf("%s",ch);
    if(feof(stdin)!=0)
      break;
    s.push(ch[0]);
    print_stack(s);
  }
  return 0;
}
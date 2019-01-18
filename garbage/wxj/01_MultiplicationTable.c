#include<stdio.h>
int main(){
  for(int r=1;r<=9;++r){
    for(int c=1;c<=r;++c)
      printf("%d*%d=%-2d%c",r,c,r*c,(c==r?'\n':'\t'));
  }
  return 0;
}
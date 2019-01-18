#include <stdio.h>

typedef unsigned long long llu;

llu count;

llu factorial(llu n)
{
  ++count;
  printf("%llu\n",count);
  if (n <= 0)
    return 1;
  else
    return n * factorial(n-1);
}

int main(){
  llu n=0;
  while(!feof(stdin)){
   scanf("%llu",&n);
   count=0;
   // printf("%20llu%20llu\n",factorial(n),count);
   printf("%20llu",factorial(n));
   // factorial(n);
   printf("%20llu\n",count);
 } 
  return 0;
}
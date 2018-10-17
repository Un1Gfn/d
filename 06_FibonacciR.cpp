#include <iostream>
using namespace std;

// const int disks = 64;

int call=0;

// 178
int fibonacci(int n)
{
  ++call;
  if (n <= 0)
   return 0;
  else if (n == 1) return 1;
  else
   return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n=0;
  while(!feof(stdin)){
    scanf("%d",&n);
    call=0;
    printf("%d\n",fibonacci(n));
    printf("call = %d\n",call);
 }
  return 0;
}

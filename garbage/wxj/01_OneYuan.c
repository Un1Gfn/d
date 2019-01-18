#include <stdio.h>
#include <stdlib.h>

void print(int one,int two,int five)
{
  printf("%3d*1 + %2d*2 + %2d*5 = %d\n", one, two, five, one*1+two*2+five*5);
}

int getNum()
{
  int ret=0;
  scanf("%d",&ret);
  if (ret<=0){
    printf("Invalid input %d\n",ret);
    exit(1);
  }
  return ret;
}

int main()
{
  int sum=getNum();

  // 2601
  // int one=0,two=0,five=0,total=0,loopCounter=0;
  // for(one=sum; one>=0; --one){
  //   for(two=(sum-one*1)/2; two>=0; --two){
  //     ++loopCounter;
  //     five=(sum-one*1-two*2)/5;
  //     if (one*1+two*2+five*5==sum){
  //       print(one,two,five);
  //       ++total;
  //     }
  //     else
  //       continue;
  //   }
  // }

  // 541
  int two=0,five=0,total=0,loopCounter=0;
  for(five=sum/5;five>=0;--five){
    for(two=(sum-five*5)/2; two>=0; --two){
      ++loopCounter;
      print(sum-five*5-two*2, two, five);
      ++total;
    }
  }

  printf("Total: %d\n",total);
  printf("Loop count: %d\n",loopCounter);
  return 0;
}

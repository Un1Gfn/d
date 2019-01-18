#include <stdio.h>
#include <stdlib.h>
#include <math.h> // pow()

int calc(int data){
  if(data<0){
    printf("Error\n");
    exit(1);
  else if(data==0)
    exit(0);
  int ret=0;
  while(data>0){
    int digit=data/10;
    ret+=pow(digit,3); // double2int
  }   
}

int main(){

}
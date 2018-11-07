#include <cstdio>
#include "09_Poly.h"


int main(){

  printf("\n");

  printf("\n");
  Poly p("-x-x^2-x+4x^2+x^100-99x^100+2x",true);
  p.Display();
  p.Reverse();
  p.Display();
  Poly q("-x-x^2-x+4x^2+x^100-99x^100+2x",false);
  q.Display();
  q.Reverse();
  q.Display();
  
  // printf("\n");
  // Poly p("x+x^2");
  // p.Display();
  // p.Reverse();
  // p.Display();
  // // );

  // printf("\n");
  // Poly p("x+x^2+x^3");
  // p.Display();
  // p.Reverse();
  // p.Display();

  // printf("\n");
  // Poly p;
  // p.Display();
  // p.Insert(1,2);
  // p.Insert(-1,2);
  // p.Display();

  // printf("\n");
  // Poly("2x^3+4x^5+6x^7").Display();

  // printf("\n");
  // testCoefExpn("34x^2");
  // testCoefExpn("+1x^2");
  // testCoefExpn("x^2");

  // printf("\n");
  // testCoefExpn("+0x^2");
  // testCoefExpn("0x^2");
  // testCoefExpn("-0x^2");

  // printf("\n");
  // testCoefExpn("-34x^2");
  // testCoefExpn("-x^2");
  // testCoefExpn("-1x^2");


  // printf("\n");
  // testCoefExpn("x^-1");
  // testCoefExpn("x^0");
  // testCoefExpn("x");
  // testCoefExpn("x^-23");
  // testCoefExpn("x^23");

  printf("\n");
  return 0;
}
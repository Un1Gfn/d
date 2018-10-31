#include <cstdio>
#include "09_Poly.h"

// void testCoefExpn(const char* Str){
//   Poly p;
//   printf("%7d ",p.GetCoef(Str));
//   printf("%7d\n",p.GetExpn(Str));
// }

int main(){

  printf("\n");

  printf("\n");
  // Poly p("1x^2+3x^4+5x^6");
  // Poly p("x-x^2+2x");
  Poly p("-x-x^2-x+4x^2+x^100-99x^100+2x");
  p.Display();
  
  // printf("\n");
  // Poly p;
  // p.Display();
  // p.Insert(1,2);
  // p.Insert(-1,0);
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
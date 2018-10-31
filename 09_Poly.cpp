#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "09_Poly.h"

Poly::Poly(const char *str):Ascending(1){
  while(*str){
    double Coef=GetCoef(str);
    int Expn=GetExpn(str);
    if(Coef!=0)
      Insert(Coef,Expn);
  }
}

Poly::Poly():Ascending(1),Exp(NULL){}

Poly::~Poly(){
  while(Exp){
    Node *tmp=Exp->next;
    delete Exp;
    Exp=tmp;
  }
}

int Poly::GetCoef(const char *&Str){
  const char *Pt;
  char Data[8]={};
  Pt=Str;
  if(*Str=='-'||*Pt=='+')
    Str++;
  while('0'<=*Str&&*Str<='9')
    Str++;
  int k=Str-Pt;
  if(k==0)
    k=1;
  else if( k==1 && (*Pt=='+'||*Pt=='-') )
    k=(*Pt=='+'?1:-1);
  else{
    // strncpy_s(Data,7,Pt,k);
    strncpy(Data,Pt,k);
    Data[k]='\0';
    k=atoi(Data);
  }
  return k;
}

int Poly::GetExpn(const char *&Str){
  const char *Pt;
  char Data[8];
  if(*Str!='X' && *Str!='x')
    return 0;
  Str++;
  if(*Str!='^')
    return 1;
  Pt=++Str;
  while('0'<=*Str && *Str<='9')
    Str++;
  int k=Str-Pt;
  // strncpy(Data,7,Pt,k);
  strncpy(Data,Pt,k);
  Data[k]='\0';
  return atoi(Data);
}

void Poly::Display(){
  Node *p=Exp;
  while(p){
    printf("%+dx^%d",p->Coef,p->Expn);
    p=p->next;
  }
  printf("\n");
}

void Poly::Insert(int Coef,int Expn){
  Node **p=&Exp;
  if(Ascending){
    while(1){
      if(*p==NULL){
        *p=new Node{Coef,Expn,NULL};
        break;
      }
      if((*p)->Expn > Expn){
        *p=new Node{Coef,Expn,*p};
        break;
      }
      if((*p)->Expn == Expn){
        (*p)->Coef+=Coef;
        if(fabs((*p)->Coef)<0.01){
          Node *del=(*p);
          *p=(*p)->next;
          delete del;
        }
        break;
      }
      p=&((*p)->next);
    }
  }else{
    printf("Descending\n");
    exit(1);
  }
}
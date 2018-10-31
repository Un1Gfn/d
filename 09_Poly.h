#ifndef POLY
#define POLY

// Exp:  Expression
// Expn: Exponent

typedef struct _Node{
  int Coef;
  int Expn;
  struct _Node *next;
} Node;

class Poly{
public:
  Poly();
  Poly(const char *str);
  Poly(const Poly&);
  ~Poly();
  void Display();
  void Reverse();
  void Clear();
public:
  void Insert(int Coef,int Expn);
  bool Ascending;
  Node *Exp;
  int GetCoef(const char *&str);
  int GetExpn(const char *&str);
};

#endif
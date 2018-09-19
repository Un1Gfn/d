#ifndef STACK
#define STACK

const int maxstack = 10;
typedef double Stack_entry;
enum Error_code{success,overflow,underflow};

struct Stack {
  int count;
  Stack_entry entry[maxstack];
};


void Stackinit();
bool empty();
// const pointer to const object
Error_code push(const Stack_entry * const item);
// const pointer to mutable object
Error_code top(Stack_entry * const item);
Error_code pop();

#endif

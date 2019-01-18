#include "03_C_Stack.h"

Stack numbers;

void Stackinit()
{
  numbers.count = 0;
}

bool empty()
{
  const Stack * const protect=&numbers;
  const Stack * const numbers = protect;
  bool outcome = true;
  if (numbers->count > 0) outcome = false;
  return outcome;
}

Error_code push(const Stack_entry * const item)
{
  Error_code outcome = success;
  if (numbers.count >= maxstack)
    outcome = overflow;
  else
    numbers.entry[numbers.count++] = *item;
  return outcome;
}

Error_code top(Stack_entry * const item)
{
  const Stack * const protect=&numbers;
  const Stack * const numbers = protect;
  Error_code outcome = success;
  if (numbers->count == 0)
    outcome = underflow;
  else
    *item = numbers->entry[numbers->count - 1];
  return outcome;
}

Error_code pop()
{
  Error_code outcome = success;
  if (numbers.count == 0)
    outcome = underflow;
  else --numbers.count;
  return outcome;
}



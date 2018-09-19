#include "03_Stack.h"
#include <iostream>

using namespace std;

int main()
{
  int n;
  double item=0;
  Stack numbers;
  cout << " Type in an integer n followed by n decimal numbers." << endl
       << " The numbers will be printed in reverse order." << endl;
  cin >> n;
  for (int i = 0; i < n; i++ ) {
    cin >> item;
    numbers.push(item);
  }
  cout << endl << endl;
  while (!numbers.empty()) {

    // cout << numbers.top() << " ";

    Stack_entry tmp=0;
    numbers.top(tmp);
    cout << tmp << " ";

    numbers.pop();
  }
  cout << endl;
}

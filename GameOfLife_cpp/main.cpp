// p08 S1
// p08 S2

// p22 S3

// p23 S4

// p24 S5

// p25 S6

// p26 S7
// p26 S8

// p27 S9

#include "utility.h"
#include "life.h"

int main()
{
  Life configuration;
  instructions();
  configuration.initialize();
  configuration.print();
  cout << "Continue viewing new generations? " << endl;
  while (user_says_yes()) {
    configuration.update();
    configuration.print();
    cout << "Continue viewing new generations? " << endl;
  }
}

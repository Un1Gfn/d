#include "life.h" // maxrow maxcol
#include "utility.h"

void instructions()
{
  cout << "Welcome to Conway's game of Life." << endl;
  cout << "This game uses a grid of size "
       << maxrow << " by " << maxcol << " in which" << endl;
  cout << "each cell can either be occupied by an organism or not." << endl;
  cout << "The occupied cells change from generation to generation" << endl;
  cout << "according to the number of neighboring cells which are alive."
       << endl;
}
bool user_says_yes()
{
  int c;
  bool initial_response = true;
  do {
    if (initial_response)
      cout << " (y,n)? " << flush;
    else
      cout << "Respond with either y or n: " << flush;
    do {
      c = cin. get();
    } while (c == '\n' || c == ' ' || c == '\t' );
    initial_response = false;
  } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
  return (c == 'y' || c == 'Y');
}

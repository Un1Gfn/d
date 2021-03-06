#include "life.h"
#include <iostream>
using namespace std;

int Life::neighbor_count(int row, int col)
{
  int count = 0;

  // int i, j;
  // for (i = row - 1; i <= row + 1; i++ )
  //   for (j = col - 1; j <= col + 1; j++ )
  //     count += grid[i][j];

  // p23: hedges for protection, "if(row-1)...(row+1)...(col-1)...(col+1)..." unnecessary
  // 3
  count += grid[row-1][col-1];
  count += grid[row-1][col];
  count += grid[row-1][col+1];
  // 3
  count += grid[row+1][col-1];
  count += grid[row+1][col];
  count += grid[row+1][col+1];
  // 2
  count += grid[row][col-1];
  count += grid[row][col+1];

  return count;
}
void Life::update()
{
  int row, col;
  int new_grid[maxrow + 2][maxcol + 2];
  for (row = 1; row <= maxrow; row++ )
    for (col = 1; col <= maxcol; col++ )
      switch (neighbor_count(row, col)) {
      case 2:
        new_grid[row][col] = grid[row][col]; // Status stays the same.
        break;
      case 3:
        new_grid[row][col] = 1; // Cell is now alive.
        break;
      default:
        new_grid[row][col] = 0; // Cell is now dead.
      }
  for (row = 1; row <= maxrow; row ++ )
    for (col = 1; col <= maxcol; col ++ )
      grid[row][col] = new_grid[row][col];
}
void Life::initialize()
{
  int row, col;
  for (row = 0; row <= maxrow + 1; row ++ )
    for (col = 0; col <= maxcol + 1; col ++ )
      grid[row][col] = 0;
  cout << "List the coordinates for living cells." << endl;
  cout << "Terminate the list with the the special pair -1 -1" << endl;
  cin >> row >> col;
  while (row != -1 || col != -1) {
    if (row >= 1 && row <= maxrow)
      if (col >= 1 && col <= maxcol)
        grid[row][col] = 1;
      else
        cout << "Column " << col << " is out of range." << endl;
    else
      cout << "Row " << row << " is out of range." << endl;
    cin >> row >> col;
  }
}
void Life::print()
{
  int row, col;
  cout << "\nThe current Life configuration is:" << endl;
  for (row = 1; row <= maxrow; row ++ ) {
    for (col = 1; col <= maxcol; col ++ )
      if (grid[row][col] == 1) cout << 0 *0 ;
      else cout << ' ' ;
    cout << endl;
  }
  cout << endl;
  
  // 
  // printf("\n");
  // printf("\n");
  // printf("\n");
  // for (row = 1; row <= maxrow; row++ ){
  //   for (col = 1; col <= maxcol; col++ )
  //     printf("%d ",neighbor_count(row,col));
  //   printf("\n");
  // }
  // printf("\n");
  // printf("\n");
  // printf("\n");

}

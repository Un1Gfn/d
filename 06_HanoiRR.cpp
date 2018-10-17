// 165
#include <iostream>
using namespace std;

// const int disks = 64;

int call=0;
int op=0;

void move(int count, int start, int finish, int temp);

int main()
{
  int disks=0;
  while(!feof(stdin)){
    scanf("%d",&disks);
    call=0;
    op=0;
    move(disks, 1, 3, 2);
    printf("call = %d\n",call);
    printf("op   = %d\n",op);
 }
  return 0;
}

void move(int count, int start, int finish, int temp)
{
  ++call;
  if (count > 0) {
    move(count - 1, start, temp, finish);
    cout << "Move disk " << count << " from " << start
         << " to " << finish << "." << endl;
    ++op;
    move(count - 1, temp, finish, start);
  }
}

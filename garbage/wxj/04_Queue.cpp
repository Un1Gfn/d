#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef int Queue_entry;
enum Error_code{success,overflow,underflow};
#define NEXT(i) (i+1)%maxqueue
#define COUNT   (rear-front+1+maxqueue)%maxqueue
#define ISEMPTY COUNT==0
#define FULL    COUNT==maxqueue-1

// 89
const int maxqueue = 10;
class Queue {
public:
  Queue();
  bool empty() const;
  Error_code serve();
  Error_code append(const Queue_entry &item);
  Error_code retrieve(Queue_entry &item) const;
protected:
  int front, rear;
  Queue_entry entry[maxqueue];
};

// 82
class Extended_queue: public Queue {
public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
};

// 90
Queue::Queue()
{
  rear = maxqueue - 1;
  front = 0;
}
bool Queue::empty() const
{
  return COUNT==0;
}
Error_code Queue::append(const Queue_entry &item)
{
  if(FULL)
    return overflow;
  rear = NEXT(rear);
  entry[rear] = item;
  return success;
}
Error_code Queue::serve()
{
  if(ISEMPTY)
    return underflow;
  front = NEXT(front);
  return success;
}
Error_code Queue::retrieve(Queue_entry &item) const
{
  if(ISEMPTY)
    return underflow;
  item = entry[front];
  return success;
}

// 91
int Extended_queue::size() const
{
  return COUNT;
}

// 94
void help()
{
  cout << endl
  << "This program allows the user to enter one command" << endl
  << "(but only one) on each input line." << endl
  << "For example, if the command S is entered, then" << endl
  << "the program will serve the front of the queue." << endl << endl

  << " The valid commands are:" << endl
  << "A - Append the next input character to the extended queue" << endl
  << "S - Serve the front of the extended queue" << endl
  // << "R - Retrieve and print the front entry." << endl
  << "# - The current size of the extended queue" << endl
  // << "C - Clear the extended queue (same as delete)" << endl
  << "P - Print the extended queue" << endl
  // << "H - This help screen" << endl
  // << "Q - Quit" << endl
  << "Press < Enter > to continue." << flush;

  // The following tries to get "< Enter >"
  char c;
  do {
    cin.get(c);
  } while (c != '\n');
}

char get_command(){
  char command[8]={0};
  scanf("%s",command); // Stopping at the first whitespace character found
  return command[0];
}

// 95
bool do_command(char c, Extended_queue &test_queue)
{
  bool continue_input = true;
  Queue_entry x=0;
  Queue copy_queue=test_queue;

  switch (c) {
  // case 'r':
  //   if (test_queue.retrieve(x) == underflow)
  //     cout << "Queue is empty." << endl;
  //   else
  //     cout << endl
  //          << "The first entry is: " << x
  //          << endl;
  //   break;
  // case 'q':
  //   cout << "Extended queue demonstration finished." << endl;
  //   continue_input = false;
  //   break;
  case 'a':
    scanf("%d",&x);
    if(test_queue.append(x)==overflow)
      cout << "Queue is full." << endl;
    break;
  case 's':
    if(test_queue.serve() == underflow)
      printf("Queue is empty.\n");
    break;
  case '#':
    printf("Size %d\n",test_queue.size());
    break;
  case 'p':
    printf("F ");
    while(!copy_queue.empty()){
      copy_queue.retrieve(x);
      printf("%d ",x);
      copy_queue.serve();
    }
    printf("R\n");
    break;
  default:
    printf("Unimplemented\n");
    exit(1);
  }
  return continue_input;
}

//93
int main()
{
  Extended_queue test_queue;
  help (); // introduction();
  while (do_command(get_command(), test_queue));
}


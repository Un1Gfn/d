// 138
// 139
// 140

#include <stddef.h> // NULL, size_t, ...

enum Error_code{success,overflow,underflow};

typedef char Queue_entry;
typedef Queue_entry Node_entry;

struct Node {
  Node_entry entry;
  Node *next;
  Node();
  Node(Node_entry item, Node *add_on = NULL);
};

class Queue {
public:
  Queue(); // pass
  bool empty() const; // pass
  Error_code append(const Queue_entry &item); // pass
  Error_code serve(); // pass
  Error_code retrieve(Queue_entry &item) const; // pass
  ~Queue(); // pass
  Queue(const Queue &original);
  void operator=(const Queue &original);
protected:
  Node *front, *rear;
};

class Extended_queue: public Queue {
public:
  int size() const;
  Error_code serve_and_retrieve(Queue_entry &item); // pass
};

class Super_queue: public Extended_queue {
public:
  void print()const;
};
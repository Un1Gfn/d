// 123
// 125
// 127
// 128
// 129
// 130
// 134
// 136

#include <stddef.h> // NULL, size_t, ...

enum Error_code{success,overflow,underflow};

typedef char Stack_entry;
typedef Stack_entry Node_entry;

struct Node {
  Node_entry entry;
  Node *next;
  Node();
  Node(Node_entry item, Node *add_on = NULL);
};

class Stack {
public:
  Stack();
  bool empty() const;
  Error_code push(const Stack_entry &item);
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  ~Stack();
  Stack(const Stack &original);
  void operator = (const Stack &original);
protected:
  Node *top_node;
};

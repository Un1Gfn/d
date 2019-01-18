// 221
// 223
// 224
// 226

template<class Node_entry>
struct Node{
  // data members
  Node_entry entry;
  Node<Node_entry> *next;
  // constructors
  Node();
  Node(Node_entry, Node<Node_entry> *link = NULL);
};

template<class List_entry>
class List {
public:
  ~List();
  List(const List<List_entry> &copy);
  void operator = (const List<List_entry> &copy);
protected:
  int count;
  Node<List_entry> *head;
  Node<List_entry> *set_position(int position) const;
};

template<class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const
{
  Node<List_entry> *q = head;
  for (int i = 0; i < position; i++ ) q = q->next;
  return q;
}

template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
  if (position < 0 || position > count)
    return range_error;
  Node<List_entry> *new_node, *previous, *following;
  if (position > 0) {
    previous = set_position(position - 1);
    following = previous->next;
  }
  else
    following = head;
  new_node = new Node<List_entry>(x, following);
  if (new_node == NULL)
    return overflow;
  if (position == 0)
    head = new_node;
  else
    previous->next = new_node;
  count++;
  return success;
}

// template<class List_entry>
// class List {
// public:
// // Add specifications for the methods of the list ADT.
// // Add methods to replace the compiler-generated defaults.
// protected:
// // Data members for the linked-list implementation with
// // current position follow:
// int count;
// mutable int current_position;
// Node<List_entry> *head;
// mutable Node<List_entry> *current;
// // Auxiliary function to locate list positions follows:
// void set_position(int position) const;
// };

// template<class List_entry>
// void List<List_entry>::set_position(int position) const
// /* Pre: position is a valid position in the List: 0 ≤ position < count.
// Post: The current Node pointer references the Node at position. */
// {
// if (position < current_position) { // must start over at head of list
// current_position = 0;
// current = head;
// }
// for (; current_position != position; current_position ++ )
// current = current->next;
// }

#pragma once
#include "Error_code.h"
#include <initializer_list>

using namespace std;

#ifdef CONTIGUOUS

  const int max_list=50;

  template <class List_entry>
  class List {
  public:
    List():count(0){}
    List(std::initializer_list<List_entry>);
    int size() const{return count;};
    bool full()const{return count==max_list;}
    void print()const;
    void traverse(void (*visit)(List_entry &));
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code insert(int position, const List_entry &x);
    // bool empty() const;
    // void clear();
  protected:
    int count;
    List_entry entry[max_list];
  };

  template <class List_entry>
  List<List_entry>::List(initializer_list<List_entry> il):count(0){
    for(auto beg=il.begin();beg!=il.end();++beg){
      entry[count]=*beg;
      ++count;
    }
  }

  template <class List_entry>
  void List<List_entry>::print()const
  {
    for (int i = 0; i < count; i ++ )
      cout<<entry[i]<<" ";
    cout<<endl;
  }
  
  template <class List_entry>
  void List<List_entry>::traverse(void (*visit)(List_entry &))
  {
    for (int i = 0; i < count; i ++ )
    (*visit)(entry[i]);
  }

  template <class List_entry>
  Error_code List<List_entry>::retrieve(int position, List_entry &x) const{
    if(position<0||position>count-1)
      return Error_code::range_error;
    x=entry[position];
    return success;
  }

  template <class List_entry>
  Error_code List<List_entry>::replace(int position, const List_entry &x){
    if(position<0||position>count-1)
      return Error_code::range_error;
    entry[position]=x;
    return success;
  }

  template <class List_entry>
  Error_code List<List_entry>::remove(int position, List_entry &x){
    if (position < 0 || position > count-1)
      return Error_code::range_error;
    x=entry[position];
    for(int i=position;i<=count-1;++i)
      entry[i]=entry[i+1];
    --count;
    return success;
  }

  template <class List_entry>
  Error_code List<List_entry>::insert(int position, const List_entry &x)
  {
    if (full())
      return overflow;
    if (position < 0 || position > count)
      return Error_code::range_error;
    for (int i = count - 1; i >= position; i-- )
      entry[i + 1] = entry[i];
    entry[position] = x;
    count++ ;
    return success;
  }

#endif

#ifdef LINKED

  template<class Node_entry>
  struct Node{
    // data members
    Node_entry entry;
    Node<Node_entry> *next;
    // constructors
    Node();
    Node(Node_entry, Node<Node_entry> *link = nullptr);
  };

  template <class List_entry>
  class List {
  public:
    ~List();
    List(const List<List_entry> &copy);
    void operator = (const List<List_entry> &copy);
    List();
    int size() const;
    bool full() const;
    void traverse(void (*visit)(List_entry &));
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code insert(int position, const List_entry &x);
    // bool empty() const;
    // void clear();
  protected:
    int count;
    Node<List_entry> *head;
    mutable int current_position;
    mutable Node<List_entry> *current;
    // Node<List_entry> *set_position(int position) const;
    void set_position(int position) const;
  };

  // template<class List_entry>
  // Node<List_entry> *List<List_entry>::set_position(int position) const
  // {
  //   Node<List_entry> *q = head;
  //   for (int i = 0; i < position; i++ ) q = q->next;
  //   return q;
  // }

  template<class List_entry>
  Error_code List<List_entry>::insert(int position, const List_entry &x)
  {
    if (position < 0 || position > count)
      return Error_code::range_error;
    Node<List_entry> *new_node, *previous, *following;
    if (position > 0) {
      previous = set_position(position - 1);
      following = previous->next;
    }
    else
      following = head;
    new_node = new Node<List_entry>(x, following);
    if (new_node == nullptr)
      return overflow;
    if (position == 0)
      head = new_node;
    else
      previous->next = new_node;
    count++;
    return success;
  }

  template<class List_entry>
  void List<List_entry>::set_position(int position) const
  {
    if (position < current_position) {
      current_position = 0;
      current = head;
    }
    for (; current_position != position; current_position ++ )
      current = current->next;
  }

  template<class List_entry>
  int List<List_entry>::size() const
  {
    return count;
  }

#endif
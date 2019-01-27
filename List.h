#pragma once
#include "Error_code.h"
#include <initializer_list>
#include <iostream>

using namespace std;

#ifdef CONTIGUOUS
const int max_list=50;
#endif

#ifdef LINKED
template<class Node_entry>
struct Node{
  // data members
  Node_entry entry;
  Node<Node_entry> *next;
  // constructors
  Node():entry(0),next(nullptr){}
  Node(const Node_entry &e, Node<Node_entry> *link = nullptr):entry(e),next(link){}
};
#endif

template <class List_entry>
class List {
public:
  ~List();
  List();
  List(std::initializer_list<List_entry>);
#ifdef LINKED
  List(const List<List_entry> &copy) = delete;
  void operator = (const List<List_entry> &copy) = delete;
#endif
#ifdef CONTIGUOUS
  bool full()const{return count==max_list;}
#endif
  int size()const{return count;};
  void print()const;
  void traverse(void (*visit)(List_entry &));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);
  // bool empty()const;
  // void clear();
protected:
  int count;
#ifdef CONTIGUOUS
  List_entry entry[max_list];
#endif
#ifdef LINKED
  Node<List_entry> *head;
  mutable int current_position;
  mutable Node<List_entry> *current;
  Node<List_entry> *set_position(int position) const;
#endif
};

#ifdef LINKED
template <class List_entry>
List<List_entry>::List():
  count(0),head(nullptr),current_position(0),current(nullptr){}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
List<List_entry>::List():count(0){}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
List<List_entry>::~List()=default;
#endif

#ifdef LINKED
template <class List_entry>
List<List_entry>::~List()
{
  while(head!=nullptr){
    Node<List_entry> *tmp=head->next;
    delete head;
    head=tmp;
  }
}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
List<List_entry>::List(initializer_list<List_entry> il):count(0){
  for(auto beg=il.begin();beg!=il.end();++beg){
    entry[count]=*beg;
    ++count;
  }
}
#endif

#ifdef LINKED
template <class List_entry>
List<List_entry>::List(initializer_list<List_entry> il):
count(il.size()),head(nullptr){
  Node<List_entry> **p=&head;
  // int i=0;
  for(auto beg=il.begin();beg!=il.end();++beg){
    // cout<<"> "<<i<<endl;
    // ++i;
    *p=new Node<List_entry>(*beg);
    p=&((**p).next);
  }
}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
void List<List_entry>::print()const
{
  for (int i = 0; i < count; i ++ )
    cout<<entry[i]<<" ";
  cout<<endl;
}
#endif

#ifdef LINKED
template <class List_entry>
void List<List_entry>::print()const
{
  for(Node<List_entry> *p=head; p!=nullptr; p=p->next)
    cout<<p->entry<<" ";
  cout<<endl;
}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
  for (int i = 0; i < count; i ++ )
  (*visit)(entry[i]);
}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const{
  if(position<0||position>count-1)
    return Error_code::range_error;
  x=entry[position];
  return success;
}
#endif

#ifdef CONTIGUOUS
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x){
  if(position<0||position>count-1)
    return Error_code::range_error;
  entry[position]=x;
  return success;
}
#endif

#ifdef CONTIGUOUS
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
#endif

#ifdef CONTIGUOUS
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x){
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
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x){
  if (position < 0 || position > count)
    return Error_code::range_error;
  Node<List_entry> *new_node, *previous, *following;
  if (position==0) 
    following = head;
  else{
    previous = set_position(position - 1);
    following = previous->next;
  }
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
#endif

#ifdef LINKED
template<class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const
{
  if (current==nullptr||position<current_position) {
    current_position = 0;
    current = head;
  }
  for (; current_position != position; current_position ++ )
    current = current->next;
  return current;
}
#endif
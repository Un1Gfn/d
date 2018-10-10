#include <stdio.h>
#include <stdlib.h>
#include "05_LQ.h"

// Implementation of the Node struct

Node::Node()
{
  next = NULL;
}

Node::Node(Node_entry item, Node *add_on)
{
  entry = item;
  next = add_on;
}

// Implementation of the Queue class

Queue::Queue()
{
  front = rear = NULL;
}

bool Queue::empty()const
{
  if( (front!=NULL&&rear==NULL) || (front==NULL&&rear!=NULL) ){
    printf("Front %s\n",front==NULL?"NULL":" ");
    printf("Rear  %s\n",rear==NULL?"NULL":" ");
    printf("Error");
    exit(1);
  }
  return front==NULL&&rear==NULL;
}

Error_code Queue::append(const Queue_entry &item)
{
  Node *new_rear = new Node(item);
  if (new_rear == NULL) return overflow;
  if (rear == NULL) front = rear = new_rear;
  else {
    rear->next = new_rear;
    rear = new_rear;
  }
  return success;
}

Error_code Queue::serve()
{
  if (front == NULL) return underflow;
  Node *old_front = front;
  front = old_front->next;
  if (front == NULL) rear = NULL;
  delete old_front;
  return success;
}

Error_code Queue::retrieve(Queue_entry &item) const{
  if(empty())
    return underflow;
  item=front->entry;
  return success;
}

Queue::~Queue(){
  while(front!=NULL){
    Node* old_front=front;
    front=front->next;
    delete old_front;
  }
}

// Implementation of the Extended_queue class

int Extended_queue::size() const
{
  Node *window = front;
  int count = 0;
  while (window != NULL) {
    window = window->next;
    count++ ;
  }
  return count;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item){
  if(empty())
    return underflow;
  item=front->entry;
  Node* old_front=front;
  front=front->next;
  delete old_front;
  return success;
}

// Implementation of the Super_queue class

void Super_queue::print()const{
  printf("FRONT ");
  for (Node *p=front;p!=NULL;p=p->next)
    printf("%c ",p->entry);
  printf("REAR\n");
}
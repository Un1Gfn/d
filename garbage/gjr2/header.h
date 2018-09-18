// header.h
#ifndef HEADER_H
#define HEADER_H
#include<stdexcept>
#include<iostream>
#include<array>
#include<vector>
using namespace std;
template<typename T>
struct Node{
	T val;
	Node* next;
	Node(const T t,Node* p):val(t),next(p){}
};
template<typename T>
class Stack{
public:
	typedef size_t size_type;
	typedef Node<T> node_type;
private:
	node_type* p_top;
	size_type size_;
public:
	Stack():p_top(nullptr),size_(0){}
	T top()const throw(runtime_error){
		if(!size())
			throw runtime_error("get top of empty stack");
		return p_top->val;
	}
	void pop()throw(runtime_error){
		if(!size())
			throw runtime_error("pop from empty stack");
		node_type* holder=p_top->next;
		delete p_top;
		p_top=holder;
		--size_;
	}
	void push(const T ele){
		p_top=new node_type(ele,p_top);
		++size_;
	}
	size_type size()const{
		return size_;
	}
	void display()const{
		cout<<"<top> ";
		if(size_==0)
			cout<<"empty";
		else{
			node_type* p=p_top;
			for(size_type i=0;i!=size_;++i){
				cout<<p->val<<" ";
				p=p->next;
			}

		}
		cout<<"<bottom>"<<endl;
	}
};
template<typename T,int I>
class Queue{
public:
	typedef int size_type;
private:
	// rr:rear+1
	size_type size_,f,rr;
	array<T,I> data;
	void increase(size_type& pos)const{
			++pos;
			pos%=I;
	}
	size_type increase(size_type pos,size_type n)const{
		while(n--){
			++pos;
			pos%=I;
		}
		return pos;
	}
public:
	Queue():size_(0),f(0),rr(0){}
	void enqueue(const T t)throw(runtime_error){
		if(size_==I)
			throw runtime_error("enqueue when full");
		data[rr]=t;
		increase(rr);
		++size_;
	}
	void dequeue()throw(runtime_error){
		if(size_==0)
			throw runtime_error("dequeue when empty");
		increase(f);
		--size_;
	}
	T front()const throw(runtime_error){
		if(size_==0)
			throw runtime_error("get front when empty");
		return data[f];
	}
	T rear()const throw(runtime_error){
		if(size_==0)
			throw runtime_error("get rear when empty");
		return data[rr-1];
	}
	size_type size()const{
		return size_;
	}
	void display()const{
		cout<<"<front> ";
		if(size_==0)
			cout<<"empty";
		else{
			for(size_type i=0;i!=size_;++i)
				cout<<data[increase(f,i)]<<" ";
		}
		cout<<"<rear>"<<endl;
	}
};

#endif
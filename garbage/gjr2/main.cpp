// main.cpp
#include "header.h"
// run "g++ -std=c++11 -D ONE main.cpp" for the first test
#ifdef ONE
	int main(){
		Stack<char> s;
		char arr[]={'C','O','M','P','U','T','E','R'};
		for(char ch:arr){
			s.push(ch);
			cout<<"push "<<ch<<", top: "<<s.top()<<endl;
		}
		try{
			for(char ch:arr){
				s.pop();
				cout<<"pop   "<<", top: "<<s.top()<<endl;
			}
			s.pop();
			// cout<<"pop   "<<", top: "<<s.top()<<endl;
		}catch(runtime_error err){
			cout<<err.what()<<endl;
		}
		return 0;
	}
#endif
// run "g++ -std=c++11 -D TWO main.cpp"
// for the second test
#ifdef TWO
	int main(){
		Queue<char,4> q;
		q.display();
		for(char ch:{'C','O','M','P'})
			q.enqueue(ch);
		// cout<<q.size()<<endl;
		q.display();
		for(char ch:{'C','O','M'})
			q.dequeue();
		q.display();
		for(char ch:{'U','T','E'})
			q.enqueue(ch);
		q.display();
		q.dequeue();
		q.display();
		q.enqueue('R');
		q.display();
	}
#endif
// run "g++ -std=c++11 -D THERE main.cpp"
// for the third test
#ifdef THREE
	int main(){
		Stack<char> s;
		Queue<char,10> q;
		cout<<"command consists of a letter and a sign"<<endl;
		cout<<"first letter  : s for stack, q for queue"<<endl;
		cout<<"second letter : + for adding an element  , - for removing an element"<<endl;
		cout<<"enter q to quit"<<endl;
		while(1){
			string op;
			cout<<"input command: ";
			getline(cin,op);
			if(!cin||op=="q")
				break;
			else if(op=="s+"){
				char ch=0;
				cout<<"element to add to stack: ";
				cin>>ch;
				s.push(ch);
				s.display();
			}
			else if(op=="q+"){
				char ch=0;
				cout<<"element to add to queue: ";
				cin>>ch;
				q.enqueue(ch);
				q.display();
			}
			else if(op=="s-"){
				s.pop();
				s.display();
			}
			else if(op=="q-"){
				q.dequeue();
				q.display();
			}
		}
		return 0;
	}
#endif

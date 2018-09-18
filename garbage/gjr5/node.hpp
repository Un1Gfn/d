#ifndef NODE
#define NODE
using namespace std;
template < class Entry >
struct Binary_node {
	// data members:
	Entry data;
	Binary_node< Entry > *left;
	Binary_node< Entry > *right;
	// constructors:
	Binary_node( ):data(0),left(0),right(0){}
	Binary_node(const Entry &x):data(x),left(0),right(0){}
};
#endif
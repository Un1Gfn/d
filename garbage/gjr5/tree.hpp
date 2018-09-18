#ifndef TREE
#define TREE
#include<stdexcept>
#include<algorithm>
#include"node.hpp"
using namespace std;
enum Error_code{success,duplicate_error};
template < class Entry >
class Binary_tree {
public:
	Binary_tree( )
	/* Post: An empty binary tree has been created. */
	{
		root = NULL;
	}
	bool empty( ) const
	/* Post: A result of true is returned if the binary tree is empty. Otherwise, false is
	returned. */
	{
		return root == NULL;
	}
	void preorder(void (*visit)(Entry &))
	/* Post: The tree has been been traversed in infix order sequence.
	Uses: The function recursive_preorder */
	{
		recursive_preorder(root, visit);
	}
	void inorder(void (*visit)(Entry &))
	/* Post: The tree has been been traversed in infix order sequence.
	Uses: The function recursive_inorder */
	{
		recursive_inorder(root, visit);
	}
	void postorder(void (*visit)(Entry &))
	/* Post: The tree has been been traversed in infix order sequence.
	Uses: The function recursive_postorder */
	{
		recursive_postorder(root, visit);
	}
	Error_code insert(const Entry &new_data)
	{
		return search_and_insert(root, new_data);
	}
	void flip(){
		recursive_flip(root);
	}
	void release(Binary_node<Entry>*& tmp)
	{
		if(tmp==nullptr)
			return;
		release(tmp->left);
		release(tmp->right);
		if(tmp->left||tmp->right)
			throw runtime_error("Fail to release someone's children");
		if(!tmp->left&&!tmp->right){
			delete tmp;
			tmp=nullptr;
		}
		// auto lambda=(){
		// 	for(auto& p:{e.left,e.right}){
		// 		if(p==nullptr)
		// 			return;
		// 		if(p->left==nullptr&&p->right==nullptr){
		// 			delete p;
		// 			p=nullptr;
		// 		}
		// 	}
		// });

	}
	void clear()
	{
		release(root);
		root=nullptr;
	}
	// void insert(const Entry &);
	~Binary_tree( ){
		clear();
		root=nullptr;
	}
protected:
	// Add auxiliary function prototypes here.
	Binary_node< Entry > *root;
	void recursive_inorder(Binary_node< Entry > *sub_root,void (*visit)(Entry &))
	/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
	Post: The subtree has been been traversed in inorder sequence.
	Uses: The function recursive_inorder recursively */
	{
		if (sub_root != NULL) {
			recursive_inorder(sub_root->left, visit);
			(*visit)(sub_root->data);
			recursive_inorder(sub_root->right, visit);
		}
	}
	void recursive_preorder(Binary_node< Entry > *sub_root,void (*visit)(Entry &))
	/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
	Post: The subtree has been been traversed in preorder sequence.
	Uses: The function recursive_preorder recursively */
	{
		if (sub_root != NULL) {
			(*visit)(sub_root->data);
			recursive_preorder(sub_root->left, visit);
			recursive_preorder(sub_root->right, visit);
		}
	}
	void recursive_postorder(Binary_node< Entry > *sub_root,void (*visit)(Entry &))
	/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
	Post: The subtree has been been traversed in postorder sequence.
	Uses: The function recursive_postorder recursively */
	{
		if (sub_root != NULL) {
			recursive_postorder(sub_root->left, visit);
			recursive_postorder(sub_root->right, visit);
			(*visit)(sub_root->data)
;		}
	}
	void recursive_flip(Binary_node<Entry>* p)
	{
		if(!p)
			return;
		std::swap(p->left,p->right);
		recursive_flip(p->left);
		recursive_flip(p->right);
	}
	// void recursive_postorder1(Binary_node< Entry > *sub_root,void (*visit)(Entry &))
	//  /*Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
	// Post: The subtree has been been traversed in preorder sequence.
	// Uses: The function recursive_preorder recursively */
	// {
	// 	if (sub_root != NULL) {
	// 		auto* tmp_l=sub_root->left;
	// 		auto* tmp_r=sub_root->right;
			// recursive_preorder(tmp_l, visit);
	// 		recursive_preorder(tmp_r, visit);
	// 		(*visit)(sub_root->data);
	// 	}
	// }
	Error_code search_and_insert(Binary_node< Entry > * &sub_root, const Entry &new_data)
	{
		if (sub_root == NULL) {
			sub_root = new Binary_node< Entry >(new_data);
			return success;
		}
		else if (new_data < sub_root->data)
			return search_and_insert(sub_root->left, new_data);
		else if (new_data > sub_root->data)
			return search_and_insert(sub_root->right, new_data);
		else
			return duplicate_error;
	}
};
#endif
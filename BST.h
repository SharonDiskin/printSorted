#ifndef __BST
#define __BST

#include <iostream>
using namespace std;
#include "TreeNode.h"

class BST
{
private:
	TreeNode* root;

public:
	BST(TreeNode* root = nullptr) {}; //C'tor

	//Binary tree methods
	bool isEmpty();
	void makeEmpty(TreeNode* root);
	TreeNode* insert(TreeNode* root, Data data, int& counter);
	TreeNode* find(TreeNode* root, int id);
	TreeNode* findMin(TreeNode* root);
	TreeNode* remove(TreeNode* root, int id);

	//Get, set
	TreeNode* getRoot(){ return root; };
	void setRoot(TreeNode* root) { this->root = root; };

	void printSmallerThanInOrder(TreeNode* root, int k, int& counter); //Print method to print all the nodes that are data is smaller than k

	~BST(); //D'tor

};
#endif // !__BST

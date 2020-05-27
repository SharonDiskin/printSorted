#include "BST.h"

bool BST::isEmpty() //This function check if our tree is empty
{
	return this->root == nullptr;
}

//This function delete all the nodes of a given tree
void BST::makeEmpty(TreeNode* root) 
{
	if (root == nullptr)
		return;

	makeEmpty(root->left);
	makeEmpty(root->right);
	delete root;
}

//This function find a node according to it's key value (id)
TreeNode* BST::find(TreeNode* root, int id) 
{
	if (root == nullptr)
		return nullptr;

	if (root->data.id < id)
		find(root->left, id);
	else if (root->data.id > id)
		find(root->right, id);
	
	return root;
}
//This function finds the right place for a new node, alocate a node and insert it to the tree
//The function also get a refrenced counter and check amount of comparisons overall in all the insert we do in order to create the tree
TreeNode* BST::insert(TreeNode* root, Data data, int &counter) 
{

	if (root == nullptr) //If we got to null we allocate the new node
		root = new TreeNode(data);
	
	else if (root->data.id > data.id)
	{
		counter++;
		root->left = insert(root->left, data, counter);
	}
	else
	{
		counter++;
		root->right = insert(root->right, data, counter);
	}
	return root;
}
 
//This function returns the node with the minimum value in the tree
TreeNode* BST:: findMin(TreeNode* root)
{
	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

//This function removes a node from the the tree (according to a key value)
TreeNode* BST:: remove(TreeNode* root, int id)
{
	if (root == nullptr)
		return nullptr;
	else if (id < root->data.id)
		root->left = remove(root->left, id);
	else if (id > root->data.id)
		root->right = remove(root->right, id);
	else
	{
		if (root->left == nullptr && root->right == nullptr)
			return nullptr;
		else if (root->right == nullptr) //the root only have one child		
		{
			TreeNode* res = root->left;
			delete root; //We free the root
			return res; //We return root's only child
		}
		else if (root->right == NULL)
		{
			TreeNode* res = root->left;
			delete root; //We free the root
			return res; //We return root's only child
		}

		// node with two children: Get the smallest	in the right subtree
		TreeNode* temp = findMin(root->right);

		root->data = temp->data;

		// Delete the inorder smallest
		root->right = remove(root->right, temp->data.id);
	}
	return root;
}

//This method prints all the nodes that their id is smaller than k inorder 
void BST::printSmallerThanInOrder(TreeNode* root, int k, int& counter)
{
	if (root == nullptr)
		return;
	else
	{
		printSmallerThanInOrder(root->left, k, counter);
		if (root->data.id <= k) {
			root->data.print();
			printSmallerThanInOrder(root->right, k, counter);
		}
		counter++;
	}
}

//D'tor
BST::~BST() {
	makeEmpty(root);
}

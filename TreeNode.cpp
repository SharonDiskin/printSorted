#include "TreeNode.h"

//C'tor
TreeNode:: TreeNode(Data data)
{
	this->data = data;
	this->right = nullptr;
	this->left = nullptr;
}

//No need to define a d'tor - no use of memory allocation
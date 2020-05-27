#ifndef __TREENODE
#define __TREENODE

#include "Data.h"

class TreeNode
{
private:
	Data data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode() = default;
	TreeNode(Data data);

	friend class BST;
};

#endif // !__TREENODE

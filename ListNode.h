#ifndef __LISTNODE
#define __LISTNODE

#include <iostream>
using namespace std;

#include "Data.h"

class ListNode
{
private:
	Data data;
	ListNode* next;

public:
	ListNode() = default;
	ListNode(Data data);
	Data getData();
	ListNode* getNext();
	bool setData(Data data);
	bool setNext(ListNode* next);
};

#endif // !__LISTNODE
#ifndef __LINKEDLIST
#define __LINKEDLIST

#include <iostream>
using namespace std;
#include "listnode.h"

class LinkedList
{
private:
	ListNode * head;
	ListNode* tail;

public:
	
	LinkedList(); //C'tor
	~LinkedList(); //D'tor

	//Get methods
	ListNode* getHead();
	ListNode* getTail(); 

	//Set methods
	bool setHead(ListNode* node);
	bool setTail(ListNode* node);

	//List methods
	bool isEmpty();
	void addNewNode(Data data, int& counter);
	void print();
};

#endif // !__LINKEDLIST
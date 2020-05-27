#include "listnode.h"

//C'tor
ListNode::ListNode(Data data)
{
	this->data = data;
	this->next = nullptr;
}

//Get data
Data ListNode::getData()
{
	return data;
}

//Get next
ListNode* ListNode::getNext()
{
	return next;
}

//Set data
bool ListNode::setData(Data data)
{
	this->data = data;
	return true;
}

//Set next
bool ListNode::setNext(ListNode* next)
{
	this->next = next;
	return true;
}

//No need to define a d'tor - no use of memmory allocation
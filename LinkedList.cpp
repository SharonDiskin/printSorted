#include "LinkedList.h"

//C'tor
LinkedList::LinkedList()
{
	this->head = nullptr; //We initialize head and tail at null
	this->tail = nullptr;
}


bool LinkedList::isEmpty() //This function checks if a list is empty
{
	return (this->head == nullptr);
}

ListNode* LinkedList::getHead() //get head of list
{
	return head;
}

ListNode* LinkedList::getTail() //get head of list
{
	return tail;
}

bool LinkedList::setHead(ListNode* node) //Set head of list
{
	this->head = node;
	return true;
}
bool LinkedList::setTail(ListNode* node) //Set tail of list
{
	this->tail = node;
	return true;
}

//This function add a new node in a sorted fashion
void LinkedList::addNewNode(Data data, int& counter)
{
	ListNode* newNode = new ListNode(data);
	if (isEmpty())
	{
		this->head = this->tail = newNode;
		return;
	}
	else if (this->head->getData().getId() >= data.getId())
	{
		newNode->setNext(this->head);
		setHead(newNode);
		counter++;
		return;
	}
	else
	{
		ListNode* node = head->getNext();
		ListNode* prev = head;
		counter++;
		while (node)
		{
			if (node->getData().getId() >= data.getId())
			{
				prev->setNext(newNode);
				newNode->setNext(node);
				counter++;
				return;
			}
			else
			{
				prev = node;
				node = node->getNext();
				counter++;
			}
		}
	}
	this->tail->setNext(newNode);
	setTail(newNode);
}

void deleteList(ListNode* head) //This function free the list
{
	if (head == nullptr)
		return;
	deleteList(head->getNext());
	delete head;
}

//D'tor. The d'tor uses the delete list function in order to delete all the allocated memmory
LinkedList::~LinkedList()
{
	deleteList(this->head);
}


//Print
void LinkedList::print()
{
	ListNode* node = this->head;
	while (node)
	{
		node->getData().print();
		node = node->getNext();
	}
}
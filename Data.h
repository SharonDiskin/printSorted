#ifndef __DATA
#define __DATA

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX_SIZE = 128;

class Data
{
private:
	int id;
	char name[MAX_SIZE];

public:
	//C'tor
	Data() = default;
	Data(int number, char* pName);

	//Get methods
	char* getName() { return name; };
	int getId() { return id; };

	//Set methods
	bool setId(int id);
	bool setName(char* name);

	void print();

	//Giving friendship to classes who use data
	friend class TreeNode;
	friend class BST;
};

#endif //!_DATA
/*
This OOP project was written by 
Meir Shatarkman, id: 
Sharon Diskin, id: 205379993

Input: Amount of people, a list of people (id+name), a number k
Firstly we absorb all the data to an array of people.

We sort the data in three diffrent ways:
1. We sort all the people who's id is smaller than k in a sorted linked list
2. We sort all the people in a binary search tree
3. We sort the array of people using quicksort 

Output: 
1. We have three priting functions:
NaivePrint (which prints the linked list we create)
BSTPrint (which prints all the numbers who are smaller than k in the binary search tree we create)
PrintBySort (which prints all the numbers who are smaller than k in the sorted array after we quicksort our array)

2. We print the number of comparsion each our priting function required in order to print our data sorted (and smaller than k).
---Example for such print:---
NaivePrint: 130 comparisons
BSTPrint: 200 comparisons
PrintBySort: 500 comparisons

*/

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "Data.h"
#include "LinkedList.h"
#include "BST.h"

//Prototypes
bool isUnique(Data persons[], int currSize, int id);
int NaivePrint(Data persons[], int n, int k);
int BSTPrint(Data persons[], int n, int k);
void swap(int& a, int& b);
int partition(Data* arr, int left, int right, int& counter);
void quickSort(Data* arr, int left, int right, int& counter);
int PrintBySort(Data persons[], int n, int k);

//Main
int main()
{
	int n, number, k, currSize = 0;
	char pName[MAX_SIZE];
	int naiveCount, BSTCount, sortCount;
	cin >> n;

	Data* arr = new Data[n];
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		cin.getline(pName, MAX_SIZE);

		arr[i].setId(number);

		if (!isUnique(arr, currSize ,number) || !arr[i].setName(pName)) //If the person entered doesn't have a unique Id or the person name is not in a valid format we exit the program
 		{
			cout << "invalid input\n";
			exit(1);
		}
		else
			currSize++; //We increase current size which we send to the unique id check function
		
	}
	cin >> k;

	cout << "\n----------------------Naive print------------------------ \n\n";
	naiveCount = NaivePrint(arr, n, k);

	
	cout << "\n---------------------BST print--------------------------- \n\n";
	BSTCount = BSTPrint(arr, n, k);

	cout << "\n-------------------Print by sort------------------------- \n\n";
	sortCount = PrintBySort(arr, n, k);
	

	cout << "\n\nNaivePrint: " << naiveCount << " Comparisons\n";
	cout << "BSTPrint: " << BSTCount << " Comparisons\n";
	cout << "PrintBySort: " << sortCount << " Comparisons\n";

	delete[]arr; //We free our main array

	system("pause");
}

//This function recieve an unsorted array of people and and an id number and scans the array in order to check if the id already appears in the array
//If the id given appears in the array the function return false, else it return true (=id is unique)
bool isUnique(Data persons[], int currSize, int id)
{
	for (int i = 0; i < currSize; i++)
		if (persons[i].getId() == id)
			return false;
	return true;
}

//Naive print function
int NaivePrint(Data persons[], int n, int k)
{
	LinkedList lst;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (persons[i].getId() < k)
		{
			lst.addNewNode(persons[i], counter);
		}
		counter++;
	}

	lst.print();
	return counter;
}

//Binary search tree print
int BSTPrint(Data persons[], int n, int k)
{
	BST bst;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		bst.setRoot(bst.insert(bst.getRoot(), persons[i], counter));
	}

	bst.printSmallerThanInOrder(bst.getRoot(), k, counter);
	return counter;
}

//Swap helper for pratitions
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Partition is the helper function for quicksort
int partition(Data* arr, int left, int right, int& counter)
{
	Data pivot = arr[right];    // pivot 
	int i = left - 1;  // Index of smaller element 

	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j].getId() <= pivot.getId())
		{
			i++;    // increment index of smaller element 
			swap(arr[i], arr[j]);
		}
		counter++;
	}
	swap(arr[i + 1], arr[right]);
	return (i + 1);
}

//Quick sort - helper function for "print by sort function"
void quickSort(Data* arr, int left, int right, int& counter)
{
	if (left < right)
	{
		int pivot = partition(arr, left, right, counter);

		quickSort(arr, left, pivot - 1, counter);
		quickSort(arr, pivot + 1, right, counter);
	}
}

//print by sort
int PrintBySort(Data persons[], int n, int k)
{
	int counter = 0;
	quickSort(persons, 0, n - 1, counter);
	for (int i = 0; i < n && persons[i].getId() <= k; i++)
	{
		persons[i].print();
		counter++; //We run on the array while the id value is smaller than k, so it is considered a comparsion and we increase the counter
	}

	return counter;
}

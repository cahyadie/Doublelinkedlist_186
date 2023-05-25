#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** cureent);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void SearchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->noMhs = nim;
	newNode->name = nm;


	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}
	/*inserting a node between two nodes in the list*/
	Node* current = START;	//step 1.a
	Node* previous = NULL;	//step 1.b
	while (current->next != NULL && current->next->noMhs < nim)	//step 1.c
	{
		previous = current;	//step 1.d
		current = current->next;	//step 1.e
	}
	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;	//step 4
	newNode->prev = current;	//step 5
	if (current->next != NULL)
		current->next->prev = newNode;	//step 6
	current->next = newNode;	//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;	//	step 1.a
	*current = START;	//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {	//step 1.c
		*previous = *current;	//step 1.d
		*current = (*current)->next;	//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;	//step 2
	if (previous != NULL)
		previous->next = current->next;	//step 3
	else
		START = current->next;

	delete current;	//step 4
	return true;
}

bool listEmpty() {
	return (START == NULL);
}


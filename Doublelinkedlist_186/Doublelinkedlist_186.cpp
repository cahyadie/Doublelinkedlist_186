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

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "Nlist is empty" << endl;
	else {
		cout << "\nrecords in ascending order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << "" << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is emptty" << endl;
	}
	
	else {
		cout << "\nRecord in describing order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nlist is empty" << endl;
	}
	cout << "\nEnter the roll number of the student whose record is to be deleted : ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "\nrecord not found" << endl;
	else
		cout << "\nrecord with roll number " << rollNo << "deleted " << endl;
}

void DoubleLinkedList::SearchData() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "nEnter the roll number of the student whose record you want to search : ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number : " << curr->noMhs << endl;
		cout << "\nName : " << curr->name << endl;
	}
}

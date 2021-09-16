#pragma once
#include "Node.h"

class LinkedList
{
	Node *head;
	Node *tail;

	void FreeMemory();

public:
	LinkedList();
	~LinkedList();

	void addToHead(EToll c);
	void addToTail(EToll c);
	void remove(string licence);
	int count(string type);
	double totalIncome();

	

	friend ostream& operator<<(ostream &output, const LinkedList &L);
	LinkedList & operator+=(const LinkedList & L);
	LinkedList & operator-=(const LinkedList & L);

};


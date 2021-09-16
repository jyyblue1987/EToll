#pragma once
#include "EToll.h"
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void addToHead(EToll c);
	void addToTail(EToll c);
	void remove(string licence);
	int count(string type);
	int totalIncome();

	

	friend ostream& operator<<(ostream &output, const LinkedList &L);
	LinkedList & operator+=(const LinkedList & L);
	LinkedList & operator-=(const LinkedList & L);

};


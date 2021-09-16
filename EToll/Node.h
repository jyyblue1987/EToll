#pragma once
#include "EToll.h"

class Node
{
public:
	EToll value;	// value
	Node *prev;		// Pointer To Previous Element
	Node *next;		// Pointer To Next Element

	Node();
	Node(EToll v, Node *p, Node *n);
	~Node();
};


#include "Node.h"



Node::Node()
{
}

Node::Node(EToll v, Node *p, Node *n)
{
	value = v;
	prev = p;
	next = n;
}

Node::~Node()
{
}

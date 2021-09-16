#include "LinkedList.h"
#include <string>

using namespace std;


LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}


LinkedList::~LinkedList()
{
	FreeMemory();
}

// Free the allocated memory when instance is destroyed
void LinkedList::FreeMemory()
{
	Node *t = head;
	while (t != NULL)
	{
		Node *n = t->next;
		delete t;
		t = n;
	}

	head = NULL;
	tail = NULL;
}

void LinkedList::addToHead(EToll c)
{
	Node *n = new Node(c, NULL, head);
	if (head == NULL)
		tail = n;

	head = n;
}

void LinkedList::addToTail(EToll c)
{
	Node *n = new Node(c, tail, NULL);
	if (tail == NULL)
		head = n;

	tail = n;
}

void LinkedList::remove(string licence)
{
	// find the element
	Node *t = head;
	Node *p = NULL;
	Node *n = NULL;
	while (t != NULL)
	{
		n = t->next;
		if (t->value.get_licence() == licence)	// if find element
		{
			// delete element
			if (p == NULL) // it means head
			{
				// remove head
				head = t->next;
				if (head == NULL)	// if there is no element
					tail = NULL;
				else
					head->prev = NULL;
			}
			else // middle of list
			{
				// remove element
				p->next = t->next;
				if (p->next != NULL)
					p->next->prev = p;
			}

			// free element
			delete t;
		}
		else
		{
			// save previous item
			p = t;			
		}

		t = n;
	}
}

int LinkedList::count(string type)
{
	Node *t = head;
	int n = 0;
	while (t != NULL)
	{
		if (t->value.get_type() == type)
			n++;
		t = t->next;
	}

	return n;
}


double LinkedList::totalIncome()
{
	Node *t = head;
	double total = 0;
	while (t != NULL)
	{
		total += t->value.get_charge();
		t = t->next;
	}

	return 0;
}

ostream& operator<<(ostream &output, const LinkedList &L) 
{
	Node *t = L.head;
	
	while (t != NULL)
	{
		output << "  (" << t->value.get_licence() << "," << t->value.get_type() << ")";
		t = t->next;
	}
	
	return output;
}

LinkedList& LinkedList::operator+=(const LinkedList& L)
{
	Node *t = L.head;
	while (t != NULL)
	{
		addToTail(t->value);
		t = t->next;
	}

	return *this;
}

LinkedList& LinkedList::operator-=(const LinkedList& L)
{
	Node *t = L.head;
	while (t != NULL)
	{
		remove(t->value.get_licence());
		t = t->next;
	}

	return *this;
}
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
	else
		head->prev = n;

	head = n;
}

void LinkedList::addToTail(EToll c)
{
	Node *n = new Node(c, tail, NULL);
	if (tail == NULL)
		head = n;
	else
		tail->next = n;

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

	return total;
}

void sortedInsert(Node** head_ref, Node* newNode)
{
	Node* t;

	// if list is empty
	if (*head_ref == NULL)
		*head_ref = newNode;

	// if the node is to be inserted at the beginning
	// of the doubly linked list
	else if ((*head_ref)->value.get_licence() >= newNode->value.get_licence()) {
		newNode->next = *head_ref;
		newNode->next->prev = newNode;
		*head_ref = newNode;
	}

	else {
		t = *head_ref;

		// locate the node after which the new node
		// is to be inserted
		while (t->next != NULL &&
			t->next->value.get_licence() < newNode->value.get_licence())
			t = t->next;

		/*Make the appropriate links */

		newNode->next = t->next;

		// if the new node is not inserted
		// at the end of the list
		if (t->next != NULL)
			newNode->next->prev = newNode;

		t->next = newNode;
		newNode->prev = t;
	}
}

void LinkedList::order()
{
	// Initialize 'sorted' - a sorted doubly linked list
	Node* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	Node* t = head;
	while (t != NULL) {

		// Store next for next iteration
		Node* n = t->next;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		t->prev = t->next = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, t);

		// Update current
		t = n;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;

	// update tail
	t = head;
	tail = NULL;
	while (t != NULL)
	{
		tail = t;
		t = t->next;
	}
}

ostream& operator<<(ostream &output, const LinkedList &L) 
{
	Node *t = L.head;
	if (t == NULL)
	{
		output << "List is empty.";
		return output;
	}
	
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
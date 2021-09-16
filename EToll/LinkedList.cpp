#include "LinkedList.h"
#include <string>

using namespace std;


LinkedList::LinkedList()
{
}


LinkedList::~LinkedList()
{
}


void LinkedList::addToHead(EToll c)
{

}

void LinkedList::addToTail(EToll c)
{

}

void LinkedList::remove(string licence)
{

}

int LinkedList::count(string type)
{
	return 0;
}


int LinkedList::totalIncome()
{
	return 0;
}

ostream& operator<<(ostream &output, const LinkedList &L) 
{

	//output << "F : " << D.feet << " I : " << D.inches;
	return output;
}

LinkedList& LinkedList::operator+=(const LinkedList& L)
{

	//this->m_iNumber += rhs.m_iNumber;
	return *this;
}

LinkedList& LinkedList::operator-=(const LinkedList& L)
{

	//this->m_iNumber += rhs.m_iNumber;
	return *this;
}
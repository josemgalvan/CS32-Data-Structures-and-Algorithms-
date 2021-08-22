#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head=nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs) //copy constructor
{
	head = new Node;
	Node* ptr = rhs.head;
	Node* copier = head;
	while (ptr->next != nullptr)
	{
		copier->value = ptr->value;
		copier->next = ptr->next;
		ptr = ptr->next;
		copier->next = new Node;
		copier = copier->next;
	}
	copier->next = nullptr;
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* n = temp->next; //gets new address
		delete temp; // deletes temp
		temp = n;
	}
}
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	{
		if (&rhs != this)
		{
			LinkedList T(rhs);
			swap(T);
		}

		return *this;
	}

}

void LinkedList::printList() const
{
	Node* ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->next == nullptr)
		{
			cout << ptr->value<<endl;
		}
		else
		{
			cout << ptr->value << " ";
		}
		ptr = ptr->next;
	}
}

bool LinkedList::get(int i, ItemType& item) const
{
	if(head==nullptr)
		return false;
	else
	{
		Node* ptr = head;
		int cnt = 0;
		while (ptr != nullptr)
		if (cnt== i)
		{
			item=ptr->value;
			//ptr->value = item;
			return true;
		}
		else
		{
			cnt++;
			ptr = ptr->next;
		}
	}
	return false;
}

void LinkedList::insertToFront(const ItemType& val)
{
	Node* p;
	p = new Node;
	p->value = val;
	p->next = head;
	head = p;
}

int LinkedList::size() const
{
	Node* p=head;
	int cnt = 0;
	while (p != nullptr)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void LinkedList::reverseList()
{
	
	if (head == nullptr)// theres no list to reverse
		return;
	else
	{
		Node* p=nullptr;
		Node* C = head;
		while (C != nullptr)
		{
			Node* f = C->next;
			C->next =p;
			p = C;
			C = f;	
		}
		head = p;
	}
}
void LinkedList::rev(Node* head, int Size) const
{
	Node* ptr = head;
	int cnt = 1;
	while (ptr->next != nullptr && cnt<Size)
	{
		cnt++;
		ptr = ptr->next;
	}
	if (cnt == 1)
	{
		cout << ptr->value << endl;
	}
	else
	cout << ptr->value << " ";
}
void LinkedList::printReverse() const
{
	Node* ref = head;
	int SI = size(); //size
	int refN = SI;
	int cnt1 = 0;
	while (cnt1<SI)
	{
		rev(ref,refN);
		cnt1++;
		refN--; //make size smaller since we just printed one out and since we cant edit the linked list
	}
}

void LinkedList::append(const LinkedList& other)
{
	Node* p = head;
	if (head != nullptr)
	{
		while (p->next != nullptr)
		{
			p = p->next; //find the last struct
		}
	}
	LinkedList sub(other); // copy construct a new list which will be appended 
	p->next = sub.head;   // attach end of one list to the beginning of the other 
	sub.head = nullptr;   //point head of the copy constructed to null.
}
void LinkedList::swap(LinkedList& other)
{
	Node* temp = head;
	head = other.head;
	other.head=temp;
	temp = nullptr;
}
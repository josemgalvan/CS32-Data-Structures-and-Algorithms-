#include "OnlineDating.h"
#include <string>
using namespace std;


OnlineDating::OnlineDating()
{
	head = nullptr;
	//head->prev = nullptr; //initialize the prev to point to the nullptr
	//new Node;
}

OnlineDating::~OnlineDating()
{
	Node* p = head;
	while (p != nullptr)
	{
		Node* temp = p->next;
		delete p;
		p = temp;
	}
}

OnlineDating::OnlineDating(const OnlineDating& other)
{
	head = new Node;
	Node* ptr = other.head;
	Node* copier = head;
	if (ptr != nullptr) // tests if the list is empty
	{
		while (ptr->next != nullptr)
		{
			copier->firstName = ptr->firstName;
			copier->lastName = ptr->lastName;
			copier->data = ptr->data;
			copier->next = ptr->next;
			copier->prev = ptr->prev;
			ptr = ptr->next;
			copier->next = new Node;
			copier = copier->next;
		}
		copier->firstName = ptr->firstName;
		copier->lastName = ptr->lastName;
		copier->data = ptr->data;
		copier->next = nullptr;
		copier->prev = ptr->prev;
	}
	else //ptr is equal to the nullptr
	{
		head = nullptr;
	}
}

const OnlineDating& OnlineDating::operator=(const OnlineDating& other)
{
	if (this != &other)
	{
		OnlineDating temp(other);
		tradeMatches(temp);
		return *this;
	}
	return *this;
}
bool OnlineDating::noMatches() const // Return true if the OnlineDating list is empty, otherwise false.
{
	if (head == nullptr)
		return true;
	else
		return false;
}

int OnlineDating::howManyMatches() const
{
	int cnt = 0;
	if (head == nullptr)
		return 0;
	else
	{
		Node* ptr = head;
		while (ptr!= nullptr)
		{
			ptr = ptr->next;
			cnt++;
		}
		return cnt;
	}
}
bool OnlineDating::makeMatch(const std::string& firstName, const std::string&
	lastName, const OnlineType& value)
{
	if (someoneAmongMatches(firstName, lastName)) // if this returns true then there is a match 
		return false;
	else if (head == nullptr)//name is not in list
	{
		head = new Node;
		head->firstName = firstName;
		head->lastName = lastName;
		head->data = value;
		head->next = nullptr;
		head->prev = nullptr;
		return true;
	}
	/*else
		if (ptr == nullptr) // no list just place it in the beginning of it
		{
			ptr = new Node;
			ptr->next = nullptr;
			ptr->firstName = firstName;
			ptr->lastName = lastName;
			ptr->data = value;
			ptr->prev = nullptr;
		} */
	else // list has contents
	{
		Node* ptr = head;
		Node* p = head;
		while (ptr != nullptr)
		{
			if (ptr->lastName < lastName)// if current last name is smaller then iterate
			{
				if (ptr->next == nullptr) //we are at the end
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = nullptr;
					temp->prev = p;
					p->next = temp; // figure out how to point to it correcg
					return true;
				}
				else if (ptr->next->lastName > lastName)
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = p->next;
					temp->prev = p;
					p->next = temp; // figure out how to point to it correcg
					return true;
				}
				else
					p = ptr = ptr->next;
				continue;
			}
			else if (ptr->lastName == lastName) //last names match now we need to see which one precedes each other in first names
			{
				if (ptr->next != nullptr)
				{
					while (ptr->next != nullptr)
					{
						if (ptr->firstName < firstName && ptr->next->lastName> lastName) // if current first name is smaller iterate
						{
							Node* temp = new Node;
							temp->firstName = firstName;
							temp->lastName = lastName;
							temp->data = value;   // creating and storing info in new node
							temp->prev = ptr;
							temp->next = ptr->next;
							ptr->next->prev = temp;
							ptr->next = temp;   // figure out how to point to it correctly
							return true;
						}
						else if (ptr->firstName > firstName && ptr->prev->firstName < firstName) //current first name is bigger than input first name and smaller than previous first name
						{
							Node* temp = new Node;
							temp->firstName = firstName;
							temp->lastName = lastName;
							temp->data = value;   // creating and storing info in new node
							temp->next = ptr;
							temp->prev = ptr->prev;
							ptr->prev->next = temp; // figure out how to point to it correctly
							ptr->prev = temp;
							return true;
						}
						else
						{
							p = ptr = ptr->next;
							continue;
						}
					}
				}
				else if (ptr->firstName > firstName) //current first name is bigger than input first name and smaller than previous first name
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = ptr;
					temp->prev = ptr->prev;
					ptr->prev->next = temp; // figure out how to point to it correctly
					ptr->prev = temp;
					return true;
				}
				else if (ptr->firstName < firstName)
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = nullptr;
					temp->prev = ptr;
					ptr->next = temp;
					return true;
				}
			}
			else if (ptr->lastName > lastName)
			{
				if (ptr->next == nullptr || ptr->prev == nullptr)// we are at the end or beginning of the list, place new node in front
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = ptr;
					temp->prev = nullptr;
					ptr->prev = temp; // figure out how to point to it correctly
					head = temp;
					return true;
				}
				else if (ptr->lastName > lastName && ptr->prev->lastName < lastName) //current last name is bigger than input last name and smaller than previous last name)
				{
					Node* temp = new Node;
					temp->firstName = firstName;
					temp->lastName = lastName;
					temp->data = value;   // creating and storing info in new node
					temp->next = ptr;
					temp->prev = ptr->prev;
					ptr->prev->next = temp; // figure out how to point to it correctly
					ptr->prev = temp;
					return true;
				}
			}
			else
				p = ptr = ptr->next;
		}
	}
	return true;
}

bool OnlineDating::transformMatch(const std::string& firstName, const
	std::string& lastName, const OnlineType& value)
{
	if (someoneAmongMatches(firstName, lastName)) //returns true if full name is in list
	{
		Node* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->firstName == firstName && ptr->lastName == lastName)
				break;
			else
			{
				ptr = ptr->next;
			}
		}
		ptr->data = value; // chnages value
		return true;
	}
	else
	{
		return false;
	}
}

bool OnlineDating::makeOrTransform(const std::string& firstName, const
	std::string& lastName, const OnlineType& value)
{
	if (someoneAmongMatches(firstName, lastName))
	{
		transformMatch(firstName, lastName, value);
		return true;
	}
	else
	{
		makeMatch(firstName, lastName, value);//adds it to the list
		return true;
	}
}

bool OnlineDating::blockPreviousMatch(const std::string& firstName, const
	std::string& lastName)
{
	if (someoneAmongMatches(firstName, lastName)) // true if it is in the list
	{
		Node* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->firstName == firstName && ptr->lastName == lastName)
			{
				break;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		if (ptr->next == nullptr && ptr->prev == nullptr)
		{
			head = nullptr;
			delete ptr;
			ptr = nullptr;
			return true;
		}
		else if (ptr->prev == nullptr)
		{
			head = ptr->next;
			ptr->next->prev = nullptr;
		}
		else if (ptr->next == nullptr)
		{
			ptr->prev->next = nullptr;
			ptr->next = nullptr;
		}
		else
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
		}
		delete ptr;
		return true;
	}
	else // it is not in the list
		return false;
}
bool OnlineDating::someoneAmongMatches(const std::string& firstName, const
	std::string& lastName) const
{
	Node* ptr = head;
	if (ptr == nullptr)// this means that there are no matches
	{
		return false;
	}
	else
	{
		while (ptr != nullptr)
		{
			if (ptr->firstName == firstName && ptr->lastName == lastName)
				return true; //if both the first name and last name match then it will return true
			else
				ptr = ptr->next; //if it ddint match it will check the next node
		}
		return false; //left the while loop hence it didnt find it
	}
}
bool OnlineDating::lookAtMatches(const std::string& firstName, const
	std::string& lastName, OnlineType& value) const
{
	if (someoneAmongMatches(firstName, lastName)) /// true if the full name is in the list;
	{
		Node* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->firstName == firstName && ptr->lastName == lastName)
				break;
			else
				ptr = ptr->next;
		}
		value = ptr->data;
		return true;
	}
	else // not in the list
	{
		return false;
	}
}
bool OnlineDating::confirmMatch(int i, std::string& firstName, std::string&
	lastName, OnlineType& value) const
{
	if (i >= 0 && i < howManyMatches())
	{
		Node* ptr = head;
		int counter = 0;
		while (counter != i && ptr != nullptr)
		{
			ptr = ptr->next;
			counter++;
		} // leaves the while loop when counter equals i
		firstName = ptr->firstName;
		lastName = ptr->lastName;
		value = ptr->data;
		return true;
	}
	else // i is not within the scope of the list
	{
		return false;
	}
}
void OnlineDating::tradeMatches(OnlineDating& other)
{
	Node* temp = other.head;
	other.head = head;
	head = temp;


	return;
}


/// NON-CLASS Functions/////////
bool mergeMatches(const OnlineDating& odOne, const OnlineDating& odTwo, OnlineDating& odJoined)
{
	bool Non_C = true;
	if (odJoined.noMatches() != true) //if non empty it will return false and go into the loop, will do this until it is empty
	{
		OnlineDating EMT;
		odJoined = EMT; //assigned an emepty one
	}
	if (odJoined.noMatches()) // true if odJoined is empty
	{ // if its empty then I can add all the elements of odOne in there and later on compare them to those in odTwo
		for (int j = 0; j < odTwo.howManyMatches(); j++)
		{
			std::string first;
			std::string last;
			OnlineType data;
			odTwo.confirmMatch(j, first, last, data);
			if (odOne.someoneAmongMatches(first, last)) // odOne also contains the full name next step is to check the data type 
														//if identical copy it to odJoined else dont copy (aliasing)
			{
				OnlineType data_2;
				odOne.lookAtMatches(first, last, data_2);
				if (data == data_2) //have the same OnlineType value
				{
					odJoined.makeMatch(first, last, data); // add full name and  value to odjoined
				}
				else // Onlinetype values differ DONT COPY!!!!!!!!!!!!!!
				{
					Non_C = false;
				}
			}
			else
			{
				odJoined.makeMatch(first, last, data); // add it to Odjoined
			}
		}
		for (int i = 0; i < odOne.howManyMatches(); i++)
		{
			std::string first;
			std::string last;
			OnlineType data;
			odOne.confirmMatch(i, first, last, data);
			if (odJoined.someoneAmongMatches(first, last)) // odJoined already contains the full name we dont need to add it again,
						//want to make sure aliasing doesnt happen
			{ //if first part returns true then it means that both lists have the same copy with same value 
				continue;
			}
			else if (odTwo.someoneAmongMatches(first, last)) // if this returns true it means that its in odtwo but not odjoined hence they have different values
			{
				continue;
			}
			else
			{
				odJoined.makeMatch(first, last, data); // add it to Odjoined
			}
		}

	}
	else // odjoined is not empty, need to empty it
	{
		mergeMatches(odOne, odTwo, odJoined); // call it again
	}
	return Non_C;
}

void authenticateMatches(const std::string& fsearch, const std::string& lsearch, const OnlineDating& odOne, OnlineDating& odResult)
{
	//while (odResult.noMatches() != true) //if non empty it will return false and go into the loop, will do this until it is empty
	//{
		//OnlineDating EMT;
		//odResult = EMT;
	//}
	OnlineDating temp; // this will be a copy
	odResult.tradeMatches(temp); //exchange with temp

	bool first_asterisk = (fsearch == "*");
	bool last_asterisk = (lsearch == "*");
	if (odOne.someoneAmongMatches(fsearch, lsearch))
	{

		for (int k = 0; k < odOne.howManyMatches(); k++)
		{
			std::string first;
			std::string last;
			OnlineType data;
			odOne.confirmMatch(k, first, last, data);
			if (fsearch == first) // if true, no need to check first names
			{
				if (lsearch == last) // if true, no need to change anything
				{
					odResult.makeMatch(first, last, data);
					continue;
				}
			}
		}
	}
	else  if (first_asterisk == true && last_asterisk == true) // copy the whole linkedList 
	{
		temp = odOne;
		odResult.tradeMatches(temp);
		return;// check first names
	}
	for (int k = 0; k < odOne.howManyMatches(); k++)
	{
		std::string first;
		std::string last;
		OnlineType data;
		odOne.confirmMatch(k, first, last, data);
		if (lsearch == last)
		{
			if (first_asterisk)
			{
				odResult.makeMatch(first, last, data);
				continue;
			}
		}
		else if (first == fsearch)
		{
			if (last_asterisk)
			{
				odResult.makeMatch(first, last, data);
				continue;
			}
		}
	}
	temp.~OnlineDating();
	return;
}

	/*	if (first != fsearch) // do not match REMOVE!
			{
				odResult.blockPreviousMatch(first, last);
			}
			else //first names do match, check last names
			{
				if (last_asterisk) // if true,no need to change anything
				{
					continue;
				}
				else //need to check last names
				{
					if (last != lsearch) // they dont match REMOVE!!
					{
						odResult.blockPreviousMatch(first, last);
					}
					else //last names match KEEP
					{
						continue;
					}
				}
			}
		}
	}
	return;
} */

/*else if (last != lsearch) // lsearch is not the same as last, remove!!
			{
			odResult.blockPreviousMatch(first, last);
			}
else // last name matches lsearch   KEEP!
			{
			continue;
			}
		}
		else  // check first names
		{
		if (first != fsearch) // do not match REMOVE!
		{
			odResult.blockPreviousMatch(first, last);
		}
		else //first names do match, check last names
		{
			if (last_asterisk) // if true,no need to change anything
			{
				continue;
			}
			else //need to check last names
			{
				if (last != lsearch) // they dont match REMOVE!!
				{
					odResult.blockPreviousMatch(first, last);
				}
				else //last names match KEEP
				{
					continue;
				}
			}
		}
		}
	}
	return;
}*/
#include "BballRoster.h"
#include <string>
#include <iostream>

BballRoster::BballRoster() : head(nullptr) {}

BballRoster::~BballRoster()
//doesn't really seem to be any difference from singly-linked since hte previous's aren't really having bearing on destruction
{
	Node *p = head;
	while (p != nullptr)
	{
		Node *q = p->next;
		delete p;
		p = q;
	}
}

BballRoster::BballRoster(const BballRoster& src)
// Approach: loop through src and signPlayer(data in each node)
{
	this->head = nullptr; //safety
	if (src.head != nullptr)
	{
		Node* p = src.head;
		while (p != nullptr)
		{
			this->signPlayer(p->firstName, p->lastName, p->data);
			p = p->next;
		}
	}
}

const BballRoster& BballRoster::operator=(const BballRoster& rhs)
{
	if (this != &rhs)
	{
		BballRoster temp(rhs);
		swapRoster(temp);
	}
	return *this;
}

bool BballRoster::rosterEmpty() const
// Return true if the BballRoster list is empty, otherwise false.
{
	return (head == nullptr);
}

int BballRoster::howManyPlayers() const 
// Return the number of players in the BballRoster list.

// just like with HW1, I will likely have this run to completion whenever I need a size AND THUS NOT have a private size variable
{
	int ret = 0;
	Node *p = head;
	while (p != nullptr)
	{
		ret++;
		p = p->next;
	}
	return ret;
}

bool BballRoster::signPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value)
// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return
// true. Elements should be added according to their last name.
// Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the
// list).

// Approach:
// 1) Loop through list until you hit a){equal-to}... b){current-is-greater than}... c){end of the list} based on LASTNAME
// 2)	a) if you find an identical lastname, then check firstname
// 3)		if
// 3)			i) BOTH LAST AND FIRSTNAME ARE THE SAME --> RETURN FALSE
// 3)			ii) Same lastname, different firstname, where the "current" node is AFTER your to-add
// 3)					- add new PRECEDING current
// 3)			iii) seemse we cannot escape from checking for the end!!!
// 2)	b) if your current node is greater than your toAdd, then add it PRECEDING CURRENT
// 2)	c) if you reach end of the list, then add it to the end

// !!! Since we're doing this "prev-based", we need to check for the specific case of "previous" being nullptr: adding to the front

{
	//empty case
	if (head == nullptr)
	{
		head = new Node;
		head->firstName = firstName;
		head->lastName = lastName;
		head->data = value;
		head->next = nullptr;
		head->prev = nullptr;

		return true;
	}

	else
	{
		//1+ Node list
		Node* p = head;
		while (p != nullptr)
		{
			if (p->lastName == lastName)
			{
				if (p->firstName == firstName)
				{
					return false;
				}

				else if (p->firstName > firstName)
				{
					Node* temp = p->prev; //temp's next will need to be set to the new node, which needs to happen BEFORE you change p-> prev!!!
					//if p points to the first node, the this will evaluate to nullptr

					p->prev = new Node;
					p->prev->lastName = lastName;
					p->prev->firstName = firstName;
					p->prev->data = value;
					p->prev->next = p;
					p->prev->prev = temp;

					//Check for front case!
					//temp is the OG previous node
					if (temp != nullptr)
						temp->next = p->prev;
					else
						head = p->prev;

					return true;
				}

				//end-check!
				else if (p->next == nullptr)
				{
					p->next = new Node;
					p->next->lastName = lastName;
					p->next->firstName = firstName;
					p->next->data = value;
					p->next->next = nullptr;
					p->next->prev = p;

					return true;
				}
			}

			else if (p->lastName > lastName)
			{
				Node* temp = p->prev; //temp's next will need to be set to the new node, which needs to happen BEFORE you change p-> prev!!!

				p->prev = new Node;
				p->prev->lastName = lastName;
				p->prev->firstName = firstName;
				p->prev->data = value;
				p->prev->next = p;
				p->prev->prev = temp;

				//Check for front case!
				//temp is the OG previous node
				if (temp != nullptr)
					temp->next = p->prev;
				else
					head = p->prev;

				return true;
			}

			//end-check!
			else if (p->next == nullptr)
			{
				p->next = new Node;
				p->next->lastName = lastName;
				p->next->firstName = firstName;
				p->next->data = value;
				p->next->next = nullptr;
				p->next->prev = p;

				return true;
			}

			p = p->next;
		}

		//technically bad practice, but anything here should NEVER run because all cases should have returns in the while loop itself!!!

		return false;
	}
}

bool BballRoster::resignPlayer(const std::string& firstName, const std::string& lastName, const SomeType& value)
// If the full name is equal to a full name currently in the
// list, then make that full name no longer map to the value it
// currently maps to, but instead map to the value of the third
// parameter; return true in this case. Otherwise, make no
// change to the list and return false.
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->lastName == lastName)
			if (p->firstName == firstName)
			{
				p->data = value;
				return true;
			}
		p = p->next;
	}
	return false;
}

bool BballRoster::signOrResign(const std::string& firstName, const std::string& lastName, const SomeType& value)
// If full name is equal to a name currently in the list, then
// make that full name no longer map to the value it currently
// maps to, but instead map to the value of the third parameter;
// return true in this case. If the full name is not equal to
// any full name currently in the list then add it and return
// true. In fact, this function always returns true.
{
	if (playerOnRoster(firstName, lastName))
		return resignPlayer(firstName, lastName, value);
	else
		return signPlayer(firstName, lastName, value);
}

bool BballRoster::renouncePlayer(const std::string& firstName, const std::string& lastName)
// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return
// true. Otherwise, make no change to the list and return
// false.

// Approach:
// 3 cases for removal:
// 1) front:
//		- head points to p->next
//		- p->next->prev = nullptr;
//		- delete p
// 2) middle:
//		- p->prev->next = p->next;
//		- p->next->prev = p->prev;
//		- delete p;
// 3) end:
//		- p->prev->next = nullptr;
//		- delete p
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->lastName == lastName)
			if (p->firstName == firstName)
			{
				if (p->prev == nullptr)
				{
					head = p->next;
					p->next->prev = nullptr;
				}
				else if (p->next == nullptr)
				{
					p->prev->next = nullptr;
				}
				else
				{
					p->prev->next = p->next;
					p->next->prev = p->prev;
				}

				delete p;

				return true;
			}
		p = p->next;
	}

	return false;
}

bool BballRoster::playerOnRoster(const std::string& firstName, const std::string& lastName) const
// Return true if the full name is equal to a full name
// currently in the list, otherwise false.
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->lastName == lastName)
			if (p->firstName == firstName)
				return true;
		p = p->next;
	}
	return false;
}

bool BballRoster::lookupPlayer(const std::string& firstName, const std::string& lastName, SomeType& value) const
// If the full name is equal to a full name currently in the
// list, set value to the value in the list that that full name
// maps to, and return true. Otherwise, make no change to the
// value parameter of this function and return false.
{
	Node* p = head;
	while (p != nullptr)
	{
		if (p->lastName == lastName)
			if (p->firstName == firstName)
			{
				value = p->data;
				return true;
			}
		p = p->next;
	}
	return false;
}

bool BballRoster::choosePlayer(int i, std::string& firstName, std::string& lastName, SomeType& value) const
// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the
// parameters unchanged and return false. (See below for details
// about this function.)
{
	if (0 <= i && i < howManyPlayers())
	{
		Node* p = head;

		//you need to move the pointer i times from index 0
		for (int j = 1; j <= i; j++)
		{
			p = p->next;
		}

		//p now rests on the target node
		firstName = p->firstName;
		lastName = p->lastName;
		value = p->data;

		return true;
	}
	
	return false;
}

void BballRoster::swapRoster(BballRoster& other)
// Exchange the contents of this list with the other one.
{
	Node* tempPtr = head;
	head = other.head;
	other.head = tempPtr;
	tempPtr = nullptr;
}

void BballRoster::dump() const
{
	if (head == nullptr)
		std::cerr << "empty list" << std::endl;
	else
	{
		Node* p = head;

		std::cerr << "==========" << std::endl;
		std::cerr << "Forward:" << std::endl;
		for (; p->next != nullptr; p = p->next)
		{
			std::cerr << p->firstName << " " << p->lastName << " " << p->data << std::endl;
		}
		//p now rests on the last node... we need to rest so we can traverse backwards!
		std::cerr << p->firstName << " " << p->lastName << " " << p->data << std::endl;
		std::cerr << "==========" << std::endl;

		std::cerr << "Backward:" << std::endl;
		for (; p != nullptr; p = p->prev)
		{
			std::cerr << p->firstName << " " << p->lastName << " " << p->data << std::endl;
		}
		//this one doesn't need to stop because we won't be reusing the ptr!
		std::cerr << "==========" << std::endl;
	}
}


//NONMEMBER FUNCTIONS

bool joinRosters(const BballRoster & bbOne, const BballRoster & bbTwo, BballRoster & bbJoined)
// Approach:
// 1) Somehow destruct the other list
//		IDEA: 
//			a) create a new list, which will be empty
//			b) swap it with bbJoined
//			c) your bbJoined is now empty, and since the scope of the new list is
//				inside this bracket, it'll get destroyed on exit!
/// 2) copy-construct the first list 
/// NEW BIG IDEA: copy construct the first list, swap, then it'll destroy the second list when it's done
// 2) cleaner BIG IDEA: just use assignment operator to deal with aliasing!!!
// 3) start running through each node in the second list
// 3)	- if you cannot add it to bbJoined, which is a copy of bbOne, then this means
//		that there is a duplicate name 
// 4)		-- if there is a duplicate name, then further check the data
// 4)			--- if they are equal, then do nothing and move on
// 4)			--- if they are not equal, call delete on that name!
// *** The idea is that the methods already work so that by the time everything is added 
//		it will already be alphabetical
//
// Weird shenanigans
// - both One and Two are the same list
//		-- bbJoined will be a simple copy
// - joined is either One or Two
//		-- seems to work fine with current methodology
//			-- perhaps not though... once you swap bbJoined with throwaway, throwaway now has a head pointing to bb1 itself which will be deleted!
// - all three arguments are the same
//		-- seems to work fine
{
	///BballRoster throwaway (bbOne);
	///bbJoined.swapRoster(throwaway);

	bbJoined = bbOne;

	std::string firstNombre;
	std::string lastNombre;
	SomeType val;

	bool ret = true;

	int i = 0;
	while (bbTwo.choosePlayer(i, firstNombre, lastNombre, val))
	{
		if (bbJoined.signPlayer(firstNombre, lastNombre, val)) { }
		else
		{
			SomeType compMe;
			bbOne.lookupPlayer(firstNombre, lastNombre, compMe);

			//these else's running means that there is a duplicate name!!!
			if (compMe == val) { }
			else
			//this statement running means that there is a duplicate name and their values are NOT the same
			{
				bbJoined.renouncePlayer(firstNombre, lastNombre);
				ret = false;
			}
		}

		i++;
	}

	return ret;
}

void checkRoster(const std::string& fsearch, const std::string& lsearch, const BballRoster& bbOne, BballRoster& bbResult)
{
	///BballRoster throwaway (bbOne);
	///bbJoined.swapRoster(throwaway);

	bbResult = bbOne;

	std::string firstNombre;
	std::string lastNombre;
	SomeType val;

	bool ignoreFirst = (fsearch == "*");
	bool ignoreLast = (lsearch == "*");

	int i = 0;
	while (bbOne.choosePlayer(i, firstNombre, lastNombre, val))
	{
		if (ignoreFirst)
		{
			if (ignoreLast) //two stars = same list!
				return;
			else if (lastNombre != lsearch) //remove if last names are different
				bbResult.renouncePlayer(firstNombre, lastNombre);
			else { } //this means the last names are the same = keep in list... do nothing!
		}
		else
		//NOT ignoring first name!
		{
			if (firstNombre != fsearch) //remove if you're not ignoring and they're different!
				bbResult.renouncePlayer(firstNombre, lastNombre);
			else //first names ARE the same!
			{
				if(ignoreLast) { } //same first, ignore last, don't remove!
				else //NOT ignoring last name
				{
					if(lastNombre != lsearch)
						bbResult.renouncePlayer(firstNombre, lastNombre);
					else { } //same first name, same last name, keep it, don't remove!
				}
			}
		}
		i++;
	}
}
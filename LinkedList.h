#pragma once
#include <iostream>
#include <vector>
//#include "leaker.h"
//had conceptual discussion with Daniel Marzo on 2/8/2022 at around 12:30 pm
//had conceptual discussion with Alex Duffaut on 2/10/2022 at around 9:00 am
//had conceptual discussion with Alex Duffaut on 2/10/2022 at around 10:20 am
//got help from micah grant on 2/12/2022 at around 9:30 am
//got help from Abdullah Yuksel on 2/12/2022 at around 10:50 am & around 12:00 pm to 1:00 pm
//got help from Daniel Marzo on 2/14/2022 at around 11:30 am
//got help from James Horn on 2/14/2022 at around 3:57 pm
//got help from Daniel Marzo on 2/15/2022 at around 11:38 am
using namespace std;
template <typename T>

class LinkedList
{
public:
	LinkedList();
	void AddHead(const T&);
	void AddTail(const T&);
	void AddNodesHead(const T*, unsigned int);
	void AddNodesTail(const T*, unsigned int);
	unsigned int NodeCount() const;
	void PrintForward() const;
	void PrintReverse() const;
	T& operator[](unsigned int);
	LinkedList<T>(const LinkedList<T>&); //copy constructor
	LinkedList<T>& operator=(const LinkedList<T>&); //copy assignment
	bool operator==(const LinkedList<T>&) const; //equality operator
	//void FindAll(vector<Node*>&, const T&) const;
	~LinkedList();
	struct Node
	{
		Node* next;
		T data;
		//Node* prev;
		Node* prev;
		Node()
		{
			next = nullptr;
			prev = nullptr;
		}
	};
	void PrintForwardRecursive(const Node*) const;
	void PrintReverseRecursive(const Node*) const;
	void InsertBefore(Node*, const T&);
	void InsertAfter(Node*, const T&);
	void InsertAt(const T&, unsigned int);
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();
	void FindAll(vector<Node*>&, const T&) const;
	const Node* GetNode(unsigned int) const;
	Node* GetNode(unsigned int);
	Node* Head();

	Node* Tail();
	Node* Find(const T&);
	//Returns the head pointer(const version)
	const typename LinkedList<T>::Node* Head() const
	{
		return head;
	}
	//Returns the tail pointer(const version)
	const typename LinkedList<T>::Node* Tail() const
	{
		return tail;
	}
	//Overloaded subscript operator. Takes an index, and returns data from the indexth node.
	//Throws an out_of_range exception for an invalid index
	const T& operator[](unsigned int index) const
	{
		Node* current = head;
		Node* index_node;
		if (index > Nodecount || index < 0)
		{
			throw runtime_error("out_of_range exception");
			//return;
		}
		else
		{
			for (unsigned int i = 0; i < index; i++)
			{
				if (i == index)
				{
					index_node = current;
				}
				else
				{
					current = current->next;
				}
			}
		}
		return index_node->data;
	}
	const Node* Find(const T& data) const;

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int Nodecount = 0;

};

//constructor
//Initialize your variables
template<typename T>
LinkedList<T>::LinkedList()
{
	//this->Nodecount = 0;
	head = nullptr;
	tail = nullptr;
}

//Create a new Node at the front of the list to store the passed in parameter.
template<typename T>
void LinkedList<T>::AddHead(const T& data)
{

	//allocate new head and tail
	Node* new_Node = new Node;
	//setting next Node to data
	new_Node->data = data;
	//Node checking
	if (head == nullptr)
	{
		head = new_Node;
		tail = head;
	}
	else
	{
		//setting prev data to new Node
		head->prev = new_Node;
		//setting next Node to head
		new_Node->next = head;
		//set head to new Node
		head = new_Node;
	}
	this->Nodecount = Nodecount + 1;

}
template <typename T>
//Given an index, return a pointer to the node at that index. Throws an exception
//of type out_of_range if the index is out of range
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	Node* index_node;
	Node* current = head;
	if (index >= Nodecount)
	{
		throw out_of_range("out of range error");
		//return;
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			current = current->next;
		}
		index_node = current;
		return index_node;
	}
}
//Create a new Node at the end of the list to store the passed in parameter.
template<typename T>
void LinkedList<T>::AddTail(const T& data)
{
	//allocating new Node
	Node* new_Node = new Node;
	//initializing new Node to data
	new_Node->data = data;
	//Node checking
	if (tail == nullptr)
	{
		tail = new_Node;
		head = tail;
	}
	else
	{
		//setting prev data to tail
		new_Node->prev = tail;
		//set tails next to new Node
		tail->next = new_Node;
		//reset tail
		tail = new_Node;
	}
	this->Nodecount = Nodecount + 1;

}
template<typename T>
//Find the first node with a data value matching the passed in parameter,
//returning a pointer to that node.Returns nullptr if no matching node found.
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* current = head;
	Node* index_node = nullptr;
	for (unsigned int i = 0; i < Nodecount; i++)
	{
		if (current->data == data)
		{
			index_node = current;
			break;
		}
		else
		{
			current = current->next;
		}
	}
	return index_node;
}
//Given an array of values, insert a Node for each of those at the beginning of the
//list, maintaining the original order
template<typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	unsigned int i = count;
	while (i != 0)
	{
		i = i - 1;
		AddHead(data[i]);
	}
}

//Given an array of values, insert a Node for each of those except adding to the end of the list.
template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		AddTail(data[i]);
	}
}


//How many things are stored in this list?
template<typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	return this->Nodecount;
}

//Iterator through all of the Nodes and print out their values, one a time.
template<typename T>
void LinkedList<T>::PrintForward() const
{
	Node* current = head;
	for (unsigned int i = 0; i < Nodecount; i++)
	{
		cout << current->data << endl;
		current = current->next;
	}

}


//Exactly the same as PrintForward, except completely the opposite.
template<typename T>
void LinkedList<T>::PrintReverse() const
{
	Node* current = tail;
	for (unsigned int i = 0; i < Nodecount; i++)
	{
		cout << current->data << endl;
		current = current->prev;
	}

}
//Returns the head pointer.
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return LinkedList<T>::head;
}

//Returns the tail pointer.
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return LinkedList<T>::tail;
}
/*
Given an index, return a pointer to the node at that index. Throws an exception
of type out_of_range if the index is out of range.
*/
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	Node* index_node;
	Node* current = head;
	if (index >= Nodecount)
	{
		throw out_of_range("out of range error");
		//	return;
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			current = current->next;
		}
		index_node = current;
		return index_node;
	}
}

/*
* Find the first node with a data value matching the passed in parameter,
returning a pointer to that node. Returns nullptr if no matching node found.
*/
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* current = head;
	Node* index_node = nullptr;
	for (unsigned int i = 0; i < Nodecount; i++)
	{
		if (current->data == data)
		{
			index_node = current;
			break;
		}
		else
		{
			current = current->next;
		}
	}
	return index_node;
}
/*
This function takes in a pointer to a Node—a starting node. From that node,
recursively visit each node that follows, in forward order, and print their values.
This function MUST be implemented using recursion, or tests using it will be
worth no points. Check your textbook for a reference on recursion.
*/
template<typename T>
void typename LinkedList<T>::PrintForwardRecursive(const Node*) const
{
}
//Same deal as PrintForwardRecursive, but in reverse.
template<typename T>
void typename LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
}

//insert the new node before the indicated node.
template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	//Node* new_node = new Node;
	Node* prev_node = node->prev;
	if (prev_node == nullptr)
	{
		prev_node = new Node;
		prev_node->data = data;
		node->prev = prev_node;
		//prev_node->data = data;
		prev_node->next = node;
	}
	else
	{
		
		Node* new_node = new Node;
		new_node->data = data;
		new_node->prev = prev_node;
		node->prev = new_node;
		prev_node->next = new_node;
		new_node->next = node;
		
	}
	Nodecount = Nodecount + 1;
}
/*
* Given a pointer to a node, create a new node to store the passed in value, after
the indicated node.
*/
template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	
	//Node* After = new Node;
	Node* old = node->next;
	InsertBefore(old, data);
	
}
/*
* Inserts a new Node to store the first parameter, at the index-th location. So if
you specified 3 as the index, the new Node should have 3 Nodes before it.
Throws an out_of_range exception if given an invalid index.
*/
template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	//Node* new_node = new Node;
	if (index == 0)
	{
		//Node* new_node = new Node;
		//new_node
		AddHead(data);
		//Nodecount = Nodecount + 1;
	}
	else if (index > Nodecount)
	{
		throw out_of_range("Out of range error");
	}
	 else if (index == Nodecount)
	{
		AddTail(data);
	}
	else
	{	
		Node* new_node = GetNode(index);
		//new_node = GetNode(index);
		//cout << new_node->data;
		InsertBefore(new_node, data);
	}
	
	//Nodecount = Nodecount + 1;
}

//Deletes the first Node in the list. Returns whether or not the Node was removed.
template<typename T>
bool LinkedList<T>::RemoveHead()
{
	Node* current = head;
	if (Nodecount > 1)
	{
		head = head->next;
		delete head->prev;
	}
	else if (Nodecount == 1)
	{
		return false;
	}
	if (current == head)
	{
		return false;
	}
	else
	{
		this->Nodecount = Nodecount - 1;
		return true;
	}
	
}

//Deletes the last Node, returning whether or not the operation was successful.
template<typename T>
bool LinkedList<T>::RemoveTail()
{
	
	Node* current = tail;
	if (Nodecount > 1)
	{
		tail = tail->prev;
		this->Nodecount = Nodecount - 1;
	}
	else if (Nodecount == 1)
	{
		return false;
	}
	if (current == tail)
	{
		return false;
	}
	else
	{
		//this->Nodecount = Nodecount - 1;
		return true;
	}
	
}

/*
Remove ALL Nodes containing values matching that of the passed - in parameter.
Returns how many instances were removed.
*/
template<typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{

	vector<LinkedList<T>::Node*> nodes;
	FindAll(nodes, data);
	for (unsigned int i = 0; i < sizeof(nodes); i++)
	{

	}
	return 0;
}

/*
* Deletes the index-th Node from the list, returning whether or not the operation
was successful.
*/
template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	//Node* target = GetNode(index);
	if (index == 0)
	{
		RemoveHead();
	}
	else if (index == Nodecount - 1)
	{
		RemoveTail();
	}
	else if (index > Nodecount)
	{
		return false;
	}
	else
	{
		Node* target = GetNode(index);
		target->prev->next = target->next;
		target->next->prev = target->prev;
		this->Nodecount = Nodecount - 1; //prevents segmentation fault
		Node* current = GetNode(index);
		if (current->data != target->data)
		{
			//cout << "success!" << endl;
			return true;
		}
		else
		{
			//cout << "fail!" << endl;
			return false;
		}
	}
	//return false;
}

/*
* Deletes all Nodes. Don’t forget the node count—how many nodes do you have
after you deleted all of them?
*/
template<typename T>
void LinkedList<T>::Clear()
{
}

/*
* Find all nodes which match the passed in parameter value, and store a pointer to
that node in the passed in vector. Use of a parameter like this (passing a
something in by reference, and storing data for later use) is called an output
parameter.
*/
template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* current = head;
	//Node* index_node;
	for (unsigned int i = 0; i < Nodecount; i++)
	{
		if (current->data == value)
		{
			outData.push_back(current);
		}
		current = current->next;
	}
}


/*
* Overloaded subscript operator. Takes an index, and returns data from the indexth node. Throws an out_of_range exception for an invalid index. Const and nonconst versions.
*/
template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	Node* current = head;
	Node* index_node;
	if (index > Nodecount || index < 0)
	{
		throw out_of_range("out of range error");
		//return;
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			if (i == index)
			{
				index_node = current;
			}
			else
			{
				current = current->next;
			}
		}
	}
	return index_node->data;
}

/*
* Assignment operator. After listA = listB, listA == listB is true. Can you utilize any
of your existing functions to make write this one? (Hint: Yes you can.)
*/
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	Node* copy;
	Node* destroy_next;
	while (head)
	{
		destroy_next = head->next;
		delete head;
		head = destroy_next;
	}
	copy = rhs.head;
	head = nullptr;
	tail = nullptr;
	Nodecount = 0;
	//copy = list.head;
	for (unsigned int i = 0; i < rhs.NodeCount(); i++)
	{
		//copy = head
		//this
		this->AddTail(copy->data);
		copy = copy->next;
	}
	return *this;
}


template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	
	Node* rhscurrent = rhs.head;
	Node* thiscurrent = this->head;
	bool equal = false;
	//unsigned int truecount = 0;
	if (rhs.NodeCount() != Nodecount)
	{
		equal = false;
	}
	else
	{
		for (unsigned int i = 0; i < NodeCount(); i++)
		{
			if (thiscurrent->data == rhscurrent->data)
			{
				equal = true;
			}
			else
			{
				return false;
				//break;
			}
			rhscurrent = rhscurrent->next;
			thiscurrent = thiscurrent->next;
		}
	}
	
	return equal;
}

//destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node* destroy_next;
	while (head)
	{
		destroy_next = head->next;
		delete head;//hit f10 for this
		head = destroy_next;
	}
}


//Returns the head pointer
template<typename T>
typename LinkedList<T>::Node* Head()
{
	return LinkedList<T>::head;
}

//Returns the tail pointer.
template<typename T>
typename LinkedList<T>::Node* Tail()
{
	return LinkedList<T>::tail;
}

//copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	//this->Nodecount = list.Nodecount;
	//Node* current = head;
	//this->head = list.head;
	Node* copy;
	copy = list.head;
	//copy = list.head;
	for (unsigned int i = 0; i < list.NodeCount(); i++)
	{
		//copy = head
		//this
		this->AddTail(copy->data);
		copy = copy->next;
	}

}



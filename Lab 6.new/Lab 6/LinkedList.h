#pragma once
#include <cstdlib>
#include "Node.h"
#include "NodeIterators.h"

namespace CS262
{
	template <typename Item>
	class LinkedList
	{
	public:
		typedef Node<Item>* NodePtr;
		typedef node_iterator<Item> iterator;
		typedef const_node_iterator<Item> const_iterator;

		// Postcondition: An empty linked list has been created
		LinkedList();

		// Postcondition: A copy of the source linked list has been created
		LinkedList(const LinkedList& source);

		// Postcondition: All dynamic memory used by the list has been freed
		~LinkedList();

		// Postcondition: Entry has been inserted into a new node at
		// the head of the list
		void insertAtHead(const Item& entry);

		// Postcondition: Entry has been inserted into a new node at
		// the end of the list
		void insertAtTail(const Item& entry);

		// Postcondition: If target is in the list, the first occurence is
		// removed and removeFromList returns true. If target is not in
		// the list, removeFromList returns false.
		bool removeFromList(const Item& target);

	    // Postcondition: all nodes are removed from the list and returned
		// to the heap. head is reset to NULL. 
		void clearList();

		// Postcondition: the return value is the number of nodes in the list
		std::size_t size() const;

		// Postcondition: the current list has been replaced with a copy of
		// the source linked list. The return value is the calling object
		LinkedList& operator =(const LinkedList& source);

		// creates a node_iterator set to the begining of the list 
		iterator begin() {return iterator(head);}

	// creates a const_node_iterator set to the beginning of the list
	const_iterator begin() const {return const_iterator(head);}

	// creates a node_iterator set to the end of the list 
	iterator end() {return iterator(NULL);}

	// creates a const_node_iterator set to the end of the list
	const_iterator end() const {return const_iterator(NULL);}

	// creates a node_iterator set to the end of the list 
	iterator rbegin() {return iterator(tail);}

	// creates a const_node_iterator set to the end of the list
	const_iterator rbegin() const {return const_iterator(tail);}

	protected:
		NodePtr head;
		NodePtr tail;
		std::size_t node_count;
	};
}

#include "LinkedList.cpp"
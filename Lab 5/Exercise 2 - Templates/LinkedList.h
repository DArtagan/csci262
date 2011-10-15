#pragma once
#include <cstdlib>
#include "Node.h"


namespace CS262
{
	template <typename Item>
	class LinkedList
	{
	public:
		typedef Node<Item>* NodePtr;
		typedef Item value_type;

		// Postcondition: An empty linked list has been created
		LinkedList() : head(NULL), tail(NULL), node_count(0) {}

		// Postcondition: A linked list

		// Postcondition: A copy of the source linked list has been created
		LinkedList(const LinkedList& source);

		// Postcondition: All dynamic memory used by the list has been freed
		~LinkedList();

		// Postcondition: Entry has been inserted into a new node at
		// the head of the list
		void insertAtHead(const value_type& entry);

		// Postcondition: Entry has been inserted into a new node at
		// the end of the list
		void insertAtTail(const value_type& entry);

		// Postcondition: If target is in the list, the first occurence is
		// removed and removeFromList returns true. If target is not in
		// the list, removeFromList returns false.
		bool removeFromList(const value_type& target);

	    // Postcondition: all nodes are removed from the list and returned
		// to the heap. head is reset to NULL. 
		void clearList();

		// Postcondition: the return value is the number of nodes in the list
		std::size_t size() const  {return node_count;}

		// Postcondition: the current list has been replaced with a copy of
		// the source linked list. The return value is the calling object
		LinkedList& operator =(const LinkedList& source);

	private:
		NodePtr head;
		NodePtr tail;
		std::size_t node_count;
	};
}

#include "LinkedList.cpp"
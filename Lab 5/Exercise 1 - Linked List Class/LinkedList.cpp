#include "LinkedList.h"


namespace CS262 {
	// Postcondition: A copy of the source linked list has been created
	LinkedList::LinkedList(const LinkedList& source) {
		
	}

	// Postcondition: All dynamic memory used by the list has been freed
	LinkedList::~LinkedList() {

	}
	
	void LinkedList::insertAtHead(const value_type& entry) {
		new Node(entry);
	}

	LinkedList& LinkedList::operator =(const LinkedList& source) {
		return *this; // must return something (but still basically empty)
	}

	// Postcondition: Entry has been inserted into a new node at
	// the end of the list
	void LinkedList::insertAtTail(const value_type& entry) {

	}

	// Postcondition: If target is in the list, the first occurence is
	// removed and removeFromList returns true. If target is not in
	// the list, removeFromList returns false.
	bool LinkedList::removeFromList(const value_type& target) {
		return 1;
	}

	// Postcondition: all nodes are removed from the list and returned
	// to the heap. head is reset to NULL. 
	void LinkedList::clearList() {

	}
}
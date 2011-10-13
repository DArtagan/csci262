#include "LinkedList.h"
#include <iostream>


namespace CS262 {
	// Postcondition: A copy of the source linked list has been created
	LinkedList::LinkedList(const LinkedList& source) {
		head = 0;
		tail = 0;
		node_count = 0;
		Node* n;
		n = source.head;
		while(n != NULL) {
			insertAtTail(n->data);
			n = n->next;
		}
		node_count = source.node_count;
	}

	// Postcondition: All dynamic memory used by the list has been freed
	LinkedList::~LinkedList() {
		
	}
	
	void LinkedList::insertAtHead(const value_type& entry) {
		Node* n(head);
		head = new Node(entry, head, NULL);
		if(node_count == 0) {
			tail = head;
		} else {
			n->prev = head;
		}
		node_count++;
	}

	// Postcondition: Entry has been inserted into a new node at
	// the end of the list
	void LinkedList::insertAtTail(const value_type& entry) {
		Node* n(tail);
		tail = new Node(entry, NULL, tail);
		if(node_count == 0) {
			head = tail;
		} else {
			n->next = tail;
		}
		node_count++;
	}
	
	// Postcondition: If target is in the list, the first occurence is
	// removed and removeFromList returns true. If target is not in
	// the list, removeFromList returns false.
	bool LinkedList::removeFromList(const value_type& target) {
		Node* n(head);
		while(n != NULL && n->data != target) {n = n->next;}
		if(n == NULL) { return false;}
		if(n->prev == NULL && n->next == NULL) {
			head = NULL;
			tail = NULL;
		} else if(n->prev == NULL) {
			head = n->next;
			n->next->prev = NULL;
		} else if(n->next == NULL) {
			tail = n->prev;
			n->prev->next = NULL;
		} else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
		}
		node_count--;
		delete n;
		return true;
	}

	// Postcondition: all nodes are removed from the list and returned
	// to the heap. head is reset to NULL. 
	void LinkedList::clearList(){
		while (head != NULL){
			Node* temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;
		head = NULL;
		node_count = 0;
	}
	
	LinkedList& LinkedList::operator =(const LinkedList& source) {
		if(this == &source) return *this;

		const Node* n;
		if(head != NULL) clearList();
		n = source.head;
		while(n != NULL) {
			insertAtHead(n->data);
			n = n->next;
		}
		node_count = source.node_count;
		return *this;
	}
}
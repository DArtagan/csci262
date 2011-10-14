#include "LinkedList.h"
#include <iostream>


namespace CS262 {
	// Postcondition: A copy of the source linked list has been created
	template <typename Item>
	LinkedList<Item>::LinkedList<Item>(const LinkedList<Item>& source) {
		head = 0;
		tail = 0;
		node_count = 0;
		NodePtr n;
		n = source.head;
		while(n != NULL) {
			insertAtTail(n->data);
			n = n->next;
		}
		node_count = source.node_count;
	}

	// Postcondition: All dynamic memory used by the list has been freed
	template <typename Item>
	LinkedList<Item>::~LinkedList<Item>() {
		
	}
	
	template <typename Item>
	void LinkedList<Item>::insertAtHead(const value_type& entry) {
		NodePtr n(head);
		head = new Node<Item>(entry, head, NULL);
		if(node_count == 0) {
			tail = head;
		} else {
			n->prev = head;
		}
		node_count++;
	}

	// Postcondition: Entry has been inserted into a new node at
	// the end of the list
	template <typename Item>
	void LinkedList<Item>::insertAtTail(const value_type& entry) {
		NodePtr n(tail);
		tail = new Node<Item>(entry, NULL, tail);
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
	template <typename Item>
	bool LinkedList<Item>::removeFromList(const value_type& target) {
		NodePtr n(head);
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
	template <typename Item>
	void LinkedList<Item>::clearList(){
		while (head != NULL){
			NodePtr temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;
		head = NULL;
		node_count = 0;
	}
	
	template <typename Item>
	LinkedList<Item>& LinkedList<Item>::operator =(const LinkedList<Item>& source) {
		if(this == &source) return *this;

		const NodePtr n;
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
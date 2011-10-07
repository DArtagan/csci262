#include <iterator>
#include "Node.h"


namespace CS262 {

	template <typename Item>
	class node_iterator :
		public std::iterator<std::bidirectional_iterator_tag, Item>
	{
		public:
			// constructor
			node_iterator(Node<Item>* initial = NULL):
				current(initial) { }

			// dereference operator
			Item& operator *() const { return current->data; }

			// prefix ++
			node_iterator& operator ++() { 
				current = current->next;
				return *this;
			}

			// postfix ++
			node_iterator operator ++(int) {
				node_iterator original(current);
				current = current->next;
				return original;      	  
			}

			// prefix --
			node_iterator& operator --() { 
				current = current->prev;
				return *this;
			}

			// postfix --
			node_iterator operator --(int) {
				node_iterator original(current);
				current = current->prev;
				return original;      	  
			}

			// end of list?
			bool hasNext() const {
				return (current->next != NULL);
			}

			// beginning of list?
			bool hasPrev() const {
				return (current->prev != NULL);
			}

			// equality operator
			bool operator ==(const node_iterator other) const {
				return current == other.current;
			}

			// inequality operator
			bool operator !=(const node_iterator other) const {
				return current != other.current;
			}

		private:
			Node<Item>* current;
	};


	template <typename Item>
	class const_node_iterator :
		public std::iterator<std::forward_iterator_tag, const Item>
	{
		public:
			// constructor
			const_node_iterator(const Node<Item>* initial = NULL):
				current(initial) { }

			// dereference operator
			const Item& operator *() const { return current->data; }

			// prefix ++
			const_node_iterator& operator ++() { 
				current = current->next;
				return *this;
			}

			// postfix ++
			const_node_iterator operator ++(int) {
				node_iterator original(current);
				current = current->next;
				return original;      	  
			}

			// prefix --
			const_node_iterator& operator --() { 
				current = current->prev;
				return *this;
			}

			// postfix --
			const_node_iterator operator --(int) {
				node_iterator original(current);
				current = current->prev;
				return original;      	  
			}

			// end of list?
			bool hasNext() const {
				return (current->next != NULL);
			}

			// beginning of list?
			bool hasPrev() const {
				return (current->prev != NULL);
			}

			// equality operator
			bool operator ==(const const_node_iterator other) const {
				return current == other.current;
			}

			// inequality operator
			bool operator !=(const const_node_iterator other) const {
				return current != other.current;
			}

		private:
			const Node<Item>* current;
	};
}
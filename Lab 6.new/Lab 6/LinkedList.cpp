namespace CS262
{
		// Postcondition: An empty linked list has been created
		template <typename Item>
		LinkedList<Item>::LinkedList(){
			head = NULL;
			tail = NULL;
			node_count = 0;
		}
		
		// Postcondition: A copy of the source linked list has been created
		template <typename Item>
		LinkedList<Item>::LinkedList(const LinkedList<Item>& source){
			head = NULL;
			tail = NULL;
			node_count = 0;
			NodePtr N = source.head;
			while (N != NULL) {
				insertAtTail(N->data);
				N = N->next;
			}

		}

		// Postcondition: All dynamic memory used by the list has been freed
		template <typename Item>
		LinkedList<Item>::~LinkedList(){
			clearList();
		}

		// Postcondition: Entry has been inserted into a new node at
		// the head of the list
		template <typename Item>
		void LinkedList<Item>::insertAtHead(const Item& entry){
			if (node_count == 0) {
				head = new Node<Item>(entry,tail,head);
				tail = head;
			} else { 
				head = new Node<Item>(entry,head,NULL);
				head->next->prev = head;
			}
			node_count++;
		}

		// Postcondition: Entry has been inserted into a new node at
		// the end of the list
		template <typename Item>
		void LinkedList<Item>::insertAtTail(const Item& entry){
			if (node_count == 0) {
				tail = new Node<Item>(entry,head,tail);
				head = tail;
			} else { 
				tail = new Node<Item>(entry,NULL,tail);
				tail->prev->next = tail;
			}
			node_count++;
		}

		// Postcondition: If target is in the list, the first occurence is
		// removed and removeFromList returns true. If target is not in
		// the list, removeFromList returns false.
		template <typename Item>
		bool LinkedList<Item>::removeFromList(const Item& target){
			NodePtr N = head;
			while ((N != NULL) && (N->data != target)) {
				N = N->next;
			}
			if (N == NULL) {
				return false;
			}
			if (N->next == NULL) {tail = N->prev;}
			else {N->next->prev = N->prev;}
			if (N->prev == NULL) {head = N->next;}
			else {N->prev->next = N->next;}
			delete N;
			node_count--;
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

		// Postcondition: the return value is the number of nodes in the list
		template <typename Item>
		std::size_t LinkedList<Item>::size() const{
			return node_count;
		}

		// Postcondition: the current list has been replaced with a copy of
		// the source linked list. The return value is the calling object
		template <typename Item>
		LinkedList<Item>& LinkedList<Item>::operator =(const LinkedList<Item>& source){
			if (head == source.head) {
				return *this;
			}
			if (head != NULL) {
				clearList();
			}
			head = NULL;
			tail = NULL;
			node_count = 0;
			NodePtr N = source.head;
			while (N != NULL) {
				insertAtTail(N->data);
				N = N->next;
			}
		    return *this; // must return something (but still basically empty)
		}
}
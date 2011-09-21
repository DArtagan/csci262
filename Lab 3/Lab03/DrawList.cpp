#include "DrawList.h"

using namespace std;

namespace CS262{
	
	// Constructors and Destructors
	DrawList::DrawList(size_type initial_capacity) {
		MyRects = new value_type*[initial_capacity];
		capacity = initial_capacity;
		current_index = 0;
		used = 0;
		for(size_type i=0; i<initial_capacity; i++) {
			MyRects[i] = NULL;
		}
	}

	DrawList::DrawList(const DrawList& source) {
		MyRects = new value_type*[source.capacity];

		used = source.used;
		capacity = source.capacity;
		current_index = source.current_index;

		for(size_type i=0; i<used; i++) {
			MyRects[i] = source.MyRects[i];
		}
	}

	DrawList::~DrawList() {
		for(size_type i=0; i<capacity; i++) {
			delete MyRects[i];
		}
		delete [] MyRects;
	}


	// Operators
	DrawList& DrawList::operator =(const DrawList& source) {
		if (this == &source) return *this;

		if(capacity != source.capacity) {
			delete [] MyRects;
			MyRects = new value_type*[source.capacity];
			capacity = source.capacity;
		}

		used = source.used;
		for(size_type i=0; i<used; i++) {
			MyRects[i] = source.MyRects[i];
		}
		return *this;
	}
	void DrawList::operator ++() {
		assert(!end());
		current_index++;
	}

	DrawList::value_type DrawList::operator *() const {
		assert(!end()); 
		return *MyRects[current_index];
	}


	// Functions
	void DrawList::insert(const value_type& entry) {
		if(used >= capacity) {
			reserve(2*used+1);
		}
		MyRects[used] = new value_type(entry);
		used++;
	}

	void DrawList::reserve(size_type new_size) {
		if(new_size == capacity) return;
		if(new_size < used) new_size = used;

		value_type **new_array = new value_type*[new_size];
		for(size_type i=0; i<used; i++) {
			new_array[i] = MyRects[i];
		}
		for(size_type i=used; i<new_size; i++) {
			new_array[i] = NULL;
		}
		delete [] MyRects;
		MyRects = new_array;
		capacity = new_size;
	}

	void DrawList::remove_last() {
		assert(used > 0);
		MyRects[--used] = NULL;
		delete MyRects[used];
	}

	bool DrawList::end() const {
		return(current_index >= used);
	}
}
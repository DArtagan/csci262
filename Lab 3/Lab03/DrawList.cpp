#include "DrawList.h"

using namespace std;

namespace CS262{
	// Operators
	void DrawList::operator ++() {
		assert(!end());
		current_index++;
	}

	DrawList::value_type DrawList::operator *() const {
		assert(!end()); 
		return MyRects[current_index];
	}


	// Functions
	void DrawList::insert(const value_type& entry) {
		assert(used < CAPACITY);
		MyRects[used] = entry;
		used++;
	}

	void DrawList::remove_last() {
		assert(used > 0);
		used--;
	}

	bool DrawList::end() const {
		if(current_index >= used) {
			return true;
		} else {
			return false;
		}
	}
}
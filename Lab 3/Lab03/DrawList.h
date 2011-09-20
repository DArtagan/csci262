// FILE: DrawList.h
// CLASS PROVIDED: DrawList

#pragma once
#include <iostream>
#include <cassert>
#include "Color.h"
#include "Point.h"
#include "MyRect.h"

namespace CS262 {
	class DrawList {
		public:
			// typedefs and constants
			typedef MyRect value_type;
			typedef std::size_t size_type;
			size_type DEFAULT_CAPACITY = 3;

			//constructors
			DrawList() : used(0), current_index(0), capacity(DEFAULT_CAPACITY) {}

			//operators
			void operator ++();
			value_type operator *() const;

			//functions
			void insert(const value_type& entry);
			void remove_last();
			size_type size() const {return used;}
			void begin() {current_index = 0;}
			bool end() const;

		private:
			value_type MyRects[CAPACITY];
			size_type used, current_index;
			size_type capacity;
	};
}
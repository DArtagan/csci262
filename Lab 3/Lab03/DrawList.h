// FILE: DrawList.h
// CLASS PROVIDED: DrawList

#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Color.h"
#include "Point.h"
#include "MyRect.h"

namespace CS262 {
	class DrawList {
		public:
			// typedefs and constants
			typedef MyRect value_type;
			typedef std::size_t size_type;
			static const size_type DEFAULT_CAPACITY = 3;

			//constructors and destructors
			DrawList(size_type initial_capacity = DEFAULT_CAPACITY);
			DrawList(const DrawList& source);
			~DrawList();

			//operators
			DrawList& operator =(const DrawList& source);
			void operator ++();
			value_type operator *() const;

			//functions
			void insert(const value_type& entry);
			void reserve(size_type new_size);
			void remove_last();
			size_type size() const {return used;}
			void begin() {current_index = 0;}
			bool end() const;

		private:
			value_type **MyRects;
			size_type used, current_index, capacity;
	};
}
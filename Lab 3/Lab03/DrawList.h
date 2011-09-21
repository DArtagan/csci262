/********************************
Name: William H. Weiskopf
Section: A
Date: September 20, 2011

Purpose: typedef is utilized to simplify the declarations of functions and data types.  The biggest feature of this program is learing dynamic allocation and pointers through the use of an array to store the MyRect objects. Finally, there is the Big Three (constructor, assignment, and destructor).  Creating these is similar to many of the other functions created in this program, but these three are essential for basic class functionallity.  
********************************/
#pragma once

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
			DrawList(const size_type initial_capacity = DEFAULT_CAPACITY);
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

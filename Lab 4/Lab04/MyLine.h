/********************************
Name: William H. Weiskopf
Section: A
Date: September 20, 2011

Purpose: Gain further experience with class creation and use.  Practice the use of namespace for restricting the scope of functions. Also, using inline functions and default arguments to make code cleaner and simpler.  
********************************/
#pragma once

#include "MyShape.h"

namespace CS262 {
	class MyLine : public MyShape {
		public:
			// CONSTRUCTORS
			MyLine(); // initializes all properties of the line to default values
			MyShape* makeClone() const;

			// ACCESSORS

			// MODIFIERS

			// FUNCTIONS
			void draw(System::Drawing::Graphics^ g) const;
	};

} // end namespace

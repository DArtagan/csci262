/********************************
Name: William H. Weiskopf
Section: A
Date: September 23, 2011
********************************/
#pragma once

#include "MyShape.h"

namespace CS262 {
	class MyRect : public MyShape {
		public:
			// CONSTRUCTORS
			MyRect() : drawFilled(true) { } // initializes all properties of the rectangle to default values
			MyRect(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0), bool isFilled=true) : MyShape(thePoint1, thePoint2, theColor), drawFilled(isFilled) {} //Initializes MyRect to given values
			MyShape* makeClone() const;

			// ACCESSORS

			// MODIFIERS
			void setFilled(bool isFilled ) { drawFilled = isFilled; }

			// FUNCTIONS
			void draw(System::Drawing::Graphics^ g) const;
			// Postcondition: Returns true if x and y values are the same,
			// false otherwise
		

		private: 
			// x and y are represented in our Point class as float to
			// faciliate calculations.
			bool drawFilled;
	};

} // end namespace

/********************************
Name: William H. Weiskopf
Section: A
Date: September 20, 2011

Purpose: Gain further experience with class creation and use.  Practice the use of namespace for restricting the scope of functions. Also, using inline functions and default arguments to make code cleaner and simpler.  
********************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Color.h"
#include "Point.h"

namespace CS262 {
	class MyRect {
		public:
			// CONSTRUCTORS
			MyRect() : Point1(10,10), Point2(100,100), color(Color(0,0,0)) {}

			// Postcondition: MyRect has been initialized to (thePoint1, thePoint2, theColor, isFilled) with theColor defaulting to black and isFilled defaulting to true
			MyRect(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0)) : Point1(thePoint1), Point2(thePoint2), color(theColor), drawFilled(isFilled) {}

			// ACCESSORS
		

			// MODIFIERS
			void setPoint1(Point thePoint1) { Point1 = thePoint1; }
			void setPoint2(Point thePoint2) { Point2 = thePoint2; }
			void setColor(Color theColor) { color = theColor; }

			// FUNCTIONS
			virtual void draw(System::Drawing::Graphics^) const=0; //Note: You might want to take out the carrot
			virtual MyShape* makeClone(void) const = 0;

			// Postcondition: Returns true if x and y values are the same,
			// false otherwise
		

		private: 
			// x and y are represented in our Point class as float to
			// faciliate calculations.
			Point Point1, Point2;
			Color color;
	};

} // end namespace

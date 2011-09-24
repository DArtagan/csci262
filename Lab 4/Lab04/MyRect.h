/********************************
Name: William H. Weiskopf
Section: A
Date: September 20, 2011

Purpose: Gain further experience with class creation and use.  Practice the use of namespace for restricting the scope of functions. Also, using inline functions and default arguments to make code cleaner and simpler.  
********************************/
#pragma once

#include "MyShape.h"

namespace CS262 {
	class MyRect : public MyShape {
		public:
			// CONSTRUCTORS
			MyRect() : drawFilled(true) { } // initializes all properties of the rectangle to default values
			MyRect(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0), bool isFilled=true) : Point1(thePoint1), Point2(thePoint2), color(theColor), drawFilled(isFilled) {} //Initializes MyRect to given values
			MyShape* makeClone() const;

			// ACCESSORS
		

			// MODIFIERS
			void setPoint1(Point thePoint1) { Point1 = thePoint1; }
			void setPoint2(Point thePoint2) { Point2 = thePoint2; }
			void setColor(Color theColor) { color = theColor; }
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

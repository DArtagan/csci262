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
			MyLine(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0), bool isFilled=true) : Point1(thePoint1), Point2(thePoint2), color(theColor) {} //Initializes MyLine to given values
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
	};

} // end namespace

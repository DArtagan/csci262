/********************************
Name: William H. Weiskopf
Section: A
Date: September 23, 2011
********************************/
#pragma once

#include "MyShape.h"

namespace CS262 {
	class MyLine : public MyShape {
		public:
			// CONSTRUCTORS
			MyLine(); // initializes all properties of the line to default values
			MyLine(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0)) : MyShape(thePoint1, thePoint2, theColor) {} //Initializes MyLine to given values
			MyShape* makeClone() const;

			// ACCESSORS

			// MODIFIERS

			// FUNCTIONS
			void draw(System::Drawing::Graphics^ g) const;
	};

} // end namespace

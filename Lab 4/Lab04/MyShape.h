/********************************
Name: William H. Weiskopf
Section: A
Date: September 23, 2011

Purpose: To create abstract classes that different child classes can inherit from.
********************************/
#pragma once
#include <iostream>
#include <cmath>
#include "Color.h"
#include "Point.h"

namespace CS262 {
	class MyShape {
		public:
			// CONSTRUCTORS
			MyShape() : Point1(10,10), Point2(100,100), color(Color(0,0,0)) {}

			// Postcondition: MyShape has been initialized to (thePoint1, thePoint2, theColor) with theColor defaulting to black
			MyShape(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0)) : Point1(thePoint1), Point2(thePoint2), color(theColor) {}

			// ACCESSORS
		

			// MODIFIERS
			void setPoint1(Point thePoint1) { Point1 = thePoint1; }
			void setPoint2(Point thePoint2) { Point2 = thePoint2; }
			void setColor(Color theColor) { color = theColor; }

			// FUNCTIONS
			virtual void draw(System::Drawing::Graphics^ g) const = 0;
			virtual MyShape* makeClone(void) const = 0;

		protected: 
			// x and y are represented in our Point class as float to
			// faciliate calculations.
			Point Point1, Point2;
			Color color;
	};

} // end namespace

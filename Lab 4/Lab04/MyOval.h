/********************************
Name: William H. Weiskopf
Section: A
Date: September 23, 2011
********************************/
#pragma once

#include "MyShape.h"

namespace CS262 {
	class MyOval : public MyShape {
		public:
			// CONSTRUCTORS
			MyOval() : drawFilled(true) { } // initializes all properties of the oval to default values
			MyOval(Point thePoint1, Point thePoint2, Color theColor=Color(0,0,0), bool isFilled=true) : MyShape(thePoint1, thePoint2, theColor), drawFilled(isFilled) {} //Initializes MyOval to given values
			MyShape* makeClone() const;

			// ACCESSORS
		
			// MODIFIERS
			void setFilled(bool isFilled ) { drawFilled = isFilled; }

			// FUNCTIONS
			void draw(System::Drawing::Graphics^ g) const;
			// Postcondition: Returns true if x and y values are the same,
			// false otherwise
		

		private: 
			bool drawFilled;
	};

} // end namespace
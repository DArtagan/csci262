#include "MyLine.h"

using namespace std;
using System::Drawing::Color;
using System::Drawing::Point;
using System::Drawing::Graphics;
using System::Drawing::Pen;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace CS262 {
	void MyLine::draw(System::Drawing::Graphics^ g) const {

		// convert color variable from our Color class to .Net color
		System::Drawing::Color drawColor = color.getNetColor();

		// YOUR NAME FOR drawFilled MAY BE DIFFERENT
		Pen^ pen = gcnew Pen(color.getNetColor());
		g->DrawLine(pen,
			Point1.getX(), Point1.getY(),
			Point2.getX(), Point2.getY()
		);
	}
	
	// return a pointer to a copy of the calling object (*this)
	MyShape* MyLine::makeClone() const
	{
		return new MyLine(*this);
	}
}
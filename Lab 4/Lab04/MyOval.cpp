#include "MyOval.h"

using namespace std;
using System::Drawing::Color;
using System::Drawing::Point;
using System::Drawing::Graphics;
using System::Drawing::Pen;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace CS262 {
	void MyOval::draw(System::Drawing::Graphics^ g) const {
		float height, width, x, y;

		height = fabs(Point1.getY()-Point2.getY());
		width = fabs(Point1.getX()-Point2.getX());
		x = min(Point1.getX(),Point2.getX());
		y = min(Point1.getY(),Point2.getY());

		// convert color variable from our Color class to .Net colro
		System::Drawing::Color drawColor = color.getNetColor();

		if (drawFilled)
		{
			// draw a solid oval
			Brush^ hbr = gcnew SolidBrush(color.getNetColor());
			g->FillEllipse(hbr, x, y, width, height);
		}
		else   
		{
			// draw just the outline using pen
			Pen^ pen = gcnew Pen(color.getNetColor());
			g->DrawEllipse(pen, x, y, width, height);
		}
	}
	
	// return a pointer to a copy of the calling object (*this)
	MyShape* MyOval::makeClone() const
	{
		return new MyOval(*this);
	}
}
#include "MyRect.h"
#include <iostream>

using namespace std;
using System::Drawing::Color;
using System::Drawing::Point;
using System::Drawing::Graphics;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

void CS262::MyRect::draw(System::Drawing::Graphics^) {
	float height, width, x, y;

	height = fabs(Point1.getY()-Point2.getY());
	width = fabs(Point1.getX()-Point2.getX());
	x = min(Point1.getX(),Point2.getX());
	y = min(Point1.getY(),Point2.getY());

	// convert color variable from our Color class to .Net color
	// YOUR NAME FOR color MAY BE DIFFERENT
	System::Drawing::Color drawColor = color.getNetColor();

	// YOUR NAME FOR drawFilled MAY BE DIFFERENT
	if (filled)  // create solid brush for drawing
	{
		Brush^ hbr = gcnew SolidBrush(drawColor);
		g->FillRectangle(hbr, x, y, width, height);
	}
	else  // draw just outline using pen
	{
		Pen^ pen = gcnew Pen(drawColor);
		g->DrawRectangle(pen, x, y, width, height); 
	}
}
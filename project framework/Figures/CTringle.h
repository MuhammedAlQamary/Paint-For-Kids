#pragma once
#include "CFigure.h"
class CTringle : public CFigure
{
private:
	Point Point1;
	Point Point2;
	Point Point3;
	//int length;
public:
	CTringle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};


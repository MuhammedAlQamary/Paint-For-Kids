#pragma once
#include "CFigure.h"
class CRectangle :
    public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};


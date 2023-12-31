#pragma once
#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};
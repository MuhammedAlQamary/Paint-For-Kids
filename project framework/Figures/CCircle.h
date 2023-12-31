#pragma once
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
public:
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};


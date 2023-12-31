#ifndef CLINE_H
#define CLINE_H
#include "CFigure.h"


class CLine : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
	int length;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
};



#endif
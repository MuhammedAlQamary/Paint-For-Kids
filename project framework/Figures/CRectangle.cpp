#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	//length = len;
}


void CRectangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Rectangle on the screen	
	pGUI->DrawRectangle(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);


}
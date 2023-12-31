#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	//length = len;
}


void CLine::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawLine to draw a Square on the screen	
	pGUI->DrawLine(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);


}
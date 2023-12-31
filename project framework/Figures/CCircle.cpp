#include "CCircle.h"



CCircle::CCircle(Point P1, int len, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	//BottomRightCorner = P2;
	length = len;
}


void CCircle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Square on the screen	
	pGUI->DrawCircle(TopLeftCorner, length, FigGfxInfo, Selected);

}
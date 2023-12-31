#include "CEllipse.h"



CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	//length = len;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawElipse to draw a Square on the screen	
	pGUI->DrawEllipse(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);

}
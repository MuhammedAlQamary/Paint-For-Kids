#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
	
bool CSquare::Get(int x, int y) const
{
	if (x>=TopLeftCorner.x&&x<=TopLeftCorner.x+ length&&
		y>= TopLeftCorner.y&& TopLeftCorner.y+length)
		return true;
	return false;
}

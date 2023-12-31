#include "CTringle.h"

CTringle::CTringle(Point _P1, Point _P2, Point _P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = _P1;
	Point2 = _P2;
	Point3 = _P3;
	//length = len;
}


void CTringle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawTriangle to draw a Square on the screen	
	pGUI->DrawTringle(Point1, Point2, Point3, FigGfxInfo, Selected);


}
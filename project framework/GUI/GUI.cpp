#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}


string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)							// 27 ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		else if (Key == 13)						// 13 ENTER key is pressed
			return Label;
		//else if (Key == 110 || Key == 78)
		//	return "";
		if (Key == 8)							// 08 BackSpace
		{
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);

		}
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LIN : return DRAW_LINE;
			case ITM_REC: return DRAW_RECTANGLE;
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI: return DRAW_TRI;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LIN] = "images\\MenuItems\\Menu_Lin.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\Menu_Rectangle.jpg";
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Ellipse.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tringle.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	//MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;


	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::DrawSquare(Point P1, int length, GfxInfo SquareGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = SquareGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;		
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);

}

void GUI::DrawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	//pWind->DrawLine		(P1.x, P1.y, P1.x + length, P1.y + length, style);

}

void GUI::DrawEllipse(Point P1, Point P2, GfxInfo EllipseGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = EllipseGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, EllipseGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (EllipseGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else
		style = FRAME;


	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawCircle(Point P1, int length, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawCircle(P1.x, P1.y, length, style);

}

//void GUI::DrawCircle(Point P1, int length, GfxInfo CircleGfxInfo, bool selected) const
//{
//	color DrawingClr;
//	if (selected)
//		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
//	else
//		DrawingClr = CircleGfxInfo.DrawClr;
//
//	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width
//
//	drawstyle style;
//	if (CircleGfxInfo.isFilled)
//	{
//		style = FILLED;
//		pWind->SetBrush(CircleGfxInfo.FillClr);
//	}
//	else
//		style = FRAME;
//
//
//	//pWind->DrawRectangle(P1.x, P1.y, P1.x + length, P1.y + length, style);
//	pWind->DrawCircle(P1.x, P1.y, length, style);
//
//}

void GUI::DrawTringle(Point P1, Point P2, Point P3, GfxInfo TringleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TringleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TringleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TringleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TringleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);

}



//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}


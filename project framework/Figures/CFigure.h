#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	virtual bool Get(int x, int y) const = 0;	//Check if the point inside The Figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

};

#endif
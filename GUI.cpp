#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_EXIT: return OP_EXIT;
			case ICON_DEL:  return DEL;
			case ICON_CH_DRAW_COLOR: return CH_PEN_COLOR;
			case ICON_CH_FULL_COLOR: return CHNG_FILL_CLR;
			case ICON_CH_PEN_WIDTH: return CH_PEN_Width;
			case ICON_CH_Border_Color: return CH_Border_Color;
			case ICON_CH_FiLL_Color_SinGLE: return CH_Fill_Color_singleshape;
			case ICON_CH_BORDER_WIDTH_SinGLE: return CH_Border_Width;

			case ICON_Modeplay: return TO_PLAY;

				

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_3: return TO_DRAW;



			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\Menu_del.jpg";
	MenuIconImages[ICON_CH_DRAW_COLOR]="images\\MenuIcons\\Menu_CH_DRAWCOLOR.jpg";
	MenuIconImages[ICON_CH_FULL_COLOR] = "images\\MenuIcons\\Menu_Fullcolor.jpg";
	MenuIconImages[ICON_CH_PEN_WIDTH] = "images\\MenuIcons\\Menu_CHWidth.jpg";
	MenuIconImages[ICON_CH_Border_Color] = "images\\MenuIcons\\Menu_bordercolor.jpg";
	MenuIconImages[ICON_CH_FiLL_Color_SinGLE] = "images\\MenuIcons\\Menu_fillcolor.jpg";
	MenuIconImages[ICON_CH_BORDER_WIDTH_SinGLE] = "images\\MenuIcons\\Menu_borderWidth.jpg";
	MenuIconImages[ICON_Modeplay] = "images\\MenuIcons\\Menu_playMode.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;

	string MenuIconImages[PLAY_ICON_COUNT];

	MenuIconImages[ICON_1] = "images\\MenuIcons\\Menu_CH_DRAWCOLOR.jpg";
	MenuIconImages[ICON_2] = "images\\MenuIcons\\Menu_CH_DRAWCOLOR.jpg";
	MenuIconImages[ICON_3] = "images\\MenuIcons\\Menu_CH_DRAWCOLOR.jpg";


	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);


	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

	///TODO: write code to create Play mode menu
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);


}


void GUI::ClearToolBar() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0,0 ,width , ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
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

}

void GUI::setDrawColor(color newColor)
{
	DrawColor = newColor;
}

void GUI::setFullColor(color newColor)
{
	FillColor = newColor;
}

void GUI::setPenWidth(int  newWidth)
{
	PenWidth = newWidth;
}

void GUI::setBOrderColor_singleShape(color newColor)
{
	color BORDERcolor_singleshape= newColor;
}

void GUI::setFILLColor_singleShape(color newColor)
{
	color fIllcolor_singleshape = newColor;
}

void GUI::setBorderWidth_singleShape(int newNumber)
{
	color BorderWidth_singleShape = newNumber;
}

void GUI::setPlayMood()
{
	InterfaceMode = MODE_PLAY;
	ClearToolBar();
	CreatePlayToolBar();
}

void GUI::setDRAWMood()
{
	InterfaceMode = MODE_DRAW;
	ClearToolBar();
	CreateDrawToolBar();
}


//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}


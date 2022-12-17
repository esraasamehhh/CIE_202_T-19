#include "Graph.h"
#include "../GUI/GUI.h"
#include <vector>

using namespace std;

Graph::Graph()
{
	selectedShape = nullptr;
}


Graph::~Graph()
{
	while (shapesList.size())
	{
		shape* p = *shapesList.begin();
		shapesList.erase(shapesList.begin());
		delete p;
	}
}






//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL

	///Add your code here to search for a shape given a point x,y	

	return shapesList[0];
}

void Graph::Delshape() 
{
	for (auto i = shapesList.begin(); i < shapesList.end(); i++)
	{
		if ((*i)->IsSelected())
		{
			shape* p = *i;
			shapesList.erase(i);
			delete p;
			break;
		}
	}
		
}

void Graph::setBordercolor_Single(color  newcolor, shape* pshape)
{
	pshape->ChngDrawClr(newcolor);
}
void Graph::setFillcolor_Single(color  newcolor, shape* pshape)
{
	pshape->ChngFillClr(newcolor);
}

void Graph::setBorderWidth_Single(int  nwNumber, shape* pshape)
{
	pshape->ChngBorderWidth(nwNumber);
}

#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\deleteShape.h"
#include "operations\opChangeDrawColor.h"
#include "operations\opChangeFullColor.h"
#include "operations\opChangepenwidth.h"
#include "operations\opChangeBorderColor_single.h"
#include "operations\opChangeFillColor_SingleShape.h"
#include "operations\opChangeBorderWidth_single.h"
#include "operations\PlayMood.h"
#include "operations\DRAWMood.h"
#include "operations\EXIT.h"


//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;
		case DEL:
			pOp = new deleteShape(this);
			break;
		case CH_PEN_COLOR:
			pOp = new opChangeDrawColor(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new opChangeFullColor(this);
			break;

		case CH_PEN_Width:
			pOp = new opChangepenwidth(this);
			break;
			
		case CH_Border_Color:
			pOp = new opChangeBorderColor_single(this);
			break;

		case CH_Fill_Color_singleshape:
			pOp = new opChangeFillColor_SingleShape(this);
			break;

		case CH_Border_Width:
			pOp = new opChangeBorderWidth_single(this);
			break;

		case TO_PLAY:
			pOp = new PlayMood(this);
			break;

		case TO_DRAW:
			pOp = new DRAWMood(this);
			break;

		case DRAW_LINE:
			///create AddLineoperation here

			break;

		case OP_EXIT:
			pOp = new EXIT(this);

			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != OP_EXIT);

}
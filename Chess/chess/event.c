#include "chess.h"



void clickEvent(SDL_Event event)
{
	
	static int selected = 0;
	static CASE prevCase = { NULL, NULL };
	
	CASE selectedCase = { event.button.x / 100, event.button.y / 100 };
	PIECES* pieceToMove = &pieces[selectedCase.caseX][selectedCase.caseY];


	if (selected == 1)
	{
		if (selectedCase.caseX == prevCase.caseX && selectedCase.caseY == prevCase.caseY)
		{
			pieceToMove->select = 0;
			prevCase.caseX = NULL;
			prevCase.caseY = NULL;
			selected = 0;
			resetPossible();
		}
		else
		{
			if (move(prevCase, selectedCase))
			{
				pieceToMove->select = 0;
				selected = 0;
				resetPossible();
				nextPlayer();
			}
			
		}
	}

	else if(pieceToMove->color == colorTurn)
	{
		if (pieceToMove->piece != none)
		{
			pieceToMove->select = 1;
			selected = 1;
			prevCase = selectedCase;
			checkPossible(selectedCase);

		}
	}
}






int waitEvent(SDL_Window* window)
{
	SDL_Event event;
	SDL_WaitEvent(&event);

	switch (event.type)	
	{
	case SDL_QUIT:
		return end;
		break;
	case SDL_MOUSEBUTTONUP:
		clickEvent(event);
		displayBoard(window);
	default:
		return 1;
		break;
	}

	
}


void nextPlayer()
{
	if(colorTurn == white)colorTurn = black;
	else colorTurn = white;
}
#include "chess.h"



int move(CASE pieceToMove, CASE toNewCase)
{
	PIECES empty = { none,0, 0, "images/pieces/none.bmp",0 };
	PIECES* piece = &pieces[pieceToMove.caseX][pieceToMove.caseY];
	
	if (possible[toNewCase.caseX][toNewCase.caseY].YoN == 1)
	{
		piece->move++;
		pieces[toNewCase.caseX][toNewCase.caseY] = *piece;
		*piece = empty;
		return 1;
	}
	else
	{
		return 0;
	}
}
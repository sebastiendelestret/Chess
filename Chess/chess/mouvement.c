#include "chess.h"


int checkMove(CASE fromCase, CASE toCase)
{
	switch (pieces[fromCase.caseX][fromCase.caseY].piece)
	{
	case pawn:
		return movePawn(fromCase, toCase);


	default:
		return 0;
		break;
	}
	
}




int movePawn(CASE pieceToMove, CASE toNewCase)
{
	PIECES empty = { none,0, 0, "images/pieces/none.bmp" };
	PIECES* piece = &pieces[pieceToMove.caseX][pieceToMove.caseY];
	
	if (possible[toNewCase.caseX][toNewCase.caseY].YoN == 1)
	{
		pieces[toNewCase.caseX][toNewCase.caseY] = *piece;
		*piece = empty;
		return 1;
	}
	else
	{
		return 0;
	}
}
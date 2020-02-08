#include "chess.h"


void resetPossible()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			possible[i][j].YoN = 0;
		}
	}
}





int checkPossible(CASE pieceToMove)
{
	switch (pieces[pieceToMove.caseX][pieceToMove.caseY].piece)
	{
	case pawn:
		return authorizedMovePawn(pieceToMove);
	default:
		return 0;
		break;
	}
}








int authorizedMovePawn(CASE pieceToMove)
{
	PIECES piece = pieces[pieceToMove.caseX][pieceToMove.caseY];

	CASE check;
	int i;
	switch (piece.color)
	{
	case 2:
		if (pieceToMove.caseY - 1 >= 0 && pieces[pieceToMove.caseX][pieceToMove.caseY-1].piece == none)
		{
			if (pieceToMove.caseY == 6 && pieces[pieceToMove.caseX][pieceToMove.caseY - 2].piece == none) {
				possible[pieceToMove.caseX][pieceToMove.caseY - 2].YoN = 1;
			}
			possible[pieceToMove.caseX][pieceToMove.caseY - 1].YoN = 1;
		}

		if (pieces[pieceToMove.caseX - 1][pieceToMove.caseY - 1].piece != none)
		{
			possible[pieceToMove.caseX - 1][pieceToMove.caseY - 1].YoN = 1;
		}
		if (pieces[pieceToMove.caseX + 1][pieceToMove.caseY - 1].piece != none)
		{
			possible[pieceToMove.caseX + 1][pieceToMove.caseY - 1].YoN = 1;
		}
		return 1;
		break;
	case 1:
		if (pieceToMove.caseY + 1 <= 7 && pieces[pieceToMove.caseX][pieceToMove.caseY + 1].piece == none)
		{
			if (pieceToMove.caseY ==1 && pieces[pieceToMove.caseX][pieceToMove.caseY + 2].piece == none) {
				possible[pieceToMove.caseX][pieceToMove.caseY + 2].YoN = 1;
			}
			possible[pieceToMove.caseX][pieceToMove.caseY + 1].YoN = 1;
		}
		if (pieces[pieceToMove.caseX - 1][pieceToMove.caseY + 1].piece != none)
		{
			possible[pieceToMove.caseX - 1][pieceToMove.caseY + 1].YoN = 1;
		}
		if (pieces[pieceToMove.caseX + 1][pieceToMove.caseY + 1].piece != none)
		{
			possible[pieceToMove.caseX + 1][pieceToMove.caseY + 1].YoN = 1;
		}
		return 1;
		break;
	}

}

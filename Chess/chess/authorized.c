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





int checkPossible(CASE pos)
{
	switch (pieces[pos.caseX][pos.caseY].piece)
	{
	case pawn:
		return authorizedMovePawn(pos);
	default:
		return 0;
		break;
	}
}








int authorizedMovePawn(CASE pos)   //ajouter prise en passant
{
	PIECES piece = pieces[pos.caseX][pos.caseY];
	PIECES check;


	int i = 1, canMove = 0;
	switch (piece.color)
	{
	case 2:
		if (pos.caseY-1 >= 0)canMove = 1;
		i = -1;
		break;
	case 1:
		if (pos.caseY+1 <= 7)canMove = 1;
		break;
	}

	if (canMove)
	{

		check = pieces[pos.caseX][(pos.caseY) + i];
		if (check.piece == none)
		{
			if (check.color != piece.color)
			{
				possible[pos.caseX][(pos.caseY) + i].YoN = 1;
			}
			check = pieces[pos.caseX][(pos.caseY) + 2 * i];
			if (piece.move == 0 && check.color != piece.color) {
				possible[pos.caseX][(pos.caseY) + 2 * i].YoN = 1;
			}
		}
		

		for (int j = -1; j <= 1; j += 2)
		{
			check = pieces[pos.caseX + j][(pos.caseY +i)];
			if (check.piece != none && check.color != piece.color)
			{
				possible[pos.caseX + j][pos.caseY + i].YoN = 1;
			}
		}
		return 1;
	}

	return 0;
}

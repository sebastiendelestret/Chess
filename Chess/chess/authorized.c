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
	case rook:
		return authorizedMoveRook(pos);
	case knight:
		return authorizedMoveKnight(pos);
	default:
		return 0;
		break;
	}
}



int authorizedMoveKnight(CASE pos)
{
	PIECES piece = pieces[pos.caseX][pos.caseY];
	PIECES check;
	int j;

	for (int y = -2; y <= 2; y ++)
	{
		if (pos.caseY + y >= 0 && pos.caseY + y < 8 && y!=0)
		{
			if (abs(y) == 2) j = -1;
			else j = -2;
			for (int x=j; x <= abs(j); x+=2*abs(j))
			{
				if (pos.caseX + x >= 0 && pos.caseX + x < 8)
				{
					check = pieces[pos.caseX + x][pos.caseY + y];
					if (check.color != piece.color)
					{
						possible[pos.caseX + x][pos.caseY + y].YoN = 1;
					}
				}
			}
		}
	}
	

	return 1;
}


int authorizedMoveRook(CASE pos)
{
	PIECES piece = pieces[pos.caseX][pos.caseY];
	PIECES check;
	int k, j;
	
	for (int i = 1; i >= -1; i -= 2)
	{
		j = i;
		k = 1;
		do
		{
			if (pos.caseX + j >= 0 && pos.caseX + j < 8)
			{
				check = pieces[pos.caseX + j][pos.caseY];
				if (check.piece == none)
				{
					possible[pos.caseX + j][pos.caseY].YoN = 1;
				
				}
				else if (check.color != piece.color)
				{
					possible[pos.caseX + j][pos.caseY].YoN = 1;
					k = 0;
				}
				else k = 0;
				j += i;
			}
			else k = 0;
			
		} while (k);
		j = i; k = 1;
		do
		{
			if (pos.caseY + j >= 0 && pos.caseY + j < 8)
			{
				check = pieces[pos.caseX][pos.caseY + j];
				if (check.piece == none)
				{
					possible[pos.caseX][pos.caseY + j].YoN = 1;
				}
				else if (check.color != piece.color)
				{
					possible[pos.caseX][pos.caseY + j].YoN = 1;
					k = 0;
				}
				else k = 0;
				j += i;

			}
			else k = 0;
		} while (k);
		
	}
	return 1;
}


int authorizedMovePawn(CASE pos)   //ajouter prise en passant + interdit manger roi + échange pion/dame
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
			if (pos.caseX + j >= 0 && pos.caseX + j < 8)
			{
				check = pieces[pos.caseX + j][(pos.caseY + i)];
				if (check.piece != none && check.color != piece.color)
				{
					possible[pos.caseX + j][pos.caseY + i].YoN = 1;
				}
			}
		}
		return 1;
	}

	return 0;
}

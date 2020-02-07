#include "chess.h"

PIECES blackPawn = { "pawn","b",0, "images/pieces/pawnB.bmp" };
PIECES whitePawn = { "pawn","w",0, "images/pieces/pawnW.bmp" };
PIECES blackRook = { "rook","b",0, "images/pieces/rookB.bmp" };
PIECES whiteRook = { "rook","w",0, "images/pieces/rookW.bmp" };
PIECES darkKnight = { "kni","b",0, "images/pieces/knightB.bmp" };
PIECES whiteKnight = { "kni","w",0, "images/pieces/knightW.bmp" };
PIECES blackBishop = { "bish","b",0, "images/pieces/bishopB.bmp" };
PIECES whiteBishop = { "bish","w",0, "images/pieces/bishopW.bmp" };
PIECES blackQueen = { "quee","b",0, "images/pieces/queenB.bmp" };
PIECES whiteQueen = { "quee","w",0, "images/pieces/queenW.bmp" };
PIECES blackKing = { "king","b",0, "images/pieces/kingB.bmp" };
PIECES whiteKing = { "king","w",0, "images/pieces/kingW.bmp" };
PIECES none = { "none","n", 0, "images/pieces/none.bmp" };

void initChessBoard()
{

	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 0; j < 8; j += 2) //def chessboard
		{
			board[i][j] = white;
			board[i][j + 1] = black;
			board[i + 1][j] = black;
			board[i + 1][j + 1] = white;
		}
	}

	for (int i = 0; i < 8; i++) //place the pawns
	{
		pieces[i][1] = blackPawn;
		pieces[i][6] = whitePawn;
	}
	
	for (int i = 0; i < 8; i += 7) //pace the rooks
	{
		pieces[i][0] = blackRook;
		pieces[i][7] = whiteRook;
	}

	for (int i = 1; i < 7; i += 5)
	{
		pieces[i][0] = darkKnight;
		pieces[i][7] = whiteKnight;
	}

	for (int i = 2; i < 6; i += 3)
	{
		pieces[i][0] = blackBishop;
		pieces[i][7] = whiteBishop;
	}

	pieces[3][0] = blackQueen;
	pieces[3][7] = whiteQueen;
	pieces[4][0] = blackKing;
	pieces[4][7] = whiteKing;
	

	for (int i = 0; i < 8; i++)
	{
		for (int j = 2; j < 6; j++)
		{
			pieces[i][j] = none;
		}

	}
}

void displayBoard(SDL_Window* window)
{

	SDL_Surface* surface = NULL;




	SDL_Rect pos;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pos.x = i * 100;
			pos.y = j * 100;
			switch (board[i][j])
			{
			case white:
				surface = SDL_LoadBMP("images/whiteBG.bmp");
				break;
			case black:
				surface = SDL_LoadBMP("images/blackBG.bmp");
				break;
			}

			SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);
			surface = SDL_LoadBMP(pieces[i][j].file);
			
		
			SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));
			SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);
		




		}
	}

	SDL_FreeSurface(surface);
}

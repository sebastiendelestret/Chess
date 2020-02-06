#include "chess.h"


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

			switch (pieces[i][j])
			{
			case blackPawn:
				surface = SDL_LoadBMP("images/pieces/pawnB.bmp");
				break;
			case whitePawn:
				surface = SDL_LoadBMP("images/pieces/pawnW.bmp");
				break;
			case blackRook:
				surface = SDL_LoadBMP("images/pieces/rookB.bmp");
				break;
			case whiteRook:
				surface = SDL_LoadBMP("images/pieces/rookW.bmp");
				break;
			case darkKnight:
				surface = SDL_LoadBMP("images/pieces/knightB.bmp");
				break;
			case whiteKnight:
				surface = SDL_LoadBMP("images/pieces/knightW.bmp");
				break;
			case blackBishop:
				surface = SDL_LoadBMP("images/pieces/bishopB.bmp");
				break;
			case whiteBishop:
				surface = SDL_LoadBMP("images/pieces/bishopW.bmp");
				break;
			default:
				surface = SDL_LoadBMP("images/pieces/none.bmp");
				break;



			}

			SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));
			SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);




		}
	}

	SDL_FreeSurface(surface);
}

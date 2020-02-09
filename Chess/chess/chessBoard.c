#include "pieces.h"

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
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pieces[i][j] = empty;
		}

	}

	for (int i = 0; i < 8; i++) //place pawns
	{
		pieces[i][1] = blackPawn;
		pieces[i][6] = whitePawn;
	}

	for (int i = 0; i < 8; i += 7) //place rooks
	{
		pieces[i][0] = blackRook;
		pieces[i][7] = whiteRook;
	}
	for (int i = 1; i < 7; i += 5) //place knights
	{
		pieces[i][0] = darkKnight;
		pieces[i][7] = whiteKnight;
	}

	for (int i = 2; i < 6; i += 3) //place bishops
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
		for (int j = 0; j < 8; j++)
		{
			possible[i][j].YoN = 0;
			possible[i][j].file= "images/possible.bmp";
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
			if (pieces[i][j].select == 0)
			{
				SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));
			}
			SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);
		
			if (possible[i][j].YoN == 1)
			{
				surface = SDL_LoadBMP(possible[i][j].file);
				SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));
				SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);

			}



		}
	}
	SDL_UpdateWindowSurface(window);


	SDL_FreeSurface(surface);
}

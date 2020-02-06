#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define white 'w'
#define black 'b'
#define pawnB 'p'

int board[8][8];
int pieces[8][8];

void initChessBoard()
{

	for (int i = 0; i < 8 ; i+=2)
	{
		for (int j = 0; j < 8; j+=2) //def chessboard
		{
			board[i][j] = white;
			board[i][j + 1] = black;
			board[i+1][j] = black;
			board[i+1][j + 1] = white;
		}
	}

	for (int i = 0; i < 8; i++) //place the black pawns
	{
		pieces[i][1] = pawnB;
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
			case pawnB:
				surface = SDL_LoadBMP("images/pieces/pawnB.bmp");
				SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0));
				SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &pos);
			default:
				break;

			}

			


		}
	}
}

int main()
{
	SDL_Init(SDL_INIT_VIDEO);



	SDL_Window* window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
	initChessBoard(board);
	displayBoard(window);
	SDL_UpdateWindowSurface(window);

	
	Sleep(10000);


	SDL_Quit();
}


#include "chess.h"



int main()
{
	SDL_Init(SDL_INIT_VIDEO);



	SDL_Window* window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
	initChessBoard(board);
	displayBoard(window);
	SDL_UpdateWindowSurface(window);

	while (waitEvent());
	




	SDL_Quit();
}


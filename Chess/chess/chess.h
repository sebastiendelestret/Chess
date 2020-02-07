#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define white 'w'
#define black 'b'

typedef struct pieces {const char* piece;const char* color; int select; const char* file; } PIECES;



#define end 0

int board[8][8];

PIECES pieces[8][8];

typedef struct Case { int caseX; int caseY; } CASE;



void initChessBoard();
void displayBoard(SDL_Window* window);




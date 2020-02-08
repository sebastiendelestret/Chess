#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>


#define white 'w'
#define black 'b'
#define pawn 'p'
#define rook 'r'
#define bishop 'b'
#define knight 'k'
#define king 'K'
#define queen 'q'
#define none 'n'

typedef struct pieces { int piece; int color; int select; const char* file; } PIECES;
typedef struct Case { int caseX; int caseY; } CASE;
typedef struct select { CASE posSelect; PIECES pieceSelect; } SELECT;
typedef struct mark { int YoN; const char* file; } MARK;



#define end 0

int board[8][8];
PIECES pieces[8][8];
MARK possible[8][8];



void initChessBoard();
void displayBoard(SDL_Window* window);

void clickEvent(SDL_Event event);
int waitEvent(SDL_Window* window);

void resetPossible();
int checkPossible(CASE pieceToMove);
int authorizedMovePawn(CASE pieceToMove);

int checkMove(CASE fromCase, CASE toCase);
int movePawn(CASE pieceToMove, CASE toNewCase);






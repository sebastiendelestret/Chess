#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>


#define white 2
#define black 1
#define pawn 'p'
#define rook 'r'
#define bishop 'b'
#define knight 'k'
#define king 'K'
#define queen 'q'
#define none 'n'

typedef struct Case { int caseX; int caseY; } CASE;
typedef struct pieces { char piece; int color; int select; const char* file; int move; } PIECES;
typedef struct select { CASE posSelect; PIECES pieceSelect; } SELECT;
typedef struct mark { int YoN; const char* file; } MARK;



#define end 0

int board[8][8];
PIECES pieces[8][8];
MARK possible[8][8];

static int colorTurn = white;

//chessBoard.c functions
void initChessBoard();
void displayBoard(SDL_Window* window);

//event.c functions
void clickEvent(SDL_Event event);
int waitEvent(SDL_Window* window);
void nextPlayer();

//authorized.c functions
void resetPossible();
int checkPossible(CASE pos);
int authorizedMoveKnight(CASE pos);
int authorizedMoveRook(CASE pos);
int authorizedMovePawn(CASE pos);

//mouvement.c functions
int move(CASE pieceToMove, CASE toNewCase);






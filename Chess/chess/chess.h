#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


#define white 'w'
#define black 'b'

#define blackPawn 'wp'
#define whitePawn 'bp'
#define blackRook 'br'
#define whiteRook 'wr'
#define darkKnight 'dk'
#define whiteKnight 'wk'
#define blackBishop 'bb'
#define whiteBishop 'wb'


#define end 0

int board[8][8];
int pieces[8][8];
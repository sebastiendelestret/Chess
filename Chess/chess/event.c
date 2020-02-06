#include "chess.h"


int waitEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		return end;
		break;
	default:
		return 1;
		break;
	}


}
#include "chess.h"



CASE clickEvent(SDL_Event event)
{
	CASE select = { event.button.x / 8, event.button.y / 8 };
	return select;
}






int waitEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		return end;
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	default:
		return 1;
		break;
	}


}
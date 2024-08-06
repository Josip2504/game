#include "../include/game.h"

void	render(t_sdl *SDL)
{
	SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255);
	SDL_RenderClear(SDL->renderer);
	SDL_RenderPresent(SDL->renderer);
}

void	handler(SDL_Event	*event, int *game)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
			*game = 1;
		else if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				*game = 1;
		}
	}
}
#include "../include/game.h"

void	cleanup(t_sdl *SDL)
{
	SDL_DestroyRenderer(SDL->renderer);
	SDL_DestroyWindow(SDL->window);
	SDL_Quit();
}
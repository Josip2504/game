#include "../include/game.h"

void	cleanup(s_sdl *SDL)
{
	SDL_DestroyRenderer(SDL->renderer);
	SDL_DestroyWindow(SDL->window);
	SDL_Quit();
}
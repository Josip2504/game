#include "../include/game.h"

void	init(s_sdl	*SDL)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GetCurrentDisplayMode(0, &SDL->display_mode);
	SDL->width = SDL->display_mode.w;
	SDL->height = SDL->display_mode.h;
	SDL_CreateWindowAndRenderer(SDL->width, SDL->height, SDL_WINDOW_SHOWN, &SDL->window, &SDL->renderer);
	SDL_SetWindowTitle(SDL->window, "Full Screen Window");
}

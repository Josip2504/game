#include "../include/game.h"

void	cleanup(char **map, int rows, t_sdl *SDL)
{
	for (int i = 0; i < rows; i++)
		free(map[i]);
	free(map);
	SDL_DestroyRenderer(SDL->renderer);
	SDL_DestroyWindow(SDL->window);
	SDL_Quit();
}
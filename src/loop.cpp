#include "../include/game.h"

void handle_input(char **map, t_data *d, SDL_Event *event)
{
	int new_x = d->player_x;
	int new_y = d->player_y;
	switch (event->key.keysym.sym)
	{
		case SDLK_UP:
		case SDLK_w:
			new_y -= 1;
			break;
		case SDLK_DOWN:
		case SDLK_s:
			new_y += 1;
			break;
		case SDLK_LEFT:
		case SDLK_a:
			new_x -= 1;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			new_x += 1;
			break;
		default:
			return;
	}
	if (new_x >= 0 && new_x < d->cols && new_y >= 0 && new_y < d->rows && map[new_y][new_x] != '1')
	{
		map[d->player_y][d->player_x] = '0';
		map[new_y][new_x] = 'P';
		d->player_x = new_x;
		d->player_y = new_y;
	}
}

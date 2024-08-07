#include "include/game.h"

int main(int argc, char* argv[])
{
	t_sdl SDL;
	SDL_Event event;
	t_data data = {0};
	char **map;

	map = read_map("maps/1.txt", &data);
	init(&SDL);
	while (!data.game)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				data.game = 1;
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					data.game = 1;
				else
					handle_input(map, &data, &event);
			}
		}
		SDL_SetRenderDrawColor(SDL.renderer, 0, 0, 0, 255);
		SDL_RenderClear(SDL.renderer);
		render_map(&SDL, map, data.rows, data.cols);
		SDL_RenderPresent(SDL.renderer);
	}
	cleanup(map, data.rows, &SDL);
	return 0;
}

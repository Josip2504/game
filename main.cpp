#include "include/game.h"

void render_map(t_sdl *SDL, char map[7][10])
{
    int map_width = 9 * CELL_SIZE;
    int map_height = 7 * CELL_SIZE;
    int offset_x = (SDL->width - map_width) / 2;
    int offset_y = (SDL->height - map_height) / 2;

    for (int y = 0; y < 7; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            SDL_Rect cell = {offset_x + x * CELL_SIZE, offset_y + y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            if (map[y][x] == '1')
            {
                SDL_SetRenderDrawColor(SDL->renderer, 255, 255, 255, 255); // White for walls
            }
            else if (map[y][x] == '0')
            {
                SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255); // Black for empty space
            }
            else if (map[y][x] == 'P')
            {
                SDL_SetRenderDrawColor(SDL->renderer, 255, 0, 0, 255); // Red for player
            }
            SDL_RenderFillRect(SDL->renderer, &cell);
        }
    }
}


void read_map(const char *filename, char map[7][10])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Failed to open map file.\n");
        exit(1);
    }

    for (int i = 0; i < 7; i++)
    {
        fgets(map[i], 10, file);
    }

    fclose(file);
}


int	main(int argc, char* argv[])
{
	t_sdl		SDL;
	SDL_Event	event;
	int 		game;
	char		map[7][10];

	game = 0;
	read_map("maps/1.txt", map);
	init(&SDL);
	while (!game)
	{
		handler(&event, &game);
        SDL_SetRenderDrawColor(SDL.renderer, 0, 0, 0, 255);
        SDL_RenderClear(SDL.renderer);
        render_map(&SDL, map);
        SDL_RenderPresent(SDL.renderer);
	}
	cleanup(&SDL);
	return 0;
}
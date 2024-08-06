#include "../include/game.h"

void	render_map(t_sdl *SDL, char **map, int rows, int cols)
{
	int	map_width = cols * CELL_SIZE;
	int	map_height = rows * CELL_SIZE;
	int	offset_x = (SDL->width - map_width) / 2;
	int	offset_y = (SDL->height - map_height) / 2;

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			SDL_Rect cell = {offset_x + x * CELL_SIZE, offset_y + y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
			if (map[y][x] == '1')
				SDL_SetRenderDrawColor(SDL->renderer, 255, 255, 255, 255); // White for walls
			else if (map[y][x] == '0')
				SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255); // Black for empty space
			else if (map[y][x] == 'P')
				SDL_SetRenderDrawColor(SDL->renderer, 255, 0, 0, 255); // Red for player
			else
				SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 255, 255); // Blue for undefined
			SDL_RenderFillRect(SDL->renderer, &cell);
		}
	}
}

char**	read_map(const char *filename, int *rows, int *cols)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Failed to open map file.\n");
		exit(1);
	}
	size_t buffer_size = 128;
	char *buffer = (char *)malloc(buffer_size);
	*rows = 0;
	*cols = 0;
	while (fgets(buffer, buffer_size, file))
	{
		while (strchr(buffer, '\n') == NULL && !feof(file))
		{
			buffer_size *= 2;
			buffer = (char *)realloc(buffer, buffer_size);
			fgets(buffer + strlen(buffer), buffer_size / 2, file);
		}

		(*rows)++;
		int len = strlen(buffer);
		if (buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
			len--;
		}
		if (len > *cols)
		{
			*cols = len;
		}
	}
	char **map = (char **)malloc(*rows * sizeof(char *));
	for (int i = 0; i < *rows; i++)
	{
		map[i] = (char *)malloc(*cols * sizeof(char));
	}
	rewind(file);
	for (int i = 0; i < *rows; i++)
	{
		fgets(buffer, buffer_size, file);
		for (int j = 0; j < *cols; j++)
		{
			if (j < strlen(buffer))
				map[i][j] = buffer[j];
			else
				map[i][j] = ' '; // pad with spaces if line is shorter
		}
	}

	free(buffer);
	fclose(file);
	return map;
}

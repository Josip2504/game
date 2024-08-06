#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define CELL_SIZE 64

typedef struct	s_sdl
{
	SDL_DisplayMode	display_mode;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int 			width;
	int 			height;
}		t_sdl;

//render
char**	read_map(const char *filename, int *rows, int *cols);
void	render_map(t_sdl *SDL, char **map, int rows, int cols);

// init
void	init(t_sdl	*SDL);

// render
void	render(t_sdl *SDL);
void	handler(SDL_Event *event, int *game);

// cleanup
void	cleanup(char **map, int rows, t_sdl *SDL);

#endif
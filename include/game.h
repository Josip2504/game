#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>

# define CELL_SIZE 64

typedef struct	s_sdl
{
	SDL_DisplayMode	display_mode;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int 			width;
	int 			height;
}		t_sdl;

// init
void	init(s_sdl	*SDL);

// render
void	render(t_sdl *SDL);
void	handler(SDL_Event *event, int *game);

// cleanup
void	cleanup(s_sdl *SDL);

#endif
#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
#include "menu.h"
typedef struct 
{
	SDL_Surface *back;
	SDL_Surface*Dot;
	SDL_Rect posBlit;
	SDL_Rect posDot;
}Minimap;

void Init_MiniMap(Minimap*m,perso p);
void Display_MiniMap(Minimap*m,fenetre show);
void Update_MiniMap(Minimap *m,perso p);

#endif

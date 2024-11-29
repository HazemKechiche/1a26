#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "menu.h"

typedef struct 
{
	SDL_Surface * persoTab[2][3];
	SDL_Rect posperso;
	int life;
int vh , vv,direction,frame;

	
	
	
}perso;

void init(perso* p);
void afficherPerso(perso *p,fenetre show);
void deplacerPerso(perso *p);
void deplacerPersoACC(perso *p);
void animerPerso(perso *p);
void saut(perso *p);

#endif 

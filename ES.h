#ifndef ES_H_
#define ES_H_
#include <SDL/SDL.h>
#include "menu.h"
#include "perso.h"
typedef struct{
SDL_Surface *enemie;
SDL_Rect pos_enemie;

}enemie1;
typedef struct{
SDL_Surface *enemieIA[3];
SDL_Rect pos_enemieIA;
int statut;/* 0:waiting, 1: following, 2:attacking*/
int frame;
}enemieAI;

int Load_enemi(enemie1 *ES,enemieAI *esIA);
void afficher_enemie(fenetre show,enemie1 *ES,enemieAI *esIA);
void animationIA(enemieAI *esIA,perso *p);
void mvt_enemie(enemie1 *ES,perso *p,fenetre show,enemieAI *esIA);
int collision_box(enemie1 *ES, perso *p,enemieAI *esIA);
#endif


/**
* @file ES1.h
* @brief Docov
* @author 1 team
* @version 0
* testing ES for game
*/
#ifndef ES1_H_
#define ES1_H_
#include <SDL/SDL.h>
#include "menu.h"
/**
* @struct es
* @brief struct for ES
*/

typedef struct{
SDL_Surface *enemie; /*!< SURFACE*/
SDL_Rect pos_enemie; /*!< rectangle*/
SDL_Surface *backE;  /*!< SURFACE*/
SDL_Rect pos_backE; /*!< RECTANGLE*/
}enemie1;
typedef struct{
SDL_Surface *enemieIA[3]; /*!< SURFACE*/
SDL_Rect pos_enemieIA; /*!< RECTANGLE*/
int statut;/* 0:waiting, 1: following, 2:attacking*/
int frame; /*!< INTEGER*/
}enemieAI;
typedef struct{
SDL_Surface *perso;
SDL_Rect pos_perso;
int life;
}personnage;
int Load_enemi(enemie1 *ES,personnage *per,enemieAI *esIA);
void afficher_enemie(fenetre show,personnage *per,enemie1 *ES,enemieAI *esIA);
void animationIA(enemieAI *esIA,personnage *per);
void mvt_enemie(enemie1 *ES,personnage *per,fenetre show,enemieAI *esIA);
int collision_box(enemie1 *ES, personnage *per,enemieAI *esIA);
#endif

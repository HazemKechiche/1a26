#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "ES.h"
#include "menu.h"
#include "perso.h"

/*init*/
int Load_enemi(enemie1 *ES,enemieAI *esIA)
{int lvl;
lvl=1;
int i=0;

if(lvl==1)ES->enemie=IMG_Load("virus.png");
if(lvl==2)ES->enemie=IMG_Load("virus1.png");
if(lvl==3)ES->enemie=IMG_Load("virus2.png");


if ( ES->enemie==NULL )
{
printf("Unable to Load Virus: %s\n",SDL_GetError());
}
esIA->enemieIA[0]=IMG_Load("corona13.png");
esIA->enemieIA[1]=IMG_Load("corona12.png");
esIA->enemieIA[2]=IMG_Load("corona11.png");
for (i=0;i++;i<3)
if ( esIA->enemieIA==NULL )
{
printf("Unable to Load Virus: %s\n",SDL_GetError());
}
esIA->pos_enemieIA.x=1400;
esIA->pos_enemieIA.y=140;
esIA->pos_enemieIA.w=250;
esIA->pos_enemieIA.h=167;
ES->pos_enemie.x=0;
ES->pos_enemie.y=140;
ES->pos_enemie.w=256;
ES->pos_enemie.h=256;

}
/*affichage*/
void afficher_enemie(fenetre show,enemie1 *ES,enemieAI *esIA)
{
SDL_BlitSurface(ES->enemie, NULL, show.screen, &(ES->pos_enemie)) ;

SDL_BlitSurface(esIA->enemieIA[0], NULL, show.screen, &(esIA->pos_enemieIA)) ;


}

/*animationAI*/
void animationIA(enemieAI *esIA,perso* p)
{
if (esIA->pos_enemieIA.x-p->posperso.x>1000)
{
esIA->statut=0;
esIA->frame=0;
}
else if((esIA->pos_enemieIA.x-p->posperso.x<=1000)&&(esIA->pos_enemieIA.x-p->posperso.x>200))
{esIA->statut=1;
esIA->frame=1;
}
else if(esIA->pos_enemieIA.x-p->posperso.x==200)
{
esIA->statut=2;
esIA->frame=2;
}
else if(p->posperso.x-esIA->pos_enemieIA.x>100)
{
esIA->statut=0;
esIA->frame=0;
}
}
/*mouvement*/
void mvt_enemie(enemie1 *ES,perso* p,fenetre show,enemieAI *esIA)
{ 
int speed=100;



 

ES->pos_enemie.x+=(float)speed/60;

SDL_Delay(1000/60);
if((esIA->statut==1)||(esIA->statut==2))
{
esIA->pos_enemieIA.x-=(float)speed/60;
SDL_Delay(1000/60);
}
else
esIA->pos_enemieIA.x=esIA->pos_enemieIA.x;
}

/*collision*/
int collision_box(enemie1 *ES, perso *p,enemieAI *esIA)
{int i=0;
int Collision=0;
 
if(((ES->pos_enemie.x>p->posperso.x+p->posperso.w)||(ES->pos_enemie.y>p->posperso.y+p->posperso.h)||(ES->pos_enemie.x+ES->pos_enemie.w<p->posperso.x)||(ES->pos_enemie.y+ES->pos_enemie.h<p->posperso.y))&&((esIA->pos_enemieIA.x>p->posperso.x+p->posperso.w)||(esIA->pos_enemieIA.y>p->posperso.y+p->posperso.h)||(esIA->pos_enemieIA.x+esIA->pos_enemieIA.w<p->posperso.x)||(esIA->pos_enemieIA.y+esIA->pos_enemieIA.h<p->posperso.y)))

Collision=0;

else
{
Collision=1;

p->posperso.x=p->posperso.x;
SDL_Delay(1000);

ES->pos_enemie.x=p->posperso.x-300;
esIA->pos_enemieIA.x=-400;

}
return(Collision);

}
 

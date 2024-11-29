#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "ES.h"
#include "perso.h"
#include "background.h"
#include "menu.h"
#include "minimap.h"

#define GRAVITY 10


int main()
{
int i,j;
Mix_Music *musique;

int k=1;
int Collision=0;
fenetre show;
show.position_W=3000;
show.position_H=655;
show.screen=NULL;
int test=1;
text t;
t.police=NULL;
t.texte=NULL;
t.couleurNoir.r =0;
t.couleurNoir.g =0;
t.couleurNoir.b =0;
img photo;
photo.image=NULL;
Menu M;
M.menu[0]=NULL;
M.menu[1]=NULL;
M.menu[2]=NULL;
Menu1 M1;
M1.menu1[0]=NULL;
M1.menu1[1]=NULL;
M1.menu1[2]=NULL;
enemie1 ES;
ES.enemie=NULL;
Minimap m;
enemieAI esIA;
esIA.enemieIA[0]=NULL;
esIA.enemieIA[1]=NULL;
esIA.enemieIA[2]=NULL;
esIA.frame=0;
esIA.statut=0;
perso p;
int right=0,left=0,up=0;
p.life=3;
background bckg,bckg2;
bckg.img_background=NULL;
SDL_Event event;
int continuer=1;
int input;

	input=0;
	int b=0;
Load_enemi(&ES,&esIA);
init(&p);
initialiser_background(&bckg);
Init_MiniMap(&m,p);
while(continuer)
{
show=intisalisation(show);
son(musique);


k=affichage_Menu(M,M1,show,t,photo,test);
if(k==0)
{



for(i=0;i<3;i++)
{SDL_FreeSurface(M.menu[i]);
SDL_FreeSurface(M1.menu1[i]);
}
SDL_FreeSurface(t.texte);
Mix_CloseAudio();
TTF_CloseFont(t.police);
TTF_Quit;


while(p.life!=0)
{
 
    

afficher_background(bckg,show);
Update_MiniMap(&m,p);
afficher_enemie(show,&ES,&esIA);
afficherPerso(&p,show);
;
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=1;
                    input=2;
                    b=1;
                break;
                case SDLK_RIGHT:
                    right=1;
                     input=1;
                      b=1;
                break;
                case SDLK_UP:
                    up=1;
                break;    

            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                    left=0;
                    input=0;
                break;
                case SDLK_RIGHT:
                    right=0;
                 input=0;
                break;
                case SDLK_UP:
                    up=0;
                break;
            }
        break;    
        }
    } 
if (b==1)
			scrolling(&bckg,input,show);
		if (b==2)
			scrolling(&bckg2,input,show);
if (left==1) p.direction=1;
if (right==1) p.direction=0;
if (up==1) saut(&p);




deplacerPerso(&p);
if (p.direction==0) p.posperso.x--;
if (p.direction==1) p.posperso.x++;




if (left==0 && right==0)
{
    p.vh=0;
}
Display_MiniMap(&m,show);
afficherPerso(&p,show);
animerPerso(&p);


animationIA(&esIA,&p);
mvt_enemie(&ES,&p,show,&esIA);
Collision=collision_box(&ES,&p,&esIA);

SDL_Flip(show.screen);

if (Collision==1)
p.life--;
}
continuer=0;
}



                 

}
SDL_FreeSurface(ES.enemie);


for (i=0;i++;i<3)
SDL_FreeSurface(esIA.enemieIA[i]);

for (j=0;j<3;j++)
	{
		
                SDL_FreeSurface(p.persoTab[0][j]);
		SDL_FreeSurface(p.persoTab[1][j]);
	}
SDL_Quit();


return(0);
}

#include "perso.h"

void init(perso* p)
{ 
	int j,i;
	char chemin[50];
	for (j=0;j<3;j++)
		{
		sprintf(chemin,"r%d.png",j);
		p->persoTab[0][j]=IMG_Load(chemin);

	}
for (i=0;i++;i<3)
if ( p->persoTab[0][i]==NULL )
{
printf("Unable to Load perso: %s\n",SDL_GetError());
}
	for (j=0;j<3;j++)
	{
		sprintf(chemin,"l%d.png",j);
		p->persoTab[1][j]=IMG_Load(chemin);
	}
	p->posperso.x=500;
	p->posperso.y=140;
p->posperso.w=150;
p->posperso.h=225;

	p->direction=0;
	p->frame=0;
	p->vh=0;
	p->vv=0;
	

}
void afficherPerso(perso *p,fenetre show)
{
	SDL_BlitSurface(p->persoTab[p->direction][p->frame],NULL,show.screen,&p->posperso);


}



void deplacerPerso(perso *p)
{
	p->vh++;
	if (p->direction==0)
	{ SDL_Delay(1000/60);
		p->posperso.x += p->vh;
	}
	else if (p->direction==1)
	{ SDL_Delay(1000/60);
		p->posperso.x -= p->vh;
	}
	if (p->vh > 5)
	{
		p->vh = 0;
	}
	
}

void animerPerso(perso *p)
{
	p->frame++;
	if (p->frame > 2)
	{
		p->frame=0;
	}
	if (p->vh==0)
	{
		p->frame=0;
	}

	
	
}


void saut(perso *p)
{
#define GRAVITY 10
	if (p->posperso.y==140)
	{
		p->vv=-20;
	}
SDL_Delay(1000/60);
p->posperso.y += p->vv;
p->vv += GRAVITY ;
if (p->posperso.y==140)
{
    p->posperso.y=140;
    p->vv=0;
}
	
	
}



	





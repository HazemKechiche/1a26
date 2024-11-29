#include "minimap.h"
#include "perso.h"
#include "menu.h"
void Init_MiniMap(Minimap*m,perso p)
{
	m->back=IMG_Load("mini_map.png");
	m->Dot=IMG_Load("Dot.png");
	m->posBlit.x=100;
	m->posBlit.y=300;
	m->posDot.x=100;
	m->posDot.y=300;
}

void Update_MiniMap(Minimap *m,perso p)
{
	m->posDot.x=p.posperso.x/500;
	m->posDot.y=300;
}

void Display_MiniMap(Minimap*m,fenetre show)
{
        SDL_BlitSurface(m->Dot,NULL,show.screen,&(m->posDot));
	SDL_BlitSurface(m->back,NULL,show.screen,&(m->posBlit));
	
	
}

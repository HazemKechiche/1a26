/* !
* @file menu.c
* @brief Docov
* @author team1
* @version 0.1
*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

fenetre intisalisation(fenetre show)
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO );
if (SDL_Init(SDL_INIT_VIDEO ) !=0 )
{
printf("Unable to initalize SDL: %s\n",SDL_GetError());
}
show.screen= SDL_SetVideoMode(show.position_W,show.position_H,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
if (show.screen==NULL)
{
    printf("unable to Set video Mode : %s\n",SDL_GetError());
     
}
return(show);
}

int Load_files(text *t,img *photo,Menu *M,Menu1 *M1)
{
t->police=TTF_OpenFont("angelina.TTF",45);
photo->image=IMG_Load("backg.png");
M->menu[0]=IMG_Load("PLAY11.png");
M->menu[1]=IMG_Load("SETTINGS.png");
M->menu[2]=IMG_Load("EXIT11.png");
M1->menu1[0]=IMG_Load("PLAY12.png");
M1->menu1[1]=IMG_Load("SETTINGS1.png");
M1->menu1[2]=IMG_Load("EXIT12.png");
}




void draw(img *photo,Menu *M,fenetre show,text *t )
{photo->Pos_image.x=0;
photo->Pos_image.y=0;
M->postionMenu[0].x=200;
M->postionMenu[0].y=244.4;
M->postionMenu[1].x=200;
M->postionMenu[1].y=344.4;
M->postionMenu[2].x=200;
M->postionMenu[2].y=444.4;
M->postionMenu[0].h=50;
M->postionMenu[1].h=50;
M->postionMenu[1].w=100;
M->postionMenu[2].h=50;
M->postionMenu[2].w=100;
t->texte=TTF_RenderText_Blended(t->police,"Groupe 1",t->couleurNoir);
SDL_BlitSurface(photo->image,NULL,show.screen,&(photo->Pos_image));
SDL_BlitSurface(t->texte,NULL,show.screen,&(t->position_texte));
SDL_BlitSurface(M->menu[0], NULL, show.screen, &(M->postionMenu[0])) ;
SDL_BlitSurface(M->menu[1], NULL, show.screen, &(M->postionMenu[1])) ;
SDL_BlitSurface(M->menu[2], NULL, show.screen, &(M->postionMenu[2])) ;
SDL_Flip(show.screen);
}




int manipulation_menu(Menu M,Menu1 M1,fenetre show,int *test)
{
SDL_Event event;
int continuer=1;
int mute=0;
int volume=10;
int menuCourant=0;

M1.postionMenu1[0].x=200;
M1.postionMenu1[0].y=244.4;
M1.postionMenu1[1].x=200;
M1.postionMenu1[1].y=344.4;
M1.postionMenu1[2].x=200;
M1.postionMenu1[2].y=444.4;
M1.postionMenu1[0].h=50;
M1.postionMenu1[1].h=50;
M1.postionMenu1[1].w=100;
M1.postionMenu1[2].h=50;
while(continuer)
{
SDL_WaitEvent(&event);
switch(event.type) {
case SDL_QUIT:
   continuer=0;
break;
case SDL_MOUSEMOTION:
if(((event.motion.x<M.postionMenu[0].x+M.menu[0]->w)&&(event.motion.x>M.postionMenu[0].x))&&((event.motion.y<M.postionMenu[0].y+M.menu[0]->h)&&(event.motion.y>M.postionMenu[0].y)))
{


SDL_BlitSurface(M1.menu1[0],NULL,show.screen,&M1.postionMenu1[0]);
SDL_BlitSurface(M.menu[1],NULL,show.screen,&M.postionMenu[1]);
SDL_BlitSurface(M.menu[2],NULL,show.screen,&M.postionMenu[2]);

SDL_Flip(show.screen);

}
if(((event.motion.x<M.postionMenu[1].x+M.menu[1]->w)&&(event.motion.x>M.postionMenu[1].x))&&((event.motion.y<M.postionMenu[1].y+M.menu[1]->h)&&(event.motion.y>M.postionMenu[1].y)))
{


SDL_BlitSurface(M.menu[0],NULL,show.screen,&M.postionMenu[0]);
SDL_BlitSurface(M1.menu1[1],NULL,show.screen,&M1.postionMenu1[1]);
SDL_BlitSurface(M.menu[2],NULL,show.screen,&M.postionMenu[2]);


SDL_Flip(show.screen);

}
if(((event.motion.x<M.postionMenu[2].x+M.menu[2]->w)&&(event.motion.x>M.postionMenu[2].x))&&((event.motion.y<M.postionMenu[2].y+M.menu[2]->h)&&(event.motion.y>M.postionMenu[2].y)))
{


SDL_BlitSurface(M.menu[0],NULL,show.screen,&M.postionMenu[0]);
SDL_BlitSurface(M.menu[1],NULL,show.screen,&M.postionMenu[1]);
SDL_BlitSurface(M1.menu1[2],NULL,show.screen,&M1.postionMenu1[2]);
;

SDL_Flip(show.screen);

}

break;



case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
           case SDLK_ESCAPE:
                   continuer=0;
                        return(continuer);
                       break;
                    case SDLK_UP:
          
                        menuCourant--;
                        if (menuCourant < 0) {
 menuCourant = 2;
SDL_BlitSurface(M.menu[0], NULL, show.screen, &M.postionMenu[0]) ;
}
if (menuCourant == 1){
SDL_BlitSurface(M.menu[2], NULL, show.screen, &M.postionMenu[2]) ;
SDL_BlitSurface(M.menu[0], NULL, show.screen, &M.postionMenu[0]) ;
}
if (menuCourant == 0)
SDL_BlitSurface(M.menu[1], NULL,show.screen, &M.postionMenu[1]) ;

                        break ;
                    case SDLK_DOWN:
                        menuCourant++;
                  
                        if (menuCourant > 2){
menuCourant = 0;
SDL_BlitSurface(M.menu[2], NULL, show.screen,&M.postionMenu[2]) ;
}
if (menuCourant==1){
SDL_BlitSurface(M.menu[0], NULL, show.screen,&M.postionMenu[0]) ;
SDL_BlitSurface(M.menu[2], NULL, show.screen, &M.postionMenu[2]) ;
}
if (menuCourant ==2)
SDL_BlitSurface(M.menu[1], NULL, show.screen, &M.postionMenu[1]) ;
                        break ;
        
          break;
 
               
              case SDLK_TAB:
                    mute++;
           continuer=0;
           return continuer=0;
        if(mute>2)
                 mute=1;
            if(mute==1)
             Mix_PauseMusic();
             if(mute==2)
             Mix_ResumeMusic();
              break;
             case SDLK_0:
            volume--;
          Mix_VolumeMusic(volume);
              break;
            case SDLK_1:
           volume++;
          Mix_VolumeMusic(volume);
           break;
                   default: break ;
               }
            default: break ;
        }
        
SDL_BlitSurface(M1.menu1[menuCourant],NULL,show.screen,&M1.postionMenu1[menuCourant]) ;
SDL_Flip(show.screen);


}
}
int affichage_Menu(Menu M,Menu1 M1,fenetre show,text t,img photo,int test)
{ int k=0;
Load_files(&t,&photo,&M,&M1);
draw(&photo,&M,show,&t );
k=manipulation_menu(M,M1,show,&test);
return(k);
}
int son(Mix_Music *musique) 
{

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
  
   musique = Mix_LoadMUS("END.mp3"); 
   Mix_PlayMusic(musique, -1); 


}



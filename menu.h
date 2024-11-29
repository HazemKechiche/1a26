#ifndef MENU_H_
#define MENU_H_
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
typedef struct{
SDL_Surface *menu[3];
SDL_Rect  postionMenu[3];
}Menu;
typedef struct{
SDL_Surface *menu1[3];
SDL_Rect  postionMenu1[3];
}Menu1;
typedef struct{
SDL_Surface *screen;
int position_W;
int position_H;
}fenetre;
typedef struct {
SDL_Surface *texte;
TTF_Font *police;
SDL_Rect position_texte;
SDL_Color couleurNoir;
}text;
typedef struct {
SDL_Surface *image;
SDL_Rect Pos_image;
}img;



fenetre intisalisation(fenetre show);

int Load_files(text *t,img *photo,Menu *M,Menu1 *M1);
void draw(img *photo,Menu *M,fenetre show,text *t );
int manipulation_menu(Menu M,Menu1 M1,fenetre show,int *test);
int affichage_Menu(Menu M,Menu1 M1,fenetre show,text t,img photo,int test);
int son(Mix_Music *musique);




#endif

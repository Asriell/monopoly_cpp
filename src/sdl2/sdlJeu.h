#ifndef _SDLJEU_H
#define _SDLJEU_H
/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion de l'affichage sdl ainsi qu'a la gestion des images
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  sdlJeu.h
    @date 2017/04/20
*/
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
class Joueur;
//! \brief Pour gérer une image avec SDL2
class Image {
public:
    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
};



/**
    La classe gérant le jeu avec un affichage SDL
*/
class sdlJeu {

private :

    SDL_Window * window;
    SDL_Renderer * renderer;
    TTF_Font * font;

    int posj1 [2];
    int posj2 [2];
    int posj3 [2];
    int posj4 [2];
    Image im_plateau;
    Image im_pionjoueur1;
    Image im_pionjoueur2;
    Image im_pionjoueur3;
    Image im_pionjoueur4;
    Image im_argent1;
    Image im_prison1;
    Image im_pseudo1;
    Image im_argent2;
    Image im_prison2;
    Image im_pseudo2;
    Image im_argent3;
    Image im_prison3;
    Image im_pseudo3;
    Image im_argent4;
    Image im_prison4;
    Image im_pseudo4;
public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlBoucle ();
    void sdlAff ();
    void sdlInit ();
    void afficheJoueur1(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg);
    void afficheJoueur2(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg);
    void afficheJoueur3(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg);
    void afficheJoueur4(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg);
    void deplacerJoueur(int numcase, int numJ);
};

#endif

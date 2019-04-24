/**
    @brief Ce fichier contient les fonctions relatives a la gestion de l'affichage sdl ainsi qu'a la gestion des images
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  sdlJeu.cpp
    @date 2017/04/20
*/

#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

const int TAILLE_SPRITE = 12; //C'est la taille des pions
const int TAILLE_CASEX = 65;
const int TAILLE_CASEY = 58;
float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //
/**
 *   @brief Constructeur par defaut de la classe Image qui cree une image
 *   @param pas d'argument
 *   @return retourne une image
 */
Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

/**
 *   @brief charge une image depuis un fichier
 *   @param filename: const char*, renderer: SDL_Renderer *
 *   @return pas de valeur retournee
 */
void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) { //charge une image
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") +filename;
        //cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

/**
 *   @brief dessine une image a l'ecran
 *   @param renderer: SDL_Renderer *, x: int, y: int, w: int, h: int
 *   @return pas de valeur retournee
 */
void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) { //Permet d'insérer l'image sur un renderer selon les coordonnees (x,y). Les dimensions sont modifiees en changeant w et h.
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}


// ============= CLASS SDLJEU =============== //

/**
 *   @brief Constructeur par defaut de la classe sdlJeu qui initialise l'affichage
 *   @param pas d'argument
 *   @return pas de valeur retournee
 */
sdlJeu::sdlJeu (){
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }
    // Creation de la fenetre
    window = SDL_CreateWindow("THE MONOPOLY", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1200,750, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); //créé la fenêtre
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    im_plateau.loadFromFile("data/plateau_monopoly.png",renderer); //chargement de toutes les images de base sur le renderer
    im_pionjoueur1.loadFromFile("data/joueur1.png",renderer);
    im_pionjoueur2.loadFromFile("data/joueur2.png",renderer);
    im_pionjoueur3.loadFromFile("data/joueur3.png",renderer);
    im_pionjoueur4.loadFromFile("data/joueur4.png",renderer);
    posj1 [0] = 1200-290;
    posj1 [1] = 750-60;
    posj2 [0] = 1200-290;
    posj2 [1] = 750-50;
    posj3 [0] = 1200-280;
    posj3 [1] = 750-60;
    posj4 [0] = 1200-280;
    posj4 [1] = 750-50;
}

/**
 *   @brief Destructeur de la classe sdlJeu
 *   @param pas d'argument
 *   @return pas de valeur retournee
 */
sdlJeu::~sdlJeu () {
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 *   @brief affiche les donnees du joueur 1 (argent, carte libere prison)
 *   @param argent: int,prison: int,renderer: SDL_Renderer *,couleur: SDL_Color,couleurbg: SDL_Color
 *   @return pas de valeur retournee
 */
void sdlJeu::afficheJoueur1(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg)
{

   TTF_Font *policeJoueur = TTF_OpenFont("../data/police.ttf", 15);
   std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << argent;
    // récupérer une chaîne de caractères
    std::string a = oss.str();
    std::ostringstream oss2;
    // écrire un nombre dans le flux
    oss2 << prison;
    // récupérer une chaîne de caractères
    std::string p = oss2.str();
    const char* a2 = a.c_str();
    const char* p2 = p.c_str();
   im_argent1.surface = TTF_RenderText_Shaded(policeJoueur, a2, couleur,couleurbg);
   im_argent1.texture = SDL_CreateTextureFromSurface(renderer,im_argent1.surface);
   im_prison1.surface = TTF_RenderText_Shaded(policeJoueur, p2, couleur,couleurbg);
   im_prison1.texture = SDL_CreateTextureFromSurface(renderer,im_prison1.surface);
   im_pseudo1.surface = TTF_RenderText_Shaded(policeJoueur,"joueur 1",couleur,couleurbg);
   im_pseudo1.texture = SDL_CreateTextureFromSurface(renderer,im_pseudo1.surface);
   im_argent1.draw (renderer,1130,170,30,30);
   im_prison1.draw (renderer,1110,140,20,20);
   im_pseudo1.draw(renderer,1075,40,60,20);
}

/**
 *   @brief affiche les donnees du joueur 2 (argent, carte libere prison)
 *   @param argent: int,prison: int,renderer: SDL_Renderer *,couleur: SDL_Color,couleurbg: SDL_Color
 *   @return pas de valeur retournee
 */
void sdlJeu::afficheJoueur2(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg)
{

   TTF_Font *policeJoueur = TTF_OpenFont("../data/police.ttf", 15);
   std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << argent;
    // récupérer une chaîne de caractères
    std::string a = oss.str();
    std::ostringstream oss2;
    // écrire un nombre dans le flux
    oss2 << prison;
    // récupérer une chaîne de caractères
    std::string p = oss2.str();
    const char* a2 = a.c_str();
    const char* p2 = p.c_str();
   im_argent2.surface = TTF_RenderText_Shaded(policeJoueur, a2, couleur,couleurbg);
   im_argent2.texture = SDL_CreateTextureFromSurface(renderer,im_argent2.surface);
   im_prison2.surface = TTF_RenderText_Shaded(policeJoueur, p2, couleur,couleurbg);
   im_prison2.texture = SDL_CreateTextureFromSurface(renderer,im_prison2.surface);
   im_pseudo2.surface = TTF_RenderText_Shaded(policeJoueur,"joueur 2",couleur,couleurbg);
   im_pseudo2.texture = SDL_CreateTextureFromSurface(renderer,im_pseudo2.surface);
   im_argent2.draw (renderer,1130,368,30,30);
   im_prison2.draw (renderer,1110,332,20,20);
   im_pseudo2.draw(renderer,1075,210,60,20);
}

/**
 *   @brief affiche les donnees du joueur 3 (argent, carte libere prison)
 *   @param argent: int,prison: int,renderer: SDL_Renderer *,couleur: SDL_Color,couleurbg: SDL_Color
 *   @return pas de valeur retournee
 */

void sdlJeu::afficheJoueur3(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg)
{

   TTF_Font *policeJoueur = TTF_OpenFont("../data/police.ttf", 15);
   std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << argent;
    // récupérer une chaîne de caractères
    std::string a = oss.str();
    std::ostringstream oss2;
    // écrire un nombre dans le flux
    oss2 << prison;
    // récupérer une chaîne de caractères
    std::string p = oss2.str();
    const char* a2 = a.c_str();
    const char* p2 = p.c_str();
   im_argent3.surface = TTF_RenderText_Shaded(policeJoueur, a2, couleur,couleurbg);
   im_argent3.texture = SDL_CreateTextureFromSurface(renderer,im_argent3.surface);
   im_prison3.surface = TTF_RenderText_Shaded(policeJoueur, p2, couleur,couleurbg);
   im_prison3.texture = SDL_CreateTextureFromSurface(renderer,im_prison3.surface);
   im_pseudo3.surface = TTF_RenderText_Shaded(policeJoueur,"joueur 3",couleur,couleurbg);
   im_pseudo3.texture = SDL_CreateTextureFromSurface(renderer,im_pseudo3.surface);
   im_argent3.draw (renderer,1130,568,30,30);
   im_prison3.draw (renderer,1110,528,20,20);
   im_pseudo3.draw(renderer,1075,410,60,20);
}

/**
 *   @brief affiche les donnees du joueur 4 (argent, carte libere prison)
 *   @param argent: int,prison: int,renderer: SDL_Renderer *,couleur: SDL_Color,couleurbg: SDL_Color
 *   @return pas de valeur retournee
 */

void sdlJeu::afficheJoueur4(int argent,int prison,SDL_Renderer *renderer, SDL_Color couleur,SDL_Color couleurbg)
{

   TTF_Font *policeJoueur = TTF_OpenFont("../data/police.ttf", 15);
   std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << argent;
    // récupérer une chaîne de caractères
    std::string a = oss.str();
    std::ostringstream oss2;
    // écrire un nombre dans le flux
    oss2 << prison;
    // récupérer une chaîne de caractères
    std::string p = oss2.str();
    const char* a2 = a.c_str();
    const char* p2 = p.c_str();
   im_argent4.surface = TTF_RenderText_Shaded(policeJoueur, a2, couleur,couleurbg);
   im_argent4.texture = SDL_CreateTextureFromSurface(renderer,im_argent4.surface);
   im_prison4.surface = TTF_RenderText_Shaded(policeJoueur, p2, couleur,couleurbg);
   im_prison4.texture = SDL_CreateTextureFromSurface(renderer,im_prison4.surface);
   im_pseudo4.surface = TTF_RenderText_Shaded(policeJoueur,"joueur 4",couleur,couleurbg);
   im_pseudo4.texture = SDL_CreateTextureFromSurface(renderer,im_pseudo4.surface);
   im_argent4.draw (renderer,1130,720,30,30);
   im_prison4.draw (renderer,1110,690,20,20);
   im_pseudo4.draw(renderer,1075,610,60,20);
}



/**
 *   @brief affichage de tous les elements de base a l'ecran
 *   @param pas d'argument
 *   @return pas de valeur retournee
 */
void sdlJeu::sdlAff () { //affichage des sprites sur le renderer
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurbg = {186, 212, 251};
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    im_plateau.draw(renderer,0,0,1200,750); //affecte les differents elements au renderer a un certain emplacement
    afficheJoueur1(10000,0,renderer,couleurNoire,couleurbg);
    afficheJoueur2(1000,5,renderer,couleurNoire,couleurbg);
    afficheJoueur3(50,3,renderer,couleurNoire,couleurbg);
    afficheJoueur4(10,9,renderer,couleurNoire,couleurbg);
    im_pionjoueur1.draw (renderer,posj1[0],posj1[1],TAILLE_SPRITE,TAILLE_SPRITE);
    im_pionjoueur2.draw (renderer,posj2[0],posj2[1],TAILLE_SPRITE,TAILLE_SPRITE);
    im_pionjoueur3.draw (renderer,posj3[0],posj3[1],TAILLE_SPRITE,TAILLE_SPRITE);
    im_pionjoueur4.draw (renderer,posj4[0],posj4[1],TAILLE_SPRITE,TAILLE_SPRITE);
    SDL_RenderPresent(renderer);
   // SDL_RenderPresent(renderer); //je sais pas a quoi ça sert mais faut le mettre en dernier, sinon, ça marche pas
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle


}

/**
 *   @brief modifie la position d'un joueur
 *   @param nbcases: int,numJ: int
 *   @return pas de valeur retournee
 */
void sdlJeu::deplacerJoueur(int nbcases,int numJ)
{
switch (numJ)
{
case 1:
while (nbcases != 0)
{
    if (posj1[0]> 260&&posj1[1] == 750-60 && posj1[0]!=60 && nbcases != 0)
    {
        posj1[0] -=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj1[0]== 260)
        {
        posj1[0] = 250;
        posj1[1] = 660;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj1[0]== 250 && posj1[1] > 60 && nbcases != 0)
    {
        posj1[1] -=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj1[1]== 80)
        {
        posj1[0] = 280;
        posj1[1] = 60;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj1[0] >=  280 && posj1[0]< 930 && posj1[1] == 60 && nbcases != 0)
    {
        posj1[0] +=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj1[0]== 930)
        {
        posj1[0] = 970;
        posj1[1] = 80;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }

    if (posj1[0]== 970 && posj1[1] >= 80 && nbcases != 0)
    {
        posj1[1] +=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj1[1]== 660)
        {
        posj1[0] = 1200-290;
        posj1[1] = 750-60;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
}

break;

case 2:
while (nbcases != 0)
{
    if (posj2[0]> 260&&posj2[1] == 750-50 && posj2[0]!=60 && nbcases != 0)
    {
        posj2[0] -=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj2[0]== 260)
        {
        posj2[0] = 250;
        posj2[1] = 650;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj2[0]== 250 && posj2[1] > 50 && nbcases != 0)
    {
        posj2[1] -=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj2[1]== 70)
        {
        posj2[0] = 280;
        posj2[1] = 50;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj2[0] >=  280 && posj2[0]< 930 && posj2[1] == 50 && nbcases != 0)
    {
        posj2[0] +=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj2[0]== 930)
        {
        posj2[0] = 970;
        posj2[1] = 70;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }

    if (posj2[0]== 970 && posj2[1] >= 70 && nbcases != 0)
    {
        posj2[1] +=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj2[1]== 650)
        {
        posj2[0] = 1200-290;
        posj2[1] = 750-50;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
}
break;

case 3:
while (nbcases != 0)
{
    if (posj3[0]> 270&&posj3[1] == 750-60 && posj3[0]!=60 && nbcases != 0)
    {
        posj3[0] -=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj3[0]== 270)
        {
        posj3[0] = 240;
        posj3[1] = 660;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj3[0]== 240 && posj3[1] > 60 && nbcases != 0)
    {
        posj3[1] -=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj3[1]== 80)
        {
        posj3[0] = 270;
        posj3[1] = 60;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj3[0] >=  270 && posj3[0]< 930 && posj3[1] == 60 && nbcases != 0)
    {
        posj3[0] +=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj3[0]== 920)
        {
        posj3[0] = 960;
        posj3[1] = 80;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }

    if (posj3[0]== 960 && posj3[1] >= 80 && nbcases != 0)
    {
        posj3[1] +=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj3[1]== 660)
        {
        posj3[0] = 1200-280;
        posj3[1] = 750-60;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
}
break;

case 4:
while (nbcases != 0)
{
    if (posj4[0]> 270&&posj4[1] == 750-50 && posj4[0]!=60 && nbcases != 0)
    {
        posj4[0] -=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj4[0]== 270)
        {
        posj4[0] = 240;
        posj4[1] = 650;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj4[0]== 240 && posj4[1] > 50 && nbcases != 0)
    {
        posj4[1] -=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj4[1]== 70)
        {
        posj4[0] = 270;
        posj4[1] = 50;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
    if (posj4[0] >=  270 && posj4[0]< 930 && posj4[1] == 50 && nbcases != 0)
    {
        posj4[0] +=TAILLE_CASEX;
        sdlAff();
        SDL_Delay(500);
        if (posj4[0]== 920)
        {
        posj4[0] = 960;
        posj4[1] = 70;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }

    if (posj4[0]== 960 && posj4[1] >= 70 && nbcases != 0)
    {
        posj4[1] +=TAILLE_CASEY;
        sdlAff();
        SDL_Delay(500);
        if (posj4[1]== 650)
        {
        posj4[0] = 1200-280;
        posj4[1] = 750-50;
        sdlAff();
        SDL_Delay(500);
        }
        nbcases -=1;
    }
}
break;

}


}

/**
 *   @brief boucle d'evenement
 *   @param pas d'argument
 *   @return pas de valeur retournee
 */

void sdlJeu::sdlBoucle () { //la boucle de jeu
    int De1;
    int De2;
    int Tour;
    Tour = 1;
    SDL_Event events;
	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&events))
            {
            sdlAff();
			if (events.type == SDL_QUIT){quit = true;}
            if (events.type == SDL_KEYDOWN)
                {
                switch(events.key.keysym.scancode)
                {
                    case SDL_SCANCODE_D:
                    De1 = rand()%6+1;;
                    De2 = rand()%6+1;
                    cout<<De1<<"    "<<De2<<endl;
                    deplacerJoueur(De1+De2,Tour);
                    Tour +=1;
                    if (Tour == 5)
                    {
                        Tour = 1;
                    }
                    break;

                    default:
                    break;
                }
                }
            }
			}

}


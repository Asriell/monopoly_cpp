
/**
    @brief Ce fichier contient le programme principal de THE monopoly en SDL2
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  main_sdl.cpp
    @date 2017/04/20
*/

#include "sdlJeu.h"
/**
 *   @brief programme principal pour lancer les fonctions d'affichage
 *   @param argc: int,argc: char**
 *   @return retourne un entier
 */
int main (int argc, char** argv) {
	sdlJeu sj;
	sj.sdlBoucle();
	return 0;
}

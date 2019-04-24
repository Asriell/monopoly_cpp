/**
    @brief Ce fichier est le main, le programme principal de THE Monopoly.
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file main.cpp
    @date 2017/04/20
    @mainpage THE Monopoly

    @section intro_sec Introduction
    Le projet THE Monopoly concu dans le cadre de l'UE LIFAP4. <BR>
    Code ecrit en C/C++.

    @section  compile_sec Pour compiler, ouvrir un terminal
    a la racine et ecrire "make".

    @section exec_sec Pour executer, apres la compilation,
    ouvrir un terminal dans le dossier "bin" et ecrire :
    "./monopoly_txt" pour le mode texte <BR>
    "./monopoly_sdl" pour la version graphique.

    Generer la documentation du code.
    Taper "doxygen -g doc/image.doxy" puis "doxygen doc/image.doxy" dans un terminal ouvert a la
    racine. <BR>
    Ensuite ecrire "firefox html/index.html" dans le dossier "doc" ou alors "firefox doc/html/index.html" à la racine.
*/


#include <iostream>
#include <string>
#include "Joueur.h"
#include "Couleur.h"
#include "Case.h"
#include "Plateau.h"
#include "Propriete.h"
#include "Carte.h"
#include "Jeu.h"
#include "PaquetChance.h"
#include "PaquetCaisseComm.h"
#include "TableauDynamique.h"

using namespace std;

int main (void)
{
    Jeu j;
    j.initialiserJeu();

    return 0;
}

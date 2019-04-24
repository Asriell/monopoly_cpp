#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion du plateau
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Plateau.h
    @date 2017/04/20
*/

#include "Couleur.h"
class Case;
/**
    @class Plateau Plateau.h Plateau.h la classe qui permet de generer une case
*/
class Plateau {
public :
    Case * TabCases;
/**
*   @brief Constructeur par defaut de Plateau
*   @param pas d'argument
*   @return renvoie un Plateau
*/
    Plateau();
/**
*   @brief Destructeur de Plateau
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    ~Plateau();
/**
*   @brief Cherche la i-eme case du tableau de cases
*   @param x: entier
*   @return renvoie une Case
*/
    Case getTabCases(int x)const;
    //void setProprietaire(int x,Joueur j)
};

#endif // PLATEAU_H_INCLUDED

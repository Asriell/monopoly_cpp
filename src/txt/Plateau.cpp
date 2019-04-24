/**
    @brief Ce fichier contient les fonctions relatives a la gestion du plateau
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Plateau.cpp
    @date 2017/04/20
*/

#include "Plateau.h"
#include "Case.h"
#include <string>

using namespace std;
/**  @def Plateau::Plateau()
*   @brief Constructeur par defaut de Plateau
*   @param pas d'argument
*   @return renvoie un Plateau
*/
Plateau::Plateau(){
    TabCases = new Case [40];
    TabCases[0].setNumeroCase(0);
    TabCases[0].setParcGratuit(false);
    TabCases[0].setAllerEnPrison(false);
    TabCases[0].setVisitePrison(false);
    TabCases[0].setpropriete(NULL);
    TabCases[0].setCaseDepart(true);
    TabCases[0].setChance(false);
    TabCases[0].setCaisseCommunaute(false);

    Couleur marron (136,66,29,"marron");
    int * Taxesp1;
    Taxesp1 = new int [6];
    for (int i =0;i<4;i++)
    {
        Taxesp1[i] = 2 ;
    }

}

/**
*   @brief Destructeur de Plateau
*   @param pas d'argument
*   @return pas de valeur retournee
*/
Plateau::~Plateau(){
    for (int i=0;i<40;i++)
    {
        TabCases[i].setpropriete(NULL);
        TabCases[i].setParcGratuit(NULL);
        TabCases[i].setAllerEnPrison(NULL);
        TabCases[i].setVisitePrison(NULL);
        TabCases[i].setChance(NULL);
        TabCases[i].setCaisseCommunaute(NULL);
        TabCases[i].setCaseDepart(NULL);
       delete TabCases[i].getPropriete();
    }
}
/**
*   @brief Cherche la i-eme case du tableau de cases
*   @param x: entier
*   @return renvoie une Case
*/
Case Plateau::getTabCases(int x)const{
    return TabCases[x];
}
/*
void Plateau::setProprietaire(int x,Joueur j){

}

*/



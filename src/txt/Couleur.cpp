/**
    @brief Ce fichier contient les fonctions relatives a la gestion des couleurs
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Couleur.cpp
    @date 2017/04/20
*/

#include "Couleur.h"
#include <assert.h>
#include <iostream>
using namespace std;
 /**  @def Couleur::Couleur()
 *   @brief Constructeur par defaut de la classe Couleur qui cree une couleur
 *   @param pas d'argument
 *   @return retourne une couleur
 */
 Couleur::Couleur(){
    r=0;
    v=0;
    b=0;
    NomCouleur = "noir";
}
/**
*   @brief Constructeur par parametre de la classe Couleur qui cree une couleur
*   @param rouge: chaine de caractere(unsigned char), vert: chaine de caractere(unsigned char), bleu: chaine de caractere(unsigned char), nom: chaine de caractere
*   @return retourne une couleur
*/
Couleur::Couleur(unsigned char rouge, unsigned char vert, unsigned char bleu, string nom){
    r=rouge;
    b=bleu;
    v=vert;
    NomCouleur = nom;
}


/**
*   @brief Surcharge de l'operateur "=="
*   @param CouleurDroite: Couleur
*   @return retourne un booleen
*/
bool Couleur::operator ==(Couleur CouleurDroite){
    if((v == CouleurDroite.v)&&(r == CouleurDroite.r)&&(b == CouleurDroite.b)){return true;}
    return false;
}
/**
*   @brief Surcharge de l'operateur "="
*   @param CouleurDroite: Couleur
*   @return retourne une couleur
*/
Couleur& Couleur::operator =(Couleur CouleurDroite){
    r = CouleurDroite.r;
    v = CouleurDroite.v;
    b = CouleurDroite.b;
    NomCouleur = CouleurDroite.NomCouleur;
    return *this;
}
/**
*   @brief obtenir le taux de rouge d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
unsigned char Couleur::getRouge(){
    return r;
}
/**
*   @brief obtenir le taux de vert d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
unsigned char Couleur::getVert(){
    return v;
}

/**
*   @brief obtenir le taux de bleu d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
unsigned char Couleur::getBleu(){
    return b;
}
/**
*   @brief obtenir le nom d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
string Couleur::getNomCouleur(){
    return NomCouleur;
}

/**
*   @brief modifie le taux de rouge d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
void Couleur::setRouge(unsigned char rouge){
    r=rouge;
}


/**
*   @brief modifie le taux de vert d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
void Couleur::setVert(unsigned char vert){
    v=vert;
}
/**
*   @brief modifie le taux de bleu d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
void Couleur::setBleu(unsigned char bleu){
    b=bleu;
}
/**
*   @brief modifie le nom d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
void Couleur::setNomCouleur(string nom){
    NomCouleur = nom;
}

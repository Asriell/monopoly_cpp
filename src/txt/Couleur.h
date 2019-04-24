#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des couleurs
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Couleur.h
    @date 2017/04/20
*/

#include <string>
using namespace std;
/**
    @class Couleur Couleur.h Couleur.h la classe qui permet de generer une case
*/
class Couleur
{
private :
    unsigned char r;
    unsigned char v;
    unsigned char b;
    string NomCouleur;
public :
/**
*   @brief Constructeur par defaut de la classe Couleur qui cree une couleur
*   @param pas d'argument
*   @return retourne une couleur
*/
    Couleur();
/**
*   @brief Constructeur par parametre de la classe Couleur qui cree une couleur
*   @param rouge: chaine de caractere(unsigned char), vert: chaine de caractere(unsigned char), bleu: chaine de caractere(unsigned char), nom: chaine de caractere
*   @return retourne une couleur
*/
    Couleur(unsigned char r, unsigned char v, unsigned char b, string nom);
/**
*   @brief Surcharge de l'operateur "=="
*   @param CouleurDroite: Couleur
*   @return retourne un booleen
*/
    bool operator ==(Couleur CouleurDroite);
/**
*   @brief Surcharge de l'operateur "="
*   @param CouleurDroite: Couleur
*   @return retourne une couleur
*/
    Couleur& operator = (Couleur CouleurDroite);
/**
*   @brief obtenir le taux de rouge d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
    unsigned char getRouge ();
/**
*   @brief obtenir le taux de vert d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
    unsigned char getVert ();
/**
*   @brief obtenir le taux de bleu d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere (unsigned char)
*/
    unsigned char getBleu ();
/**
*   @brief obtenir le nom d'une couleur
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
    string getNomCouleur();
/**
*   @brief modifie le taux de rouge d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
    void setRouge(unsigned char rouge);
/**
*   @brief modifie le taux de vert d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
    void setVert(unsigned char vert);
/**
*   @brief modifie le taux de bleu d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
    void setBleu(unsigned char bleu);
/**
*   @brief modifie le nom d'une couleur
*   @param bleu: chaine de caractere (unsigned char)
*   @return pas de valeur retournee
*/
    void setNomCouleur(string nom);


};

#endif // COULEUR_H_INCLUDED

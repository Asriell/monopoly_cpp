#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des cartes
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Carte.h
    @date 2017/04/20
*/

#include <string>
#include "Joueur.h"
using namespace std;
class Jeu;
/**
    @class Carte Carte.h Carte.h la classe qui permet de generer une carte
*/
class Carte
{
private:
    int idCarte; // le numero propre a la carte pour l'identifier
    string description;//ce que la carte nous demande de faire
    bool Chance;//si c'est une carte chance ou caisse communauté
    int CategorieEffet;//le type d'effet soit (1  x4 prison) + (2   x6 impot des maisons) + (3   x8 se teleporter a tel endroit
    //en activant l'effet) + (4   x6 gagner argent) + (5   x6 perdre argent) + (6    x2 tous les joueurs vous donnent de l'argent)

public:
/**
*   @brief Constructeur par parametre de la classe Carte qui cree une carte
*   @param id: entier, desc: string, ch: bool, CatEffet: int
*   @return retourne une carte
*/
    Carte(int id, string desc, bool ch, int CatEffet);
/**
*   @brief Constructeur par copie de la classe Carte qui cree une carte
*   @param c: Carte
*   @return retourne une carte
*/
    Carte (const Carte & c);
/**
*   @brief Destructeur de la classe Carte qui detruit une carte
*   @param pas d'argument
*   @return pas de valeur retounee
*/
    ~Carte();
/**
*   @brief obtenir l'id d'une carte
*   @param pas d'argument
*   @return retourne un entier
*/
    int getIdCarte()const;
/**
*   @brief obtenir la description d'une carte
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
    string getDescription()const;
/**
*   @brief permet de savoir si c'est une carte chance (true) ou caisse communaute (false)
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getChance()const;
/**
*   @brief obtenir la categorie de l'effet d'une carte
*   @param pas d'argument
*   @return retourne un entier
*/
    int getCategorieEffet()const;
/**
*   @brief modifier l'id d'une carte
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setIdCarte(int x);
/**
*   @brief modifier la description d'une carte
*   @param x: chaine de caracteres
*   @return pas de valeur retournee
*/
    void setDescription(string x);
/**
*   @brief modifier le booleen chance d'une carte (si elle est de type chance ou caisse communaute)
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setChance(bool x);
/**
*   @brief modifier la categorie de l'effet d'une carte
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setCategorieEffet(int x);
/**
*   @brief Applique l'effet d'une carte au(x) joueur(s)
*   @param *numJ: Joueur, *jeu: Jeu
*   @return pas de valeur retournee
*/
    void EffetCarte(Joueur * numJ, Jeu * jeu);//CategorieEffet

};



#endif // CARTE_H_INCLUDED

/**
    @brief Ce fichier contient les fonctions relatives a la gestion des cartes
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Carte.cpp
    @date 2017/04/20
*/

#include <string>
#include <iostream>
#include "Carte.h"
#include "Jeu.h"
#include "PaquetCaisseComm.h"
#include "PaquetChance.h"
using namespace std;

 /**
 *   @brief Constructeur par parametre de la classe Carte qui cree une carte
 *   @param id: entier, desc: string, ch: bool, CatEffet: int
 *   @return retourne une carte
 */
Carte::Carte(int id, string desc, bool ch, int CatEffet)
{
    idCarte = id;
    description = desc;
    Chance = ch;
    CategorieEffet = CatEffet;

}
/**
 *   @brief Constructeur par copie de la classe Carte qui cree une carte
 *   @param c: Carte
 *   @return retourne une carte
 */
Carte::Carte(const Carte & c){
    idCarte = c.idCarte;
    description = c.description;
    Chance = c.Chance;
    CategorieEffet = c.CategorieEffet;

}
/**
*   @brief Destructeur de la classe Carte qui detruit une carte
*   @param pas d'argument
*   @return pas de valeur retounee
*/
Carte::~Carte(){
    cout<<"la carte est detruite"<<endl;
}


/**
*   @brief obtenir l'id d'une carte
*   @param pas d'argument
*   @return retourne un entier
*/
int Carte::getIdCarte()const{
    return idCarte;
}
/**
*   @brief obtenir la description d'une carte
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
string Carte::getDescription()const{
    return description;
}
/**
*   @brief permet de savoir si c'est une carte chance (true) ou caisse communaute (false)
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Carte::getChance()const{
    return Chance;
}
/**
*   @brief obtenir la categorie de l'effet d'une carte
*   @param pas d'argument
*   @return retourne un entier
*/
int Carte::getCategorieEffet()const{
    return CategorieEffet;
}


/**
*   @brief modifier l'id d'une carte
*   @param x: entier
*   @return pas de valeur retournee
*/
void Carte::setIdCarte(int x){
    idCarte = x;
}
/**
*   @brief modifier la description d'une carte
*   @param x: chaine de caracteres
*   @return pas de valeur retournee
*/
void Carte::setDescription(string x){
    description = x;
}
/**
*   @brief modifier le booleen chance d'une carte (si elle est de type chance ou caisse communaute)
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Carte::setChance(bool x){
    Chance = x;
}
/**
*   @brief modifier la categorie de l'effet d'une carte
*   @param x: entier
*   @return pas de valeur retournee
*/
void Carte::setCategorieEffet(int x){
    CategorieEffet = x;
}

/**
*   @brief Applique l'effet d'une carte au(x) joueur(s)
*   @param *numJ: Joueur, *jeu: Jeu
*   @return pas de valeur retournee
*/
void Carte::EffetCarte(Joueur * numJ,Jeu * jeu){ // tab[0]  -> position
                              // tab[1]  -> argent
                              // tab[2]  -> maisons sur terrain
                              // tab[3]  -> hotel sur terrain
    int s = numJ->getPositionJoueur() + rand()% 6+1;
    switch (CategorieEffet){
    case 1: //(4x cartes sortie de prison)
        numJ->setNbCarteLibrePrison(numJ->getNbCarteLibrePrison() + 1);
        break;

    case 2: //1 joueur doit payer aux 3 autres(6x impot des maisons)
        numJ->DiminuerArgent(100*jeu->getNbJoueurs());
        for(int i=0;i<jeu->getNbJoueurs();i++) {
                if (numJ->getNumeroJoueur() != i)
                {
                        jeu->GetJoueur(i).AugmenterArgent(100);
                }
        }

        break;

    case 3: //tp + impot (en general) (8x se teleporter a tel endroit en activant l'effet)
        numJ->AvancerCase(s);
        break;

    case 4: //gagner argent (6x gagner argent)
        numJ->AugmenterArgent((rand()% 6+1)*100);
        break;

    case 5: //perdre argent (6x perdre argent)
        numJ->DiminuerArgent((rand()% 15+1)*100);
        break;

    case 6: //3 joueurs payent a 1 joueur (2x tous les joueurs vous donnent de l'argent)
        for(int i=0;i<jeu->getNbJoueurs();i++) {
                if (numJ->getNumeroJoueur() != i)
                    {
                        jeu->GetJoueur(i).DiminuerArgent(100);
                    }
        }
        numJ->AugmenterArgent(100*jeu->getNbJoueurs());
        break;
    }
}








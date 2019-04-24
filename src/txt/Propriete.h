#ifndef PROPRIETE_H_INCLUDED
#define PROPRIETE_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des proprietes (cases) du plateau
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Propriete.h
    @date 2017/04/20
*/

#include <string>
#include "Couleur.h"

using namespace std;
class Joueur;
/**
    @class Propriete Propriete.h Propriete.h la classe qui permet de generer une case
*/
class Propriete { //Propriete = terrain
private:
    string Nom; //nom de la propriete
    int PrixTerrainNu; //prix de départ
    int PrixMaison; //prix de chaque maison
    int ValHypotheque;//Ce que le terrain rapporte en cas d'hypotheque
    int TaxesPropriete[6];//le prix en fct maison achetée
    int Proprietaire;//Celui qui a acheté ce terrain
    int NbMaisons; //Nombre de maisons sur ce terrain
    Couleur couleur;//Couleur du terrain
    bool Hypotheque;//Si la maison est en hypotheque ou non
    int NbFamille;//Nombre de terrains de la même couleur(celle-ci incluse)

public:
/**
*   @brief Constructeur par defaut de Propriete
*   @param pas d'argument
*   @return renvoie une Propriete
*/
    Propriete();
/**
*   @brief Constructeur par parametre de Plateau
*   @param Nom: chaine de caractere, PrixTerrainNu: entier, PrixMaison: entier, ValHypotheque: entier, *TaxesPropriete: entier, Proprietaire: entier,
            NbMaisons: entier, couleur: Couleur, Hypotheque: booleen, NbFamille: entier
*   @return renvoie une Propriete
*/
    Propriete(string Nom,int PrixTerrainNu,int PrixMaison,int ValHypotheque,
             int *TaxesPropriete,int Proprietaire,int NbMaisons,Couleur couleur,
             bool Hypotheque,int NbFamille);
/**
*   @brief Surcharge de l'operateur "="  entre deux Propriete
*   @param *proprieteDroite: Propriete
*   @return renvoie une Propriete
*/
    Propriete* operator= (Propriete * proprieteDroite);
/**
*   @brief Surcharge de l'operateur "==" entre deux Propriete
*   @param proprieteDroite: Propriete
*   @return renvoie un booleen
*/
    bool operator== (Propriete proprieteDroite);
/**
*   @brief obtenir le nom d'une propriete
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
    string getNom()const; //les getters
/**
*   @brief obtenir le prix d'un terrain nu (sans maison)
*   @param pas d'argument
*   @return retourne un entier
*/
    int getPrixTerrainNu()const;
/**
*   @brief obtenir le prix d'une maison
*   @param pas d'argument
*   @return retourne un entier
*/
    int getPrixMaison()const;
/**
*   @brief obtenir la valeur de l'hypotheque d'une maison
*   @param pas d'argument
*   @return retourne un entier
*/
    int getValHypotheque()const;
/**
*   @brief obtenir le rang de la taxe d'une Propriete
*   @param i: entier
*   @return retourne un entier
*/
    int getTaxesPropriete(int i)const;
/**
*   @brief Trouver le proprietaire d'une Propriete
*   @param pas d'argument
*   @return retourne un entier
*/
    int getProprietaire()const;
/**
*   @brief obtenir le nombre de maison sur une propriete
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNbMaisons()const;
/**
*   @brief obtenir la couleur d'une propriete
*   @param pas d'argument
*   @return retourne une Couleur
*/
    Couleur getCouleur()const;
/**
*   @brief obtenir le montant de l'hypotheque d'une Propriete
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getHypotheque()const;

/**
*   @brief modifier le nom d'une Propriete
*   @param nomprop: chaine de caractere
*   @return pas de valeur retournee
*/
    void setNom(string nomprop);
/**
*   @brief modifier le prix d'un terrain nu
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setPrixTerrainNu(int x);
/**
*   @brief modifier le prix d'une maison
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setPrixMaison(int x);
/**
*   @brief modifier le prix de la valeur d'une hypotheque
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setValHypotheque(int x);
/**
*   @brief modifier le tableau qui classe le rang des taxes de la propriete
*   @param *tab: tableau d'entiers
*   @return pas de valeur retournee
*/
    void setTaxesPropriete(int *tab);
/**
*   @brief modifier le proprietaire d'une Propriete
*   @param j: entier
*   @return pas de valeur retournee
*/
    void setProprietaire(int j);
/**
*   @brief modifier le nombre de maisons d'une Propriete
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setNbMaisons(int x);
/**
*   @brief modifier la couleur d'une Propriete
*   @param c: Couleur
*   @return pas de valeur retournee
*/
    void setCouleur(Couleur c);
/**
*   @brief modifier la valeur de l'hypotheque d'une Propriete
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setHypotheque(bool x);
/**
*   @brief modifier le prix d'une maison
*   @param x:entier
*   @return pas de valeur retournee
*/
/**
*   @brief Ajoute une maison a la Propriete
*   @param *j: Joueur
*   @return pas de valeur retournee
*/
    void AjouterMaison(Joueur *j);
/**
*   @brief Vend les maisons et place la Propriete en hypotheque
*   @param *j: Joueur
*   @return pas de valeur retournee
*/
    void Hypothequer(Joueur * j);//vendre les maisons + gagner argent
/**
*   @brief modifier le proprietaire d'une Propriete
*   @param NouveauP: entier
*   @return pas de valeur retournee
*/
    void ChangeProprietaire(int NouveauP);//changement de proprietaire
/**
*   @brief Fait payer un joueur non proprietaire lorsqu'il passe sur cette Propriete
*   @param Client: Joueur
*   @return pas de valeur retournee
*/
    void PayerLoyer(Joueur Client);//qd un joueur nn proprietaire s'arrete dessus
/**
*   @brief Vend un certain nombre de maisons d'une Propriete
*   @param NbMaison: entier, *j: Joueur
*   @return pas de valeur retournee
*/
    void VendreMaison(int NbMaison, Joueur * j); //le nb de maison qu'on veut vendre
};


#endif // PROPRIETE_H_INCLUDED

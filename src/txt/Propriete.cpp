/**
    @brief Ce fichier contient les fonctions relatives a la gestion des proprietes (cases) du plateau
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Propriete.cpp
    @date 2017/04/20
*/

#include "Propriete.h"
#include "Joueur.h"
#include "Couleur.h"
#include <string>
#include <iostream>
using namespace std;
/**  @def Propriete::Propriete()
*   @brief Constructeur par defaut de Propriete
*   @param pas d'argument
*   @return renvoie une Propriete
*/
Propriete::Propriete(){
    Couleur random (55,220,20,"random");
    Nom = "";
    PrixTerrainNu = 0;
    PrixMaison = 0;
    ValHypotheque = 0;
    for(int i =0;i<6;i++) {TaxesPropriete[i] = 0;}
    Proprietaire = 0;
    NbMaisons = 0;
    couleur = random;
    Hypotheque = 0;
    NbFamille = 0;
}
/**
*   @brief Constructeur par parametre de Plateau
*   @param Nom: chaine de caractere, PrixTerrainNu: entier, PrixMaison: entier, ValHypotheque: entier, *TaxesPropriete: entier, Proprietaire: entier,
            NbMaisons: entier, couleur: Couleur, Hypotheque: booleen, NbFamille: entier
*   @return renvoie une Propriete
*/
Propriete::Propriete(string Nom2,int PrixTerrainNu2,int PrixMaison2,int ValHypotheque2,int *TaxesPropriete2,int Proprietaire2,int NbMaisons2,Couleur couleur2,bool Hypotheque2,int NbFamille2){
    Nom = Nom2;
    PrixTerrainNu = PrixTerrainNu2;
    PrixMaison = PrixMaison2;
    ValHypotheque = ValHypotheque2;
    for(int i =0;i<6;i++) {TaxesPropriete[i] = TaxesPropriete2[i];}
    Proprietaire = Proprietaire2;
    NbMaisons = NbMaisons2;
    couleur = couleur2;
    Hypotheque = Hypotheque2;
    NbFamille = NbFamille2;
}

/**
*   @brief Surcharge de l'operateur "="  entre deux Propriete
*   @param *proprieteDroite: Propriete
*   @return renvoie une Propriete
*/
Propriete* Propriete::operator= (Propriete * proprieteDroite){
    Nom = proprieteDroite->Nom;
    PrixTerrainNu = proprieteDroite->PrixTerrainNu;
    PrixMaison = proprieteDroite->PrixMaison;
    ValHypotheque = proprieteDroite->ValHypotheque;
    for (int i=0;i<6;i++){TaxesPropriete[i] = proprieteDroite->TaxesPropriete[i];}
    Proprietaire = proprieteDroite->Proprietaire;
    NbMaisons = proprieteDroite->NbMaisons;
    couleur = proprieteDroite->couleur;
    Hypotheque = proprieteDroite->Hypotheque;
    NbFamille = proprieteDroite->NbFamille;
}
/**
*   @brief Surcharge de l'operateur "==" entre deux Propriete
*   @param proprieteDroite: Propriete
*   @return renvoie un booleen
*/
bool Propriete::operator== (Propriete proprieteDroite){
    return Nom == proprieteDroite.Nom;
}
/**
*   @brief obtenir le nom d'une propriete
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
string Propriete::getNom()const{  //les getters
    return Nom;
}
/**
*   @brief obtenir le prix d'un terrain nu (sans maison)
*   @param pas d'argument
*   @return retourne un entier
*/
int Propriete::getPrixTerrainNu()const{
    return PrixTerrainNu;
}
/**
*   @brief obtenir le prix d'une maison
*   @param pas d'argument
*   @return retourne un entier
*/
int Propriete::getPrixMaison()const{
    return PrixMaison;
}
/**
*   @brief obtenir la valeur de l'hypotheque d'une maison
*   @param pas d'argument
*   @return retourne un entier
*/
int Propriete::getValHypotheque()const{
    return ValHypotheque;
}
/**
*   @brief obtenir le rang de la taxe d'une Propriete
*   @param i: entier
*   @return retourne un entier
*/
int Propriete::getTaxesPropriete(int i)const{
    return TaxesPropriete[i];
}
/**
*   @brief Trouver le proprietaire d'une Propriete
*   @param pas d'argument
*   @return retourne un entier
*/
int Propriete::getProprietaire()const{
    return Proprietaire;
}
/**
*   @brief obtenir le nombre de maison sur une propriete
*   @param pas d'argument
*   @return retourne un entier
*/
int Propriete::getNbMaisons()const{
    return NbMaisons;
}
/**
*   @brief obtenir la couleur d'une propriete
*   @param pas d'argument
*   @return retourne une Couleur
*/
Couleur Propriete::getCouleur()const{
    return couleur;
}
/**
*   @brief obtenir le montant de l'hypotheque d'une Propriete
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Propriete::getHypotheque()const{
    return Hypotheque;
}
/**
*   @brief modifier le nom d'une Propriete
*   @param nomprop: chaine de caractere
*   @return pas de valeur retournee
*/
void Propriete::setNom(string nomprop){//les setters
    Nom = nomprop;
}
/**
*   @brief modifier le prix d'un terrain nu
*   @param x: entier
*   @return pas de valeur retournee
*/
void Propriete::setPrixTerrainNu(int x){
    PrixTerrainNu = x;
}
/**
*   @brief modifier le prix d'une maison
*   @param x: entier
*   @return pas de valeur retournee
*/
void Propriete::setPrixMaison(int x){
    PrixMaison = x;
}
/**
*   @brief modifier le prix de la valeur d'une hypotheque
*   @param x: entier
*   @return pas de valeur retournee
*/
void Propriete::setValHypotheque(int x){
    ValHypotheque = x;
}
/**
*   @brief modifier le tableau qui classe le rang des taxes de la propriete
*   @param *tab: tableau d'entiers
*   @return pas de valeur retournee
*/
void Propriete::setTaxesPropriete(int *tab){
    for(int i=0;i<6;i++) {TaxesPropriete[i] = tab[i];}
}
/**
*   @brief modifier le proprietaire d'une Propriete
*   @param j: entier
*   @return pas de valeur retournee
*/
void Propriete::setProprietaire(int j){
    Proprietaire = j;
}
/**
*   @brief modifier le nombre de maisons d'une Propriete
*   @param x: entier
*   @return pas de valeur retournee
*/
void Propriete::setNbMaisons(int x){
    NbMaisons = x;
}
/**
*   @brief modifier la couleur d'une Propriete
*   @param c: Couleur
*   @return pas de valeur retournee
*/
void Propriete::setCouleur(Couleur c){
    couleur=c;
}
/**
*   @brief modifier la valeur de l'hypotheque d'une Propriete
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Propriete::setHypotheque(bool x){
    Hypotheque = x;
}

/**
*   @brief Ajoute une maison a la Propriete
*   @param *j: Joueur
*   @return pas de valeur retournee
*/
void Propriete::AjouterMaison(Joueur *j){//les fonctions/procédures
    if (NbMaisons <5){
        j->DiminuerArgent(PrixMaison);
        NbMaisons += 1;
        cout<<"maison achetee"<<endl;
        }
    else
    {
        cout<<"nombre max de maisons atteint"<<endl;
    }
}
/**
*   @brief Vend les maisons et place la Propriete en hypotheque
*   @param *j: Joueur
*   @return pas de valeur retournee
*/
void Propriete::Hypothequer(Joueur * j){
    for (NbMaisons;NbMaisons <= 0;NbMaisons--){
        j->AugmenterArgent(PrixMaison);
    }
    j->AugmenterArgent(ValHypotheque);
    Hypotheque = true;
}
/**
*   @brief modifier le proprietaire d'une Propriete
*   @param NouveauP: entier
*   @return pas de valeur retournee
*/
void Propriete::ChangeProprietaire(int NouveauP){
    Proprietaire = NouveauP;
}
/**
*   @brief Fait payer un joueur non proprietaire lorsqu'il passe sur cette Propriete
*   @param Client: Joueur
*   @return pas de valeur retournee
*/
void Propriete::PayerLoyer(Joueur Client){
    Client.DiminuerArgent(TaxesPropriete[NbMaisons]);
}
/**
*   @brief Vend un certain nombre de maisons d'une Propriete
*   @param NbMaison: entier, *j: Joueur
*   @return pas de valeur retournee
*/
void Propriete::VendreMaison(int NbMaison, Joueur * j){//le nbr de maison qu'on veut vendre
    for(int i = NbMaison;i<=0;i--){
        if(NbMaisons <= 0) { break; }
        j->AugmenterArgent(PrixMaison);
    }
}

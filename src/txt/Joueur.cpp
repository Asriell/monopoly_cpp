/**
    @brief Ce fichier gere les caracteristiques des joueurs ainsi que leurs actions
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Joueur.cpp
    @date 2017/04/20
*/

#include "Joueur.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <assert.h>
#include "TableauDynamique.h"
using namespace std;

/**  @def Joueur::Joueur()
*   @brief constructeur par defaut de joueur
*   @param pas d'argument
*   @return retourne un joueur
*/
Joueur::Joueur(){
    NomJoueur ="undefined";
    NumeroJoueur = 0;
    CagnotteJoueur = 1500;//prix en €
    PositionJoueur = 0;
    CouleurJoueur = Couleur(0,0,0,"noir");
    NbCarteLibrePrison = 0;
    EnPrison = false;
    NbGare = 0;
    NbServicePublic = 0;
    EncoreEnJeu = true;
    TourPrison = 0;

}
/**
*   @brief constructeur par parametre de joueur
*   @param Nom: chaine de caractere, Numero: entier, couleurJoueur1: Couleur, couleurJoueur2: Couleur, couleurJoueur3: Couleur, couleurJoueur4: Couleur
*   @return retourne un joueur
*/
Joueur::Joueur(string Nom,int Numero, const Couleur & couleurJoueur1,const Couleur & couleurJoueur2,const Couleur & couleurJoueur3,const Couleur & couleurJoueur4){
    NomJoueur = Nom;
    NumeroJoueur = Numero;
    CagnotteJoueur = 1500;//prix en €
    PositionJoueur = 0;
    NbCarteLibrePrison = 0;
    EnPrison = false;
    NbGare = 0;
    NbServicePublic = 0;
    EncoreEnJeu = true;
    TourPrison = 0;
    switch (Numero){
    case 1 :
        {
        affecterCouleurJoueur(couleurJoueur1);
        }
        break;
    case 2 :
        {
        affecterCouleurJoueur(couleurJoueur2);
        }
        break;
    case 3 :
        {
        affecterCouleurJoueur(couleurJoueur3);
        }
        break;
    case 4 :
        {
        affecterCouleurJoueur(couleurJoueur4);
        }
        break;
    }

}

/**
*   @brief surcharge de l'operateur "=" entre deux joueurs
*   @param JoueurDroite: Joueur
*   @return retourne un joueur
*/
Joueur& Joueur::operator=(Joueur JoueurDroite){
    NomJoueur = JoueurDroite.getNomJoueur();
    NumeroJoueur = JoueurDroite.getNumeroJoueur();
    CagnotteJoueur = JoueurDroite.getCagnotteJoueur();
    ListeProprietesJoueur.vider();
    ListeProprietesJoueur.setcapacite(JoueurDroite.ListeProprietesJoueur.getcapacite());
    ListeProprietesJoueur.settaille_utilisee(0);
    for(unsigned int i =0;i<JoueurDroite.ListeProprietesJoueur.gettaille_utilisee();i++)
    {
        ListeProprietesJoueur.setIemeElement(i,JoueurDroite.ListeProprietesJoueur.valeurIemeElement(i));
    }
    ListeProprietesJoueur.settaille_utilisee(JoueurDroite.ListeProprietesJoueur.gettaille_utilisee());
    PositionJoueur = JoueurDroite.getPositionJoueur();
    CouleurJoueur = JoueurDroite.getCouleurJoueur();
    NbCarteLibrePrison = JoueurDroite.getNbCarteLibrePrison();
    EnPrison = JoueurDroite.getEnPrison();
    NbGare = JoueurDroite.getNbGare();
    NbServicePublic = JoueurDroite.getNbServicePublic();
    EncoreEnJeu = JoueurDroite.getEncoreEnJeu();
    return *this;
}


/**
*   @brief obtenir le nom d'un joueur
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
string Joueur::getNomJoueur()const{
    return NomJoueur;
}

/**
*   @brief obtenir le numero d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getNumeroJoueur()const{
    return NumeroJoueur;
}
/**
*   @brief obtenir la cagnotte d'un joueur (l'argent qu'il a en reserve)
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getCagnotteJoueur()const{
    return CagnotteJoueur;
}
/**
*   @brief obtenir la liste des proprietes d'un joueur
*   @param pas d'argument
*   @return retourne un tableau dynamique
*/
TableauDynamique Joueur::getListeProprietesJoueur()const{
    return ListeProprietesJoueur;
}
/**
*   @brief obtenir la position d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getPositionJoueur()const{
    return PositionJoueur;
}
/**
*   @brief obtenir la couleur d'un joueur
*   @param pas d'argument
*   @return retourne une couleur
*/
Couleur Joueur::getCouleurJoueur()const{
    return CouleurJoueur;
}
/**
*   @brief obtenir le nombre de cartes "libere de prison" d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getNbCarteLibrePrison()const{
    return NbCarteLibrePrison;
}
/**
*   @brief savoir si un joueur est en prison (true) ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Joueur::getEnPrison()const{
    return EnPrison;
}
/**
*   @brief obtenir le nombre de gares d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getNbGare()const{
    return NbGare;
}
/**
*   @brief obtenir le nombre de services publics d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getNbServicePublic()const{
    return NbServicePublic;
}
/**
*   @brief savoir si un joueur est encore en jeu (true) ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Joueur::getEncoreEnJeu()const{
    return EncoreEnJeu;
}
/**
*   @brief obtenir le nombre de tours passes en prison
*   @param pas d'argument
*   @return retourne un entier
*/
int Joueur::getTourPrison()const{
    return TourPrison;
}
/**
*   @brief modifier le nom d'un joueur
*   @param Nom: chaine de caractere
*   @return pas de valeur retournee
*/
void Joueur::setNomJoueur(string Nom){
    NomJoueur = Nom;
}
/**
*   @brief modifier le numero d'un joueur
*   @param Numero: entier
*   @return pas de valeur retournee
*/
void Joueur::setNumeroJoueur(int Numero){
    NumeroJoueur = Numero;
}
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Cagnotte: entier
*   @return pas de valeur retournee
*/
void Joueur::setCagnotteJoueur(int Cagnotte){
    CagnotteJoueur = Cagnotte;
}
/**
*   @brief modifier la liste des proprietes d'un joueur
*   @param e: Propriete
*   @return pas de valeur retournee
*/
void Joueur::setListeProprietesJoueur(Propriete * e){
    ListeProprietesJoueur.ajouterElement(e);
}
/**
*   @brief modifier la position d'un joueur
*   @param Position: entier
*   @return pas de valeur retournee
*/
void Joueur::setPositionJoueur(int Position){
    PositionJoueur = Position;
}
/**
*   @brief modifier la couleur d'un joueur
*   @param CouleurJ: Couleur
*   @return pas de valeur retournee
*/
void Joueur::setCouleurJoueur(Couleur CouleurJ){
    CouleurJoueur = CouleurJ;
}
/**
*   @brief modifier le nombre de cartes "libere de prison" d'un joueur
*   @param NbPrison: entier
*   @return pas de valeur retournee
*/
void Joueur::setNbCarteLibrePrison(int NbPrison){
    NbCarteLibrePrison = NbPrison;
}
/**
*   @brief placer un joueur en prison (true) ou l'en sortir (false)
*   @param Prison: booleen
*   @return pas de valeur retournee
*/
void Joueur::setEnPrison(bool Prison){
    EnPrison = Prison;
}
/**
*   @brief modifier le nombre de gares possedees par un joueur
*   @param Gare: entier
*   @return pas de valeur retournee
*/
void Joueur::setNbGare(int Gare){
    NbGare = Gare;
}
/**
*   @brief modifier le nombre de services publics possedes par un joueur
*   @param ServicePublic: entier
*   @return pas de valeur retournee
*/
void Joueur::setNbServicePublic(int ServicePublic){
    NbServicePublic = ServicePublic;
}

/**
*   @brief mettre un joueur hors-jeu (true) ou non (false)
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Joueur::setEncoreEnJeu(bool x){
    EncoreEnJeu = x;
}
/**
*   @brief modifier le nombre de tours passes en prison
*   @param x: entier
*   @return pas de valeur retournee
*/
void Joueur::setTourPrison(int x){
    TourPrison = x;
}
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Somme: entier
*   @return pas de valeur retournee
*/
void Joueur::DiminuerArgent(int Somme){
    CagnotteJoueur -= Somme;
}
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Somme: entier
*   @return pas de valeur retournee
*/
void Joueur::AugmenterArgent(int Somme){
    CagnotteJoueur += Somme;
}
/**
*   @brief faire avancer un joueur au moyen d'un lancer de dés
*   @param PaireDe: entier
*   @return pas de valeur retournee
*/
void Joueur::Avancer(De & PaireDe){
    PaireDe.LancerDe();
    if (PaireDe.GetSerieDouble() == 3)
    {
        PositionJoueur= 10;//Position de la case "simple visite"
        EnPrison = true;
        cout<<"C'est le double de trop, En prison !!"<<endl;
        PaireDe.SetSerieDouble(0);
    }
    else {
        int somme;
        somme = PaireDe.GetValeurDe1() + PaireDe.GetValeurDe2();
        while (somme !=0){
            if(PositionJoueur ==39)
            {
                PositionJoueur = 0;
                AugmenterArgent(200);
                somme -=1;
            }
            PositionJoueur +=1;
            somme -=1;

        }
        if ((PaireDe.GetValeurDe1() == PaireDe.GetValeurDe2())){
        Avancer(PaireDe);
        }
    }
}
/**
*   @brief faire avancer un joueur sur une case en particulier
*   @param Destination: entier
*   @return pas de valeur retournee
*/
void Joueur::AvancerCase(int Destination){
    if (Destination >= 40)
    {
        PositionJoueur = Destination-40;
    }
    else
    {
        PositionJoueur = Destination;
    }
}

/**
*   @brief obtenir le nombre de maisons d'un joueur
*   @param pas d'argument
*   @return renvoie un entier
*/
int Joueur::NbMaisonsJoueur()
{
    int s = 0;
    int j;
    j = ListeProprietesJoueur.gettaille_utilisee();
    for (int i=0;i<j;i++)
    {
        s +=ListeProprietesJoueur.valeurIemeElement(i).getNbMaisons();
    }
    return s;
}
/**
*   @brief obtenir le nombre de terrains non hypotheques
*   @param pas d'argument
*   @return renvoie un entier
*/
int Joueur::NbTerrainsNonHypotheques()
{
    int s = 0;
    int j = ListeProprietesJoueur.gettaille_utilisee();
    for (int i=0;i<j;i++)
    {
        if (ListeProprietesJoueur.valeurIemeElement(i).getHypotheque() == false)
        {
            s +=1;
        }
    }
    return s;
}
/**
*   @brief Oblige un joueur a verser une partie de sa cagnotte a un autre joueur
*   @param valeur: entier, receveur: Joueur
*   @return pas de valeur retournee
*/
void Joueur::Payer (int valeur, Joueur & receveur){
    if (CagnotteJoueur <= valeur)
    {
        cout<<"impossible de payer"<<endl;
        DiminuerArgent(valeur);
    }
    else
    {
        DiminuerArgent(valeur);
        receveur.AugmenterArgent(valeur);
    }
}

/**
*   @brief affecte une couleur a un joueur
*   @param c: Couleur
*   @return pas de valeur retournee
*/
void Joueur::affecterCouleurJoueur (Couleur c)
{
    CouleurJoueur.setRouge(c.getRouge());
    CouleurJoueur.setBleu(c.getBleu());
    CouleurJoueur.setVert(c.getVert());
    CouleurJoueur.setNomCouleur(c.getNomCouleur());
}
/*
void Joueur::TestRegression(){
    string res=getNomJoueur();
    string Stest="test";
    assert (typeid(Stest)==typeid(res));
    int Itest=1;
    int Ires=getNumeroJoueur();
    assert (typeid(Itest)==typeid(Ires));
    Ires=getCagnotteJoueur();
    assert (typeid(Itest)==typeid(Ires));
    Ires=getPositionJoueur();
    assert (typeid(Itest)==typeid(Ires));
    Ires=getNbCarteLibrePrison();
    assert (typeid(Itest)==typeid(Ires));
    Ires=getNbGare();
    assert (typeid(Itest)==typeid(Ires));
    Ires=getNbServicePublic();
    assert (typeid(Itest)==typeid(Ires));
    Couleur Ctest;
    Cres=getCouleurJoueur();
    assert (typeid(Ctest)==typeid(Cres));
    bool Btest;
    bool Bres=getEnPrison();
    assert (typeid(Btest)==typeid(Bres));
    int Cagnotte=getCagnotteJoueur();
    DiminuerArgent(5);
    int Baisse=getCagnotteJoueur();
    assert (Cagnotte>Baisse);
    int Cagnotte=getCagnotteJoueur();
    AugmenterArgent(5);
    int Hausse=getCagnotteJoueur();
    assert (Cagnotte<Hausse);
    int PosTest=getPositionJoueur();
    Avancer(De);
    int PosRes=getPositionJoueur();
    assert (PosRes!=PosTest);
    PosTest=getPositionJoueur();
    Avancer(Case);
    PosRes=getPositionJoueur();
    assert (PosRes!=PosTest);

}

*/

#ifndef JOUEUR_CPP_INCLUDED
#define JOUEUR_CPP_INCLUDED

/**
    @brief Ce fichier gere les en-tetes des fonctions caracteristiques des joueurs ainsi que leurs actions
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Joueur.h
    @date 2017/04/20
*/

#include <string>
#include "Case.h"
#include "TableauDynamique.h"
#include "Couleur.h"
#include "De.h"
using namespace std;
/**
    @class Joueur Joueur.h Joueur.h la classe qui permet de generer une case
*/
class Joueur
{
private :
    string NomJoueur;//pseudo que rentre le joueur en début de partie
    int NumeroJoueur;//un numéro pour désigner les joueur
    int CagnotteJoueur;//capital du joueur
    TableauDynamique ListeProprietesJoueur;//ce que possède le joueur
    int PositionJoueur;//il y a 40 cases donc € [0,39]
    Couleur CouleurJoueur;//couleur du joueur (il y en a 4 pour les 4 joueurs)
    int NbCarteLibrePrison;//le nombre de cartes "libéré de prison" possédées
    bool EnPrison;//si le joueur est en prison ou non
    int NbGare; //nombre de gares que possedent un joueur
    int NbServicePublic;//nb total de services publics possédés
    bool EncoreEnJeu;//teste so le joueur n'a pas perdu
    int TourPrison;



public :
/**
*   @brief constructeur par defaut de joueur
*   @param pas d'argument
*   @return retourne un joueur
*/
    Joueur();
/**
*   @brief constructeur par parametre de joueur
*   @param Nom: chaine de caractere, Numero: entier, couleurJoueur1: Couleur, couleurJoueur2: Couleur, couleurJoueur3: Couleur, couleurJoueur4: Couleur
*   @return retourne un joueur
*/
    Joueur(string Nom,int Numero, const Couleur & couleurJoueur1,const Couleur & couleurJoueur2,const Couleur & couleurJoueur3,const Couleur & couleurJoueur4);
/**
*   @brief surcharge de l'operateur "=" entre deux joueurs
*   @param JoueurDroite: Joueur
*   @return retourne un joueur
*/
    Joueur& operator = (Joueur JoueurDroite);
/**
*   @brief obtenir le nom d'un joueur
*   @param pas d'argument
*   @return retourne une chaine de caractere
*/
    string getNomJoueur()const;
/**
*   @brief obtenir le numero d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNumeroJoueur()const;
/**
*   @brief obtenir la cagnotte d'un joueur (l'argent qu'il a en reserve)
*   @param pas d'argument
*   @return retourne un entier
*/
    int getCagnotteJoueur()const;
/**
*   @brief obtenir la liste des proprietes d'un joueur
*   @param pas d'argument
*   @return retourne un tableau dynamique
*/
    TableauDynamique getListeProprietesJoueur()const;
/**
*   @brief obtenir la position d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
    int getPositionJoueur()const;
/**
*   @brief obtenir la couleur d'un joueur
*   @param pas d'argument
*   @return retourne une couleur
*/
    Couleur getCouleurJoueur()const;
/**
*   @brief obtenir le nombre de cartes "libere de prison" d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNbCarteLibrePrison()const;
/**
*   @brief savoir si un joueur est en prison (true) ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getEnPrison()const;
/**
*   @brief obtenir le nombre de gares d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNbGare()const;
/**
*   @brief obtenir le nombre de services publics d'un joueur
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNbServicePublic()const;
/**
*   @brief savoir si un joueur est encore en jeu (true) ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getEncoreEnJeu()const;
/**
*   @brief obtenir le nombre de tours passes en prison
*   @param pas d'argument
*   @return retourne un entier
*/
    int getTourPrison()const;
/**
*   @brief obtenir le nombre de maisons d'un joueur
*   @param pas d'argument
*   @return renvoie un entier
*/
    int NbMaisonsJoueur();//le nbr total de maisons que possède le joueur
/**
*   @brief obtenir le nombre de terrains non hypotheques
*   @param pas d'argument
*   @return renvoie un entier
*/
    int NbTerrainsNonHypotheques();//nbr de terrains hypothéqués par le joueur

/**
*   @brief modifier le nom d'un joueur
*   @param Nom: chaine de caractere
*   @return pas de valeur retournee
*/
    void setNomJoueur(string NomJoueur);
/**
*   @brief modifier le numero d'un joueur
*   @param Numero: entier
*   @return pas de valeur retournee
*/
    void setNumeroJoueur(int NumeroJoueur);
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Cagnotte: entier
*   @return pas de valeur retournee
*/
    void setCagnotteJoueur(int CagnotteJoueur);
/**
*   @brief modifier la liste des proprietes d'un joueur
*   @param e: Propriete
*   @return pas de valeur retournee
*/
    void setListeProprietesJoueur(Propriete * e);
/**
*   @brief modifier la position d'un joueur
*   @param Position: entier
*   @return pas de valeur retournee
*/
    void setPositionJoueur(int PositionJoueur);
/**
*   @brief modifier la couleur d'un joueur
*   @param CouleurJ: Couleur
*   @return pas de valeur retournee
*/
    void setCouleurJoueur(Couleur CouleurJoueur);
/**
*   @brief modifier le nombre de cartes "libere de prison" d'un joueur
*   @param NbPrison: entier
*   @return pas de valeur retournee
*/
    void setNbCarteLibrePrison(int NbCarteLibrePrison);
/**
*   @brief placer un joueur en prison (true) ou l'en sortir (false)
*   @param Prison: booleen
*   @return pas de valeur retournee
*/
    void setEnPrison(bool EnPrison);
/**
*   @brief modifier le nombre de gares possedees par un joueur
*   @param Gare: entier
*   @return pas de valeur retournee
*/
    void setNbGare(int NbGare);
/**
*   @brief modifier le nombre de services publics possedes par un joueur
*   @param ServicePublic: entier
*   @return pas de valeur retournee
*/
    void setNbServicePublic(int NbServicePublic);
/**
*   @brief mettre un joueur hors-jeu (true) ou non (false)
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setEncoreEnJeu(bool x);
/**
*   @brief modifier le nombre de tours passes en prison
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setTourPrison(int x);
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Somme: entier
*   @return pas de valeur retournee
*/
    void DiminuerArgent(int Somme);//pas de transaction, fonction plus "générale"
/**
*   @brief modifier la cagnotte d'un joueur
*   @param Somme: entier
*   @return pas de valeur retournee
*/
    void AugmenterArgent(int Somme);//pas de transaction, fonction plus "générale"
/**
*   @brief faire avancer un joueur au moyen d'un lancer de dés
*   @param PaireDe: entier
*   @return pas de valeur retournee
*/
    void Avancer(De & PaireDe);//avancer par Dé
/**
*   @brief faire avancer un joueur sur une case en particulier
*   @param Destination: entier
*   @return pas de valeur retournee
*/
    void AvancerCase(int Destination); // avancer par carte

/**
*   @brief Oblige un joueur a verser une partie de sa cagnotte a un autre joueur
*   @param valeur: entier, receveur: Joueur
*   @return pas de valeur retournee
*/
    void Payer (int valeur, Joueur & receveur);//transaction entre 2 joueurs
/**
*   @brief affecte une couleur a un joueur
*   @param c: Couleur
*   @return pas de valeur retournee
*/
    void affecterCouleurJoueur(Couleur c);
    void TestRegression();//vérifier toutes les fonctions de la classe Joueur
};

#endif // JOUEUR_CPP_INCLUDED

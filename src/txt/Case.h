#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des cases
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Case.h
    @date 2017/04/20
*/

#include "Propriete.h"
#include "Carte.h"
#include "PaquetCaisseComm.h"
#include "PaquetChance.h"
#include "Joueur.h"
#include "Jeu.h"
using namespace std;
/**
    @class Case Case.h Case.h la classe qui permet de generer une case
*/
class Case{
private :
    int NumeroCase;//un identifiant pour désigner la case
    bool ParcGratuit;//si la case est le parc gratuit
    bool AllerEnPrison;//si la case est la case "aller en prison"
    bool VisitePrison;//si la case est la case visite prison
    Propriete * propriete;//la propriété sur la case (voir tabcases)
    bool CaseDepart;//si la case est la case de départ
    bool CaisseCommunaute;//si la case est une case où le joueur devra piocher une CC
    bool Chance;//si la case est une case où le joueur devra piocher une carte chance

public :
/**
*   @brief obtenir le numero d'une case
*   @param pas d'argument
*   @return retourne un entier
*/
    int getNumeroCase()const;
/**
*   @brief pour savoir si une case est un parc gratuit ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getParcGratuit()const;
/**
*   @brief pour savoir si une case est une case "allez en prison" ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getAllerEnPrison()const;
/**
*   @brief pour savoir si une case est une case "simple visite" ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getVisitePrison()const;
/**
*   @brief obtenir la propriete d'une case
*   @param pas d'argument
*   @return retourne une propriete
*/
    Propriete * getPropriete()const;
/**
*   @brief pour savoir si une case est une case depart ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getCaseDepart()const;
/**
*   @brief pour savoir si une case permet de piocher une carte caisse de communaute ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getCaisseCommunaute()const;
/**
*   @brief pour savoir si une case permet de piocher une carte chance ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool getChance()const;
/**
*   @brief modifier le numero d'une case
*   @param x: entier
*   @return pas de valeur retournee
*/
    void setNumeroCase(int x);
/**
*   @brief faire d'une case un parc gratuit ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setParcGratuit(bool x);
/**
*   @brief faire d'une case un "allez en prison" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setAllerEnPrison(bool x);
/**
*   @brief faire d'une case un "simple visite" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setVisitePrison(bool x);
/**
*   @brief modifier une propriete
*   @param *p: Propriete
*   @return pas de valeur retournee
*/
    void setpropriete(Propriete *p);
/**
*   @brief faire d'une case une case depart ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setCaseDepart(bool x);
/**
*   @brief faire d'une case un "piocher une carte caisse communaute" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setCaisseCommunaute(bool x);
/**
*   @brief faire d'une case un "piochez une carte chance" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
    void setChance(bool x);
/**
*   @brief Permet d'appliquer l'effet d'une case sur un joueur
*   @param *j: Joueur, communaute: PaquetCaisseComm, chance: PaquetChance, *jeu: Jeu, receveur: Joueur
*   @return pas de valeur retournee
*/
    void EffetCase(Joueur *j, PaquetCaisseComm & communaute, PaquetChance & chance, Jeu * jeu,Joueur & receveur);//execute la propriete propre a la case
};

#endif // CASE_H_INCLUDED

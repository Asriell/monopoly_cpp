/**
    @brief Ce fichier contient les fonctions relatives a la gestion des cases
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Case.cpp
    @date 2017/04/20
*/

#include "Case.h"
#include "Carte.h"
#include "PaquetCaisseComm.h"
#include "PaquetChance.h"
#include "Jeu.h"
#include <iostream>
using namespace std;

 /**
 *   @brief obtenir le numero d'une case
 *   @param pas d'argument
 *   @return retourne un entier
 */
int Case::getNumeroCase()const{
    return NumeroCase;
}
/**
*   @brief pour savoir si une case est un parc gratuit ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getParcGratuit()const{
    return ParcGratuit;
}
/**
*   @brief pour savoir si une case est une case "allez en prison" ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getAllerEnPrison()const{
    return AllerEnPrison;
}
/**
*   @brief pour savoir si une case est une case "simple visite" ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getVisitePrison()const{
    return VisitePrison;
}
/**
*   @brief obtenir la propriete d'une case
*   @param pas d'argument
*   @return retourne une propriete
*/
Propriete * Case::getPropriete()const{
    return propriete;
}
/**
*   @brief pour savoir si une case est une case depart ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getCaseDepart()const{
    return CaseDepart;
}
/**
*   @brief pour savoir si une case permet de piocher une carte caisse de communaute ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getCaisseCommunaute()const{
    return CaisseCommunaute;
}
/**
*   @brief pour savoir si une case permet de piocher une carte chance ou non
*   @param pas d'argument
*   @return retourne un booleen
*/
bool Case::getChance()const{
    return Chance;
}

/**
*   @brief modifier le numero d'une case
*   @param x: entier
*   @return pas de valeur retournee
*/
void Case::setNumeroCase(int x){
    NumeroCase = x;
}
/**
*   @brief faire d'une case un parc gratuit ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setParcGratuit(bool x){
    ParcGratuit = x;
}
/**
*   @brief faire d'une case un "allez en prison" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setAllerEnPrison(bool x){
    AllerEnPrison = x;
}
/**
*   @brief faire d'une case un "simple visite" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setVisitePrison(bool x){
    VisitePrison = x;
}
/**
*   @brief modifier une propriete
*   @param *p: Propriete
*   @return pas de valeur retournee
*/
void Case::setpropriete(Propriete * p){
    propriete = p;
}
/**
*   @brief faire d'une case une case depart ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setCaseDepart(bool x){
    CaseDepart = x;
}
/**
*   @brief faire d'une case un "piocher une carte caisse communaute" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setCaisseCommunaute(bool x){
    CaisseCommunaute = x;
}
/**
*   @brief faire d'une case un "piochez une carte chance" ou non
*   @param x: booleen
*   @return pas de valeur retournee
*/
void Case::setChance(bool x){
    Chance = x;
}

/**
*   @brief Permet d'appliquer l'effet d'une case sur un joueur
*   @param *j: Joueur, communaute: PaquetCaisseComm, chance: PaquetChance, *jeu: Jeu, receveur: Joueur
*   @return pas de valeur retournee
*/
void Case::EffetCase(Joueur * j, PaquetCaisseComm & communaute, PaquetChance & chance, Jeu * jeu,Joueur & receveur){

    if (propriete->getTaxesPropriete(0)==1) //si le joueur tombe sur une compagnie
    {
        if (propriete->getProprietaire()!= 0&&propriete->getProprietaire()!=j->getNumeroJoueur())
        {
            cout<<"vous etes tombe sur une compagnie deja achetee, lancez le de"<<endl;
            char lancer;
            srand(time(NULL));
            int val1,val2;
            do
            {
                cout<<"appuyez sur d pour lancer les des"<<endl;
                cin>>lancer;
            }while (lancer !='d');
            val1=rand()%6+1;
            val2=rand()%6+1;
            cout<<"un joueur doit payer "<<val1+val2<<" € "<<endl;
            j->Payer((val1+val2)*receveur.getNbServicePublic(),receveur);
        }
        else if ((j->getCagnotteJoueur()>propriete->getPrixTerrainNu()) && (propriete->getProprietaire()==0))
        {
            cout<<"Vous etes tombe sur une compagnie. Voulez-vous l'acheter ? (Y/N)"<<endl;
            char prop;
            cin>>prop;
            if ((prop == 'Y') ||(prop == 'y'))
            {
                j->setNbServicePublic(j->getNbServicePublic()+1);
                j->DiminuerArgent(propriete->getPrixTerrainNu());
                j->getListeProprietesJoueur().ajouterElement(propriete);
                propriete->setProprietaire(j->getNumeroJoueur());
            }
        }
    }
    if (propriete->getTaxesPropriete(0)==25)//si le joueur tombe sur une gare
    {
        if (propriete->getProprietaire()!= 0 && propriete->getProprietaire()!=j->getNumeroJoueur())
        {
            cout<<"un joueur doit payer"<<endl;
            j->Payer(propriete->getTaxesPropriete(receveur.getNbGare()-1),receveur);
        }
        else if((j->getCagnotteJoueur()>propriete->getPrixTerrainNu()) && (propriete->getProprietaire()==0))
        {
            cout<<"Vous etes tombe sur une gare. Voulez-vous l'acheter ? (Y/N)"<<endl;
            char prop;
            cin>>prop;
            if ((prop == 'Y') ||(prop == 'y'))
            {
                j->setNbGare(j->getNbGare()+1);
                j->DiminuerArgent(propriete->getPrixTerrainNu());
                j->getListeProprietesJoueur().ajouterElement(propriete);
                propriete->setProprietaire(j->getNumeroJoueur());
            }
        }
    }
    if (propriete->getTaxesPropriete(0)==0)

    {
        if(AllerEnPrison)
        {
            j->setPositionJoueur(10);
            j->setEnPrison(true);
            cout<<"vous êtes tombe sur la case 'aller en prison'. En prison !\n";
        }
        if (j->getPositionJoueur()==4) {j->DiminuerArgent(200);}//les taxes "fixes"
        if (j->getPositionJoueur()==38){j->DiminuerArgent(100);}
        if ((CaseDepart==true)&&(j->getPositionJoueur()==NumeroCase)){j->AugmenterArgent(200);}
        if ((CaisseCommunaute==true)&&(j->getPositionJoueur()==NumeroCase))//Case caisse communaute
            {
                Carte * Cdc;
                Cdc = communaute.PiocherCarte();
                cout<<"vous piochez une carte caisse de communaute. Voici son effet :"<<endl;
                cout<<Cdc->getDescription()<<endl;
                Cdc->EffetCarte(j,jeu);
            }
        if ((Chance==true)&&(j->getPositionJoueur()==NumeroCase)) //Case chance
            {
                Carte *Cchance;
                Cchance = chance.PiocherCarte();
                cout <<"vous piochez une carte chance. Voici son effet :"<<endl;
                cout<<Cchance->getDescription()<<endl;
                Cchance->EffetCarte(j,jeu);
            }
    }
    else
        {
        if (propriete->getProprietaire()!= 0&&propriete->getProprietaire()!=j->getNumeroJoueur())
        {
            cout<<"un joueur est tombé sur la propriete de "<<jeu->GetJoueur(propriete->getProprietaire()-1).getNomJoueur()<<endl;
            cout<<"un joueur doit payer"<<endl;
            j->Payer(propriete->getTaxesPropriete(propriete->getNbMaisons()),receveur);
        }
        else if ((j->getCagnotteJoueur()>propriete->getPrixTerrainNu()) && (propriete->getProprietaire()==0))
        {
            cout<<"Voulez-vous l'acheter ? (Y/N)"<<endl;
            cout<<"cout : "<<propriete->getPrixTerrainNu()<<" €"<<endl;
            char prop;
            cin>>prop;
            if ((prop == 'Y') ||(prop == 'y'))
            {
                j->DiminuerArgent(propriete->getPrixTerrainNu());
                j->getListeProprietesJoueur().ajouterElement(propriete);
                propriete->setProprietaire(j->getNumeroJoueur());
            }
        }
    }
}



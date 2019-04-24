#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions pour initialiser et gerer le jeu
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Jeu.h
    @date 2017/04/20
*/

#include <iostream>
#include <string>
#include "Couleur.h"
#include "Case.h"
#include "Plateau.h"
#include "Propriete.h"
#include "Carte.h"
#include "Jeu.h"
#include "PaquetChance.h"
#include "PaquetCaisseComm.h"
#include "De.h"
#include "TableauDynamique.h"

using namespace std;
class Joueur;
/**
    @class Jeu Jeu.h Jeu.h la classe qui permet de generer une case
*/
class Jeu {

	private :
		Plateau p;
		Joueur * TabJoueur;
		PaquetChance chance;
		PaquetCaisseComm commu;
		De des;
		int NbJoueurs;

	public :
/**
*   @brief la fonction cree les cases du plateau, les cartes, et les joueurs
*   @param pas d'argument
*   @return pas de valeur retournee
*/
		void initialiserJeu();
/**
*   @brief le destructeur de la classe Jeu
*   @param pas d'argument
*   @return pas de valeur retournee
*/
		~Jeu();
/**
*   @brief Renvoie un joueur a partir de son numero
*   @param num: entier
*   @return retourne un booleen
*/
		Joueur GetJoueur(int num)const;

		const PaquetChance& GetChance()const;
		const PaquetCaisseComm& GetCommu()const;
		const De& GetDe()const;
/**
*   @brief Obtenir le nombre de joueurs
*   @param pas d'argument
*   @return retourne un entier
*/
        int getNbJoueurs()const;
/**
*   @brief Renvoie le nombre de joueurs restants (non elimines)
*   @param pas d'argument
*   @return retourne un entier
*/
		int NbJoueursRestants();
/**
*   @brief Gere les tours entre tous les joueurs, propose les actions possibles et prend en compte leurs reponses
*   @param p: Plateau, chance: PaquetChance, commu: PaquetCaisseComm, des: De, joueur: Joueur
*   @return pas de valeur retournee
*/
		void Tour(const Plateau & p, PaquetChance & chance, PaquetCaisseComm & commu, De des, Joueur * joueur);
		void Enchere(Propriete & Propriete);
/**
*   @brief La procedure qui gere les actions d'un joueur actuellement en prison.
*   @param commu: PaquetCaisseComm, chance: PaquetChance, PaireDe: De, Prisonnier: Joueur
*   @return pas de valeur retournee
*/
		void Prison(PaquetCaisseComm & commu,PaquetChance & chance,De PaireDe,Joueur * Prisonnier);
		void Faillite(Joueur * joueur);
		//void GererMaison(Joueur & Joueur);
		//void ActionCase(int IndiceCase, Joueur & Joueur );

};


#endif // JEU_H_INCLUDED

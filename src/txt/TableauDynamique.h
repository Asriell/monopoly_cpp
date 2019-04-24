#ifndef _TAB_DYN
#define _TAB_DYN

/**
    @brief Ce fichier contient en-tetes des fonctions qui permettent l'utilisation des tableaux dynamiques
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Carte.cpp
    @date 2017/04/20
*/

#include "Propriete.h"

class TableauDynamique {
private:
    unsigned int capacite;//taille max du tableau
    unsigned int taille_utilisee;//le nombre d'elmt dans le tableau
    Propriete tab[40];//le tableau
public:
    TableauDynamique ();
   // TableauDynamique ( TableauDynamique const& t);

    unsigned int getcapacite();
    unsigned int gettaille_utilisee();
    Propriete *gettab();

    void setcapacite(unsigned int capacite);
    void settaille_utilisee(unsigned int taille_utilisee);
    void setIemeElement (int i,Propriete e);
	void vider ();//supprime tous les elmts du tab
	void supprimer(Propriete * p);//supprime un seul elt de tab
    void ajouterElement (Propriete * e);//ajouter un elt a la fin du tab
    Propriete valeurIemeElement (unsigned int indice) const;//renvoie le ieme elt

};

#endif

/**
    @brief Ce fichier contient les fonctions qui permettent l'utilisation des tableaux dynamiques
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Carte.cpp
    @date 2017/04/20
*/

#include "TableauDynamique.h"
#include <iostream>
#include "Propriete.h"

using namespace std;
TableauDynamique::TableauDynamique (){
    capacite = 1;
    taille_utilisee = 0;
}



unsigned int TableauDynamique::getcapacite(){
    return capacite;
}

unsigned int TableauDynamique::gettaille_utilisee(){
    return taille_utilisee;
}

Propriete * TableauDynamique::gettab(){
    return tab;
}

void TableauDynamique::setcapacite(unsigned int c){
    capacite = c;
}

void TableauDynamique::settaille_utilisee(unsigned int tu){
    taille_utilisee = tu;
}

void TableauDynamique::setIemeElement(int i,Propriete e){
    tab[i] = e;
}
/*
void TableauDynamique::vider (){
    for(int i=0;i<taille_utilisee;i++) {
            tab[i]=NULL;
    }
}
*/
void TableauDynamique::supprimer(Propriete * p){
    unsigned int i = 0;
    string tampon = p->getNom();
    while(i < taille_utilisee)
        if(tampon == tab[i].getNom()) {
                while (i < taille_utilisee){
                    tab[i] = tab[i+1];
                    i++;
                }
                //tab[i+1] = NULL;
                taille_utilisee -= 1;
                break;
        }
        i++;
}

void TableauDynamique::ajouterElement (Propriete * e){
    if (taille_utilisee == capacite) { capacite *= 2;}
    tab[taille_utilisee] = e;
    taille_utilisee += 1;
}

Propriete TableauDynamique::valeurIemeElement (unsigned int indice) const{
    return tab[indice];
}


void TableauDynamique::vider(){
    capacite = 1;
    taille_utilisee = 0;

}

























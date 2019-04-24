/**
    @brief Ce fichier contient les fonctions relatives a la gestion des files des cartes chance
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  PaquetChance.cpp
    @date 2017/04/20
*/

#include "PaquetChance.h"
#include <string>
#include "Carte.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/**  @def PaquetChance()
*   @brief constructeur par defaut de PaquetChance
*   @param pas d'argument
*   @return retourne une file de cartes "caisse de communaute"
*/
PaquetChance::PaquetChance () {
    prem = NULL;
    last = NULL;

}
/**
*   @brief surcharge de l'operateur "=" entre deux paquets de "cartes chance"
*   @param p: PaquetCaisseComm
*   @return retourne un paquet de "caisse communaute"
*/
PaquetChance& PaquetChance::operator = (const PaquetChance & l) {
    Cellule * temp = l.prem;
    while (temp != NULL) {
        ajouterEnQueue(temp->info);
        temp = temp->suivant;
    }
    return *this;
}

PaquetChance::~PaquetChance () {
  vider();
}
/**
*   @brief vide la liste PaquetChance de toutes ses cellules (cartes)
*   @param pas d'argument
*   @return pas de valeur retournee
*/
void PaquetChance::vider () {
    while (!estVide()) supprimerTete();
}
/**
*   @brief verifie si une file est bien vide (true) ou non (false)
*   @param pas d'argument
*   @return retourne un booleen
*/
bool PaquetChance::estVide () const {
    return prem == NULL;
}
/**
*   @brief Compte le nombre d'elements dans la file
*   @param pas d'argument
*   @return retourne un entier positif
*/
unsigned int PaquetChance::nbElements () const {
    unsigned int nb = 0;
    Cellule * temp = prem;
    while (temp != NULL) {
        nb++;
        temp = temp->suivant;
    }
    return nb;
}
/**
*   @brief Selectionne la i-eme carte de la file
*   @param indice: entier positif
*   @return retourne une Carte
*/
Carte *PaquetChance::iemeElement (unsigned int i) const {
  Cellule * temp = prem;
  for (unsigned int j = 0; j < i; j++) {
      temp = temp->suivant;
      if (temp == NULL) {cout << "Erreur PaquetChance::iemeElement, i trop grand"; exit(1);}
  }
  return temp->info;
}
/**
*   @brief Remplace le i-eme element par une carte passee en parametre
*   @param indice: entier positif, *e: Carte
*   @return pas de valeur retournee
*/
void PaquetChance::modifierIemeElement (unsigned int i, Carte *e) {
  Cellule * temp = prem;
  for (unsigned int j = 0; j < i; j++) {
      temp = temp->suivant;
      if (temp == NULL) {cout << "Erreur PaquetChance::iemeElement, i trop grand"; exit(1);}
  }
  temp->info = e;
}
/**
*   @brief Ajoute un element passe en parametre au debut de la file
*   @param *e: Carte
*   @return pas de valeur retournee
*/
void PaquetChance::ajouterEnTete (Carte *e) {
  Cellule * temp = new Cellule;
  temp->info = e;
  temp->suivant = prem;
  temp->precedent = NULL;

  /* Attention au cas d'une liste qui etait vide */
  if (estVide()) last = temp;
  else prem->precedent = temp;

  prem = temp;
}
/**
*   @brief Supprime le premier element de la file
*   @param pas d'argument
*   @return pas de valeur retournee
*/
void PaquetChance::supprimerTete () {
  Cellule * temp = prem;
  prem = prem->suivant;
  if(prem != NULL) prem->precedent = NULL;
  else last = NULL;
  delete temp;
}
/**
*   @brief Ajoute un element passe en parametre a la fin de la file
*   @param *e: Carte
*   @return pas de valeur retournee
*/
void PaquetChance::ajouterEnQueue (Carte *e) {
  if (estVide()) ajouterEnTete(e);
  else {
      Cellule * temp = new Cellule;
      temp->info = e;
      temp->suivant = NULL;
      temp->precedent = last;

      last->suivant = temp;
      last = temp;
    }
}

/**
*   @brief Insere une carte a la i-eme place de la file
*   @param *e: Carte, indice: entier positif
*   @return pas de valeur retournee
*/
void PaquetChance::insererElement (Carte *e, unsigned int position) {
  Cellule *c, *nouv;

  if (estVide() || (position == 0)) ajouterEnTete(e);
  else if (position == nbElements()) ajouterEnQueue(e);
  else {
      /* 1  <=  position  <=  nb_elements-1 */
      c = prem;
      for (unsigned int i = 0; i < position; i++) c = c->suivant;
      /* c pointe sur la cellule avant laquelle il faut inserer e */
      nouv = new Cellule;
      nouv->info = e;
      nouv->suivant = c;
      nouv->precedent = c->precedent;

      c->precedent->suivant = nouv;
      c->precedent = nouv;
    }
}
      /* Postconditions : une copie indépendante de e est insérée de sorte qu'elle occupe la position d'indice en paramètre */
/**
*   @brief Trie la file en fonction de l'id des cartes
*   @param pas d'argument
*   @return pas de valeur retournee
*/
void PaquetChance::trier() {
    // Tri par insertion
    if (prem == NULL || prem->suivant == NULL) return ; // rien a faire si moins de 2 elements

    Cellule * dernieretriee = prem;
    Cellule * aplacer = prem->suivant;
    Cellule * c;

    while (aplacer != NULL) { // boucle principale sur les elements a placer
        c = prem;
        while ((c != aplacer) && (c->info < aplacer->info)) c = c->suivant;
        /*
        En sortie du while, on sait que :
          (1) soit c->info est supérieur à aplacer->info : on doit insérer aplacer entre le précédent de c et c.
          (2) soit c == aplacer : aplacer est à sa place
        */

        Cellule * precC = c->precedent;
        Cellule * precAPlacer = aplacer->precedent;
        Cellule * suivAPlacer = aplacer->suivant;

        if (c != aplacer) {  /* cas 1 */
            if (precC != NULL) precC->suivant = aplacer;
            else prem = aplacer;
            if (suivAPlacer == NULL) last = precAPlacer;
            else suivAPlacer->precedent = precAPlacer;
            // deinsertion aplacer
            precAPlacer->suivant = suivAPlacer;
            // insertion [precC,C]
            aplacer->suivant = c;
            aplacer->precedent = precC;
            c->precedent = aplacer;
            // iteration
            dernieretriee->suivant = suivAPlacer;
        }
        else { /* cas 2 */
            dernieretriee = aplacer;
        }
        aplacer = dernieretriee->suivant;
    }
}
/**
*   @brief Pioche une carte, execute son effet, et la remet a la fin du paquet
*   @param pas d'argument
*   @return renvoie une Carte
*/
Carte * PaquetChance::PiocherCarte()
{
    Carte * c (iemeElement(0));
    if (iemeElement(0)->getCategorieEffet() != 1)
    {//si ce n'est pas une carte libéré prison, la remettre sous le paquet
    ajouterEnQueue(iemeElement(0));
    }
    supprimerTete();
    return c;
}

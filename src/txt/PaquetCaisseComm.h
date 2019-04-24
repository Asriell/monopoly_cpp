#ifndef PAQUETCAISSECOMM_H_INCLUDED
#define PAQUETCAISSECOMM_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des files des cartes caisse de communaute
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  PaquetCaisseComm.h
    @date 2017/04/20
*/

class Carte;
/**
    @class PaquetCaisseComm PaquetCaisseComm.h PaquetCaisseComm.h la classe qui permet de generer une case
*/
class PaquetCaisseComm{
public:
struct Cellule {
    Carte *info;
    Cellule * suivant;
    Cellule * precedent;
};
    Cellule * prem;
    Cellule * last;
/**
*   @brief constructeur par defaut de PaquetCaisseComm
*   @param pas d'argument
*   @return retourne une file de cartes "caisse de communaute"
*/
    PaquetCaisseComm ();
/**
*   @brief destructeur de PaquetCaisseComm
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    ~PaquetCaisseComm ();
/**
*   @brief surcharge de l'operateur "=" entre deux paquets de "caisse communaute"
*   @param p: PaquetCaisseComm
*   @return retourne un paquet de "caisse communaute"
*/
    PaquetCaisseComm& operator = (const PaquetCaisseComm & p);
    /* Postcondition : la liste correspond à une copie de l (mais les 2 listes sont totalement indépendantes l'une de l'autre) */
/**
*   @brief vide la liste PaquetCaisseComm de toutes ses cellules (cartes)
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    void vider ();
    /* Postcondition : la liste ne contient plus aucune cellule */
/**
*   @brief verifie si une file est bien vide (true) ou non (false)
*   @param pas d'argument
*   @return retourne un booleen
*/
    bool estVide () const;
    /* Résultat : vrai si liste vide, faux sinon */
/**
*   @brief Compte le nombre d'elements dans la file
*   @param pas d'argument
*   @return retourne un entier positif
*/
    unsigned int nbElements () const;
    /* Résultat : nombre d'éléments contenus dans la liste */
/**
*   @brief Selectionne la i-eme carte de la file
*   @param indice: entier positif
*   @return retourne une Carte
*/
    Carte *iemeElement (unsigned int indice) const;
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'éléments
       Résultat : valeur de l'élément à l'indice en paramètre, sachant que les éléments sont numérotes à partir de 0 */
/**
*   @brief Remplace le i-eme element par une carte passee en parametre
*   @param indice: entier positif, *e: Carte
*   @return pas de valeur retournee
*/
    void modifierIemeElement (unsigned int indice, Carte *e);
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'éléments
       Postcondition : e remplace l'élément à l'indice en paramètre, sachant que les éléments sont numérotes à partir de 0 */
/**
*   @brief Ajoute un element passe en parametre au debut de la file
*   @param *e: Carte
*   @return pas de valeur retournee
*/
    void ajouterEnTete (Carte *e);
    /* Postcondition : e est ajouté en tête de liste */
/**
*   @brief Ajoute un element passe en parametre a la fin de la file
*   @param *e: Carte
*   @return pas de valeur retournee
*/
    void ajouterEnQueue (Carte *e);
    /* Postcondition : e est ajouté en fin de liste */
/**
*   @brief Supprime le premier element de la file
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    void supprimerTete ();
    /* Precondition : la liste n'est pas vide
       Postcondition : la liste perd son premier élément */
/**
*   @brief Insere une carte a la i-eme place de la file
*   @param *e: Carte, indice: entier positif
*   @return pas de valeur retournee
*/
    void insererElement (Carte *e, unsigned int indice);
    /* Preconditions : 0 <= indice <= nombre d'éléments
       Postconditions : une copie indépendante de e est insérée de sorte qu'elle occupe la position d'indice en paramètre */
/**
*   @brief Trie la file en fonction de l'id des cartes
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    void trier ();
    /* Postcondition : la liste est triée dans l'ordre croissant des valeurs des éléments */
/**
*   @brief Pioche une carte, execute son effet, et la remet a la fin du paquet
*   @param pas d'argument
*   @return renvoie une Carte
*/
    Carte * PiocherCarte (); // pioche une carte. La supprime de la tête et la retourne. Si ce n'est pas une carte "libéré prison, la rajoute en queue.
};

#endif // PAQUETCAISSECOMM_H_INCLUDED

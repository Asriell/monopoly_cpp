#ifndef DE_H_INCLUDED
#define DE_H_INCLUDED

/**
    @brief Ce fichier contient les en-tetes des fonctions relatives a la gestion des des
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  De.h
    @date 2017/04/20
*/

#include <stdlib.h>
/**
    @class De De.h De.h la classe qui permet de generer une case
*/
class De {
    private :
    int ValeurDe1;
    int ValeurDe2;
    int SerieDouble;

    public :
/**
*   @brief Constructeur par defaut de la classe De qui cree un de
*   @param pas d'argument
*   @return retourne un de
*/
    De();
/**
*   @brief obtenir la valeur du premier de
*   @param pas d'argument
*   @return retourne un entier
*/
    int GetValeurDe1()const;
/**
*   @brief obtenir la valeur du deuxieme de
*   @param pas d'argument
*   @return retourne un entier
*/
    int GetValeurDe2()const;
/**
*   @brief obtenir la valeur des des en cas de double
*   @param pas d'argument
*   @return retourne un entier
*/
    int GetSerieDouble()const;
/**
*   @brief modifier la valeur du premier de
*   @param valeur: entier
*   @return pas de valeur retournee
*/
    void SetValeurDe1(int valeur);
/**
*   @brief modifier la valeur du deuxieme de
*   @param valeur: entier
*   @return pas de valeur retournee
*/
    void SetValeurDe2(int valeur);
/**
*   @brief modifier la valeur des des en cas de double
*   @param valeur: entier
*   @return pas de valeur retournee
*/
    void SetSerieDouble(int valeur);
/**
*   @brief la fonction genere aleatoirement deux valeurs pour les deux des
*   @param pas d'argument
*   @return pas de valeur retournee
*/
    void LancerDe();

};

#endif

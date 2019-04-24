/**
    @brief Ce fichier contient les fonctions relatives a la gestion des d¨¦s
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  De.cpp
    @date 2017/04/20
*/

#include "De.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;
 /**  @def De::De()
 *   @brief Constructeur par defaut de la classe De qui cree un de
 *   @param pas d'argument
 *   @return retourne un de
 */
De::De(){
    ValeurDe1=0;
    ValeurDe2=0;
    SerieDouble=0;
}
/**
*   @brief obtenir la valeur des des en cas de double
*   @param pas d'argument
*   @return retourne un entier
*/
int De::GetSerieDouble()const{
    return SerieDouble;
}
/**
*   @brief obtenir la valeur du premier de
*   @param pas d'argument
*   @return retourne un entier
*/
int De::GetValeurDe1()const{
    return ValeurDe1;
}
/**
*   @brief obtenir la valeur du deuxieme de
*   @param pas d'argument
*   @return retourne un entier
*/
int De::GetValeurDe2()const{
    return ValeurDe2;
}
/**
*   @brief modifier la valeur du premier de
*   @param valeur: entier
*   @return pas de valeur retournee
*/
void De::SetValeurDe1(int valeur){
    ValeurDe1=valeur;
}
/**
*   @brief modifier la valeur du deuxieme de
*   @param valeur: entier
*   @return pas de valeur retournee
*/
void De::SetValeurDe2(int valeur){
    ValeurDe2=valeur;
}
/**
*   @brief modifier la valeur des des en cas de double
*   @param valeur: entier
*   @return pas de valeur retournee
*/
void De::SetSerieDouble(int valeur){
    SerieDouble=valeur;
}
/**
*   @brief la fonction genere aleatoirement deux valeurs pour les deux des
*   @param pas d'argument
*   @return pas de valeur retournee
*/
void De::LancerDe(){
    char lancer;
    cout<<"appuyez sur d pour lancer les des"<<endl;
    cin>>lancer;
    srand(time(NULL));
    int valeur1, valeur2;
    if(lancer =='d')
    {
        valeur1=rand()%6+1;
        valeur2=rand()%6+1;
        SetValeurDe1(valeur1);
        SetValeurDe2(valeur2);
    }
    else {LancerDe();}

    if (valeur1==valeur2){
        cout<<"DOUBLE !"<<endl;
        SerieDouble++;
    }
}

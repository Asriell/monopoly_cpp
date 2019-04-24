/**
    @brief Ce fichier contient les fonctions pour initialiser et gerer le jeu
    @author Matthieu Cherrier, Kevin Burdin, Tristan Damian
    @file  Jeu.cpp
    @date 2017/04/20
*/

#include "Jeu.h"
#include "Couleur.h"
#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;

/**  @def Jeu::initialiserJeu()
*   @brief la fonction cree les cases du plateau, les cartes, et les joueurs
*   @param pas d'argument
*   @return pas de valeur retournee
*/
void Jeu::initialiserJeu(){
    Couleur marron (136,66,29,"marron");
    int Taxesp0[6];
    int Taxescompagnie[6];
    for (int i =0;i<4;i++)
    {
        Taxesp0[i] = 0;
        Taxescompagnie[i] = 0;
    }
    Taxescompagnie[0] = 1;

    int  Taxesp1[6];
    Taxesp1[0] = 2;
    Taxesp1[1] = 10;
    Taxesp1[2] = 30;
    Taxesp1[3] = 90;
    Taxesp1[4] = 160;
    Taxesp1[5] = 250;
    Propriete p1 ("Belleville",60,50,30,Taxesp1,0,0,marron,false,2); //vraies taxes [2,10,30,90,160,250]
    p.TabCases[1].setNumeroCase(1);
    p.TabCases[1].setParcGratuit(false);
    p.TabCases[1].setAllerEnPrison(false);
    p.TabCases[1].setVisitePrison(false);
    p.TabCases[1].setpropriete(&p1);
    p.TabCases[1].setChance(false);
    p.TabCases[1].setCaisseCommunaute(false);
    p.TabCases[1].setCaseDepart(false);

    Propriete p2 ("CaisseCommu",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[2].setNumeroCase(2);
    p.TabCases[2].setParcGratuit(false);
    p.TabCases[2].setAllerEnPrison(false);
    p.TabCases[2].setVisitePrison(false);
    p.TabCases[2].setpropriete(&p2);
    p.TabCases[2].setChance(false);
    p.TabCases[2].setCaisseCommunaute(true);
    p.TabCases[2].setCaseDepart(false);

    int Taxesp3[6];
    Taxesp3[0] = 4;
    Taxesp3[1] = 20;
    Taxesp3[2] = 60;
    Taxesp3[3] = 180;
    Taxesp3[4] = 320;
    Taxesp3[5] = 450;
    Propriete p3 ("Lecourbe",60,50,30,Taxesp3,0,0,marron,false,2);//vraies taxes [4,20,60,180,320,450]
    p.TabCases[3].setNumeroCase(3);
    p.TabCases[3].setParcGratuit(false);
    p.TabCases[3].setAllerEnPrison(false);
    p.TabCases[3].setVisitePrison(false);
    p.TabCases[3].setpropriete(&p3);
    p.TabCases[3].setChance(false);
    p.TabCases[3].setCaisseCommunaute(false);
    p.TabCases[3].setCaseDepart(false);
    //il s'agit de l'impot sur le revenu, il faut une fonction pour gérer la case 4.
    Propriete p4 ("Impot",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[4].setNumeroCase(4);
    p.TabCases[4].setParcGratuit(false);
    p.TabCases[4].setAllerEnPrison(false);
    p.TabCases[4].setVisitePrison(false);
    p.TabCases[4].setpropriete(&p4);
    p.TabCases[4].setChance(false);
    p.TabCases[4].setCaisseCommunaute(false);
    p.TabCases[4].setCaseDepart(false);

    int Taxesgare[6];
    Taxesgare[0] = 25;
    Taxesgare[1] = 50;
    Taxesgare[2] = 100;
    Taxesgare[3] = 200;
    Taxesgare[4] = 0;
    Taxesgare[5] = 0;
    Couleur gare (0,0,0,"noir");//couleur "bidon" pour les gares
    Propriete p5 ("Montparnasse",200,0,100,Taxesgare,0,0,gare,false,4);//vraies taxes [25,50,100,200,0,0]
    p.TabCases[5].setNumeroCase(5);
    p.TabCases[5].setParcGratuit(false);
    p.TabCases[5].setAllerEnPrison(false);
    p.TabCases[5].setVisitePrison(false);
    p.TabCases[5].setpropriete(&p5);
    p.TabCases[5].setChance(false);
    p.TabCases[5].setCaisseCommunaute(false);
    p.TabCases[5].setCaseDepart(false);

    int Taxesp6 [6];
    Taxesp6[0] = 4;
    Taxesp6[1] = 30;
    Taxesp6[2] = 90;
    Taxesp6[3] = 270;
    Taxesp6[4] = 400;
    Taxesp6[5] = 550;
    Couleur azurin (169,234,254,"azurin");
    Propriete p6 ("Vaugirard",100,50,50,Taxesp6,0,0,azurin,false,3);//vraies taxes [6,30,90,270,400,550]
    p.TabCases[6].setNumeroCase(6);
    p.TabCases[6].setParcGratuit(false);
    p.TabCases[6].setAllerEnPrison(false);
    p.TabCases[6].setVisitePrison(false);
    p.TabCases[6].setpropriete(&p6);
    p.TabCases[6].setChance(false);
    p.TabCases[6].setCaisseCommunaute(false);
    p.TabCases[6].setCaseDepart(false);

    Propriete p7 ("Chance",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[7].setNumeroCase(7);
    p.TabCases[7].setParcGratuit(false);
    p.TabCases[7].setAllerEnPrison(false);
    p.TabCases[7].setVisitePrison(false);
    p.TabCases[7].setpropriete(&p7);
    p.TabCases[7].setChance(true);
    p.TabCases[7].setCaisseCommunaute(false);
    p.TabCases[7].setCaseDepart(false);

    int Taxesp8[6];
    Taxesp8[0] = 8;
    Taxesp8[1] = 40;
    Taxesp8[2] = 100;
    Taxesp8[3] = 300;
    Taxesp8[4] = 4500;
    Taxesp8[5] = 600;
    Propriete p8 ("Courcelles",100,50,50,Taxesp8,0,0,azurin,false,3);//vraies taxes [8,40,100,300,450,600]
    p.TabCases[8].setNumeroCase(8);
    p.TabCases[8].setParcGratuit(false);
    p.TabCases[8].setAllerEnPrison(false);
    p.TabCases[8].setVisitePrison(false);
    p.TabCases[8].setpropriete(&p8);
    p.TabCases[8].setChance(false);
    p.TabCases[8].setCaisseCommunaute(false);
    p.TabCases[8].setCaseDepart(false);

    Propriete p9 ("Republique",120,50,60,Taxesp8,0,0,azurin,false,3);//vraies taxes [8,40,100,300,450,600]
    p.TabCases[9].setNumeroCase(9);
    p.TabCases[9].setParcGratuit(false);
    p.TabCases[9].setAllerEnPrison(false);
    p.TabCases[9].setVisitePrison(false);
    p.TabCases[9].setpropriete(&p9);
    p.TabCases[9].setChance(false);
    p.TabCases[9].setCaisseCommunaute(false);
    p.TabCases[9].setCaseDepart(false);

    Propriete p10 ("Visite",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[10].setNumeroCase(10);
    p.TabCases[10].setParcGratuit(false);
    p.TabCases[10].setAllerEnPrison(false);
    p.TabCases[10].setVisitePrison(true);
    p.TabCases[10].setpropriete(&p10);
    p.TabCases[10].setChance(false);
    p.TabCases[10].setCaisseCommunaute(false);
    p.TabCases[10].setCaseDepart(false);

    int Taxesp11[6];
    Taxesp11[0] = 10;
    Taxesp11[1] = 50;
    Taxesp11[2] = 150;
    Taxesp11[3] = 450;
    Taxesp11[4] = 625;
    Taxesp11[5] = 750;
    Couleur rose (249,66,158, "rose");
    Propriete p11 ("Villette",140,100,70,Taxesp11,0,0,rose,false,3);//vraies taxes [10,50,150,450,625,750]
    p.TabCases[11].setNumeroCase(11);
    p.TabCases[11].setParcGratuit(false);
    p.TabCases[11].setAllerEnPrison(false);
    p.TabCases[11].setVisitePrison(false);
    p.TabCases[11].setpropriete(&p11);
    p.TabCases[11].setChance(false);
    p.TabCases[11].setCaisseCommunaute(false);
    p.TabCases[11].setCaseDepart(false);

    Couleur compagnie (255,255,255,"blanc");//couleur "bidon" pour les compagnies.
    Propriete p12 ("EDF",150,0,75,Taxescompagnie,0,0,compagnie,false,2);//vraies taxes [0,0,0,0,0,0]
    p.TabCases[12].setNumeroCase(12);
    p.TabCases[12].setParcGratuit(false);
    p.TabCases[12].setAllerEnPrison(false);
    p.TabCases[12].setVisitePrison(false);
    p.TabCases[12].setpropriete(&p12);
    p.TabCases[12].setChance(false);
    p.TabCases[12].setCaisseCommunaute(false);
    p.TabCases[12].setCaseDepart(false);

    int Taxesp13[6];
    Taxesp13[0] = 10;
    Taxesp13[1] = 50;
    Taxesp13[2] = 150;
    Taxesp13[3] = 450;
    Taxesp13[4] = 625;
    Taxesp13[5] = 750;
    Propriete p13 ("Neuilly",140,100,70,Taxesp13,0,0,rose,false,3);//vraies taxes [10,50,150,450,625,750]
    p.TabCases[13].setNumeroCase(13);
    p.TabCases[13].setParcGratuit(false);
    p.TabCases[13].setAllerEnPrison(false);
    p.TabCases[13].setVisitePrison(false);
    p.TabCases[13].setpropriete(&p13);
    p.TabCases[13].setChance(false);
    p.TabCases[13].setCaisseCommunaute(false);
    p.TabCases[13].setCaseDepart(false);

    int Taxesp14[6];
    Taxesp14[0] = 12;
    Taxesp14[1] = 60;
    Taxesp14[2] = 180;
    Taxesp14[3] = 500;
    Taxesp14[4] = 700;
    Taxesp14[5] = 900;
    Propriete p14 ("Paradis",160,100,80,Taxesp14,0,0,rose,false,3);//vraies taxes [12,60,180,500,700,900]
    p.TabCases[14].setNumeroCase(14);
    p.TabCases[14].setParcGratuit(false);
    p.TabCases[14].setAllerEnPrison(false);
    p.TabCases[14].setVisitePrison(false);
    p.TabCases[14].setpropriete(&p14);
    p.TabCases[14].setChance(false);
    p.TabCases[14].setCaisseCommunaute(false);
    p.TabCases[14].setCaseDepart(false);


    Propriete p15 ("Lyon",200,0,100,Taxesgare,0,0,gare,false,4);//vraies taxes [25,50,100,200,0,0]
    p.TabCases[15].setNumeroCase(15);
    p.TabCases[15].setParcGratuit(false);
    p.TabCases[15].setAllerEnPrison(false);
    p.TabCases[15].setVisitePrison(false);
    p.TabCases[15].setpropriete(&p15);
    p.TabCases[15].setChance(false);
    p.TabCases[15].setCaisseCommunaute(false);
    p.TabCases[15].setCaseDepart(false);

    int Taxesp16 [6];
    Taxesp16[0] = 17;
    Taxesp16[1] = 70;
    Taxesp16[2] = 200;
    Taxesp16[3] = 550;
    Taxesp16[4] = 700;
    Taxesp16[5] = 900;
    Couleur orange (255,127,0, "orange");
    Propriete p16 ("Mozart",180,100,90,Taxesp16,0,0,orange,false,3);//vraies taxes [17,70,200,550,700,900]
    p.TabCases[16].setNumeroCase(16);
    p.TabCases[16].setParcGratuit(false);
    p.TabCases[16].setAllerEnPrison(false);
    p.TabCases[16].setVisitePrison(false);
    p.TabCases[16].setpropriete(&p16);
    p.TabCases[16].setChance(false);
    p.TabCases[16].setCaisseCommunaute(false);
    p.TabCases[16].setCaseDepart(false);

    p.TabCases[17].setNumeroCase(17);
    p.TabCases[17].setParcGratuit(false);
    p.TabCases[17].setAllerEnPrison(false);
    p.TabCases[17].setVisitePrison(false);
    p.TabCases[17].setpropriete(&p2);
    p.TabCases[17].setChance(false);
    p.TabCases[17].setCaisseCommunaute(true);
    p.TabCases[17].setCaseDepart(false);

    int Taxesp18[6];
    Taxesp18[0] = 14;
    Taxesp18[1] = 70;
    Taxesp18[2] = 200;
    Taxesp18[3] = 550;
    Taxesp18[4] = 700;
    Taxesp18[5] = 950;
    Propriete p17 ("Saint-Michel",180,100,90,Taxesp18,0,0,orange,false,3);//vraies taxes [14,70,200,550,700,950]
    p.TabCases[18].setNumeroCase(18);
    p.TabCases[18].setParcGratuit(false);
    p.TabCases[18].setAllerEnPrison(false);
    p.TabCases[18].setVisitePrison(false);
    p.TabCases[18].setpropriete(&p17);
    p.TabCases[18].setChance(false);
    p.TabCases[18].setCaisseCommunaute(false);
    p.TabCases[18].setCaseDepart(false);

    int Taxesp19[6];
    Taxesp19[0] = 16;
    Taxesp19[1] = 80;
    Taxesp19[2] = 220;
    Taxesp19[3] = 600;
    Taxesp19[4] = 800;
    Taxesp19[5] = 1000;
    Propriete p18 ("Pigalle",200,100,100,Taxesp19,0,0,orange,false,3);//vraies taxes [16,80,220,600,800,1000]
    p.TabCases[19].setNumeroCase(19);
    p.TabCases[19].setParcGratuit(false);
    p.TabCases[19].setAllerEnPrison(false);
    p.TabCases[19].setVisitePrison(false);
    p.TabCases[19].setpropriete(&p18);
    p.TabCases[19].setChance(false);
    p.TabCases[19].setCaisseCommunaute(false);
    p.TabCases[19].setCaseDepart(false);

    Propriete p20 ("Parc",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[20].setNumeroCase(20);
    p.TabCases[20].setParcGratuit(true);
    p.TabCases[20].setAllerEnPrison(false);
    p.TabCases[20].setVisitePrison(false);
    p.TabCases[20].setpropriete(&p20);
    p.TabCases[20].setChance(false);
    p.TabCases[20].setCaisseCommunaute(false);
    p.TabCases[20].setCaseDepart(false);


    int Taxesp21[6];
    Taxesp21[0] = 18;
    Taxesp21[1] = 90;
    Taxesp21[2] = 250;
    Taxesp21[3] = 700;
    Taxesp21[4] = 875;
    Taxesp21[5] = 1050;
    Couleur rouge (255,0,0, "rouge");
    Propriete p21 ("Matignon",220,150,110,Taxesp21,0,0,rouge,false,3);//[18,90,250,700,875,1050]
    p.TabCases[21].setNumeroCase(21);
    p.TabCases[21].setParcGratuit(false);
    p.TabCases[21].setAllerEnPrison(false);
    p.TabCases[21].setVisitePrison(false);
    p.TabCases[21].setpropriete(&p21);
    p.TabCases[21].setChance(false);
    p.TabCases[21].setCaisseCommunaute(false);
    p.TabCases[21].setCaseDepart(false);

    Propriete p22 ("Chance",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[22].setNumeroCase(22);
    p.TabCases[22].setParcGratuit(false);
    p.TabCases[22].setAllerEnPrison(false);
    p.TabCases[22].setVisitePrison(false);
    p.TabCases[22].setpropriete(&p22);
    p.TabCases[22].setChance(true);
    p.TabCases[22].setCaisseCommunaute(false);
    p.TabCases[22].setCaseDepart(false);

    int Taxesp23[6];
    Taxesp23[0] = 18;
    Taxesp23[1] = 90;
    Taxesp23[2] = 250;
    Taxesp23[3] = 700;
    Taxesp23[4] = 875;
    Taxesp23[5] = 1050;
    Propriete p23 ("Malesherbes",220,150,110,Taxesp23,0,0,rouge,false,3);//[18,90,250,700,875,1050]
    p.TabCases[23].setNumeroCase(23);
    p.TabCases[23].setParcGratuit(false);
    p.TabCases[23].setAllerEnPrison(false);
    p.TabCases[23].setVisitePrison(false);
    p.TabCases[23].setpropriete(&p23);
    p.TabCases[23].setChance(false);
    p.TabCases[23].setCaisseCommunaute(false);
    p.TabCases[23].setCaseDepart(false);

    int Taxesp24[6];
    Taxesp24[0] = 20;
    Taxesp24[1] = 100;
    Taxesp24[2] = 300;
    Taxesp24[3] = 750;
    Taxesp24[4] = 925;
    Taxesp24[5] = 1100;
    Propriete p24 ("Henri-Martin",240,150,120,Taxesp24,0,0,rouge,false,3);//[20,100,300,750,925,1100]
    p.TabCases[24].setNumeroCase(24);
    p.TabCases[24].setParcGratuit(false);
    p.TabCases[24].setAllerEnPrison(false);
    p.TabCases[24].setVisitePrison(false);
    p.TabCases[24].setpropriete(&p24);
    p.TabCases[24].setChance(false);
    p.TabCases[24].setCaisseCommunaute(false);
    p.TabCases[24].setCaseDepart(false);

    Propriete p25 ("Nord",200,0,100,Taxesgare,0,0,gare,false,4);//[25,50,100,200,0,0]
    p.TabCases[25].setNumeroCase(25);
    p.TabCases[25].setParcGratuit(false);
    p.TabCases[25].setAllerEnPrison(false);
    p.TabCases[25].setVisitePrison(false);
    p.TabCases[25].setpropriete(&p25);
    p.TabCases[25].setChance(false);
    p.TabCases[25].setCaisseCommunaute(false);
    p.TabCases[25].setCaseDepart(false);

    int Taxesp26[6];
    Taxesp26[0] = 22;
    Taxesp26[1] = 110;
    Taxesp26[2] = 330;
    Taxesp26[3] = 800;
    Taxesp26[4] = 975;
    Taxesp26[5] = 1150;
    Couleur jaune (255,228,54, "jaune");
    Propriete p26 ("Saint-Honoré",260,150,130,Taxesp26,0,0,jaune,false,3);//[22,110,330,800,975,1150]
    p.TabCases[26].setNumeroCase(26);
    p.TabCases[26].setParcGratuit(false);
    p.TabCases[26].setAllerEnPrison(false);
    p.TabCases[26].setVisitePrison(false);
    p.TabCases[26].setpropriete(&p26);
    p.TabCases[26].setChance(false);
    p.TabCases[26].setCaisseCommunaute(false);
    p.TabCases[26].setCaseDepart(false);

    int Taxesp27[6];
    Taxesp27[0] = 22;
    Taxesp27[1] = 110;
    Taxesp27[2] = 330;
    Taxesp27[3] = 800;
    Taxesp27[4] = 975;
    Taxesp27[5] = 1150;
    Propriete p27 ("Bourse",260,150,130,Taxesp27,0,0,jaune,false,3);//[22,110,330,800,975,1150]
    p.TabCases[27].setNumeroCase(27);
    p.TabCases[27].setParcGratuit(false);
    p.TabCases[27].setAllerEnPrison(false);
    p.TabCases[27].setVisitePrison(false);
    p.TabCases[27].setpropriete(&p27);
    p.TabCases[27].setChance(false);
    p.TabCases[27].setCaisseCommunaute(false);
    p.TabCases[27].setCaseDepart(false);

    Propriete p28 ("GDF",150,0,75,Taxescompagnie,0,0,compagnie,false,2);//[0,0,0,0,0,0]
    p.TabCases[28].setNumeroCase(28);
    p.TabCases[28].setParcGratuit(false);
    p.TabCases[28].setAllerEnPrison(false);
    p.TabCases[28].setVisitePrison(false);
    p.TabCases[28].setpropriete(&p28);
    p.TabCases[28].setChance(false);
    p.TabCases[28].setCaisseCommunaute(false);
    p.TabCases[28].setCaseDepart(false);

    int Taxesp29[6];
    Taxesp29[0] = 24;
    Taxesp29[1] = 120;
    Taxesp29[2] = 360;
    Taxesp29[3] = 850;
    Taxesp29[4] = 1025;
    Taxesp29[5] = 1200;
    Propriete p29 ("Lafayette",280,150,140,Taxesp29,0,0,jaune,false,3);//[24,120,360,850,1025,1200]
    p.TabCases[29].setNumeroCase(29);
    p.TabCases[29].setParcGratuit(false);
    p.TabCases[29].setAllerEnPrison(false);
    p.TabCases[29].setVisitePrison(false);
    p.TabCases[29].setpropriete(&p29);
    p.TabCases[29].setChance(false);
    p.TabCases[29].setCaisseCommunaute(false);
    p.TabCases[29].setCaseDepart(false);

    Propriete p30 ("EnPrison",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[30].setNumeroCase(30);
    p.TabCases[30].setParcGratuit(false);
    p.TabCases[30].setAllerEnPrison(true);
    p.TabCases[30].setVisitePrison(false);
    p.TabCases[30].setpropriete(&p30);
    p.TabCases[30].setChance(false);
    p.TabCases[30].setCaisseCommunaute(false);
    p.TabCases[30].setCaseDepart(false);

    int Taxesp31[6];
    Taxesp31[0] = 26;
    Taxesp31[1] = 130;
    Taxesp31[2] = 390;
    Taxesp31[3] = 900;
    Taxesp31[4] = 1100;
    Taxesp31[5] = 1275;
    Couleur vert (0,255,0,"vert");
    Propriete p31 ("Breteuil",300,200,150,Taxesp31,0,0,vert,false,3);//[26,130,390,900,1100,1275]
    p.TabCases[31].setNumeroCase(31);
    p.TabCases[31].setParcGratuit(false);
    p.TabCases[31].setAllerEnPrison(false);
    p.TabCases[31].setVisitePrison (false);
    p.TabCases[31].setpropriete(&p31);
    p.TabCases[31].setChance(false);
    p.TabCases[31].setCaisseCommunaute(false);
    p.TabCases[31].setCaseDepart(false);

    int Taxesp32[6];
    Taxesp32[0] = 26;
    Taxesp32[1] = 130;
    Taxesp32[2] = 390;
    Taxesp32[3] = 900;
    Taxesp32[4] = 1100;
    Taxesp32[5] = 1275;
    Propriete p32 ("Foch",300,200,150,Taxesp32,0,0,vert,false,3);//[26,130,390,900,1100,1275]
    p.TabCases[32].setNumeroCase(32);
    p.TabCases[32].setParcGratuit(false);
    p.TabCases[32].setAllerEnPrison(false);
    p.TabCases[32].setVisitePrison(false);
    p.TabCases[32].setpropriete(&p32);
    p.TabCases[32].setChance(false);
    p.TabCases[32].setCaisseCommunaute(false);
    p.TabCases[32].setCaseDepart (false);

    Propriete p33 ("CaisseCommu",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[33].setNumeroCase (33);
    p.TabCases[33].setParcGratuit(false);
    p.TabCases[33].setAllerEnPrison(false);
    p.TabCases[33].setVisitePrison(false);
    p.TabCases[33].setpropriete(&p33);
    p.TabCases[33].setChance(false);
    p.TabCases[33].setCaisseCommunaute(true);
    p.TabCases[33].setCaseDepart(false);

    int Taxesp34[6];
    Taxesp34[0] = 28;
    Taxesp34[1] = 150;
    Taxesp34[2] = 450;
    Taxesp34[3] = 1000;
    Taxesp34[4] = 1200;
    Taxesp34[5] = 1400;
    Propriete p34 ("Capucines",320,200,160,Taxesp34,0,0,vert,false,3);//[28,150,450,1000,1200,1400]
    p.TabCases[34].setNumeroCase(34);
    p.TabCases[34].setParcGratuit(false);
    p.TabCases[34].setAllerEnPrison(false);
    p.TabCases[34].setVisitePrison(false);
    p.TabCases[34].setpropriete(&p34);
    p.TabCases[34].setChance(false);
    p.TabCases[34].setCaisseCommunaute(false);
    p.TabCases[34].setCaseDepart(false);

    Propriete p35 ("Saint-Lazarre",200,0,100,Taxesgare,0,0,gare,false,4);//[25,50,100,200,0,0]
    p.TabCases[35].setNumeroCase(35);
    p.TabCases[35].setParcGratuit(false);
    p.TabCases[35].setAllerEnPrison(false);
    p.TabCases[35].setVisitePrison(false);
    p.TabCases[35].setpropriete(&p35);
    p.TabCases[35].setChance(false);
    p.TabCases[35].setCaisseCommunaute(false);
    p.TabCases[35].setCaseDepart(false);

    Propriete p36 ("Chance",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[36].setNumeroCase(36);
    p.TabCases[36].setParcGratuit(false);
    p.TabCases[36].setAllerEnPrison(false);
    p.TabCases[36].setVisitePrison(false);
    p.TabCases[36].setpropriete(&p36);
    p.TabCases[36].setChance(true);
    p.TabCases[36].setCaisseCommunaute(false);
    p.TabCases[36].setCaseDepart(false);

    int Taxesp37[6];
    Taxesp37[0] = 35;
    Taxesp37[1] = 175;
    Taxesp37[2] = 500;
    Taxesp37[3] = 1100;
    Taxesp37[4] = 1300;
    Taxesp37[5] = 1500;
    Couleur bleu (0,0,255,"bleu");
    Propriete p37 ("Champs-Elysees",350,200,175,Taxesp37,0,0,bleu,false,2);//[35,175,500,1100,1300,1500]
    p.TabCases[37].setNumeroCase(37);
    p.TabCases[37].setParcGratuit(false);
    p.TabCases[37].setAllerEnPrison(false);
    p.TabCases[37].setVisitePrison(false);
    p.TabCases[37].setpropriete(&p37);
    p.TabCases[37].setChance(false);
    p.TabCases[37].setCaisseCommunaute(false);
    p.TabCases[37].setCaseDepart(false);

    //Pareil que l'impot sur le revenu, mais il s'agit de la taxe de luxe.
    Propriete p38 ("TaxeLuxe",0,0,0,Taxesp0,0,0,marron,false,0);
    p.TabCases[38].setNumeroCase(38);
    p.TabCases[38].setParcGratuit(false);
    p.TabCases[38].setAllerEnPrison(false);
    p.TabCases[38].setVisitePrison(false);
    p.TabCases[38].setpropriete(&p38);
    p.TabCases[38].setChance(false);
    p.TabCases[38].setCaisseCommunaute(false);
    p.TabCases[38].setCaseDepart(false);

    int Taxesp39[6];
    Taxesp39[0] = 50;
    Taxesp39[1] = 200;
    Taxesp39[2] = 600;
    Taxesp39[3] = 1400;
    Taxesp39[4] = 1700;
    Taxesp39[5] = 2000;
    Propriete p39 ("Paix",400,200,200,Taxesp1,0,0,bleu,false,2);//[50,200,600,1400,1700,2000]
    p.TabCases[39].setNumeroCase(39);
    p.TabCases[39].setParcGratuit(false);
    p.TabCases[39].setAllerEnPrison(false);
    p.TabCases[39].setVisitePrison(false);
    p.TabCases[39].setpropriete(&p39);
    p.TabCases[39].setChance(false);
    p.TabCases[39].setCaisseCommunaute(false);
    p.TabCases[39].setCaseDepart(false);

    TabJoueur = new Joueur[4];

    //construit les cartes caissecommu
    Carte c0 (0,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",false,2);
    Carte c1 (1,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",false,4);
    Carte c2 (2,"Vous etes libere de prison, carte a conserver",false,1);
    Carte c3 (3,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",false,5);
    Carte c4 (4,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",false,3);
    Carte c5 (5,"C'est votre anniversaire cette annee, tous les joueurs vous donnent de l'argent",false,6);
    Carte c6 (6,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",false,4);
    Carte c7 (7,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",false,2);
    Carte c8 (8,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",false,5);
    Carte c9 (9,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",false,3);
    Carte c10 (10,"Vous etes libere de prison, carte a conserver",false,1);
    Carte c11 (11,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",false,2);
    Carte c12 (12,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",false,5);
    Carte c13 (13,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",false,3);
    Carte c14 (14,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",false,4);
    Carte c15 (15,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",false,3);

    Carte * ptrc0 = &c0;
    Carte * ptrc1 = &c1;
    Carte * ptrc2 = &c2;
    Carte * ptrc3 = &c3;
    Carte * ptrc4 = &c4;
    Carte * ptrc5 = &c5;
    Carte * ptrc6 = &c6;
    Carte * ptrc7 = &c7;
    Carte * ptrc8 = &c8;
    Carte * ptrc9 = &c9;
    Carte * ptrc10 = &c10;
    Carte * ptrc11 = &c11;
    Carte * ptrc12 = &c12;
    Carte * ptrc13 = &c13;
    Carte * ptrc14 = &c14;
    Carte * ptrc15 = &c15;

    commu.ajouterEnTete(ptrc0);
    commu.ajouterEnTete(ptrc1);
    commu.ajouterEnTete(ptrc2);
    commu.ajouterEnTete(ptrc3);
    commu.ajouterEnTete(ptrc4);
    commu.ajouterEnTete(ptrc5);
    commu.ajouterEnTete(ptrc6);
    commu.ajouterEnTete(ptrc7);
    commu.ajouterEnTete(ptrc8);
    commu.ajouterEnTete(ptrc9);
    commu.ajouterEnTete(ptrc10);
    commu.ajouterEnTete(ptrc11);
    commu.ajouterEnTete(ptrc12);
    commu.ajouterEnTete(ptrc13);
    commu.ajouterEnTete(ptrc14);
    commu.ajouterEnTete(ptrc15);

    //construit les cartes chance
    Carte c16 (16,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",true,2);
    Carte c17 (17,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",true,4);
    Carte c18 (18,"Vous etes libere de prison, carte a conserver",true,1);
    Carte c19 (19,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",true,5);
    Carte c20 (20,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",true,3);
    Carte c21 (21,"C'est votre anniversaire cette annee, tous les joueurs vous donnent de l'argent",true,6);
    Carte c22 (22,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",true,4);
    Carte c23 (23,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",true,2);
    Carte c24 (24,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",true,5);
    Carte c25 (25,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",true,3);
    Carte c26 (26,"Vous etes libere de prison, carte a conserver",true,1);
    Carte c27 (27,"Vous vous etes leve de bon pied et votre generosite n'a aucune limite. Payez les autres joueurs.",true,2);
    Carte c28 (28,"Vous perdez le cheque qui se tenait dans votre poche et un inconnu le ramasse. Perdez de l'argent",true,5);
    Carte c29 (29,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",true,3);
    Carte c30 (30,"Vous avez trouve un  cheque par terre et ne le rendez pas. Recevez de l'argent",true,4);
    Carte c31 (31,"Une faille spatio-temporelle s'ouvre sous vos pieds, alors que vous traversez la rue. Deplacez-vous",true,3);

    Carte * ptrc16 = &c16;
    Carte * ptrc17 = &c17;
    Carte * ptrc18 = &c18;
    Carte * ptrc19 = &c19;
    Carte * ptrc20 = &c20;
    Carte * ptrc21 = &c21;
    Carte * ptrc22 = &c22;
    Carte * ptrc23 = &c23;
    Carte * ptrc24 = &c24;
    Carte * ptrc25 = &c25;
    Carte * ptrc26 = &c26;
    Carte * ptrc27 = &c27;
    Carte * ptrc28 = &c28;
    Carte * ptrc29 = &c29;
    Carte * ptrc30 = &c30;
    Carte * ptrc31 = &c31;

    chance.ajouterEnTete(ptrc16);
    chance.ajouterEnTete(ptrc17);
    chance.ajouterEnTete(ptrc18);
    chance.ajouterEnTete(ptrc19);
    chance.ajouterEnTete(ptrc20);
    chance.ajouterEnTete(ptrc21);
    chance.ajouterEnTete(ptrc22);
    chance.ajouterEnTete(ptrc23);
    chance.ajouterEnTete(ptrc24);
    chance.ajouterEnTete(ptrc25);
    chance.ajouterEnTete(ptrc26);
    chance.ajouterEnTete(ptrc27);
    chance.ajouterEnTete(ptrc28);
    chance.ajouterEnTete(ptrc29);
    chance.ajouterEnTete(ptrc30);
    chance.ajouterEnTete(ptrc31);

    int TourJoueur = 1;
    string pseudo;
    do
    {
    cout<<"Combien de joueurs ?"<<endl;
    cin>>NbJoueurs;
    }while ((NbJoueurs>4) || (NbJoueurs<=1));
    for(int i=1;i<NbJoueurs+1;i++)
    {
        cout<<"joueur "<<i<<", entrez votre pseudo "<<endl;
        cin>>pseudo;
        TabJoueur[i-1]= Joueur(pseudo,i,rouge,vert,bleu,jaune);
    }
    while (NbJoueurs!=1)
    {
        if(TourJoueur > NbJoueurs){TourJoueur = 1;}
        Joueur * j = &TabJoueur[TourJoueur-1];
        if (j->getEncoreEnJeu()==true)
        {
            Tour(p,chance,commu,des,j);
        }
        TourJoueur +=1;
    }
    for (int i =0;i<5;i++)
    {
        if(TabJoueur[i].getEncoreEnJeu() == true)
        {
            cout<<TabJoueur[i].getNomJoueur()<<" gagne la partie !"<<endl;
            break;
        }
    }
}
/**
*   @brief le destructeur de la classe Jeu
*   @param pas d'argument
*   @return pas de valeur retournee
*/
Jeu::~Jeu(){
    cout<<"partie terminee"<<endl;
}
/**
*   @brief Renvoie un joueur a partir de son numero
*   @param num: entier
*   @return retourne un booleen
*/
Joueur Jeu::GetJoueur(int num)const{
    return TabJoueur[num];
}
/**
*   @brief Renvoie le nombre de joueurs restants (non elimines)
*   @param pas d'argument
*   @return retourne un entier
*/
int Jeu::NbJoueursRestants(){
    int s = 0;
    for(int i= 0;i<4;i++)
    {
        if(TabJoueur[i].getEncoreEnJeu() == true)
        {
            s +=1;
        }
    }
    return s;
}
/**
*   @brief Obtenir le nombre de joueurs
*   @param pas d'argument
*   @return retourne un entier
*/
int Jeu::getNbJoueurs()const{
    return NbJoueurs;
}
/**
*   @brief Gere les tours entre tous les joueurs, propose les actions possibles et prend en compte leurs reponses
*   @param p: Plateau, chance: PaquetChance, commu: PaquetCaisseComm, des: De, joueur: Joueur
*   @return pas de valeur retournee
*/
void Jeu::Tour(const Plateau & p,PaquetChance & chance,PaquetCaisseComm & commu,De des,Joueur * joueur){
    cout<<"____________________________\n";
    char option;
    bool valide;
    bool encore = true;
    unsigned int proposition;
    int propNegocier;


    cout<<"Joueur "<<joueur->getNumeroJoueur()<<":"<<joueur->getNomJoueur()<<" : "<<"  votre capital : ";
    cout<<joueur->getCagnotteJoueur()<<"  Votre position : "<<joueur->getPositionJoueur();
    cout<<"  Cartes prison : "<<joueur->getNbCarteLibrePrison()<<endl;

    if (joueur->getEnPrison()){//Prison(PaquetCaisseComm & commu,PaquetChance & chance,De PaireDe,Joueur Prisonnier)
        Prison(commu,chance,des,joueur);
    }
    if (joueur->getCagnotteJoueur()<= 0)
    {
        //Faillite(joueur);
        int id_propriete;
        int NbMaisons;
        char choix;
        bool again;
        again = true;
        while (again == true)
        {
        cout<<"Votre capital :"<<joueur->getCagnotteJoueur()<<"Vous etes ruine, vous devez hypothéquer ou vendre des maisons "<<endl;
        cout<<"Hypothéquer (h), Vendre des maisons (m) ou Fin (f)?"<<endl;
        cin>>choix;
        switch (choix)
        {
        case 'h':
            cout<<"quelle propriete ?\n";
            for(int i=0;i<40;i++)
                {
                    if (p.getTabCases(i).getPropriete()->getProprietaire()== joueur->getNumeroJoueur() && p.getTabCases(i).getPropriete()->getHypotheque()== false)
                    {
                        cout<<i<<" - "<<p.getTabCases(i).getPropriete()->getNom()<<" - "<<p.getTabCases(i).getPropriete()->getCouleur().getNomCouleur()<<endl;
                    }
                }
                cin>>id_propriete;
                p.getTabCases(id_propriete).getPropriete()->Hypothequer(joueur);
            break;

        case 'm':
            cout<<"quelle propriete ?\n";
            for(int i=1;i<40;i++)
                {
                    if (p.getTabCases(i).getPropriete()->getProprietaire()== joueur->getNumeroJoueur() && p.getTabCases(i).getPropriete()->getHypotheque()== false)
                    {
                        cout<<i<<" - "<<p.getTabCases(i).getPropriete()->getNom()<<" - "<<p.getTabCases(i).getPropriete()->getCouleur().getNomCouleur()<<" maisons : "<<p.getTabCases(i).getPropriete()->getNbMaisons()<<endl;
                    }
                }
                cin>>id_propriete;
                p.getTabCases(proposition).getPropriete()->VendreMaison(1,joueur);
            break;

        default:
            again = false;
            break;
        }
        }
        if (joueur->getCagnotteJoueur()<= 0)
        {
            joueur->setEncoreEnJeu(false);
            NbJoueurs -= 1;
            cout<<"RIP in peace "<<joueur->getNomJoueur()<<endl;
        }
    }
    else if(joueur->getEnPrison()==false)
    {
        joueur->Avancer(des);

        cout<<"Joueur "<<joueur->getNumeroJoueur()<<":"<<joueur->getNomJoueur()<<" : "<<"  votre capital : ";
        cout<<joueur->getCagnotteJoueur()<<"  Votre position : "<<joueur->getPositionJoueur();
        cout<<"  Cartes prison : "<<joueur->getNbCarteLibrePrison()<<endl;
        if(p.getTabCases(joueur->getPositionJoueur()).getPropriete()->getProprietaire()==0)
        {
        p.getTabCases(joueur->getPositionJoueur()).EffetCase(joueur,commu,chance,this,TabJoueur[0]); //EffetCase(Joueur *j, PaquetCaisseComm & communaute, PaquetChance & chance, Jeu * jeu)
        }
        else
        {
        p.getTabCases(joueur->getPositionJoueur()).EffetCase(joueur,commu,chance,this,TabJoueur[p.getTabCases(joueur->getPositionJoueur()).getPropriete()->getProprietaire()-1]); //EffetCase(Joueur *j, PaquetCaisseComm & communaute, PaquetChance & chance, Jeu * jeu)
        }
    }
    do
    {
    cout<<"Achat maisons (M), Fin Du Tour (T)"<<endl;
    cin>>option;
    switch (option)
    {
        case'm':
            valide =false;
            while (valide == false)
            {
                cout<<"Entrez le numero de la propriete qui corespond :"<<endl;
                //cout<<i<<" - "<<joueur->getListeProprietesJoueur().valeurIemeElement(i).getNom()<< " - "<<joueur->getListeProprietesJoueur().valeurIemeElement(i).getCouleur().getNomCouleur()<<endl;
                for(int i=1;i<40;i++)
                {
                    if (p.getTabCases(i).getPropriete()->getProprietaire()== joueur->getNumeroJoueur())
                    {
                        cout<<i<<" - "<<p.getTabCases(i).getPropriete()->getNom()<<" - "<<p.getTabCases(i).getPropriete()->getCouleur().getNomCouleur()<<endl;
                    }
                }
            cin>>proposition;
            if (p.getTabCases(proposition).getPropriete()->getProprietaire()== joueur->getNumeroJoueur())
            {
                if (p.getTabCases(proposition).getPropriete()->getTaxesPropriete(0)== 25 || p.getTabCases(proposition).getPropriete()->getTaxesPropriete(0)== 1 )
                {
                    cout<<"vous ne pouvez acheter de maison sur une gare ou une compagnie"<<endl;
                }
                else
                {
                    p.getTabCases(proposition).getPropriete()->AjouterMaison(joueur);
                }
                valide = true;
            }
            else
            {
                cout<<"Cette propriete ne vous appartient pas! \n";
            }
            }


            break;
        case'n':
            int a,b;
            a = 0;
            b = 0;
            Propriete * c;
            Propriete * d;
            valide = false;
            while (valide == false)
            {
                cout<<"Entrez le numero de joueur avec lequel vous souhaitez negocier."<<endl;
                for (int i = 0;i<NbJoueurs;i++)
                {
                    if(TabJoueur[i].getNomJoueur()!= joueur->getNomJoueur()) {cout<<i<<" - "<<TabJoueur[i].getNomJoueur()<<endl;}
                }
                cin>>propNegocier;
                if(propNegocier < NbJoueurs)
                {
                    valide = true;
                }
            }
            cout<<joueur->getNomJoueur()<<", vous souhaitez offrir terrain nu(T) ou argent (A) ?"<<endl;
            cin>>option;
            switch(option)
            {
            case 't':
                {
                Propriete n1;
                cout<<"Entrez le numero de la propriete qui correspond :"<<endl;
                for (unsigned int i = 0; i< joueur->getListeProprietesJoueur().gettaille_utilisee();i++)
                {
                    cout<<i<<" - "<<joueur->getListeProprietesJoueur().valeurIemeElement(i).getNom()<< " - "<<joueur->getListeProprietesJoueur().valeurIemeElement(i).getCouleur().getNomCouleur()<<endl;
                }
                cin>>proposition;
                if (proposition < joueur->getListeProprietesJoueur().gettaille_utilisee())
                {
                    if (joueur->getListeProprietesJoueur().valeurIemeElement(proposition).getNbMaisons()==0)
                    {
                        n1 = joueur->getListeProprietesJoueur().valeurIemeElement(proposition);
                    }
                    c = &n1;
                }
                break;
                }
            case 'a':
                {
                int n1;
                do
                {

                cout<<"Entrez une somme"<<endl;
                cin>>n1;
                }while (n1>= joueur->getCagnotteJoueur());
                a = n1;
                break;}}
            cout<<"en echange d'argent (A) ou d'un terrain nu (T) ?"<<endl;
            cin>>proposition;
            switch(option)
            {
            case 't':{
                Propriete n2;
                cout<<"Entrez le numero de la propriete qui correspond :"<<endl;
                for (unsigned int i = 0; i< TabJoueur[propNegocier].getListeProprietesJoueur().gettaille_utilisee();i++)
                {
                    cout<<i<<" - "<<TabJoueur[propNegocier].getListeProprietesJoueur().valeurIemeElement(i).getNom()<< " - "<<TabJoueur[propNegocier].getListeProprietesJoueur().valeurIemeElement(i).getCouleur().getNomCouleur()<<endl;
                }
                cin>>proposition;
                if (proposition < TabJoueur[propNegocier].getListeProprietesJoueur().gettaille_utilisee())
                {
                    if (TabJoueur[propNegocier].getListeProprietesJoueur().valeurIemeElement(proposition).getNbMaisons()==0)
                    {
                        n2 = TabJoueur[propNegocier].getListeProprietesJoueur().valeurIemeElement(proposition);
                    }
                }
                d = &n2;
                break;}
            case 'a':
                {
                int n2;
                do
                {

                cout<<"Entrez une somme"<<endl;
                cin>>n2;
                }while (n2>= TabJoueur[propNegocier].getCagnotteJoueur());
                b = n2;
                break;}
            cout<<"Le joueur accepte-t-il ? (Y/N) "<<endl;
            cin>>option;
            switch(option)
            {
            case 'y':
                {
                if (a!= 0)
                {
                    joueur->Payer(a,TabJoueur[propNegocier]);
                }
                else
                {
                    c->ChangeProprietaire(TabJoueur[propNegocier].getNumeroJoueur());
                    TabJoueur[propNegocier].getListeProprietesJoueur().ajouterElement(c);
                    joueur->getListeProprietesJoueur().supprimer(c);

                }
                if (b != 0)
                {
                    TabJoueur[propNegocier].Payer(b, *joueur);
                }
                else
                {

                    d->ChangeProprietaire(joueur->getNumeroJoueur());
                    joueur->getListeProprietesJoueur().ajouterElement(d);
                    TabJoueur[propNegocier].getListeProprietesJoueur().supprimer(d);

                }
                break;}
            case'n':
                break;}


        break;}
        case't':{
        encore = false;
        break;}
    default:
        cout<<"Mauvaise commande"<<endl;}
    }while (encore == true);
}
/**
*   @brief La procedure qui gere les actions d'un joueur actuellement en prison.
*   @param commu: PaquetCaisseComm, chance: PaquetChance, PaireDe: De, Prisonnier: Joueur
*   @return pas de valeur retournee
*/
void Jeu::Prison(PaquetCaisseComm & commu,PaquetChance & chance,De PaireDe,Joueur * Prisonnier){
    Carte c(0,"Vous etes libere de prison, carte a conserver",true,1);
    Carte * ptrc = &c;
    cout<<"tentative pour sortir de prison\n";
    PaireDe.LancerDe();
	if (PaireDe.GetValeurDe1()==PaireDe.GetValeurDe2())
	{
		Prisonnier->setEnPrison(false);
		Prisonnier->setTourPrison(0);
		Prisonnier->Avancer(PaireDe);
		cout<<"Libere par un double"<<endl;
	}
	else if (Prisonnier->getNbCarteLibrePrison() > 0)
	{
		cout<<"utilise 1 carte"<<endl;
		Prisonnier->setEnPrison(false);
		Prisonnier->setTourPrison(0);
		Prisonnier->Avancer(PaireDe);
		Prisonnier->setNbCarteLibrePrison(Prisonnier->getNbCarteLibrePrison()-1);
		if (chance.nbElements()!= 32)
        {
            chance.ajouterEnQueue(ptrc);
        }
        else
        {
            commu.ajouterEnQueue(ptrc);
        }

	}
	else if (Prisonnier->getTourPrison()==3)
    {
		cout<<"Peine terminée"<<endl;
		Prisonnier->DiminuerArgent(50);
		Prisonnier->setEnPrison(false);
		Prisonnier->Avancer(PaireDe);
		Prisonnier->setTourPrison(0);
	}
	else
	{
	    cout<<"reste en prison"<<endl;
	    Prisonnier->setTourPrison(Prisonnier->getTourPrison()+1);
    }
}










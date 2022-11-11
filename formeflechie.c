//
// Created by antoi on 25/10/2022.
//

#include "formeflechie.h"

motFlechi initmotf(char* mot, char* personne, char* nombre, char* temps){
    motFlechi nouvmot;
    nouvmot.mot = malloc(30*sizeof(char));
    nouvmot.personne = malloc(30*sizeof(char));
    nouvmot.nombre = malloc(30*sizeof(char));
    nouvmot.temps = malloc(30*sizeof(char));
    nouvmot.mot = mot;
    nouvmot.personne = personne;
    nouvmot.nombre = nombre;
    nouvmot.temps = temps;
}

void addmf(listeFlechi* liste, motFlechi mot){
    if (liste == NULL){
        liste->tab = malloc(30*sizeof(motFlechi));
        liste->nbmots=0;
    }
    liste->tab[liste->nbmots] = mot;
    ++(liste->nbmots);
}
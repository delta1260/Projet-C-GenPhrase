//
// Created by antoi on 25/10/2022.
//

#include "formeflechie.h"

motFlechi initmf(char* mot, char* personne, char* nombre, char* tempsgenre){
    motFlechi nouvmot;
    nouvmot.mot = malloc(30*sizeof(char));
    nouvmot.personne = malloc(10*sizeof(char));
    nouvmot.nombre = malloc(10*sizeof(char));
    nouvmot.tempsgenre = malloc(10*sizeof(char));
    nouvmot.mot = mot;
    nouvmot.personne = personne;
    nouvmot.nombre = nombre;
    nouvmot.tempsgenre = tempsgenre;
    return nouvmot;
}

void addmf(listeFlechi* liste, motFlechi mot){
    liste->tab[liste->nbmots] = mot;
    ++(liste->nbmots);
}
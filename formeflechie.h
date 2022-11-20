//
// Created by antoi on 25/10/2022.
//

#ifndef MAIN_C_FORMEFLECHIE_H
#define MAIN_C_FORMEFLECHIE_H

#include <stdio.h>
#include <malloc.h>

typedef struct{
    char* mot;
    char* personne;
    char* nombre;
    char* tempsgenre;
} motFlechi;

typedef struct{
    char* base;
    int nbmots;
    motFlechi tab[50];
} listeFlechi;

void addmf(listeFlechi* liste, motFlechi mot);
motFlechi initmf(char* mot, char* personne, char* nombre, char* temps);

#endif //MAIN_C_FORMEFLECHIE_H

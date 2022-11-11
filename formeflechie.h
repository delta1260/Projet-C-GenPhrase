//
// Created by antoi on 25/10/2022.
//

#ifndef MAIN_C_FORMEFLECHIE_H
#define MAIN_C_FORMEFLECHIE_H

typedef struct{
    char* mot;
    char* personne;
    char* nombre;
    char* temps;

} motFlechi;

typedef struct{
    int nbmots;
    motFlechi* tab;
} listeFlechi;

#endif //MAIN_C_FORMEFLECHIE_H

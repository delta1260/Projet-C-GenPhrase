//
// Created by antoi on 25/10/2022.
//

#ifndef MAIN_C_TREE_H
#define MAIN_C_TREE_H
#include "formeflechie.h"

struct s_letter{
    char letter;
    listeFlechi* liste;
    int nbNext;
    struct s_letter* next;
};

typedef struct s_letter t_letter;

typedef struct {
    t_letter* root;
}tree;

typedef struct {
    t_letter* adj;
    t_letter* nom;
    t_letter* adverbe;
    t_letter* verbe;
} allTree;

#endif //MAIN_C_TREE_H

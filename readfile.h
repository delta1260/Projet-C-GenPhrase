//
// Created by antoi on 17/10/2022.
//

#ifndef UNTITLED4_READFILE_H

#include <stdio.h>
#include "tree.h"
#include "formeflechie.h"
#define NBMAX 30

typedef struct {
    char* flechie;
    char* base;
    char* type;
} line;

char* readfile(char* name);
void splittext(char* text, allTree arbre);


listeFlechi findWord(t_node myLetter);
t_node randomNumber(t_node myLetter);
#define UNTITLED4_READFILE_H

#endif //UNTITLED4_READFILE_H

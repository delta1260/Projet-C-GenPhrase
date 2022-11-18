//
// Created by antoi on 17/10/2022.
//

#ifndef UNTITLED4_READFILE_H

#include <stdio.h>
#include "tree.h"
#include "formeflechie.h"
#define NBMAX 30

typedef struct {
    char* base;
    char* type;
    motFlechi mf;
} line;

char* readfile(char* name);
void splittext(char* text, allTree* arbre);

int randomWords(p_node myLetter, listeFlechi* lst, int i);
p_node randomLetter(p_node myLetter);
motFlechi rWord(listeFlechi* lst, int i);
#define UNTITLED4_READFILE_H

#endif //UNTITLED4_READFILE_H

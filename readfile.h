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
void splittext(char* text);


typedef struct {
    int values[NBMAX];
    int nbElts;
    listeFlechi* liste;
} rWord;

rWord CreateEmptyWord();
void findWord(t_letter myLetter);
t_letter randomNumber(t_letter myLetter);
#define UNTITLED4_READFILE_H

#endif //UNTITLED4_READFILE_H

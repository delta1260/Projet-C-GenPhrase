//
// Created by antoi on 17/10/2022.
//

#ifndef UNTITLED4_READFILE_H

#include <stdio.h>

typedef struct {
    char* flechie;
    char* base;
    char* type;
} line;

char* readfile(char* name);
void splittext(char* text);

#define UNTITLED4_READFILE_H

#endif //UNTITLED4_READFILE_H

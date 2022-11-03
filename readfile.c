//
// Created by antoi on 17/10/2022.
//

#include "readfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readfile(char *name) {
    FILE *file;
    file = fopen(name, "r");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        int filesize = ftell(file);
        if (filesize == 0) {
            return "";
        }
        rewind(file);
        char *buf;
        buf = calloc(filesize, sizeof(char));
        fread(buf, sizeof(char), filesize, file);
        return buf;
    }
    return "";
}

void splittext(char* text, arbre* tree){
    int i;
    line tmpline;
    char *token;
    while (token != NULL) {
        token = strtok(text, "\t");
        tmpline.flechie = token;
        token = strtok(NULL, "\t");
        tmpline.base = token;
        token = strtok(NULL, "\n");
        tmpline.type = token;
    }
    //void addtostruct(tmpline)
}
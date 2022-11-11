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

void splittext(char* text){
    int i;
    line tmpline;
    char *token = "";
    tmpline.flechie = malloc(30*sizeof(char));
    tmpline.base = malloc(30*sizeof(char));
    tmpline.type = malloc(30*sizeof(char));
    while (token != NULL) {
        token = strtok(text, "\t");
        tmpline.flechie = token;
        strcat(tmpline.flechie, "\0");
        token = strtok(NULL, "\t");
        tmpline.base = token;
        strcat(tmpline.base, "\0");
        token = strtok(NULL, "\n");
        tmpline.type = token;
        strcat(tmpline.type, "\0");
    }

}

rWord CreateEmptyWord(){
    rWord myWord;
    myWord.nbElts=0;
    return myWord;
}


t_letter randomNumber(t_letter myLetter){
    int nbr=0;
    nbr = (rand() % myLetter.nbNext);
    return myLetter.next[nbr];
}

void findWord(t_letter myLetter){
    if(myLetter.next!=NULL)
}
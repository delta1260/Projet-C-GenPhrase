//
// Created by antoi on 17/10/2022.
//

#include "readfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void splittext(char* text,allTree* arbre){
    int flag;
    line tmpline;
    char *token;
    listeFlechi* lst;
    tmpline.base = malloc(30*sizeof(char));
    tmpline.type = malloc(30*sizeof(char));
    tmpline.mf = initmf("","","","");
    token = strtok(text, "\t");
    while (token != NULL) {
        strcat(token, "\0");
        tmpline.mf.mot = token;
        token = strtok(NULL, "\t");
        strcat(token, "\0");
        tmpline.base = token;
        token = strtok(NULL, ":\n");
        strcat(token, "\0");
        tmpline.type = token;
        //printf("mot:%s type:%s\n",tmpline.mf.mot, tmpline.type);
        switch (tmpline.type[2]) {
            case('r'):
                if (tmpline.type[1] == 'b')
                    break;
                flag = 1;
                while (flag) {
                    token = strtok(NULL, "+\n");
                    strcat(token, "\0");
                    tmpline.mf.tempsgenre = token;
                    if (tmpline.mf.tempsgenre[0] == 'I' && tmpline.mf.tempsgenre[1] == 'n') {
                        lst = addWord(arbre->verbe, tmpline.base);
                        addmf(lst, tmpline.mf);
                        break;
                    }
                    else if (tmpline.mf.tempsgenre[0] == 'P' && tmpline.mf.tempsgenre[1] == 'P') {
                        token = strtok(NULL, "\n");
                        break;
                    }
                    token = strtok(NULL, "+");
                    strcat(token, "\0");
                    tmpline.mf.nombre = token;
                    token = strtok(NULL, ":\n");
                    if (!isupper(token[4]) && !isupper(token[3])) {
                        flag = 0;
                    }
                    strcat(token, "\0");
                    tmpline.mf.personne = token;
                    //printf("->conjug: %s %s %s\n", tmpline.mf.tempsgenre, tmpline.mf.nombre, tmpline.mf.personne);
                    if ((token[0] == 'I' && token[1] == 'I') || (token[0] == 'I' && token[1] == 'P') ||
                        (token[0] == 'S' && token[1] == 'P')) {
                        lst = addWord(arbre->verbe, tmpline.base);
                        addmf(lst, tmpline.mf);
                    }
                }
                break;
            case('m'):
                token = strtok(NULL, "+");
                strcat(token, "\0");
                tmpline.mf.tempsgenre = token;
                token = strtok(NULL, "\n");
                strcat(token, "\0");
                tmpline.mf.nombre = token;
                lst = addWord(arbre->nom, tmpline.base);
                addmf(lst, tmpline.mf);
                break;
            case('v'):
                lst = addWord(arbre->adverbe, tmpline.base);
                addmf(lst, tmpline.mf);
                break;
            case('j'):
                token = strtok(NULL, "+");
                strcat(token, "\0");
                tmpline.mf.tempsgenre = token;
                token = strtok(NULL, "\n");
                strcat(token, "\0");
                tmpline.mf.nombre = token;
                lst = addWord(arbre->adj, tmpline.base);
                addmf(lst, tmpline.mf);
                break;
            default:
                token = strtok(NULL, "\n");
                break;

        }

        tmpline.mf.nombre = "";
        tmpline.mf.tempsgenre = "";
        tmpline.mf.personne = "";

        token = strtok(NULL, "\t");
    }

}


p_node randomLetter(p_node myLetter){
    int nbr;
    nbr = (rand() % myLetter->nbNext);
    return (myLetter->next[nbr]);
}

int randomWords(p_node node, listeFlechi* lst, int i){
    if (node->nbNext != 0){
        if (node->liste != NULL) {
            lst[i] = *node->liste;
            return randomWords(randomLetter(node), lst, i + 1);
        }
        return randomWords(randomLetter(node), lst, i);
    }
    lst[i] = *node->liste;
    return i;
}
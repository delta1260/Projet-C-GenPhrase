//
// Created by antoi on 17/10/2022.
//

#include "readfile.h"
#include <stdio.h>
#include <stdlib.h>

char* readfile() {
    FILE *file;
    file = fopen("dictionnaire.txt", "r");
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

#include "readfile.h"

int main() {
    char* text = readfile("dictionnaire.txt");
    splittext(text);
}


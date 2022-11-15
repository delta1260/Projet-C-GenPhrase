
#include "readfile.h"


int main() {
    allTree TREE = initTree();
    char* text = readfile("dictionnaire.txt");
    splittext(text, TREE);




}


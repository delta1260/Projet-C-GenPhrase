
#include "readfile.h"
#include <time.h>

int main() {
    listeFlechi lst[20];
    srand(time(NULL));
    allTree TREE = initTree();
    char* text = readfile("dictionnaire_non_accentue.txt");
    splittext(text, &TREE);
    int i = randomWords(TREE.adj, lst, 0);
    printf("%d", i);
    for(int a = 0; a < i; ++a) {
        printf("%s\n", lst[a].tab[0].mot);
    }
}

//
// Created by antoi on 25/10/2022.
//

#include "tree.h"

p_node newNode(char c) {
    p_node new = malloc(sizeof(t_node));
    new->letter = c;
    new->liste = NULL;
    new->nbNext = 0;
    new->next = (p_node*)malloc(26 * sizeof(p_node));
    return new;
}

allTree initTree() {
    allTree tree;
    p_node new = newNode(' ');
    tree.nom = new;
    new = newNode(' ');
    tree.verbe = new;
    new = newNode(' ');
    tree.adj = new;
    new = newNode(' ');
    tree.adverbe = new;
    return tree;
}

listeFlechi* addWord(p_node pn, char* word) {
    if (word[0] != '\0') {
        int n = 1;
        while (pn->nbNext >= n && pn->next[n - 1]->letter != word[0]) {
            n++;
        }
        if (pn->nbNext == 0 || pn->nbNext < n) {

            p_node new = newNode(word[0]);
            pn->next[n-1] = new;
            pn->nbNext++;
            return addWord(new, word + 1);
        }
        else
            return addWord(pn->next[n - 1], word + 1);
    }
    else {
        if (pn->liste == NULL) {
            listeFlechi* list = malloc(sizeof(listeFlechi));
            list->nbmots = 0;
            pn->liste = list;
            return list;
        }
        else
            return pn->liste;
    }
}
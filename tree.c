//
// Created by antoi on 25/10/2022.
//

#include "tree.h"

//création d'un nouveau noeud
p_node newNode(char c) {
    p_node new = malloc(sizeof(t_node));
    new->letter = c;
    new->liste = NULL;
    new->nbNext = 0;
    new->next = (p_node*)malloc(26 * sizeof(p_node));
    return new;
}

//création des arbres principaux
allTree initTree() {
    allTree tree;
    p_node new = newNode(' '); // le char ' ' n'est jamais utilisé mais est nécéssaire au bon fonctionnement du code
    tree.nom = new;
    new = newNode(' ');
    tree.verbe = new;
    new = newNode(' ');
    tree.adj = new;
    new = newNode(' ');
    tree.adverbe = new;
    return tree;
}

// fonction récursive pour mettre les formes de bases dans les arbres
listeFlechi* addWord(p_node pn, char* word) {
    if (word[0] != '\0') {//verifie s'il reste des lettres dans le mot
        int n = 1;
        while (pn->nbNext >= n && pn->next[n - 1]->letter != word[0]) {// verifie si la lettre se trouve deja dans les suivants
            n++;
        }
        if (pn->nbNext == 0 || pn->nbNext < n) {

            p_node new = newNode(word[0]);
            pn->next[n-1] = new;
            pn->nbNext++;
            return addWord(new, word + 1);// continue la récursivité avec nouveau noeud contenant la lettre actuelle et le mot sa première lettre
        }
        else
            return addWord(pn->next[n - 1], word + 1);// continue la récursivité avec le noeud la lettre actuelle et le mot sans celle-ci
    }
    else {
        if (pn->liste == NULL) {// liste de mot flechi inexistante ?
            listeFlechi* list = malloc(sizeof(listeFlechi));
            list->nbmots = 0;
            pn->liste = list;
            return list;// retourne le pointeur de liste de mot flechi nouvellement créé
        }
        else
            return pn->liste;//// retourne le pointeur de liste de mot flechi existante
    }
}

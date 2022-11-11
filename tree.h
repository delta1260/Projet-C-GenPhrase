//
// Created by antoi on 25/10/2022.
//

#ifndef MAIN_C_TREE_H
#define MAIN_C_TREE_H
#include "formeflechie.h"


struct s_node {
    char letter;
    listeFlechi* liste;
    int nbNext;
    struct s_node** next;
};

typedef struct s_node t_node, *p_node;

typedef struct {
    int nbRoot;
    p_node* root;
}tree;

typedef struct {
    tree adj;
    tree nom;
    tree adverbe;
    tree verbe;
} allTree;

t_node newNode(char c);
listeFlechi addWord(t_node* pn, char* word, x);

#endif //MAIN_C_TREE_H

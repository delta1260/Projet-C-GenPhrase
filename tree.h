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
    p_node adj;
    p_node nom;
    p_node adverbe;
    p_node verbe;
} allTree;

p_node newNode(char c);
allTree initTree();
listeFlechi* addWord(p_node pn, char* word);

#endif //MAIN_C_TREE_H
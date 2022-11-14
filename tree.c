//
// Created by antoi on 25/10/2022.
//

#include "tree.h"

t_node newNode(char c) {
	t_node new;
	new.letter = c;
	new.liste = NULL;
	new.nbNext = 0;
	new.next = (p_node*)malloc(26 * p_node);
	return new;
}

listeFlechi* addWord(p_node pn, char* word) {
	if (word[0] != '\0') {
		int n = 1;
		while (pn->nbNext >= n && pn->next[n - 1]->letter != word[x]) {
			n++;
		}
		if (pn->nbNext == 0 || pn->nbNext < n) {
			t_node new = newNode(word[x]);
			pn->next[n] = &new;
			pn->nbNext++;
			return addWord(&new, word++);
		}
		else
			return addWord(pn->next[n - 1], word);
	}
	else {
		if (pn->liste = NULL) {
			listeFlechie list;
			pn->liste = &list;
			return &list;
		}
		else
			return pn->liste;
	}
}


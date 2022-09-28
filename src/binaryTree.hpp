#ifndef TREE_HPP 
#define TREE_HPP

#include <iostream>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	float key;
	float value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree();
bool TVazia(Tree **t);
void insertTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);

#endif

#ifndef RB_HPP 
#define RB_HPP

#include <iostream>

using namespace std;

typedef struct Record_rb Record_rb;
typedef struct Tree_rb Tree_rb;

struct Record_rb{
	float key;
};

struct Tree_rb{
	Record_rb reg;
	Tree_rb *esq, *dir;
	Tree_rb *pai; 
	bool cor;
};


Tree_rb* CreateTree_rb();

void rotacaoSimplesEsquerda_rb(Tree_rb **raiz, Tree_rb *child);
void rotacaoSimplesDireita_rb(Tree_rb **raiz, Tree_rb *child);

void insertFixUp_rb(Tree_rb **raiz, Tree_rb *child);
void insertTree_rb(Tree_rb **t, Tree_rb **pai, Tree_rb **raiz, Record_rb r);
void pesquisa_rb(Tree_rb **t, Tree_rb **aux, Record_rb r);

void RBTransplant(Tree_rb **raiz, Tree_rb *valor, Tree_rb *sucessor);
void RBDeleteFixup(Tree_rb **raiz, Tree_rb *valor);
void deleteRB(Tree_rb **raiz, Tree_rb *valor);
void removeTree_rb(Tree_rb **raiz, Tree_rb **t, Record_rb r);
Tree_rb * TreeMinimun(Tree_rb **t);

#endif
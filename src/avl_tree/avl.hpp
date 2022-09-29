#ifndef AVL_HPP 
#define AVL_HPP

#include <iostream>

using namespace std;

typedef struct Record_avl_tree Record_avl_tree;
typedef struct avl_Tree avl_Tree;

struct Record_avl_tree{
	float key;
	float value;
};

struct avl_Tree{
	Record_avl_tree reg;
	avl_Tree *left, *right;
	int weight;
};

avl_Tree* CreateTree_avl();
void insertTree_avl(avl_Tree **t, Record_avl_tree r);
void pesquisa_avl(avl_Tree **t, avl_Tree **aux, Record_avl_tree r);
int isInTree_avl(avl_Tree *t, Record_avl_tree r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTree_avl(avl_Tree **t, avl_Tree **f, Record_avl_tree r);
void antecessor_avl(avl_Tree **t, avl_Tree *aux);
void rebalanceTree_avl(avl_Tree **t);

void preordem_avl(avl_Tree *t);
void central_avl(avl_Tree *t);
void posordem_avl(avl_Tree *t);

int getWeight_avl(avl_Tree **t);
int getMaxWeight_avl(int left, int right);

void rotacaoSimplesDireita_avl(avl_Tree **t);
void rotacaoSimplesEsquerda_avl(avl_Tree **t);
void rotacaoDuplaDireita_avl(avl_Tree **t);
void rotacaoDuplaEsquerda_avl(avl_Tree **t);

#endif

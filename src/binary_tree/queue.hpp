#ifndef QUEUE_HPP 
#define QUEUE_HPP

#include <iostream>
#include "binaryTree.hpp"

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	binary_Tree *p;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};

void FFVazia(Fila *f);
bool isVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);

#endif
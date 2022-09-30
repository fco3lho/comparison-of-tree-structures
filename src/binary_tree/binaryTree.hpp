#ifndef BINARYTREE_HPP 
#define BINARYTREE_HPP

#include <iostream>

typedef struct Record_binary_tree Record_binary_tree;
typedef struct binary_Tree binary_Tree;

struct Record_binary_tree{
	float key;
	float value;
};

struct binary_Tree{
	Record_binary_tree reg;
	binary_Tree *esq, *dir;
};

binary_Tree* CreateTree_binary();
bool TVazia_binary(binary_Tree **t);
void insertTree_binary(binary_Tree **t, Record_binary_tree r);
void removeTree_binary(binary_Tree **t, Record_binary_tree r);
void antecessor_binary(binary_Tree **t, binary_Tree *aux);

#endif

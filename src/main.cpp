#include "includes.hpp"

void executeBinaryTree(){
	Tree *raiz = CreateTree();
	Record r;
	insertElements(&raiz, r);
	searchAndRemoveElements(&raiz, r);
}

int main(){
	executeBinaryTree();
}
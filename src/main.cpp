#include "binaryTree.hpp"
#include "queue.hpp"
#include "readFile.hpp"

int main(){
	Tree *raiz = CreateTree();
	Record r;
  
	insertElements(&raiz, r);
	searchAndRemoveElements(&raiz, r);
}
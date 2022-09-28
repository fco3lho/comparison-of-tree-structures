#include "binaryTree.hpp"
#include "queue.hpp"
#include "readFile.hpp"

int main(){
	Tree *raiz = CreateTree();
	// Tree *aux = CreateTree();
	Record r;
  
	insertElements(&raiz, r);
	searchAndRemoveElements(&raiz, r);


 


































 //  	printf("Árvore vazia: %d\n\n", TVazia(&raiz));
  	
	// printf("METODO PREORDEM: { ");
 //  	preordem(raiz);
 //  	printf("}\n\n");


 //  	printf("METODO CENTRAL: { ");
 //  	central(raiz);
	// printf("}\n\n");

 //  	printf("METODO POSORDEM: { ");
 //  	posordem(raiz);
 //  	printf("}\n\n");

 //  	printf("METODO LARGURA: { ");
 //  	widthPath(raiz);
 //  	printf("}\n\n");

	// r.key = 2;
	// pesquisa(&raiz, &aux, r);
	
	// printf("PESQUISA 2 E IMPRIME A SUBARVORE { ");
	// central(aux);
	// printf("}\n\n");

	// r.key = 3;
	// removeTree(&raiz, r);

	// printf("REMOVE 3 E IMPRIME A ARVORE { ");
	// central(raiz);
	// printf("}\n\n");

}
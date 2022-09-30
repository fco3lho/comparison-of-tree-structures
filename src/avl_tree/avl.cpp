#include "avl.hpp"

avl_Tree* CreateTree_avl(){
	return NULL;
}

void insertTree_avl(avl_Tree **t, Record_avl_tree r){

  if(*t == NULL){
    *t = new avl_Tree;
    (*t)->left   = NULL; 
    (*t)->right  = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 
  } 

  else{
    if(r.key < (*t)->reg.key){
      insertTree_avl(&(*t)->left, r);
      if ((getWeight_avl(&(*t)->left) - getWeight_avl(&(*t)->right)) == 2){
      	if(r.key < (*t)->left->reg.key)
      		rotacaoSimplesDireita_avl(t);
      	else
      		rotacaoDuplaDireita_avl(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_avl(&(*t)->right, r);
      if ((getWeight_avl(&(*t)->right) - getWeight_avl(&(*t)->left)) == 2){
      	if(r.key > (*t)->right->reg.key)
      		rotacaoSimplesEsquerda_avl(t);
      	else
      		rotacaoDuplaEsquerda_avl(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight_avl(getWeight_avl(&(*t)->left), getWeight_avl(&(*t)->right)) + 1;
}

void antecessor_avl(avl_Tree **t, avl_Tree *aux){ 

	if ((*t)->right != NULL){ 
		antecessor_avl(&(*t)->right, aux);
		return;
  	}
  	
  	aux->reg = (*t)->reg;
  	aux = *t; 
  	*t = (*t)->left;
  	delete(aux);
} 

void rebalanceTree_avl(avl_Tree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight_avl(&(*t)->left) - getWeight_avl(&(*t)->right);
	if((*t)->left)
		left = getWeight_avl(&(*t)->left->left) - getWeight_avl(&(*t)->left->right);
	if((*t)->right)
		right = getWeight_avl(&(*t)->right->left) - getWeight_avl(&(*t)->right->right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita_avl(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita_avl(t);

	if(balance == -2 && right <= 0)
		rotacaoSimplesEsquerda_avl(t);
	if(balance == -2 && right > 0)
		rotacaoDuplaEsquerda_avl(t); 	

}

void removeTree_avl(avl_Tree **t, avl_Tree **f, Record_avl_tree r){
	avl_Tree *aux;
  	
	if (*t == NULL){ 
		// cout << "[ERROR]: Record not found!" << endl;
  	return;
	}

	if (r.key < (*t)->reg.key){ removeTree_avl(&(*t)->left, t, r); return;}
	if (r.key > (*t)->reg.key){ removeTree_avl(&(*t)->right, t, r); return;}

	if ((*t)->right == NULL){ 
		aux = *t;  
		*t = (*t)->left;
  	delete(aux);
  	rebalanceTree_avl(f);
  	return;
	}

	if ((*t)->left != NULL){ 
		antecessor_avl(&(*t)->left, *t);
		rebalanceTree_avl(t);
		rebalanceTree_avl(f);
		return;
	}

	aux = *t;  
	*t = (*t)->right;
	delete(aux);
	rebalanceTree_avl(t);
	rebalanceTree_avl(f); 	
}

int getWeight_avl(avl_Tree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight_avl(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita_avl(avl_Tree **t){
	avl_Tree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight_avl(getWeight_avl(&(*t)->left), getWeight_avl(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight_avl(getWeight_avl(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda_avl(avl_Tree **t){
	avl_Tree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight_avl(getWeight_avl(&(*t)->left), getWeight_avl(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight_avl(getWeight_avl(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita_avl(avl_Tree **t){
	rotacaoSimplesEsquerda_avl(&(*t)->left);
	rotacaoSimplesDireita_avl(t);
}

void rotacaoDuplaEsquerda_avl(avl_Tree **t){
	rotacaoSimplesDireita_avl(&(*t)->right);
	rotacaoSimplesEsquerda_avl(t);
}
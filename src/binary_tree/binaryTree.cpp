#include "binaryTree.hpp"
#include "queue.hpp"

binary_Tree* CreateTree_binary(){
  return NULL;
}

bool TVazia_binary(binary_Tree **t){
  return *t == NULL;
}

void insertTree_binary(binary_Tree **t, Record_binary_tree r){

  if(TVazia_binary(t)){
    *t = new binary_Tree;
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  }

  else{
    
    if(r.key < (*t)->reg.key){
      insertTree_binary(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_binary(&(*t)->dir, r);
    }
  }
}

void pesquisa_binary(binary_Tree **t, binary_Tree **aux, Record_binary_tree r){

  if(*t == NULL){
    cout << "[ERROR]: Node not found!" << endl;
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa_binary(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa_binary(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

int isInTree_binary(binary_Tree *t, Record_binary_tree r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree_binary(t->esq, r) || isInTree_binary(t->dir, r);
}

void antecessor_binary(binary_Tree **t, binary_Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor_binary(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  delete(aux);
} 

void removeTree_binary(binary_Tree **t, Record_binary_tree r){
	binary_Tree *aux;
  	
  	if (*t == NULL){ 
  		// cout << "[ERROR]: Record not found!!!" << endl;
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree_binary(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree_binary(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	delete(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor_binary(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	delete(aux);
}
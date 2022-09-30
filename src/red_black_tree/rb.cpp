#include "rb.hpp"

Tree_rb* CreateTree_rb(){
  return NULL;
}

void insertFixUp_rb(Tree_rb **raiz, Tree_rb *child){
  Tree_rb *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->esq){
        
        tio = child->pai->pai->dir;

        //caso 1:
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->dir){
            child = child->pai;
            rotacaoSimplesEsquerda_rb(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita_rb(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->esq;
        
        //caso 1
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->esq){
            child = child->pai;
            rotacaoSimplesDireita_rb(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda_rb(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertTree_rb(Tree_rb **t, Tree_rb **pai, Tree_rb **raiz, Record_rb r){
  
  if(*t == NULL){
    *t = new Tree_rb;
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->pai = pai!=t?*pai:NULL;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp_rb(raiz, *t); 
  } 

  else{ 

    if(r.key < (*t)->reg.key){
      insertTree_rb(&(*t)->esq, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertTree_rb(&(*t)->dir, t, raiz, r);
      return;
    }
  }
}

void pesquisa_rb(Tree_rb **t, Tree_rb **aux, Record_rb r){

  if(*t == NULL){
    cout << "[ERROR]: Node not found!" << endl;
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa_rb(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa_rb(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

void rotacaoSimplesEsquerda_rb(Tree_rb **raiz, Tree_rb *child){
  Tree_rb *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if(y->esq != NULL)
    y->esq->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL)
    *raiz = y;

  else{

    if(x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  
  }

  y->esq = x;
  x->pai = y;
}


void rotacaoSimplesDireita_rb(Tree_rb **raiz, Tree_rb *child){
  Tree_rb *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if(y->dir != NULL)
    y->dir->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL){
    *raiz = y;
  }

  else{
    if(x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  }

  y->dir = x;
  x->pai = y;
  
}
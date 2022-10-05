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

void RBTransplant(Tree_rb **raiz, Tree_rb *valor, Tree_rb *sucessor){
  if (valor->pai == nullptr){
    (*raiz) = sucessor;
  }

  else if(valor == valor->pai->esq){
    valor->pai->esq = sucessor;
  }
  
  else{
    valor->pai->dir = sucessor;
  }

  sucessor->pai = valor->pai;
}

void RBDeleteFixup(Tree_rb **raiz, Tree_rb *valor){
  while(valor != (*raiz) && valor->cor){
    if(valor == valor->pai->esq){
      Tree_rb* aux = valor->pai->dir;

      if(aux != nullptr){
        if(!aux->cor){
          aux->cor = true;
          valor->pai->cor = false;
          rotacaoSimplesEsquerda_rb(raiz, valor->pai);
          aux = valor->pai->dir;
        }

        if((aux->dir == nullptr || aux->dir->cor) && (aux->esq == nullptr || aux->esq->cor)){
          aux->cor = false;
          valor = valor->pai;
        }

        else if(aux->dir == nullptr || aux->dir->cor){
          aux->esq->cor = true;
          aux->cor = false;
          rotacaoSimplesDireita_rb(raiz, aux);
          aux = valor->pai->dir;
        }

        if(aux->dir != nullptr && !aux->dir->cor){
          aux->cor = valor->pai->cor;
          valor->pai->cor = true;
          aux->dir->cor = true;
          rotacaoSimplesEsquerda_rb(raiz, valor->pai);
          valor = (*raiz);
        }
      }

      else{
        valor = valor->pai;
      }
    }

    else{
      Tree_rb* aux = valor->pai->esq;

      if(aux != nullptr){
        if(!aux->cor){
          aux->cor = true;
          valor->pai->cor = false;
          rotacaoSimplesDireita_rb(raiz, valor->pai);
          aux = valor->pai->esq;
        }

        if((aux->dir == nullptr || aux->dir->cor) && (aux->esq == nullptr || aux->esq->cor)){
          if(aux){
            aux->cor = false;
          }

          valor = valor->pai;
        }

        else if(aux->esq == nullptr || aux->esq->cor){
          aux->dir->cor = true;
          aux->cor = false;
          rotacaoSimplesEsquerda_rb(raiz, aux);
          aux = valor->pai->esq;
        }

        if(aux->esq != nullptr && !aux->esq->cor){
          aux->cor = valor->pai->cor;
          valor->pai->cor = true;
          aux->esq->cor = true;
          rotacaoSimplesDireita_rb(raiz, valor->pai);
          valor = (*raiz);
        }
      }

      else{
        valor = valor->pai;
      }      
    }
  }
  valor->cor = true;
}

void deleteRB(Tree_rb **raiz, Tree_rb *valor){
  Tree_rb *y = valor;
  Tree_rb *x;

  bool original_color = y->cor;

  if(valor->esq == nullptr){
    x = valor->dir;

    if(x == nullptr){
      x = new Tree_rb;
      x->reg.key = 404;
      x->cor = true;
      valor->dir = x;
    }

    RBTransplant(raiz, valor, valor->dir);
    x->pai = valor->pai;
  }

  else if(valor->dir == nullptr){
    x = valor->esq;

    if(x == nullptr){
      x = new Tree_rb;
      x->reg.key = 404;
      x->cor = true;
      valor->esq = x;
    }

    RBTransplant(raiz, valor, valor->esq);
    x->pai = valor->pai;
  }

  else{
    y = TreeMinimun(&valor->esq);
    original_color = y->cor;
    x = y->esq;

    if(x == nullptr){
      x = new Tree_rb;
      x->pai = y;
      x->reg.key = 404;
      x->cor = true;
      y->esq = x;
    }

    if(y->pai == valor){
      x->pai = y;
    }

    else{
      RBTransplant(raiz, y, y->esq);
      y->esq = valor->esq;
      y->esq->pai = y;
    }

    RBTransplant(raiz, valor, y);
    y->dir = valor->dir;
    y->dir->pai = y;
    y->cor = valor->cor;
  }

  Tree_rb *aux = x;

  if(original_color){
    RBDeleteFixup(raiz, x);
  }

  if(aux->reg.key == 404){
    if(aux == aux->pai->esq){
      aux->pai->esq = nullptr;
    }
    else{
      aux->pai->dir = nullptr;
    }

    delete aux;
  }

  delete valor;
}

void removeTree_rb(Tree_rb **raiz, Tree_rb **t, Record_rb r){
  if(*t == nullptr){
    return;
  }

  if(r.key < (*t)->reg.key){
    removeTree_rb(raiz, &(*t)->esq, r);
    return;
  }

  if(r.key > (*t)->reg.key){
    removeTree_rb(raiz, &(*t)->dir, r);
    return;
  }

  if((*raiz)->dir == nullptr && (*raiz)->esq == nullptr){
    delete (*raiz);
    (*raiz) = nullptr;
    return;
  }

  deleteRB(raiz, (*t));
}

Tree_rb *TreeMinimun(Tree_rb **t){
  if((*t)->dir != nullptr){
    return TreeMinimun(&(*t)->dir);
  }

  else{
    return (*t);
  }

  return nullptr;
}
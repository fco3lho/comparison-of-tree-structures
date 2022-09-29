#ifndef AVL_FUNCTIONS_HPP
#define AVL_FUNCTIONS_HPP

#include "avl.hpp"

#include <fstream>

void insertElements_avl_tree(avl_Tree **t, Record_avl_tree r, string textFile);
void searchAndRemoveElements_avl_tree(avl_Tree **t, Record_avl_tree r);

#endif
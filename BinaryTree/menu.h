#pragma once
#include "BinaryTree.h"
/* Menu bar */
void InputDatas(tree_t* tp);

int menu(const char** menuList, int cnt);

void mTraverse(tree_t* tp);
void mSearch(tree_t* tp);
void mDelete(tree_t* tp);
void mAdd(tree_t* tp);
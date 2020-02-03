#pragma once
#include <stdio.h>
#include "LinkedList.h"

int menu(const char** menuList, int cnt);
void mInputFirst(list_t* lp);
void mInputLast(list_t* lp);
void mOutput(list_t* lp);
void mSearch(list_t* lp);
void mDelete(list_t* lp);
void mSort(list_t* lp);
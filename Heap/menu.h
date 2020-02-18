#pragma once
#include <stdio.h>
#include "Heap.h"

/* Menu bar */
int menu(const char** menuList, int cnt);

void mInsert(heap_t* hp);
void mDelete(heap_t* hp);
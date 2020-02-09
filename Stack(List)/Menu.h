#pragma once
#include "ArrayStack.h"
/* Menu bar */
int menu(const char** menuList, int cnt);

void mPush(stack_t* sp);
void mPop(stack_t* sp);
void mTerminate(stack_t* sp);
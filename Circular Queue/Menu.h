#pragma once
#include "CircularQueue.h"
/* Menu bar */
int menu(const char** menuList, int cnt);

void mEnqueue(queue_t* qp);
void mDequeue(queue_t* qp);
void mTerminate(queue_t* qp);
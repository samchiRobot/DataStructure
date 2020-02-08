#include <stdio.h>
#include "ArrayStack.h"

int main(void)
{
	bool_t checker = FALSE;
	stack_t stack;
	checker = CreateStack(&stack, 10);
	if (checker)
		printf("Success\n");
	else
	{
		printf("Fail\n");
		return -1;
	}
	return 0;
}
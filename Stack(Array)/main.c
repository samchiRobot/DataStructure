#include <stdio.h>
#include "ArrayStack.h"

int main(void)
{
	bool_t checker = FALSE;
	stack_t s;
	int test = 0;
	checker = CreateStack(&s, 10);

	checker = Push(&s, 10);
	checker = Push(&s, 20);
	checker = Push(&s, 30);

	Pop(&s, &test);
	printf("%d\n", test);

	PrintStack(&s);

	if (checker)
		printf("Success\n");
	else
	{
		printf("Fail\n");
		return -1;
	}
	return 0;
}
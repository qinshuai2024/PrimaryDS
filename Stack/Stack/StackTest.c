#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void test1()
{
	ST st;

	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPrint(&st);

	printf("%d \n", StackTop(&st));
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);
	StackDestroy(&st);

}
int main()
{
	test1();
	return 0;
}
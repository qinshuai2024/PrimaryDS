#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void test1()
{
	LTNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPushFront(phead, 5);
	ListPushFront(phead, 6);
	ListPushFront(phead, 7);
	ListPrint(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListPopFront(phead);
	ListInsert(ListFind(phead, 1), 5);
	ListInsert(ListFind(phead, 2), 5);
	ListErase(ListFind(phead, 1));
	ListPrint(phead);

	ListDestroy(phead);
}
int main()
{
	test1();
	return 0;
}
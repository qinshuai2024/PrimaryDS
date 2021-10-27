#pragma once
#include"SList.h"

void test1()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushBack(&phead, 5);

	SListPushFront(&phead, 5);
	SListPushFront(&phead, 4);

	//SListPopBack(&phead);
	//SListPopBack(&phead);
	//SListPopBack(&phead);

	//SListPopFront(&phead);
	//SListPopFront(&phead);
	//SListPopFront(&phead);
	//SListPopFront(&phead);
	
	//SListErase(&phead, SListFind(phead, 2));
	//SListErase(&phead, SListFind(phead, 3));
	//SListErase(&phead, SListFind(phead, 4));
	//SListErase(&phead, SListFind(phead, 5));

	//SListInsert(&phead, SListFind(phead, 2), 20);
	//SListInsert(&phead, SListFind(phead, 5), 50);
	//SListEraseAfter(SListFind(phead, 5));
	SListInsertAfter(SListFind(phead, 5), 55);
	SListInsertAfter(SListFind(phead, 4), 44);

	SListPrint(phead);

	SListDestory(&phead);
}
int main()
{
	test1();
	return 0;
}
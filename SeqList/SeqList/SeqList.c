#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SLtest1()
{
	SL sl;
	SeqListInit(&sl, 4);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListErase(&sl, SeqListFind(&sl, 1));
	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 10);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}
int main()
{
	SLtest1();
	return 0;
}



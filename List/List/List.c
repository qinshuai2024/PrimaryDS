#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//初始化链表
LTNode* ListInit()
{
	//创建头结点
	LTNode* head = (LTNode*)malloc(sizeof(LTNode));
	if (head == NULL)
		exit(-1);

	head->next = head;
	head->prev = head;
	
	return head;
}
// 双向链表打印
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* sur = phead->next;
	while (sur != phead)
	{
		printf("%d->", sur->data);
		sur = sur->next;
	}
	printf("NULL\n");
}
//创建一个新的结点
LTNode* BuyListNode(LTDataType x)
{
	//创建头结点
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
// 双向链表尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	LTNode* newnode = BuyListNode(x);
	//直接链接，不用考虑多余情况
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}
// 双向链表尾删
void ListPopBack(LTNode* phead)
{
	//头结点不为空，并且链表不为空
	assert(phead && phead->next != phead);

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;//尾的前一个
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
}
// 双向链表头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* first = phead->next;//第一个有效结点

	phead->next = newnode;
	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
}
// 双向链表头删
void ListPopFront(LTNode* phead)
{
	//头结点不为空，并且链表不为空
	assert(phead && phead->next != phead);

	LTNode* first = phead->next;
	LTNode* firstNext = first->next;

	phead->next = firstNext;
	firstNext->prev = phead;
	free(first);
}
// 双向链表查找
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead && phead->next != phead);
	LTNode* temp = phead->next;
	while (temp != phead)
	{
		if (temp->data == x)
			return temp;
		temp = temp->next;
	}
	//找不到
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = BuyListNode(x);
	LTNode* posPrev = pos->prev;
	
	newnode->prev = posPrev;
	posPrev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	posPrev->next = pos->next;
	pos->next->prev = posPrev;
	free(pos);
}

// 摧毁链表
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* sur = phead->next;
	LTNode* next = NULL;
	while (sur != phead)
	{
		next = sur->next;
		free(sur);
		sur = next;
	}
	free(phead);
}
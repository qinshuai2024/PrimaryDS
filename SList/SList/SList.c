#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

// 动态申请一个节点
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
// 单链表打印
void SListPrint(SLTNode* phead)
{
	while (phead)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//1.没有结点
	//2.至少一个结点
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		//没有结点		
		*pphead = newnode;
	}
	else
	{
		//有结点，找尾
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// 单链表的头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//链表是否为空不影响头插
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
// 单链表的尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//不能没有结点
	//如果只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//不止一个结点
		SLTNode* prev = *pphead;//存放最后一个结点的前一个
		SLTNode* tail = *pphead;//找尾
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}
// 单链表头删
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//不能没有结点
	
	//有一个结点也相同
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{	
	while (phead != NULL)
	{
		if (phead->data == x)
			break;
		phead = phead->next;
	}
	return phead;
}

// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);

	SLTNode* newnode = BuySListNode(x);	
	if (*pphead == pos)
	{
		//只有一个结点,头插
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* prev = *pphead;//存放pos结点的前一个
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
// 删除在pos位置节点
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	//只有一个结点
	if (*pphead == pos)
	{
		SLTNode* next = (*pphead)->next;//存放pos结点的下一个
		free(*pphead);
		*pphead = next;
	}
	else
	{
		SLTNode* prev = *pphead;//存放pos结点的前一个

		while (prev != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);

		//SLTNode* tail = *pphead;//找pos
		//while (tail->next != NULL)
		//{
		//	if (tail == pos)
		//		break;
		//	prev = tail;
		//	tail = tail->next;
		//}
		//prev->next = tail->next;
		//free(tail);
	}
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//pos后面不能没有
	//链接删除结点左右两个结点
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}



void SListDestory(SLTNode** pphead)
{
	SLTNode* next = *pphead;
	while (next != NULL)
	{
		SLTNode* temp = next;
		next = next->next;
		free(temp);		
	}
	*pphead = NULL;
}
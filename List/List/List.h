#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//带头结点的双向循环链表
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化链表
LTNode* ListInit();
// 双向链表打印
void ListPrint(LTNode* phead);
//创建一个新的结点
LTNode* BuyListNode(LTDataType x);
// 双向链表尾插
void ListPushBack(LTNode* phead, LTDataType x);
// 双向链表尾删
void ListPopBack(LTNode* phead);
// 双向链表头插
void ListPushFront(LTNode* phead, LTDataType x);
// 双向链表头删
void ListPopFront(LTNode* phead);
// 双向链表查找
LTNode* ListFind(LTNode* phead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(LTNode* pos);
// 摧毁链表
void ListDestroy(LTNode* phead);

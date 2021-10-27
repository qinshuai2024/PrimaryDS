#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;
	struct SLNode* next;
};
typedef struct SListNode SLTNode;

// 动态申请一个节点
SLTNode* BuySListNode(SLTDataType x);
// 单链表打印
void SListPrint(SLTNode* phead);
// 单链表尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
// 单链表的头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
// 单链表的尾删
void SListPopBack(SLTNode** pphead);
// 单链表头删
void SListPopFront(SLTNode** pphead);
// 单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode* pos, SLTDataType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode* pos);

// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
// 删除在pos位置节点
void SListErase(SLTNode** pphead, SLTNode* pos);

void SListDestory(SLTNode** pphead);

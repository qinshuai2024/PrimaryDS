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

// ��̬����һ���ڵ�
SLTNode* BuySListNode(SLTDataType x);
// �������ӡ
void SListPrint(SLTNode* phead);
// ������β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
// �������ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);
// �������βɾ
void SListPopBack(SLTNode** pphead);
// ������ͷɾ
void SListPopFront(SLTNode** pphead);
// ���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode* pos, SLTDataType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SLTNode* pos);

// ��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
// ɾ����posλ�ýڵ�
void SListErase(SLTNode** pphead, SLTNode* pos);

void SListDestory(SLTNode** pphead);

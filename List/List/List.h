#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//��ͷ����˫��ѭ������
typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//��ʼ������
LTNode* ListInit();
// ˫�������ӡ
void ListPrint(LTNode* phead);
//����һ���µĽ��
LTNode* BuyListNode(LTDataType x);
// ˫������β��
void ListPushBack(LTNode* phead, LTDataType x);
// ˫������βɾ
void ListPopBack(LTNode* phead);
// ˫������ͷ��
void ListPushFront(LTNode* phead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(LTNode* phead);
// ˫���������
LTNode* ListFind(LTNode* phead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(LTNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos);
// �ݻ�����
void ListDestroy(LTNode* phead);

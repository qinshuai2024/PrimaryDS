#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//��ʼ������
LTNode* ListInit()
{
	//����ͷ���
	LTNode* head = (LTNode*)malloc(sizeof(LTNode));
	if (head == NULL)
		exit(-1);

	head->next = head;
	head->prev = head;
	
	return head;
}
// ˫�������ӡ
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
//����һ���µĽ��
LTNode* BuyListNode(LTDataType x)
{
	//����ͷ���
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
// ˫������β��
void ListPushBack(LTNode* phead, LTDataType x)
{
	LTNode* newnode = BuyListNode(x);
	//ֱ�����ӣ����ÿ��Ƕ������
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}
// ˫������βɾ
void ListPopBack(LTNode* phead)
{
	//ͷ��㲻Ϊ�գ���������Ϊ��
	assert(phead && phead->next != phead);

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;//β��ǰһ��
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
}
// ˫������ͷ��
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* first = phead->next;//��һ����Ч���

	phead->next = newnode;
	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
}
// ˫������ͷɾ
void ListPopFront(LTNode* phead)
{
	//ͷ��㲻Ϊ�գ���������Ϊ��
	assert(phead && phead->next != phead);

	LTNode* first = phead->next;
	LTNode* firstNext = first->next;

	phead->next = firstNext;
	firstNext->prev = phead;
	free(first);
}
// ˫���������
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
	//�Ҳ���
	return NULL;
}
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	posPrev->next = pos->next;
	pos->next->prev = posPrev;
	free(pos);
}

// �ݻ�����
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
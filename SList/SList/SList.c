#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

// ��̬����һ���ڵ�
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
// �������ӡ
void SListPrint(SLTNode* phead)
{
	while (phead)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}
// ������β��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//1.û�н��
	//2.����һ�����
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		//û�н��		
		*pphead = newnode;
	}
	else
	{
		//�н�㣬��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
// �������ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//�����Ƿ�Ϊ�ղ�Ӱ��ͷ��
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
// �������βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//����û�н��
	//���ֻ��һ�����
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//��ֹһ�����
		SLTNode* prev = *pphead;//������һ������ǰһ��
		SLTNode* tail = *pphead;//��β
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}
// ������ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//����û�н��
	
	//��һ�����Ҳ��ͬ
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
// ���������
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

// ��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead && pos);

	SLTNode* newnode = BuySListNode(x);	
	if (*pphead == pos)
	{
		//ֻ��һ�����,ͷ��
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* prev = *pphead;//���pos����ǰһ��
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
// ɾ����posλ�ýڵ�
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	//ֻ��һ�����
	if (*pphead == pos)
	{
		SLTNode* next = (*pphead)->next;//���pos������һ��
		free(*pphead);
		*pphead = next;
	}
	else
	{
		SLTNode* prev = *pphead;//���pos����ǰһ��

		while (prev != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);

		//SLTNode* tail = *pphead;//��pos
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//pos���治��û��
	//����ɾ����������������
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
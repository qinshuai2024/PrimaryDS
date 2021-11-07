#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
// ��β�����
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = data;
	newnode->next = NULL;
	//����Ƿ�Ϊ��
	if (pq->head == NULL)
	{
		//Ϊ�գ�ͷβָ���һ�����
		pq->head = pq->tail = newnode;
	}
	else
	{
		//��Ϊ�գ�β��
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

// ��ͷ������
void QueuePop(Queue* pq)
{
	//�ж϶����Ƿ�Ϊ��
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;


	//��ȫ��Ԫ�ض������к�βָ���ÿ�
	if (pq->head == NULL)
		pq->tail = NULL;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* sur = pq->head;
	while (sur != NULL)
	{
		count++;
		sur = sur->next;
	}
	return count;
}
// �������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
// ���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* sur = pq->head;
	while (sur != NULL)//����д��sur!=pq->tail����������ɾ�����һ��
	{
		QueueNode* next = sur->next;
		free(sur);
		sur = next;
	}
	pq->head = pq->tail = NULL;
}
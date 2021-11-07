#define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"
//����ѭ������˳���ʵ��

//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	if (cq == NULL)
//		exit(-1);
//	cq->a = (CQDataType*)malloc(sizeof(CQDataType) * (k + 1));
//	//�࿪��һ���ռ䣬�����������Ϳ�
//	if (cq->a == NULL)
//		exit(-1);
//	cq->capacity = k ;
//	cq->front = cq->rear = 0;
//	return cq;
//}
////�����
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	//�ж��Ƿ���
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//����
//	obj->a[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % (obj->capacity + 1);
//	return true;
//}
////������
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	
//	if (myCircularQueueIsEmpty(obj))
//	{
//		//Ϊ��
//		return false;
//	}
//	obj->front = (obj->front + 1) % (obj->capacity + 1);
//	return true;
//}
////ȡ��ͷԪ��
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->a[obj->front];
//}
////ȡ��βԪ��
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	//ȡrear��ǰһ��
//	return obj->a[(obj->rear + obj->capacity) % (obj->capacity + 1)];
//}
////�ж��Ƿ�Ϊ��
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	if (obj->front == obj->rear)
//		return true;
//	else
//		return false;
//}
////�ж϶����Ƿ���
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	if ((obj->rear + 1) % (obj->capacity + 1) == obj->front)
//		return true;
//	else
//		return false;
//}
////���ٶ���
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->a);
//	obj->capacity = obj->front = obj->rear = 0;
//	free(obj);
//	obj = NULL;
//}

//����ʵ��
//����ѭ������
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cq == NULL)
		exit(-1);
	cq->capacity = k;
	//����k+1�����
	//��һ��
	MyCQNode* head = (MyCQNode*)malloc(sizeof(MyCQNode));
	if (head == NULL)
		exit(-1);
	head->next = NULL;
	MyCQNode* sur = head;
	
	while (k--)
	{
		//�ٿ�K��
		MyCQNode* newnode = (MyCQNode*)malloc(sizeof(MyCQNode));
		if (newnode == NULL)
			exit(-1);
		newnode->next = NULL;
		sur->next = newnode;
		sur = sur->next;

	}
	sur->next = head;//ѭ������
	cq->head = cq->tail = head;//�����ָ���һ��
	return cq;
}
//�����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;
	//tailָ�����һ��λ�ü���
	obj->tail->next->data = value;
	obj->tail = obj->tail->next;
	return true;
}
//������
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->head = obj->head->next;
	return true;
}
//ȡ��ͷԪ��
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	//headָ�����һ���������
	return obj->head->next->data;
}
//ȡ��βԪ��
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->tail->data;
}
//�ж��Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->head == obj->tail)
		return true;
	else
		return false;
}
//�ж϶����Ƿ���
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->head == obj->tail->next)
		return true;
	else
		return false;
}
//���ٶ���
void myCircularQueueFree(MyCircularQueue* obj)
{
	MyCQNode* temp = obj->head;
	MyCQNode* headnext = obj->head->next;
	temp->next = NULL;//����
	while (headnext != NULL)
	{
		temp = headnext->next;
		free(headnext);
		headnext = temp;
	}
	obj->capacity = 0;
	obj->head = obj->tail = NULL;
	free(obj);
	obj = NULL;
}
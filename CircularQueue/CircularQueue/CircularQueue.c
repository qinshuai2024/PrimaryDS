#define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"
//创建循环队列顺序表实现

//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	if (cq == NULL)
//		exit(-1);
//	cq->a = (CQDataType*)malloc(sizeof(CQDataType) * (k + 1));
//	//多开辟一个空间，用以区分满和空
//	if (cq->a == NULL)
//		exit(-1);
//	cq->capacity = k ;
//	cq->front = cq->rear = 0;
//	return cq;
//}
////入队列
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	//判断是否满
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//插入
//	obj->a[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % (obj->capacity + 1);
//	return true;
//}
////出队列
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	
//	if (myCircularQueueIsEmpty(obj))
//	{
//		//为空
//		return false;
//	}
//	obj->front = (obj->front + 1) % (obj->capacity + 1);
//	return true;
//}
////取队头元素
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->a[obj->front];
//}
////取队尾元素
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	//取rear的前一个
//	return obj->a[(obj->rear + obj->capacity) % (obj->capacity + 1)];
//}
////判断是否为空
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	if (obj->front == obj->rear)
//		return true;
//	else
//		return false;
//}
////判断队列是否满
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	if ((obj->rear + 1) % (obj->capacity + 1) == obj->front)
//		return true;
//	else
//		return false;
//}
////销毁队列
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	free(obj->a);
//	obj->capacity = obj->front = obj->rear = 0;
//	free(obj);
//	obj = NULL;
//}

//链表实现
//创建循环队列
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (cq == NULL)
		exit(-1);
	cq->capacity = k;
	//开辟k+1个结点
	//先一个
	MyCQNode* head = (MyCQNode*)malloc(sizeof(MyCQNode));
	if (head == NULL)
		exit(-1);
	head->next = NULL;
	MyCQNode* sur = head;
	
	while (k--)
	{
		//再开K个
		MyCQNode* newnode = (MyCQNode*)malloc(sizeof(MyCQNode));
		if (newnode == NULL)
			exit(-1);
		newnode->next = NULL;
		sur->next = newnode;
		sur = sur->next;

	}
	sur->next = head;//循环链表
	cq->head = cq->tail = head;//最初都指向第一个
	return cq;
}
//入队列
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;
	//tail指向的下一个位置加入
	obj->tail->next->data = value;
	obj->tail = obj->tail->next;
	return true;
}
//出队列
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->head = obj->head->next;
	return true;
}
//取队头元素
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	//head指向的下一个结点数据
	return obj->head->next->data;
}
//取队尾元素
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->tail->data;
}
//判断是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->head == obj->tail)
		return true;
	else
		return false;
}
//判断队列是否满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->head == obj->tail->next)
		return true;
	else
		return false;
}
//销毁队列
void myCircularQueueFree(MyCircularQueue* obj)
{
	MyCQNode* temp = obj->head;
	MyCQNode* headnext = obj->head->next;
	temp->next = NULL;//断链
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
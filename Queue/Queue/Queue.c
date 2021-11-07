#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
// 队尾入队列
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = data;
	newnode->next = NULL;
	//检查是否为空
	if (pq->head == NULL)
	{
		//为空，头尾指向第一个结点
		pq->head = pq->tail = newnode;
	}
	else
	{
		//不为空，尾插
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

}

// 队头出队列
void QueuePop(Queue* pq)
{
	//判断队列是否为空
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;


	//当全部元素都出队列后尾指针置空
	if (pq->head == NULL)
		pq->tail = NULL;
}
// 获取队列头部元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
// 获取队列中有效元素个数
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
// 检测队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
// 销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* sur = pq->head;
	while (sur != NULL)//不能写出sur!=pq->tail，这样会少删了最后一个
	{
		QueueNode* next = sur->next;
		free(sur);
		sur = next;
	}
	pq->head = pq->tail = NULL;
}
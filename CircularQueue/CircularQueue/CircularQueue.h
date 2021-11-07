#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int CQDataType;

//˳���ʵ��ѭ������

//typedef struct 
//{
//	int* a;//����
//	int front;//ͷ
//	int rear;//β
//	int capacity;//����
//} MyCircularQueue;

//����ѭ������ʵ��
typedef struct MyCircularQueueNode
{
	CQDataType data;
	struct MyCircularQueueNode* next;
}MyCQNode;
typedef struct
{
	
	MyCQNode* head;//ָ��ѭ�����е�ͷ��ǰһ��
	MyCQNode* tail;//ָ��β
	int capacity;//����
} MyCircularQueue;


//����ѭ������
MyCircularQueue* myCircularQueueCreate(int k);
//�����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//������
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//ȡ��ͷԪ��
int myCircularQueueFront(MyCircularQueue* obj);
//ȡ��βԪ��
int myCircularQueueRear(MyCircularQueue* obj);
//�ж��Ƿ�Ϊ��
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//�ж϶����Ƿ���
bool myCircularQueueIsFull(MyCircularQueue* obj);
//���ٶ���
void myCircularQueueFree(MyCircularQueue* obj);


#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int CQDataType;

//顺序表实现循环队列

//typedef struct 
//{
//	int* a;//数组
//	int front;//头
//	int rear;//尾
//	int capacity;//容量
//} MyCircularQueue;

//单向循环链表实现
typedef struct MyCircularQueueNode
{
	CQDataType data;
	struct MyCircularQueueNode* next;
}MyCQNode;
typedef struct
{
	
	MyCQNode* head;//指向循环队列的头的前一个
	MyCQNode* tail;//指向尾
	int capacity;//容量
} MyCircularQueue;


//创建循环队列
MyCircularQueue* myCircularQueueCreate(int k);
//入队列
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//出队列
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//取队头元素
int myCircularQueueFront(MyCircularQueue* obj);
//取队尾元素
int myCircularQueueRear(MyCircularQueue* obj);
//判断是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//判断队列是否满
bool myCircularQueueIsFull(MyCircularQueue* obj);
//销毁队列
void myCircularQueueFree(MyCircularQueue* obj);


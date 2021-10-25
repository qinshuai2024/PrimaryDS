#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//顺序表

//#define MAX_NUM 100
//typedef int SLDataType;
////静态的
//struct SeqList
//{
//	SLDataType arr[MAX_NUM];//定长的数组，之后不在改变
//	int size;//数组中存放了多少个数据
//};

//动态的

typedef int SLDataType;
struct SeqList
{
	SLDataType* a;//一个数据类型的指针，指向动态开辟的空间
	int size;     //数组中存放了多少个数据
	int capacity; //数组实际能存数据的个数
};
typedef struct SeqList SL;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SL* psl, int capacity);
// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl);
// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x);
// 顺序表尾删
void SeqListPopBack(SL* psl);
// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x);
// 顺序表头删
void SeqListPopFront(SL* psl);
// 顺序表查找
int SeqListFind(SL* psl, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SL* psl, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* psl, int pos);
// 顺序表销毁
void SeqListDestory(SL* psl);
// 顺序表打印
void SeqListPrint(SL* psl);
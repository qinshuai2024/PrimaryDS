#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//˳���

//#define MAX_NUM 100
//typedef int SLDataType;
////��̬��
//struct SeqList
//{
//	SLDataType arr[MAX_NUM];//���������飬֮���ڸı�
//	int size;//�����д���˶��ٸ�����
//};

//��̬��

typedef int SLDataType;
struct SeqList
{
	SLDataType* a;//һ���������͵�ָ�룬ָ��̬���ٵĿռ�
	int size;     //�����д���˶��ٸ�����
	int capacity; //����ʵ���ܴ����ݵĸ���
};
typedef struct SeqList SL;

// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SL* psl, int capacity);
// ���ռ䣬������ˣ���������
void SeqListCheckCapacity(SL* psl);
// ˳���β��
void SeqListPushBack(SL* psl, SLDataType x);
// ˳���βɾ
void SeqListPopBack(SL* psl);
// ˳���ͷ��
void SeqListPushFront(SL* psl, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SL* psl);
// ˳������
int SeqListFind(SL* psl, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SL* psl, int pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* psl, int pos);
// ˳�������
void SeqListDestory(SL* psl);
// ˳����ӡ
void SeqListPrint(SL* psl);
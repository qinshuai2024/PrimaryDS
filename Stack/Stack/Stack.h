#pragma once
//˳���ʵ��ջ
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;
	int capacity;
};
typedef struct Stack ST;

//��ʼ��ջ
void StackInit(ST* ps);
//����ջ
void StackDestroy(ST* ps);
//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//��ȡջ��Ԫ��
STDataType StackTop(ST* ps);
//��ȡջԪ�ظ���
int StackSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);
//��ӡջԪ��
void StackPrint(ST* ps);
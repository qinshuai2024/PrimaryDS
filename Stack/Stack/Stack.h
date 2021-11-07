#pragma once
//顺序表实现栈
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

//初始化栈
void StackInit(ST* ps);
//销毁栈
void StackDestroy(ST* ps);
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//获取栈定元素
STDataType StackTop(ST* ps);
//获取栈元素个数
int StackSize(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);
//打印栈元素
void StackPrint(ST* ps);
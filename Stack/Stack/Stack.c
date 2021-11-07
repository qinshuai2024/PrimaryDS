#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//初始化栈
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//top指向栈当前元素的下一个位置
	ps->capacity = 0;
}
//销毁栈
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//栈满
		//如果是第一次开辟，先开辟四个，否则以两倍增加
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (temp == NULL)
			exit(-1);
		ps->a = temp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);//如果栈为空则出错
	assert(!StackEmpty(ps));
	ps->top--;
}
//获取栈定元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
//获取栈元素个数
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
//打印栈元素
void StackPrint(ST* ps)
{
	assert(ps);
	int top = ps->top;
	while (top--)
	{
		printf("%d ", ps->a[top]);
	}
	printf("\n");
}
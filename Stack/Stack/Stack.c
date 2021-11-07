#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//��ʼ��ջ
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//topָ��ջ��ǰԪ�ص���һ��λ��
	ps->capacity = 0;
}
//����ջ
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//ջ��
		//����ǵ�һ�ο��٣��ȿ����ĸ�����������������
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
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);//���ջΪ�������
	assert(!StackEmpty(ps));
	ps->top--;
}
//��ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
//��ȡջԪ�ظ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
//��ӡջԪ��
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
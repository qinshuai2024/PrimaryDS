#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
// 顺序表初始化
void SeqListInit(SL* psl, int capacity)
{
	psl->a = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if (psl->a == NULL)
		exit(-1);
	psl->capacity = capacity;
	psl->size = 0;
}

// 顺序表销毁
void SeqListDestory(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}

// 顺序表打印
void SeqListPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		//扩容
		//int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//如果是第一次扩容，设置容量为4，否则以两倍扩充
		int newcapacity = psl->capacity * 2;
		SLDataType* new = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newcapacity);//扩大两倍，如果psl->a==NULL，realloc相当于malloc
		if (new== NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		psl->a = new;
		psl->capacity = newcapacity;
	}
	else
		return;

}
// 顺序表尾插
void SeqListPushBack(SL* psl, SLDataType x)
{
	//1.判断顺序表是否满了
	SeqListCheckCapacity(psl);
	psl->a[psl->size] = x;
	++psl->size;
}
// 顺序表尾删
void SeqListPopBack(SL* psl)
{
	assert(psl);
	psl->size--;
}
// 顺序表头插
void SeqListPushFront(SL* psl, SLDataType x)
{
	//判断是否满了
	SeqListCheckCapacity(psl);
	//从后往前移动
	int end = psl->size-1;//end为最后一个的下标
	while (end >= 0)
	{
		//end最小为0
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
// 顺序表头删
void SeqListPopFront(SL* psl)
{
	assert(psl);
	//删除第一个元素，后面的往前移动
	int begin = 0;
	while (begin < psl->size-1)
	{
		//begin最大为psl->size-2
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}
// 顺序表查找
int SeqListFind(SL* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
			return i;
	}
	//失败返回-1
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SL* psl, int pos, SLDataType x)
{
	//判断是否满
	SeqListCheckCapacity(psl);
	//判断pos是否越界
	if (pos < 0 || pos >= psl->size)
	{
		printf("pos error\n");
		return;
	}
	else
	{
		//往后移动，类似头插
		int end = psl->size - 1;
		while (end >= pos)
		{
			psl->a[end + 1] = psl->a[end];
			end--;
		}
		psl->a[pos] = x;
		psl->size++;
	}
}
// 顺序表删除pos位置的值
void SeqListErase(SL* psl, int pos)
{
	//往前移，类似头删
	assert(psl);
	int begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}


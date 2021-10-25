#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
// ˳����ʼ��
void SeqListInit(SL* psl, int capacity)
{
	psl->a = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if (psl->a == NULL)
		exit(-1);
	psl->capacity = capacity;
	psl->size = 0;
}

// ˳�������
void SeqListDestory(SL* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}

// ˳����ӡ
void SeqListPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

// ���ռ䣬������ˣ���������
void SeqListCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		//����
		//int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//����ǵ�һ�����ݣ���������Ϊ4����������������
		int newcapacity = psl->capacity * 2;
		SLDataType* new = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newcapacity);//�������������psl->a==NULL��realloc�൱��malloc
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
// ˳���β��
void SeqListPushBack(SL* psl, SLDataType x)
{
	//1.�ж�˳����Ƿ�����
	SeqListCheckCapacity(psl);
	psl->a[psl->size] = x;
	++psl->size;
}
// ˳���βɾ
void SeqListPopBack(SL* psl)
{
	assert(psl);
	psl->size--;
}
// ˳���ͷ��
void SeqListPushFront(SL* psl, SLDataType x)
{
	//�ж��Ƿ�����
	SeqListCheckCapacity(psl);
	//�Ӻ���ǰ�ƶ�
	int end = psl->size-1;//endΪ���һ�����±�
	while (end >= 0)
	{
		//end��СΪ0
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
// ˳���ͷɾ
void SeqListPopFront(SL* psl)
{
	assert(psl);
	//ɾ����һ��Ԫ�أ��������ǰ�ƶ�
	int begin = 0;
	while (begin < psl->size-1)
	{
		//begin���Ϊpsl->size-2
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}
// ˳������
int SeqListFind(SL* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
			return i;
	}
	//ʧ�ܷ���-1
	return -1;
}
// ˳�����posλ�ò���x
void SeqListInsert(SL* psl, int pos, SLDataType x)
{
	//�ж��Ƿ���
	SeqListCheckCapacity(psl);
	//�ж�pos�Ƿ�Խ��
	if (pos < 0 || pos >= psl->size)
	{
		printf("pos error\n");
		return;
	}
	else
	{
		//�����ƶ�������ͷ��
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
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* psl, int pos)
{
	//��ǰ�ƣ�����ͷɾ
	assert(psl);
	int begin = pos;
	while (begin < psl->size - 1)
	{
		psl->a[begin] = psl->a[begin + 1];
		++begin;
	}
	psl->size--;
}


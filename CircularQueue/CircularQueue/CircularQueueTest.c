 #define _CRT_SECURE_NO_WARNINGS 1
#include"CircularQueue.h"

void test1()
{
	
	MyCircularQueue* cq=myCircularQueueCreate(4);
	myCircularQueueEnQueue(cq, 1);
	myCircularQueueEnQueue(cq, 2);
	myCircularQueueEnQueue(cq, 3);
	myCircularQueueEnQueue(cq, 4);
	int k = myCircularQueueFront(cq);
	int m = myCircularQueueRear(cq);

	bool tf = myCircularQueueDeQueue(cq);
	tf = myCircularQueueDeQueue(cq);
	tf = myCircularQueueDeQueue(cq);
	tf = myCircularQueueDeQueue(cq);
	tf = myCircularQueueDeQueue(cq);

	myCircularQueueFree(cq);
}
int main()
{
	test1();
	return 0;
}
#pragma once
#include <stdio.h>
#define maxSize 50

typedef struct
{
	int data[maxSize];
	int front, rear;

}CirQueue;

//0- maxSize-1
//init queue(front rear指向一个位置)
void InitCirQueue(CirQueue* cirQueue)
{
	cirQueue->front = cirQueue->rear = maxSize - 1;
}

//入队操作（插入队尾）
void EnQueue(CirQueue* cirQueue, int element)
{
	//可插入的范围为 0- (maxSize-2)，初始化从0开始
	if ((cirQueue->rear + 1) % maxSize == cirQueue->front)
	{
		printf("上溢！");
	}
	else
	{
		cirQueue->rear = (cirQueue->rear + 1) % maxSize;
		cirQueue->data[cirQueue->rear] = element;
	}
}

int DeCirQueue(CirQueue* cirQueue)
{
	if (cirQueue->front == cirQueue->rear)
	{
		return NULL;
	}
	else
	{
		cirQueue->front = (cirQueue->front + 1) % maxSize;
		return cirQueue->data[cirQueue->front];
	}
}

//may  exist problem
int GetCirQueueHeader(CirQueue *cirQueue)
{
	if (cirQueue->front == cirQueue->rear)
	{
		return NULL;
	}
	else
	{
		int i = (cirQueue->front + 1) % maxSize;
		return cirQueue->data[i];
	}
}
int IsEmpty(CirQueue *cirQueue)
{
	if(cirQueue->front == cirQueue->rear)
	{
		return 0;
	}
	else
		return 1;
}

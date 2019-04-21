#pragma once
#include <stdio.h>
#define maxSize 50

typedef struct
{
	int data[maxSize];
	int front, rear;

}CirQueue;

//0- maxSize-1
//init queue(front rearָ��һ��λ��)
void InitCirQueue(CirQueue* cirQueue)
{
	cirQueue->front = cirQueue->rear = maxSize - 1;
}

//��Ӳ����������β��
void EnQueue(CirQueue* cirQueue, int element)
{
	//�ɲ���ķ�ΧΪ 0- (maxSize-2)����ʼ����0��ʼ
	if ((cirQueue->rear + 1) % maxSize == cirQueue->front)
	{
		printf("���磡");
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

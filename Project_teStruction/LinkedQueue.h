#pragma once
#include <stdio.h>
//single linked
typedef struct LinkedNode
{
	int x;
	LinkedNode* next;
}LinkedNode;
//for Expedience
typedef struct
{
	LinkedNode *front, *rear;
}LinkedQueue;

void InitLinkedQueue(LinkedQueue* linkedQueue)
{
	LinkedNode* s = (LinkedNode*)malloc(sizeof(LinkedNode));
	s->next = NULL;
	linkedQueue->rear = linkedQueue->front = s;
}
void EnLinkedQueue()
{

}
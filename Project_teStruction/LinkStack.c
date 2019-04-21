#include <stdio.h>

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

void InitLinkStack(LNode* lnode)
{
	lnode = NULL;
}
int InsertLS(LNode* lnode,int element)
{
	LNode* node = (LNode*)malloc(sizeof(LNode));
	node->data = element;
	node->next = lnode;
	lnode = node;
}
int PopLS(LNode* lnode)
{
	int i = 0;
	if (lnode != NULL)
		i = lnode->data;
		lnode = lnode->next;
	return i;
}
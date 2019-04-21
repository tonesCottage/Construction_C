#include <stdio.h>
typedef struct DLNode {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode;

void InsertElementByPosition(DLNode* first, int i, int element)
{
	DLNode* p = first; int count = 0;
	//first is exist value;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		printf("not exist!");
		exit(-1);
	}
	else
	{
		DLNode* node = (DLNode*)malloc(sizeof(DLNode));
		node->data = element;
		node->next = p->next;
		node->prior = p;
		//£î£ï£ô£é£ã£å
		p->next->prior = node;
		p->next = node;
	}
}
DLNode* Delete(DLNode* first, int i)
{
	DLNode* p = first; int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		printf("not  exist!");
		exit(-1);
	}
	else
	{
		DLNode* q = p->next;
		p->next = q->next;
		q->next->prior = p;
		free(q);
		return q;
	}
}
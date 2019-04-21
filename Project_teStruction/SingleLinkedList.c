#include <stdio.h>
#include<stdlib.h>

//����ͷ�ڵ������
typedef struct SLinkList
{
	int data;
	struct  SLinkList *next;
}SLinkList;
//init
SLinkList* InitSingleLinkedList(SLinkList* first)
{
	first = (SLinkList*)malloc(sizeof(SLinkList));
	first->next = NULL;
	return first;
}
//foreach
void PrintList(SLinkList *list)
{
	SLinkList* p;
	p = list->next;
	while (p != NULL)
	{
		printf(p->data);
		p = p->next;
	}
}
int GetLen(SLinkList* list)
{
	int count = 0;
	SLinkList* p;
	p = list->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
SLinkList GetElementByPosition_SLL(SLinkList* list, int position)
{
	SLinkList* p;
	p = list->next;
	int count = 0;
	while (p != NULL && count < position)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || count == 0)
	{
		exit(-1);
	}
	else
	{
		return *p;
	}
}
//INSERT POSITION--I  main:��s->next=p->next;p->next=s;��
//main:(not exit header)(1.s->next=first 2.first=s; )
void Insert(SLinkList *slinklist, int i, int data)
{
	SLinkList* p;
	p = slinklist;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		printf("not found!");
		exit(-1);
	}
	else
	{
		SLinkList* s = (SLinkList*)malloc(sizeof(SLinkList));
		s->data = data;
		s->next = p->next;
		//s���뵽p֮��
		p->next = s;
	}

}
//header insert
SLinkList* CreateSLListH(SLinkList* list, int IntArray[], int len)
{
	list = (SLinkList*)malloc(sizeof(SLinkList));
	list->next = NULL;
	for (int i = 0; i < len; i++)
	{
		SLinkList* s = (SLinkList*)malloc(sizeof(SLinkList));
		s->data = IntArray[i];
		s->next = list->next;
		list->next = s;
	}
	return list;
}
//End Insert(���ָ��ı仯)���Աȿ�ʵ�ֵ������ߵݼ�������)
SLinkList* CreateSLListE(SLinkList* list, int IntArray[], int len)
{
	list = (SLinkList*)malloc(sizeof(SLinkList));
	SLinkList* m = list;
	for (int i = 0; i < len; i++)
	{
		SLinkList* s = (SLinkList*)malloc(sizeof(SLinkList));
		s->data = IntArray[i];
		m->next = s;
		m = s;
	}
	m->next = NULL;
	return list;
}
SLinkList* DeleteElementByPosition(SLinkList* first, int position)
{
	SLinkList* p = first;
	int count = 0;
	while (p!=NULL && count<position-1 )
	{
		p = p->next;
		count++;
	}
	if (p==NULL)
	{
		printf("node  not  exist");
	}
	else
	{
		SLinkList* q = p->next;
		SLinkList* x = q->next;
		p->next = q->next;
		free(q);
		return x;
	}
}

//�ϲ�����list
void Merge(SLinkList *A, SLinkList *B, SLinkList *C)
{
	SLinkList *p = A->next;
	SLinkList *q = B->next;
	SLinkList *r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p; p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q; q = q->next;
			r = r->next;
		}
		r->next = NULL;
		if (p != NULL)
			r->next = p;
		if (q != NULL)
			r->next = q;
	}
}

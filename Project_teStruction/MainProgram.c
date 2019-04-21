#include <stdio.h>
#include "SingleLinkedList.c"
int main(void)
{
	SLinkList *A, *B, *C;
	A = (SLinkList*)malloc(sizeof(SLinkList));
	A->next = NULL;
	B = (SLinkList*)malloc(sizeof(SLinkList));
	B->next = NULL;
	C = (SLinkList*)malloc(sizeof(SLinkList));
	C->next = NULL;

	for (int i = 1; i < 4; i++)
	{
		SLinkList *MID;
		MID = (SLinkList*)malloc(sizeof(SLinkList));
		MID->data = 2 * i;

		MID->next = A->next;

		A->next = MID;
	}
	int a[4] = { 1, 2, 3, 4 };
	B = CreateSLListE(B, a,4);

	SLinkList* r = B;
	for (int i = 1; i < 4; i++)
	{
		SLinkList *MID;
		MID = (SLinkList*)malloc(sizeof(SLinkList));
		MID->data = 2 * i+1;
		r->next = MID;
		r = r->next;//r=MID;
	}
	r->next = NULL;


	Merge(A, B, C);
	printf("Helloddd world!\n");
	system("pause");
}
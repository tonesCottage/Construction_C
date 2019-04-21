#include <stdio.h>
#define MaxSize 100

typedef struct
{
	int data[MaxSize];
	int top;
}SqStack;
//初始化
void InitSqStack(SqStack* sqStack)
{
	sqStack->top = -1;
}
//是否为空
int IsEmpty(SqStack sqStack)
{
	if (sqStack.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Push(SqStack* sqstack, int element)
{
	if (sqstack->top == MaxSize - 1)
		return 0;
	//sqstack->data[++(sqstack->top)] = element;
	++(sqstack->top);
	sqstack->data[sqstack->top] = element;
		return 1;
}
int Pop(SqStack* sqstack)
{
	if (sqstack->top == -1)
		return 0;
	//int x=sqstack->data[(sqstack->top)--];
	int x = sqstack->data[sqstack->top];
	--(sqstack->top);
		return 1;
}
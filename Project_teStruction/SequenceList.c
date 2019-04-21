#include <stdio.h>
#define maxSize 50

typedef struct
{
	int data[maxSize];
	int length;
}Sqlist;
int A[maxSize];
int n;

void InitList(Sqlist L)
{
	L.length = 0;
}

//找到元素可能所处位置（待插入）
int FindElem(Sqlist L, int x)
{
	int i=-1;
	for (int i = 0; i < L.length; i++)
	{
		//如果首次小于顺序表的值，则返回当前位置（若插入，在i之前即可）
		if (x < L.data[i])
		{
			return i;
		}
	}
	return i;
}
//找到元素位置
int FindElemByValue(Sqlist L, int x)
{
	int i=-1;
	for (int i = 0; i < L.length; i++)
	{
		//如果首次小于顺序表的值，则返回当前位置（若插入，在i之前即可）
		if (x == L.data[i])
		{
			return i;
		}
	}
	return i;
}
//插入
//使用引用类型&L
int InsertElem(Sqlist L, int x)
{
	int p, i;
	p = FindElem(L, x);
	if (L.length < maxSize)
	{
		//from  right to x.position
		for (i = L.length - 1; i >= p; i--)
			L.data[i + 1] = L.data[i];
		L.data[i] = x;
		++(L.length);
		return 1;
	}
	else
	{
		return 0;
	}
}
//插入指定位置
int InsertElemByPosition(Sqlist L, int position, int x)
{
	int i;
	if (L.length == maxSize || position > L.length || position < 0)
		return 0;
	for (i = L.length - 1; i >= position; --i)
		L.data[i + 1] = L.data[i];
	L.data[position] = x;
	++(L.length);
	return 1;
}
//删除下标元素
int DeleteElem(Sqlist L, int position)
{
	if (position < 0 || position >= L.length)
		return 0;
	int i;
	for (i = position; i < L.length-1; ++i)
		L.data[i] = L.data[i + 1];
	--(L.length);
	return 1;
}

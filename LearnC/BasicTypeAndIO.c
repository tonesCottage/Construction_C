#include <stdio.h>
#include <stdlib.h>
//����������ֵ
void ExChange(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	printf("p:%d||", *p);
	printf("q:%d\n", *q);
};
void test3() {
	int a = 0;
	a++;
	printf("a��ֵ��%d\n", a);
	/**
	 static���ξֲ�������
	 1>�ӳ��ֲ��������������ڣ����������ʱ�򣬾ֲ������Żᱻ����
	 2>��û�иı�ֲ�������������
	 3>���е�test����������һ������b
	 */
	static int b = 0;
	b++;
	printf("b��ֵ��%d\n", b);
}
void PrintArray(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d:%d||", i + 1, *(p + i));
	}
	printf("\n");
};
struct Student
{
	int age;
	char* name;
	char sex;
};
enum Color
{
	red = 7, green, black
};
main()
{
	//char int float double long short
	//%c %d %f %lf %ld  16:%x 8:%o string:%s  
	printf("Hello World1\n");
	printf("char length:%d\nfloat length:%d\ndouble length:%d\nint length:%d\nlong length:%d\nshort length:%d\n", sizeof(char), sizeof(float),
		sizeof(double), sizeof(int), sizeof(long), sizeof(short));

	//io  exception
	char arr[20];
	//scanf_s("%s", arr, 20);
	//printf("arr=%s\n", arr);

	//zhizhen
	int i = 5;
	printf("i address:%#x\n", &i);
	int* p; p = &i;
	printf("p~s i address:%#x\n", p); printf("*p��ֵ%d\n", *p);

	//array
	// ������һ���������ڴ�ռ�  ������ �����ڴ�ռ���׵�ַ 
	// ������[i]  ==  *(������+i); 
	int arr2[3] = { 100,234,386 };
	printf("output array:%d%d\n", arr2[0], arr2[1]);
	printf("output array:%x\n", arr2);
	printf("output array:%x%x\n", &arr2[1], &arr2[2]);
	printf("output array:%x%x\n", arr2[1], *(arr2 + 1));
	PrintArray(&arr2[0], 3);
	//realloc(arr2,sizeof(int)*12);

	int* fl = (int*)malloc(sizeof(int));
	*fl = 21;
	printf("fl value:%d||", *fl); printf("fl zhizhen:%x||", fl);
	//����ָ��
	int x = 2; int y = 3;
	void(*pp)(int* x, int* y) = ExChange;
	pp(&x, &y);

	//struct
	struct Student stu = { 18,"liming",'��' };
	printf("name:%s||%c\n", stu.name, stu.sex);
	printf("name:%x and size:%d\n", &stu, sizeof(stu));
	struct Student* pst;
	pst = &stu;
	printf("name:%s\n", pst->name);
	//union
	union { int i; long j; char x; }mix;
	mix.x = '/';
	printf("value:%ld\n", mix.i);
	//enum
	enum Color color = red;
	printf("color:%d\n", color);
	//typedef
	typedef char fu;
	fu c = '1234';
	printf("fu:%c\n", c);

	//Ԥ����
	//static�ڲ����� extent�ⲿ����
	system("pause");
}
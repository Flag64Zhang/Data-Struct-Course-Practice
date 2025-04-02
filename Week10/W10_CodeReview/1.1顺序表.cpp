#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100
//声明
typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;
//初始化
void InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
//建立
void CreatList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++, i++;
	}
	L->length = k;
}
//输出
void DispList(SqList*& L) {
	for (int i = 0; i < L->length; i++)
		cout << L->data[i] << endl;
}
//销毁顺序表
void DestroyList(SqList*& L) {
	free(L);
}
//顺序表求长度
int ListLength(SqList*& L) {
	return(L->length);
}
//顺序表判断是否为空
bool ListEmpty(SqList*& L) {
	return(L->length == 0);
}
//按序号求顺序表中元素
bool GetElem(SqList*& L, int i, ElemType& e) {
	if (i<1 || i>L->length - 1)
		return false;
	else
		e = L->data[i - 1];
	return true;
}
//顺序表按元素查找
int LocateElem(SqList* L, ElemType e) {
	int i = 0;
	while (i <= L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}
//顺序表插入数据元素
bool ListInsert(SqList*& L, int i, ElemType e) {
	int j;
	if (i == L->length + 1 || L->length == MaxSize || i < 1)
		return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->length++;
	L->data[i] = e;
	return true;
}
//顺序表按索引删除数据元素
bool ListDelete(SqList*& L, int i, ElemType& e) {
	int j;
	if (i > L->length || i < 1)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++) 
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}
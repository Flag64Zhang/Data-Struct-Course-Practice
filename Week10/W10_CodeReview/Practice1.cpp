#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
void CreatList(SqList*& L, ElemType a[], int n) {
	int i=0, j = 0;
	InitList(L);
	for (i = 0; i < n; i++) {
		L->data[i] = a[j];
		j++;
	}
	L->length = i;
}
bool DispList(SqList*& L) {
	if (L->length == 0)
		return false;
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << endl;
	}
	return true;
}
bool GetElem(SqList*& L,int i, ElemType& e) {
	if (i<1 || i>L->length - 1)
		return false;
	else
		e = L->data[i - 1];
	return true;
}
int LocateElem(SqList*& L, ElemType e) {
	int i = 0;
	while (i <= L->length && L->data[i] != e)
		i++;
	if (i > L->length)
		return 0;
	else
		return i + 1;
}
bool ListInsert(SqList*& L, int i, ElemType e) {
	if (i >= L->length - 1 || i < 1 || L->length == MaxSize)
		return false;
	L->length++;
	for (int n = i; n < L->length; n++) {
		L->data[n + 1] = L->data[n];
	}
	L->data[i] = e;
	return true;
}
bool ListDelete(SqList*& L, int i, ElemType& e) {
	if (i < 1 || i >= L->length)
		return false;
	e = L->data[i];
	for (int n = L->length;n>i; n--) {
		L->data[n-1]=L->data[n];
	}
	L->length--;
	return true;
}
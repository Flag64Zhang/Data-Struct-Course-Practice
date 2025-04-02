#pragma once
using namespace std;

typedef char ElemType;
#define MAX 100

typedef struct {
	ElemType Data[MAX];
	int length;
}SqList;

void InitList(SqList*& L);

void DestroyList(SqList*& L);

void InsertByOrder(SqList* L);

bool AddElemByOrder(SqList* L, ElemType e, int i);

bool DeleteElemByOrder(SqList* L, ElemType& e, int i);

bool DeleteElemByObj(SqList* L, ElemType e, int& i);

void ShowList(SqList* L);

int GetListLength(SqList* L);

bool IsEmpty(SqList* L);

bool GetElemByOrder(SqList* L, ElemType& e, int i);

int GetFirstOrderByElem(SqList* L, ElemType e);

bool GetMaxElem(SqList* L,ElemType &max, int& i);

void CheckInput(ElemType& e, string str);

void CheckInput(int& i, string str);

void CheckList(SqList*& L);
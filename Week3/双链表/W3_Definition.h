#pragma once
#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
} DLinkNode;
void InitList(DLinkNode*& L);

void CreateListR_1(DLinkNode*& L);

void CreateListR(DLinkNode*& L, int n);

void DLinkListPrint(DLinkNode*& L);

bool ListInsert(DLinkNode*& L, int i, ElemType e);

bool ListDelete(DLinkNode*& L, int i, ElemType& e);

int ListLength(DLinkNode* L);

bool ListEmpty(DLinkNode* L);

void DestroyList(DLinkNode*& L);

bool GetElem(DLinkNode* L, int i, ElemType& e);

int LocateElem(DLinkNode* L, ElemType e);
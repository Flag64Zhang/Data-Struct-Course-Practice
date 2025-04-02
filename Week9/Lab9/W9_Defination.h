#pragma once
#include <iostream>
using namespace std;

#define MaxSize 20
#define MAXV 50
#define INF 32767
typedef int ElemType;
typedef struct sqstack {
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct Anode {
	int adjvex;
	struct Anode* nextarc;
	int weight;
}ArcNode;
typedef struct Vnode {
	int info;
	ArcNode* firstarc;
}VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;
void InitStack(SqStack*& s);
bool StackEmpty(SqStack* s);
bool Push(SqStack*& s, ElemType e);
bool Pop(SqStack*& s, ElemType& e);
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
void TopSort(AdjGraph* G);

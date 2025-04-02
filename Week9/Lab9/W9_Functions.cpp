#include"W9_Defination.h"

void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
bool StackEmpty(SqStack* s) {
	return  (s->top == -1);
}
bool Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	}
	G->n = n; G->e = e;
}
void DispAdj(AdjGraph* G) {
	int i; ArcNode* p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p != NULL) {
			printf("%3d", p->adjvex);
			p = p->nextarc;
		}
		printf("^\n");
	}
}
void TopSort(AdjGraph* G) {
	SqStack* st;
	InitStack(st);
	int indegree[MAXV];
	for (int i = 0; i < G->n; i++)indegree[i] = 0;
	for (int i = 0; i < G->n; i++) {
		ArcNode* p = G->adjlist[i].firstarc;
		while (p != NULL) {
			int w = p->adjvex;
			indegree[w]++;
			p = p->nextarc;
		}
	}
	for (int i = 0; i < G->n; i++)
		if (indegree[i] == 0)
			Push(st, i);
	int i;
	while (!StackEmpty(st)) {
		Pop(st, i);
		printf("C%d\t", i + 1);
		ArcNode* p = G->adjlist[i].firstarc;
		while (p != NULL) {
			int w = p->adjvex;
			indegree[w]--;
			if (indegree[w] == 0)
				Push(st, w);
			p=p->nextarc;
		}
	}
}
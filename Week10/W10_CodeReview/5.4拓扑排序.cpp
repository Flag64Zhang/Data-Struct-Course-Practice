#include <iostream>
using namespace std;

#define MaxSize 20
#define MAXV 50
typedef int ElemType;
typedef struct sqstack {
	ElemType data[MaxSize];
	int top;
}SqStack;
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
		if (indegree[i] == 0)Push(st, i);
	int i;
	while (!StackEmpty(st)) {
		Pop(st, i);
		printf("%d", i);
		ArcNode* p = G->adjlist[i].firstarc;
		while (p != NULL) {
			int w = p->adjvex;
			indegree[w]--;
			p->nextarc;
		}
	}
}
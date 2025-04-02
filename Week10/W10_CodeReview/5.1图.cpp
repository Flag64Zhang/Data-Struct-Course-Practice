#include <iostream>
using namespace std;
#define MAXV 10
#define INF 32767
typedef char InfoType;
typedef int EdgeType;
//邻接表式存储
typedef struct ANode {//边节点
	int adjvex;
	struct ANode* nextarc;
	EdgeType weight;
}ArcNode;
typedef struct VNode {//头结点
	InfoType info;
	ArcNode* firstarc;
}VNode;
typedef struct {//邻接表
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;
//创建图的邻接表的运算算法
void CreateAdj(AdjGraph* G, int A[MAXV][MAXV], int n, int e) {
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++) {
		for (j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0 && A[i][j] != INF) {
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = n; G->e = e;
}
//输出图的运算算法
void DispAdj(AdjGraph* G) {
	int i; ArcNode* p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p != NULL) {
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}
//销毁图的运算算法
void DestroyAdj(AdjGraph*& G) {
	int i; ArcNode* p, * pre;
	for (i = 0; i < G->n; i++) {
		pre = G->adjlist[i].firstarc;
		if (pre != NULL) {
			p = pre->nextarc;
			while (p != NULL) {
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}
//深度优先遍历(Depth first search)
int visited[MAXV] = { 0 };
void DFS(AdjGraph* G, int v) {
	ArcNode* p;
	visited[v] = 1;
	printf("%d", v);
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}
//广度优先遍历(Breadth first search)
#define MaxSize 100
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
bool QueueEmpty(SqQueue* q) {
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType& e) {
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e) {
	if (QueueEmpty(q))
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}
void BFS(AdjGraph* G, int v) {
	int w, i; ArcNode* p;
	SqQueue* qu;
	InitQueue(qu);
	int visited[MAXV];
	for (i = 0; i < G->n; i++)visited[i] = 0;
	printf("%2d", v);
	visited[v] = 1;
	enQueue(qu, v);
	while (!QueueEmpty(qu)) {
		deQueue(qu, w);
		p = G->adjlist[w].firstarc;
		while (p != NULL) {
			if (visited[p->adjvex] == 0) {
				printf("%2d", p->adjvex);
				visited[p->adjvex] = 1;
				enQueue(qu, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}
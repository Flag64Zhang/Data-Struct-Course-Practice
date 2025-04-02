#include "W8_Defination.h"
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++) {
		for (j = n-1; j >=0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->ajdvex = j;
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
			printf("%3d[%d]", p->ajdvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}
int visited[MAXV] = { 0 };
void DFS(AdjGraph* G, int v) {
	ArcNode* p;
	visited[v] = 1;
	printf("·ÃÎÊ¶¥µã±àºÅÎª:%d\t", v);
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visited[p->ajdvex] == 0)
			DFS(G, p->ajdvex);
		p = p->nextarc;
	}
}
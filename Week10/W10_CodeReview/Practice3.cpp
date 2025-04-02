#include <iostream>
using namespace std;
#define MAXV 50
#define INF 32767
typedef char InfoType;
typedef int EdgeType;
typedef struct anode {
	int adjvex;
	struct anode* nextarc;
	EdgeType weight;
}ArcNode;
typedef struct vnode {
	InfoType info;
	ArcNode* firstarc;
}VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;
//创建
void CreateAdj(AdjGraph* G, int A[MAXV][MAXV], int n, int e) {
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			if (A[i][j] != 0 && A[i][j] != INF) {
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->adjvex = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = e;
}
//输出
void DispAdj(AdjGraph* G) {
	int i; ArcNode* p;
	for (int i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d",i);
		while (p != NULL) {
			printf("%3d(%d)->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}
//销毁
void DestroyAdj(AdjGraph*&G) {
	int i; ArcNode* pre, * p;
	for (i = 0; i < G->n; i++) {
		pre = G->adjlist[i].firstarc;
		if (p != NULL) {
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
//深度优先遍历
int visited[MAXV] = {0};
void DFS(AdjGraph* G,int v) {
	ArcNode* p;
	visited[v] = 1;
	p = G->adjlist[v].firstarc;
	printf("%d", v);
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

typedef struct {
	int key;
	InfoType info;
}RecType;
//堆排序
void sift(RecType R[], int low, int high) {
	int i = low, j = 2 * i;
	RecType tmp = R[i];
	while (j <= high) {
		if (j < high && R[j].key < R[j + 1].key)
			j++;
		if (tmp.key < R[j].key) {
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = tmp;
}
void HeapSort(RecType R[], int n) {
	int i;
	RecType tmp;
	for (i = n / 2; i >= 1; i--)
		sift(R, i, n);
	for (i = n; i >= 2; i--) {
		tmp = R[1];
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);
	}
}
void sift(RecType R[], int low, int high) {
	int i = low, j = 2 * i;
	RecType tmp = R[i];
	while (j <= high) {
		if (j < high && R[j].key < R[j + 1].key)
			j++;
		if (tmp.key < R[j].key) {
			R[i] = R[j];
			i = j;
			j = i * 2;
		}
		else break;

	}	
	R[i] = tmp;
}
void sift(RecType R[], int low, int high) {
	int i = low, j = 2 * i;
	RecType tmp = R[i];
	while (j <= high) {
		if (j < high && R[j].key < R[j + 1].key)
			j++;
		if (tmp.key < R[j].key) {
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = tmp;
}
void HeapSort(RecType R[], int n) {
	int i;
	RecType tmp;
	for (i = i / 2; i >= 1; i--)
		sift(R, i, n);
	for (i = n; i >= 2; i--) {
		tmp = R[1];
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);
	}
}
void HeapSort(RecType R[],int n){
	int i;
	RecType tmp;
	for (i = i / 2; i >= 1; i--)
		sift(R, i, n);
	for (i = n; i >= 2; i--) {
		tmp = R[1];
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);
	}
}

typedef struct {
	int no;
	InfoType info;
}VertexType;
typedef struct {
	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
}MatGraph;
typedef struct {
	InfoType info;
	int no;
}VertexType;
typedef struct {
	VertexType vexs[MAXV];
	int n, e;
	int edges[MAXV][MAXV];
};
typedef struct {
	int no;
	InfoType info;
}VertexType;
typedef struct {
	VertexType vexs[MAXV];
	int edges[MAXV][MAXV];
	int n, e;
};
void Prim(MatGraph g, int v) {
	int lowcost[MAXV];
	int mindist;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++) {
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {
		mindist = INF;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && lowcost[j] < mindist) {
				mindist = lowcost[j];
				k = j;
			}
		printf("边(%d,%d)权为%d\n", closest[k], k, mindist);
		lowcost[k] = 0;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
void Prim(MatGraph g, int v) {
	int lowcost[MAXV];
	int mindist;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++) {
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {
		mindist = INF;
		for (j = 0; j < g.n; j++) {
			if (lowcost[j] != 0 && lowcost[j] < mindist) {
				mindist = lowcost[i];
				k = j;
			}
		}
		printf("边(%d,%d)权为%d\n", closest[k], k, mindist);
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++)
			if (lowcost[j]!=0&&g.edges[k][j]<lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
void InsertSort(RecType R[], int n) {
	int i, j = 0; RecType tmp;
	for (i = 0; i < n; i++) {
		if (R[i].key < R[i - 1].key) {
			tmp = R[i];
			j = i - 1;
			do {
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].key > tmp.key);
		}R[j + 1] = tmp;
	}
}
void Prim(MatGraph g,int v) {
	int lowcost[MAXV];
	int mindist;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++) {
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {
		mindist = INF;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && lowcost[j] < mindist) {
				mindist = lowcost[j];
				k = j;
			}
		printf;
		lowcost[k] = 0;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
void Prim(MatGraph g, int v) {
	int lowcost[MAXV];
	int mindist;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++) {
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++) {
		mindist = INF;
		for (j = 0; j < g.n; j++) 
			if (lowcost[j] != 0 && lowcost[j] < mindist) {
				mindist = lowcost[j];
				k = j;
			}
		printf("%d%d%d", closest[k], k, mindist);
		lowcost[k] = 0;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
void Prim(MatGraph g, int v) {
	int mindist;
	int lowcost[MAXV];
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++) {
		closest[i] = v;
		lowcost[i] = g.edges[v][i];
	}
	for (i = 0; i < g.n; i++) {
		mindist = INF;
		for(j=0;i<g.n;j++)
			if (lowcost[j] != 0 && lowcost[j] < mindist) {
				mindist = lowcost[j];
				k = j;
			}
		printf("%d%d%d", closest[k], k, mindist);
		lowcost[k] = 0;
		for(j=0;j<g.n;j++)
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
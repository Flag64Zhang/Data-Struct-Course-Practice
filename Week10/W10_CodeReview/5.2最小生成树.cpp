#include <iostream>
using namespace std;
//邻接矩阵
#define MAXV 50
#define INF 32767
typedef int InfoType;
typedef struct {
	int no;
	InfoType info;
}VertexType;
typedef struct {
	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
}MatGraph;
//普里姆算法Prim
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
			if (lowcost[j] != 0 && lowcost[j] < mindist)
				mindist = lowcost[j];
			k = j;
		}
		printf("边(%d,%d)权为:%d", closest[k], k, mindist);
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++) {
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
}
//克鲁斯卡尔Kruscal
#define MaxSize 100
typedef struct {
	int u, v, w;//起始顶点、终止顶点、权值
}Edge;//直接插入排序法
void InsertSort(Edge R[], int n) {
	int i, j; Edge tmp;
	for (i = 1; i < n; i++) {
		if (R[i].w < R[i - 1].w) {
			tmp = R[i];
			j = i - 1;
			do {
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].w > tmp.w);
			R[j + 1] = tmp;
		}
	}
}
void Kruscal(MatGraph g) {
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXV];
	Edge E[MaxSize];
	k = 0;
	for (i = 0; i < g.n; i++) {
		for (j = 0; j <= i; j++) {
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
				k++;
			}
		}
	}
	InsertSort(E, g.e);
	for (i = 0; i < g.n; i++)
		vset[i] = i;
	k = 1; j = 0;
	while (k < g.n) {
		u1 = E[j].u; v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];
		if (sn1 != sn2) {
			printf("(%d,%d):%d\n", u1, v1, E[j].w);
			k++;
			for (i = 0; i < g.n; i++) {
				if (vset[i] == sn2)
					vset[i] = sn1;
			}
			j++;
		}
	}
}
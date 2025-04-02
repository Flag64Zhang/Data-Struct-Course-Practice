#include "W9_Defination.h"
//创建邻接矩阵
void CreatMat(MatGraph& g) {
	g.n = 6; g.e = 10;
	int matrixData[6][6] = {
		{0, 5, INF, 7, INF, 3},
		{INF, 0, 4, INF, INF, INF},
		{8, INF, 0, INF, INF, 9},
		{INF, INF, 5, 0, INF, 6},
		{INF, INF, INF, 5, 0, INF},
		{INF, INF, INF, INF, 1, 0}
	};

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			g.edges[i][j] = matrixData[i][j];
		}
	}
}
//输出邻接矩阵
void DispMat(MatGraph g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.edges[i][j] == INF) {
				cout << "INF ";
			}
			else {
				cout << g.edges[i][j] << " ";
			}
		}
		cout << endl;
	}
}
//直接插入排序
void InsertSort(Edge R[],int n) {
	int i, j; Edge temp;
	for (i = 1; i < n; i++) {
		if (R[i].w < R[i - 1].w) {
			temp = R[i];
			j = i - 1;
			do {
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].w > temp.w);
			R[j + 1] = temp;
		}
	}
}
//克鲁斯卡尔算法Kruskal algorithm
void Kruskal(MatGraph g) {
	int i, j, u1, v1, sn1, sn2, k;
	int vest[MAXV];
	Edge E[MaxSize];
	k = 0;
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
				E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
				k++;
			}
		}
	}
	InsertSort(E, g.e);
	for (int i = 0; i < g.n; i++)
		vest[i] = i	;
	k = 1; j = 0;
	while (k < g.n) {
		u1 = E[j].u;
		v1 = E[j].v;
		sn1 = vest[u1];
		sn2 = vest[v1];
		if (sn1 != sn2) {
			printf("(%d,%d):%d\n", u1, v1, E[j].w);
			k++;
			for (i = 0; i < g.n; i++) {
				if (vest[i] == sn2)
					vest[i] = sn1;
			}
		}
	j++;
	}
}
//狄克斯特拉算法Dijkstra algorithm
void Dijkstra(MatGraph g, int v) {
	int dist[MAXV], path[MAXV];
	int S[MAXV];
	int mindist, i, j, u;
	for (i = 0; i < g.n; i++) {
		dist[i] = g.edges[v][i];
		S[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	S[v] = 1; path[v] = 0;
	for (i = 0; i < g.n - 1; i++) {
		mindist = INF;
		for (j = 0; j < g.n; j++)
			if (S[j] == 0 && dist[j] < mindist) {
				u = j;
				mindist = dist[j];
			}
		S[u] = 1;
		for (j = 0; j < g.n; j++) {
			if (S[j] == 0)
				if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
		}
	}
	Dispath(g, dist, path, S, v);
}
//狄克斯特拉算法输出函数
void Dispath(MatGraph g, int dist[], int path[], int S[], int v) {
	int i, j, k;
	int apath[MAXV], d;
	for (i = 0; i < g.n; i++)
		if (S[i] == 1 && i != v) {
			printf("从顶点%d到顶点%d的路径长度为:%d\t路径为:", v, i, dist[i]);
			d = 0; apath[d] = i;
			k = path[i];
			if (k == -1)
				printf("无路径\n");
			else {
				while (k != v) {
					d++; apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = v;
				printf("%d", apath[d]);
				for (j = d - 1; j >= 0; j--)
					printf(",%d", apath[j]);
				printf("\n");
			}
		}
}
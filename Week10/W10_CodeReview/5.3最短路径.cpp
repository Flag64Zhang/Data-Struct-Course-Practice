#include <iostream>
using namespace std;
//�ڽӾ���
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
//��Դ���·������
//�ҿ�˹�����㷨Dijkstra algorithm
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
//�ҿ�˹�����㷨�������
void Dispath(MatGraph g, int dist[], int path[], int S[], int v) {
	int i, j, k;
	int apath[MAXV], d;
	for (i = 0; i < g.n; i++)
		if (S[i] == 1 && i != v) {
			printf("�Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:", v, i, dist[i]);
			d = 0; apath[d] = i;
			k = path[i];
			if (k == -1)
				printf("��·��\n");
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
//��Դ���·������
//���������㷨Floyd algorithm
void Floyd(MatGraph g) {
	int A[MAXV][MAXV], path[MAXV][MAXV];
	int i, j, k;
	for (i = 0; i < g.n; j++) {
		A[i][j] = g.edges[i][j];
		if (i != j && g.edges[i][j] < INF)
			path[i][j] = i;
		else
			path[i][j] = -1;
	}
	for (k = 0; k < g.n; k++) {
		for (i = 0; i < g.n; i++) {
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = path[k][j];
				}
		}
		Dispath(g, A, path);
	}
}
//���������㷨�������
void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
	int i, j, k, s;
	int apath[MAXV], d;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++) {
			if (A[i][j] != INF && i != j) {
				printf("��%d��%d��·��Ϊ:", i, j);
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != -1 && k != i) {
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;
				printf("%d", apath[d]);
				for (s = d - 1; s >= 0; s--)
					printf(",%d", apath[s]);
				printf("\t·������Ϊ:%d\n", A[i][j]);
			}
		}
}
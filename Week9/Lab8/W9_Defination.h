#pragma once
#include <iostream>
using namespace std;
#define MAXV 50
#define INF 32767
#define MaxSize 100
typedef char InfoType;
//邻接矩阵定义
typedef struct {
	int no;
	InfoType info;
}VertexType;
typedef struct {
	int edges[MAXV][MAXV];
	VertexType vexs[MAXV];
	int n, e;
}MatGraph;
//克鲁斯卡尔算法的边
typedef struct {
	int u, v, w;
}Edge;
void CreatMat(MatGraph& g);
void DispMat(MatGraph g);
void InsertSort(Edge R[], int n);
void Kruskal(MatGraph g);
void Dijkstra(MatGraph g, int v);
void Dispath(MatGraph g, int dist[], int path[], int S[], int v);
#pragma once
#include <iostream>
using namespace std;
#define MAXV 50
#define INF 32767
typedef int InfoType;
typedef struct Anode {
	int ajdvex;
	struct Anode* nextarc;
	int weight;
}ArcNode;
typedef struct Vnode {
	InfoType info;
	ArcNode* firstarc;
}VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
void DFS(AdjGraph* G, int v);
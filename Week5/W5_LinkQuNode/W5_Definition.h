/*
Version Alpha 1.0
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#pragma once
#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct qnode {
	ElemType data;
	struct qnode* next;
}DataNode;
typedef struct  {
	DataNode* rear, * front;
}LinkQuNode;
void InitQueue(LinkQuNode*& q);
void DestroyQueue(LinkQuNode*& q);
bool QueueEmpty(LinkQuNode*& q);
bool enQueue(LinkQuNode*& q, ElemType e);
bool enQueueALL(LinkQuNode*& q, ElemType a[],int size);
bool deQueue(LinkQuNode*& q, ElemType& e);
bool QueuePrint(LinkQuNode*& q);
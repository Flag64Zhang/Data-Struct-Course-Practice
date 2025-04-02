/*
Version Alpha 1.0
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include"W5_Definition.h"
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void DestroyQueue(LinkQuNode*& q) {
	DataNode* pre = q->front, * p;
	if (pre != NULL) {
		p = pre->next;
		free(pre);
		while (p != NULL) {
			pre = p;
			p = p->next;
		}
		free(pre);
	}free(q);
}
bool QueueEmpty(LinkQuNode*&q) {
	return(q->front == NULL);
}
bool enQueue(LinkQuNode*& q, ElemType e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (QueueEmpty(q))
		q->front = q->rear = p;
	else {
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}
bool enQueueALL(LinkQuNode*& q, ElemType a[],int size) {
	DataNode* p,*s;
	p = (DataNode*)malloc(sizeof(DataNode));
	if (q->rear == NULL) {
		s = (DataNode*)malloc(sizeof(DataNode));
		s->data = a[0]; 
		s->next = p;
		p->data = a[1];
		q->front = s;
		for (int i = 2; i < size ; i++)
		{
			p->next = (DataNode*)malloc(sizeof(DataNode));
			p = p->next;
			p->data = a[i];
		}
		p->next = NULL;
		q->rear = p;
	}
	else {
		for (int i = 0; i < size - 1; i++)
		{
			p->data = a[i];
			p = p->next;
		}
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}
bool deQueue(LinkQuNode*& q, ElemType& e) {
	DataNode* t;
	if (QueueEmpty(q))
		return false;
	t= q->front;
	if (q->rear == q->front) 
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
bool QueuePrint(LinkQuNode*& q) {
	ElemType e;
	DataNode* p = q->front;
	if (QueueEmpty(q))
		return false;
	while (p->next != NULL) {
			e=p->data;
			p= p->next;
		cout << "出队序列为:" << e << endl;
		if (p->next == NULL && p !=  NULL) {
			e = p->data;
			cout << "出队序列为:" << e << endl;
		}
	}
	return true;
}
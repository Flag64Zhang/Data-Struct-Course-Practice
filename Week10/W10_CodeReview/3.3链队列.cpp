#include <iostream>
using namespace std;
typedef char ElemType;

//链队列(存储结构)
typedef struct qnode {
	ElemType data;
	struct qnode* next;
}DataNode;
//链队列(头节点)
typedef struct {
	DataNode* front;
	DataNode* rear;
}LinkQuNode;
//初始化队列
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//销毁队列
void DestroyQueue(LinkQuNode*& q) {
	DataNode* pre = q->front, * p;
	if (pre != NULL) {
		p = pre->next;
		while (p != NULL) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(q);
}
//判断是否为空
bool QueueEmpty(LinkQuNode*& q) {
	return(q->rear == NULL);
}
//进队列
bool enQueue(LinkQuNode*& q, ElemType e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	if (q->rear == NULL)
		q->rear = q->front = p;
	else {
		q->rear->next = p;
		q->rear = p;
	}
	return true;
}
//出队列
bool deQueue(LinkQuNode*& q, ElemType& e) {
	DataNode* t;
	if (q->rear = NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
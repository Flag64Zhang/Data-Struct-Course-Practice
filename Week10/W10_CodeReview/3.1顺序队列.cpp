#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100
//声明
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;
//初始化
void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//销毁队列
void DestroyQueue(SqQueue*&q) {
	free(q);
}
//判断是否为空
bool QueueEmpty(SqQueue*& q) {
	return(q->front == q->rear);
}
//进队列
bool enQueue(SqQueue*& q, ElemType e) {
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//出队列
bool deQueue(SqQueue*& q, ElemType& e) {
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
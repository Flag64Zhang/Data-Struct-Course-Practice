/*
Version: Final
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include<iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue*& q) {
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q) {
	free(q);
	q = NULL;
}
bool QueueEmpty(SqQueue* q) {
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType &e) {
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType &e) {
	if (QueueEmpty(q))
		return false;
	q->front = (q->front + 1) % MaxSize;
	e=q->data[q->front];
	return true;
}
int Count(SqQueue* q) {
	return(q->rear - q->front + MaxSize) % MaxSize;
}
bool QueuePrint(SqQueue*& q) {
	if (QueueEmpty(q) || (q->rear + 1) % MaxSize == q->front)
		return false;
	cout << "循环队列元素为:" << endl;
	int total = Count(q);
	for (int i = 1; i < total; i++)
	{
		int index = (q->front + i)%MaxSize;
		cout << q->data[index] << "\t";
	}
	int index = (q->front + total) % MaxSize;
	cout << q->data[index]<<endl;
	return true;
}
bool QueueSort(SqQueue*& q) {
	if (QueueEmpty(q) || (q->rear + 1) % MaxSize == q->front)
		return false;
	int total = Count(q);
	for (int i = 0; i < total-1; i++) {
		for (int j = 0; j < total - i-1; j++) {
			int s = ((q->front + 1)+j) % MaxSize;
			int p = ((q->front +1)+j+1) % MaxSize;
			if (q->data[s] > q->data[p]) {
				ElemType temp = q->data[s];
				q->data[s] = q->data[p];
				q->data[p] = temp;

			}
		}
	}
	return true;
}
int main() {
	int n = 1;
	SqQueue* q = NULL;
	while (n != 0) {
		cout << " = ====请输入对应数字以执行相应操作==== = " << endl;
		cout << "1.创建循环队列" << endl;
		cout << "2.对循环队列升序排序" << endl;
		cout << "3.出队一个元素并输出该元素" << endl;
		cout << "4.销毁循环队列" << endl;
		cout << "5.输出出队序列" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----创建循环队列----" << endl;
			ElemType e;
			InitQueue(q);
			cout << "循环队列自动初始化成功！" << endl;
			cout << "请输入进队元素个数" << endl;
			int num_1;
			cin >> num_1;
			for (int c = 0; c < num_1; c++)
			{
				cout << "请输入进队元素" << endl;
				cin >> e;
				enQueue(q, e);
			}
			break;
		case 2:
			cout << "----对循环队列升序排序----" << endl;
			if (QueueSort(q)) {
				cout << "循环队列排序成功！" << endl;
				cout << "现循环队列为:" << endl;
				QueuePrint(q);
			}
			else {
				cout << "循环队列排序失败！" << endl;
			}
			break;
		case 3:
			cout << "----出队一个元素并输出该元素----" << endl;
			deQueue(q, e);
			cout << "出队的元素是:" << e << endl;
			break;
		case 4:
			cout << "----销毁循环队列----" << endl;
			DestroyQueue(q);
			cout << "循环队列销毁成功" << endl;
			break;
		case 5:
			cout << "----输出出队序列----" << endl;
			if (QueueEmpty(q))
				cout << "循环队列为空 !" << endl;
			QueuePrint(q);
			break;
		default:
			cout << "输入错误!" << endl;
		}
		system("pause");
		system("cls");
	}
}
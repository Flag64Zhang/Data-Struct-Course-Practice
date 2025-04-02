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
	cout << "ѭ������Ԫ��Ϊ:" << endl;
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
		cout << " = ====�������Ӧ������ִ����Ӧ����==== = " << endl;
		cout << "1.����ѭ������" << endl;
		cout << "2.��ѭ��������������" << endl;
		cout << "3.����һ��Ԫ�ز������Ԫ��" << endl;
		cout << "4.����ѭ������" << endl;
		cout << "5.�����������" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----����ѭ������----" << endl;
			ElemType e;
			InitQueue(q);
			cout << "ѭ�������Զ���ʼ���ɹ���" << endl;
			cout << "���������Ԫ�ظ���" << endl;
			int num_1;
			cin >> num_1;
			for (int c = 0; c < num_1; c++)
			{
				cout << "���������Ԫ��" << endl;
				cin >> e;
				enQueue(q, e);
			}
			break;
		case 2:
			cout << "----��ѭ��������������----" << endl;
			if (QueueSort(q)) {
				cout << "ѭ����������ɹ���" << endl;
				cout << "��ѭ������Ϊ:" << endl;
				QueuePrint(q);
			}
			else {
				cout << "ѭ����������ʧ�ܣ�" << endl;
			}
			break;
		case 3:
			cout << "----����һ��Ԫ�ز������Ԫ��----" << endl;
			deQueue(q, e);
			cout << "���ӵ�Ԫ����:" << e << endl;
			break;
		case 4:
			cout << "----����ѭ������----" << endl;
			DestroyQueue(q);
			cout << "ѭ���������ٳɹ�" << endl;
			break;
		case 5:
			cout << "----�����������----" << endl;
			if (QueueEmpty(q))
				cout << "ѭ������Ϊ�� !" << endl;
			QueuePrint(q);
			break;
		default:
			cout << "�������!" << endl;
		}
		system("pause");
		system("cls");
	}
}
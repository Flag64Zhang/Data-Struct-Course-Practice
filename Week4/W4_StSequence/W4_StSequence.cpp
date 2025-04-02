/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include <iostream>
using namespace std;

typedef char ElemType;
//����ջ�ڵ�
typedef struct linknode {
	ElemType data;
	struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode*& s) {//��ʼ��ջ
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
bool Pop(LinkStNode*& s, ElemType& e)//��ջ
{
	LinkStNode* p ;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	cout << "[��ջ]Ԫ��Ϊ��" << e << endl;
	free(p);
	return true;
}
void DestroyStack(LinkStNode*& s)//����ջ
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		pre = p;
		p = pre->next;
		free(pre);
	}
	free(s);
	s = NULL;
}

bool StackEmpty(LinkStNode* s)//�ж�ջ�Ƿ�Ϊ��
{
	return s->next == NULL;
}

bool PushSequentially(LinkStNode*& s, ElemType e)//���ν�ջ
{
	LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	cout<<"[��ջ]Ԫ��Ϊ��"<<e<<endl;
	return true;
}

// һ�ν�ջ���Ԫ��
void PushAll(LinkStNode*& s,ElemType elems[]) {
	cout << "[��ջ]Ԫ��Ϊ��";
	for (int i = 0; i < 3; ++i) {
		LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
		if (p == NULL) {
			cout << "�ڴ����ʧ��" << endl;
			return;
		}
		p->data = elems[i];
		p->next = s->next;
		s->next = p;
		cout << elems[i] << " ";
	}
	cout << endl;
}

void LinkStPrint(LinkStNode*& s) //�������ջ��Ԫ��
{
	if (s->next == NULL) {
		cout << "ջΪ��" << endl;
		return;
	}
	LinkStNode* p = s->next;
	cout << "��ջ��Ԫ��Ϊ��";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetTop(LinkStNode* s, ElemType& e)//ȡջ��Ԫ�ز����
{
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	cout << "ջ��Ԫ��Ϊ��" << e << endl;
	return true;
}

int length(LinkStNode* top)//��ȡ������
{
	int i = 0;
	LinkStNode* p = top;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}

void SortStack(LinkStNode*& s) {
	LinkStNode* temp = NULL;
	InitStack(temp); // ��ʼ��һ����ʱջ

	static int run_times = 0; // ��¼�ݹ����д���
	int len=length(s); // ��ջ����

	LinkStNode* p = s->next; // ָ����ջ�ĵ�һ��Ԫ��
	char min = s->next->data; // ������СֵΪ��һ��Ԫ��
	int index = 0; // ��¼��Сֵ��λ��
	int temp_num = 0; // ��ʱ������

	// Ѱ����Сֵ����������
	for (int i = 0; i < len - run_times; i++) {
		if (p->data < min) {
			min = p->data;
			index = temp_num;
		}
		p = p->next;
		temp_num++;
	}

	// ��С����Сֵ��Ԫ���ƶ�����ʱջ
	for (int i = 0; i < index; i++) {
		char elem;
		Pop(s, elem);
		PushSequentially(temp, elem);
	}

	// ������СԪ��
	Pop(s, min);

	// ��ʣ���Ԫ���ƶ�����ʱջ
	for (int j = 0; j < len - index - 1 - run_times; j++) {
		char elem;
		Pop(s, elem);
		PushSequentially(temp, elem);
	}

	// ����СԪ�طŻ�ԭջ
	PushSequentially(s, min);

	// ����ʱջ�е�Ԫ���ƻ�ԭջ
	while (temp->next != NULL) {
		char elem;
		Pop(temp, elem);
		PushSequentially(s, elem);
	}

	run_times++;

	DestroyStack(temp); // ������ʱջ

	if (run_times == len) {
		return; // ����ݹ����������ջ���ȣ������ݹ�
	}
	else {
		SortStack(s); // �ݹ����
	}
}


int main() {
	LinkStNode* s = nullptr;
	InitStack(s);
	ElemType arr[] = {'a', 'b', 'c'};
	// ��ջ��������
	PushAll(s,arr);
	PushSequentially(s, 'd');
	PushSequentially(s, 'e');
	PushSequentially(s, 'f');

	cout << "ԭʼջ: ";
	LinkStPrint(s);

	SortStack(s);

	cout << "����ջ: ";
	LinkStPrint(s);

	DestroyStack(s);
	return 0;
}
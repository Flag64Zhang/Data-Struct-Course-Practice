/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#pragma once
#include <iostream>
using namespace std;

typedef char ElemType;
//����ջ�ڵ�
typedef struct linknode{
	ElemType data;
	struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode* &s)//��ʼ��ջ
{
	s=(LinkStNode*)malloc(sizeof(LinkStNode));
	s->next=NULL;
}

void DestroyStack(LinkStNode*& s)//����ջ
{
	LinkStNode* pre=s,*p=s->next;
	while(p!=NULL)
	{
		pre=p;
		p=pre->next;
		free(pre);
	}
	free(s);
	s=NULL;
}

bool StackEmpty(LinkStNode* s)//�ж�ջ�Ƿ�Ϊ��
{
	return s->next==NULL;
}

bool PushSequentially(LinkStNode* &s,ElemType e)//���ν�ջ
{
	LinkStNode* p=(LinkStNode*)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
	return true;
}

// һ�ν�ջ���Ԫ��
void PushAll(LinkStNode*& s, const ElemType elems[], int size) {
	for (int i = 0; i < size; ++i) {
		LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode)); 
		if (p == NULL) {
			cout << "�ڴ����ʧ��" << endl;
			return;
		}
		p->data = elems[i]; 
		p->next = s->next; 
		s->next = p; 
	}
}

void LinkStPrint(LinkStNode*& s) //�������ջ��Ԫ��
{
	if (s == nullptr) {
		cout << "ջδ��ʼ�����ѱ�����" << endl;
		return;
	}
	if (s->next == NULL) {
		cout << "ջΪ��" << endl;
		return;
	}
	LinkStNode* p = s->next;
	int count = 1;
	cout << "��ջ�е�" << count << "��Ԫ��Ϊ��" << p->data << endl;
	p = p->next; 
	while (p != NULL) {
		count++; 
		cout << "��ջ�е�" << count << "��Ԫ��Ϊ��" << p->data << endl;
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
	return true;
}
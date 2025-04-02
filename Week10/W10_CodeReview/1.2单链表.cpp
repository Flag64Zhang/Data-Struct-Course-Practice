#include <iostream>
using namespace std;
typedef char ElemType;
//����
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LinkNode;
//��ʼ��
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
//����(ͷ�巨)
void CreatListF(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
//����(β�巨)
void CreatListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		s = r;
	}
	r->next = NULL;
}
//���
void DispList(LinkNode*& L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
//���ٵ�����
void DestroyList(LinkNode*& L) {
	LinkNode* p, * pre;
	pre = L;
	p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//�жϵ������Ƿ�Ϊ��
bool ListEmpty(LinkNode*& L) {
	return(L->next == NULL);
}
// ������ĳ���
int ListLength(LinkNode*& L) {
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
//�������������Ԫ��
bool GetElem(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)
		return false;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		e = p->data;
		return true;
	}
}
//������Ԫ�ز���
int LocateElem(LinkNode*& L, ElemType e) {
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
//�������������Ԫ��
bool ListInsert(LinkNode*& L, int i, ElemType e) {
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
//����������ɾ������Ԫ��
bool DeleteElem(LinkNode*& L, int i, ElemType& e) {
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else {
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
#include <iostream>
using namespace std;
typedef char ElemType;
//声明
typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
} DLinkNode;
//初始化
void IniList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
}
//建立(头插法)
void CreatListF(DLinkNode*& L, ElemType a[], int n) {
	DLinkNode* s;
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
}

//建立(尾插法)
void CreatListR(DLinkNode*& L, ElemType a[], int n) {
	DLinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
//输出
void DispList(DLinkNode*& L) {
	DLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
// 求长度
int ListLength(DLinkNode*& L) {
	int n = 0;
	DLinkNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
//按序号求双链表中元素
bool GetElem(DLinkNode*& L, int i, ElemType e) {
	int j = 0;
	DLinkNode* p = L;
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
//双链表按元素查找
int LocateElem(DLinkNode*& L, ElemType e) {
	int i = 1;
	DLinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
//插入元素
bool ListInsert(DLinkNode*& L, int i, ElemType e) {
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)return false;
	else {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		p->next = s;
		s->prior = p;
		return true;
	}
}
//删除元素
bool ListInsert(DLinkNode*& L, int i, ElemType &e) {
	int j = 0;
	DLinkNode* p = L, * q;
	if (i <= 0)return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)return false;
	else {
		q = p->next;
		if (q == NULL)return false;
		e = q->data;
		p->next = q->next;
		if (q->next != NULL)
			q->next->prior = p;
		free(q);
		return true;
	}
}
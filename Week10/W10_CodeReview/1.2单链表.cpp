#include <iostream>
using namespace std;
typedef char ElemType;
//声明
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LinkNode;
//初始化
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
//建立(头插法)
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
//建立(尾插法)
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
//输出
void DispList(LinkNode*& L) {
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}
}
//销毁单链表
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
//判断单链表是否为空
bool ListEmpty(LinkNode*& L) {
	return(L->next == NULL);
}
// 求单链表的长度
int ListLength(LinkNode*& L) {
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}
//按序号求单链表中元素
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
//单链表按元素查找
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
//单链表插入数据元素
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
//单链表按索引删除数据元素
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
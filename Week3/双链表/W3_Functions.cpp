#include <iostream>
#include"W3_Definition.h"
using namespace std;
void InitList(DLinkNode*& L)//初始化双链表
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
}

void CreateListR_1(DLinkNode*& L)//依次采用尾插法插入元素a,b,c,d,e
{
	DLinkNode* s, * r;
	r = L; 
	ElemType a[] = {'a', 'b', 'c', 'd', 'e'};
	
	for (int i = 0; i < 5; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s; s->prior = r;
		r = s;
	}
	r->next = NULL;
}

void CreateListR(DLinkNode*& L, int n)//依次采用尾插法插入自定义元素
{
	if (n <= 0) {//判断元素数量是否正确
		return;
	}
	DLinkNode* s, * r;
	r = L;
	char c;
	while (  r->next!= NULL)
	{
		r = r->next;
	}
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		cout<<"请输入第"<<i+1<<"个元素："<<endl;
		cin >> c;
		s->data = c;
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
void DLinkListPrint(DLinkNode*& L) //	输出循环链表L
{
	if (L == NULL || L->next == L) {
		cout << "链表为空" << endl;
		return;
	}
	DLinkNode* p = L->next;
	cout << p->data << "  ";
	while (p->next) {
		cout << p->next->data << "  ";
		p = p->next;
	}
	cout<<endl;
	return;
}
bool ListInsert(DLinkNode*& L, int i, ElemType e)//在指定位置处插入元素
{
	int j = 0;
	DLinkNode* p = L,*s;
	if (i <= 0)return false;
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if(p->next!=NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}
bool ListDelete(DLinkNode*& L, int i, ElemType& e)//根据位置删除元素
{
	int j = 0;
	DLinkNode* p = L;
	DLinkNode* q;
	if (i <= 0)return false;
	while (j < i-1 && p != NULL)
	{
		j++;
		p=p->next;
	}
	if (p == NULL)
		return false;
	
	else
	{
		q=p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		if (q->next!= NULL)
			q->next->prior = p;
		free(q);
		return true;
	}
}
int ListLength(DLinkNode* L)//输出循环链表L的长度
{
	int len = 0;
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}
bool GetElem(DLinkNode* L, int i, ElemType& e)//输出元素的位置
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0)return false;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

int LocateElem(DLinkNode* L, ElemType e)//按元素值查找
{
	int i = 1;
	DLinkNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return (i);
}
void DestroyList(DLinkNode*& L)//销毁双链表
{ 
	DLinkNode* p = L;
	DLinkNode* q = NULL;
	while (p != NULL) {
		q = p->next; 
		free(p); 
		p = q; 
	}
	L = NULL; 
}
bool ListEmpty(DLinkNode* L)//判断双链表是否为空
{
	if (L == NULL)
		return true;
	return(L->next == L);

}